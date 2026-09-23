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
      return AnimRegistry.get().nameIndex(name);
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
      final AnimAnimator animator = new AnimAnimator();
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
      reps.put(h, new Rep());
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
}
