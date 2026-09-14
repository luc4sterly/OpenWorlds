package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.core.Debug;
import NET.worlds.network.URL;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.text.MessageFormat;
import java.util.StringTokenizer;
import java.util.Vector;

public class ClickSensor extends Sensor implements MouseDownHandler, MouseUpHandler, BGLoaded {
   private static final int clickTime = 750;
   public static final int CENTER = 4;
   public static final int RIGHT = 2;
   public static final int LEFT = 1;
   public static final int ANY = 7;
   protected long mouseDownTime = 0L;
   protected int keyToCheck = 1;
   protected boolean waitForUp = false;
   protected URL config = null;
   transient int width;
   transient int height;
   transient ClickSensor.Area[] configTable;
   private static Object classCookie = new Object();

   public ClickSensor(Action var1, char var2) {
      this(var1, (int)var2);
   }

   public ClickSensor(Action var1, int var2) {
      this.keyToCheck = var2 & 7;
      if (var1 != null) {
         this.addAction(var1);
      }
   }

   public ClickSensor(Action var1) {
      this(var1, 7);
   }

   public ClickSensor() {
   }

   public int getWhichButton() {
      return this.keyToCheck;
   }

   public boolean getWaitForUp() {
      return this.waitForUp;
   }

   public void setWhichButton(int var1) {
      Debug.assert_(0 <= var1 && var1 <= 7);
      this.keyToCheck = var1;
   }

   public void setWaitForUp(boolean var1) {
      this.waitForUp = var1;
   }

   public boolean handle(MouseDownEvent var1) {
      if (this.keyToCheck == 7 || (var1.key & this.keyToCheck) != 0) {
         if (this.waitForUp) {
            this.mouseDownTime = System.currentTimeMillis();
         } else {
            this.trigger(var1);
         }
      }

      return true;
   }

   public boolean handle(MouseUpEvent var1) {
      if (this.waitForUp && (this.keyToCheck == 7 || (var1.key & this.keyToCheck) != 0) && System.currentTimeMillis() - this.mouseDownTime < 750L) {
         this.trigger(var1);
      }

      return true;
   }

   public void triggerAction(String var1, Vector var2, Event var3) {
      int var4 = this.actions.size();

      for (int var5 = 0; var5 < var4; var5++) {
         Action var6 = (Action)this.actions.elementAt(var5);
         if (var6.getName().regionMatches(0, var1, 0, var1.length())) {
            var4 = var2.size();

            for (byte var10 = 0; var10 < var4; var10 += 2) {
               String var7 = (String)var2.elementAt(var10);
               String var8 = (String)var2.elementAt(var10 + 1);
               SetPropertyAction.propHelper(2, var8, var7, var6);
            }

            RunningActionHandler.trigger(var6, this.getWorld(), var3);
            return;
         }
      }
   }

   public void trigger(Event var1) {
      if (this.configTable != null && this.getOwner() instanceof WObject) {
         WObject var2 = (WObject)this.getOwner();
         Transform var3 = var2.getObjectToWorldMatrix().invert();
         Point3Temp var4 = Point3Temp.make(Camera.downAt).times(var3);
         var4.x = var4.x * this.width;
         var4.z = var4.z * this.height;

         for (int var5 = 0; var5 < this.configTable.length; var5++) {
            ClickSensor.Area var6 = this.configTable[var5];
            if (var4.x > var6.x && var4.z > var6.y && var4.x - var6.x < var6.w && var4.z - var6.y < var6.h) {
               this.triggerAction(var6.actionNamePrefix, var6.props, var1);
            }
         }

         var3.recycle();
      } else {
         super.trigger(var1);
      }
   }

   public Object asyncBackgroundLoad(String var1, URL var2) {
      return var1;
   }

   public boolean syncBackgroundLoad(Object var1, URL var2) {
      if (var1 != null) {
         this.loadConfig((String)var1);
      }

      return false;
   }

   public Room getBackgroundLoadRoom() {
      return null;
   }

   public static String getString(StringTokenizer var0) {
      String var1 = var0.nextToken();
      if (var1.length() > 0 && var1.charAt(0) == '"') {
         StringBuffer var2 = new StringBuffer(var1.substring(1));

         while (var2.charAt(var2.length() - 1) != '"') {
            var2.append(" ");
            var2.append(var0.nextToken());
         }

         var2.setLength(var2.length() - 1);
         var1 = var2.toString();
      }

      return var1;
   }

   public void loadConfig(String var1) {
      Object var2 = null;
      DataInputStream var3 = null;
      int var4 = 1;

      try {
         var3 = new DataInputStream(new FileInputStream(var1));
         StringTokenizer var5 = new StringTokenizer(var3.readLine());
         int var23 = Integer.parseInt(var5.nextToken());
         this.width = Integer.parseInt(var5.nextToken());
         this.height = Integer.parseInt(var5.nextToken());
         var2 = new ClickSensor.Area[var23];

         for (int var7 = 0; var7 < var23; var7++) {
            ClickSensor.Area var8 = new ClickSensor.Area();
            var4++;
            var5 = new StringTokenizer(var3.readLine());
            var8.x = Integer.parseInt(var5.nextToken());
            var8.y = Integer.parseInt(var5.nextToken());
            var8.w = Integer.parseInt(var5.nextToken());
            var8.h = Integer.parseInt(var5.nextToken());
            var8.actionNamePrefix = getString(var5);
            Vector var9 = new Vector();

            while (var5.hasMoreTokens()) {
               var9.addElement(getString(var5));
               var9.addElement(getString(var5));
            }

            var8.props = var9;
            ((Object[])var2)[var7] = var8;
         }

         this.configTable = (ClickSensor.Area[])var2;
      } catch (Exception var19) {
         Object[] var6 = new Object[]{new String(var1), new String("" + var4)};
         Console.println(MessageFormat.format(Console.message("Error-config-table"), var6));
      } finally {
         try {
            if (var3 != null) {
               var3.close();
            }
         } catch (IOException var18) {
         }
      }
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Left Button"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean((this.keyToCheck & 1) != 0);
            } else if (var3 == 2) {
               if ((Boolean)var4) {
                  this.keyToCheck |= 1;
               } else {
                  this.keyToCheck &= -2;
               }
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Right Button"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean((this.keyToCheck & 2) != 0);
            } else if (var3 == 2) {
               if ((Boolean)var4) {
                  this.keyToCheck |= 2;
               } else {
                  this.keyToCheck &= -3;
               }
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Center Button"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean((this.keyToCheck & 4) != 0);
            } else if (var3 == 2) {
               if ((Boolean)var4) {
                  this.keyToCheck |= 4;
               } else {
                  this.keyToCheck &= -5;
               }
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Wait for up-click"), "Down", "Up");
            } else if (var3 == 1) {
               var5 = new Boolean(this.waitForUp);
            } else if (var3 == 2) {
               this.waitForUp = (Boolean)var4;
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = URLPropertyEditor.make(new Property(this, var1, "Config File").allowSetNull(), "clk");
            } else if (var3 == 1) {
               var5 = this.config;
            } else if (var3 == 2) {
               this.config = (URL)var4;
               if (this.config != null) {
                  BackgroundLoader.get(this, this.config);
               } else {
                  this.configTable = null;
               }
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 5, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(2, classCookie);
      super.saveState(var1);
      var1.saveInt(this.keyToCheck);
      var1.saveBoolean(this.waitForUp);
      URL.save(var1, this.config);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.keyToCheck = (char)var1.restoreInt();
            break;
         case 1:
            super.restoreState(var1);
            this.keyToCheck = (char)var1.restoreInt();
            this.waitForUp = var1.restoreBoolean();
            break;
         case 2:
            super.restoreState(var1);
            this.keyToCheck = (char)var1.restoreInt();
            this.waitForUp = var1.restoreBoolean();
            this.config = URL.restore(var1);
            break;
         default:
            throw new TooNewException();
      }

      if (this.config == null) {
         this.configTable = null;
      } else {
         BackgroundLoader.get(this, this.config);
      }
   }

   public String toString() {
      String var1 = super.toString() + "[";
      if ((this.keyToCheck & 1) != 0) {
         var1 = var1 + "*";
      } else {
         var1 = var1 + " ";
      }

      if ((this.keyToCheck & 4) != 0) {
         var1 = var1 + "*";
      } else {
         var1 = var1 + " ";
      }

      if ((this.keyToCheck & 2) != 0) {
         var1 = var1 + "*";
      } else {
         var1 = var1 + " ";
      }

      if (this.waitForUp) {
         var1 = var1 + "u]";
      } else {
         var1 = var1 + "d]";
      }

      return var1;
   }

   class Area {
      int x;
      int y;
      int w;
      int h;
      String actionNamePrefix;
      Vector props;
   }
}
