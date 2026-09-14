package NET.worlds.console;

import NET.worlds.scape.Material;
import NET.worlds.scape.Point3;
import NET.worlds.scape.Point3Temp;
import NET.worlds.scape.Portal;
import NET.worlds.scape.Rect;
import NET.worlds.scape.Room;
import NET.worlds.scape.RoomEnvironment;
import NET.worlds.scape.World;

public class Escalator {
   public Portal bottom;
   public Portal top;
   private Room antelower;
   private Stair stairs;
   private Room anteupper;

   public Escalator(
      World var1,
      String var2,
      float var3,
      float var4,
      float var5,
      float var6,
      float var7,
      int var8,
      Material var9,
      Material var10,
      Material var11,
      Material var12,
      Material var13,
      Material var14,
      Material var15,
      float var16
   ) {
      this.stairs = new Stair(var1, var2, var3, var4, var5, var5 + var6, var8, var9, var10, var12, var13, var14, var15);
      this.antelower = new Room(var1, "antelower." + var2);
      RoomEnvironment var17 = this.antelower.getEnvironment();
      var17.add(new Rect(0.0F, 0.0F, 0.0F, 0.0F, var7, var6, var12));
      var17.add(new Rect(var3, var7, 0.0F, var3, 0.0F, var6, var13));
      Portal var18 = new Portal(0.0F, var7, 0.0F, var3, var7, var6).biconnect(this.stairs.bottom);
      var17.add(var18);
      this.bottom = new Portal(var3, 0.0F, 0.0F, 0.0F, 0.0F, var6);
      var17.add(this.bottom);
      var17.add(Rect.floor(0.0F, 0.0F, 0.0F, var3, var7, var11));
      var17.add(Rect.ceiling(0.0F, 0.0F, var6, var3, var7, var15));
      this.anteupper = new Room(var1, "anteupper." + var2);
      RoomEnvironment var19 = this.anteupper.getEnvironment();
      var19.add(new Rect(0.0F, 0.0F, 0.0F, 0.0F, var7, var6, var12));
      var19.add(new Rect(var3, var7, 0.0F, var3, 0.0F, var6, var13));
      Portal var20 = new Portal(0.0F, var7, 0.0F, var3, var7, var6).biconnect(this.stairs.top);
      var19.add(var20);
      this.top = new Portal(var3, 0.0F, 0.0F, 0.0F, 0.0F, var6);
      var19.add(this.top);
      var19.add(Rect.floor(0.0F, 0.0F, 0.0F, var3, var7, var11));
      var19.add(Rect.ceiling(0.0F, 0.0F, var6, var3, var7, var15));
      CameraConveyor var21 = new CameraConveyor(Point3Temp.make(0.0F, var4 / var16, 0.0F));
      CameraConveyor var22 = new CameraConveyor(new Point3(0.0F, -var4 / var16, 0.0F));
      var18.addHandler(new AddHandler(var21));
      var20.addHandler(new AddHandler(var22));
      this.stairs.bottom.addHandler(new RemoveHandler(var21));
      this.stairs.bottom.addHandler(new RemoveHandler(var22));
      this.stairs.top.addHandler(new RemoveHandler(var21));
      this.stairs.top.addHandler(new RemoveHandler(var22));
   }
}
