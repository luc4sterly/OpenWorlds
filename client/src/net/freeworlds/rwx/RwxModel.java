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
   /** Parallel to {@link #vertices}: the script vertex each copy comes from
    * (unique per clump and index; -1 when unknown). RenderWare lights a
    * LightSampling Vertex polygon with the normals of its SHARED vertices
    * (sum over the polygons that use the vertex), and the triangles here
    * each get their own copies. */
   public final List<Integer> vertexKeys = new ArrayList<>();
   /** Parallel to {@link #vertices}: the normal the script gave the vertex
    * ({@code Normal x y z} after the position), baked like the position
    * and of unit length, or null. RW uses it instead of the computed one. */
   public final List<float[]> vertexNormals = new ArrayList<>();
   /** Parallel to {@link #triangles}: the script polygon (Triangle, Quad or
    * Polygon) the triangle belongs to; RW lights and normals per polygon. */
   public final List<Integer> trianglePolygons = new ArrayList<>();

   public int addVertex(RwxVector3 v) {
      return addVertex(v, 0f, 0f);
   }

   public int addVertex(RwxVector3 v, float u, float vTex) {
      return addVertex(v, u, vTex, -1, null);
   }

   public int addVertex(RwxVector3 v, float u, float vTex, int key, float[] normal) {
      vertices.add(v);
      uvs.add(new float[]{u, vTex});
      vertexKeys.add(key);
      vertexNormals.add(normal);
      return vertices.size() - 1;
   }

   public void addTriangle(int a, int b, int c, RwxMaterial mat) {
      addTriangle(a, b, c, mat, triangles.size());
   }

   public void addTriangle(int a, int b, int c, RwxMaterial mat, int polygon) {
      triangles.add(new int[]{a, b, c});
      triangleMaterials.add(mat);
      trianglePolygons.add(polygon);
   }
}
