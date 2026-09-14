package NET.worlds.scape;

import NET.worlds.console.Console;
import java.awt.Color;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class Whiteboard extends Attribute {
   String _line = "default text";
   private static Object classCookie = new Object();

   public Whiteboard(int var1) {
      super(var1);
   }

   public Whiteboard() {
   }

   protected void noteAddingTo(SuperRoot var1) {
      this.nada((Surface)((Sharer)var1).getOwner());
      this.setOwnerText();
   }

   public void set(String var1) {
      this._line = var1;
      this.setOwnerText();
      this.noteChange();
   }

   protected void nada(Surface var1) {
   }

   private void setOwnerText() {
      Sharer var1 = (Sharer)this.getOwner();
      if (var1 != null) {
         Surface var2 = (Surface)var1.getOwner();
         var2.setMaterial(new Material(new StringTexture(this._line, Console.message("MaterialFont"), 20, Color.black, Color.white)));
      }
   }

   public String get() {
      return this._line;
   }

   public void generateNetData(DataOutputStream var1) throws IOException {
      var1.writeUTF(this._line);
   }

   public void setFromNetData(DataInputStream var1, int var2) throws IOException {
      this.set(var1.readUTF());
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Whiteboard text"));
            } else if (var3 == 1) {
               var5 = this._line;
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
      var1.saveString(this._line);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this._line = var1.restoreString();
            this.setOwnerText();
            return;
         default:
            throw new TooNewException();
      }
   }
}
