package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.network.URL;
import java.io.IOException;

public class WearAction extends Action {
   char limb = 'B';
   String val = "";
   private static String allowedLimbChars = "PBLMORUVIJKXYZabcdefHQE";
   private static Object classCookie = new Object();

   public Persister trigger(Event var1, Persister var2) {
      SuperRoot var3 = this.getOwner();
      if (var3 != null) {
         setAvLimb(this.limb, this.val);
      }

      return null;
   }

   public static void setAvLimb(char var0, String var1) {
      String var2 = PosableShape.getCurrentAvCustomizable();
      if (var2 != null) {
         int var3 = var2.indexOf(".", 7);
         String var4 = var2.substring(7, var3).toLowerCase();
         int var5;
         int var6;
         if (var0 == 'H' || var0 == 'E') {
            int var20 = var2.lastIndexOf("NS");
            if (var20 < 0) {
               return;
            }

            if (var1 == null) {
               var1 = var4;
               if (var0 == 'E') {
                  var0 = 'H';
                  if (var20 >= 0 && var2.charAt(var20 + 5) == 'G') {
                     var1 = PosableShape.readName(var2, var20 + 6).toLowerCase();
                  }
               }
            }

            int var24 = var2.lastIndexOf("DgT");
            int var27 = -1;
            if (var24 < var20) {
               if (var0 == 'E') {
                  Console.println("Can't change the face of this type of head.");
                  return;
               }

               var24 = -1;
            } else {
               var27 = var24 + 2;

               int var30;
               while ((var30 = PosableShape.skipMat(var2, var27)) != var27) {
                  var27 = var30;
               }
            }

            URL var31 = PosableShape.getAvURL(var1);
            if (var31 == null) {
               return;
            }

            String var33 = var31.getAbsolute();
            if (var33 == null) {
               return;
            }

            if (var0 == 'H') {
               int var35 = var33.lastIndexOf("NS");
               if (var35 < 0) {
                  return;
               }

               String var38 = "";
               var3 = var2.indexOf(".0E", 7);
               if (!var1.equalsIgnoreCase(var2.substring(7, var3))) {
                  var38 = "G" + PosableShape.getBodyType(var1);
               }

               var5 = var20 + 5;
               var6 = var2.length();
               var1 = var38 + var33.substring(var35 + 5);
            } else {
               int var36 = var33.lastIndexOf("Dg");
               if (var36 < 0) {
                  return;
               }

               int var40 = var36 + 2;

               int var39;
               while ((var39 = PosableShape.skipMat(var33, var40)) != var40) {
                  var40 = var39;
               }

               var5 = var24;
               var6 = var27;
               var1 = var33.substring(var36, var40);
            }
         } else if (var0 == 'Q') {
            int var7 = var2.lastIndexOf("NS");
            if (var7 < 0) {
               Console.println("Can't customize this avatar.");
               return;
            }

            var5 = var7 + 2;
            var6 = var7 + 5;
            if (var1 == null) {
               var1 = "000";
            }
         } else if (var0 == 'f') {
            int var18 = var2.lastIndexOf("Dg");
            if (var18 > 0) {
               int var9 = var18 + 2;

               int var8;
               while ((var8 = PosableShape.skipMat(var2, var9)) != var9) {
                  var9 = var8;
               }

               int var10 = var2.length() - 4;
               String var11 = "";

               while (var8 < var10) {
                  char var12 = var2.charAt(var8);
                  if (var12 == 'Q') {
                     var11 = var11 + var12;
                     var8++;
                  } else if (var12 >= '0' && var12 <= '9') {
                     var11 = var11 + var12;
                     var8++;
                  } else {
                     int var13 = PosableShape.skipMat(var2, var8);
                     if (var8 != var13) {
                        var11 = var11 + "f";
                        var8 = var13;
                     } else {
                        var8++;
                     }
                  }
               }

               if (var1 != null) {
                  var2 = var2.substring(0, var9) + var11 + ".rwg";
               } else {
                  URL var34 = PosableShape.getAvURL(var4);
                  String var37 = "";
                  if (var34 != null) {
                     var37 = var34.getInternal();
                  }

                  int var14 = var37.lastIndexOf("Dg");
                  if (var14 > 0) {
                     int var16 = var14 + 2;

                     int var15;
                     while ((var15 = PosableShape.skipMat(var37, var16)) != var16) {
                        var16 = var15;
                     }

                     var2 = var2.substring(0, var9) + var37.substring(var16);
                  }
               }
            }

            var5 = PosableShape.getMatPosition(var2, var0);
            if (var5 < 0) {
               return;
            }

            var6 = PosableShape.skipMat(var2, var5);
            if (var1 == null) {
               URL var22 = PosableShape.getAvURL(var4);
               if (var22 == null) {
                  return;
               }

               String var25 = var22.getInternal();
               int var28 = PosableShape.getMatPosition(var25, var0);
               if (var28 < 0) {
                  return;
               }

               int var32 = PosableShape.skipMat(var25, var28);
               var1 = var25.substring(var28, var32);
            }
         } else {
            var5 = PosableShape.getMatPosition(var2, var0);
            if (var5 < 0) {
               return;
            }

            var6 = PosableShape.skipMat(var2, var5);
            if (var1 == null) {
               URL var19 = PosableShape.getAvURL(var4);
               if (var19 == null) {
                  return;
               }

               String var23 = var19.getInternal();
               int var26 = PosableShape.getMatPosition(var23, var0);
               if (var26 < 0) {
                  return;
               }

               int var29 = PosableShape.skipMat(var23, var26);
               var1 = var23.substring(var26, var29);
            }
         }

         Console var21 = Console.getActive();
         if (var21 != null) {
            var21.setAvatar(URL.make(var2.substring(0, var5) + var1 + var2.substring(var6)));
         }
      }
   }

   public static String makeMatString(int var0, int var1, int var2) {
      StringBuffer var3 = new StringBuffer("C");
      var3.append(toBase64(var0));
      var3.append(toBase64(var1));
      var3.append(toBase64(var2));
      return var3.toString();
   }

   public static char toBase64(int var0) {
      return PosableShape.base64.charAt(var0);
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
               String var9 = (String)var4;
               if (var9.length() == 1 && allowedLimbChars.indexOf(var9.charAt(0)) >= 0) {
                  this.limb = var9.charAt(0);
                  this.val = null;
               } else {
                  Console.println("Limb must one of " + allowedLimbChars);
               }
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Value").allowSetNull());
            } else if (var3 == 1) {
               var5 = this.val;
            } else if (var3 == 2) {
               String var6 = (String)var4;
               if (var6 != null) {
                  if (this.limb != 'H' && this.limb != 'E') {
                     if (this.limb == 'Q') {
                        if (var6.length() != 3) {
                           Console.println("Head size must be three letters, usually all the same.");
                           return var5;
                        }

                        for (int var7 = 0; var7 < 3; var7++) {
                           char var8 = var6.charAt(var7);
                           if (var8 != '0' && (var8 < 'a' || var8 > 'z') && (var8 < 'A' || var8 > 'Z')) {
                              Console.println("Head size letters must each be one of z-a9A-Z.");
                              return var5;
                           }
                        }
                     } else if (var6.length() < 1) {
                        var6 = null;
                     } else if (var6.charAt(0) != 'C' && var6.charAt(0) != 'T') {
                        Console.println("Material must be C_X, CXYZ, or Ttexname.");
                        return var5;
                     }
                  } else if (PosableShape.readName(var6, 0).length() != var6.length()) {
                     Console.println("Head and face must be set to  all-lowercase name of body type.");
                     return var5;
                  }
               }

               this.val = var6;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 2, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      super.saveState(var1);
      var1.saveString(this.val);
      var1.saveString("" + this.limb);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            int var2 = var1.restoreInt();
            int var3 = var1.restoreInt();
            int var4 = var1.restoreInt();
            String var5 = var1.restoreString();
            if (var5 == null) {
               this.val = makeMatString(var2, var3, var4);
            } else {
               char var6;
               if (var5.length() == 1 && (var6 = var5.charAt(0)) >= 'A' && var6 <= 'Z') {
                  this.val = "C_" + var5;
               } else {
                  this.val = "T" + var5;
               }
            }

            this.limb = var1.restoreString().charAt(0);
            break;
         case 1:
            super.restoreState(var1);
            this.val = var1.restoreString();
            this.limb = var1.restoreString().charAt(0);
            break;
         default:
            throw new TooNewException();
      }
   }
}
