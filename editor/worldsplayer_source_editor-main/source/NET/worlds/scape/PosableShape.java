package NET.worlds.scape;

import NET.worlds.console.AvMenu;
import NET.worlds.console.Console;
import NET.worlds.console.DefaultConsole;
import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import NET.worlds.core.ServerTableManager;
import NET.worlds.core.Std;
import NET.worlds.core.Timer;
import NET.worlds.core.TimerCallback;
import NET.worlds.network.Cache;
import NET.worlds.network.CacheFile;
import NET.worlds.network.NetUpdate;
import NET.worlds.network.URL;
import NET.worlds.network.WorldServer;
import java.awt.Color;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.net.MalformedURLException;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.StringTokenizer;
import java.util.Vector;

public class PosableShape extends Shape implements FrameHandler, Prerenderable, MouseDownHandler, ShapeLoaderListener, TimerCallback {
   protected int figureType = -1;
   private float closestView = 10000.0F;
   private int farViewCount;
   private Vector animationList;
   private boolean COG;
   private boolean setPrepFigure = true;
   private boolean runPrepFigure = this.setPrepFigure;
   private static URL defaultURL = URL.make("avatar:aura.0PG.rwg");
   protected DroneAnimator animator = null;
   private boolean recomputeHeight = false;
   private boolean firstURL = true;
   private Shape subparts;
   public static Color[] colorTable = new Color[]{
      new Color(0, 0, 0),
      new Color(51, 102, 204),
      new Color(234, 162, 115),
      new Color(255, 102, 51),
      new Color(255, 153, 204),
      new Color(139, 232, 0),
      new Color(43, 131, 0),
      new Color(51, 51, 153),
      new Color(145, 51, 204),
      new Color(153, 204, 255),
      new Color(204, 51, 102),
      new Color(0, 204, 102),
      new Color(255, 204, 102),
      new Color(102, 102, 102),
      new Color(254, 123, 26),
      new Color(255, 51, 153),
      new Color(188, 51, 204),
      new Color(204, 0, 38),
      new Color(118, 0, 0),
      new Color(153, 102, 51),
      new Color(196, 196, 196),
      new Color(204, 153, 255),
      new Color(255, 255, 255),
      new Color(255, 179, 2),
      new Color(247, 227, 2),
      new Color(255, 255, 153)
   };
   private Hashtable actions;
   private int scanPos;
   private static Material origMat = new Material((Texture)null);
   public static String base64 = "-0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ+";
   private static String[] permittedList = ServerTableManager.instance().getTable("permittedList");
   private static String[] faceList = ServerTableManager.instance().getTable("faceList");
   private static String[] humanList = ServerTableManager.instance().getTable("humanList");
   private static String[] secretList = ServerTableManager.instance().getTable("secretList");
   private static Hashtable permittedHash = new Hashtable();
   private static Vector permittedNames = new Vector();
   private static Vector faceNames = new Vector();
   private static Hashtable humanHash = new Hashtable();
   private static Hashtable worldHash = new Hashtable();
   private static Hashtable secretNames = new Hashtable();
   private static Hashtable faceTextures = new Hashtable();
   static boolean gotServerAvatarList;
   static boolean serverAvatarListError;
   private Enumeration animations;
   private boolean doLOD = false;
   protected int expressionStart;
   protected int nextChange;
   protected Vector expressionChanges;
   private static Object classCookie;

   public static URL getDefaultURL() {
      return defaultURL;
   }

   public PosableShape(URL var1) {
      this.setURL(var1);
   }

   public PosableShape(URL var1, boolean var2) {
      this.setPrepFigure = var2;
      this.runPrepFigure = this.setPrepFigure;
      this.setURL(var1);
   }

   public PosableShape() {
   }

   public void loadInit() {
      this.setURL(defaultURL);
   }

   public void markVoid() throws ClassCastException {
      if (this.animator != null) {
         this.animator.endanimations();
         if (this.figureType != -1) {
            this.animator.delayedDeltype(this.figureType);
         }
      }

      this.animator = null;
      this.getRoom().removePrerenderHandler(this);
      super.markVoid();
   }

   public synchronized void recursiveAddRwChildren(WObject var1) {
      if (!this.hasClump()) {
         super.recursiveAddRwChildren(var1);
         this.getRoom().addPrerenderHandler(this);
         if (this.isFullyLoaded() && this.figureType != -1) {
            DroneAnimator.addtype(this.figureType);
            if (this.runPrepFigure) {
               DroneAnimator.prepFigure(this, this.COG);
            }

            this.animator = new DroneAnimator();
         }
      }
   }

   public void notifyShapeLoaded(Shape var1) {
      this.recomputeHeight = true;
   }

   public Transform getObjectToWorldMatrix() {
      return this.clumpID != 0 ? this.getJointedObjectToWorldMatrix(Transform.make()) : super.getObjectToWorldMatrix();
   }

   public static int getFigureType(URL var0) {
      String var1 = getBodyType(var0);
      return var1 == null ? -1 : DroneAnimator.getnameindex(var1);
   }

   public static int getFigureType(String var0) {
      var0 = getBodyType(var0);
      return var0 == null ? -1 : DroneAnimator.getnameindex(var0);
   }

   protected void download(URL var1) {
      PendingDrone var2 = PosableDroneLoader.makePendingDrone(null, var1);
      Enumeration var3 = getComponentAvatars(var2.getUrl());
      if (var3 != null) {
         while (var3.hasMoreElements()) {
            String var4 = (String)var3.nextElement();
            var2.download(URL.make(var4));
         }
      }
   }

   public synchronized void setURL(URL var1) {
      if (var1 != this.url && (var1 == null || !var1.equals(this.url))) {
         if (var1 == null || !var1.toString().startsWith("avatar:lod")) {
            if (var1 != null) {
               this.download(var1);
               int var2 = getFigureType(var1);
               if (var2 != this.figureType) {
                  if (this.animator != null) {
                     this.animator.endanimations();
                     if (this.figureType != -1) {
                        this.animator.delayedDeltype(this.figureType);
                     }
                  }

                  this.animator = null;
                  this.figureType = var2;
                  this.animationList = null;
               }
            }

            this.setBaseLODURL(var1);
            if (forceLODLevel != -1 && this.numDetailLevels > 0 && this.doLOD) {
               this.setLOD(0.0F);
               return;
            }
         }

         this.removeSubparts();
         if (var1 != null && var1.getAbsolute().startsWith("avatar:")) {
            try {
               this.createSubparts(var1);
            } catch (MalformedURLException var3) {
               System.out.println("Received bogus PosableShape URL: " + var1);
               return;
            }
         }

         super.setURL(var1);
      }
   }

   private String scanName(String var1) {
      int var2 = this.scanPos;

      char var3;
      while ((var3 = var1.charAt(this.scanPos)) >= 'a' && var3 <= 'z' || var3 == '_') {
         this.scanPos++;
      }

      return var1.substring(var2, this.scanPos);
   }

   public static String readName(String var0, int var1) {
      int var2 = var1;

      char var3;
      try {
         while ((var3 = var0.charAt(var1)) >= 'a' && var3 <= 'z' || var3 == '_') {
            var1++;
         }
      } catch (StringIndexOutOfBoundsException var4) {
      }

      return var0.substring(var2, var1);
   }

   private int scanInt(String var1) {
      int var2 = this.scanPos;
      int var3 = 0;

      char var4;
      while ((var4 = var1.charAt(this.scanPos)) >= '0' && var4 <= '9') {
         var3 = 10 * var3 + (var4 - '0');
         this.scanPos++;
      }

      return var3;
   }

   private static Material scanTexture(String var0, int var1) {
      if (var1 <= 0) {
         var0 = "avatar:" + var0 + ".cmp";
      } else {
         var0 = "avatar:" + var0 + var1 + "s*.mov";
      }

      Material var2 = new Material(0.32F, 0.55F, 0.0F, colorTable[3], null, 1.0F, true, false);
      var2.loadTexture(URL.make(var0));
      return var2;
   }

   public static Material readTexture(String var0, int var1) {
      int var2 = 0;

      char var3;
      while ((var3 = var0.charAt(var1)) >= '0' && var3 <= '9') {
         var2 = 10 * var2 + (var3 - '0');
         var1++;
      }

      return scanTexture(readName(var0, var1), var2);
   }

   public static boolean isValidTexture(String var0) {
      int var1 = var0.length();
      int var3 = 0;

      char var2;
      while (var3 < var1 && (var2 = var0.charAt(var3)) >= '0' && var2 <= '9') {
         var3++;
      }

      while (var3 < var1) {
         if (((var2 = var0.charAt(var3)) < 'a' || var2 > 'z') && var2 != '_') {
            return false;
         }

         var3++;
      }

      return true;
   }

   private static int scanBase64(char var0) {
      int var1 = base64.indexOf(var0);
      return var1 < 0 ? 0 : var1;
   }

   public static Material readColor(String var0, int var1) {
      char var2 = var0.charAt(var1++);
      Material var3 = null;
      if (var2 == '_') {
         int var4 = var0.charAt(var1++) - 'A';
         if (var4 >= 0 && var4 < colorTable.length) {
            var3 = new Material(0.32F, 0.55F, 0.0F, colorTable[var4], null, 1.0F, true, false);
         } else {
            var3 = origMat;
         }
      } else {
         int var12 = 4 * scanBase64(var2);
         int var5 = 4 * scanBase64(var0.charAt(var1++));
         int var6 = 4 * scanBase64(var0.charAt(var1++));
         var3 = new Material(0.32F, 0.55F, 0.0F, new Color(var12, var5, var6), null, 1.0F, true, false);
      }

      return var3;
   }

   private Material scanColor(String var1) {
      Material var2 = readColor(var1, this.scanPos);
      if (var1.charAt(this.scanPos) == '_') {
         this.scanPos += 2;
      } else {
         this.scanPos += 3;
      }

      return var2;
   }

   private float getScale(char var1) {
      if (var1 >= 'a' && var1 <= 'z') {
         return 1.0F - (var1 - 'a' + 1) * 0.025615385F;
      } else {
         return var1 >= 'A' && var1 <= 'Z' ? 1.0F / (1.0F - (var1 - 'A' + 1) * 0.025615385F) : 1.0F;
      }
   }

   private Material getMat(char var1, Vector var2) {
      int var3 = var1 - 'a';
      if (var3 < var2.size()) {
         Material var4 = (Material)var2.elementAt(var3);
         return var4 == origMat ? origMat : (Material)var4.clone();
      } else {
         return null;
      }
   }

   private Shape getLimb(String var1, String var2, int var3, int var4, Shape var5, Vector var6, boolean var7) {
      int var8 = var1.length() - 4;
      if (var2 == null) {
         if (var5 instanceof PosableShape) {
            var2 = "";
         } else {
            var2 = Shape.getBodBase(var5.getURL());
            if (var5.getURL().toString().indexOf("lod/") != -1) {
               var2 = "lod/" + var2;
            }
         }
      }

      Shape var9 = new Shape();
      Shape var10 = var9;
      var9.setURL(URL.make("avatar:" + var2 + var4 / 10 + var4 % 10 + ".bod"));
      int var11 = 0;
      Material var12 = null;
      int var13 = 0;
      int var14 = 0;
      Object var15 = null;
      boolean var16 = false;
      if (var3 > 0) {
         this.scanPos = var3 + 1;

         while (true) {
            char var17 = var1.charAt(this.scanPos++);
            if (var17 >= 'A' && var17 <= 'Z') {
               if (var17 == 'G') {
                  int var24 = this.scanInt(var1);
                  if (var24 <= 0 || var24 > 99) {
                     var24 = var4;
                  }

                  var2 = this.scanName(var1);
                  if (var2.equals("")) {
                     break;
                  }

                  var10.setURL(URL.make("avatar:" + var2 + var24 / 10 + var24 % 10 + ".bod"));
               } else if (var17 == 'S') {
                  char var23 = var1.charAt(this.scanPos++);
                  char var19 = var1.charAt(this.scanPos++);
                  char var20 = var1.charAt(this.scanPos++);
                  if (var23 == 'Z' && var19 == 'Z' && var20 == 'Z') {
                     this.runPrepFigure = false;
                  }

                  var10.scale(this.getScale(var23), this.getScale(var19), this.getScale(var20));
               } else if (var17 != 'Q') {
                  if (var17 == 'C') {
                     Debug.assert_(false);
                  } else if (var17 == 'D') {
                     var13 += (int)(1000.0 * (Math.pow(1.0932, scanBase64(var1.charAt(this.scanPos++))) - 0.9F));
                  } else if (var17 == 'A') {
                     var15 = this.scanName(var1);
                     this.animationList = null;
                  } else {
                     if (var17 != 'T' && var17 != 'C') {
                        this.scanPos--;
                        break;
                     }

                     System.out.println("Illegal av " + this.url);
                  }
               }
            } else if (var17 >= 'a') {
               Material var18 = this.getMat(var17, var6);
               if (var18 != null) {
                  if (var13 == 0) {
                     var13 = 50;
                  }

                  var14 += var13;
                  if (var12 != null) {
                     if (!var16) {
                        var16 = true;
                        this.addChange(var14 - var13, var12, var10);
                     }

                     this.addChange(var14, var18, var10);
                  }

                  if (var18 != origMat) {
                     var10.setMaterial(var18);
                  }

                  var12 = var18;
                  var13 = 0;
               }
            } else {
               if (var17 < '0' || var17 > '9') {
                  break;
               }

               this.scanPos--;
               int var22 = this.scanInt(var1) - var11;
               var11++;
               var10 = new SubclumpShape();
               var10.setURL(URL.make("system:subclump" + var22));
               var9.add(var10);
               var12 = null;
               var16 = false;
               var14 = 0;
               var13 = 0;
            }

            if (this.scanPos > var8) {
               this.scanPos = var8;
               return var5;
            }
         }
      }

      if (var2.equals("")) {
         return var5;
      }

      var9.addLoadListener(this);
      if (ProgressiveAdder.get().enabled() && !var7) {
         ProgressiveAdder.get().scheduleForAdd(var5, var9);
      } else {
         var5.add(var9);
      }

      if (this.subparts == null) {
         this.subparts = var9;
      }

      return var9;
   }

   private void addChange(int var1, Material var2, Shape var3) {
      PosableShape.TimedMatChange var4 = new PosableShape.TimedMatChange();
      var4.when = var1;
      var4.mat = var2;
      var4.limb = var3;
      var2.setKeepLoaded(true);
      int var5 = 0;
      if (this.expressionChanges == null) {
         this.expressionChanges = new Vector();
         this.expressionStart = Std.getRealTime();
         this.nextChange = 0;
      } else {
         for (var5 = this.expressionChanges.size(); var5 > 0; var5--) {
            PosableShape.TimedMatChange var6 = (PosableShape.TimedMatChange)this.expressionChanges.elementAt(var5 - 1);
            if (var1 >= var6.when) {
               break;
            }
         }
      }

      this.expressionChanges.insertElementAt(var4, var5);
   }

   public static Enumeration getComponentAvatars(URL var0) {
      if (var0 == null) {
         return null;
      }

      Vector var1 = new Vector();
      String var2 = var0.getAbsolute();
      if (var2.startsWith("avatar:") && var2.endsWith(".rwg")) {
         String var3 = var2.substring(7, var2.indexOf(46));
         var1.addElement("avatar:" + var3 + ".rwg");
         int var4 = var2.indexOf(46);
         int var5 = var2.length() - 4;

         label83:
         while (var4 < var5) {
            char var6 = var2.charAt(var4++);
            if (var6 >= 'A' && var6 <= 'Z') {
               switch (var6) {
                  case 'A':
                  case 'B':
                  case 'E':
                  case 'F':
                  case 'H':
                  case 'I':
                  case 'J':
                  case 'K':
                  case 'L':
                  case 'M':
                  case 'N':
                  case 'O':
                  case 'P':
                  case 'Q':
                  case 'R':
                  case 'T':
                  default:
                     break;
                  case 'C':
                     var6 = var2.charAt(var4++);
                     if (var6 == '_') {
                        var4++;
                     } else {
                        var4 += 2;
                     }
                     break;
                  case 'D':
                     var4++;
                     break;
                  case 'G':
                     while (var4 < var5) {
                        var6 = var2.charAt(var4);
                        if (var6 < '0' || var6 > '9') {
                           break;
                        }

                        var4++;
                     }

                     String var7 = "";

                     while (true) {
                        if (var4 < var5) {
                           var6 = var2.charAt(var4);
                           if ((var6 < '0' || var6 > '9') && var6 >= 'a' && var6 <= 'z') {
                              var7 = var7 + var6;
                              var4++;
                              continue;
                           }
                        }

                        if (var7 != "" && var7.length() > 1) {
                           var1.addElement("avatar:" + var7 + ".rwg");
                        }
                        continue label83;
                     }
                  case 'S':
                     var4 += 3;
               }
            }
         }

         return var1.elements();
      } else {
         return null;
      }
   }

   public static int skipLimb(String var0, int var1) {
      int var2 = var0.length() - 4;

      while (var1 < var2) {
         char var3 = var0.charAt(var1++);
         if (var3 >= 'A' && var3 <= 'Z') {
            switch (var3) {
               case 'A':
               case 'G':
               case 'Q':
               case 'T':
                  break;
               case 'B':
               case 'E':
               case 'F':
               case 'H':
               case 'I':
               case 'J':
               case 'K':
               case 'L':
               case 'M':
               case 'N':
               case 'O':
               case 'P':
               case 'R':
               default:
                  return var1 - 1;
               case 'C':
                  var3 = var0.charAt(var1++);
                  if (var3 == '_') {
                     var1++;
                  } else {
                     var1 += 2;
                  }
                  break;
               case 'D':
                  var1++;
                  break;
               case 'S':
                  var1 += 3;
            }
         } else if ((var3 < 'a' || var3 > 'z') && (var3 < '0' || var3 > '9')) {
            break;
         }
      }

      return -1;
   }

   private String findStarts(String var1, int var2, int[] var3, String var4, Vector var5) {
      String var6 = var4;

      while (this.scanPos < var2) {
         char var7 = var1.charAt(this.scanPos);
         if (var7 < 'A' || var7 > 'Z') {
            return var1;
         }

         var3[var7 - 'A'] = this.scanPos++;

         while (this.scanPos < var2) {
            char var8 = var1.charAt(this.scanPos++);
            if (var8 < 'A' || var8 > 'Z') {
               if ((var8 < '0' || var8 > '9') && (var8 < 'a' || var8 > 'z')) {
                  return var1.substring(0, this.scanPos - 1) + ".rwg";
               }
            } else if (var8 == 'G') {
               this.scanInt(var1);
               this.scanName(var1);
            } else if (var8 == 'S') {
               this.scanPos += 3;
            } else if (var8 != 'Q') {
               if (var8 == 'C' || var8 == 'T') {
                  int var9 = this.scanPos - 1;
                  char var10 = (char)(97 + var5.size());
                  Material var11;
                  if (var8 == 'C') {
                     var11 = this.scanColor(var1);
                  } else {
                     int var12 = this.scanInt(var1);
                     String var13 = this.scanName(var1);
                     if (var13.equals("")) {
                        var13 = var6;
                     } else {
                        var6 = var13;
                     }

                     var11 = scanTexture(var13, var12);
                  }

                  var5.addElement(var11);
                  var1 = var1.substring(0, var9) + 'Q' + var10 + var1.substring(this.scanPos);
                  int var14 = this.scanPos - var9 - 2;
                  this.scanPos -= var14;
                  var2 -= var14;
               } else if (var8 == 'D') {
                  this.scanPos++;
               } else {
                  if (var8 != 'A') {
                     this.scanPos--;
                     break;
                  }

                  this.scanName(var1);
               }
            }
         }
      }

      return var1;
   }

   public static Vector getPermittedNames() {
      return permittedNames;
   }

   public static String[] getPermittedList() {
      return permittedList;
   }

   public static void downloadPermittedNames() {
      if (!gotServerAvatarList) {
         serverAvatarListError = false;
         WorldServer var0 = Pilot.getActive().getServer();
         if (var0 != null && var0.getGalaxy() != null) {
            String var1 = Console.getActive().getScriptServer() + "getavlist.pl?u=" + var0.getGalaxy().getChatname();
            if (var0.getGalaxy().getSerialNum() != null) {
               var1 = var1 + "&s=" + var0.getGalaxy().getSerialNum();
            }

            URL var2 = URL.make(var1);
            CacheFile var3 = Cache.getFile(var2, true);
            var3.waitUntilLoaded();
            if (!var3.error()) {
               permittedNames.removeAllElements();
               humanHash.clear();
               worldHash.clear();

               try {
                  RandomAccessFile var4 = new RandomAccessFile(var3.getLocalName(), "r");

                  while (var4.getFilePointer() < var4.length()) {
                     String var5 = var4.readLine();
                     if (!var5.startsWith("//")) {
                        StringTokenizer var6 = new StringTokenizer(var5);
                        if (var6.countTokens() > 2) {
                           String var7 = var6.nextToken();
                           permittedNames.addElement(var7);
                           String var8 = var6.nextToken();
                           if (var8.equals("m") || var8.equals("f")) {
                              humanHash.put(var7, var8);
                           }

                           Vector var9 = new Vector();

                           while (var6.hasMoreTokens()) {
                              var9.addElement(var6.nextToken());
                           }

                           worldHash.put(var7, var9);
                        }
                     }
                  }

                  var4.close();
               } catch (Exception var10) {
                  System.out.println("Error parsing avatar list: " + var10.toString());
                  serverAvatarListError = true;
                  return;
               }

               gotServerAvatarList = true;
               Console var11 = Console.getActive();
               if (var11 instanceof DefaultConsole) {
                  DefaultConsole var12 = (DefaultConsole)var11;
                  var12.getAvatarMenu().rebuildVIPMenu();
               }

               if (var11.getPilot() != null) {
                  var11.getPilot().resetAvatarNow();
               }

               AvMenu.rebuildHeadList();
            } else {
               serverAvatarListError = true;
            }
         }
      }
   }

   public static URL getPermitted(URL var0, World var1) {
      if (var0.endsWith(".mov")) {
         return var0;
      }

      if (NetUpdate.isInternalVersion()) {
         return var0;
      }

      boolean var2 = IniFile.override().getIniString("ProductName", "").equalsIgnoreCase("RedLightWorld");
      if (var2) {
         return var0;
      }

      if (!gotServerAvatarList && !serverAvatarListError) {
         return var0;
      }

      if (serverAvatarListError) {
         return validateAvatar(var0.getAbsolute()) ? var0 : getDefAv();
      }

      Enumeration var3 = getComponentAvatars(var0);

      while (var3 != null && var3.hasMoreElements()) {
         String var4 = (String)var3.nextElement();
         String var5 = getBodyType(URL.make(var4));
         if (var5 == null) {
            return getDefAv();
         }

         Vector var6 = (Vector)worldHash.get(var5);
         if (var6 == null) {
            return getDefAv();
         }

         boolean var7 = false;
         Enumeration var8 = var6.elements();

         while (true) {
            if (var8.hasMoreElements()) {
               String var9 = (String)var8.nextElement();
               if (var9 == null) {
                  return getDefAv();
               }

               if (var9.equals("all")) {
                  var7 = true;
               } else {
                  var9 = var9.replace('_', ' ').toLowerCase().trim();
                  if (var1 == null) {
                     var7 = true;
                     continue;
                  }

                  if (!var9.equals(var1.toString().toLowerCase().trim())) {
                     continue;
                  }

                  var7 = true;
               }
            }

            if (!var7) {
               return getDefAv();
            }
            break;
         }
      }

      return var0;
   }

   public static Vector getFaceNames() {
      return faceNames;
   }

   public static URL getAvURL(String var0) {
      Object var1 = permittedHash.get(var0);
      return var1 instanceof String ? URL.make("avatar:" + (String)var1) : null;
   }

   public static boolean validateAvatar(String var0) {
      System.out.println("Validating " + var0);
      String var1 = getBodyType(URL.make(var0));
      return var1 == null ? false : permittedHash.get(var1) != null;
   }

   public static String convertLODToParent(String var0) {
      String var1 = var0;
      if (var1.startsWith("lod/")) {
         var1 = var1.substring(4, var1.length() - 1);
      }

      return var1;
   }

   public static String getBodyType(URL var0) {
      if (var0 == null) {
         return null;
      }

      String var1 = var0.getAbsolute();
      if (var1.startsWith("avatar:") && (var1.endsWith(".rwg") || var1.endsWith(".RWG")) && var1.charAt(7) != '.') {
         int var2 = var1.indexOf(".", 7);
         String var3 = var1.substring(7, var2).toLowerCase();
         var3 = convertLODToParent(var3);
         if (var1.charAt(var2 + 1) != '0') {
            var3 = getBodyType(var3);
         }

         return var3;
      } else {
         return null;
      }
   }

   static URL getDefAv() {
      return URL.make(IniFile.override().getIniString("DefaultArticAv", "avatar:willy.rwg"));
   }

   public static URL getHuman(URL var0) {
      if (var0.endsWith(".mov")) {
         return HoloDrone.getHuman(var0);
      }

      String var1 = getBodyType(var0);
      if (var1 == null) {
         return getDefAv();
      }

      String var2 = (String)humanHash.get(var1);
      if (var2 == null) {
         return getDefAv();
      }

      URL var3 = URL.make("avatar:" + var1 + ".rwg");
      String var4 = var0.getAbsolute();
      int var5 = var4.indexOf(".0EC_");
      if (var5 >= 0 && var4.length() >= var5 + 7 && "_AC".indexOf(var4.charAt(var5 + 5)) >= 0) {
         if (!var2.equals("m")
            || var4.indexOf("yank") < 0
            || var4.regionMatches(var5 + 6, "TyankshirtC_", 0, 12) && var4.regionMatches(var5 + 19, "C-2bTyankstripe", 0, 15)) {
            var5 = var4.lastIndexOf("HDgT2");
            if (var5 >= 0 && var4.length() >= var5 + 7) {
               String var6 = (String)humanHash.get(readName(var4, var5 + 5));
               if (var6 != null && var6.equals(var2)) {
                  var5 = var4.lastIndexOf("NS");
                  if (var5 >= 0 && var4.length() >= var5 + 3 && "0abcdABCD".indexOf(var4.charAt(var5 + 2)) >= 0) {
                     var5 += 5;
                     if (var4.length() < var5 + 2) {
                        return var3;
                     }

                     if (var4.charAt(var5) == 'G') {
                        String var7 = (String)humanHash.get(readName(var4, var5 + 1));
                        if (var7 == null || !var7.equals(var2)) {
                           return var3;
                        }
                     }

                     return var0;
                  } else {
                     return var3;
                  }
               } else {
                  return var3;
               }
            } else {
               return var3;
            }
         } else {
            return var3;
         }
      } else {
         return var3;
      }
   }

   public URL getHuman() {
      return getHuman(this.getURL());
   }

   public static String getBodyType(String var0) {
      String var1 = (String)permittedHash.get(var0);
      if (var1 != null) {
         var0 = var1.substring(0, var1.indexOf("."));
      }

      return var0;
   }

   public static int getMatPosition(String var0, char var1) {
      int var2 = "abcdef".indexOf(var1);
      if (var2 >= 0) {
         int var6 = var0.indexOf(".0E");
         if (var6 >= 0) {
            var6 += 3;

            for (int var4 = 0; var4 < var2; var4++) {
               var6 = skipMat(var0, var6);
            }
         }

         return var6;
      } else {
         int var3 = var0.indexOf(".0E");
         if (var3 >= 0) {
            for (var3 += 2; var3 >= 0; var3 = skipLimb(var0, var3)) {
               if (var0.charAt(var3++) == var1) {
                  return var3;
               }
            }
         }

         return var3;
      }
   }

   public static String getCurrentAvCustomizable() {
      URL var0 = Pilot.getActive().getSourceURL();
      String var1 = var0.getAbsolute();
      if (var1.startsWith("avatar:") && (var1.endsWith(".rwg") || var1.endsWith(".RWG")) && var1.charAt(7) != '.') {
         int var2 = var1.indexOf(".", 7);
         if (!var1.regionMatches(var2, ".0E", 0, 3)) {
            var0 = getAvURL(var1.substring(7, var2).toLowerCase());
            if (var0 == null) {
               if (!var1.substring(var2).equalsIgnoreCase(".rwg")) {
                  Console.println(Console.message("cant-cust-av"));
                  return null;
               }

               var1 = "avatar:" + var1.substring(7, var2) + ".0EC__C__C__C__C__C__" + "PeBbLcMcOaRcUcVaWeXeYIeJeK" + "NS000QaHDgT2tonyT3T2T1Q0f.rwg";
            } else {
               var1 = var0.getAbsolute();
            }
         }

         return var1;
      } else {
         Console.println(Console.message("non-cust-av"));
         return null;
      }
   }

   public static int skipMat(String var0, int var1) {
      char var2 = var0.charAt(var1);
      int var3 = var1;
      if (var2 == 'C') {
         var2 = var0.charAt(var1 + 1);
         if (var2 == '_') {
            var3 = var1 + 3;
         } else {
            var3 = var1 + 4;
         }
      } else if (var2 == 'T') {
         var3 = var1 + 1;

         while ((var2 = var0.charAt(var3)) >= '0' && var2 <= '9') {
            var3++;
         }

         while ((var2 = var0.charAt(var3)) >= 'a' && var2 <= 'z') {
            var3++;
         }
      } else if (var2 >= 'a' && var2 <= 'z') {
         var3 = var1 + 1;
      }

      return var3;
   }

   public static String getFace(String var0) {
      Object var1 = faceTextures.get(var0);
      return var1 != null ? (String)var1 : "1" + var0;
   }

   private void createSubparts(URL var1) throws MalformedURLException {
      String var2 = var1.getAbsolute();
      int var3 = var2.length();
      String var4 = null;
      this.runPrepFigure = this.setPrepFigure;
      if (var2.startsWith("avatar:") && (var2.endsWith(".rwg") || var2.endsWith(".RWG")) && var2.charAt(7) != '.') {
         this.scanPos = var2.indexOf(".", 7);
         var4 = var2.substring(7, this.scanPos).toLowerCase();
         if (var2.charAt(this.scanPos + 1) != '0') {
            this.scanPos = var3 - 4;
            Object var5 = permittedHash.get(var4);
            if (var5 != null) {
               var2 = (String)var5;
               this.scanPos = 0;
               var4 = this.scanName(var2);
               if (var2.charAt(this.scanPos) != '.') {
                  throw new MalformedURLException();
               }

               if (var2.charAt(this.scanPos + 1) != '0') {
                  throw new MalformedURLException();
               }

               this.scanPos += 2;
            }
         } else {
            this.scanPos += 2;
         }
      } else {
         this.scanPos = 0;
         var2 = ".rwg";
         var4 = "aura";
      }

      Vector var26 = new Vector();
      int[] var6 = new int[26];
      var2 = this.findStarts(var2, var2.length() - 4, var6, var4, var26);
      if (this.subparts != null) {
         throw new MalformedURLException();
      }

      Shape var7 = this.getLimb(var2, var4, var6[15], 1, this, var26, true);
      Shape var8 = this.getLimb(var2, null, var6[1], 2, var7, var26, false);
      Shape var9 = this.getLimb(var2, null, var6[13], 3, var8, var26, false);
      Shape var10 = this.getLimb(var2, null, var6[7], 4, var9, var26, false);
      Shape var11 = this.getLimb(var2, null, var6[11], 11, var8, var26, false);
      Shape var12 = this.getLimb(var2, null, var6[12], 12, var11, var26, false);
      Shape var13 = this.getLimb(var2, null, var6[14], 13, var12, var26, false);
      Shape var14 = this.getLimb(var2, null, var6[17], 6, var8, var26, false);
      Shape var15 = this.getLimb(var2, null, var6[20], 7, var14, var26, false);
      Shape var16 = this.getLimb(var2, null, var6[21], 8, var15, var26, false);
      Shape var17 = this.getLimb(var2, null, var6[8], 19, var7, var26, false);
      Shape var18 = this.getLimb(var2, null, var6[9], 20, var17, var26, false);
      Shape var19 = this.getLimb(var2, null, var6[10], 21, var18, var26, false);
      Shape var20 = this.getLimb(var2, null, var6[22], 15, var7, var26, false);
      Shape var21 = this.getLimb(var2, null, var6[23], 16, var20, var26, false);
      Shape var22 = this.getLimb(var2, null, var6[24], 17, var21, var26, false);
      Shape var23 = this.getLimb(var2, null, var6[25], 24, var7, var26, false);
   }

   protected void removeSubparts() {
      if (this.subparts != null) {
         this.subparts.discard();
         this.subparts = null;
         this.actions = null;
      }
   }

   public void prerender(Camera var1) {
      if (this.getVisible()) {
         Point3Temp var2 = this.inCamSpace(var1);
         boolean var3 = var2 != null && var2.z > 1.0F && var2.x < var2.z && -var2.x < var2.z;
         if (var3) {
            if (this.closestView > var2.z) {
               this.closestView = var2.z;
            }

            if (var2.z > 700.0F && ++this.farViewCount > 10) {
               if (this.closestView > 400.0F) {
                  this.closestView = 400.0F;
               }

               this.farViewCount = 0;
            }
         }
      }
   }

   public float animate(String var1) {
      if (this.animator == null) {
         return 0.0F;
      }

      if (var1.length() == 1) {
         char var2 = var1.toLowerCase().charAt(0);
         char var3 = var1.toUpperCase().charAt(0);
         Vector var4 = this.getAnimationList();
         int var5 = var4.size();

         for (int var6 = 0; var6 < var5; var6++) {
            String[] var7 = ServerTableManager.instance().getTable("actionAliases");
            String var8 = (String)var4.elementAt(var6);
            if (var7 != null) {
               for (byte var9 = 0; var9 < var7.length; var9 += 2) {
                  if (var8.toLowerCase().equals(var7[var9].toLowerCase())) {
                     var8 = var7[var9 + 1];
                     break;
                  }
               }
            }

            char var10 = var8.charAt(0);
            if (var10 == var2 || var10 == var3) {
               var1 = (String)var4.elementAt(var6);
               break;
            }
         }
      }

      return this.performAnimationSequence(var1);
   }

   public void timerDone() {
      if (this.animations.hasMoreElements()) {
         String var1 = (String)this.animations.nextElement();
         float var2 = this.animator.getAnimationTime(this.figureType, var1);
         this.animator.animate(this.figureType, var1, Std.getRealTime());
         Timer var3 = new Timer(var2, this);
         var3.start();
      }
   }

   private float performAnimationSequence(String var1) {
      float var2 = 0.0F;
      Vector var3 = new Vector();
      StringTokenizer var4 = new StringTokenizer(var1, "&\t\n\r");

      while (var4.hasMoreTokens()) {
         String var5 = var4.nextToken();
         var2 += this.animator.getAnimationTime(this.figureType, var5);
         var3.addElement(var5);
      }

      this.animations = var3.elements();
      this.timerDone();
      return var2;
   }

   public Vector getAnimationList() {
      if (this.animationList != null) {
         return this.animationList;
      }

      this.animationList = DroneAnimator.getActionList(this.figureType);
      return this.animationList;
   }

   public void enableLOD(boolean var1) {
      this.doLOD = var1;
   }

   public boolean handle(MouseDownEvent var1) {
      return false;
   }

   public boolean handle(FrameEvent var1) {
      float var2 = this.closestView;
      this.closestView = 10000.0F;
      if (this.animator != null && !(var2 > 900.0F) && this.hasClump()) {
         if (this.recomputeHeight) {
            if (this.runPrepFigure) {
               DroneAnimator.prepFigure(this, this.COG);
            }

            this.recomputeHeight = false;
         }

         if (this.doLOD && this.setLOD(var2)) {
            return true;
         }

         int var3 = Std.getRealTime();
         Transform var4 = this.getObjectToWorldMatrix();
         this.animator.moveto(this.figureType, (short)var4.getX(), (short)var4.getY(), (short)var4.getZ(), (short)(-var4.getYaw()), var3 - 1);
         this.animator.update(null, this, var3, var4.getScaleX(), var2 > 700.0F);
         var4.recycle();
         if (this.expressionStart > 0) {
            var3 -= this.expressionStart;

            while (true) {
               PosableShape.TimedMatChange var6 = (PosableShape.TimedMatChange)this.expressionChanges.elementAt(this.nextChange);
               if (var3 < var6.when) {
                  break;
               }

               if (var6.mat != origMat) {
                  var6.limb.setMaterial(var6.mat);
               }

               if (++this.nextChange >= this.expressionChanges.size()) {
                  this.nextChange = 0;
                  this.expressionStart += var3;
                  break;
               }
            }
         }

         return true;
      } else {
         return true;
      }
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Center of Gravity"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.COG);
            } else if (var3 == 2) {
               this.COG = (Boolean)var4;
               URL var6 = this.getURL();
               this.setURL(defaultURL);
               this.setURL(var6);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 1, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      var1.saveBoolean(this.COG);
      if (this.subparts != null) {
         this.subparts.detach();
         super.saveState(var1);
         this.add(this.subparts);
      } else {
         super.saveState(var1);
      }
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            this.COG = var1.restoreBoolean();
         case 0:
            super.restoreState(var1);
            return;
         default:
            throw new TooNewException();
      }
   }

   public String toString() {
      return this.getName();
   }

   static {
      if (!NetUpdate.isInternalVersion()) {
         for (int var0 = 0; var0 < secretList.length; var0++) {
            secretNames.put(secretList[var0], secretList[var0]);
         }
      }

      for (byte var1 = 0; var1 < permittedList.length; var1 += 2) {
         if (secretNames.get(permittedList[var1]) == null) {
            permittedNames.addElement(permittedList[var1]);
            if (permittedList[var1 + 1].indexOf("DgT") >= 0) {
               faceNames.addElement(permittedList[var1]);
            }
         }

         if (permittedList[var1 + 1] != null) {
            permittedHash.put(permittedList[var1], permittedList[var1 + 1]);
         }
      }

      for (byte var2 = 1; var2 < humanList.length; var2 += 2) {
         humanHash.put(humanList[var2 - 1], humanList[var2]);
      }

      for (byte var3 = 0; var3 < faceList.length; var3 += 2) {
         faceTextures.put(faceList[var3], faceList[var3 + 1]);
      }

      gotServerAvatarList = false;
      serverAvatarListError = false;
      classCookie = new Object();
   }

   class TimedMatChange {
      Shape limb;
      Material mat;
      int when;
   }
}
