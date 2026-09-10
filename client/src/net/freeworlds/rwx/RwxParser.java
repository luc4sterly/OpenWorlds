package net.freeworlds.rwx;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;
import java.util.Locale;

/**
 * RWX (RenderWare Script) text-format parser. Behavior is modeled on
 * three-rwx-loader (github.com/Blaxar/three-rwx-loader) - read directly
 * from its source, not guessed - documented in
 * docs/rwx-format-reference.md. Key, easy-to-miss behaviors verified
 * there and replicated here:
 *
 * - `ModelBegin`/`ModelEnd` are NOT recognized by the reference at all -
 *   pure no-ops. Only `ClumpBegin`/`ClumpEnd` establish scope.
 * - Vertex indices in Triangle/Quad/Polygon are relative to a PER-CLUMP
 *   vertex buffer that resets at every ClumpBegin *and* ClumpEnd, not a
 *   single running list for the whole file.
 * - `Transform <16 values>` is an ABSOLUTE set (column-major, matching
 *   three.js's Matrix4.fromArray), not a multiply - unlike
 *   Translate/Rotate/Scale, which post-multiply into the current
 *   transform.
 * - `ClumpBegin` freezes whatever transform had accumulated in the
 *   enclosing scope as this clump's world "base", then resets the local
 *   accumulator to identity for content declared inside; `ClumpEnd`
 *   restores the local accumulator to what it was right before the reset
 *   (discarding whatever the clump's own content did to it) and pops the
 *   base back to the parent's.
 * - `Rotate x y z angle` is NOT a single arbitrary-axis rotation: it's up
 *   to three independent rotations around the X, then Y, then Z axis
 *   (each only applied if its coefficient is non-zero), each by
 *   `coefficient * angle` degrees.
 * - Material state (`Color`/`Opacity`/`Ambient`/`Diffuse`/`Specular`/
 *   `Surface`/`Texture`) is clump-scoped the same way transform is: a
 *   clone is pushed on ClumpBegin, restored on ClumpEnd.
 * - `JointTransformBegin`/`JointTransformEnd`/`IdentityJoint`/`Hints`/
 *   `AddHint`/`Tag` are not recognized by the reference either - no
 *   geometry/material effect, `Tag` only sets metadata.
 *
 * Any other unrecognized command is silently ignored, matching the RWX
 * spec's documented behavior (worlds-chat-project.md sec. 2).
 */
public final class RwxParser {
   private List<RwxVector3> localVertices = new ArrayList<>();
   private List<float[]> localUvs = new ArrayList<>(); // parallel to localVertices; {0,0} when the line has no UV suffix

   private RwxMatrix4 groupWorld = RwxMatrix4.identity(); // world transform of the innermost enclosing clump
   private final Deque<RwxMatrix4> groupWorldStack = new ArrayDeque<>();

   private RwxMatrix4 currentTransform = RwxMatrix4.identity(); // local to the current clump scope
   private final Deque<RwxMatrix4> clumpLocalSaveStack = new ArrayDeque<>(); // ClumpBegin/End save-restore
   private final Deque<RwxMatrix4> transformSaveStack = new ArrayDeque<>(); // TransformBegin/End save-restore

   private RwxMaterial currentMaterial = new RwxMaterial();
   private final Deque<RwxMaterial> materialStack = new ArrayDeque<>();

   private final RwxModel model = new RwxModel();

   public RwxModel parse(String text) {
      String[] lines = text.split("\r\n|\r|\n");
      for (int lineNo = 0; lineNo < lines.length; lineNo++) {
         String raw = lines[lineNo];
         int hash = raw.indexOf('#');
         String line = (hash >= 0 ? raw.substring(0, hash) : raw).trim().replace('\t', ' ');
         if (line.isEmpty()) {
            continue;
         }

         try {
            parseLine(line);
         } catch (RuntimeException e) {
            model.warnings.add("line " + (lineNo + 1) + ": " + e.getMessage() + " [" + line + "]");
         }
      }
      return model;
   }

   private void parseLine(String line) {
      String[] tok = line.split("\\s+");
      String cmd = tok[0].toLowerCase(Locale.ROOT);

      switch (cmd) {
         case "clumpbegin":
            clumpLocalSaveStack.push(currentTransform);
            groupWorldStack.push(groupWorld);
            groupWorld = groupWorld.multiply(currentTransform);
            currentTransform = RwxMatrix4.identity();
            localVertices = new ArrayList<>();
            localUvs = new ArrayList<>();
            materialStack.push(currentMaterial);
            currentMaterial = currentMaterial.copy();
            break;
         case "clumpend":
            currentTransform = clumpLocalSaveStack.isEmpty() ? currentTransform : clumpLocalSaveStack.pop();
            groupWorld = groupWorldStack.isEmpty() ? RwxMatrix4.identity() : groupWorldStack.pop();
            localVertices = new ArrayList<>();
            localUvs = new ArrayList<>();
            currentMaterial = materialStack.isEmpty() ? currentMaterial : materialStack.pop();
            break;
         // ModelBegin/ModelEnd: deliberately NOT handled - not recognized by
         // the reference, must stay no-ops (see class doc).

         case "transformbegin":
            transformSaveStack.push(currentTransform);
            break;
         case "transformend":
            if (!transformSaveStack.isEmpty()) {
               currentTransform = transformSaveStack.pop();
            }
            break;
         case "identity":
            currentTransform = RwxMatrix4.identity();
            break;
         case "transform":
            currentTransform = parseTransformMatrix(tok);
            break;
         case "translate":
            currentTransform = currentTransform.multiply(RwxMatrix4.makeTranslation(f(tok[1]), f(tok[2]), f(tok[3])));
            break;
         case "scale":
            currentTransform = currentTransform.multiply(RwxMatrix4.makeScale(f(tok[1]), f(tok[2]), f(tok[3])));
            break;
         case "rotate":
            applyRotate(f(tok[1]), f(tok[2]), f(tok[3]), f(tok[4]));
            break;

         case "vertex":
         case "vertexext":
            localVertices.add(bakedVertex(f(tok[1]), f(tok[2]), f(tok[3])));
            localUvs.add(parseUvSuffix(tok));
            break;
         case "triangle":
            emitTriangle(idx(tok[1]), idx(tok[2]), idx(tok[3]));
            break;
         case "quad":
            emitQuad(idx(tok[1]), idx(tok[2]), idx(tok[3]), idx(tok[4]));
            break;
         case "polygon": {
            int n = Integer.parseInt(tok[1]);
            // Reference builds the index list via unshift() - i.e. reversed
            // relative to file order - before fan-triangulating.
            int[] ids = new int[n];
            for (int i = 0; i < n; i++) {
               ids[n - 1 - i] = idx(tok[2 + i]);
            }
            for (int i = 1; i < n - 1; i++) {
               emitTriangle(ids[0], ids[i], ids[i + 1]);
            }
            break;
         }

         case "color":
            currentMaterial = currentMaterial.copy();
            currentMaterial.colorR = f(tok[1]);
            currentMaterial.colorG = f(tok[2]);
            currentMaterial.colorB = f(tok[3]);
            break;
         case "opacity":
            currentMaterial = currentMaterial.copy();
            currentMaterial.opacity = f(tok[1]);
            break;
         case "surface":
            currentMaterial = currentMaterial.copy();
            currentMaterial.ambient = f(tok[1]);
            currentMaterial.diffuse = f(tok[2]);
            currentMaterial.specular = f(tok[3]);
            break;
         case "ambient":
            currentMaterial = currentMaterial.copy();
            currentMaterial.ambient = f(tok[1]);
            break;
         case "diffuse":
            currentMaterial = currentMaterial.copy();
            currentMaterial.diffuse = f(tok[1]);
            break;
         case "specular":
            currentMaterial = currentMaterial.copy();
            currentMaterial.specular = f(tok[1]);
            break;
         case "texture":
            currentMaterial = currentMaterial.copy();
            currentMaterial.textureName = tok[1].equalsIgnoreCase("null") ? null : tok[1];
            currentMaterial.maskName = (tok.length > 2 && !tok[2].equalsIgnoreCase("null")) ? tok[2] : null;
            break;
         case "materialmode":
         case "materialmodes":
            // Real corpus evidence: assets/GROUNDZERO/YARD_TABLE.RWX has
            // "MaterialModes Double". Doesn't affect vertex/triangle
            // geometry (irrelevant to the phase-1 three-rwx-loader
            // position comparison, hence previously ignored), but matters
            // for phase-2 rendering: whether backfaces are culled.
            currentMaterial = currentMaterial.copy();
            currentMaterial.doubleSided = tok[1].equalsIgnoreCase("double");
            break;

         default:
            // Unrecognized command (includes ModelBegin/ModelEnd,
            // JointTransformBegin/End, IdentityJoint, Hints, AddHint, Tag,
            // GeometrySampling, LightSampling, TextureModes...): ignored,
            // matches the reference exactly for all of these (verified in
            // docs/rwx-format-reference.md) - none of these affect vertex
            // positions, which was phase 1's only concern.
            break;
      }
   }

   private RwxVector3 bakedVertex(float x, float y, float z) {
      RwxMatrix4 effective = groupWorld.multiply(currentTransform);
      return effective.transformPoint(new RwxVector3(x, y, z));
   }

   /** Optional {@code UV u v} suffix on vertex lines (case-insensitive
    * keyword; anything after the two floats - e.g. GROUNDZERO's
    * {@code Normal x y z} - is ignored). Returns {@code {0, 0}} when
    * absent or malformed (recorded as a warning by the caller path). */
   private float[] parseUvSuffix(String[] tok) {
      for (int i = 4; i + 2 <= tok.length - 1; i++) {
         if (tok[i].equalsIgnoreCase("uv")) {
            try {
               return new float[]{f(tok[i + 1]), f(tok[i + 2])};
            } catch (RuntimeException e) {
               return new float[]{0f, 0f};
            }
         }
      }
      return new float[]{0f, 0f};
   }

   private void applyRotate(float x, float y, float z, float angleDeg) {
      if (x != 0f) {
         currentTransform = currentTransform.multiply(RwxMatrix4.makeRotationX(Math.toRadians(x * angleDeg)));
      }
      if (y != 0f) {
         currentTransform = currentTransform.multiply(RwxMatrix4.makeRotationY(Math.toRadians(y * angleDeg)));
      }
      if (z != 0f) {
         currentTransform = currentTransform.multiply(RwxMatrix4.makeRotationZ(Math.toRadians(z * angleDeg)));
      }
   }

   private void emitTriangle(int a, int b, int c) {
      int va = model.addVertex(localVertices.get(a), localUvs.get(a)[0], localUvs.get(a)[1]);
      int vb = model.addVertex(localVertices.get(b), localUvs.get(b)[0], localUvs.get(b)[1]);
      int vc = model.addVertex(localVertices.get(c), localUvs.get(c)[0], localUvs.get(c)[1]);
      model.addTriangle(va, vb, vc, currentMaterial);
   }

   private void emitQuad(int a, int b, int c, int d) {
      // Reference cuts along whichever diagonal is SHORTER (see
      // addQuad()/docs/rwx-format-reference.md) - not always A-C.
      RwxVector3 va = localVertices.get(a);
      RwxVector3 vb = localVertices.get(b);
      RwxVector3 vc = localVertices.get(c);
      RwxVector3 vd = localVertices.get(d);
      boolean cutAC = distSq(va, vc) > distSq(vb, vd);
      if (cutAC) {
         emitTriangle(a, b, c);
         emitTriangle(a, c, d);
      } else {
         emitTriangle(a, b, d);
         emitTriangle(b, c, d);
      }
   }

   private static float distSq(RwxVector3 a, RwxVector3 b) {
      float dx = a.x - b.x;
      float dy = a.y - b.y;
      float dz = a.z - b.z;
      return dx * dx + dy * dy + dz * dz;
   }

   private RwxMatrix4 parseTransformMatrix(String[] tok) {
      float[] v = new float[16];
      for (int i = 0; i < 16; i++) {
         v[i] = f(tok[i + 1]);
      }
      // AW client quirk (see docs/rwx-format-reference.md): the bottom-right
      // element is always treated as 1 even if the file has it as 0.
      if (v[15] == 0f) {
         v[15] = 1f;
      }
      return RwxMatrix4.fromColumnMajor16(v);
   }

   private int idx(String s) {
      // RWX vertex references are 1-based.
      return Integer.parseInt(s) - 1;
   }

   private float f(String s) {
      return Float.parseFloat(s);
   }
}
