package NET.worlds.scape;

import java.io.OutputStream;
import java.io.PrintStream;

public class IndentStream extends PrintStream {
   private boolean _atstart = true;
   private int _indent = 0;

   public IndentStream(OutputStream var1) {
      super(var1);
   }

   public IndentStream(OutputStream var1, boolean var2) {
      super(var1, var2);
   }

   public void indent(int var1) {
      this._indent += var1;
   }

   public void indent() {
      this.indent(2);
   }

   public void undent(int var1) {
      if (this._indent >= var1) {
         this._indent -= var1;
      } else {
         this._indent = 0;
      }
   }

   public void undent() {
      this.undent(2);
   }

   public int curIndent() {
      return this._indent;
   }

   private void startLine() {
      for (int var1 = 0; var1 < this._indent; var1++) {
         super.write(32);
      }

      this._atstart = false;
   }

   public void write(int var1) {
      if (var1 == 10) {
         this._atstart = true;
      } else if (this._atstart) {
         this.startLine();
      }

      super.write(var1);
   }

   public void write(byte[] var1, int var2, int var3) {
      while (var3 > 0) {
         int var4 = 0;

         while (var4 < var3 && var1[var2 + var4] != 10) {
            var4++;
         }

         if (var4 > 0) {
            if (this._atstart) {
               this.startLine();
            }

            super.write(var1, var2, var4);
            var2 += var4;
            var3 -= var4;
            this._atstart = false;
            var4 = 0;
         }

         while (var4 < var3 && var1[var2 + var4] == 10) {
            var4++;
         }

         if (var4 > 0) {
            super.write(var1, var2, var4);
            var2 += var4;
            var3 -= var4;
            this._atstart = true;
         }
      }
   }
}
