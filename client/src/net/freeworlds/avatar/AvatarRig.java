package net.freeworlds.avatar;

import net.freeworlds.bod.BodClump;
import net.freeworlds.bod.BodFile;
import net.freeworlds.bod.BodVertex;
import net.freeworlds.bod.SeqSampler;
import net.freeworlds.cmp.CmpTexture;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * Una figura de avatar .bod con sus joints, sin GL: lo que en el original
 * es el arbol de clumps del PosableShape despues de DroneAnimator.prepFigure
 * y al que FUN_00434470 aplica cada pose.
 *
 * <ul>
 * <li>Arbol: la misma regla que BodViewer (RWXTOBOD.PL: placeholders con
 *     traslacion de los que cuelga otra parte); LTM de RenderWare 2.1,
 *     LTM = Joint x Modelado x LTM_padre en vector fila (RWL21.DLL
 *     0x10004747/0x10004788). Joint del clump = cuaternion de su tag o
 *     identidad; placeholder = solo traslacion de modelado.</li>
 * <li>La figura es un clump sin geometria cuyo primer hijo es la pelvis (la
 *     parte raiz del .bod). {@link #prepFigure} fija su joint.</li>
 * <li>{@link #applyPose}: FUN_00434470.</li>
 * </ul>
 *
 * Las coordenadas que devuelve {@link #triangles} son las del sistema del
 * PosableShape (unidades de mundo, Z arriba): lo que queda es la matriz del
 * objeto en el mundo.
 */
public final class AvatarRig {
   /** Un clump del arbol. */
   private static final class Node {
      final int parent;
      /** Tag para el joint (RwFindTaggedClump); -1 = placeholder (sin joint). */
      final int tag;
      float tx, ty, tz;
      final BodClump clump;
      /** Aspecto del nombre de avatar (solo raices de parte) o null. */
      final AvatarLooks.Look look;
      final float[] ltm = new float[16];

      Node(int parent, int tag, float tx, float ty, float tz, BodClump clump, AvatarLooks.Look look) {
         this.parent = parent;
         this.tag = tag;
         this.tx = tx;
         this.ty = ty;
         this.tz = tz;
         this.clump = clump;
         this.look = look;
      }
   }

   /** Un triangulo colocado: 9 coordenadas, 6 UV, color y textura (o null). */
   public static final class Tri {
      public final float[] p = new float[9];
      public final float[] uv = new float[6];
      public float r, g, b;
      public CmpTexture texture;
      /** true si el material viene del nombre de avatar (constantes de PosableShape.scanTexture/readColor). */
      public boolean avatarMaterial;
   }

   private final List<Node> nodes = new ArrayList<>();
   /** Indice del nodo pelvis (parte raiz), hijo de la figura. */
   private final int pelvis;
   /** Joint actual de cada tag 1..30 (cuaternion w,x,y,z); FUN_00434470 deja los que no toca. */
   private final float[][] joints = new float[31][];
   /** Joint de la figura (prepFigure) en vector fila. */
   private float[] figureJoint = identity();
   public final int badIndices;
   public final int orphans;

   /**
    * Construye el arbol desde el .bod. La raiz es la parte a la que no
    * apunta ningun placeholder (pelvis, tag 1, en todo el corpus); las
    * partes que no cuelgan de ella se anaden sueltas a la figura (nunca
    * visto en el corpus), igual que BodViewer.
    */
   public AvatarRig(BodFile bod, Map<Integer, AvatarLooks.Look> looks) {
      Map<Integer, BodClump> partByTag = new HashMap<>();
      for (BodClump p : bod.parts) {
         partByTag.put(p.tag, p);
      }
      Set<Integer> referenced = new HashSet<>();
      for (BodClump p : bod.parts) {
         collectPlaceholders(p, referenced);
      }
      BodClump root = null;
      for (BodClump p : bod.parts) {
         if (!referenced.contains(p.tag)) {
            root = p;
            break;
         }
      }
      if (root == null) {
         root = partByTag.get(1);
      }
      if (root == null && !bod.parts.isEmpty()) {
         root = bod.parts.get(0);
      }
      // Nodo 0: la figura (sin geometria, sin tag).
      this.nodes.add(new Node(-1, -1, 0f, 0f, 0f, null, null));
      Set<Integer> visited = new HashSet<>();
      int[] bad = {0};
      int orph = 0;
      this.pelvis = root == null ? -1 : this.add(root, 0, true, looks, partByTag, visited, bad);
      for (BodClump p : bod.parts) {
         if (!visited.contains(p.tag)) {
            orph++;
            this.add(p, 0, true, looks, partByTag, visited, bad);
         }
      }
      this.badIndices = bad[0];
      this.orphans = orph;
      for (int t = 1; t < this.joints.length; t++) {
         this.joints[t] = new float[]{1f, 0f, 0f, 0f};
      }
   }

   private static void collectPlaceholders(BodClump c, Set<Integer> out) {
      if (c.placeholder) {
         out.add(c.tag);
         return;
      }
      if (c.children != null) {
         for (BodClump child : c.children) {
            collectPlaceholders(child, out);
         }
      }
   }

   private int add(BodClump c, int parent, boolean partRoot, Map<Integer, AvatarLooks.Look> looks,
         Map<Integer, BodClump> partByTag, Set<Integer> visited, int[] bad) {
      visited.add(c.tag);
      AvatarLooks.Look look = partRoot && looks != null ? looks.get(c.tag) : null;
      int me = this.nodes.size();
      this.nodes.add(new Node(parent, c.tag, c.tx, c.ty, c.tz, c, look));
      if (c.children != null) {
         for (BodClump child : c.children) {
            if (child.placeholder) {
               BodClump target = partByTag.get(child.tag);
               if (target == null) {
                  bad[0]++;
                  continue;
               }
               // Placeholder: clump sin joint con su traslacion de modelado;
               // la parte cuelga de el (WObject.addChildToClump nativo).
               int ph = this.nodes.size();
               this.nodes.add(new Node(me, -1, child.tx, child.ty, child.tz, null, null));
               this.add(target, ph, true, looks, partByTag, visited, bad);
            } else {
               this.add(child, me, false, looks, partByTag, visited, bad);
            }
         }
      }
      return me;
   }

   /**
    * m00 de la matriz de modelado de la pelvis, que lee FUN_00435520 para
    * la escala del walk: la del .bod es solo traslacion, asi que 1.
    */
   public float pelvisM00() {
      return 1.0F;
   }

   // ------------------------------------------------------------- prepFigure

   /** 1000 (DAT_0047552c). */
   static final float FIGURE_SCALE = 1000.0F;

   /**
    * DroneAnimator.prepFigure (0x00416470 -&gt; FUN_00434f00) con COG = false:
    * joint de la figura = T(traslacion de la pelvis) x S(1000) x R(180
    * grados sobre (0,1,1)) (RwRotateMatrix sustituir DAT_00475528 = 180,
    * eje DAT_00475524/20; RwScaleMatrix PRECONCAT; RwTranslateMatrix +
    * RwTransformClumpJoint PRECONCAT). R lleva (x,y,z) a (-x,z,y): el +Y del
    * .bod pasa a ser el +Z (arriba) y su +Z el +Y. La traslacion de la pelvis
    * pasa a 0 (FUN_00431990). Luego el punto (centro x, centro y, z minima)
    * de la caja del arbol en el mundo (FUN_00418900: el origen de la LTM de
    * la figura mas RwGetClumpBBox de cada clump) se lleva al sistema de la
    * figura y se resta despues del joint (POSTCONCAT); con COG = false solo
    * la z: los pies (o el origen, si queda mas abajo) quedan en z = 0.
    *
    * ⚠️ VERIFICAR: COG = true (recentrar x e y) no se porta: WorldRestorer
    * lee y descarta el COG de PosableShape (version 1), asi que aqui no hay
    * de donde sacarlo; PosableShape lo inicia a false. La caja se calcula
    * en el sistema de la figura, que es lo mismo que la del mundo llevada a
    * la figura mientras la matriz del objeto no incline el eje Z.
    */
   public void prepFigure() {
      float[] m1 = mul(scale(FIGURE_SCALE), rotate180Axis011());
      Node p = this.pelvis >= 0 ? this.nodes.get(this.pelvis) : null;
      if (p != null) {
         m1 = mul(translation(p.tx, p.ty, p.tz), m1);
         p.tx = 0f;
         p.ty = 0f;
         p.tz = 0f;
      }
      this.figureJoint = m1;
      this.updateLtms();
      // FUN_00418900: min = max = origen de la LTM de la figura.
      float zmin = this.figureJoint[14];
      for (Node n : this.nodes) {
         if (n.clump == null || n.clump.vertices == null) {
            continue;
         }
         for (BodVertex v : n.clump.vertices) {
            float z = v.x * n.ltm[2] + v.y * n.ltm[6] + v.z * n.ltm[10] + n.ltm[14];
            if (z < zmin) {
               zmin = z;
            }
         }
      }
      this.figureJoint = mul(this.figureJoint, translation(0f, 0f, -zmin));
      this.updateLtms();
   }

   /**
    * La matriz de RwRotateMatrix para 180 grados sobre (0,1,1): v' =
    * 2(n.v)n - v con n = (0,1,1)/sqrt(2), es decir (x,y,z) -&gt; (-x,z,y).
    * ⚠️ El binario la calcula en float con cos/sin de 180 grados; aqui van
    * los valores exactos (diferencia del orden de 1e-7).
    */
   static float[] rotate180Axis011() {
      return new float[]{-1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1};
   }

   // ------------------------------------------------------------- pose

   /**
    * FUN_00434470: aplica una pose a la figura. Entradas con clave &lt; 3:
    * la traslacion de raiz (clave 2) x 0.1 (DAT_00475490) va a la fila 3
    * del modelado de la pelvis, multiplicada por su diagonal (FUN_00431990,
    * 1 en el .bod); la rotacion de raiz (clave 1) no se aplica. Luego, para
    * los tags 1..30 en orden, el joint cuyo id (FUN_00429880) coincide con
    * la clave recibe su cuaternion si es de tipo 4/5/6 (FUN_00434610); un
    * tag sin entrada recibe la identidad; una entrada de otro tipo deja el
    * joint como estaba. Pose nula: todo identidad.
    */
   public void applyPose(AnimPose pose) {
      float[] ident = {1f, 0f, 0f, 0f};
      int tag = 1;
      if (pose != null) {
         List<AnimPose.Entry> es = pose.entries;
         int i = 0;
         for (; i < es.size() && es.get(i).key < 3; i++) {
            AnimPose.Entry e = es.get(i);
            if (e.key == 2 && this.pelvis >= 0) {
               float k = 0.1F;
               Node p = this.nodes.get(this.pelvis);
               p.tx = k * e.v[0];
               p.ty = k * e.v[1];
               p.tz = e.v[2] * k;
            }
         }
         while (tag < 0x1f && i < es.size()) {
            AnimPose.Entry e = es.get(i);
            int id = AnimSequence.tagId(tag);
            if (e.key < id) {
               i++;
            } else if (e.key <= id) {
               if (e.kind == 4 || e.kind == 5 || e.kind == 6) {
                  this.joints[tag] = e.v.clone();
               }
               tag++;
               i++;
            } else {
               this.joints[tag] = ident.clone();
               tag++;
            }
         }
      }
      for (; tag < 0x1f; tag++) {
         this.joints[tag] = ident.clone();
      }
      this.updateLtms();
   }

   /** Joint actual de un tag (para las comprobaciones). */
   public float[] joint(int tag) {
      return this.joints[tag].clone();
   }

   /** LTM (sistema de la figura) del primer clump con ese tag, o null. */
   public float[] ltmOfTag(int tag) {
      for (Node n : this.nodes) {
         if (n.tag == tag && n.clump != null) {
            return n.ltm.clone();
         }
      }
      return null;
   }

   /** Traslacion de modelado actual de la pelvis (para las comprobaciones). */
   public float[] pelvisTranslation() {
      Node p = this.nodes.get(this.pelvis);
      return new float[]{p.tx, p.ty, p.tz};
   }

   /** Joint de la figura (para las comprobaciones). */
   public float[] figureJoint() {
      return this.figureJoint.clone();
   }

   /**
    * LTM de cada clump: la figura tiene solo su joint; los demas Joint x
    * T(modelado) x LTM_padre, con el joint del tag normalizado y pasado a
    * matriz (FUN_00434610: FUN_00426f40 + FUN_00427040).
    */
   private void updateLtms() {
      for (int k = 0; k < this.nodes.size(); k++) {
         Node n = this.nodes.get(k);
         float[] local;
         if (n.parent < 0) {
            System.arraycopy(this.figureJoint, 0, n.ltm, 0, 16);
            continue;
         }
         local = translation(n.tx, n.ty, n.tz);
         if (n.tag >= 1 && n.tag < this.joints.length && n.clump != null) {
            float[] q = this.joints[n.tag].clone();
            AnimPose.normalize(q);
            local = mul(SeqSampler.quatToMatrix(q), local);
         }
         float[] out = mul(local, this.nodes.get(n.parent).ltm);
         System.arraycopy(out, 0, n.ltm, 0, 16);
      }
   }

   /** Los triangulos con la pose actual, en el sistema del PosableShape. */
   public List<Tri> triangles() {
      List<Tri> out = new ArrayList<>();
      for (Node n : this.nodes) {
         BodClump c = n.clump;
         if (c == null || c.vertices == null || c.vertices.isEmpty() || c.triangles == null) {
            continue;
         }
         List<BodVertex> v = c.vertices;
         float r = n.look != null ? n.look.r : (c.r & 0xFF) / 255f;
         float g = n.look != null ? n.look.g : (c.g & 0xFF) / 255f;
         float b = n.look != null ? n.look.b : (c.b & 0xFF) / 255f;
         for (int[] t : c.triangles) {
            if (t[0] < 0 || t[1] < 0 || t[2] < 0 || t[0] >= v.size() || t[1] >= v.size() || t[2] >= v.size()) {
               continue;
            }
            Tri tri = new Tri();
            for (int j = 0; j < 3; j++) {
               BodVertex a = v.get(t[j]);
               float[] m = n.ltm;
               tri.p[j * 3] = a.x * m[0] + a.y * m[4] + a.z * m[8] + m[12];
               tri.p[j * 3 + 1] = a.x * m[1] + a.y * m[5] + a.z * m[9] + m[13];
               tri.p[j * 3 + 2] = a.x * m[2] + a.y * m[6] + a.z * m[10] + m[14];
               tri.uv[j * 2] = a.u;
               tri.uv[j * 2 + 1] = a.v;
            }
            tri.r = r;
            tri.g = g;
            tri.b = b;
            tri.texture = n.look != null ? n.look.texture : null;
            tri.avatarMaterial = n.look != null;
            out.add(tri);
         }
      }
      return out;
   }

   /** Caja (min x,y,z, max x,y,z) de los triangulos con la pose actual. */
   public float[] bounds() {
      float[] b = {Float.MAX_VALUE, Float.MAX_VALUE, Float.MAX_VALUE, -Float.MAX_VALUE, -Float.MAX_VALUE, -Float.MAX_VALUE};
      for (Tri t : this.triangles()) {
         for (int j = 0; j < 9; j++) {
            b[j % 3] = Math.min(b[j % 3], t.p[j]);
            b[3 + j % 3] = Math.max(b[3 + j % 3], t.p[j]);
         }
      }
      return b;
   }

   // ------------------------------------------------------------- Transform.getYaw

   /**
    * Transform.getYaw (gamma.dll 0x00425440) de una matriz de objeto a
    * mundo (convencion vector fila, la misma disposicion que la de GL por
    * columnas): el eje (0,1,0) (DAT_00471bf8..c00) girado por la matriz sin
    * escala y ortonormalizada; con su parte horizontal (x, y) y r =
    * sqrt(x^2 + y^2): angulo = 180 * (0.5 * pi - atan2(x/r, sqrt(1 -
    * (x/r)^2))) * (1/pi) (DAT_00471c14 = 180, DAT_00471c18 = 0.5f,
    * DAT_00471c20 = 1/pi), 180 si x/r &lt;= -1 y 0 (DAT_00471c10) si &gt;= 1;
    * negado si y &lt; 0; yaw = 90 (DAT_00471c28) - angulo, mas 360
    * (DAT_00471c2c) si queda negativo. Es decir, 90 menos el rumbo del eje
    * Y del objeto, en grados, en [0, 360). Sin parte horizontal (r^2 &lt; 0,
    * DAT_00471c08) el binario devuelve NaN (DAT_004823b0) y pone errno 0x21.
    *
    * ⚠️ VERIFICAR: la escala se deshace con los xScale/yScale/zScale del
    * Transform y luego RwOrthoNormalizeMatrix; aqui se usa la direccion del
    * eje Y tal cual, que es lo mismo mientras la matriz no este sesgada.
    */
   public static float transformYaw(float[] m) {
      // La norma del eje no cambia x/r: basta con la direccion.
      float vx = m[4];
      float vy = m[5];
      float r2 = vx * vx + vy * vy;
      if (r2 < 0f) {
         return Float.NaN;
      }
      float r = (float) Math.sqrt(r2);
      float yaw;
      if (vx < r) {
         if (-r < vx) {
            double f = (double) vx / (double) r;
            double a = Math.atan2(f, Math.sqrt(1.0 - f * f));
            yaw = 180.0F * (float) (0.5 * Math.PI - a) * (float) (1.0 / Math.PI);
         } else {
            yaw = 180.0F;
         }
      } else {
         yaw = 0.0F;
      }
      if (vy < 0.0F) {
         yaw = -yaw;
      }
      yaw = 90.0F - yaw;
      if (yaw < 0.0F) {
         yaw += 360.0F;
      }
      return yaw;
   }

   // ------------------------------------------------------------- matrices (vector fila)

   static float[] identity() {
      return new float[]{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
   }

   static float[] translation(float x, float y, float z) {
      return new float[]{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, x, y, z, 1};
   }

   static float[] scale(float s) {
      return new float[]{s, 0, 0, 0, 0, s, 0, 0, 0, 0, s, 0, 0, 0, 0, 1};
   }

   /** a x b fila-mayor (producto de RWL21.DLL 0x1005118c). */
   static float[] mul(float[] a, float[] b) {
      float[] o = new float[16];
      for (int i = 0; i < 4; i++) {
         for (int j = 0; j < 4; j++) {
            float s = 0f;
            for (int k = 0; k < 4; k++) {
               s += a[i * 4 + k] * b[k * 4 + j];
            }
            o[i * 4 + j] = s;
         }
      }
      return o;
   }
}
