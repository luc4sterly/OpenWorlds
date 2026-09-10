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
   /** Per-vertex texture coordinates, parallel to {@link #vertices}.
    * Parsed from the optional {@code UV u v} suffix on {@code Vertex}/
    * {@code VertexExt} lines (real corpus evidence: sball.rwx carries
    * {@code UV 0..1} per vertex; GROUNDZERO files also append
    * {@code Normal x y z} after it). Vertices without UV data get
    * {@code {0, 0}} - never null, never a crash. */
   public final List<float[]> uvs = new ArrayList<>();
   public final List<int[]> triangles = new ArrayList<>(); // 3 indices into vertices
   public final List<RwxMaterial> triangleMaterials = new ArrayList<>(); // parallel to triangles
   public final List<String> warnings = new ArrayList<>();

   public int addVertex(RwxVector3 v) {
      return addVertex(v, 0f, 0f);
   }

   public int addVertex(RwxVector3 v, float u, float vTex) {
      vertices.add(v);
      uvs.add(new float[]{u, vTex});
      return vertices.size() - 1;
   }

   public void addTriangle(int a, int b, int c, RwxMaterial mat) {
      triangles.add(new int[]{a, b, c});
      triangleMaterials.add(mat);
   }
}
