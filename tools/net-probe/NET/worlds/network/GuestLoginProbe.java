package NET.worlds.network;

import NET.worlds.core.Std;
import java.lang.reflect.Field;
import java.net.Socket;
import java.util.Enumeration;
import java.util.Hashtable;

/**
 * REAL login probe — PHASE 4: completes the startup up to sessionInit
 * against a live server, following AutoServer's genuine handoff.
 *
 * A 100% real path through the decompiled client:
 *   1. Same as AutoServerProbe: initInstance + state_Initializing +
 *      WSConnecting + setSocket + state_XMIT_PROPREQ + perFrame until the
 *      AutoServer hands off (state 17). This really creates the concrete
 *      subclass (UserServer/AnonUserServer/AnonRoomServer depending on
 *      prop #15), hands it the live connection (reuseConnection), does
 *      swapServer + setGalaxyType (which brings up the real LoginWizard
 *      under Xvfb, same as for the client).
 *   2. Retrieves the live server from the ServerTracker (read-only via
 *      reflection: it is harness instrumentation, it changes no behaviour).
 *   3. Calls Galaxy.setAuthInfo EXACTLY as
 *      LoginWizard.activeCallback (LoginWizard.java:279) does when the
 *      user presses Sign-In — but without UI: the nick comes from argv.
 *      Without this step, buildSessionInitCmd dies in dAssert(false)
 *      (loginMode 0 UNKNOWN): login REQUIRES auth info, by design.
 *   4. Drives the live server with the real perFrame() (what the Main
 *      loop would do): 0→3→7 (XMIT_SI sends sessionInitCmd) →8 (waits for
 *      the server's ack) →11/12 (login accepted) or 17 (VarError =
 *      rejected).
 *
 * Default target server: Worlio's guest server (gippsland.worlio.com:8265),
 * which according to https://worlds.worlio.com/ "requires no registration,
 * only a valid nickname" — the only place where a real login is possible
 * without an account. The primary server (worlds.worlio.com:6650) requires
 * an account registered on the website (https://worlds.worlio.com/register):
 * WITHOUT a password this probe CANNOT get past sessionInit there, and it
 * does NOT make up credentials. The optional 4th argv lets you pass a
 * password ONLY for an account you registered by hand on that website
 * yourself; never hardcode values here.
 *
 * Usage: GuestLoginProbe [host] [port] [nickname] [password?] [clientVersion?]
 *   defaults: gippsland.worlio.com 8265 FWProbeNNN(random) null 2004080500
 * The default clientVersion (prop 9 VAR_CLIENT of the sessionInit) is the
 * REAL value returned by the native gamma.dll of OUR install
 * (assets/WorldsPlayer/bin/gamma.dll, build 08/05/04 Rev 1900): the
 * export _Java_NET_worlds_core_Std_getClientVersion@8 (RVA 0x2ff0) does
 * NewStringUTF(env, literal at 0x46d428) = "2004080500" (YYYYMMDDHH format
 * of the build date; verified with objdump on the real DLL, without
 * running anything native). The JNI mock returns null and the server
 * answers that with VarError#7 "client out of date".
 * A single connection per run, closed at the end.
 */
public final class GuestLoginProbe extends AutoServer {
   private String connectedHost;
   private boolean socketDone;

   public GuestLoginProbe() {
      super();
   }

   @Override
   protected synchronized void setSocket(Socket s, VarErrorException e, String h) {
      super.setSocket(s, e, h);
      this.connectedHost = h;
      this.socketDone = true;
      this.notifyAll();
   }

   public static void main(String[] args) throws Exception {
      String host = args.length > 0 ? args[0] : "gippsland.worlio.com";
      int port = args.length > 1 ? Integer.parseInt(args[1]) : 8265;
      String nick = args.length > 2 ? args[2]
         : "FWProbe" + (100 + (int)(Math.random() * 900));
      String pass = args.length > 3 ? args[3] : null;
      String clientVer = args.length > 4 ? args[4] : "2004080500";

      NET.worlds.core.Std.initProductName();

      // Harness-ONLY instrumentation: the level comes from worlds.ini
      // (netdebug, 0 here) and this probe needs the send/recv dumps of
      // the real code (WorldServer.sendNetMsg bit 128+1024, recv bit
      // 64) + sessionInit (4) + tracker (8) + autodetection (32).
      // 1260 = 1024+128+64+32+8+4. It does not touch source/, only the static.
      Field dbg = Galaxy.class.getDeclaredField("_debugLevel");
      dbg.setAccessible(true);
      dbg.setInt(null, 1260);
      System.out.println("netdebug(harness-override)=1260");

      GuestLoginProbe probe = new GuestLoginProbe();
      Galaxy galaxy = Galaxy.getGalaxy("worldserver://" + host + ":" + port);
      ServerURL surl = new ServerURL("worldserver://" + host + ":" + port);
      probe.initInstance(galaxy, surl);
      probe.state_Initializing();

      synchronized (probe) {
         long deadline = System.currentTimeMillis() + 20000;
         while (!probe.socketDone && System.currentTimeMillis() < deadline) {
            probe.wait(deadline - System.currentTimeMillis());
         }
      }
      if (!probe.socketDone) {
         System.out.println("NO SOCKET CALLBACK within 20s");
         System.exit(1);
      }
      System.out.println("connectedHost=" + probe.connectedHost
         + " state=" + stateName(probe._state.getState()));
      if (probe._sock == null) {
         System.out.println("connect failed: lastError=" + probe._lastError);
         System.exit(1);
      }

      // PHASE A: handshake up to the handoff (real code).
      probe.state_XMIT_PROPREQ();
      System.out.println("sent propReq, state=" + stateName(probe._state.getState()));
      int last = -99;
      long end = System.currentTimeMillis() + 25000;
      while (System.currentTimeMillis() < end) {
         int st = probe._state.getState();
         if (st != last) {
            System.out.println("autoserver state -> " + stateName(st));
            last = st;
         }
         if (st == 12 || st == 17 || st == -1) {
            break;
         }
         try {
            probe.perFrame(Std.getFastTime());
         } catch (Throwable t) {
            System.out.println("autoserver perFrame threw: " + t);
            t.printStackTrace(System.out);
            break;
         }
         Thread.sleep(200);
      }
      System.out.println("autoserver final state=" + stateName(probe._state.getState()));
      if (probe._state.getState() != 17) {
         System.out.println("HANDOFF NOT REACHED, stopping");
         closeQuiet(probe._sock);
         System.exit(1);
      }

      // PHASE B: retrieve the live server (read via reflection).
      WorldServer live = findLiveServer(galaxy, probe, host + ":" + port);
      if (live == null) {
         System.out.println("NO LIVE SERVER found in tracker after handoff");
         System.exit(1);
      }
      System.out.println("live server class=" + live.getClass().getName()
         + " state=" + stateName(live.getState())
         + " version=" + live.getVersion());
      dumpProps(live);

      // The JNI mock leaves _clientVersion=null (real native: the
      // current build). Without this the sessionInit goes out with
      // VAR_CLIENT=null and the server knocks it down with VarError#7.
      // Direct assignment: a protected field in the same package, harness
      // only, before the first tick (the value is read in
      // buildSessionInitCmd, state 7).
      System.out.println("override _clientVersion=null -> \"" + clientVer + "\"");
      live._clientVersion = clientVer;

      // PHASE C: auth info, the LoginWizard's exact call on Sign-In
      // (LoginWizard.activeCallback: setAuthInfo(loginUserName, null,
      // loginPassword, null, loginSerialNumber, loginMode) with mode=2
      // AUTHENTICATE). For UserServer/AnonUserServer/AnonRoomServer,
      // mode 2 only requires the chatname; password/serial stay null.
      System.out.println("setAuthInfo(nick=" + nick
         + " password=" + (pass == null ? "null" : "***")
         + " mode=2 AUTHENTICATE)");
      preseedWizard(galaxy, nick);
      galaxy.setAuthInfo(nick, null, pass, null, null, 2);
      System.out.println("loginMode=" + galaxy.getLoginMode()
         + " chatname=" + galaxy.getChatname());

      // PHASE D: drive the live server with the real perFrame.
      last = -99;
      end = System.currentTimeMillis() + 45000;
      long mainloopSince = -1;
      while (System.currentTimeMillis() < end) {
         int st = live.getState();
         if (st != last) {
            System.out.println("live state -> " + stateName(st));
            last = st;
            if (st == 12) {
               mainloopSince = System.currentTimeMillis();
            }
         }
         if (st == 17 || st == -1) {
            break;
         }
         if (st == 12 && System.currentTimeMillis() - mainloopSince > 12000) {
            System.out.println("MAINLOOP stable 12s, stopping");
            break;
         }
         try {
            live.perFrame(Std.getFastTime());
         } catch (Throwable t) {
            System.out.println("live perFrame threw: " + t);
            t.printStackTrace(System.out);
            break;
         }
         Thread.sleep(200);
      }
      System.out.println("live final state=" + stateName(live.getState())
         + " lastError=" + live._lastError);
      try {
         if (live._sock != null) {
            live._sock.close();
         }
      } catch (Exception ignored) {
      }
      closeQuiet(probe._sock);
      System.out.println("closed cleanly");
      System.exit(0);
   }

   /**
    * Leaves the real LoginWizard in the state it would be in if the user
    * had typed the nick and pressed Sign-In (LoginWizard.
    * validateKnownUserInfo: loginUserName=nick, loginMode=2, doLogin()
    * with loginFrom=screen 0). Without this, setConnected() does
    * setIniString("User0", null) and the IniFile MOCK throws an NPE
    * (Hashtable does not accept nulls) — a harness artifact from skipping
    * the UI, not a client bug: in the real flow loginUserName is never
    * null here because validateKnownUserInfo requires it before doLogin.
    */
   private static void preseedWizard(Galaxy galaxy, String nick) throws Exception {
      Field fWiz = Galaxy.class.getDeclaredField("_wizard");
      fWiz.setAccessible(true);
      Object wiz = fWiz.get(galaxy);
      if (wiz == null) {
         System.out.println("preseedWizard: no wizard, skipping");
         return;
      }
      Field fName = wiz.getClass().getDeclaredField("loginUserName");
      fName.setAccessible(true);
      fName.set(wiz, nick);
      Field fFrom = wiz.getClass().getDeclaredField("loginFrom");
      fFrom.setAccessible(true);
      fFrom.setInt(wiz, 0);
      System.out.println("preseedWizard: loginUserName=" + nick + " loginFrom=0 on " + wiz);
   }

   private static WorldServer findLiveServer(Galaxy galaxy, GuestLoginProbe probe, String hostPort)
      throws Exception {
      Field fTracker = Galaxy.class.getDeclaredField("_serverTracker");
      fTracker.setAccessible(true);
      Object tracker = fTracker.get(galaxy);
      Field fHash = tracker.getClass().getDeclaredField("_serverHash");
      fHash.setAccessible(true);
      Hashtable hash = (Hashtable)fHash.get(tracker);
      System.out.println("tracker entries=" + hash.size());
      Enumeration e = hash.elements();
      while (e.hasMoreElements()) {
         Object o = e.nextElement();
         System.out.println("tracker holds: " + o
            + (o == null ? "" : " class=" + o.getClass().getName()));
         if (o instanceof WorldServer && o != probe) {
            return (WorldServer)o;
         }
      }
      return null;
   }

   private static void dumpProps(WorldServer live) {
      int[] ids = {1, 3, 15, 25, 26, 27};
      for (int i = 0; i < ids.length; i++) {
         try {
            Object p = live.getProperty(ids[i]);
            System.out.println("prop #" + ids[i] + "="
               + (p == null ? "null" : ((net2Property)p).value()));
         } catch (Throwable t) {
            System.out.println("prop #" + ids[i] + " unreadable: " + t);
         }
      }
   }

   private static void closeQuiet(Socket s) {
      try {
         if (s != null) {
            s.close();
         }
      } catch (Exception ignored) {
      }
   }

   private static String stateName(int s) {
      switch (s) {
         case -1: return "-1 DEAD";
         case 0: return "0 PRECONNECTED";
         case 3: return "3 INITIALIZING";
         case 4: return "4 CONNECTING";
         case 5: return "5 XMIT_PROPREQ";
         case 6: return "6 RCV_PROPS";
         case 7: return "7 XMIT_SI";
         case 8: return "8 RCV_SI_ACK";
         case 9: return "9 XMIT_AI";
         case 10: return "10 RCV_AI_ACK";
         case 11: return "11 XMIT_PROPS";
         case 12: return "12 MAINLOOP";
         case 13: return "13 XMIT_AE";
         case 15: return "15 XMIT_SE";
         case 16: return "16 RCV_SE_ACK";
         case 17: return "17 DISCONNECTED";
         case 18: return "18 DISCONNECTED+";
         case 19: return "19 SLEEPING";
         default: return String.valueOf(s);
      }
   }
}
