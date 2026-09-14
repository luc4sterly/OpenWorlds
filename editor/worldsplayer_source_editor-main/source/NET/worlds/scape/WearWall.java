package NET.worlds.scape;

import NET.worlds.network.URL;
import java.io.IOException;
import java.util.StringTokenizer;

public class WearWall extends Rect {
   char limb = ' ';
   String tileList = "";
   WObject[] subs;
   private static Object classCookie = new Object();

   WearWall() {
   }

   public void rebuild() {
      this.unbuild();
      if (this.limb != ' ') {
         int var1 = 0;
         StringTokenizer var2 = new StringTokenizer(this.tileList);

         while (var2.hasMoreTokens()) {
            var1++;
            var2.nextToken();
         }

         if (var1 != 0) {
            float var3 = this.getScaleX();
            float var4 = this.getScaleZ();
            int var5 = 1;
            int var6 = 1;

            while (var5 * var6 < var1) {
               if (var4 * (var5 + 1) > var3 * (var6 + 1)) {
                  var6++;
               } else {
                  var5++;
               }
            }

            this.subs = new WObject[var1];
            float var7 = 1.0F / var5;
            float var8 = 1.0F / var6;
            float var9 = var7 * this.getScaleX();
            float var10 = var8 * this.getScaleZ();
            float var11 = var9 < var10 ? var9 : var10;
            var9 = (var11 - 6.0F) / this.getScaleX() / 2.0F;
            var10 = (var11 - 6.0F) / this.getScaleZ() / 2.0F;
            var2 = new StringTokenizer(this.tileList);
            float var12 = -1.0F / this.getScaleY();
            float var13 = 1.0F - var8 / 2.0F;
            int var14 = 0;

            for (int var15 = 0; var15 < var6; var13 -= var8) {
               float var16 = var7 / 2.0F;

               for (int var17 = 0; var17 < var5; var16 += var7) {
                  if (!var2.hasMoreTokens()) {
                     return;
                  }

                  Material var18 = null;
                  String var19 = var2.nextToken();
                  String var20 = null;

                  label92: {
                     try {
                        char var21 = var19.charAt(0);
                        if (var21 != 'C' && var21 != 'T') {
                           String var22 = PosableShape.readName(var19, 0);
                           if (this.limb == 'H') {
                              var20 = var22;
                           } else {
                              if (this.limb != 'E') {
                                 break label92;
                              }

                              var22 = PosableShape.getFace(var22);
                              var18 = PosableShape.readTexture(var22, 0);
                           }
                        } else {
                           if (this.limb == 'H' || this.limb == 'E') {
                              break label92;
                           }

                           if (var21 == 'C') {
                              var18 = PosableShape.readColor(var19, 1);
                           } else {
                              var18 = PosableShape.readTexture(var19, 1);
                           }
                        }
                     } catch (StringIndexOutOfBoundsException var25) {
                        break label92;
                     }

                     if (var20 != null) {
                        var19 = PosableShape.getAvURL(var20).getAbsolute();
                        int var30;
                        if (var19 != null && (var30 = var19.indexOf(".0E")) >= 0) {
                           var30 = PosableShape.skipLimb(var19, var30 + 3);
                           if (var30 >= 0) {
                              int var34 = var19.lastIndexOf("NS");
                              if (var34 >= 0) {
                                 PosableShape var23 = new PosableShape(
                                    URL.make(var19.substring(0, var30) + "PGNG" + PosableShape.getBodyType(var20) + "Q" + var19.substring(var34 + 1)), false
                                 );
                                 var23.scale(750.0F / this.getScaleX(), 750.0F / this.getScaleY(), 750.0F / this.getScaleZ());
                                 var23.spin(0.0F, 1.0F, 1.0F, 180.0F);
                                 var23.spin(0.0F, 1.0F, 0.0F, 180.0F);
                                 var23.moveTo(var16, var12 * 10.0F, var13 - var10 / 2.0F);
                                 WearAction var24 = new WearAction();
                                 var24.limb = this.limb;
                                 var24.val = var20;
                                 var23.addAction(var24);
                                 var23.addHandler(new ClickSensor(var24, 1));
                                 this.add(var23);
                                 this.subs[var14] = var23;
                              }
                           }
                        }
                     } else if (var18 != null) {
                        var18.setAmbient(0.75F);
                        var18.setDiffuse(0.0F);
                        Rect var32 = new Rect(var16 - var9, var12, var13 - var10, var16 + var9, var12, var13 + var10, var18);
                        WearAction var35 = new WearAction();
                        var35.limb = this.limb;
                        var35.val = var19;
                        var32.addAction(var35);
                        var32.addHandler(new ClickSensor(var35, 1));
                        this.add(var32);
                        this.subs[var14] = var32;
                     }
                  }

                  var17++;
                  var14++;
               }

               var15++;
            }
         }
      }
   }

   private void unbuild() {
      if (this.subs != null) {
         int var1 = this.subs.length;

         while (--var1 >= 0) {
            if (this.subs[var1] != null) {
               this.subs[var1].detach();
            }
         }
      }

      this.subs = null;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Limb"));
            } else if (var3 == 1) {
               var5 = new String("" + this.limb);
            } else if (var3 == 2) {
               String var6 = (String)var4;
               if (var6.length() >= 1) {
                  this.limb = var6.charAt(0);
                  this.rebuild();
               }
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Tile List"));
            } else if (var3 == 1) {
               var5 = new String(this.tileList);
            } else if (var3 == 2) {
               this.tileList = (String)var4;
               this.rebuild();
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 2, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      this.unbuild();
      var1.saveVersion(2, classCookie);
      super.saveState(var1);
      this.rebuild();
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      int var2 = var1.restoreVersion(classCookie);
      switch (var2) {
         case 0:
            super.restoreState(var1);
            var1.restoreString();
            var1.restoreString();
            break;
         case 1:
            super.restoreState(var1);
            var1.restoreString();
            break;
         case 2:
            super.restoreState(var1);
            break;
         default:
            throw new TooNewException();
      }

      this.rebuild();
   }
}
