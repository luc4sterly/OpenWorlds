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
import java.io.IOException;

public class WebPageWall extends Rect implements WebControlListener {
   WebControlImp _wci = null;
   TextureSurface _surface;
   Texture[] _textures;
   Material _material = null;
   String _textureURL = "$SCRIPTSERVERgetad.pl?u=$USERNAME";
   String _postTextureData = null;
   String _adURL = "http://www.worlds.com/";
   String _postAdData = null;
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

   WebPageWall() {
   }

   public boolean getIsAdBanner() {
      return this._isAdBanner;
   }

   public void rebuild() {
      this.unbuild();
      this.assignMaterial();
   }

   public void unbuild() {
      if (this._wci != null) {
         this._wci.detach();
         this._wci = null;
      }
   }

   public void detach() {
      this.unbuild();
      super.detach();
   }

   public void finalize() {
      this.unbuild();
      super.finalize();
   }

   public boolean handle(MouseDownEvent var1) {
      if ((var1.key & 1) == 1) {
         Point2 var2 = this.deproject();
         if (this._passClicks) {
            double var8 = (double)var2.x * this._surface.getWidth();
            double var9 = (double)var2.y * this._surface.getHeight();
            var9 = this._surface.getHeight() - var9;
            this._surface.sendLeftClick((int)var8, (int)var9);
            return false;
         }

         Console var3 = Console.getActive();
         if (var3 != null && var3 instanceof DefaultConsole) {
            DefaultConsole var4 = (DefaultConsole)var3;

            try {
               WebControl var5 = new WebControl(var4.getRender(), this._xPercent, this._yPercent, this._hasToolbar, this._isFixed, false);
               var5.activate();
               var5.setURL(this._adURL, this._postAdData);
            } catch (NoWebControlException var7) {
               new SendURLAction(this._adURL).doIt();
            }
         }
      }

      return false;
   }

   public void prerender(Camera var1) {
      Point3Temp var2 = this.inCamSpace(var1);
      boolean var3 = var2 != null && var2.z > 1.0F && var2.x < var2.z && -var2.x < var2.z;
      if (var3) {
         this.visible = true;
      }
   }

   public boolean handle(FrameEvent var1) {
      if (this.visible) {
         if (this._retryURL && this._wci != null) {
            if (!this._wci.setURL(this._textureURL, this._postTextureData)) {
               return false;
            }

            this._retryURL = false;
         }

         if (this._surface != null) {
            if (this.frameCnt <= this._refresh && this.frameCnt != -1) {
               this.frameCnt++;
            } else {
               if (this.frameCnt != -1 && this._refresh == -1) {
                  return false;
               }

               this.frameCnt = 0;
               this.draw();
            }
         }
      }

      return false;
   }

   public WebControlImp getWebControlImp() {
      return this._wci;
   }

   private void assignMaterial() {
      int var1 = this._xSurface / 128;
      if (var1 < 1) {
         var1 = 1;
      }

      int var2 = this._ySurface / 128;
      if (var2 < 1) {
         var2 = 1;
      }

      this._surface = null;
      if (this._wci != null) {
         this._wci.detach();
      }

      this._wci = null;
      this._rows = var2;
      this._material = new Material(URL.make(this._defTextureURL), var1, var2);
      this.setMaterial(this._material);
      this._textures = this._material.getTextures();
      this._surface = new TextureSurface(this._textures, var2, this._xSurface, this._ySurface);

      try {
         this._wci = WebControlFactory.createWebControlImp(this._surface.getHwnd(), false, this._isAdBanner);
      } catch (NoWebControlException var4) {
         System.out.println("Could not create MSIE control for billboard.");
         this._wci = null;
         return;
      }

      if (!this._wci.setURL(this._textureURL, this._postTextureData)) {
         this._retryURL = true;
      }

      this._wci.addListener(this);
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

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Wall's URL"));
            } else if (var3 == 1) {
               var5 = this._textureURL;
            } else if (var3 == 2) {
               this._textureURL = (String)var4;
               this.rebuild();
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Wall's POST data"));
            } else if (var3 == 1) {
               var5 = this._postTextureData;
            } else if (var3 == 2) {
               this._postTextureData = (String)var4;
               this.rebuild();
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Wall Page Width (pixels)"), 0, 1024);
            } else if (var3 == 1) {
               var5 = new Integer(this._xSurface);
            } else if (var3 == 2) {
               this._xSurface = (Integer)var4;
               this.rebuild();
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Wall Page Height (pixels)"), 0, 1024);
            } else if (var3 == 1) {
               var5 = new Integer(this._ySurface);
            } else if (var3 == 2) {
               this._ySurface = (Integer)var4;
               this.rebuild();
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Wall Refresh Rate (frames)"), -1, 1024);
            } else if (var3 == 1) {
               var5 = new Integer(this._refresh);
            } else if (var3 == 2) {
               this._refresh = (Integer)var4;
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Use Scrollbars"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(!this._isAdBanner);
            } else if (var3 == 2) {
               this._isAdBanner = !(Boolean)var4;
            }
            break;
         case 6:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(
                  new Property(this, var1, "Pass clicks"), "No - Click launches target page", "Yes - Mouse events passed through to wall page"
               );
            } else if (var3 == 1) {
               var5 = new Boolean(this._passClicks);
            } else if (var3 == 2) {
               this._passClicks = (Boolean)var4;
            }
            break;
         case 7:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Target URL for click"));
            } else if (var3 == 1) {
               var5 = this._adURL;
            } else if (var3 == 2) {
               this._adURL = (String)var4;
            }
            break;
         case 8:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Target's POST data"));
            } else if (var3 == 1) {
               var5 = this._postAdData;
            } else if (var3 == 2) {
               this._postAdData = (String)var4;
               this.rebuild();
            }
            break;
         case 9:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Target Page Size Units"), "Percentage", "Pixels");
            } else if (var3 == 1) {
               var5 = new Boolean(this._isFixed);
            } else if (var3 == 2) {
               this._isFixed = (Boolean)var4;
            }
            break;
         case 10:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Target X Overlay % or Width"), 0, 1024);
            } else if (var3 == 1) {
               var5 = new Integer(this._xPercent);
            } else if (var3 == 2) {
               this._xPercent = (Integer)var4;
            }
            break;
         case 11:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Target Y Overlay % or Height"), 0, 1024);
            } else if (var3 == 1) {
               var5 = new Integer(this._yPercent);
            } else if (var3 == 2) {
               this._yPercent = (Integer)var4;
            }
            break;
         case 12:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Target Page Has Toolbar"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this._hasToolbar);
            } else if (var3 == 2) {
               this._hasToolbar = (Boolean)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 13, var3, var4);
      }

      if (var3 == 2) {
         this.rebuild();
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
      var1.saveString(this._postTextureData);
      var1.saveString(this._postAdData);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
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
            this._isAdBanner = var1.restoreBoolean();
            this._postTextureData = var1.restoreString();
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
            this._postTextureData = var1.restoreString();
            this._postAdData = var1.restoreString();
            break;
         default:
            throw new TooNewException();
      }

      this.rebuild();
   }

   public boolean acceptsLeftClicks() {
      return this.getIsAdBanner() ? true : this.getMouseOver();
   }
}
