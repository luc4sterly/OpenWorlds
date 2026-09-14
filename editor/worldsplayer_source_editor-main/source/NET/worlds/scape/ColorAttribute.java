package NET.worlds.scape;

import java.awt.Color;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class ColorAttribute extends Attribute {
   private Color value = Color.black;
   private static Object classCookie = new Object();

   public ColorAttribute(int var1) {
      super(var1);
   }

   public ColorAttribute() {
   }

   public void set(Color var1) {
      this.value = var1;
      this.noteChange();
   }

   public Color get() {
      return this.value;
   }

   public void generateNetData(DataOutputStream var1) throws IOException {
      var1.writeInt(this.value.getRGB());
   }

   public void setFromNetData(DataInputStream var1, int var2) throws IOException {
      this.value = new Color(var1.readInt());
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = ColorPropertyEditor.make(new Property(this, var1, "value"));
            } else if (var3 == 1) {
               var5 = this.get();
            } else if (var3 == 2) {
               this.set((Color)var4);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 1, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
      var1.saveInt(this.value.getRGB());
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.value = new Color(var1.restoreInt());
            return;
         default:
            throw new TooNewException();
      }
   }

   public String toString() {
      return super.toString() + "[" + this.get() + "]";
   }
}
