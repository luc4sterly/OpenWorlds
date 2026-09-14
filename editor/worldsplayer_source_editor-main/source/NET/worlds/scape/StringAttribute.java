package NET.worlds.scape;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class StringAttribute extends Attribute {
   String value = "";
   private static Object classCookie = new Object();

   public StringAttribute(int var1) {
      super(var1);
   }

   public StringAttribute() {
   }

   public void set(String var1) {
      this.value = var1;
      this.noteChange();
   }

   public String get() {
      return this.value;
   }

   public void generateNetData(DataOutputStream var1) throws IOException {
      var1.writeUTF(this.value);
   }

   public void setFromNetData(DataInputStream var1, int var2) throws IOException {
      this.value = var1.readUTF();
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "value"));
            } else if (var3 == 1) {
               var5 = this.get();
            } else if (var3 == 2) {
               this.set((String)var4);
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
      var1.saveString(this.value);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.value = var1.restoreString();
            this.set(this.value);
            return;
         default:
            throw new TooNewException();
      }
   }

   public String toString() {
      return super.toString() + "[" + this.get() + "]";
   }
}
