package net.openworlds.solar;

import java.io.ByteArrayOutputStream;
import java.io.EOFException;
import java.io.IOException;
import java.io.InputStream;
import java.io.UTFDataFormatException;

/**
 * One packet of the Worlds protocol, as the 2004 client reads and writes it
 * (NET.worlds.network.netPacket, netPacketReader, ServerInputStream and
 * ServerOutputStream): {@code [length][ObjID][command][data...]}, where the
 * length byte counts itself (so a packet is at most 255 bytes) and the ObjID
 * is either one byte (a short id) or a zero followed by a string (a long id,
 * such as a user or room name). Strings are modified UTF-8 with a one-byte
 * length. Numbers are big-endian.
 */
final class Packet {
   // ObjIDs with a meaning of their own (netConst)
   static final int CLIENT = 1;
   static final int CURRENT_ROOM = 253;
   static final int CO = 254;
   static final int PO = 255;

   // commands (the client's *Cmd classes; see protocol/LibreWorlds-wiki-master/Packet-types.md)
   static final int LONGLOC = 1;
   static final int PROP = 3;
   static final int SHORTLOC = 4;
   static final int ROOMCHNG = 5;
   static final int SESSINIT = 6;
   static final int SESSEXIT = 7;
   static final int APPINIT = 8;
   static final int PROPREQ = 10;
   static final int DISAPPR = 11;
   static final int APPRACTR = 12;
   static final int REGOBJID = 13;
   static final int TEXT = 14;
   static final int PROPSET = 15;
   static final int PROPUPD = 16;
   static final int WHISPER = 17;
   static final int TELEPORT = 18;
   static final int ROOMIDRQ = 20;
   static final int ROOMID = 21;
   static final int SUBSCRIB = 22;
   static final int UNSUBSCR = 23;
   static final int SUBDIST = 24;
   static final int REDIRECT = 25;
   static final int REDIRID = 26;
   static final int FINGREQ = 27;
   static final int FINGREP = 28;
   static final int BUDDYLISTUPDATE = 29;
   static final int BUDDYLISTNOTIFY = 30;
   static final int CHANNEL = 31;

   /** Short id, or 0 when the ObjID is a long one. */
   final int shortId;
   /** Long id (a name), or null when the ObjID is short. */
   final String longId;
   final int command;
   private final byte[] data;
   private int pos;

   private Packet(int shortId, String longId, int command, byte[] data) {
      this.shortId = shortId;
      this.longId = longId;
      this.command = command;
      this.data = data;
   }

   /** Reads the next packet, or returns null at the end of the stream. */
   static Packet read(InputStream in) throws IOException {
      int length = in.read();
      if (length < 0) {
         return null;
      }
      if (length < 3) {
         throw new IOException("packet too short (" + length + ")");
      }
      byte[] body = new byte[length - 1];
      int off = 0;
      while (off < body.length) {
         int n = in.read(body, off, body.length - off);
         if (n < 0) {
            throw new EOFException();
         }
         off += n;
      }
      Packet head = new Packet(0, null, 0, body);
      int shortId = head.u8();
      String longId = shortId == 0 ? head.utf() : null;
      int command = head.u8();
      byte[] data = new byte[body.length - head.pos];
      System.arraycopy(body, head.pos, data, 0, data.length);
      return new Packet(shortId, longId, command, data);
   }

   /** The ObjID as the client's ObjectMgr would name it: the long id, or "#n". */
   String objName() {
      return longId != null ? longId : "#" + shortId;
   }

   boolean more() {
      return pos < data.length;
   }

   int remaining() {
      return data.length - pos;
   }

   int u8() throws IOException {
      if (pos >= data.length) {
         throw new EOFException("packet ends early");
      }
      return data[pos++] & 0xff;
   }

   int s16() throws IOException {
      return (short) u16();
   }

   int u16() throws IOException {
      return (u8() << 8) | u8();
   }

   /** Modified UTF-8 with a one-byte length (ServerInputStream.readUTF). */
   String utf() throws IOException {
      int len = u8();
      if (pos + len > data.length) {
         throw new UTFDataFormatException("string runs past the packet");
      }
      String s = decodeUtf(data, pos, len);
      pos += len;
      return s;
   }

   /** The raw bytes of the next {@code n} bytes. */
   byte[] bytes(int n) throws IOException {
      if (pos + n > data.length) {
         throw new EOFException("packet ends early");
      }
      byte[] b = new byte[n];
      System.arraycopy(data, pos, b, 0, n);
      pos += n;
      return b;
   }

   /** An ObjID inside the data (TEXT and WHISPER carry the sender this way). */
   String objIdInData() throws IOException {
      int s = u8();
      return s == 0 ? utf() : "#" + s;
   }

   static String decodeUtf(byte[] b, int off, int len) throws UTFDataFormatException {
      StringBuilder sb = new StringBuilder(len);
      int i = off;
      int end = off + len;
      while (i < end) {
         int c = b[i] & 0xff;
         if (c < 0x80) {
            sb.append((char) c);
            i++;
         } else if ((c & 0xe0) == 0xc0) {
            if (i + 1 >= end) {
               throw new UTFDataFormatException();
            }
            sb.append((char) (((c & 0x1f) << 6) | (b[i + 1] & 0x3f)));
            i += 2;
         } else if ((c & 0xf0) == 0xe0) {
            if (i + 2 >= end) {
               throw new UTFDataFormatException();
            }
            sb.append((char) (((c & 0x0f) << 12) | ((b[i + 1] & 0x3f) << 6) | (b[i + 2] & 0x3f)));
            i += 3;
         } else {
            throw new UTFDataFormatException();
         }
      }
      return sb.toString();
   }

   /** Length of s in modified UTF-8 (ServerOutputStream.utfLength). */
   static int utfLength(String s) {
      int n = 0;
      for (int i = 0; i < s.length(); i++) {
         char c = s.charAt(i);
         n += c >= 1 && c <= 127 ? 1 : c > 2047 ? 3 : 2;
      }
      return n;
   }

   @Override
   public String toString() {
      return "packet " + command + " for " + objName() + " (" + data.length + " bytes of data)";
   }

   /** Builds one outgoing packet. */
   static final class Out {
      private final ByteArrayOutputStream b = new ByteArrayOutputStream(64);

      Out u8(int v) {
         b.write(v & 0xff);
         return this;
      }

      Out s16(int v) {
         b.write((v >>> 8) & 0xff);
         b.write(v & 0xff);
         return this;
      }

      /** Modified UTF-8 with a one-byte length (ServerOutputStream.writeUTF); longer strings are cut. */
      Out utf(String s) {
         String t = s == null ? "" : s;
         while (utfLength(t) > 255) {
            t = t.substring(0, t.length() - 1);
         }
         b.write(utfLength(t));
         for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);
            if (c >= 1 && c <= 127) {
               b.write(c);
            } else if (c > 2047) {
               b.write(0xe0 | (c >> 12) & 0x0f);
               b.write(0x80 | (c >> 6) & 0x3f);
               b.write(0x80 | c & 0x3f);
            } else {
               b.write(0xc0 | (c >> 6) & 0x1f);
               b.write(0x80 | c & 0x3f);
            }
         }
         return this;
      }

      Out bytes(byte[] v) {
         b.write(v, 0, v.length);
         return this;
      }

      /** An ObjID inside the data: a name (long id). */
      Out longObjId(String name) {
         u8(0);
         return utf(name);
      }

      /** The bytes written so far, without a frame. */
      byte[] raw() {
         return b.toByteArray();
      }

      /** The finished packet for a short ObjID. */
      byte[] packet(int shortId, int command) {
         return frame(new byte[]{(byte) shortId}, command);
      }

      /** The finished packet for a long ObjID (a name). */
      byte[] packet(String longId, int command) {
         Out id = new Out().u8(0).utf(longId);
         return frame(id.b.toByteArray(), command);
      }

      private byte[] frame(byte[] objId, int command) {
         byte[] body = b.toByteArray();
         int length = 1 + objId.length + 1 + body.length;
         if (length > 255) {
            throw new IllegalArgumentException("packet too large (" + length + " bytes)");
         }
         byte[] p = new byte[length];
         p[0] = (byte) length;
         System.arraycopy(objId, 0, p, 1, objId.length);
         p[1 + objId.length] = (byte) command;
         System.arraycopy(body, 0, p, 2 + objId.length, body.length);
         return p;
      }
   }
}
