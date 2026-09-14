package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.DefaultConsole;
import NET.worlds.console.NoWebControlException;
import NET.worlds.console.WebControl;
import NET.worlds.console.WebControlFactory;
import NET.worlds.console.WebControlImp;
import NET.worlds.console.WebControlListener;
import NET.worlds.core.IniFile;
import NET.worlds.network.URL;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class Billboard extends Attribute implements WebControlListener {
   WebControlImp _wci = null;
   TextureSurface _surface;
   Texture[] _textures;
   Material _material = null;
   String _textureURL = "$SCRIPTSERVERgetad.pl?u=$USERNAME";
   String _adURL = "http://www.worlds.com/";
   String _defTextureURL = IniFile.override().getIniString("defaultAd", "adworlds.cmp");
   int _xPercent = 100;
   int _yPercent = 100;
   int _xSurface = 468;
   int _ySurface = 60;
   boolean _hasToolbar = true;
   boolean _isFixed = false;
   int _rows = 1;
   int _refresh = 5;
   boolean _passClicks = true;
   boolean _isAdBanner = true;
   boolean _retryURL = false;
   int frameCnt = -1;
   private static Object classCookie = new Object();

   public Billboard(int var1) {
      super(var1);
   }

   public Billboard() {
   }

   public final void noteChange() {
   }

   protected void noteAddingTo(SuperRoot var1) {
      Rect var2 = (Rect)((Sharer)var1).getOwner();
      var2._billboardAttribute = this;
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
      if (this._wci != null) {
         this._wci.detach();
      }

      this._wci = null;
      this._rows = var3;
      this._material = new Material(URL.make(this._defTextureURL), var2, var3);
      var1.setMaterial(this._material);
      this._textures = this._material.getTextures();
      this._surface = new TextureSurface(this._textures, var3, this._xSurface, this._ySurface);

      try {
         this._wci = WebControlFactory.createWebControlImp(this._surface.getHwnd(), false, this._isAdBanner);
      } catch (NoWebControlException var5) {
         System.out.println("Could not create MSIE control for billboard.");
         this._wci = null;
         return;
      }

      if (!this._wci.setURL(this._textureURL)) {
         this._retryURL = true;
      }

      this._wci.addListener(this);
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
      var1._billboardAttribute = null;
      if (this._wci != null) {
         this._wci.detach();
      }

      super.detach();
   }

   public void finalize() {
      this.releaseAuxilaryData();
      super.finalize();
   }

   public boolean getIsAdBanner() {
      return this._isAdBanner;
   }

   public void billboardClicked(Point2 var1) {
      if (this._passClicks) {
         double var7 = (double)var1.x * this._surface.getWidth();
         double var8 = (double)var1.y * this._surface.getHeight();
         var8 = this._surface.getHeight() - var8;
         this._surface.sendLeftClick((int)var7, (int)var8);
      } else {
         Console var2 = Console.getActive();
         if (var2 != null && var2 instanceof DefaultConsole) {
            DefaultConsole var3 = (DefaultConsole)var2;

            try {
               WebControl var4 = new WebControl(var3.getRender(), this._xPercent, this._yPercent, this._hasToolbar, this._isFixed, false);
               var4.activate();
               var4.setURL(this._adURL);
            } catch (NoWebControlException var6) {
               new SendURLAction(this._adURL).doIt();
            }
         }
      }
   }

   public void billboardFrame(FrameEvent var1) {
      if (this._retryURL && this._wci != null) {
         if (!this._wci.setURL(this._textureURL)) {
            return;
         }

         this._retryURL = false;
      }

      if (this._surface != null) {
         if (this.frameCnt <= this._refresh && this.frameCnt != -1) {
            this.frameCnt++;
         } else {
            if (this.frameCnt != -1 && this._refresh == -1) {
               return;
            }

            this.frameCnt = 0;
            this.draw();
         }
      }
   }

   public synchronized void draw() {
      if (this._surface != null && this._wci != null) {
         this._surface.setTextures(this._material.getTextures(), this._rows);
         this._surface.draw(this._wci);
      }
   }

   public void webControlEvent(int var1) {
      if (var1 == 1 && this._refresh == -1) {
         this.draw();
      }
   }

   public void generateNetData(DataOutputStream var1) throws IOException {
      var1.writeUTF(this._adURL);
      var1.writeUTF(this._textureURL);
      var1.writeInt(this._xPercent);
      var1.writeInt(this._yPercent);
      var1.writeInt(this._xSurface);
      var1.writeInt(this._ySurface);
      var1.writeInt(this._refresh);
      var1.writeInt(this._hasToolbar ? 1 : 0);
      var1.writeInt(this._isFixed ? 1 : 0);
      var1.writeInt(this._passClicks ? 1 : 0);
      var1.writeInt(this._isAdBanner ? 1 : 0);
   }

   public void setFromNetData(DataInputStream var1, int var2) throws IOException {
      this._adURL = var1.readUTF();
      this._textureURL = var1.readUTF();
      this._xPercent = var1.readInt();
      this._yPercent = var1.readInt();
      this._xSurface = var1.readInt();
      this._ySurface = var1.readInt();
      this._refresh = var1.readInt();
      this._hasToolbar = var1.readInt() == 1;
      this._isFixed = var1.readInt() == 1;
      this._passClicks = var1.readInt() == 1;
      this._isAdBanner = var1.readInt() == 1;
      this.noteChange();
      this.setTexture();
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Target URL"));
            } else if (var3 == 1) {
               var5 = this._adURL;
            } else if (var3 == 2) {
               this._adURL = (String)var4;
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Texture URL"));
            } else if (var3 == 1) {
               var5 = this._textureURL;
            } else if (var3 == 2) {
               this._textureURL = (String)var4;
               this.setTexture();
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "X Overlay % or Width"), 0, 1024);
            } else if (var3 == 1) {
               var5 = new Integer(this._xPercent);
            } else if (var3 == 2) {
               this._xPercent = (Integer)var4;
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Y Overlay % or Height"), 0, 1024);
            } else if (var3 == 1) {
               var5 = new Integer(this._yPercent);
            } else if (var3 == 2) {
               this._yPercent = (Integer)var4;
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Has Toolbar"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this._hasToolbar);
            } else if (var3 == 2) {
               this._hasToolbar = (Boolean)var4;
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Fixed size"), "No - Percentage specified", "Yes - Pixels specified");
            } else if (var3 == 1) {
               var5 = new Boolean(this._isFixed);
            } else if (var3 == 2) {
               this._isFixed = (Boolean)var4;
            }
            break;
         case 6:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Texture Width"), 0, 1024);
            } else if (var3 == 1) {
               var5 = new Integer(this._xSurface);
            } else if (var3 == 2) {
               this._xSurface = (Integer)var4;
               this.setTexture();
            }
            break;
         case 7:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Texture Height"), 0, 1024);
            } else if (var3 == 1) {
               var5 = new Integer(this._ySurface);
            } else if (var3 == 2) {
               this._ySurface = (Integer)var4;
               this.setTexture();
            }
            break;
         case 8:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Texture Refresh Rate"), -1, 1024);
            } else if (var3 == 1) {
               var5 = new Integer(this._refresh);
            } else if (var3 == 2) {
               this._refresh = (Integer)var4;
            }
            break;
         case 9:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(
                  new Property(this, var1, "Pass clicks"), "No - Click launches specified page", "Yes - Mouse events passed through to texture page"
               );
            } else if (var3 == 1) {
               var5 = new Boolean(this._passClicks);
            } else if (var3 == 2) {
               this._passClicks = (Boolean)var4;
            }
            break;
         case 10:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Is Ad Banner"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this._isAdBanner);
            } else if (var3 == 2) {
               this._isAdBanner = (Boolean)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 11, var3, var4);
      }

      if (var3 == 2) {
         this.noteChange();
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(3, classCookie);
      super.saveState(var1);
      var1.saveString(this._adURL);
      var1.saveString(this._textureURL);
      var1.saveInt(this._xPercent);
      var1.saveInt(this._yPercent);
      var1.saveBoolean(this._hasToolbar);
      var1.saveBoolean(this._isFixed);
      var1.saveInt(this._xSurface);
      var1.saveInt(this._ySurface);
      var1.saveInt(this._refresh);
      var1.saveBoolean(this._passClicks);
      var1.saveBoolean(this._isAdBanner);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this._adURL = var1.restoreString();
            this._textureURL = var1.restoreString();
            this._xPercent = var1.restoreInt();
            this._yPercent = var1.restoreInt();
            this._hasToolbar = var1.restoreBoolean();
            this.noteChange();
            break;
         case 1:
            super.restoreState(var1);
            this._adURL = var1.restoreString();
            this._textureURL = var1.restoreString();
            this._xPercent = var1.restoreInt();
            this._yPercent = var1.restoreInt();
            this._hasToolbar = var1.restoreBoolean();
            this._isFixed = var1.restoreBoolean();
            this.noteChange();
            break;
         case 2:
            super.restoreState(var1);
            this._adURL = var1.restoreString();
            this._textureURL = var1.restoreString();
            this._xPercent = var1.restoreInt();
            this._yPercent = var1.restoreInt();
            this._hasToolbar = var1.restoreBoolean();
            this._isFixed = var1.restoreBoolean();
            this._xSurface = var1.restoreInt();
            this._ySurface = var1.restoreInt();
            this._refresh = var1.restoreInt();
            this._passClicks = var1.restoreBoolean();
            this.noteChange();
            break;
         case 3:
            super.restoreState(var1);
            this._adURL = var1.restoreString();
            this._textureURL = var1.restoreString();
            this._xPercent = var1.restoreInt();
            this._yPercent = var1.restoreInt();
            this._hasToolbar = var1.restoreBoolean();
            this._isFixed = var1.restoreBoolean();
            this._xSurface = var1.restoreInt();
            this._ySurface = var1.restoreInt();
            this._refresh = var1.restoreInt();
            this._passClicks = var1.restoreBoolean();
            this._isAdBanner = var1.restoreBoolean();
            this.noteChange();
            break;
         default:
            throw new TooNewException();
      }

      this.setTexture();
   }

   public void releaseAuxilaryData() {
      if (this._wci != null) {
         this._wci.detach();
         this._wci = null;
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
