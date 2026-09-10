package NET.worlds.network;

import NET.worlds.core.Std;
import java.lang.reflect.Field;
import java.net.Socket;
import java.util.Enumeration;
import java.util.Hashtable;

/**
 * Sonda de login REAL — FASE 4: completa el arranque hasta sessionInit
 * contra un servidor vivo, siguiendo el handoff genuino de AutoServer.
 *
 * Camino 100% real del cliente decompilado:
 *   1. Igual que AutoServerProbe: initInstance + state_Initializing +
 *      WSConnecting + setSocket + state_XMIT_PROPREQ + perFrame hasta que
 *      el AutoServer handofflea (estado 17). Esto crea de verdad la
 *      subclase concreta (UserServer/AnonUserServer/AnonRoomServer según
 *      prop #15), le transfiere la conexión viva (reuseConnection),
 *      hace swapServer + setGalaxyType (que levanta el LoginWizard real
 *      bajo Xvfb, igual que al cliente).
 *   2. Recupera el servidor vivo del ServerTracker (solo lectura por
 *      reflexión: es instrumentación del harness, no cambia conducta).
 *   3. Llama a Galaxy.setAuthInfo EXACTO como lo hace
 *      LoginWizard.activeCallback (LoginWizard.java:279) cuando el
 *      usuario pulsa Sign-In — pero sin UI: el nick viene de argv.
 *      Sin este paso, buildSessionInitCmd muere en dAssert(false)
 *      (loginMode 0 UNKNOWN): el login EXIGE auth info, es el diseño.
 *   4. Conduce el servidor vivo con perFrame() real (lo que el Main loop
 *      haría): 0→3→7 (XMIT_SI envía sessionInitCmd) →8 (espera el ack
 *      del servidor) →11/12 (login aceptado) o 17 (VarError = rechazo).
 *
 * Servidor objetivo por defecto: el guest de Worlio
 * (gippsland.worlio.com:8265), que según https://worlds.worlio.com/
 * "requires no registration, only a valid nickname" — el único sitio
 * donde un login real es posible sin cuenta. El servidor primario
 * (worlds.worlio.com:6650) exige cuenta registrada en la web
 * (https://worlds.worlio.com/register): SIN password esta sonda NO
 * puede pasar del sessionInit allí, y NO inventa credenciales.
 * El 4º argv opcional permite pasar un password SOLO para una cuenta
 * que uno mismo haya registrado a mano en esa web; jamás hardcodear
 * valores aquí.
 *
 * Uso: GuestLoginProbe [host] [port] [nickname] [password?] [clientVersion?]
 *   defecto: gippsland.worlio.com 8265 FWProbeNNN(aleatorio) null 2004080500
 * El clientVersion por defecto (prop 9 VAR_CLIENT del sessionInit) es el
 * valor REAL que devuelve el gamma.dll nativo de NUESTRA instalación
 * (assets/WorldsPlayer/bin/gamma.dll, build 08/05/04 Rev 1900): la
 * exportación _Java_NET_worlds_core_Std_getClientVersion@8 (RVA 0x2ff0)
 * hace NewStringUTF(env, literal en 0x46d428) = "2004080500"
 * (formato AAAAMMDDHH de la fecha de build; verificado con objdump
 * sobre la DLL real, sin ejecutar nada nativo). El mock JNI devuelve
 * null y el servidor responde a eso con VarError#7 "client out of date".
 * Una sola conexión por ejecución, se cierra al terminar.
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

      // Instrumentación SOLO del harness: el nivel sale de worlds.ini
      // (netdebug, aquí 0) y esta sonda necesita los volcados send/recv
      // del código real (WorldServer.sendNetMsg bit 128+1024, recv bit
      // 64) + sessionInit (4) + tracker (8) + autodetección (32).
      // 1260 = 1024+128+64+32+8+4. No toca source/, solo el static.
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

      // FASE A: handshake hasta el handoff (código real).
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

      // FASE B: recuperar el servidor vivo (lectura por reflexión).
      WorldServer live = findLiveServer(galaxy, probe, host + ":" + port);
      if (live == null) {
         System.out.println("NO LIVE SERVER found in tracker after handoff");
         System.exit(1);
      }
      System.out.println("live server class=" + live.getClass().getName()
         + " state=" + stateName(live.getState())
         + " version=" + live.getVersion());
      dumpProps(live);

      // El mock JNI deja _clientVersion=null (nativo real: build actual).
      // Sin esto el sessionInit sale con VAR_CLIENT=null y el servidor
      // lo tumba con VarError#7. Asignación directa: campo protected en
      // el mismo paquete, solo el harness, antes del primer tick (el
      // valor se lee en buildSessionInitCmd, estado 7).
      System.out.println("override _clientVersion=null -> \"" + clientVer + "\"");
      live._clientVersion = clientVer;

      // FASE C: auth info, la llamada exacta del LoginWizard al Sign-In
      // (LoginWizard.activeCallback: setAuthInfo(loginUserName, null,
      // loginPassword, null, loginSerialNumber, loginMode) con mode=2
      // AUTHENTICATE). Para UserServer/AnonUserServer/AnonRoomServer el
      // modo 2 solo exige chatname; password/serial quedan null.
      System.out.println("setAuthInfo(nick=" + nick
         + " password=" + (pass == null ? "null" : "***")
         + " mode=2 AUTHENTICATE)");
      preseedWizard(galaxy, nick);
      galaxy.setAuthInfo(nick, null, pass, null, null, 2);
      System.out.println("loginMode=" + galaxy.getLoginMode()
         + " chatname=" + galaxy.getChatname());

      // FASE D: conducir el servidor vivo con perFrame real.
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
    * Deja el LoginWizard real en el estado que tendría si el usuario
    * hubiera tecleado el nick y pulsado Sign-In (LoginWizard.
    * validateKnownUserInfo: loginUserName=nick, loginMode=2, doLogin()
    * con loginFrom=pantalla 0). Sin esto, setConnected() hace
    * setIniString("User0", null) y el MOCK de IniFile lanza NPE
    * (Hashtable no admite nulls) — artefacto del harness por saltarse
    * la UI, no bug del cliente: en el flujo real loginUserName nunca es
    * null aquí porque validateKnownUserInfo lo exige antes de doLogin.
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
