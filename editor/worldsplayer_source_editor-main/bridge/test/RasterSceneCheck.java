import NET.worlds.core.NativeScene;

/**
 * RwDestroyScene (RWL21 0x100306b0) en el puente: destruye las luces y
 * cada clump de la escena (padres e hijos, cada uno por su nodo); un clump
 * de otra escena no se toca.
 */
public final class RasterSceneCheck {
   public static void main(String[] args) {
      int failures = 0;
      int s = NativeScene.createScene();
      int other = NativeScene.createScene();
      int root = NativeScene.createClump();
      int child = NativeScene.createClump();
      int grandchild = NativeScene.createClump();
      int outside = NativeScene.createClump();
      NativeScene.addChildToClump(child, grandchild);
      NativeScene.addChildToClump(root, child);
      NativeScene.addClumpToScene(s, root);
      NativeScene.addClumpToScene(other, outside);
      int light = NativeScene.createLight(1, 0, 0, -1, 1.0F);
      NativeScene.addLightToScene(s, light);
      NativeScene.destroyScene(s);
      if (NativeScene.clump(root) != null || NativeScene.clump(child) != null || NativeScene.clump(grandchild) != null) {
         System.out.println("FALLA: quedan clumps de la escena destruida");
         failures++;
      }
      if (NativeScene.light(light) != null) {
         System.out.println("FALLA: queda la luz");
         failures++;
      }
      if (NativeScene.scene(s) != null || NativeScene.clump(outside) == null || NativeScene.scene(other) == null) {
         System.out.println("FALLA: escena propia viva u otra escena tocada");
         failures++;
      }
      if (failures != 0) {
         System.exit(1);
      }
      System.out.println("RasterSceneCheck OK");
   }
}
