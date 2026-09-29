package NET.worlds.core;

import java.util.Vector;

/**
 * Los nativos de NET.worlds.scape.DroneAnimator (gamma.dll 0x00416280..
 * 0x00416740). Los envoltorios JNI son finos: la logica esta en el motor de
 * animacion de gamma.dll (0x0042b000..0x0043c500), traducido aqui y en las
 * clases Anim* de este paquete. Evidencia por direccion en cada metodo;
 * resumen en docs/seq-animation-reference.md.
 */
public final class NativeAnimator {
   private NativeAnimator() {
   }

   /** DAT_004a0118: el directorio que recibe init (FUN_0042f6b0). */
   private static String home = ".";

   /**
    * DroneAnimator.init (0x00416280 -> FUN_004349d0): fija las cadenas de
    * configuracion (".seq" DAT_004754f0, ".zip" DAT_004754f8, el directorio,
    * "\\" DAT_00475500 y "avatars" DAT_00475504 para las rutas
    * "%s/%s" DAT_00474cc8), registra los ids de los tags 1..30
    * (FUN_004298b0) y vacia el registro (FUN_0042ca50). El envoltorio
    * busca ademas java.util.Vector para getActionList.
    */
   public static synchronized void init(String path) {
      home = path == null ? "" : AnimRegistry.str(path);
      AnimSeqCache.registerTags();
      AnimRegistry.get().clear();
   }

   /** DAT_0049fe1c / DAT_004a021c: sprintf("%s/%s", directorio, "avatars"). */
   static String avatarDir() {
      return home + "/avatars";
   }

   /**
    * DroneAnimator.loadconfig (0x00416360 -> FUN_00434b70): vacia el
    * registro y, si hay ruta, lee el fichero con Archive.readTextFile
    * (FUN_00403e80 -> FUN_00403eb0, que quita los CR) y lo analiza
    * (FUN_0042cb90). ⚠️ VERIFICAR: un error de sintaxis es un throw de C++
    * cuyo catch no esta localizado; aqui se avisa y se conservan los tipos
    * leidos hasta el error.
    */
   public static void loadconfig(String path) {
      AnimRegistry reg = AnimRegistry.get();
      reg.clear();
      if (path == null) {
         return;
      }
      byte[] text = Archive.readTextFile(path);
      if (text == null) {
         return;
      }
      try {
         reg.load(text, path);
      } catch (AnimRegistry.ParseError e) {
         System.err.println("[DroneAnimator] " + path + ": " + e.getMessage());
      }
   }

   /** DroneAnimator.getnameindex (0x004163b0 -> FUN_00434ce0 -> FUN_0042c8a0). */
   public static int getnameindex(String name) {
      int i = AnimRegistry.get().nameIndex(name);
      if (AnimAnimator.LOG) {
         System.out.println("[anim] getnameindex(" + name + ") = " + i + " de " + AnimRegistry.get().size());
      }
      return i;
   }

   /**
    * DroneAnimator.getindexgeom (0x004163f0 -> FUN_00434d10): "" si el tipo
    * no existe o no tiene geometry; si no, "&lt;dir&gt;/avatars" + "\\" +
    * geometry (FUN_0042f750 + FUN_0042f950 + strcat).
    */
   public static String getindexgeom(int type) {
      AnimRegistry.AvatarType t = AnimRegistry.get().type(type);
      if (t == null) {
         return "";
      }
      String geom = t.attr("geometry");
      if (geom.isEmpty()) {
         return "";
      }
      return avatarDir() + "\\" + geom;
   }

   /**
    * DroneAnimator.getActionList (0x004166c0): un Vector nuevo
    * (FUN_00415a40) con las claves de los explicitos del tipo en el orden
    * del fichero (FUN_00434e50 + callback 0x00416680 -> addElement); vacio
    * si el tipo no existe.
    */
   public static Vector<String> getActionList(int type) {
      Vector<String> v = new Vector<String>();
      AnimRegistry.AvatarType t = AnimRegistry.get().type(type);
      if (t != null) {
         for (String k : t.expKeys) {
            v.addElement(k);
         }
      }
      return v;
   }

   // ------------------------------------------------------------- tipos y secuencias

   /** DroneAnimator.addtype (0x00416430 -> FUN_00434ec0 -> FUN_0042b160). */
   public static void addtype(int type) {
      if (AnimAnimator.LOG) {
         AnimRegistry.AvatarType t = AnimRegistry.get().type(type);
         System.out.println("[anim] addtype " + type + " " + (t == null ? "?" : t.attr("name")));
      }
      AnimSeqCache.addType(type);
   }

   /** DroneAnimator.deltype (0x00416450 -> FUN_00434ee0 -> FUN_0042b280). */
   public static void deltype(int type) {
      AnimSeqCache.delType(type);
   }

   /**
    * PendingCacheDrone.nativeInit (0x0044bd00): guarda el JNIEnv y los ids
    * de downloadSeqFile/getAvatarDatPath. En Java la llamada es directa
    * (AnimSeqCache.requester): no hay nada que guardar.
    */
   public static void nativeInit() {
   }

   /** PendingCacheDrone.notifySeqLoaded (0x0044bda0). */
   public static void notifySeqLoaded(int handle, String path) {
      AnimSeqCache.notifySeqLoaded(handle, path);
   }

   // ------------------------------------------------------------- representaciones

   /** El objeto de 8 bytes de CreateRep (FUN_004350c0): el animador. */
   static final class Rep {
      final AnimAnimator animator;
      final AnimMotion.State state;

      Rep(AnimTime now) {
         this.animator = new AnimAnimator(now);
         this.state = new AnimMotion.State(now);
      }
   }

   /** FUN_004279e0: la hora actual de FUN_00402c10 (Std.nativeGetMillis, NativeInput.millis). */
   static AnimTime now() {
      return AnimTime.ofMillis(NativeInput.millis());
   }

   private static final java.util.Map<Integer, Rep> reps = new java.util.HashMap<Integer, Rep>();
   private static int nextRep = 1;

   static synchronized Rep rep(int h) {
      return reps.get(h);
   }

   /** Para las comprobaciones: el animador de un handle de CreateRep. */
   public static AnimAnimator animator(int h) {
      Rep r = rep(h);
      return r == null ? null : r.animator;
   }

   /**
    * DroneAnimator.CreateRep (0x004164a0): FUN_004350c0(this, 0, 1) -&gt;
    * FUN_00432880 con tipo de movimiento 0 (el salto de 0x0043293a por la
    * tabla 0x47542c lleva a 0x432941: objeto de 0x50 bytes, FUN_004313b0),
    * activo = 1 y FUN_00433420. Devuelve un handle donde el original
    * devuelve el puntero.
    */
   public static synchronized int CreateRep() {
      int h = nextRep++;
      reps.put(h, new Rep(now()));
      return h;
   }

   /** DroneAnimator.DestroyRep (0x004164d0). */
   public static synchronized void DestroyRep(int h) {
      reps.remove(h);
   }

   /** DroneAnimator.endanimations (0x00416500 -> FUN_004351a0 -> FUN_00433420). */
   public static void endanimations(int h) {
      Rep r = rep(h);
      if (r != null) {
         r.animator.reset();
      }
   }

   /**
    * DroneAnimator.animate (0x004165c0 -> FUN_004355a0): el nombre pasa a
    * minusculas (FUN_004280b0), se busca entre los explicitos del tipo
    * (FUN_00433e90) y se arranca (FUN_00432d10 con implicito -1); devuelve
    * su duracion en segundos, o 0.0 (DAT_00475524) si no existe. El tiempo
    * que recibe se convierte a {s, ms} (FUN_00427a20) y no se usa.
    */
   public static float animate(int h, int type, String name) {
      Rep r = rep(h);
      if (r == null || name == null) {
         return 0.0F;
      }
      int idx = AnimAnimator.explicitIndex(type, AnimRegistry.lower(name));
      if (idx == -1) {
         return 0.0F;
      }
      return r.animator.play(type, -1, idx);
   }

   /** DroneAnimator.getAnimationTime (0x00416620 -> FUN_00435630 -> FUN_00432be0). */
   public static float getAnimationTime(int h, int type, String name) {
      Rep r = rep(h);
      if (r == null || name == null) {
         return 0.0F;
      }
      int idx = AnimAnimator.explicitIndex(type, AnimRegistry.lower(name));
      if (idx == -1) {
         return 0.0F;
      }
      return r.animator.duration(type, idx);
   }

   // ------------------------------------------------------------- movimiento y pose

   /** pi (DAT_00475530, double) y 1/180 (DAT_00475538, double). */
   private static final double PI = 3.141592653589793;
   private static final double INV_180 = 0.005555555555555556;

   /**
    * DroneAnimator.moveto (0x00416530 -> FUN_004351b0): posicion (x, y, z)
    * y orientacion de eje Z (0x49f398 = (0,0,1), iniciado en 0x42856c) y
    * angulo yaw * pi * 1/180 (fild + fmull + fmull, a float), tiempo en ms.
    * PosableShape le pasa (short) x/y/z, (short) -yaw en grados y
    * Std.getRealTime() - 1.
    */
   public static void moveto(int h, int type, short x, short y, short z, short yaw, int time) {
      Rep r = rep(h);
      if (r == null) {
         return;
      }
      float[] p = {(float) x, (float) y, (float) z};
      float[] q = AnimMotion.axisAngle(0f, 0f, 1f, (float) ((double) yaw * PI * INV_180));
      if (AnimAnimator.LOG && r.state.lastChange.same(AnimTime.ZERO)) {
         System.out.println("[anim] primer moveto rep " + h + " tipo " + type + " en (" + x + "," + y + "," + z + ") yaw " + yaw + " t " + time);
      }
      r.animator.moved(r.state, type, p, q, AnimTime.ofMillis(time));
   }

   /**
    * DroneAnimator.moveby (0x00416580 -> FUN_004352f0): la posicion del
    * movimiento del animador (FUN_00433610) + (dx, dy, 0) y su orientacion
    * (FUN_004336a0) por el giro dyaw (FUN_00429150 = producto de Hamilton,
    * sin normalizar); luego como moveto.
    */
   public static void moveby(int h, int type, short dx, short dy, short dyaw, int time) {
      Rep r = rep(h);
      if (r == null) {
         return;
      }
      float[] p;
      float[] cur;
      synchronized (r.animator) {
         AnimMotion m = r.animator.motion;
         p = new float[]{m.pos[0] + (float) dx, m.pos[1] + (float) dy, m.pos[2] + 0f};
         cur = m.quat.clone();
      }
      float[] d = AnimMotion.axisAngle(0f, 0f, 1f, (float) ((double) dyaw * PI * INV_180));
      r.animator.moved(r.state, type, p, AnimMotion.mul(cur, d), AnimTime.ofMillis(time));
   }

   /**
    * DroneAnimator.update (0x00416740 -> FUN_00435520 -> FUN_00433710):
    * clump1/clump2 son los clumpID de los dos WObject (FUN_00412cf0; 0 si
    * null). escala = 10 / (scaleX * (m00 * 1000)) (DAT_00475540,
    * DAT_0047552c), con m00 de la matriz de modelado del primer hijo de la
    * figura (la pelvis). PosableShape pasa (null, this, getRealTime(),
    * getScaleX(), lejos): el ultimo no se usa.
    */
   public static void update(int h, int clump1, int clump2, int time, float scaleX, boolean far) {
      Rep r = rep(h);
      if (r == null) {
         return;
      }
      float[] m = new float[16];
      NativeScene.getClumpMatrix(NativeScene.getFirstChild(clump2), m);
      float m1000 = m[0] * 1000.0F;
      float scale = 10.0F / (scaleX * m1000);
      r.animator.update(AnimTime.ofMillis(time), clump1, clump2, scale);
   }

   /**
    * FUN_00434470: aplica una pose a la figura. Entradas con clave &lt; 3:
    * la traslacion de raiz (clave 2) x 0.1 (DAT_00475490) va a la fila 3
    * del modelado del primer hijo, multiplicada por su diagonal
    * (FUN_00431990); la rotacion de raiz (clave 1) no se aplica. Luego,
    * para los tags 1..30 en orden, el joint cuyo id (FUN_00429880) coincide
    * con la clave recibe su cuaternion si es de tipo 4/5/6 (FUN_00434610:
    * RwFindTaggedClump + matriz de FUN_00427040 + RwTransformClumpJoint
    * sustituir); un tag sin entrada recibe la identidad; una entrada de
    * otro tipo deja el joint como estaba. Pose nula: todo identidad.
    */
   static void applyPose(AnimPose pose, int figure) {
      float[] ident = {1f, 0f, 0f, 0f};
      int tag = 1;
      if (pose != null) {
         java.util.List<AnimPose.Entry> es = pose.entries;
         int i = 0;
         for (; i < es.size() && es.get(i).key < 3; i++) {
            AnimPose.Entry e = es.get(i);
            if (e.key == 2) {
               int child = NativeScene.getFirstChild(figure);
               if (child != 0) {
                  float k = 0.1F;
                  rootTranslation(child, k * e.v[0], k * e.v[1], e.v[2] * k);
               }
            }
         }
         while (tag < 0x1f && i < es.size()) {
            AnimPose.Entry e = es.get(i);
            int id = AnimSeqCache.tagId(tag);
            if (e.key < id) {
               i++;
            } else if (e.key <= id) {
               if (e.kind == 4 || e.kind == 5 || e.kind == 6) {
                  setJoint(figure, tag, e.v);
               }
               tag++;
               i++;
            } else {
               setJoint(figure, tag, ident);
               tag++;
            }
         }
      }
      for (; tag < 0x1f; tag++) {
         setJoint(figure, tag, ident);
      }
   }

   /** FUN_00431990: fila 3 del modelado = diagonal * v (RwTransformClump sustituir). */
   static void rootTranslation(int clump, float x, float y, float z) {
      if (clump == 0) {
         return;
      }
      float[] m = new float[16];
      NativeScene.getClumpMatrix(clump, m);
      m[12] = m[0] * x;
      m[13] = m[5] * y;
      m[14] = m[10] * z;
      NativeScene.transformClump(clump, m, NativeRw.REPLACE);
   }

   /** FUN_00434610 + FUN_00431870. */
   static void setJoint(int figure, int tag, float[] quat) {
      int c = NativeScene.findTaggedClump(figure, tag);
      if (c == 0) {
         return;
      }
      float[] q = quat.clone();
      AnimPose.normalize(q);
      NativeScene.transformClumpJoint(c, net.openworlds.bod.SeqSampler.quatToMatrix(q), NativeRw.REPLACE);
   }

   /**
    * DroneAnimator.prepFigure (0x00416470 -> FUN_00434f00): matriz de joint
    * de la figura = escala 1000 (DAT_0047552c) por giro de 180 grados
    * (DAT_00475528) sobre (0,1,1) (DAT_00475524/20) (RwScaleMatrix modo 2
    * sobre RwRotateMatrix sustituir); la traslacion del primer hijo pasa
    * delante de esa matriz (RwTranslateMatrix + RwTransformClumpJoint modo
    * 2) y la del hijo se pone a 0 (FUN_00431990). Luego el punto (centro x,
    * centro y, z minima) de la caja del arbol en el mundo (FUN_00435690 ->
    * FUN_00418900: origen + RwGetClumpBBox de todos, 0.5 = DAT_00475544) se
    * lleva al sistema de la figura (inversa de modelado * LTM del padre) y
    * se resta despues del joint (modo 3); con COG = false solo la z.
    */
   public static void prepFigure(int clump, boolean cog) {
      if (clump == 0) {
         return;
      }
      if (AnimAnimator.LOG) {
         float[] l = new float[16];
         NativeScene.getClumpLTM(clump, l);
         System.out.println("[anim] prepFigure clump " + clump + " COG " + cog + " en (" + l[12] + "," + l[13] + "," + l[14] + ")");
      }
      float[] m1 = NativeRw.identity();
      float[] m2 = NativeRw.identity();
      NativeRw.rotate(m1, 0.0F, 1.0F, 1.0F, 180.0F, NativeRw.REPLACE);
      NativeRw.scale(m1, 1000.0F, 1000.0F, 1000.0F, NativeRw.PRECONCAT);
      NativeScene.transformClumpJoint(clump, m1, NativeRw.REPLACE);
      int child = NativeScene.getFirstChild(clump);
      if (child != 0) {
         float[] cm = new float[16];
         NativeScene.getClumpMatrix(child, cm);
         NativeRw.translate(m1, cm[12], cm[13], cm[14], NativeRw.REPLACE);
         NativeScene.transformClumpJoint(clump, m1, NativeRw.PRECONCAT);
         rootTranslation(child, 0f, 0f, 0f);
      }
      float[] box = treeBox(clump);
      float cx = (box[3] + box[0]) * 0.5F;
      float cy = (box[4] + box[1]) * 0.5F;
      float cz = box[2];
      NativeScene.getClumpMatrix(clump, m1);
      int parent = NativeScene.getClumpParent(clump);
      if (parent != 0) {
         NativeScene.getClumpLTM(parent, m2);
         NativeRw.transformMatrix(m1, m2, NativeRw.POSTCONCAT);
      }
      NativeRw.invert(m1, m2);
      float[] p = NativeRw.transformPoint(m2, cx, cy, cz);
      if (!cog) {
         p[1] = 0.0F;
         p[0] = 0.0F;
      }
      NativeRw.translate(m1, -p[0], -p[1], -p[2], NativeRw.REPLACE);
      NativeScene.transformClumpJoint(clump, m1, NativeRw.POSTCONCAT);
   }

   /**
    * FUN_00418900: min = max = RwGetClumpOrigin (traslacion de la LTM) y
    * luego RwForAllClumpsInHierarchyPointer (hijos primero, luego el
    * propio clump) con el callback 0x418670, que amplia con cada
    * RwGetClumpBBox (min si es menor, max si es mayor).
    */
   static float[] treeBox(int clump) {
      float[] ltm = new float[16];
      NativeScene.getClumpLTM(clump, ltm);
      float[] b = {ltm[12], ltm[13], ltm[14], ltm[12], ltm[13], ltm[14]};
      grow(clump, b);
      return b;
   }

   private static void grow(int clump, float[] b) {
      for (int k : NativeScene.childHandles(clump)) {
         grow(k, b);
      }
      float[] c = NativeScene.getClumpBBox(clump);
      for (int j = 0; j < 3; j++) {
         if (c[j] < b[j]) {
            b[j] = c[j];
         }
         if (c[3 + j] > b[3 + j]) {
            b[3 + j] = c[3 + j];
         }
      }
   }
}
