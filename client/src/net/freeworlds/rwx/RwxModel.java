package net.freeworlds.rwx;

import java.util.ArrayList;
import java.util.List;

/**
 * Flattened parse result: all vertices already in the model's root space
 * (transforms baked in, matching the comparison harness's setFlatten(true)
 * reference mode - see tools/rwx-harness/extract.mjs).
 */
public final class RwxModel {
   public final List<RwxVector3> vertices = new ArrayList<>();
   public final List<int[]> triangles = new ArrayList<>(); // 3 indices into vertices
   public final List<RwxMaterial> triangleMaterials = new ArrayList<>(); // parallel to triangles
   public final List<String> warnings = new ArrayList<>();

   public int addVertex(RwxVector3 v) {
      vertices.add(v);
      return vertices.size() - 1;
   }

   public void addTriangle(int a, int b, int c, RwxMaterial mat) {
      triangles.add(new int[]{a, b, c});
      triangleMaterials.add(mat);
   }
}
