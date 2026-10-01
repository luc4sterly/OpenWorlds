package net.openworlds.solar;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.net.SocketTimeoutException;
import java.util.BitSet;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.TimeUnit;

/**
 * One connected WorldsPlayer: its socket with a reader thread (packets go to
 * {@link SolarServer#handle}) and a writer thread fed by a queue, so a slow
 * player never holds up the others. The fields below the I/O are the world
 * state the server keeps for it; they are only touched under the server's lock.
 */
final class Client {
   /** Packets waiting to be written before the player is dropped as too slow. */
   private static final int MAX_QUEUE = 4000;
   private static final int IDLE_LOGIN_MS = 30 * 60_000;
   private static final int IDLE_PLAYING_MS = 10 * 60_000;
   /**
    * Packets a connection may send in 2 seconds before it is dropped: many
    * times what the client sends (a room's worth of requests when a world
    * loads, then a few position reports a second).
    */
   static final int MAX_PACKETS_PER_2S = 400;

   final SolarServer server;
   final Socket socket;
   final boolean secure;
   final String address;
   final long connectedAt = System.currentTimeMillis();
   private final LinkedBlockingQueue<byte[]> queue = new LinkedBlockingQueue<>();
   /** No more packets are queued; the writer closes the socket once the queue is empty. */
   private volatile boolean closing;
   private volatile boolean closed;
   private volatile String closeReason;

   // ------------------------------------------------ state (server lock)
   String name;
   /** Lower-case name: the key in the server's tables. */
   String key;
   Accounts.Account account;
   boolean guest;
   boolean loggedIn;
   int protocol;
   /** Current room number (0 = none). */
   int room;
   int x;
   int y;
   int z;
   int dir;
   /** The player's own properties (avatar, asleep...), as PROPSET brought them. */
   final Map<Integer, Props.Prop> props = new TreeMap<>();
   final Set<Integer> subscribed = new HashSet<>();
   /** Short ObjIDs registered in this player's client (REGOBJID), by the other player's key. */
   final Map<String, Integer> ids = new HashMap<>();
   private final BitSet usedIds = new BitSet();
   /** Other players this client currently shows as avatars. */
   final Set<String> shown = new HashSet<>();
   /** Friends list of a guest (accounts keep theirs). */
   final Set<String> guestBuddies = new LinkedHashSet<>();
   private long floodWindow;
   private int floodCount;
   private long rateWindow;
   private int rateCount;

   Client(SolarServer server, Socket socket, boolean secure) {
      this.server = server;
      this.socket = socket;
      this.secure = secure;
      this.address = socket.getInetAddress().getHostAddress();
   }

   void start() {
      Thread reader = new Thread(this::readLoop, "solar-read-" + address);
      reader.setDaemon(true);
      Thread writer = new Thread(this::writeLoop, "solar-write-" + address);
      writer.setDaemon(true);
      reader.start();
      writer.start();
   }

   private void readLoop() {
      try {
         socket.setTcpNoDelay(true);
         socket.setSoTimeout(60_000);
         InputStream in = new BufferedInputStream(socket.getInputStream());
         long lastHeard = System.currentTimeMillis();
         while (!closing) {
            Packet p;
            try {
               p = Packet.read(in);
            } catch (SocketTimeoutException e) {
               long idle = System.currentTimeMillis() - lastHeard;
               if (idle > (loggedIn ? IDLE_PLAYING_MS : IDLE_LOGIN_MS)) {
                  closeReason = "idle for " + idle / 60_000 + " min";
                  break;
               }
               continue;
            }
            if (p == null) {
               break;
            }
            lastHeard = System.currentTimeMillis();
            if (lastHeard - rateWindow > 2000) {
               rateWindow = lastHeard;
               rateCount = 0;
            }
            if (++rateCount > MAX_PACKETS_PER_2S) {
               closeReason = "sent more than " + MAX_PACKETS_PER_2S + " packets in 2 seconds";
               break;
            }
            server.handle(this, p);
         }
      } catch (IOException e) {
         if (closeReason == null) {
            closeReason = e.getMessage() == null ? e.getClass().getSimpleName() : e.getMessage();
         }
      } catch (RuntimeException e) {
         closeReason = "server error: " + e;
         server.log("[solar] error handling " + this + ": " + e);
         e.printStackTrace();
      } finally {
         finish();
      }
   }

   private void writeLoop() {
      try {
         OutputStream out = new BufferedOutputStream(socket.getOutputStream());
         while (true) {
            byte[] p = queue.poll(250, TimeUnit.MILLISECONDS);
            if (p == null) {
               if (closing) {
                  break;
               }
               continue;
            }
            out.write(p);
            byte[] more;
            while ((more = queue.poll()) != null) {
               out.write(more);
            }
            out.flush();
         }
      } catch (IOException | InterruptedException e) {
         // the reader sees the socket die too and cleans up
      } finally {
         closeSocket();
      }
   }

   private void closeSocket() {
      try {
         socket.close();
      } catch (IOException ignored) {
         // already closed
      }
   }

   /** Queues a packet; ignored once the connection is closing. */
   void send(byte[] packet) {
      if (closing) {
         return;
      }
      if (queue.size() > MAX_QUEUE) {
         closeReason = "too slow to keep up";
         closing = true;
         queue.clear();
         closeSocket();
         return;
      }
      queue.add(packet);
   }

   /**
    * Ends the connection after writing what is already queued (a goodbye
    * message, say). Safe under the server's lock: the clean-up
    * ({@link SolarServer#disconnected}) runs later, on the reader thread.
    */
   void kick(String reason) {
      if (closing) {
         return;
      }
      closeReason = reason;
      closing = true;
   }

   /** Reader thread's end: tells the server once, and lets the writer finish. */
   private void finish() {
      synchronized (this) {
         if (closed) {
            return;
         }
         closed = true;
      }
      closing = true;
      server.disconnected(this, closeReason);
   }

   boolean isClosed() {
      return closed;
   }

   /**
    * The short ObjID this client knows {@code other} by, registering one
    * (REGOBJID) first if needed; 0 when none is left (then the long id, the
    * name, is used). regObjIDCmd reads the id as a signed byte, so only
    * 2..127 are usable.
    */
   int idFor(Client other) {
      Integer id = ids.get(other.key);
      if (id != null) {
         return id;
      }
      int free = usedIds.nextClearBit(2);
      if (free > 127) {
         return 0;
      }
      usedIds.set(free);
      ids.put(other.key, free);
      send(new Packet.Out().utf(other.name).u8(free).packet(Packet.PO, Packet.REGOBJID));
      return free;
   }

   /** Frees the short ObjID of a player who left (it is registered again before any reuse). */
   void releaseId(String otherKey) {
      Integer id = ids.remove(otherKey);
      if (id != null) {
         usedIds.clear(id);
      }
   }

   /** The key of the player a short ObjID stands for in this client, or null. */
   String keyForId(int id) {
      for (Map.Entry<String, Integer> e : ids.entrySet()) {
         if (e.getValue() == id) {
            return e.getKey();
         }
      }
      return null;
   }

   /** True when the player sends more than 12 chat lines in 5 seconds. */
   boolean flooding() {
      long now = System.currentTimeMillis();
      if (now - floodWindow > 5000) {
         floodWindow = now;
         floodCount = 0;
      }
      return ++floodCount > 12;
   }

   Set<String> buddies() {
      return account != null ? account.buddies : guestBuddies;
   }

   @Override
   public String toString() {
      return (name != null ? name : "?") + "@" + address + (secure ? " (TLS)" : "");
   }
}
