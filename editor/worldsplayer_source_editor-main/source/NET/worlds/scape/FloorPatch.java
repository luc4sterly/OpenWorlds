package NET.worlds.scape;

public interface FloorPatch {
   boolean inPatch(float var1, float var2);

   float floorHeight(float var1, float var2);

   Point3 surfaceNormal(float var1, float var2);
}
