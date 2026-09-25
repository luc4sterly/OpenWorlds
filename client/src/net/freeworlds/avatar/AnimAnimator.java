package net.freeworlds.avatar;

import java.util.ArrayList;
import java.util.List;

/**
 * El animador de un avatar de gamma.dll: lo que en el original es el Rep
 * de DroneAnimator.CreateRep (FUN_004350c0, 8 bytes) con su animador
 * (FUN_00432880, 0x3c bytes) y la estructura de estado de implicitos
 * (0x38 bytes):
 *
 * <pre>
 * animador +0x00  movimiento (0x50 bytes, FUN_004313b0; lo usa update)
 *          +0x08  W1: hueco de los implicitos (placeholder)
 *          +0x10  W2: raiz, un placeholder que contiene W1 o los explicitos encima
 *          +0x18  claves de los implicitos del tipo (copia)
 *          +0x24  secuencias de los implicitos (copia, la cambian los changeimp)
 *          +0x30  tipo actual (-1)
 *          +0x34  implicito actual (1)
 *          +0x38  ultimo explicito (0)
 * Rep +4   estado de implicitos (AnimMotion.State, FUN_00434670)
 * </pre>
 *
 * Portado del puente (bridge/NET/worlds/core/AnimAnimator.java y la parte
 * de NativeAnimator que no toca RenderWare: moveto, update, animate,
 * getAnimationTime); la pose se devuelve en vez de aplicarse a un clump
 * (eso lo hace {@link AvatarRig#applyPose}, FUN_00434470). No se porta
 * moveby (FUN_004352f0), que el visor no usa. Lo que queda del lado de
 * Java (cuando se llama a moveto/update) esta en PosableShape y lo porta
 * quien dibuja (WorldViewer).
 */
public final class AnimAnimator {
   /**
    * Tabla de implicitos (0x475288, 12 bytes por indice 0..9): nombre,
    * arg1 (0 = por distancia, 1 = por tiempo) y arg2 (modo de fin:
    * 1 = quedarse en el ultimo key, 2 = bucle). Los indices 1 y 2 no tienen
    * nombre (pipe vacio): 1 = quieto recien llegado, 2 = girando en el sitio.
    */
   static final String[] IMP_NAMES = {"", "", "", "walk", "wait", "endwait", "run", "fly", "hover", "sit"};
   static final int[] IMP_ARG1 = {0, 0, 0, 0, 1, 1, 0, 0, 1, 1};
   static final int[] IMP_ARG2 = {0, 0, 0, 2, 1, 1, 2, 2, 2, 2};
   /** Mezcla de cambio de implicito: {0 s, 0xfa ms} (FUN_00432d10). */
   static final AnimTime SHIFT_TIME = new AnimTime(0, 250);

   /** pi (DAT_00475530, double) y 1/180 (DAT_00475538, double) de moveto. */
   private static final double PI = 3.141592653589793;
   private static final double INV_180 = 0.005555555555555556;

   private final AnimRegistry registry;
   private final AnimSequence.Library library;
   final AnimMotion motion;
   final AnimMotion.State state;
   AnimGraph.Placeholder w1;
   AnimGraph.Placeholder root;
   final List<String> impKeys = new ArrayList<>();
   final List<String> impValues = new ArrayList<>();
   int type = -1;
   int imp = 1;
   int exp = 0;

   /**
    * DroneAnimator.CreateRep (0x004164a0 -&gt; FUN_004350c0(this, 0, 1)):
    * movimiento de tipo 0 y estado con la hora actual (FUN_004279e0), activo,
    * y FUN_00433420.
    */
   public AnimAnimator(AnimRegistry registry, AnimSequence.Library library, int nowMs) {
      this.registry = registry;
      this.library = library;
      AnimTime now = AnimTime.ofMillis(nowMs);
      this.motion = new AnimMotion(now);
      this.state = new AnimMotion.State(now);
      this.reset();
   }

   /**
    * FUN_00433420 (tambien endanimations, 0x00416500 -&gt; FUN_004351a0):
    * implicito 1, explicito 0, W1 = placeholder(pipe vacio) y raiz =
    * placeholder(W1). No toca el tipo ni las listas de implicitos.
    */
   public void reset() {
      this.imp = 1;
      this.exp = 0;
      this.w1 = new AnimGraph.Placeholder(AnimGraph.emptyPipe());
      this.root = new AnimGraph.Placeholder(this.w1);
   }

   /**
    * FUN_004330a0: si cambia el tipo copia sus implicitos; si expIdx (1..n)
    * tiene un bloque changeimp y NoImpChange != 1, sustituye las secuencias
    * de esos implicitos. (El error del original con claves que no son
    * implicitos, 0x433378, escribe fuera del vector y nadie lo lee: se
    * ignora, como en el puente.)
    */
   boolean applyChangeImp(int type, int expIdx) {
      AnimRegistry.AvatarType t = this.registry.type(type);
      if (t == null) {
         return false;
      }
      if (type != this.type) {
         this.type = type;
         this.impValues.clear();
         this.impValues.addAll(t.impValues);
         this.impKeys.clear();
         this.impKeys.addAll(t.impKeys);
      }
      int i = expIdx - 1;
      if (i < 0 || t.expValues.size() <= i) {
         return false;
      }
      if (AnimGraph.noImpChange()) {
         return false;
      }
      AnimRegistry.ChangeImp c = t.changeImp(t.expKeys.get(i));
      if (c == null) {
         return false;
      }
      boolean changed = false;
      for (int k = 0; k < c.keys.size(); k++) {
         int j = this.impKeys.indexOf(c.keys.get(k));
         if (j >= 0) {
            this.impValues.set(j, AnimRegistry.str(c.values.get(k)));
         }
         changed = true;
      }
      return changed;
   }

   /**
    * FUN_00433a70: pipe del implicito idx (fuera de 1..9 se toma 1). Sin
    * nombre en la tabla, sin tipo o sin esa clave entre los implicitos del
    * avatar -&gt; pipe vacio; si no, el pipe de su secuencia con arg1/arg2.
    */
   AnimGraph.Pipe implicitPipe(int type, int idx) {
      if (idx < 1 || 9 < idx) {
         idx = 1;
      }
      String name = IMP_NAMES[idx];
      if (name.isEmpty() || this.registry.type(type) == null) {
         return AnimGraph.emptyPipe();
      }
      int j = this.impKeys.indexOf(name);
      if (j < 0) {
         return AnimGraph.emptyPipe();
      }
      return AnimGraph.pipe(this.library, this.impValues.get(j), IMP_ARG1[idx], IMP_ARG2[idx]);
   }

   /** FUN_00433f70: pipe del explicito idx (1..n) por tiempo y modo 0, o null. */
   AnimGraph.Pipe explicitPipe(int type, int idx) {
      AnimRegistry.AvatarType t = this.registry.type(type);
      if (t == null) {
         return null;
      }
      int i = idx - 1;
      if (i < 0 || t.expValues.size() <= i) {
         return null;
      }
      return AnimGraph.pipe(this.library, t.expValues.get(i), 1, 0);
   }

   /** FUN_00433e90: indice 1..n del explicito por su clave (strcmp) o -1. */
   int explicitIndex(int type, String lowerName) {
      AnimRegistry.AvatarType t = this.registry.type(type);
      if (t == null) {
         return -1;
      }
      int i = t.expKeys.indexOf(AnimRegistry.str(lowerName));
      return i < 0 ? -1 : i + 1;
   }

   /**
    * FUN_00432d10: primero FUN_004330a0; si impIdx &gt;= 0 y cambia, W1 pasa
    * a ser shiftto(lo que habia, nuevo implicito, 250 ms); si expIdx &gt;= 0,
    * la raiz pasa a ser overlay(lo que habia, pipe del explicito, su
    * duracion) y se devuelve esa duracion en segundos (s + ms / 1000,
    * DAT_00472020 = 1000). Si no, 0.
    */
   float play(int type, int impIdx, int expIdx) {
      this.applyChangeImp(type, expIdx);
      if (impIdx >= 0 && impIdx != this.imp) {
         this.imp = impIdx;
         if (this.imp == 0) {
            return 0.0F;
         }
         AnimGraph.Pipe p = this.implicitPipe(type, this.imp);
         AnimGraph.Node cur = this.w1.take();
         this.w1.set(new AnimGraph.ShiftTo(cur, p, SHIFT_TIME));
      }
      if (expIdx >= 0) {
         this.exp = expIdx;
         if (this.exp == 0) {
            return 0.0F;
         }
         AnimGraph.Pipe p = this.explicitPipe(type, this.exp);
         if (p == null) {
            return 0.0F;
         }
         AnimGraph.Node cur = this.root.take();
         AnimTime d = p.duration();
         this.root.set(new AnimGraph.Overlay(cur, p, d));
         return (float) d.seconds();
      }
      return 0.0F;
   }

   /**
    * DroneAnimator.moveto (0x00416530 -&gt; FUN_004351b0): posicion (x, y, z)
    * y orientacion de eje Z (0x49f398 = (0,0,1)) y angulo yaw * pi * 1/180,
    * tiempo en ms. Estado de implicitos del Rep, FUN_00432a30 y
    * FUN_00432d10(tipo, estado, -1). PosableShape le pasa (short) x/y/z de
    * su getObjectToWorldMatrix, (short) -getYaw() y Std.getRealTime() - 1.
    */
   public void moveto(int type, short x, short y, short z, short yaw, int timeMs) {
      float[] p = {(float) x, (float) y, (float) z};
      float[] q = AnimMotion.axisAngle(0f, 0f, 1f, (float) ((double) yaw * PI * INV_180));
      AnimTime t = AnimTime.ofMillis(timeMs);
      int st = this.state.moved(p, q, t);
      this.motion.offer(p, q, t);
      this.play(type, st, -1);
   }

   /**
    * DroneAnimator.update (0x00416740 -&gt; FUN_00435520 -&gt; FUN_00433710)
    * sin clump1 (PosableShape pasa null): apunta la hora, cantidad =
    * distancia * |escala| (vtable [11] del movimiento), dt = ahora - hora del
    * update anterior, y avanza la raiz. Devuelve la pose de la raiz, que
    * FUN_00434470 aplica a la figura ({@link AvatarRig#applyPose}).
    *
    * @param scale la de {@link #updateScale}
    */
   public AnimPose update(int timeMs, float scale) {
      AnimTime t = AnimTime.ofMillis(timeMs);
      AnimTime prev = this.motion.lastUpdate;
      this.motion.lastUpdate = t;
      if (scale < 0.0F) {
         scale = -scale;
      }
      float amount = this.motion.takeDistance() * scale;
      this.step(amount, t.minus(prev));
      return this.pose();
   }

   /**
    * FUN_00435520: escala = 10 / (scaleX * (m00 * 1000)) (DAT_00475540 = 10,
    * DAT_0047552c = 1000), con m00 de la matriz de modelado del primer hijo
    * de la figura (la pelvis) y scaleX el de PosableShape (getScaleX de su
    * Transform).
    */
   public static float updateScale(float scaleX, float pelvisM00) {
      float m1000 = pelvisM00 * 1000.0F;
      return 10.0F / (scaleX * m1000);
   }

   /** El paso de grafo de FUN_00433710: raiz = raiz.avanzar(cantidad, dt). */
   public void step(float amount, AnimTime dt) {
      this.root.advance(amount, dt);
   }

   /**
    * DroneAnimator.animate (0x004165c0 -&gt; FUN_004355a0): nombre a
    * minusculas (FUN_004280b0), buscado entre los explicitos del tipo
    * (FUN_00433e90) y arrancado (FUN_00432d10 con implicito -1); devuelve
    * su duracion en segundos, o 0.0 (DAT_00475524) si no existe.
    */
   public float animate(int type, String name) {
      if (name == null) {
         return 0.0F;
      }
      int idx = this.explicitIndex(type, AnimRegistry.lower(name));
      if (idx == -1) {
         return 0.0F;
      }
      return this.play(type, -1, idx);
   }

   /** DroneAnimator.getAnimationTime (0x00416620 -&gt; FUN_00435630 -&gt; FUN_00432be0). */
   public float getAnimationTime(int type, String name) {
      if (name == null) {
         return 0.0F;
      }
      int idx = this.explicitIndex(type, AnimRegistry.lower(name));
      if (idx < 0) {
         return 0.0F;
      }
      AnimGraph.Pipe p = this.explicitPipe(type, idx);
      return p == null ? 0.0F : (float) p.duration().seconds();
   }

   /** La pose de la raiz (vtable +8 sobre +0x14). */
   public AnimPose pose() {
      return this.root.pose();
   }

   /** Implicito actual (+0x34): 1 quieto, 2 girando, 3 walk, 4 wait, 5 endwait. */
   public int implicitIndex() {
      return this.imp;
   }

   /** Nombre del implicito actual en la tabla 0x475288 ("" para 1 y 2). */
   public String implicitName() {
      return IMP_NAMES[this.imp < 1 || this.imp > 9 ? 1 : this.imp];
   }

   /** Para las comprobaciones: ¿la raiz tiene solo el hueco de implicitos? */
   public boolean onlyImplicit() {
      return this.root.inner == this.w1;
   }

   /** Para las comprobaciones: el nodo del hueco de implicitos. */
   public AnimGraph.Node implicitNode() {
      return this.w1.inner;
   }
}
