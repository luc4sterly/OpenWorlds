package NET.worlds.scape;

import java.awt.Color;
import java.io.IOException;

public class BuildStairs extends SwitchableBehavior implements FrameHandler, Persister {
   protected boolean doBuild = false;
   protected boolean built = false;
   protected WrStaircase stairs = null;
   protected String stairName = "staircase";
   protected float length = 1000.0F;
   protected float width = 300.0F;
   protected float pWidth = 250.0F;
   protected float pHeight = 240.0F;
   protected float dz = 300.0F;
   protected float lintelZ = 50.0F;
   protected int numsteps = 10;
   protected Material riser = new Material(Color.gray);
   protected Material tread = new Material(Color.green);
   protected Material left = new Material(Color.cyan);
   protected Material right = new Material(Color.red);
   protected Material doorpost = new Material(Color.yellow);
   protected Material lintel = new Material(Color.magenta);
   protected Material ceiling = new Material(Color.blue);
   protected String worldURL = null;

   protected void build(Portal var1) {
      Room var2 = var1.getRoom();
      World var3 = var2.getWorld();
      this.stairs = new WrStaircase(
         var3,
         this.stairName,
         this.length,
         this.width,
         this.pWidth,
         this.pHeight,
         this.dz,
         this.lintelZ,
         this.numsteps,
         this.riser,
         this.tread,
         this.left,
         this.right,
         this.doorpost,
         this.lintel,
         this.ceiling
      );
      var1.biconnect(this.stairs.portal1);
      this.built = true;
      var1.removeHandler(this);
   }

   protected void unbuild(Portal var1) {
      this.built = false;
   }

   public boolean handle(FrameEvent var1) {
      if (!this.built && this.doBuild && var1.target instanceof Portal) {
         this.build((Portal)var1.target);
      } else if (this.built && !this.doBuild && var1.target instanceof Portal) {
         this.unbuild((Portal)var1.target);
      }

      return true;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = new ClassProperty(this, var1, "BuildStairs");
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Build now?"), "Later", "Now");
            } else if (var3 == 1) {
               var5 = new Boolean(this.doBuild);
            } else if (var3 == 2) {
               this.doBuild = (Boolean)var4;
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Staircase Name"));
            } else if (var3 == 1) {
               var5 = this.stairName;
            } else if (var3 == 2) {
               this.stairName = (String)var4;
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Number of Steps"));
            } else if (var3 == 1) {
               var5 = new Integer(this.numsteps);
            } else if (var3 == 2) {
               this.numsteps = (Integer)var4;
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Portal-to-portal Distance"));
            } else if (var3 == 1) {
               var5 = new Float(this.length);
            } else if (var3 == 2) {
               this.length = (Float)var4;
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Stairwell Width"));
            } else if (var3 == 1) {
               var5 = new Float(this.width);
            } else if (var3 == 2) {
               this.width = (Float)var4;
            }
            break;
         case 6:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Portal Width"));
            } else if (var3 == 1) {
               var5 = new Float(this.pWidth);
            } else if (var3 == 2) {
               this.pWidth = (Float)var4;
            }
            break;
         case 7:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Portal Height"));
            } else if (var3 == 1) {
               var5 = new Float(this.pHeight);
            } else if (var3 == 2) {
               this.pHeight = (Float)var4;
            }
            break;
         case 8:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Total Rise"));
            } else if (var3 == 1) {
               var5 = new Float(this.dz);
            } else if (var3 == 2) {
               this.dz = (Float)var4;
            }
            break;
         case 9:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Lintel Height"));
            } else if (var3 == 1) {
               var5 = new Float(this.lintelZ);
            } else if (var3 == 2) {
               this.lintelZ = (Float)var4;
            }
            break;
         case 10:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Riser Material");
            } else if (var3 == 1) {
               var5 = this.riser;
            }
            break;
         case 11:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Tread Material");
            } else if (var3 == 1) {
               var5 = this.tread;
            }
            break;
         case 12:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Left Wall Material");
            } else if (var3 == 1) {
               var5 = this.left;
            }
            break;
         case 13:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Right Wall Material");
            } else if (var3 == 1) {
               var5 = this.right;
            }
            break;
         case 14:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Doorpost Material");
            } else if (var3 == 1) {
               var5 = this.doorpost;
            }
            break;
         case 15:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Lintel Material");
            } else if (var3 == 1) {
               var5 = this.lintel;
            }
            break;
         case 16:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Ceiling Material");
            } else if (var3 == 1) {
               var5 = this.ceiling;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 17, var3, var4);
      }

      return var5;
   }

   public String toString() {
      return "Stairs: built=" + this.built;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveBoolean(this.built);
      var1.saveString(this.stairName);
      var1.saveFloat(this.length);
      var1.saveFloat(this.width);
      var1.saveFloat(this.pWidth);
      var1.saveFloat(this.pHeight);
      var1.saveFloat(this.dz);
      var1.saveFloat(this.lintelZ);
      var1.saveInt(this.numsteps);
   }

   public void restoreState(Restorer var1) throws IOException {
      this.built = var1.restoreBoolean();
      this.stairName = var1.restoreString();
      this.length = var1.restoreFloat();
      this.width = var1.restoreFloat();
      this.pWidth = var1.restoreFloat();
      this.pHeight = var1.restoreFloat();
      this.dz = var1.restoreFloat();
      this.lintelZ = var1.restoreFloat();
      this.numsteps = var1.restoreInt();
   }

   public void postRestore(int var1) {
   }
}
