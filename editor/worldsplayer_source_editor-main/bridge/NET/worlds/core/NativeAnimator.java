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
    * "%s/%s" DAT_00474cc8) y vacia el registro (FUN_0042ca50). El envoltorio
    * busca ademas java.util.Vector para getActionList.
    */
   public static synchronized void init(String path) {
      home = path == null ? "" : AnimRegistry.str(path);
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
}
