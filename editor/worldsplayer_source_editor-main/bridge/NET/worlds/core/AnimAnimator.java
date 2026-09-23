package NET.worlds.core;

import java.util.ArrayList;
import java.util.List;

/**
 * El animador de un avatar (objeto de 0x3c bytes, FUN_00432880):
 *
 * <pre>
 * +0x00  movimiento (0x50 bytes, FUN_004313b0; lo usa update)
 * +0x05  activo (param_2 != 0; CreateRep pasa 1)
 * +0x08  W1: hueco de los implicitos (placeholder)
 * +0x10  W2: raiz, un placeholder que contiene W1 o los explicitos encima
 * +0x18  claves de los implicitos del tipo (copia)
 * +0x24  secuencias de los implicitos (copia, la cambian los changeimp)
 * +0x30  tipo actual (-1)
 * +0x34  implicito actual (1)
 * +0x38  ultimo explicito (0)
 * </pre>
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

   final boolean active = true;
   AnimGraph.Placeholder w1;
   AnimGraph.Placeholder root;
   final List<String> impKeys = new ArrayList<String>();
   final List<String> impValues = new ArrayList<String>();
   int type = -1;
   int imp = 1;
   int exp = 0;

   AnimAnimator() {
      this.reset();
   }

   /**
    * FUN_00433420 (tambien endanimations): implicito 1, explicito 0, W1 =
    * placeholder(pipe vacio) y raiz = placeholder(W1). No toca el tipo ni
    * las listas de implicitos.
    */
   synchronized void reset() {
      this.imp = 1;
      this.exp = 0;
      this.w1 = new AnimGraph.Placeholder(AnimGraph.emptyPipe());
      this.root = new AnimGraph.Placeholder(this.w1);
   }

   /**
    * FUN_004330a0: si cambia el tipo copia sus implicitos; si expIdx
    * (1..n) tiene un bloque changeimp y NoImpChange != 1, sustituye las
    * secuencias de esos implicitos. ⚠️ Error del original: si una clave del
    * bloque no esta entre los implicitos, compara con el final de la lista
    * de EXPLICITOS (0x433378 contra -0x164 = FUN_0042bd40) y escribe una
    * posicion mas alla del vector; como nadie lee esa posicion aqui se
    * ignora.
    */
   boolean applyChangeImp(int type, int expIdx) {
      AnimRegistry.AvatarType t = AnimRegistry.get().type(type);
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
      if (name.isEmpty() || AnimRegistry.get().type(type) == null) {
         return AnimGraph.emptyPipe();
      }
      int j = this.impKeys.indexOf(name);
      if (j < 0) {
         return AnimGraph.emptyPipe();
      }
      return AnimGraph.pipe(this.impValues.get(j), IMP_ARG1[idx], IMP_ARG2[idx]);
   }

   /** FUN_00433f70: pipe del explicito idx (1..n) por tiempo y modo 0, o null. */
   static AnimGraph.Pipe explicitPipe(int type, int idx) {
      AnimRegistry.AvatarType t = AnimRegistry.get().type(type);
      if (t == null) {
         return null;
      }
      int i = idx - 1;
      if (i < 0 || t.expValues.size() <= i) {
         return null;
      }
      return AnimGraph.pipe(t.expValues.get(i), 1, 0);
   }

   /** FUN_00433e90: indice 1..n del explicito por su clave (strcmp) o -1. */
   static int explicitIndex(int type, String lowerName) {
      AnimRegistry.AvatarType t = AnimRegistry.get().type(type);
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
   public synchronized float play(int type, int impIdx, int expIdx) {
      if (!this.active) {
         return 0.0F;
      }
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
         AnimGraph.Pipe p = explicitPipe(type, this.exp);
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
    * El paso de grafo de FUN_00433710: raiz = raiz.avanzar(cantidad, dt)
    * (vtable +4 sobre +0x14, FUN_00434350 guarda el resultado).
    */
   public synchronized void step(float amount, AnimTime dt) {
      // W2 es un placeholder (FUN_00439aa0), que siempre se devuelve a si mismo.
      this.root.advance(amount, dt);
   }

   /** La pose de la raiz (vtable +8 sobre +0x14). */
   public synchronized AnimPose pose() {
      return this.root.pose();
   }

   /** Para las comprobaciones: implicito actual (+0x34). */
   public synchronized int implicitIndex() {
      return this.imp;
   }

   /** Para las comprobaciones: ¿la raiz tiene solo el hueco de implicitos (ningun explicito encima)? */
   public synchronized boolean onlyImplicit() {
      return this.root.inner == this.w1;
   }

   /** Para las comprobaciones: el nodo del hueco de implicitos. */
   public synchronized AnimGraph.Node implicitNode() {
      return this.w1.inner;
   }

   /**
    * FUN_00432be0: duracion del explicito idx (crea su pipe, lo que pide
    * la secuencia si hace falta); 0 si idx &lt; 0.
    */
   synchronized float duration(int type, int expIdx) {
      if (!this.active || expIdx < 0) {
         return 0.0F;
      }
      AnimGraph.Pipe p = explicitPipe(type, expIdx);
      return p == null ? 0.0F : (float) p.duration().seconds();
   }
}
