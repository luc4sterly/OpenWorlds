package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.core.Debug;
import NET.worlds.network.URL;
import java.io.IOException;

public class Hologram extends Surface implements Prerenderable, BGLoaded, Postrenderable, MainCallback {
   private int isLoading;
   ScapePicMovie fromMovie;
   URL movieName;
   protected Texture[] images;
   protected Material[] materials;
   private static Object classCookie = new Object();
   private int origTransformID = 0;
   private HoloCallback callback;
   private float scaleDist;

   public Hologram(float var1, float var2, Texture[] var3) {
      super(null);
      this.scale(var1, 1.0F, var2);
      this.images = var3;
   }

   public Hologram() {
      super(null);
   }

   public Hologram(Texture[] var1) {
      this(var1[0].getW(), var1[0].getH(), var1);
   }

   public Hologram(ScapePicMovie var1) {
      this(var1.getW(), var1.getH(), var1.getTextures());
      this.fromMovie = var1;
   }

   public Hologram(float var1, float var2, ScapePicMovie var3) {
      this(var1, var2, var3.getTextures());
      this.fromMovie = var3;
   }

   public Hologram(URL var1, HoloCallback var2) {
      super(null);
      this.setAutosize(true);
      this.scale(100.0F, 1.0F, 100.0F);
      this.load(var1, var2);
   }

   public Hologram(URL var1) {
      this(var1, null);
   }

   public Hologram(float var1, float var2, URL var3, HoloCallback var4) {
      super(null);
      this.scale(var1, 1.0F, var2);
      this.load(var3, var4);
   }

   public Hologram(float var1, float var2, URL var3) {
      this(var1, var2, var3, null);
   }

   public static native void nativeInit();

   private void load(URL var1, HoloCallback var2) {
      Debug.assert_(this.getMaterial() != null);
      this.callback = var2;
      this.movieName = var1;
      if (this.callback != null || this.hasClump()) {
         this.forceLoad();
      }
   }

   private void lockMaterials(boolean var1) {
      if (this.materials != null) {
         for (int var2 = 0; var2 < this.materials.length; var2++) {
            this.materials[var2].setKeepLoaded(var1);
         }
      }
   }

   private void releaseMaterials() {
      this.lockMaterials(false);
      this.materials = null;
   }

   private void loadMultipart(URL var1, String var2, int var3, String var4) {
      this.images = null;
      this.releaseMaterials();
      this.materials = new Material[var3];

      while (--var3 >= 0) {
         this.materials[var3] = new Material(URL.make(var1, var2 + (var3 + 1) + var4));
      }

      this.setMaterial(this.materials[0]);
      if (this.callback != null) {
         this.callback.holoCallback(this, true);
         this.callback = null;
      }
   }

   private void forceLoad() {
      URL var1 = HoloDrone.permission(this.movieName);
      String var2 = (var1 == null ? this.movieName : var1).getBase();
      int var3 = var2.length();
      boolean var5 = var3 > 5 && var2.regionMatches(true, var3 - 5, "*.mov", 0, 5);
      int var6 = 1;
      int var7 = 1;
      boolean var8 = true;

      int var4;
      for (int var9 = var3 - 5; var9 > 2 && var2.charAt(var9) == '*' && (var4 = var2.charAt(var9 - 2) - '0') > 0 && var4 <= 9; var9 -= 3) {
         char var10 = Character.toLowerCase(var2.charAt(var9 - 1));
         if (var10 == 'h') {
            var6 = var4;
         } else if (var10 == 'v') {
            var7 = var4;
         } else if (var10 == 's') {
            if (this.getAutosize()) {
               this.scale(var6 * 160.0F / var7 / this.getScaleX(), 1.0F, 160.0F / this.getScaleZ());
            }

            if (var5) {
               this.loadMultipart(this.movieName, var2.substring(0, var9 - 2), var4, "s*" + var6 + "h*" + var7 + "v*.mov");
            } else {
               this.loadMultipart(this.movieName, var2.substring(0, var9 - 2), var4, var2.substring(var9 + 1));
            }

            return;
         }
      }

      this.isLoading++;
      BackgroundLoader.get(this, this.movieName);
   }

   public Object asyncBackgroundLoad(String var1, URL var2) {
      if (var1 != null) {
         if (var1.toLowerCase().endsWith(".mov")) {
            return new ScapePicMovie(var1, var2).getTextures();
         }

         Texture[] var3 = new Texture[]{TextureDecoder.decode(var2, var1)};
         if (var3[0] != null && var3[0].textureID != 0) {
            return var3;
         }
      }

      return null;
   }

   public boolean syncBackgroundLoad(Object var1, URL var2) {
      this.releaseMaterials();
      if (var1 != null) {
         this.images = (Texture[])var1;
         if (this.getAutosize()) {
            this.scale(this.images[0].getW() / this.getScaleX(), 1.0F, this.images[0].getH() / this.getScaleZ());
         }
      } else {
         if (this.movieName != null) {
            Console.println(Console.message("No-load-hologram") + this.movieName);
         }

         this.images = null;
         this.setMaterial(null);
      }

      if (this.callback != null) {
         this.callback.holoCallback(this, this.images != null || this.materials != null);
         this.callback = null;
      }

      this.isLoading--;
      return false;
   }

   public Room getBackgroundLoadRoom() {
      return this.getRoom();
   }

   public BoundBoxTemp getBoundBox() {
      Point3Temp var1 = this.getWorldPosition();
      Point3Temp var2 = Point3Temp.make(this.getW() / 2.0F, this.getW() / 2.0F, this.getH() / 2.0F);
      return BoundBoxTemp.make(Point3Temp.make(var1).minus(var2), Point3Temp.make(var1).plus(var2));
   }

   public float getMinXYExtent() {
      return this.getW();
   }

   public float getW() {
      return this.getScaleX();
   }

   public float getH() {
      return this.getScaleZ();
   }

   public int getNumSides() {
      if (this.images == null) {
         return this.materials == null ? 1 : this.materials.length;
      } else {
         return this.images.length;
      }
   }

   void setActiveSide(int var1) {
      if (var1 >= this.getNumSides()) {
         System.out.println("Error at NET.worlds.Hologram.setActiveSide side " + var1 + " of " + this.getNumSides());
         var1 = 0;
      }

      if (this.materials == null) {
         Texture var2 = this.images == null ? null : (var1 < this.images.length ? this.images[var1] : null);
         if (var2 != null) {
            var2.incRef();
         }

         this.material.setTexture(var2);
      } else if (this.materials[var1] != this.material) {
         this.setMaterial(this.materials[var1]);
      }
   }

   public URL getMovieName() {
      return this.movieName == null && this.fromMovie != null ? this.fromMovie.getURL() : this.movieName;
   }

   protected void addRwChildren(WObject var1) {
      this.addNewRwChild(var1);
      if (this.images == null && this.materials == null && this.movieName != null && this.isLoading == 0) {
         this.forceLoad();
      }

      this.addVertex(0.5F, 0.0F, -0.5F, 0.0F, 1.0F);
      this.addVertex(-0.5F, 0.0F, -0.5F, 1.0F, 1.0F);
      this.addVertex(-0.5F, 0.0F, 0.5F, 1.0F, 0.0F);
      this.addVertex(0.5F, 0.0F, 0.5F, 0.0F, 0.0F);
      this.doneWithEditing();
      if (!this.isReclumping()) {
         this.lockMaterials(true);
         this.getRoom().addPrerenderHandler(this);
         this.getRoom().addPostrenderHandler(this);
      }

      if (this.images == null && this.materials == null && this.isLoading > 0) {
         this.makeTemporarilyInvisible();
      }
   }

   public native void makeTemporarilyInvisible();

   protected void markVoid() {
      if (!this.isReclumping()) {
         this.lockMaterials(false);
         this.getRoom().removePrerenderHandler(this);
         this.getRoom().removePostrenderHandler(this);
      }

      if (this.movieName != null && this.fromMovie == null && this.isLoading == 0) {
         Main.register(this);
      }

      super.markVoid();
   }

   public void mainCallback() {
      if (!this.hasClump()) {
         if (this.images != null) {
            int var1 = this.images.length;

            while (--var1 >= 0) {
               if (this.images[var1] != null) {
                  this.images[var1].decRef();
               }
            }

            this.images = null;
         }

         this.releaseMaterials();
      }

      Main.unregister(this);
   }

   public native void prerender(Camera var1);

   public native void postrender(Camera var1);

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(6, classCookie);
      var1.saveFloat(this.scaleDist);
      Material var2 = this.getMaterial();
      URL var3 = this.getMovieName();
      if (var3 != null) {
         this.setMaterial(null);
      }

      super.saveState(var1);
      this.setMaterial(var2);
      URL.save(var1, var3);
      if (var3 == null) {
         if (this.fromMovie != null) {
            var1.saveBoolean(true);
            var1.save(this.fromMovie);
         } else {
            var1.saveBoolean(false);
            if (this.images != null) {
               var1.saveBoolean(true);
               var1.saveArray(this.images);
            } else {
               Debug.assert_(this.materials == null);
               var1.saveBoolean(false);
            }
         }
      }
   }

   private static Texture[] extractTextureArray(Material[] var0) {
      Texture[] var1 = new Texture[var0.length];

      for (int var2 = 0; var2 < var0.length; var2++) {
         var1[var2] = var0[var2].extractTexture(0);
      }

      return var1;
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      int var2 = var1.restoreVersion(classCookie);
      switch (var2) {
         case 0:
            super.restoreState(var1);
            float var5 = var1.restoreFloat();
            if (var5 == 0.0F) {
               var5 = 100.0F;
            }

            float var6 = var1.restoreFloat();
            if (var6 == 0.0F) {
               var6 = 100.0F;
            }

            this.scale(var5, 1.0F, var6);
            if (var1.restoreBoolean()) {
               this.fromMovie = (ScapePicMovie)var1.restore();
               this.images = this.fromMovie.getTextures();
            } else {
               this.setAutosize(true);
            }
            break;
         case 1:
            super.restoreState(var1);
            float var3 = var1.restoreFloat();
            if (var3 == 0.0F) {
               var3 = 100.0F;
            }

            float var4 = var1.restoreFloat();
            if (var4 == 0.0F) {
               var4 = 100.0F;
            }

            this.scale(var3, 1.0F, var4);
            if ((this.movieName = URL.restore(var1)) != null) {
               this.load(this.movieName, null);
            } else if (var1.restoreBoolean()) {
               this.fromMovie = (ScapePicMovie)var1.restore();
               this.images = this.fromMovie.getTextures();
            } else {
               this.setAutosize(true);
            }
            break;
         case 2:
            super.restoreState(var1);
            if ((this.movieName = URL.restore(var1)) != null) {
               this.load(this.movieName, null);
            } else if (var1.restoreBoolean()) {
               this.fromMovie = (ScapePicMovie)var1.restore();
               this.images = this.fromMovie.getTextures();
            } else {
               this.setAutosize(true);
            }
            break;
         case 3:
            super.restoreState(var1);
            if ((this.movieName = URL.restore(var1)) != null) {
               this.load(this.movieName, null);
            } else if (var1.restoreBoolean()) {
               this.fromMovie = (ScapePicMovie)var1.restore();
               this.images = this.fromMovie.getTextures();
            } else {
               this.setAutosize(true);
               if (var1.restoreBoolean()) {
                  this.images = extractTextureArray((Material[])var1.restoreArray());
               }
            }
            break;
         case 5:
         case 6:
            this.scaleDist = var1.restoreFloat();
         case 4:
            super.restoreState(var1);
            if ((this.movieName = URL.restore(var1)) != null) {
               this.load(this.movieName, null);
            } else if (var1.restoreBoolean()) {
               this.fromMovie = (ScapePicMovie)var1.restore();
               this.images = this.fromMovie.getTextures();
            } else {
               if (var2 < 6) {
                  this.setAutosize(true);
               }

               if (var1.restoreBoolean()) {
                  this.images = (Texture[])var1.restoreArray();
               }
            }
            break;
         default:
            throw new TooNewException();
      }
   }

   public Hologram setRoughCut(boolean var1) {
      if (var1) {
         this.flags |= 4;
      } else {
         this.flags &= -5;
      }

      return this;
   }

   public final boolean getRoughCut() {
      return (this.flags & 4) != 0;
   }

   public void setAutosize(boolean var1) {
      if (var1) {
         this.flags |= 4194304;
      } else {
         this.flags &= -4194305;
      }
   }

   public final boolean getAutosize() {
      return (this.flags & 4194304) != 0;
   }

   public Hologram setViewplaneAligned(boolean var1) {
      if (var1) {
         this.flags |= 262144;
      } else {
         this.flags &= -262145;
      }

      return this;
   }

   public final boolean getViewplaneAligned() {
      return (this.flags & 262144) != 0;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = URLPropertyEditor.make(new Property(this, var1, "File"), TextureDecoder.getAllExts());
            } else if (var3 == 1) {
               var5 = this.getMovieName();
            } else if (var3 == 2) {
               this.load((URL)var4, null);
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Viewplane Aligned"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getViewplaneAligned());
            } else if (var3 == 2) {
               this.setViewplaneAligned((Boolean)var4);
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Rough Cut Alignment"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getRoughCut());
            } else if (var3 == 2) {
               this.setRoughCut((Boolean)var4);
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Scale Distance"));
            } else if (var3 == 1) {
               var5 = new Float(this.getScaleDist());
            } else if (var3 == 2) {
               this.setScaleDist((Float)var4);
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = Point2PropertyEditor.make(new Property(this, var1, "Extent"));
            } else if (var3 == 1) {
               var5 = new Point2(this.getScaleX(), this.getScaleZ());
            } else if (var3 == 2) {
               this.setAutosize(false);
               this.scale(((Point2)var4).x / this.getScaleX(), 1.0F, ((Point2)var4).y / this.getScaleZ());
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Autosize"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getAutosize());
            } else if (var3 == 2) {
               this.setAutosize((Boolean)var4);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 6, var3, var4);
      }

      return var5;
   }

   public String toString() {
      URL var1 = this.getMovieName();
      return super.toString() + "[" + (var1 != null ? var1.toString() : "") + "]";
   }

   public void setScaleDist(float var1) {
      this.scaleDist = var1;
   }

   public final float getScaleDist() {
      return this.scaleDist;
   }

   static {
      nativeInit();
   }
}
