package net.freeworlds.rwx;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;
import java.util.Locale;

/**
 * Extracts the NAMED clump hierarchy from an RWX file as a joint tree,
 * instead of RwxParser's flattened single-mesh output. Used for articulated
 * avatar rigs (real corpus: assets/GROUNDZERO/SPIN.RWX, a 19-joint rig whose
 * clump names match the GammaDocs body-part convention exactly - see
 * worlds-chat-project.md). Every clump-scoping/transform/material rule is
 * copied verbatim from RwxParser (same reference behavior, see its class
 * doc) - only the output shape differs: geometry is kept per-joint in the
 * joint's own local frame (not baked into a single root-space mesh), and
 * clump nesting becomes parent/child RwxJoint nodes instead of being
 * discarded.
 *
 * Joint naming: RWX has no dedicated "clump name" command - the convention
 * (confirmed against SPIN.RWX's real bytes) is a "# name" comment on its
 * own line immediately before the clump's TransformBegin/Transform/
 * ClumpBegin block. Since RwxParser's line loop strips '#' comments before
 * they ever reach parseLine, this parser captures them separately: any line
 * whose first non-blank character is '#' updates `pendingName`, which the
 * next ClumpBegin consumes (and clears, so it doesn't leak to a later
 * sibling).
 */
public final class RwxSkeletonParser {
   // Not an ArrayDeque: the root clump's parent slot is null, and
   // ArrayDeque rejects null elements.
   private final List<RwxJoint> jointStack = new ArrayList<>();
   private RwxJoint currentJoint; // geometry target; null until the first ClumpBegin

   private String pendingName;

   // Per-segment vertex-index resolution buffer: like RwxParser's
   // localVertices, this resets on BOTH ClumpBegin and ClumpEnd (the
   // reference's real, verified behavior - a clump's own vertex indices do
   // not survive a nested child clump). It maps a file-local index within
   // the current segment to the index in currentJoint.vertices, since that
   // list persists across segments for the same joint (unlike the index
   // space).
   private List<Integer> localIndexToJointIndex = new ArrayList<>();

   private RwxMatrix4 currentTransform = RwxMatrix4.identity(); // local to the current clump scope
   private final Deque<RwxMatrix4> clumpLocalSaveStack = new ArrayDeque<>();
   private final Deque<RwxMatrix4> transformSaveStack = new ArrayDeque<>();

   private RwxMaterial currentMaterial = new RwxMaterial();
   private final Deque<RwxMaterial> materialStack = new ArrayDeque<>();

   private final List<String> warnings = new ArrayList<>();
   private final List<RwxJoint> topLevelJoints = new ArrayList<>();

   public RwxJoint parse(String text) {
      String[] lines = text.split("\r\n|\r|\n");
      for (int lineNo = 0; lineNo < lines.length; lineNo++) {
         String raw = lines[lineNo].trim();
         if (raw.startsWith("#")) {
            String name = raw.substring(1).trim();
            if (!name.isEmpty()) {
               pendingName = name;
            }
            continue;
         }

         int hash = raw.indexOf('#');
         String line = (hash >= 0 ? raw.substring(0, hash) : raw).trim().replace('\t', ' ');
         if (line.isEmpty()) {
            continue;
         }

         try {
            parseLine(line);
         } catch (RuntimeException e) {
            warnings.add("line " + (lineNo + 1) + ": " + e.getMessage() + " [" + line + "]");
         }
      }

      if (topLevelJoints.size() == 1) {
         return topLevelJoints.get(0);
      }
      RwxJoint synthetic = new RwxJoint();
      synthetic.name = null;
      synthetic.children.addAll(topLevelJoints);
      return synthetic;
   }

   public List<String> warnings() {
      return warnings;
   }

   private void parseLine(String line) {
      String[] tok = line.split("\\s+");
      String cmd = tok[0].toLowerCase(Locale.ROOT);

      switch (cmd) {
         case "clumpbegin": {
            RwxJoint joint = new RwxJoint();
            joint.name = pendingName;
            joint.localTransform = currentTransform;
            pendingName = null;

            if (currentJoint == null) {
               topLevelJoints.add(joint);
            } else {
               currentJoint.children.add(joint);
            }
            jointStack.add(currentJoint);
            currentJoint = joint;

            clumpLocalSaveStack.push(currentTransform);
            currentTransform = RwxMatrix4.identity();
            localIndexToJointIndex = new ArrayList<>();
            materialStack.push(currentMaterial);
            currentMaterial = currentMaterial.copy();
            break;
         }
         case "clumpend":
            currentTransform = clumpLocalSaveStack.isEmpty() ? currentTransform : clumpLocalSaveStack.pop();
            currentJoint = jointStack.isEmpty() ? null : jointStack.remove(jointStack.size() - 1);
            localIndexToJointIndex = new ArrayList<>();
            currentMaterial = materialStack.isEmpty() ? currentMaterial : materialStack.pop();
            break;

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
         case "vertexext": {
            RwxJoint joint = requireJoint();
            RwxVector3 v = currentTransform.transformPoint(new RwxVector3(f(tok[1]), f(tok[2]), f(tok[3])));
            joint.vertices.add(v);
            localIndexToJointIndex.add(joint.vertices.size() - 1);
            break;
         }
         case "triangle":
            emitTriangle(idx(tok[1]), idx(tok[2]), idx(tok[3]));
            break;
         case "quad":
            emitQuad(idx(tok[1]), idx(tok[2]), idx(tok[3]), idx(tok[4]));
            break;
         case "polygon": {
            int n = Integer.parseInt(tok[1]);
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
            currentMaterial = currentMaterial.copy();
            currentMaterial.doubleSided = tok[1].equalsIgnoreCase("double");
            break;

         default:
            break;
      }
   }

   private RwxJoint requireJoint() {
      if (currentJoint == null) {
         throw new IllegalStateException("geometry command outside any ClumpBegin");
      }
      return currentJoint;
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
      RwxJoint joint = requireJoint();
      joint.triangles.add(new int[]{resolve(a), resolve(b), resolve(c)});
      joint.triangleMaterials.add(currentMaterial);
   }

   private int resolve(int localIndex) {
      return localIndexToJointIndex.get(localIndex);
   }

   private void emitQuad(int a, int b, int c, int d) {
      RwxJoint joint = requireJoint();
      RwxVector3 va = joint.vertices.get(resolve(a));
      RwxVector3 vb = joint.vertices.get(resolve(b));
      RwxVector3 vc = joint.vertices.get(resolve(c));
      RwxVector3 vd = joint.vertices.get(resolve(d));
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
      if (v[15] == 0f) {
         v[15] = 1f;
      }
      return RwxMatrix4.fromColumnMajor16(v);
   }

   private int idx(String s) {
      return Integer.parseInt(s) - 1;
   }

   private float f(String s) {
      return Float.parseFloat(s);
   }
}
