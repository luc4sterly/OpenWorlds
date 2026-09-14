package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.DefaultConsole;
import java.io.IOException;

public class Rect extends Surface implements MouseDownHandler, FrameHandler, Prerenderable {
   static BumpCalc standardPlaneBumpCalc = new PlaneBumpCalc();
   Billboard _billboardAttribute = null;
   VideoTexture _videoAttribute = null;
   boolean visible = false;
   protected float u = 1.0F;
   protected float v = 1.0F;
   protected float uOff;
   protected float vOff;
   private static Object classCookie = new Object();

   public Rect(float var1, float var2, Material var3) {
      super(var3);
      this.scale(var1, var2, var2);
   }

   public Rect(float var1, float var2, float var3, Material var4) {
      super(var4);
      this.setFarCorner(Point3Temp.make(var1, var2, var3));
   }

   public Rect(float var1, float var2, float var3, float var4, float var5, float var6, Material var7) {
      super(var7);
      this.moveBy(var1, var2, var3);
      this.setFarCorner(Point3Temp.make(var4, var5, var6));
   }

   public Rect(Point3Temp var1, Point3Temp var2, Material var3) {
      this(var1.x, var1.y, var1.z, var2.x, var2.y, var2.z, var3);
   }

   Rect() {
   }

   public static boolean setFarCornerHelper(Transform var0, Point3Temp var1) {
      var0.scale(1.0F / var0.getScaleX(), 1.0F / var0.getScaleY(), 1.0F / var0.getScaleZ());
      Point3Temp var2 = Point3Temp.make(1.0F, 0.0F, 0.0F).vectorTimes(var0);
      Point3Temp var3 = Point3Temp.make(0.0F, 1.0F, 0.0F).vectorTimes(var0);
      Point3Temp var4 = Point3Temp.make(0.0F, 0.0F, 1.0F).vectorTimes(var0);
      Point3Temp var5 = Point3Temp.make(var1).minus(var0.getPosition());
      float var6 = var5.dot(var2);
      float var7 = var5.dot(var3);
      float var8 = var5.dot(var4);
      if (!(var8 >= 0.0F)) {
         return false;
      }

      if (var6 != 0.0F || var7 != 0.0F) {
         var0.spin(0.0F, 0.0F, 1.0F, (float)(Math.atan2(var7, var6) * 180.0 / Math.PI));
      }

      var0.scale((float)Math.sqrt(var6 * var6 + var7 * var7), var8, var8);
      return true;
   }

   public boolean setFarCorner(Point3Temp var1) {
      Transform var2 = this.getTransform();
      if (setFarCornerHelper(var2, var1)) {
         this.setTransform(var2);
         var2.recycle();
         return true;
      } else {
         var2.recycle();
         Console.println(Console.message("cant-rot-rect"));
         return false;
      }
   }

   public Point3Temp getFarCorner() {
      Point3Temp var1 = Point3Temp.make(1.0F, 0.0F, 1.0F);
      if (this.hasClump()) {
         Transform var2 = this.getObjectToWorldMatrix();
         var1.times(var2);
         var2.recycle();
      } else {
         var1.times(this);
      }

      return var1;
   }

   public Point3Temp getFarCornerLocal() {
      Point3Temp var1 = Point3Temp.make(1.0F, 0.0F, 1.0F);
      if (this.hasClump()) {
         Transform var2 = this.getTransform();
         var1.times(var2);
         var2.recycle();
      } else {
         var1.times(this);
      }

      return var1;
   }

   public void setNearCorner(Point3Temp var1) {
      Point3Temp var2 = this.getFarCornerLocal();
      Point3Temp var3 = this.getPosition();
      this.moveTo(var1);
      if (!this.setFarCorner(var2)) {
         this.moveTo(var3);
      }
   }

   public Point3Temp getPlaneExtent() {
      return Point3Temp.make(1.0F, 0.0F, 1.0F);
   }

   public BumpCalc getBumpCalc(BumpEventTemp var1) {
      return this.bumpCalc == null ? standardPlaneBumpCalc : this.bumpCalc;
   }

   public Point2 getTileSize() {
      return new Point2(this.u != 1.0F ? this.getScaleX() / this.u : 0.0F, this.v != 1.0F ? this.getScaleZ() / this.v : 0.0F);
   }

   void setUV(float var1, float var2) {
      this.setTileSize(this.getScaleX() / var1, this.getScaleZ() / var2);
   }

   public Rect setTileSize(float var1, float var2) {
      this.u = var1 == 0.0F ? 1.0F : this.getScaleX() / var1;
      this.v = var2 == 0.0F ? 1.0F : this.getScaleZ() / var2;
      this.reclump();
      return this;
   }

   public void setTileOffset(Point2 var1) {
      this.uOff = this.getScaleX() == 0.0F ? 0.0F : var1.x / this.getScaleX();
      this.vOff = this.getScaleZ() == 0.0F ? 0.0F : var1.y / this.getScaleZ();
      this.reclump();
   }

   public Point2 getTileOffset() {
      return new Point2(this.uOff * this.getScaleX(), this.vOff * this.getScaleZ());
   }

   public static Rect floor(float var0, float var1, Material var2) {
      return (Rect)new Rect(var0, var1, var2).setBumpable(false).postspin(1.0F, 0.0F, 0.0F, -90.0F);
   }

   public static Rect floor(float var0, float var1, float var2, float var3, float var4, Material var5) {
      return (Rect)floor(var3 - var0, var4 - var1, var5).moveBy(var0, var1, var2);
   }

   public static Rect ceiling(float var0, float var1, Material var2) {
      return (Rect)new Rect(var0, var1, var2).setBumpable(false).postspin(1.0F, 0.0F, 0.0F, 90.0F).moveBy(0.0F, var1, 0.0F);
   }

   public static Rect ceiling(float var0, float var1, float var2, float var3, float var4, Material var5) {
      return (Rect)ceiling(var3 - var0, var4 - var1, var5).moveBy(var0, var1, var2);
   }

   public Rect hang(float var1, float var2, float var3, float var4, Material var5) {
      Rect var6 = (Rect)new Rect((var3 - var1) / this.getScaleX(), (var4 - var2) / this.getScaleZ(), var5)
         .moveBy(var1 / this.getScaleX(), 0.0F, var2 / this.getScaleZ())
         .post(this);
      return (Rect)var6.premoveBy(0.0F, -1.0F / var6.getScale().length(), 0.0F);
   }

   public VideoTexture getVideoAttribute() {
      return this._videoAttribute;
   }

   public Billboard getBillboardAttribute() {
      return this._billboardAttribute;
   }

   public boolean handle(MouseDownEvent var1) {
      if (this._billboardAttribute != null && (var1.key & 1) == 1) {
         Point2 var2 = this.deproject();
         this._billboardAttribute.billboardClicked(var2);
      }

      return false;
   }

   public boolean handle(FrameEvent var1) {
      if (this._billboardAttribute != null && this.getVisible() && this.visible) {
         this._billboardAttribute.billboardFrame(var1);
      }

      if (this._videoAttribute != null && this.getVisible() && this.visible) {
         this._videoAttribute.videoFrame(var1);
      }

      this.visible = false;
      return false;
   }

   public void prerender(Camera var1) {
      if (this._billboardAttribute != null || this._videoAttribute != null) {
         Point3Temp var2 = this.inCamSpace(var1);
         boolean var3 = var2 != null && var2.z > 1.0F && var2.x < var2.z && -var2.x < var2.z;
         if (var3) {
            this.visible = true;
         }
      }
   }

   protected Point2 deproject() {
      Console var1 = Console.getActive();
      if (var1 instanceof DefaultConsole) {
         DefaultConsole var3 = (DefaultConsole)var1;
         Point3Temp var2 = var3.getRender().getCamera().lastPickSpot();
         Point3Temp var7 = Point3Temp.make(var2);
         var7.minus(this.getObjectToWorldMatrix().getPosition());
         Transform var4 = this.getObjectToWorldMatrix().invert();
         Point3Temp var5 = Point3Temp.make(var7).vectorTimes(var4);
         var4.recycle();
         Point2 var6 = new Point2();
         var6.set(var5.x, var5.z);
         return var6;
      } else {
         return new Point2(-1.0F, -1.0F);
      }
   }

   protected void addRwChildren(WObject var1) {
      this.addNewRwChild(var1);
      float var2 = this.uOff;
      if (var2 != 0.0F) {
         var2 *= this.u;
         var2 = (float)(var2 - 2.0 * Math.floor(var2 / 2.0F));
      }

      float var3 = this.vOff;
      if (var3 != 0.0F) {
         var3 *= this.v;
         var3 = (float)(var3 - 2.0 * Math.floor(var3 / 2.0F));
      }

      this.addVertex(0.0F, 0.0F, 0.0F, var2, this.v + var3);
      this.addVertex(1.0F, 0.0F, 0.0F, this.u + var2, this.v + var3);
      this.addVertex(1.0F, 0.0F, 1.0F, this.u + var2, var3);
      this.addVertex(0.0F, 0.0F, 1.0F, var2, var3);
      this.doneWithEditing();
      if (!(this instanceof Portal)) {
         this.getRoom().addPrerenderHandler(this);
      }
   }

   protected void markVoid() {
      if (!(this instanceof Portal)) {
         this.getRoom().removePrerenderHandler(this);
      }

      super.markVoid();
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = Point2PropertyEditor.make(new Property(this, var1, "Tile Size"));
            } else if (var3 == 1) {
               var5 = this.getTileSize();
            } else if (var3 == 2) {
               Point2 var7 = (Point2)var4;
               if (!(var7.x < 0.0F) && !(var7.y < 0.0F)) {
                  this.setTileSize(var7.x, var7.y);
               } else {
                  Console.println(Console.message("Tile-size"));
               }
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = Point2PropertyEditor.make(new Property(this, var1, "Tile Origin"));
            } else if (var3 == 1) {
               var5 = this.getTileOffset();
            } else if (var3 == 2) {
               this.setTileOffset((Point2)var4);
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "From"));
            } else if (var3 == 1) {
               var5 = new Point3(this.getPosition());
            } else if (var3 == 2) {
               this.setNearCorner((Point3)var4);
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "To"));
            } else if (var3 == 1) {
               var5 = new Point3(this.getFarCornerLocal());
            } else if (var3 == 2) {
               this.setFarCorner((Point3)var4);
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = Point2PropertyEditor.make(new Property(this, var1, "Extent"));
            } else if (var3 == 1) {
               var5 = new Point2(this.getScaleX(), this.getScaleZ());
            } else if (var3 == 2) {
               float var6 = ((Point2)var4).y / this.getScaleZ();
               this.scale(((Point2)var4).x / this.getScaleX(), var6, var6);
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Flip Alternate U"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getUFlip());
            } else if (var3 == 2) {
               this.setUFlip((Boolean)var4);
               this.reclump();
            }
            break;
         case 6:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Flip Alternate V"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getVFlip());
            } else if (var3 == 2) {
               this.setVFlip((Boolean)var4);
               this.reclump();
            }
            break;
         case 7:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Unused"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getMouseOver());
            } else if (var3 == 2) {
               this.setMouseOver((Boolean)var4);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 8, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(4, classCookie);
      super.saveState(var1);
      var1.saveFloat(this.u);
      var1.saveFloat(this.v);
      var1.saveFloat(this.uOff);
      var1.saveFloat(this.vOff);
      var1.saveBoolean(false);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      int var2 = var1.restoreVersion(classCookie);
      switch (var2) {
         case 0:
         case 1:
            super.restoreState(var1);
            float var3 = var1.restoreFloat();
            float var4 = var1.restoreFloat();
            float var5 = var1.restoreFloat();
            var1.restoreFloat();
            var1.restoreFloat();
            var1.restoreFloat();
            this.u = var1.restoreFloat();
            this.v = var1.restoreFloat();
            this.spin(0.0F, 0.0F, 1.0F, (float)(Math.atan2(var4, var3) * 180.0 / Math.PI));
            this.scale((float)Math.sqrt(var3 * var3 + var4 * var4), var5, var5);
            break;
         case 2:
            super.restoreState(var1);
            this.u = var1.restoreFloat();
            this.v = var1.restoreFloat();
            break;
         case 3:
            super.restoreState(var1);
            this.u = var1.restoreFloat();
            this.v = var1.restoreFloat();
            this.uOff = var1.restoreFloat();
            this.vOff = var1.restoreFloat();
            break;
         case 4:
            super.restoreState(var1);
            this.u = var1.restoreFloat();
            this.v = var1.restoreFloat();
            this.uOff = var1.restoreFloat();
            this.vOff = var1.restoreFloat();
            var1.restoreBoolean();
            break;
         default:
            throw new TooNewException();
      }
   }

   public String toString() {
      return super.toString() + "[" + this.getPosition() + "->" + this.getFarCornerLocal() + "]";
   }

   public boolean acceptsLeftClicks() {
      return this._billboardAttribute != null && this._billboardAttribute.getIsAdBanner() ? true : this.getMouseOver();
   }

   static {
      standardPlaneBumpCalc.setName("defaultPlaneBumpCalc");
   }
}
