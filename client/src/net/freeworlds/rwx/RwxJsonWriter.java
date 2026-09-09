package net.freeworlds.rwx;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

/**
 * Emits the same canonical JSON shape as tools/rwx-harness/extract.mjs
 * (the three-rwx-loader reference side of the comparison harness), so the
 * two can be diffed directly: deduplicated materials array (color as a
 * 6-hex-digit string, matching THREE.Color#getHexString()), and a
 * triangles array of {v: [[x,y,z]x3], material: <index into materials>},
 * sorted by the JSON text of `v` for order-independent comparison (the
 * two parsers may walk/group geometry differently while producing the
 * same model).
 */
public final class RwxJsonWriter {
   private RwxJsonWriter() {
   }

   public static String toJson(RwxModel model) {
      Map<String, Integer> materialIndex = new LinkedHashMap<>();
      List<RwxMaterial> materials = new ArrayList<>();
      List<String> triJson = new ArrayList<>();

      for (int i = 0; i < model.triangles.size(); i++) {
         int[] t = model.triangles.get(i);
         RwxMaterial mat = model.triangleMaterials.get(i);
         String key = materialKey(mat);
         Integer idx = materialIndex.get(key);
         if (idx == null) {
            idx = materials.size();
            materialIndex.put(key, idx);
            materials.add(mat);
         }

         RwxVector3 a = model.vertices.get(t[0]);
         RwxVector3 b = model.vertices.get(t[1]);
         RwxVector3 c = model.vertices.get(t[2]);
         String v = "[" + vec(a) + "," + vec(b) + "," + vec(c) + "]";
         triJson.add("{\"v\":" + v + ",\"material\":" + idx + "}");
      }

      triJson.sort(RwxJsonWriter::compareTriangleJson);

      StringBuilder sb = new StringBuilder();
      sb.append("{\"triangleCount\":").append(model.triangles.size());
      sb.append(",\"vertexCount\":").append(model.triangles.size() * 3);
      sb.append(",\"materialCount\":").append(materials.size());
      sb.append(",\"materials\":[");
      for (int i = 0; i < materials.size(); i++) {
         if (i > 0) {
            sb.append(',');
         }
         writeMaterial(sb, materials.get(i));
      }
      sb.append("],\"triangles\":[");
      for (int i = 0; i < triJson.size(); i++) {
         if (i > 0) {
            sb.append(',');
         }
         sb.append(triJson.get(i));
      }
      sb.append("],\"warnings\":[");
      for (int i = 0; i < model.warnings.size(); i++) {
         if (i > 0) {
            sb.append(',');
         }
         sb.append('"').append(escape(model.warnings.get(i))).append('"');
      }
      sb.append("]}");
      return sb.toString();
   }

   // Matches extract.mjs's triangles.sort((a, b) =>
   // JSON.stringify(a.v).localeCompare(JSON.stringify(b.v))) - plain
   // codepoint string comparison of the same v-array JSON text.
   private static int compareTriangleJson(String a, String b) {
      String va = a.substring(a.indexOf("\"v\":") + 4, a.indexOf(",\"material\""));
      String vb = b.substring(b.indexOf("\"v\":") + 4, b.indexOf(",\"material\""));
      return va.compareTo(vb);
   }

   private static String vec(RwxVector3 v) {
      return "[" + num(v.x) + "," + num(v.y) + "," + num(v.z) + "]";
   }

   private static String materialKey(RwxMaterial mat) {
      return hexColor(mat) + "|" + round(mat.opacity, 3) + "|" + (mat.opacity < 1.0f) + "|" + (mat.textureName == null ? "" : mat.textureName);
   }

   private static void writeMaterial(StringBuilder sb, RwxMaterial mat) {
      sb.append("{\"color\":\"").append(hexColor(mat)).append('"');
      sb.append(",\"opacity\":").append(numD(round(mat.opacity, 3)));
      sb.append(",\"transparent\":").append(mat.opacity < 1.0f);
      sb.append(",\"map\":").append(mat.textureName == null ? "null" : ("\"" + escape(mat.textureName) + "\""));
      sb.append('}');
   }

   // Matches THREE.Color#getHexString(): each channel clamped to [0,1],
   // scaled to [0,255], rounded, formatted as 2 lowercase hex digits.
   private static String hexColor(RwxMaterial mat) {
      return hex(mat.colorR) + hex(mat.colorG) + hex(mat.colorB);
   }

   private static String hex(float c) {
      int v = Math.round(clamp01(c) * 255f);
      String h = Integer.toHexString(v);
      return h.length() == 1 ? "0" + h : h;
   }

   private static float clamp01(float v) {
      return v < 0f ? 0f : (v > 1f ? 1f : v);
   }

   private static double round(float f, int dp) {
      double p = Math.pow(10, dp);
      return Math.round((double) f * p) / p;
   }

   private static String num(float f) {
      return numD(round(f, 5));
   }

   private static String numD(double d) {
      if (d == Math.floor(d) && !Double.isInfinite(d)) {
         return String.valueOf((long) d);
      }
      return String.valueOf(d);
   }

   private static String escape(String s) {
      return s.replace("\\", "\\\\").replace("\"", "\\\"");
   }
}
