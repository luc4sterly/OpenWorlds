import NET.worlds.core.NativeScene;

/**
 * RwDestroyScene (RWL21 0x100306b0) in the bridge: destroys the lights and
 * every clump of the scene (parents and children, each through its node); a
 * clump of another scene is not touched.
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
         System.out.println("FAIL: clumps of the destroyed scene remain");
         failures++;
      }
      if (NativeScene.light(light) != null) {
         System.out.println("FAIL: the light remains");
         failures++;
      }
      if (NativeScene.scene(s) != null || NativeScene.clump(outside) == null || NativeScene.scene(other) == null) {
         System.out.println("FAIL: own scene still alive or another scene touched");
         failures++;
      }
      if (failures != 0) {
         System.exit(1);
      }
      System.out.println("RasterSceneCheck OK");
   }
}
