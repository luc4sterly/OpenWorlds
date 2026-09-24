package NET.worlds.core;

import java.util.ArrayList;
import java.util.List;

/**
 * Shape.convertSpecial (gamma.dll 0x0041f1b0 -> FUN_0041efd0 / FUN_0041ee70
 * / FUN_0041e780) en NativeShapes: nombre empaquetado en el tag, esquinas
 * (Q, P) del rectángulo vertical calculadas a mano, intercambio de x/z,
 * LTM, errores y recorrido en post-orden. Sale con 1 si algo falla.
 */
public final class ShapeSpecialCheck {
   private static int failures = 0;
   private static final List<String> made = new ArrayList<String>();

   public static void main(String[] args) {
      Object room = new Object() {
         public String toString() {
            return "sala";
         }
      };
      int scene = NativeScene.createScene();
      NativeScene.setSceneData(scene, room);

      // raíz: Rect (0x20000000) trasladada (10,0,0); hijo: portal "door"
      int root = NativeScene.createClump();
      NativeScene.setClumpTag(root, 0x20000000);
      float[] m = NativeRw.identity();
      NativeRw.translate(m, 10.0F, 0.0F, 0.0F, NativeRw.REPLACE);
      NativeScene.transformClump(root, m, NativeRw.REPLACE);
      // a=(0,0,0) b=(2,0,0) c=(2,3,0): base a-b, P=c sobre b -> Q=a, sin intercambio
      tri(root, new float[][]{{0, 0, 0}, {2, 0, 0}, {2, 3, 0}});
      // a=(0,0,0) b=(2,0,0) c=(0,3,0): P=c sobre a -> Q=b e intercambio x/z: P=(2,3,0) Q=(0,0,0)
      tri(root, new float[][]{{0, 0, 0}, {2, 0, 0}, {0, 3, 0}});
      // P por debajo de Q: nada (a=(0,3,0) b=(2,3,0) c=(2,0,0))
      tri(root, new float[][]{{0, 3, 0}, {2, 3, 0}, {2, 0, 0}});
      // base no horizontal: error y nada
      tri(root, new float[][]{{0, 0, 0}, {1, 1, 0}, {2, 2, 0}});

      int door = NativeScene.createClump();
      // "DOOR " en 6 bits (c - 0x20) desde el bit 24: D=0x24 O=0x2f O=0x2f R=0x32 ' '=0
      int tag = 0x40000000 | 0x24 << 24 | 0x2f << 18 | 0x2f << 12 | 0x32 << 6;
      NativeScene.setClumpTag(door, tag);
      // b.y = c.y: P=a; a sobre c -> Q=b con intercambio: P=(1,4,5) Q=(3,0,5)... ver abajo
      tri(door, new float[][]{{1, 4, 5}, {3, 0, 5}, {1, 0, 5}});
      NativeScene.addChildToClump(root, door);
      NativeScene.addClumpToScene(scene, root);

      NativeShapes.convertSpecial(root, new NativeShapes.SpecialSink() {
         public void make(Object r, String name, float[] q, float[] p) {
            made.add(r + " " + name + " " + v(q) + " " + v(p));
         }
      });
      // hijo primero (post-orden). door: a=(1,4,5) b=(3,0,5) c=(1,0,5): b.y=c.y -> P=a;
      // a sobre b? no; a sobre c (x 1, z 5) -> Q=b, con intercambio -> P=(1,4,5) sin tocar, Q=(3,0,5).
      // El LTM del hijo es el del padre por el suyo: (10,0,0) de traslación.
      eq("objetos", made.toString(),
         "[sala door (13,0,5) (11,4,5), sala null (10,0,0) (12,3,0), sala null (10,0,0) (12,3,0)]");

      // un clump fuera de escena (RwGetSceneData 0): nada
      made.clear();
      int loose = NativeScene.createClump();
      NativeScene.setClumpTag(loose, 0x20000000);
      tri(loose, new float[][]{{0, 0, 0}, {2, 0, 0}, {2, 3, 0}});
      NativeShapes.convertSpecial(loose, new NativeShapes.SpecialSink() {
         public void make(Object r, String name, float[] q, float[] p) {
            made.add(name);
         }
      });
      eq("sin escena no hace nada", made.size(), 0);

      // FUN_004189c0: los polígonos sin tag se retaguean 1..n en orden
      NativeScene.Clump rc = NativeScene.clump(root);
      eq("tag del polígono 1", rc.polys.get(0).tag, 1);
      eq("tag del polígono 4", rc.polys.get(3).tag, 4);

      if (failures > 0) {
         System.out.println(failures + " fallos");
         System.exit(1);
      }
      System.out.println("ShapeSpecialCheck OK");
   }

   private static void tri(int clump, float[][] pts) {
      int base = NativeScene.getNumVertices(clump);
      for (float[] p : pts) {
         NativeScene.addVertex(clump, p[0], p[1], p[2]);
      }
      NativeScene.addPolygon(clump, 3, new int[]{base + 1, base + 2, base + 3});
   }

   private static String v(float[] a) {
      return "(" + (int) a[0] + "," + (int) a[1] + "," + (int) a[2] + ")";
   }

   private static void eq(String what, Object got, Object want) {
      if (got == null ? want != null : !got.equals(want)) {
         failures++;
         System.out.println("FALLA " + what + ": " + got + " != " + want);
      }
   }

   private static void eq(String what, int got, int want) {
      eq(what, Integer.valueOf(got), Integer.valueOf(want));
   }
}
