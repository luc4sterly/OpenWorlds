package net.freeworlds.world;

import java.util.ArrayList;
import java.util.IdentityHashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

/**
 * Las texturas que cambian con el tiempo en un .world, tal como las mueve
 * el cliente original: un StartupSensor dispara acciones, y las que siguen
 * vivas se vuelven a llamar en cada frame (RunningActionHandler). De esas
 * acciones solo las que cambian material: AnimateAction (cambia el
 * Material del dueno por el de una lista, con cadencia fija), y las que la
 * secuencian: SequenceAction y WaitAction. Una .mov no se anima sola: sus
 * frames son las celdas de un Material (ver MaterialTiles); lo que se
 * anima es el Material entero.
 *
 * Reglas, del Java original (editor/.../source/NET/worlds/scape):
 * - StartupSensor.handle: dispara sus acciones en el primer FrameEvent
 *   (una sola vez, hasTriggered).
 * - RunningActionHandler.trigger: accion.trigger(evento, null); si no
 *   devuelve null, handle() la vuelve a llamar en cada frame con lo que
 *   devolvio hasta que devuelva null.
 * - AnimateAction.trigger: con seqID null, si ya corre sin bucle infinito
 *   devuelve null; si no, startAnimation (startTime = ahora, frame -1).
 *   t = ahora - startTime; k = count*t/cycleTime (long); ciclo = k/count;
 *   frame = k - ciclo*count. Si ciclo &gt;= cycles y no es infinita: ultimo
 *   frame y deja de correr. Si el frame cambia: owner.setMaterial(new
 *   Material(URL(frameList[frame]))). Devuelve this mientras corre.
 *   Sin frames o cycleTime &lt;= 0: ciclo = 1e9.
 * - SequenceAction.trigger + SequenceActionState.run: llama a sus
 *   componentes en orden con un unico seqID; al acabar la lista vuelve al
 *   principio y descuenta un bucle (loopCount, o infinito).
 * - WaitAction.trigger: termina cuando el tiempo del evento alcanza
 *   inicio + 1000*duration.
 *
 * El dueno de una AnimateAction es el WObject en cuya lista de acciones
 * esta (WObject.addAction). Material(URL) lleva ambient 0.75, diffuse 0,
 * specular 0, color (128,128,128), opacidad 1 (Material.java).
 *
 * Limites (no inventados, documentados): solo se ejecutan acciones de
 * estos tres tipos; un StartupSensor cuyas acciones incluyan otras
 * (MoveAction, TeleportAction...) ejecuta solo las soportadas, y una
 * SequenceAction con algun componente no soportado no se ejecuta entera
 * (sus tiempos dependen de todos). El reloj es uno solo en ms para
 * Std.getRealTime (AnimateAction) y FrameEvent.time (WaitAction). El
 * original deja de llamar a setMaterial mientras el dueno no tiene clump
 * (sala descargada); aqui se sigue calculando, lo que solo cambia algo
 * invisible.
 */
public final class TextureActions {
   /** Material vigente puesto por una AnimateAction: dueno -&gt; URL de textura. */
   public final Map<WNode, String> materialOverride = new IdentityHashMap<>();
   private final Map<WNode, WNode> owner = new IdentityHashMap<>();
   private final Map<WNode, Boolean> sensorFired = new IdentityHashMap<>();
   private final Map<WNode, Anim> anims = new IdentityHashMap<>();
   private final Map<WNode, Object> seqCurrent = new IdentityHashMap<>();
   private final List<Object[]> running = new ArrayList<>(); // {action, seqID}
   /** Acciones de StartupSensor no ejecutadas, por clase (informe). */
   public final List<String> skipped = new ArrayList<>();

   /** Recorre el mundo para saber el dueno de cada accion. */
   public TextureActions(WNode world) {
      Map<WNode, Boolean> seen = new IdentityHashMap<>();
      for (WNode room : world.roomsByName.values()) {
         index(room, seen);
         if (room.environment != null) {
            index(room.environment, seen);
         }
      }
   }

   private void index(WNode n, Map<WNode, Boolean> seen) {
      if (seen.put(n, Boolean.TRUE) != null) {
         return;
      }
      if (n.actions != null && animatable(n)) {
         for (WNode a : n.actions) {
            if (!owner.containsKey(a)) {
               owner.put(a, n);
            }
         }
      }
      for (WNode c : n.children) {
         index(c, seen);
      }
   }

   /**
    * Animatable (la interfaz que exige AnimateAction.trigger) la
    * implementan Surface y Shape; de las clases que lee WorldRestorer lo
    * son Surface, Rect, Portal, WebPageWall, Shape y PosableShape (RectPatch
    * y Billboard no: extienden WObject y Attribute).
    */
   static boolean animatable(WNode n) {
      String c = n.className;
      return c.endsWith(".Surface") || c.endsWith(".Rect") || c.endsWith(".Portal")
         || c.endsWith(".WebPageWall") || c.endsWith(".Shape") || c.endsWith(".PosableShape");
   }

   /**
    * Primer frame de una sala: dispara los StartupSensor de sus objetos
    * (sala, entorno y descendientes) que no se hayan disparado ya.
    */
   public void startRoom(WNode room, long nowMs) {
      List<WNode> sensors = new ArrayList<>();
      collectSensors(room, sensors, new IdentityHashMap<WNode, Boolean>());
      if (room.environment != null) {
         collectSensors(room.environment, sensors, new IdentityHashMap<WNode, Boolean>());
      }
      for (WNode s : sensors) {
         if (sensorFired.put(s, Boolean.TRUE) != null || s.actions == null) {
            continue;
         }
         for (WNode a : new ArrayList<>(s.actions)) {
            if (!supported(a)) {
               skipped.add(cls(a) + (a.name != null ? "[" + a.name + "]" : ""));
               continue;
            }
            Object seq = trigger(a, nowMs, null);
            if (seq != null) {
               running.add(new Object[]{a, seq});
            }
         }
      }
   }

   private static void collectSensors(WNode n, List<WNode> out, Map<WNode, Boolean> seen) {
      if (seen.put(n, Boolean.TRUE) != null) {
         return;
      }
      if (n.handlers != null) {
         for (WNode h : n.handlers) {
            if (h.className.endsWith(".StartupSensor")) {
               out.add(h);
            }
         }
      }
      for (WNode c : n.children) {
         collectSensors(c, out, seen);
      }
   }

   /** Un frame: RunningActionHandler.handle de cada accion viva. */
   public void tick(long nowMs) {
      for (int i = 0; i < running.size(); i++) {
         Object[] r = running.get(i);
         Object seq = trigger((WNode) r[0], nowMs, r[1]);
         if (seq == null) {
            running.remove(i--);
         } else {
            r[1] = seq;
         }
      }
   }

   public int runningCount() {
      return running.size();
   }

   private boolean supported(WNode a) {
      if (a.className.endsWith(".AnimateAction") || a.className.endsWith(".WaitAction")) {
         return true;
      }
      if (a.className.endsWith(".SequenceAction") && a.actions != null) {
         for (WNode c : a.actions) {
            if (!supported(c)) {
               return false;
            }
         }
         return true;
      }
      return false;
   }

   private Object trigger(WNode a, long now, Object seqID) {
      if (a.className.endsWith(".AnimateAction")) {
         return animate(a, now, seqID);
      }
      if (a.className.endsWith(".WaitAction")) {
         long end = seqID == null ? now + (long) (1000.0F * a.waitDuration) : (Long) seqID;
         return now < end ? (Object) end : null;
      }
      return sequence(a, now, seqID);
   }

   /** SequenceActionState: bucles restantes, infinito, accion actual y su seqID. */
   private static final class SeqState {
      int currentLoop;
      boolean loopInfinite;
      List<WNode> actions;
      Object seqID;
      int currentAct;
   }

   private Object sequence(WNode a, long now, Object seqID) {
      if (seqID != seqCurrent.get(a)) {
         return null;
      }
      if (seqID == null) {
         SeqState st = new SeqState();
         st.currentLoop = a.seqLoopCount;
         st.loopInfinite = a.seqLoopInfinite;
         st.actions = new ArrayList<>(a.actions);
         seqCurrent.put(a, st);
      }
      SeqState st = (SeqState) seqCurrent.get(a);
      if (!runSeq(st, now)) {
         seqCurrent.remove(a);
         return null;
      }
      return st;
   }

   private boolean runSeq(SeqState st, long now) {
      if (st.currentLoop <= 0 && !st.loopInfinite) {
         return false;
      }
      while (st.currentAct < st.actions.size()) {
         if ((st.seqID = trigger(st.actions.get(st.currentAct), now, st.seqID)) != null) {
            return true;
         }
         st.currentAct++;
      }
      st.currentAct = 0;
      if (st.currentLoop > 0) {
         st.currentLoop--;
      }
      return true;
   }

   /** Estado de una AnimateAction (campos de la instancia en el original). */
   private static final class Anim {
      String[] frames;
      long startTime;
      int cycleNo;
      int currentFrameNo;
      boolean running;
   }

   private Object animate(WNode a, long now, Object seqID) {
      WNode own = owner.get(a);
      if (own == null) {
         return null; // AnimateAction.trigger: el dueno no es Animatable
      }
      Anim st = anims.get(a);
      if (st == null) {
         st = new Anim();
         List<String> names = new ArrayList<>();
         StringTokenizer tok = new StringTokenizer(a.animFrameList == null ? "" : a.animFrameList);
         while (tok.hasMoreTokens()) {
            names.add(tok.nextToken());
         }
         st.frames = names.toArray(new String[0]);
         st.currentFrameNo = -1;
         anims.put(a, st);
      }
      if (seqID == null) {
         if (st.running && !a.animInfiniteLoop) {
            return null;
         }
         st.cycleNo = 0;
         st.currentFrameNo = -1;
         st.startTime = now;
      }
      int count = st.frames.length;
      int elapsed = (int) (now - st.startTime);
      st.cycleNo = cycleAt(count, a.animCycleTime, elapsed);
      int frame = frameAt(count, a.animCycleTime, a.animCycles, a.animInfiniteLoop, elapsed);
      st.running = !(st.cycleNo >= a.animCycles && !a.animInfiniteLoop);
      if (frame != st.currentFrameNo) {
         st.currentFrameNo = frame;
         if (st.currentFrameNo >= 0) {
            materialOverride.put(own, st.frames[st.currentFrameNo]);
         }
      }
      return st.running ? a : null;
   }

   /** Ciclo de AnimateAction.trigger a t ms del arranque (1e9 sin frames o sin periodo). */
   static int cycleAt(int count, int cycleTime, int elapsedMs) {
      if (count == 0 || cycleTime <= 0) {
         return 1000000000;
      }
      long k = (long) count * elapsedMs / cycleTime;
      return (int) (k / count);
   }

   /** Frame que AnimateAction.trigger elige a t ms del arranque. */
   public static int frameAt(int count, int cycleTime, int cycles, boolean infinite, int elapsedMs) {
      if (cycleAt(count, cycleTime, elapsedMs) >= cycles && !infinite) {
         return count - 1;
      }
      if (count == 0 || cycleTime <= 0) {
         return 0;
      }
      long k = (long) count * elapsedMs / cycleTime;
      return (int) (k - (k / count) * count);
   }

   private static String cls(WNode n) {
      return n.className.substring(n.className.lastIndexOf('.') + 1);
   }
}
