package NET.worlds.console;

import NET.worlds.core.IniFile;
import NET.worlds.scape.Point2;
import NET.worlds.scape.Point3Temp;

public class SnapTool {
   private static SnapTool theSnapTool = null;
   private int snapX = 1;
   private int snapY = 1;
   private int snapZ = 1;
   private boolean useSnap = false;

   public static SnapTool snapTool() {
      if (theSnapTool == null) {
         theSnapTool = new SnapTool();
      }

      return theSnapTool;
   }

   private SnapTool() {
      this.snapX = IniFile.gamma().getIniInt("Shaper.snapX", 100);
      this.snapY = IniFile.gamma().getIniInt("Shaper.snapY", 100);
      this.snapZ = IniFile.gamma().getIniInt("Shaper.snapZ", 1);
      this.useSnap = IniFile.gamma().getIniInt("Shaper.useSnapTool", 0) != 0;
   }

   public Point3Temp snapTo(Point3Temp var1) {
      if (!this.useSnap) {
         return var1;
      }

      float var2 = this.snapTo(var1.x, this.snapX);
      float var3 = this.snapTo(var1.y, this.snapY);
      float var4 = this.snapTo(var1.z, this.snapZ);
      return Point3Temp.make(var2, var3, var4);
   }

   public Point2 snapTo(Point2 var1) {
      if (!this.useSnap) {
         return var1;
      }

      float var2 = this.snapTo(var1.x, this.snapX);
      float var3 = this.snapTo(var1.y, this.snapY);
      return new Point2(var2, var3);
   }

   public float snapTo(float var1, int var2) {
      if (!this.useSnap) {
         return var1;
      }

      int var3 = Math.round(var1 / var2);
      return var3 * var2;
   }

   public int getSnapX() {
      return this.snapX;
   }

   public void setSnapX(int var1) {
      if (var1 > 0) {
         this.snapX = var1;
         IniFile.gamma().setIniInt("Shaper.snapX", var1);
      }
   }

   public int getSnapY() {
      return this.snapY;
   }

   public void setSnapY(int var1) {
      if (var1 > 0) {
         this.snapY = var1;
         IniFile.gamma().setIniInt("Shaper.snapY", var1);
      }
   }

   public int getSnapZ() {
      return this.snapZ;
   }

   public void setSnapZ(int var1) {
      if (var1 > 0) {
         this.snapZ = var1;
         IniFile.gamma().setIniInt("Shaper.snapZ", var1);
      }
   }

   public boolean useSnap() {
      return this.useSnap;
   }

   public void setSnap(boolean var1) {
      this.useSnap = var1;
      IniFile.gamma().setIniInt("Shaper.useSnapTool", var1 ? 1 : 0);
   }

   public void print() {
      System.out.println("SnapTool " + (this.useSnap ? "ON" : "OFF"));
      System.out.println("SnapTool Settings: X=" + this.snapX + " Y=" + this.snapY + " Z=" + this.snapZ);
   }

   public void test() {
      this.setSnapX(150);
      this.setSnapY(200);
      this.setSnapY(-100);
      this.setSnapY(0);
      this.setSnapZ(5);
      this.print();
   }
}
