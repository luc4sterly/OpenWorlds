package net.freeworlds.rwx;

import java.util.ArrayList;
import java.util.List;

/**
 * One node of a named-clump hierarchy extracted from an RWX file (see
 * RwxSkeletonParser). Geometry here is in the joint's OWN local frame (only
 * transforms declared inside this clump, before its own ClumpBegin reset,
 * are baked in) - to get world-space positions, walk from the root
 * multiplying localTransform down the chain, exactly like RwxParser's
 * groupWorld does for the flattened model.
 */
public final class RwxJoint {
   public String name; // from the "# name" comment that precedes this clump's opening TransformBegin/ClumpBegin block; null if none was found
   public RwxMatrix4 localTransform = RwxMatrix4.identity(); // this clump's accumulated transform relative to its PARENT joint's frame (the value ClumpBegin froze)
   public final List<RwxVector3> vertices = new ArrayList<>();
   public final List<int[]> triangles = new ArrayList<>(); // 3 indices into vertices
   public final List<RwxMaterial> triangleMaterials = new ArrayList<>(); // parallel to triangles
   public final List<RwxJoint> children = new ArrayList<>();
}
