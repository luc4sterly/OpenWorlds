package NET.worlds.scape;

import NET.worlds.core.IniFile;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class BizCard extends Attribute {
   String[] _line = new String[]{"", "", "", "", ""};
   private static Object classCookie = new Object();

   public BizCard(int var1) {
      super(var1);
      this.loadIni();
   }

   public BizCard() {
   }

   private void loadIni() {
      for (int var1 = 0; var1 < 5; var1++) {
         this._line[var1] = IniFile.gamma().getIniString("BizCard" + var1, this._line[var1]);
      }
   }

   public String[] get() {
      return this._line;
   }

   public void set(String[] var1) {
      int var2 = 0;

      for (int var3 = 0; var3 < this._line.length; var3++) {
         int var4 = var1[var3].length();
         var2 += var4;
         if (var2 < 200 && var1[var3] != null) {
            this._line[var3] = var1[var3];
         } else {
            this._line[var3] = "";
         }
      }

      this.noteChange();
   }

   protected void noteAddingTo(SuperRoot var1) {
      this.set(this._line);
   }

   public void generateNetData(DataOutputStream var1) throws IOException {
      var1.writeInt(this._line.length);

      for (int var2 = 0; var2 < this._line.length; var2++) {
         var1.writeUTF(this._line[var2]);
      }
   }

   public void setFromNetData(DataInputStream var1, int var2) throws IOException {
      int var3 = var1.readInt();
      String[] var4 = new String[var3];

      for (int var5 = 0; var5 < var3; var5++) {
         var4[var5] = var1.readUTF();
      }

      this.set(var4);
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
         case 1:
         case 2:
         case 3:
         case 4:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Line " + (var1 - var2)));
            } else if (var3 == 1) {
               var5 = this._line[var1 - var2];
            } else if (var3 == 2) {
               this._line[var1 - var2] = (String)var4;
               this.set(this._line);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 5, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
      var1.saveInt(this._line.length);

      for (int var2 = 0; var2 < this._line.length; var2++) {
         var1.saveString(this._line[var2]);
      }
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            int var2 = var1.restoreInt();
            this._line = new String[var2];

            for (int var3 = 0; var3 < var2; var3++) {
               this._line[var3] = var1.restoreString();
            }

            this.set(this._line);
            return;
         default:
            throw new TooNewException();
      }
   }
}
