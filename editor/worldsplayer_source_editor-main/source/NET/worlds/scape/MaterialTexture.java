package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.network.URL;
import java.awt.Color;

class MaterialTexture extends SuperRoot implements NonPersister {
   private URL fileName;
   private StringTexture stexture;
   private String text = "";
   private String font = Console.message("MaterialFont");
   private int size = 48;
   private Color foregroundColor = Color.white;
   private Color backgroundColor = Color.black;

   MaterialTexture(URL var1) {
      this.fileName = var1;
   }

   MaterialTexture(StringTexture var1) {
      this.stexture = var1;
      this.text = this.stexture.getText();
      this.font = this.stexture.getFont();
      this.size = this.stexture.getSize();
      this.foregroundColor = this.stexture.getForegroundColor();
      this.backgroundColor = this.stexture.getBackgroundColor();
   }

   private void setFile(URL var1, boolean var2) {
      this.fileName = var1;
      if (this.stexture == null || var2) {
         this.stexture = null;
         ((Material)this.getOwner()).loadTexture(var1);
      }
   }

   private void makeString() {
      Material var1 = (Material)this.getOwner();
      this.stexture = new StringTexture(this.text, this.font, this.size, this.foregroundColor, this.backgroundColor);
      var1.setTexture(this.stexture);
   }

   private String getText() {
      return this.text;
   }

   private void setText(String var1) {
      this.text = var1;
      if (this.stexture != null) {
         this.makeString();
      }
   }

   private void setFont(String var1) {
      this.font = var1;
      if (this.stexture != null) {
         this.makeString();
      }
   }

   private void setSize(int var1) {
      if (var1 >= 1 && var1 <= 720) {
         this.size = var1;
         if (this.stexture != null) {
            this.makeString();
         }
      } else {
         Console.println(Console.message("Font-sizes"));
      }
   }

   private void setForegroundColor(Color var1) {
      this.foregroundColor = var1;
      if (this.stexture != null) {
         this.makeString();
      }
   }

   private void setBackgroundColor(Color var1) {
      this.backgroundColor = var1;
      if (this.stexture != null) {
         this.makeString();
      }
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(
                  new Property(this, var1, "Texture Type (Text String)"), "Texture loaded from an image file.", "Texture created from a text string."
               );
            } else if (var3 == 1) {
               var5 = new Boolean(this.stexture != null);
            } else if (var3 == 2) {
               boolean var6 = (Boolean)var4;
               if (var6 && this.stexture == null) {
                  this.makeString();
               } else if (!var6 && this.stexture != null) {
                  this.setFile(this.fileName, true);
               }
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = new Property(this, var1, "File");
               if (this.stexture == null) {
                  var5 = URLPropertyEditor.make((Property)var5, TextureDecoder.getAllExts());
               }
            } else if (var3 == 1) {
               var5 = this.fileName;
            } else if (var3 == 2) {
               this.setFile((URL)var4, false);
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Text");
               if (this.stexture != null) {
                  var5 = StringPropertyEditor.make((Property)var5);
               }
            } else if (var3 == 1) {
               var5 = this.getText();
            } else if (var3 == 2) {
               this.setText((String)var4);
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Font");
               if (this.stexture != null) {
                  var5 = StringPropertyEditor.make((Property)var5);
               }
            } else if (var3 == 1) {
               var5 = this.font;
            } else if (var3 == 2) {
               this.setFont((String)var4);
            }

            System.out.println("Setting font " + (String)var4 + " in Material.java");
            break;
         case 4:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Size");
               if (this.stexture != null) {
                  var5 = IntegerPropertyEditor.make((Property)var5);
               }
            } else if (var3 == 1) {
               var5 = new Integer(this.size);
            } else if (var3 == 2) {
               this.setSize((Integer)var4);
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Foreground Color");
               if (this.stexture != null) {
                  var5 = ColorPropertyEditor.make((Property)var5);
               }
            } else if (var3 == 1) {
               var5 = this.foregroundColor;
            } else if (var3 == 2) {
               this.setForegroundColor((Color)var4);
            }
            break;
         case 6:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Background Color");
               if (this.stexture != null) {
                  var5 = ColorPropertyEditor.make((Property)var5);
               }
            } else if (var3 == 1) {
               var5 = this.backgroundColor;
            } else if (var3 == 2) {
               this.setBackgroundColor((Color)var4);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 7, var3, var4);
      }

      return var5;
   }

   public String toString() {
      if (this.stexture != null) {
         return "" + this.stexture;
      }

      Material var1 = (Material)this.getOwner();
      URL var2 = null;
      if (var1 != null) {
         var2 = var1.textureName;
      }

      return var2 == null ? "File " : "File " + var2;
   }
}
