package NET.worlds.core;

import java.util.ArrayList;
import java.util.List;

/**
 * Una pose del motor de animacion de gamma.dll (objeto de 0x14 bytes,
 * vtable 0x477238, FUN_0043bd40): lista de entradas de 0x1c bytes ordenada
 * por clave.
 *
 * <pre>
 * [0] clave  1 = rotacion de raiz, 2 = traslacion de raiz, 3.. = id de joint (FUN_004296f0)
 * [1] tipo   1/4/5/6 cuaternion (w,x,y,z), 2 vector (x,y,z), 3 escalar, 0 otro
 * [2..6]     el valor
 * </pre>
 *
 * Una pose "nula" (puntero a 0) es null en Java y no es lo mismo que una
 * pose vacia (FUN_0043bc20): la mezcla (FUN_0043bf80) devuelve la otra tal
 * cual si una es nula, pero mezcla con la identidad si esta vacia.
 */
public final class AnimPose {
   public static final class Entry {
      public final int key;
      public final int kind;
      /** 4 floats (w,x,y,z) en cuaterniones, 3 en vectores, 1 en escalares. */
      public final float[] v;

      public Entry(int key, int kind, float[] v) {
         this.key = key;
         this.kind = kind;
         this.v = v;
      }
   }

   public final List<Entry> entries;

   public AnimPose(List<Entry> entries) {
      this.entries = entries;
   }

   /** FUN_0043bc20: pose vacia. */
   public static AnimPose empty() {
      return new AnimPose(new ArrayList<Entry>());
   }

   public Entry find(int key) {
      for (Entry e : this.entries) {
         if (e.key == key) {
            return e;
         }
      }
      return null;
   }

   // ------------------------------------------------------------- mezcla

   /** Las dos tablas de funciones de mezcla (vtables 0x477210 y 0x4771fc). */
   interface Blend {
      Entry onlyA(Entry a);

      Entry onlyB(Entry b);

      Entry both(Entry a, Entry b);
   }

   /**
    * Funcion de mezcla de los implicitos (FUN_0043c230, vtable 0x477210):
    * solo en A -&gt; interp(A, identidad, r) (0x43c250); solo en B -&gt;
    * interp(identidad, B, r) (0x43c290); en las dos -&gt; interp(A, B, r)
    * (0x43c2d0).
    */
   static Blend implicitBlend(final float r) {
      return new Blend() {
         public Entry onlyA(Entry a) {
            return interp(a, identity(a.key, a.kind), r);
         }

         public Entry onlyB(Entry b) {
            return interp(identity(b.key, b.kind), b, r);
         }

         public Entry both(Entry a, Entry b) {
            return interp(a, b, r);
         }
      };
   }

   /**
    * Funcion de mezcla de los explicitos (FUN_0043c300, vtable 0x4771fc):
    * solo en A -&gt; A sin tocar (0x43c320: copia las 7 palabras); solo en
    * B -&gt; interp(identidad, B, r) (0x43c360); en las dos -&gt;
    * interp(A, B, r) (0x43c3a0). Por eso un gesto solo mueve los joints de
    * su .seq y el resto sigue con el implicito.
    */
   static Blend explicitBlend(final float r) {
      return new Blend() {
         public Entry onlyA(Entry a) {
            return a;
         }

         public Entry onlyB(Entry b) {
            return interp(identity(b.key, b.kind), b, r);
         }

         public Entry both(Entry a, Entry b) {
            return interp(a, b, r);
         }
      };
   }

   /** FUN_0043bde0: mezcla de implicitos con peso r. */
   static AnimPose blendImplicit(AnimPose a, AnimPose b, float r) {
      return merge(a, b, implicitBlend(r));
   }

   /** FUN_0043beb0: mezcla de explicitos con peso r. */
   static AnimPose blendExplicit(AnimPose a, AnimPose b, float r) {
      return merge(a, b, explicitBlend(r));
   }

   /**
    * FUN_0043bf80: si A es nula devuelve B (sea lo que sea); si B es nula,
    * A; si no, recorre las dos listas ordenadas por clave como un merge.
    */
   static AnimPose merge(AnimPose a, AnimPose b, Blend f) {
      if (a == null) {
         return b;
      }
      if (b == null) {
         return a;
      }
      List<Entry> out = new ArrayList<Entry>(a.entries.size() + b.entries.size());
      int i = 0;
      int j = 0;
      while (i < a.entries.size() && j < b.entries.size()) {
         Entry ea = a.entries.get(i);
         Entry eb = b.entries.get(j);
         if (ea.key < eb.key) {
            out.add(f.onlyA(ea));
            i++;
         } else if (eb.key < ea.key) {
            out.add(f.onlyB(eb));
            j++;
         } else {
            out.add(f.both(ea, eb));
            i++;
            j++;
         }
      }
      for (; i < a.entries.size(); i++) {
         out.add(f.onlyA(a.entries.get(i)));
      }
      for (; j < b.entries.size(); j++) {
         out.add(f.onlyB(b.entries.get(j)));
      }
      return new AnimPose(out);
   }

   /**
    * FUN_00439320: la entrada neutra de esa clave y tipo: cuaternion
    * identidad (1,0,0,0) en 1/4/5/6 (FUN_00428f10), vector 0 en 2, escalar
    * 0 en 3. En otro tipo el binario deja el valor sin inicializar (pila);
    * esas entradas no las usa nadie (interp las copia y la aplicacion solo
    * lee 4/5/6), aqui van a 0.
    */
   static Entry identity(int key, int kind) {
      switch (kind) {
         case 1:
         case 4:
         case 5:
         case 6:
            return new Entry(key, kind, new float[]{1f, 0f, 0f, 0f});
         case 2:
            return new Entry(key, kind, new float[3]);
         default:
            return new Entry(key, kind, new float[1]);
      }
   }

   /**
    * FUN_00439450: interpolacion segun el tipo de A. Cuaterniones: si
    * dot(B, A) &lt; 0 se niega B (FUN_004292a0, DAT_00473440 = -1) y se
    * interpola por componentes con normalizacion (FUN_00429310 ->
    * FUN_004271c0 + FUN_00426f40: solo si |q|^2 &gt; 1e-5). Vectores:
    * A + r(B - A) (FUN_004294d0/004295a0/00429480). Escalares:
    * (B - A) r + A. Tipo 0: copia de A.
    */
   static Entry interp(Entry a, Entry b, float r) {
      switch (a.kind) {
         case 0:
            return a;
         case 1:
         case 4:
         case 5:
         case 6: {
            float[] qa = a.v;
            float[] qb = b.v.clone();
            float dot = qb[3] * qa[3] + qb[2] * qa[2] + qb[0] * qa[0] + qb[1] * qa[1];
            if (dot < 0f) {
               for (int k = 0; k < 4; k++) {
                  qb[k] = qb[k] * -1f;
               }
            }
            float[] q = new float[4];
            for (int k = 0; k < 4; k++) {
               q[k] = (qb[k] - qa[k]) * r + qa[k];
            }
            normalize(q);
            return new Entry(a.key, a.kind, q);
         }
         case 2: {
            float[] va = a.v;
            float[] vb = b.v;
            float[] d = {vb[0] - va[0], vb[1] - va[1], vb[2] - va[2]};
            return new Entry(a.key, a.kind, new float[]{va[0] + r * d[0], va[1] + r * d[1], va[2] + r * d[2]});
         }
         case 3:
            return new Entry(a.key, a.kind, new float[]{(b.v[0] - a.v[0]) * r + a.v[0]});
         default:
            return new Entry(0, 0, new float[1]);
      }
   }

   /** FUN_00426f40: (w^2 + z^2 + x^2 + y^2); normaliza solo si |s| &gt; (float) 1e-5 (_DAT_00471d28). */
   static void normalize(float[] q) {
      float s = q[0] * q[0] + q[3] * q[3] + q[1] * q[1] + q[2] * q[2];
      if (Math.abs(s) <= (float) 1e-5) {
         return;
      }
      float len = (float) Math.sqrt(s);
      q[0] = q[0] / len;
      q[1] = q[1] / len;
      q[2] = q[2] / len;
      q[3] = q[3] / len;
   }
}
