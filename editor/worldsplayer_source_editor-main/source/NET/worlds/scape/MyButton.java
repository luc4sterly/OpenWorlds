package NET.worlds.scape;

import java.awt.Button;

class MyButton extends Button {
   int numParamsXYZ;
   int numParamsN;

   MyButton(String var1, int var2, int var3) {
      super(var1);
      this.numParamsXYZ = var2;
      this.numParamsN = var3;
   }
}
