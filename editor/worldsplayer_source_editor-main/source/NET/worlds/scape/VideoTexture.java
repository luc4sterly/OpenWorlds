package NET.worlds.scape;

import NET.worlds.core.IniFile;
import NET.worlds.network.URL;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class VideoTexture extends Attribute {
   DirectShow _ds = null;
   TextureSurface _surface;
   Texture[] _textures;
   Material _material = null;
   String _textureURL = "http://dev.worlds.net/rr-worlds/video/eminem.asf";
   String _defTextureURL = IniFile.override().getIniString("defaultAd", "adworlds.cmp");
   int _xSurface = 128;
   int _ySurface = 128;
   boolean _autoPlay = true;
   int _rows = 1;
   private static Object classCookie = new Object();

   public VideoTexture(int var1) {
      super(var1);
   }

   public VideoTexture() {
   }

   protected void noteAddingTo(SuperRoot var1) {
      Rect var2 = (Rect)((Sharer)var1).getOwner();
      var2._videoAttribute = this;
      this.assignMaterial(var2);
   }

   private void assignMaterial(Rect var1) {
      int var2 = this._xSurface / 128;
      if (var2 < 1) {
         var2 = 1;
      }

      int var3 = this._ySurface / 128;
      if (var3 < 1) {
         var3 = 1;
      }

      this._surface = null;
      this._ds = null;
      this._rows = var3;
      this._material = new Material(URL.make(this._defTextureURL), var2, var3);
      var1.setMaterial(this._material);
      this._textures = this._material.getTextures();
      this._surface = new TextureSurface(this._textures, var3, this._xSurface, this._ySurface);
      this._ds = new DirectShow(this._surface.getHwnd());
      this._ds.nOpen(this._textureURL);
      if (this._autoPlay) {
         this._ds.nPlay(1);
      }
   }

   private void setTexture() {
      Sharer var1 = (Sharer)this.getOwner();
      if (var1 != null) {
         Rect var2 = (Rect)var1.getOwner();
         this.assignMaterial(var2);
      }
   }

   public void detach() {
      Rect var1 = (Rect)((Sharer)this.getOwner()).getOwner();
      var1._videoAttribute = null;
      if (this._ds != null) {
         this._ds.nStop();
         this._ds = null;
      }

      super.detach();
   }

   public void finalize() {
      this.releaseAuxilaryData();
      super.finalize();
   }

   public DirectShow getDirectShow() {
      return this._ds;
   }

   public void videoFrame(FrameEvent var1) {
      this.draw();
   }

   public final void noteChange() {
   }

   public synchronized void draw() {
      if (this._surface != null && this._ds != null) {
         this._surface.setTextures(this._material.getTextures(), this._rows);
         this._surface.draw(this._ds);
      }
   }

   public void generateNetData(DataOutputStream var1) throws IOException {
      var1.writeUTF(this._textureURL);
      var1.writeInt(this._xSurface);
      var1.writeInt(this._ySurface);
   }

   public void setFromNetData(DataInputStream var1, int var2) throws IOException {
      this._textureURL = var1.readUTF();
      this._xSurface = var1.readInt();
      this._ySurface = var1.readInt();
      this.noteChange();
      this.setTexture();
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Texture URL"));
            } else if (var3 == 1) {
               var5 = this._textureURL;
            } else if (var3 == 2) {
               this._textureURL = (String)var4;
               this.setTexture();
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Texture Width"), 0, 1024);
            } else if (var3 == 1) {
               var5 = new Integer(this._xSurface);
            } else if (var3 == 2) {
               this._xSurface = (Integer)var4;
               this.setTexture();
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Texture Height"), 0, 1024);
            } else if (var3 == 1) {
               var5 = new Integer(this._ySurface);
            } else if (var3 == 2) {
               this._ySurface = (Integer)var4;
               this.setTexture();
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Auto-play?"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this._autoPlay);
            } else if (var3 == 2) {
               this._autoPlay = (Boolean)var4;
               this.setTexture();
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 4, var3, var4);
      }

      if (var3 == 2) {
         this.noteChange();
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      super.saveState(var1);
      var1.saveString(this._textureURL);
      var1.saveInt(this._xSurface);
      var1.saveInt(this._ySurface);
      var1.saveBoolean(this._autoPlay);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this._textureURL = var1.restoreString();
            this._xSurface = var1.restoreInt();
            this._ySurface = var1.restoreInt();
            this.noteChange();
            break;
         case 1:
            super.restoreState(var1);
            this._textureURL = var1.restoreString();
            this._xSurface = var1.restoreInt();
            this._ySurface = var1.restoreInt();
            this._autoPlay = var1.restoreBoolean();
            this.noteChange();
            break;
         default:
            throw new TooNewException();
      }

      this.setTexture();
   }

   public void releaseAuxilaryData() {
      if (this._ds != null) {
         this._ds.nStop();
         this._ds = null;
      }

      if (this._surface != null) {
         this._surface.finalize();
         this._surface = null;
      }

      if (this._material != null) {
         this._material.detach();
         this._material.finalize();
         this._material = null;
      }

      this._textures = null;
   }
}
