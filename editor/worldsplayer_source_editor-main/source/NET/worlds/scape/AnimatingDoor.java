package NET.worlds.scape;

import NET.worlds.core.Std;
import NET.worlds.network.URL;
import java.io.IOException;
import java.net.MalformedURLException;
import java.util.StringTokenizer;
import java.util.Vector;

public class AnimatingDoor extends Portal implements FrameHandler {
   public String frameList = "";
   protected transient Material[] frames = null;
   float perFrame = 100.0F;
   private URL openSound;
   private URL closeSound;
   private transient float state;
   private transient int lastUpdate;
   private transient boolean wasSameRoom;
   private transient int lastFrame = -1;
   private Point3 start = new Point3(-0.5F, -1.0F, 0.0F);
   private Point3 end = new Point3(1.5F, 0.0F, 1.0F);
   private static Object classCookie = new Object();

   public AnimatingDoor() {
      this.flags |= 262208;
   }

   public void detach() {
      if (this.frames != null) {
         int var1 = this.frames.length;

         while (--var1 >= 0) {
            this.frames[var1].setKeepLoaded(false);
         }

         this.frames = null;
      }

      super.detach();
   }

   public boolean handle(FrameEvent var1) {
      Pilot var2 = Pilot.getActive();
      Room var3 = var2.getRoom();
      boolean var4 = var3 == this.getRoom();
      boolean var5 = false;
      Point3Temp var6 = var2.getPosition();
      if (var4) {
         BoundBoxTemp var7 = BoundBoxTemp.make(Point3Temp.make(this.start).times(this), Point3Temp.make(this.end).times(this));
         var5 = var7.contains(var6);
      }

      Portal var11 = this.farSide();
      if (var11 != null && var11 instanceof AnimatingDoor) {
         AnimatingDoor var8 = (AnimatingDoor)var11;
         if (!var5) {
            Room var9 = var8.getRoom();
            if (var9 == null) {
               this.animate(var4, var5);
               return true;
            }

            if (var8.getRoom() == var3) {
               if (!var4) {
                  return true;
               }

               BoundBoxTemp var10 = BoundBoxTemp.make(Point3Temp.make(var8.start).times(var8), Point3Temp.make(var8.end).times(var8));
               var5 = var10.contains(var6);
            }
         }

         var8.animate(var4, var5);
      }

      this.animate(var4, var5);
      return true;
   }

   private void animate(boolean var1, boolean var2) {
      int var3 = Std.getFastTime();
      float var4 = this.state;
      if (this.frames == null) {
         this.frames = namesToMaterialArray(this, this.frameList);
         this.lastFrame = -1;
      }

      int var5 = this.frames.length - 2;
      boolean var6 = this.wasSameRoom;
      this.wasSameRoom = var1;
      if (!var1) {
         this.state = 0.0F;
      } else if (!var6) {
         this.state = var2 ? 1.0F : 0.0F;
      } else if (this.state == 0.0F) {
         if (!var2) {
            return;
         }

         this.state = 1.0E-4F;
      } else if (this.state == 1.0F) {
         if (var2) {
            return;
         }

         this.playSound(this.closeSound);
         this.state = 0.999F;
      } else {
         if (this.state == 1.0E-4F && var2) {
            if (this.active()) {
               this.playSound(this.openSound);
               this.state = 2.0E-4F;
            } else {
               this.lastUpdate = var3;
            }
         }

         float var7 = var5 * this.perFrame;
         if (var7 > 0.0F && var3 != this.lastUpdate) {
            float var8 = (var3 - this.lastUpdate) / var7;
            if (var2) {
               if ((this.state += var8) >= 1.0F) {
                  this.state = 1.0F;
               }
            } else if ((this.state -= var8) <= 0.0F) {
               this.state = 0.0F;
            }
         }
      }

      if (var4 != 0.0F && this.state == 0.0F) {
         this.flags |= 262144;
         this.reset();
      } else if (var4 == 0.0F && this.state != 0.0F) {
         this.flags &= -262145;
         this.reset();
         this.triggerLoad();
      }

      this.lastUpdate = var3;
      int var9 = 0;
      if (var5 >= 0) {
         if (this.state <= 2.0E-4F) {
            var9 = 0;
         } else if (this.state == 1.0F) {
            var9 = var5 + 1;
         } else {
            var9 = 1 + (int)(this.state * var5);
         }
      } else if (var5 == -2) {
         return;
      }

      this.setFrame(var9);
   }

   private void setFrame(int var1) {
      if (var1 != this.lastFrame && this.frames != null && this.frames.length > var1) {
         this.setMaterial(this.frames[var1]);
         this.lastFrame = var1;
      }
   }

   private void playSound(URL var1) {
      if (var1 != null && this.getRoom() == Pilot.getActive().getRoom()) {
         WavSoundPlayer var2 = new WavSoundPlayer(null);
         var2.open(1.0F, 0.0F, false, false);
         var2.start(var1);
      }
   }

   public static Material[] namesToMaterialArray(SuperRoot var0, String var1) {
      Vector var2 = new Vector();
      StringTokenizer var3 = new StringTokenizer(var1);

      while (var3.hasMoreTokens()) {
         var2.addElement(var3.nextToken());
      }

      int var4 = var2.size();
      Material[] var5 = new Material[var4];
      int var6 = var4;

      while (--var6 >= 0) {
         String var7 = (String)var2.elementAt(var6);

         URL var8;
         try {
            var8 = new URL(var0, var7);
         } catch (MalformedURLException var10) {
            var8 = URL.make("error:\"" + var7 + '"');
         }

         var5[var6] = new Material(var8);
         var5[var6].setKeepLoaded(true);
      }

      return var5;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Frame List"));
            } else if (var3 == 1) {
               var5 = this.frameList;
            } else if (var3 == 2) {
               this.frameList = ((String)var4).toString().trim();
               this.frames = null;
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "Start"));
            } else if (var3 == 1) {
               var5 = new Point3(this.start);
            } else if (var3 == 2) {
               this.start = (Point3)var4;
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "End"));
            } else if (var3 == 1) {
               var5 = new Point3(this.end);
            } else if (var3 == 2) {
               this.end = (Point3)var4;
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Time Per Frame"));
            } else if (var3 == 1) {
               var5 = new Float(this.perFrame);
            } else if (var3 == 2) {
               this.perFrame = (Float)var4;
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = URLPropertyEditor.make(new Property(this, var1, "Open Sound URL").allowSetNull(), "wav;mid;ram;ra;rm");
            } else if (var3 == 1) {
               var5 = this.openSound;
            } else if (var3 == 2) {
               this.openSound = (URL)var4;
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = URLPropertyEditor.make(new Property(this, var1, "Close Sound URL").allowSetNull(), "wav;mid;ram;ra;rm");
            } else if (var3 == 1) {
               var5 = this.closeSound;
            } else if (var3 == 2) {
               this.closeSound = (URL)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 6, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      this.setFrame(0);
      var1.saveVersion(0, classCookie);
      int var2 = this.flags;
      this.flags |= 262144;
      super.saveState(var1);
      this.flags = var2;
      var1.saveString(this.frameList);
      var1.saveFloat(this.perFrame);
      var1.save(this.start);
      var1.save(this.end);
      URL.save(var1, this.openSound);
      URL.save(var1, this.closeSound);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.frameList = var1.restoreString();
            this.perFrame = var1.restoreFloat();
            this.start = (Point3)var1.restore();
            this.end = (Point3)var1.restore();
            this.openSound = URL.restore(var1);
            this.closeSound = URL.restore(var1);
            return;
         default:
            throw new TooNewException();
      }
   }
}
