package NET.worlds.scape;

import java.io.IOException;

public class StdoutAction extends Action {
   String txt = null;
   boolean dumpArg = false;
   private static Object classCookie = new Object();

   public StdoutAction() {
   }

   public StdoutAction(String var1) {
      this.txt = var1;
   }

   public Persister trigger(Event var1, Persister var2) {
      if (this.txt != null) {
         System.out.println(this.txt);
      } else {
         System.out.println("StdoutAction " + this.getName() + ", no text!");
      }

      if (this.dumpArg) {
         if (var1 == null) {
            System.out.println("<Null event>");
         } else {
            System.out.println("<" + var1 + ">");
         }
      }

      System.out.flush();
      return null;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Text Out"));
            } else if (var3 == 1) {
               var5 = this.txt;
            } else if (var3 == 2) {
               this.txt = (String)var4;
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Dump Event"), "Don't print event", "Print event");
            } else if (var3 == 1) {
               var5 = new Boolean(this.dumpArg);
            } else if (var3 == 2) {
               this.dumpArg = (Boolean)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 2, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      super.saveState(var1);
      var1.saveString(this.txt);
      var1.saveBoolean(this.dumpArg);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.txt = var1.restoreString();
            var1.setOldFlag();
            break;
         case 1:
            super.restoreState(var1);
            this.txt = var1.restoreString();
            this.dumpArg = var1.restoreBoolean();
            break;
         default:
            throw new TooNewException();
      }
   }

   public String toString() {
      return super.toString() + "[" + this.txt + "]";
   }
}
