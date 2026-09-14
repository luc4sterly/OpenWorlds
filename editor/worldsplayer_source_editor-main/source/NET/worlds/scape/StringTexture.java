package NET.worlds.scape;

import java.awt.Color;
import java.io.IOException;

public class StringTexture extends Texture implements Persister {
   private String _text;
   private String _font;
   private int _size;
   private Color _fore;
   private Color _back;
   private char[] _array;
   private int _length;
   private static Object classCookie = new Object();

   public StringTexture(String var1, String var2, int var3, Color var4, Color var5) {
      this._text = var1;
      this._font = var2;
      this._size = var3;
      this._fore = var4;
      this._back = var5;
      this._array = var1.toCharArray();
      this._length = var1.length();
      this.makeStringTexture();
   }

   protected StringTexture() {
   }

   public static native void nativeInit();

   private native void makeStringTexture();

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
      var1.saveString(this._text);
      var1.saveString(this._font);
      var1.saveInt(this._size);
      var1.saveInt(this._fore.getRGB());
      var1.saveInt(this._back.getRGB());
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this._text = var1.restoreString();
            this._array = this._text.toCharArray();
            this._length = this._text.length();
            this._font = var1.restoreString();
            this._size = var1.restoreInt();
            this._fore = new Color(var1.restoreInt());
            this._back = new Color(var1.restoreInt());
            this.makeStringTexture();
            return;
         default:
            throw new TooNewException();
      }
   }

   public String getText() {
      return this._text;
   }

   public String getFont() {
      return this._font;
   }

   public int getSize() {
      return this._size;
   }

   public Color getForegroundColor() {
      return this._fore;
   }

   public Color getBackgroundColor() {
      return this._back;
   }

   public String toString() {
      return super.toString()
         + "["
         + this._text
         + ", Font "
         + this._font
         + ", Size "
         + this._size
         + ", Forground "
         + this._fore
         + ", Background "
         + this._back
         + "]";
   }

   static {
      nativeInit();
   }
}
