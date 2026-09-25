package net.freeworlds.avatar;

/**
 * El grafo de reproduccion del motor de animacion de gamma.dll: los
 * "drivers" que recorren una secuencia y los nodos que los envuelven,
 * mezclan y encadenan. Todos se alcanzan solo por vtable (funciones
 * recuperadas en decompiled-native/gamma_dll, commit 130b4b4).
 *
 * <pre>
 * driver  [1] duracion  [2] avanzar(cantidad, dt) -&gt; driver o null  [3] pose
 * nodo    [1] avanzar(cantidad, dt) -&gt; nodo o null                 [2] pose
 * </pre>
 *
 * "cantidad" es la distancia recorrida por el avatar escalada (update) y
 * dt el tiempo real transcurrido; los drivers de tiempo usan dt y los de
 * distancia usan la cantidad.
 *
 * Portado al cliente propio (2026-09-25) desde el puente
 * (editor/.../bridge/NET/worlds/core/AnimGraph.java), que es la traduccion
 * verificada con bridge/test/Animator*Check.java; aqui solo cambia de
 * donde salen las secuencias (AnimSequence.Library en vez de la cache de
 * gamma.dll que pide los ficheros a Java) y NoImpChange.
 */
public final class AnimGraph {
   private AnimGraph() {
   }

   /** 1/30 (DAT_00476ec0, float). */
   static final float INV_KEYS_PER_SECOND = 0.033333335F;
   /** 30.0 (DAT_00476ec8). */
   static final float KEYS_PER_SECOND = 30.0F;

   // ------------------------------------------------------------- drivers

   public abstract static class Driver {
      public abstract AnimTime duration();

      public abstract Driver advance(float amount, AnimTime dt);

      public abstract AnimPose pose();
   }

   /**
    * Driver vacio (vtable 0x47700c, FUN_0043b320): dura {10000 s, 0}
    * (FUN_0043b360), avanzar lo deja igual (FUN_0043b380) y su pose es una
    * pose vacia (FUN_0043b3c0 -&gt; FUN_0043bc20).
    */
   public static final class EmptyDriver extends Driver {
      public AnimTime duration() {
         return new AnimTime(10000, 0);
      }

      public Driver advance(float amount, AnimTime dt) {
         return this;
      }

      public AnimPose pose() {
         return AnimPose.empty();
      }
   }

   /** FUN_0043b5c0 / FUN_0043b590 / FUN_0043b920: (float) duracion * 1/30 pasado a {s, ms}. */
   static AnimTime durationOf(AnimSequence seq) {
      return AnimTime.ofSeconds((float) ((double) seq.duration() * (double) INV_KEYS_PER_SECOND));
   }

   /**
    * Driver por tiempo (vtable 0x476fdc, FUN_0043b840): +0x10 modo, +0x14
    * key actual (short), +0x18 tiempo acumulado {s, ms}.
    */
   public static final class TimeDriver extends Driver {
      final AnimSequence seq;
      final int mode;
      short key;
      AnimTime elapsed = AnimTime.ZERO;

      TimeDriver(AnimSequence seq, int mode) {
         this.seq = seq;
         this.mode = mode;
      }

      public AnimTime duration() {
         return durationOf(this.seq);
      }

      /**
       * FUN_0043b950: tiempo += dt; key = (short) trunc(segundos * 30) (el
       * fistp va con la palabra de control en truncar, "orb $0xc"). Si
       * key &gt; duracion: modo 2 -&gt; key % (duracion + 1) (bucle); modo 1
       * -&gt; duracion (se queda en el ultimo key); otro -&gt; termina (null).
       */
      public Driver advance(float amount, AnimTime dt) {
         this.elapsed = this.elapsed.plus(dt);
         this.key = (short) AnimTime.fistp(truncate(this.elapsed.seconds() * (double) KEYS_PER_SECOND));
         short dur = this.seq.duration();
         if (dur < this.key) {
            if (this.mode == 2) {
               this.key = (short) (this.key % (short) (dur + 1));
            } else {
               if (this.mode != 1) {
                  return null;
               }
               this.key = dur;
            }
         }
         return this;
      }

      /** FUN_0043baa0: pose con la z de la traslacion de raiz (flag 1). */
      public AnimPose pose() {
         return this.seq.pose(this.key, true);
      }
   }

   /**
    * Driver por distancia (vtable 0x476ff4, FUN_0043b490): +0x18 cantidad
    * acumulada (float, "segundos"), +0x1c duracion en segundos (float) =
    * (float) duracion * 1/30.
    */
   public static final class DistanceDriver extends Driver {
      final AnimSequence seq;
      final int mode;
      short key;
      float acc;
      final float dur;

      DistanceDriver(AnimSequence seq, int mode) {
         this.seq = seq;
         this.mode = mode;
         this.dur = (float) ((double) seq.duration() * (double) INV_KEYS_PER_SECOND);
      }

      public AnimTime duration() {
         return durationOf(this.seq);
      }

      /**
       * FUN_0043b5f0: acc += cantidad (float). Si acc &lt; 0: acc =
       * (float) fmod(acc, |dur|) + dur (fprem). Si acc &gt; dur: modo 2 -&gt;
       * 0 si dur == 0 y si no fmod(acc, |dur|); modo 1 -&gt; dur; otro -&gt;
       * termina. key = (short) trunc(acc * 30.0f). Andar hacia atras (cantidad
       * negativa) recorre la secuencia al reves.
       */
      public Driver advance(float amount, AnimTime dt) {
         this.acc = this.acc + amount;
         if (this.acc < 0.0F) {
            float rem = (float) ((double) this.acc % Math.abs((double) this.dur));
            this.acc = rem + this.dur;
         }
         if (this.dur < this.acc) {
            if (this.mode == 2) {
               if (this.dur == 0.0F) {
                  this.acc = 0.0F;
               } else {
                  this.acc = (float) ((double) this.acc % Math.abs((double) this.dur));
               }
            } else {
               if (this.mode != 1) {
                  return null;
               }
               this.acc = this.dur;
            }
         }
         // flds acc; fmuls 30.0f: el producto se queda en el registro x87.
         this.key = (short) AnimTime.fistp(truncate((double) this.acc * (double) KEYS_PER_SECOND));
         return this;
      }

      /** Para las comprobaciones: key actual (+0x14). */
      public short key() {
         return this.key;
      }

      /** FUN_0043b770: pose sin la z de la traslacion de raiz (flag 0). */
      public AnimPose pose() {
         return this.seq.pose(this.key, false);
      }
   }

   static double truncate(double v) {
      return v < 0 ? Math.ceil(v) : Math.floor(v);
   }

   /**
    * FUN_00437d00: sin nombre o sin secuencia en la cache (FUN_0042fc90) -&gt;
    * driver vacio; si no, por distancia si arg1 == 0 (FUN_0043b3e0) y por
    * tiempo si no (FUN_0043b790), con modo arg2. La cache es aqui la
    * biblioteca de .seq del cliente ({@link AnimSequence.Library}).
    */
   static Driver driver(AnimSequence.Library lib, String name, int arg1, int arg2) {
      if (name == null || name.isEmpty()) {
         return new EmptyDriver();
      }
      AnimSequence seq = lib == null ? null : lib.get(name);
      if (seq == null) {
         return new EmptyDriver();
      }
      return arg1 == 0 ? new DistanceDriver(seq, arg2) : new TimeDriver(seq, arg2);
   }

   // ------------------------------------------------------------- nodos

   public abstract static class Node {
      public abstract Node advance(float amount, AnimTime dt);

      public abstract AnimPose pose();
   }

   /** "pipe" (vtable 0x476e78, FUN_00439990 / FUN_00439a10): un driver en +0xc. */
   public static final class Pipe extends Node {
      Driver driver;

      Pipe(Driver d) {
         this.driver = d;
      }

      /** Para las comprobaciones: el driver (+0xc). */
      public Driver driver() {
         return this.driver;
      }

      /** FUN_00439880: duracion del driver o {0, 0}. */
      public AnimTime duration() {
         return this.driver != null ? this.driver.duration() : AnimTime.ZERO;
      }

      /** FUN_00439710: si el driver termina, el pipe tambien (null). */
      public Node advance(float amount, AnimTime dt) {
         if (this.driver != null) {
            this.driver = this.driver.advance(amount, dt);
         }
         return this.driver != null ? this : null;
      }

      /** FUN_004397e0: sin driver, pose nula. */
      public AnimPose pose() {
         return this.driver == null ? null : this.driver.pose();
      }
   }

   /** FUN_004398c0: pipe con el driver vacio (FUN_00437c60). */
   static Pipe emptyPipe() {
      return new Pipe(new EmptyDriver());
   }

   /** FUN_00439920: pipe con el driver de esa secuencia. */
   static Pipe pipe(AnimSequence.Library lib, String name, int arg1, int arg2) {
      return new Pipe(driver(lib, name, arg1, arg2));
   }

   /**
    * "placeholder" (vtable 0x476e60, FUN_00439db0; la variante 0x476e48 de
    * FUN_00439ed0 tiene los mismos metodos): un nodo en +0xc que se puede
    * sacar (FUN_00439c60) y poner (FUN_00439c40). Nunca termina.
    */
   public static final class Placeholder extends Node {
      Node inner;

      Placeholder(Node inner) {
         this.inner = inner;
      }

      /** FUN_00439c60: devuelve el nodo y deja el hueco vacio. */
      Node take() {
         Node n = this.inner;
         this.inner = null;
         return n;
      }

      /** FUN_00439c40. */
      void set(Node n) {
         this.inner = n;
      }

      /** FUN_00439aa0. */
      public Node advance(float amount, AnimTime dt) {
         if (this.inner != null) {
            this.inner = this.inner.advance(amount, dt);
         }
         return this;
      }

      /** FUN_00439b40. */
      public AnimPose pose() {
         return this.inner != null ? this.inner.pose() : null;
      }
   }

   /**
    * Base de dos hijos (vtable 0x476e30, FUN_0043a150): A en +0xc, B en
    * +0x14, tiempo {s, ms} en +0x18 y duracion en +0x20.
    */
   abstract static class Transition extends Node {
      Node a;
      Node b;
      AnimTime elapsed = AnimTime.ZERO;
      final AnimTime duration;

      Transition(Node a, Node b, AnimTime duration) {
         this.a = a;
         this.b = b;
         this.duration = duration;
      }

      /**
       * FUN_00439fb0: avanza los dos; si A termina queda B, si B termina
       * queda A.
       */
      Node advanceBoth(float amount, AnimTime dt) {
         if (this.a != null) {
            this.a = this.a.advance(amount, dt);
         }
         if (this.b != null) {
            this.b = this.b.advance(amount, dt);
         }
         if (this.a == null) {
            return this.b;
         }
         if (this.b == null) {
            return this.a;
         }
         return this;
      }

      /** tiempo / duracion en segundos, sin recortar. */
      double ratio() {
         return this.elapsed.seconds() / this.duration.seconds();
      }

      abstract float weight();

      abstract AnimPose blend(AnimPose pa, AnimPose pb, float r);

      /**
       * FUN_0043a290 / FUN_0043a880 (misma forma): mezcla la pose de A (o
       * una vacia) con la de B (o una vacia) con el peso de [4]; sin A ni B,
       * pose vacia.
       */
      public AnimPose pose() {
         float r = this.weight();
         if (this.a != null) {
            return this.blend(this.a.pose(), this.b == null ? AnimPose.empty() : this.b.pose(), r);
         }
         if (this.b == null) {
            return AnimPose.empty();
         }
         return this.blend(AnimPose.empty(), this.b.pose(), r);
      }
   }

   /**
    * Cambio de implicito "shiftto" (vtable 0x476e14, FUN_0043a6f0), creado
    * por FUN_00432d10 con duracion {0 s, 0xfa = 250 ms}.
    */
   public static final class ShiftTo extends Transition {
      ShiftTo(Node from, Node to, AnimTime duration) {
         super(from, to, duration);
      }

      /**
       * FUN_0043a1f0: tiempo += dt; al llegar a la duracion el nodo se
       * sustituye por lo que devuelva B al avanzar; antes avanzan los dos.
       */
      public Node advance(float amount, AnimTime dt) {
         this.elapsed = this.elapsed.plus(dt);
         if (this.elapsed.greaterOrEqual(this.duration)) {
            return this.b == null ? null : this.b.advance(amount, dt);
         }
         return this.advanceBoth(amount, dt);
      }

      /** FUN_0043a540: clamp(tiempo / duracion, 0, 1) (DAT_004767b4 = 0, DAT_004767b8 = 1). */
      float weight() {
         double f = this.ratio();
         if (f < 0.0 || Double.isNaN(f)) {
            f = 0.0;
         }
         if (1.0 < f) {
            f = 1.0;
         }
         return (float) f;
      }

      /** FUN_0043bde0. */
      AnimPose blend(AnimPose pa, AnimPose pb, float r) {
         return AnimPose.blendImplicit(pa, pb, r);
      }
   }

   /**
    * Explicito encima del implicito (vtable 0x476df8, FUN_0043ad60),
    * creado por FUN_00432d10 con la duracion del pipe del explicito.
    */
   public static final class Overlay extends Transition {
      Overlay(Node under, Node gesture, AnimTime duration) {
         super(under, gesture, duration);
      }

      /**
       * FUN_0043a7e0: tiempo += dt; al llegar a la duracion vuelve a lo que
       * habia debajo (A avanza y se devuelve); antes avanzan los dos (y si
       * el pipe del gesto termina antes, tambien queda A).
       */
      public Node advance(float amount, AnimTime dt) {
         this.elapsed = this.elapsed.plus(dt);
         if (this.elapsed.greaterOrEqual(this.duration)) {
            return this.a == null ? null : this.a.advance(amount, dt);
         }
         return this.advanceBoth(amount, dt);
      }

      /**
       * FUN_0043ab30: con override.ini [Runtime] NoImpChange = 1, 1; si no,
       * x = clamp(tiempo / duracion, 0, 1) y peso = clamp(4 * x * (1 - x) * 2,
       * 0, 1) (DAT_004767f0 = 4, DAT_004767f4 = 2): entra en el primer
       * 14,6 % del gesto y sale en el ultimo.
       */
      float weight() {
         if (noImpChange()) {
            return 1.0F;
         }
         double f = this.ratio();
         if (f < 0.0 || Double.isNaN(f)) {
            f = 0.0;
         } else if (1.0 < f) {
            f = 1.0;
         }
         double w = 4.0 * f * (1.0 - f) * 2.0;
         if (w < 0.0 || Double.isNaN(w)) {
            w = 0.0;
         } else if (1.0 < w) {
            w = 1.0;
         }
         return (float) w;
      }

      /** FUN_0043beb0. */
      AnimPose blend(AnimPose pa, AnimPose pb, float r) {
         return AnimPose.blendExplicit(pa, pb, r);
      }
   }

   /**
    * GetPrivateProfileIntA("Runtime", "NoImpChange", 0, ".\\override.ini")
    * == 1 (FUN_004330a0, FUN_0043ab30). El override.ini instalado
    * (assets/WorldsPlayer/override.ini) no tiene esa clave: 0, falso. Se
    * puede forzar para las comprobaciones.
    */
   public static volatile boolean noImpChange;

   static boolean noImpChange() {
      return noImpChange;
   }
}
