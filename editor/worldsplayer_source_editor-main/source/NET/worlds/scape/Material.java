package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import NET.worlds.network.NetUpdate;
import NET.worlds.network.URL;
import java.awt.Color;
import java.io.IOException;

public class Material extends SuperRoot implements BGLoaded, MainCallback {
   static int serial = 0;
   public static boolean botMode = false;
   private boolean keepLoaded = false;
   private int[] ids;
   private Texture[] textures;
   private int vRes = 1;
   private int hRes = 1;
   private int sPos = -1;
   private final boolean loResMode = false;
   URL textureName;
   protected URL[] subnames;
   private boolean doReclump;
   private static boolean tryBMP = IniFile.gamma().getIniInt("TRYBMP", 0) != 0;
   private float ambient;
   private float diffuse;
   private float specular;
   private float opacity;
   private boolean smooth;
   private boolean filter;
   private int r;
   private int g;
   private int b;
   private Color color;
   private static Object classCookie = new Object();

   public static native void nativeInit();

   public Material(float var1, float var2, float var3, Color var4, Texture var5, float var6, boolean var7, boolean var8) {
      if (botMode) {
         var5 = null;
      }

      this.ambient = var1;
      this.diffuse = var2;
      this.specular = var3;
      this.setColor(var4);
      if (var5 != null) {
         this.textures = new Texture[1];
         this.textures[0] = var5;
      }

      this.opacity = var6;
      this.smooth = var7;
      this.filter = var8;
   }

   public Material(Color var1) {
      this(0.75F, 0.0F, 0.0F, var1, null, 1.0F, false, false);
   }

   public Material(Texture var1) {
      this(0.75F, 0.0F, 0.0F, Color.black, var1, 1.0F, false, false);
   }

   public Material(Color var1, URL var2) {
      this(var1 != null ? var1 : new Color(128, 128, 128));
      if (!botMode) {
         this.loadTexture(var2);
      }
   }

   public Material(URL var1, int var2, int var3) {
      this(0.75F, 0.0F, 0.0F, Color.black, null, 1.0F, false, false);
      this.hRes = var2;
      this.vRes = var3;
      serial++;
      int var4 = this.getHRes() * this.getVRes();
      this.textures = new Texture[var4];
      this.makeMaterials();
      this.subnames = new URL[var4];
      String var5 = var1.getBase();
      int var6 = 0;

      for (int var7 = this.vRes; var7 > 0; var7--) {
         String var8 = "" + var7;

         for (int var9 = 0; var9 < this.hRes; var6++) {
            URL var10 = URL.make(var1, var5 + serial + var8 + (var9 + 1) + ".cmp");
            this.subnames[var6] = var10;
            this.syncBackgroundLoad(var1.unalias(), var10);
            var9++;
         }
      }
   }

   public Material(URL var1) {
      this(null, var1);
   }

   public Material() {
   }

   protected void noteAddingTo(SuperRoot var1) {
      if (((WObject)var1).hasClump()) {
         this.addRwChildren();
      }
   }

   public void detach() {
      if (this.ids != null) {
         this.markVoid();
      }

      super.detach();
   }

   public Texture[] getTextures() {
      return this.textures;
   }

   public void addRwChildren() {
      if (this.ids == null) {
         if (this.textures == null && this.textureName != null) {
            this.loadTextures();
         } else {
            this.makeMaterials();
            if (this.textures != null) {
               for (int var1 = 0; var1 < this.ids.length; var1++) {
                  this.nativeSetTexture(var1, this.textures[var1]);
               }
            }
         }
      }
   }

   public void markVoid() {
      if (!this.keepLoaded) {
         if (this.textureName != null) {
            this.removeTextures();
         }

         this.closeMaterials();
      }
   }

   public void setKeepLoaded(boolean var1) {
      boolean var2 = this.keepLoaded;
      this.keepLoaded = var1;
      if (!var1 && var2) {
         SuperRoot var3 = this.getOwner();
         if (var3 == null || !((WObject)var3).hasClump()) {
            this.markVoid();
         }
      }
   }

   public static Material restore(Restorer var0) throws IOException, TooNewException {
      Material var1 = (Material)var0.restoreMaybeNull();
      if (var1 != null && var0.version() < 6 && var1.getOwner() != null) {
         var1 = (Material)var1.clone();
      }

      return var1;
   }

   private native void nativeSetTexture(int var1, Texture var2);

   private synchronized void setTexture(int var1, Texture var2) {
      if (this.textures[var1] != null) {
         Texture var3 = this.extractTexture(var1);
         if (var3 != null) {
            var3.decRef();
         }
      }

      this.textures[var1] = var2;
      this.nativeSetTexture(var1, var2);
      if (!this.doReclump) {
         this.doReclump = true;
         Main.register(this);
      }
   }

   public void mainCallback() {
      Main.unregister(this);
      if (this.doReclump) {
         this.propagateTextureChange();
      }

      this.doReclump = false;
   }

   private void propagateTextureChange() {
      if (this.ids != null) {
         SuperRoot var1 = this.getOwner();
         if (var1 instanceof WObject) {
            if (var1 instanceof Surface && ((Surface)var1).getMaterial() == this) {
               ((Surface)var1).setMaterial(this, true);
            } else if (var1 instanceof Shape && ((Shape)var1).getMaterial() == this) {
               ((Shape)var1).setMaterial(this);
            } else {
               ((WObject)var1).reclump();
            }
         }
      }

      this.doReclump = false;
   }

   public synchronized void setTexture(Texture var1) {
      this.textureName = null;
      if (this.textures != null && this.textures.length != 1) {
         this.removeTextures();
         this.textures = new Texture[1];
         this.setTexture(0, var1);
      } else {
         if (this.textures == null) {
            this.textures = new Texture[1];
         } else if (var1 == this.textures[0]) {
            return;
         }

         this.setTexture(0, var1);
      }
   }

   synchronized native Texture extractTexture(int var1);

   private void removeTextures() {
      if (this.textures != null) {
         for (int var1 = 0; var1 < this.textures.length; var1++) {
            Texture var2 = this.extractTexture(var1);
            if (var2 != null) {
               var2.decRef();
            }
         }

         this.textures = null;
      }

      this.hRes = this.vRes = 1;
      this.sPos = -1;
      this.closeMaterials();
   }

   protected void finalize() {
      this.removeTextures();
      super.finalize();
   }

   private native void closeMaterial(int var1);

   private void closeMaterials() {
      if (this.ids != null) {
         for (int var1 = 0; var1 < this.ids.length; var1++) {
            this.closeMaterial(var1);
         }

         this.ids = null;
      }
   }

   private int calcRes() {
      this.hRes = 1;
      this.vRes = 1;
      this.sPos = -1;
      if (this.textureName == null) {
         return -1;
      }

      String var1 = this.textureName.getInternal();
      int var2 = var1.length();
      if (var2 >= 4 && var1.regionMatches(true, var2 - 4, ".mov", 0, 4)) {
         this.sPos = 0;
      }

      if (var2 > 7 && var1.regionMatches(true, var2 - 5, "*.", 0, 2)) {
         int var3;
         int var4;
         for (var4 = var2 - 5; var4 > 2 && var1.charAt(var4) == '*' && (var3 = var1.charAt(var4 - 2) - '0') > 0 && var3 <= 9; var4 -= 3) {
            char var5 = Character.toLowerCase(var1.charAt(var4 - 1));
            if (var5 == 'h') {
               this.hRes = var3;
            } else if (var5 == 'v') {
               this.vRes = var3;
            } else if (var5 == 's' && this.sPos >= 0) {
               this.sPos = var3 - 1;
            }
         }

         return var2 - (var4 + 1);
      } else {
         return -1;
      }
   }

   private void loadTextures() {
      int var1 = this.calcRes();
      if (var1 >= 0) {
         String var2 = this.textureName.getBase();
         int var3 = var2.length() - var1;
         var2 = var2.substring(0, var3);
         int var4 = this.getHRes() * this.getVRes();
         this.textures = new Texture[var4];
         this.makeMaterials();
         if (this.sPos >= 0) {
            this.subnames = new URL[1];
            this.subnames[0] = URL.make(this.textureName, var2 + ".mov");
            BackgroundLoader.get(this, this.subnames[0]);
         } else {
            this.subnames = new URL[var4];
            int var5 = 0;

            for (int var6 = this.vRes; var6 > 0; var6--) {
               String var7 = "" + var6;

               for (int var8 = 0; var8 < this.hRes; var5++) {
                  URL var9 = URL.make(this.textureName, var2 + var7 + (var8 + 1) + ".cmp");
                  this.subnames[var5] = var9;
                  BackgroundLoader.get(this, var9);
                  var8++;
               }
            }
         }
      } else {
         this.subnames = null;
         this.textures = new Texture[1];
         this.makeMaterials();
         BackgroundLoader.get(this, this.textureName);
      }
   }

   public void loadTexture(URL var1) {
      boolean var2 = this.ids != null;
      this.removeTextures();
      this.textureName = var1;
      this.calcRes();
      if (var2) {
         this.addRwChildren();
      }

      SuperRoot var3 = this.getOwner();
      if (var3 instanceof WObject) {
         ((WObject)var3).reclump();
      }
   }

   private static native int makeMaterial(float var0, float var1, float var2, float var3, int var4, int var5, int var6, boolean var7);

   private void makeMaterials() {
      int var1 = this.getHRes() * this.getVRes();
      this.ids = new int[var1];

      for (int var2 = 0; var2 < var1; var2++) {
         this.ids[var2] = makeMaterial(
            this.ambient, this.diffuse, this.specular, this.opacity, this.color.getRed(), this.color.getGreen(), this.color.getBlue(), this.smooth
         );
      }
   }

   private void loadError(URL var1) {
      SuperRoot var2 = this.getOwner();
      System.out.println("Unable to load texture " + var1 + (var2 == null ? "" : " for " + var2.getName()) + ".");
   }

   public float getAmbient() {
      return this.ambient;
   }

   public float getDiffuse() {
      return this.diffuse;
   }

   public float getSpecular() {
      return this.specular;
   }

   public float getOpacity() {
      return this.opacity;
   }

   public boolean getSmooth() {
      return this.smooth;
   }

   public boolean getFilter() {
      return this.filter;
   }

   public boolean getHiRes() {
      return this.vRes > 1 || this.hRes > 1;
   }

   public int getVRes() {
      return this.vRes;
   }

   public int getHRes() {
      return this.hRes;
   }

   public int getRed() {
      return this.r;
   }

   public int getGreen() {
      return this.g;
   }

   public int getBlue() {
      return this.b;
   }

   public Color getColor() {
      return this.color;
   }

   public native void paramChange();

   public void setAmbient(float var1) {
      this.ambient = var1;
      this.paramChange();
   }

   public void setDiffuse(float var1) {
      this.diffuse = var1;
      this.paramChange();
   }

   public void setSpecular(float var1) {
      this.specular = var1;
      this.paramChange();
   }

   public void setOpacity(float var1) {
      this.opacity = var1;
      this.paramChange();
   }

   public void setSmooth(boolean var1) {
      this.smooth = var1;
      this.paramChange();
   }

   public void setFilter(boolean var1) {
      this.filter = var1;
      this.paramChange();
   }

   public void setColor(Color var1) {
      this.color = var1;
      this.r = var1.getRed();
      this.g = var1.getGreen();
      this.b = var1.getBlue();
      this.paramChange();
   }

   public Object asyncBackgroundLoad(String var1, URL var2) {
      return var1;
   }

   public boolean syncBackgroundLoad(Object var1, URL var2) {
      int var3 = 0;
      if (this.textures == null) {
         return false;
      }

      String var5 = var2.getAbsolute();
      String var6 = IniFile.gamma().getIniString("avatarDir", "avatar/");
      if (!var6.endsWith("/")) {
         var6 = var6 + "/";
      }

      String var7 = URL.make(NetUpdate.getUpgradeServerURL() + var6).getAbsolute();
      if (var5.startsWith(var7)) {
         URL var4 = URL.make("avatar:" + var5.substring(var7.length()));
      }

      String var8 = var2 == null ? null : var2.getBase();
      String var9 = this.textureName == null ? null : this.textureName.getBase();
      if (!var8.equals(var9)) {
         if (this.textureName != null && this.textureName.endsWith(".mov")) {
            String var15 = this.textureName.getBaseWithoutExt();
            String var11 = var2.getBaseWithoutExt();
            if (!var15.startsWith(var11)) {
               return false;
            }
         } else {
            if (this.subnames == null) {
               return false;
            }

            while (var3 < this.subnames.length) {
               String var10 = this.subnames[var3].getBase();
               if (var8.equals(var10)) {
                  break;
               }

               var3++;
            }

            if (var3 == this.textures.length) {
               return false;
            }
         }
      }

      String var16 = (String)var1;
      if (this.ids == null) {
         return false;
      }

      if (var16 != null) {
         if (this.sPos < 0) {
            Texture var17 = TextureDecoder.decode(var2, var16);
            if (var17 != null && var17.textureID != 0) {
               this.setTexture(var3, var17);
            } else {
               var16 = null;
            }
         } else {
            ScapePicTexture[] var18 = new ScapePicMovie(var16, var2).getTextures();
            if (var18 != null && this.hRes * this.vRes * (this.sPos + 1) <= var18.length) {
               int var12 = this.hRes * this.vRes * this.sPos;

               for (int var13 = (this.vRes - 1) * this.hRes; var13 >= 0; var13 -= this.hRes) {
                  for (int var14 = 0; var14 < this.hRes; var12++) {
                     this.setTexture(var13 + var14, var18[var12]);
                     var14++;
                  }
               }
            } else {
               var16 = null;
            }
         }
      } else {
         int var19 = var5.length();
         if (tryBMP && this.sPos == -1 && var19 > 4 && var5.regionMatches(true, var19 - 4, ".cmp", 0, 4) && !var2.isRemote()) {
            String var20 = var5.substring(0, var19 - 4) + ".bmp";
            Texture var21 = TextureDecoder.decode(URL.make(var20), var20);
            if (var21 != null && var21.textureID != 0) {
               this.setTexture(var3, var21);
               var16 = var20;
            }
         }
      }

      if (var16 == null) {
         if (var5.startsWith("avatar:")) {
            BackgroundLoader.get(this, URL.make(var7 + var5.substring(7)));
            return false;
         }

         this.loadError(var2);
      }

      return false;
   }

   public Room getBackgroundLoadRoom() {
      WObject var1 = (WObject)this.getOwner();
      return var1 == null ? null : var1.getRoom();
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(4, classCookie);
      super.saveState(var1);
      var1.saveFloat(this.getAmbient());
      var1.saveFloat(this.getDiffuse());
      var1.saveFloat(this.getSpecular());
      var1.saveFloat(this.getOpacity());
      var1.saveBoolean(this.getSmooth());
      var1.saveBoolean(this.getFilter());
      var1.saveInt(this.getRed());
      var1.saveInt(this.getGreen());
      var1.saveInt(this.getBlue());
      URL.save(var1, this.textureName);
      var1.saveBoolean(this.keepLoaded);
      if (this.textureName == null) {
         if (this.textures != null && this.textures.length != 1) {
            var1.saveMaybeNull(null);
         } else {
            var1.saveMaybeNull(this.textures == null ? null : this.textures[0]);
         }
      }
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      Texture var2 = null;
      int var3 = var1.restoreVersion(classCookie);
      switch (var3) {
         case 1:
            super.restoreState(var1);
         case 0:
            this.ambient = var1.restoreFloat();
            this.diffuse = var1.restoreFloat();
            this.specular = var1.restoreFloat();
            this.opacity = var1.restoreFloat();
            int var8 = var1.restoreInt();
            int var9 = var1.restoreInt();
            int var10 = var1.restoreInt();
            this.setColor(new Color(var8, var9, var10));
            var2 = (Texture)var1.restoreMaybeNull();
            break;
         case 2:
         case 3:
         case 4:
            super.restoreState(var1);
            this.ambient = var1.restoreFloat();
            this.diffuse = var1.restoreFloat();
            this.specular = var1.restoreFloat();
            this.opacity = var1.restoreFloat();
            if (var3 > 3) {
               this.smooth = var1.restoreBoolean();
               this.filter = var1.restoreBoolean();
            }

            int var4 = var1.restoreInt();
            int var5 = var1.restoreInt();
            int var6 = var1.restoreInt();
            this.setColor(new Color(var4, var5, var6));
            URL var7 = URL.restore(var1);
            if (var3 > 2) {
               this.setKeepLoaded(var1.restoreBoolean());
            }

            if (var7 == null) {
               var2 = (Texture)var1.restoreMaybeNull();
            } else {
               this.loadTexture(var7);
            }
            break;
         default:
            throw new TooNewException();
      }

      if (var2 != null) {
         this.textures = new Texture[1];
         this.textures[0] = var2;
      }

      Debug.dAssert(var1.version() >= 6 || this.getOwner() == null);
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Texture").allowSetNull();
            } else if (var3 == 1) {
               MaterialTexture var6;
               if (this.textures != null && this.textures[0] instanceof StringTexture) {
                  var6 = new MaterialTexture((StringTexture)this.textures[0]);
               } else {
                  var6 = new MaterialTexture(this.textureName);
               }

               this.add(var6);
               var5 = var6;
            } else if (var3 == 2) {
               if (var4 == null) {
                  this.loadTexture(null);
               } else {
                  Console.println(Console.message("Cant-undo-tex"));
               }
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = ColorPropertyEditor.make(new Property(this, var1, "Color"));
            } else if (var3 == 1) {
               var5 = this.getColor();
            } else if (var3 == 2) {
               this.setColor((Color)var4);
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Ambient Reflection Coefficient"), 0.0F, 1.0F);
            } else if (var3 == 1) {
               var5 = new Float(this.getAmbient());
            } else if (var3 == 2) {
               this.setAmbient((Float)var4);
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Diffuse Reflection Coefficient"), 0.0F, 1.0F);
            } else if (var3 == 1) {
               var5 = new Float(this.getDiffuse());
            } else if (var3 == 2) {
               this.setDiffuse((Float)var4);
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Specular Reflection Coefficient"), 0.0F, 1.0F);
            } else if (var3 == 1) {
               var5 = new Float(this.getSpecular());
            } else if (var3 == 2) {
               this.setSpecular((Float)var4);
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Opacity"), 0.0F, 1.0F);
            } else if (var3 == 1) {
               var5 = new Float(this.getOpacity());
            } else if (var3 == 2) {
               this.setOpacity((Float)var4);
            }
            break;
         case 6:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Smooth"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getSmooth());
            } else if (var3 == 2) {
               this.setSmooth((Boolean)var4);
            }
            break;
         case 7:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Filter"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getFilter());
            } else if (var3 == 2) {
               this.setFilter((Boolean)var4);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 8, var3, var4);
      }

      return var5;
   }

   public String toString() {
      return this.getName()
         + "["
         + (this.textureName != null ? this.textureName.toString() : (this.textures == null ? null : this.textures.toString()))
         + ", "
         + this.getColor()
         + ", Ambient "
         + this.getAmbient()
         + ", Diffuse "
         + this.getDiffuse()
         + ", Specular "
         + this.getSpecular()
         + ", Opacity "
         + this.getOpacity()
         + ", Smooth "
         + this.getSmooth()
         + ", Filter "
         + this.getFilter()
         + ", hRes "
         + this.hRes
         + ", vRes "
         + this.vRes
         + ", loResMode "
         + false
         + "]";
   }

   static {
      nativeInit();
   }
}
