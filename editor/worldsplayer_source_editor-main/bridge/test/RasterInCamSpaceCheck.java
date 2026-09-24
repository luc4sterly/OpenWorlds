import NET.worlds.core.NativeCamera;
import NET.worlds.core.NativeRw;
import NET.worlds.core.NativeScene;

/**
 * WObject.nativeInCamSpace (gamma.dll 0x00413910) en el puente
 * (NativeCamera.inCamSpace): origen de la LTM del clump pasado por la
 * inversa de la LTM de la camara; null sin camara/clump o con estado != 2.
 */
public final class RasterInCamSpaceCheck {
   private static int failures;

   private static void expect(String what, boolean ok) {
      if (!ok) {
         System.out.println("FALLA " + what);
         failures++;
      }
   }

   public static void main(String[] args) {
      int cam = NativeCamera.createCamera(64, 48, 0);
      int clump = NativeScene.createClump();
      float[] m = NativeRw.identity();
      m[12] = 13.0F;
      m[13] = 4.0F;
      m[14] = 5.0F;
      NativeScene.transformClump(clump, m, NativeRw.REPLACE);
      // camara en (10,0,0) sin girar: (13,4,5) - (10,0,0) = (3,4,5)
      NativeCamera.setPosition(cam, 10.0F, 0.0F, 0.0F);
      float[] p = NativeCamera.inCamSpace(cam, clump);
      expect("identidad: " + java.util.Arrays.toString(p), p != null && p[0] == 3.0F && p[1] == 4.0F && p[2] == 5.0F);
      // camara girada 90 grados sobre y: filas right=(0,0,-1), up=(0,1,0),
      // at=(1,0,0); el punto relativo (3,4,5) queda en (-5, 4, 3)
      float[] r = {0, 0, -1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 10, 0, 0, 1};
      NativeCamera.transformCamera(cam, r);
      p = NativeCamera.inCamSpace(cam, clump);
      expect("girada: " + java.util.Arrays.toString(p), p != null && Math.abs(p[0] + 5.0F) < 1e-5F
         && Math.abs(p[1] - 4.0F) < 1e-5F && Math.abs(p[2] - 3.0F) < 1e-5F);
      // estado OFF (1): RwGetClumpState != 2 -> false
      NativeScene.setClumpState(clump, 1);
      expect("clump OFF", NativeCamera.inCamSpace(cam, clump) == null);
      NativeScene.setClumpState(clump, 2);
      expect("sin camara", NativeCamera.inCamSpace(0, clump) == null);
      expect("sin clump", NativeCamera.inCamSpace(cam, 0) == null);
      if (failures != 0) {
         System.out.println(failures + " fallos");
         System.exit(1);
      }
      System.out.println("RasterInCamSpaceCheck OK");
   }
}
