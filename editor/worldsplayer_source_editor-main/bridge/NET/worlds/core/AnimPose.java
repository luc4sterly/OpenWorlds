package NET.worlds.core;

import java.util.ArrayList;
import java.util.List;

/**
 * A pose of gamma.dll's animation engine (0x14-byte object,
 * vtable 0x477238, FUN_0043bd40): a list of 0x1c-byte entries sorted
 * by key.
 *
 * <pre>
 * [0] key    1 = root rotation, 2 = root translation, 3.. = joint id (FUN_004296f0)
 * [1] kind   1/4/5/6 quaternion (w,x,y,z), 2 vector (x,y,z), 3 scalar, 0 other
 * [2..6]     the value
 * </pre>
 *
 * A "null" pose (pointer to 0) is null in Java and is not the same as an
 * empty pose (FUN_0043bc20): the blend (FUN_0043bf80) returns the other one
 * as is if one is null, but blends with the identity if it is empty.
 */
public final class AnimPose {
   public static final class Entry {
      public final int key;
      public final int kind;
      /** 4 floats (w,x,y,z) for quaternions, 3 for vectors, 1 for scalars. */
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

   /** FUN_0043bc20: empty pose. */
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

   // -------------------------------------------------------------- blend

   /** The two tables of blend functions (vtables 0x477210 and 0x4771fc). */
   interface Blend {
      Entry onlyA(Entry a);

      Entry onlyB(Entry b);

      Entry both(Entry a, Entry b);
   }

   /**
    * Blend function for the implicit animations (FUN_0043c230, vtable
    * 0x477210): only in A -&gt; interp(A, identity, r) (0x43c250); only in
    * B -&gt; interp(identity, B, r) (0x43c290); in both -&gt; interp(A, B, r)
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
    * Blend function for the explicit animations (FUN_0043c300, vtable
    * 0x4771fc): only in A -&gt; A untouched (0x43c320: copies the 7 words);
    * only in B -&gt; interp(identity, B, r) (0x43c360); in both -&gt;
    * interp(A, B, r) (0x43c3a0). That is why a gesture only moves the joints
    * of its .seq and the rest keeps following the implicit animation.
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

   /** FUN_0043bde0: blend of implicit animations with weight r. */
   static AnimPose blendImplicit(AnimPose a, AnimPose b, float r) {
      return merge(a, b, implicitBlend(r));
   }

   /** FUN_0043beb0: blend of explicit animations with weight r. */
   static AnimPose blendExplicit(AnimPose a, AnimPose b, float r) {
      return merge(a, b, explicitBlend(r));
   }

   /**
    * FUN_0043bf80: if A is null returns B (whatever it is); if B is null,
    * A; otherwise walks both lists, sorted by key, like a merge.
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
    * FUN_00439320: the neutral entry for that key and kind: identity
    * quaternion (1,0,0,0) for 1/4/5/6 (FUN_00428f10), zero vector for 2,
    * zero scalar for 3. For any other kind the binary leaves the value
    * uninitialized (stack); nobody uses those entries (interp copies them
    * and the application only reads 4/5/6), here they are 0.
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
    * FUN_00439450: interpolation according to A's kind. Quaternions: if
    * dot(B, A) &lt; 0, B is negated (FUN_004292a0, DAT_00473440 = -1) and
    * interpolated component-wise with normalization (FUN_00429310 ->
    * FUN_004271c0 + FUN_00426f40: only if |q|^2 &gt; 1e-5). Vectors:
    * A + r(B - A) (FUN_004294d0/004295a0/00429480). Scalars:
    * (B - A) r + A. Kind 0: copy of A.
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

   /** FUN_00426f40: (w^2 + z^2 + x^2 + y^2); normalizes only if |s| &gt; (float) 1e-5 (_DAT_00471d28). */
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
