package NET.worlds.scape;

import NET.worlds.console.PolledDialog;
import NET.worlds.core.Debug;

public class EnumPropertyEditor extends PropEditor {
   private String[] choices;
   private int[] numbers;

   private EnumPropertyEditor(Property var1, String[] var2, int[] var3) {
      super(var1);
      Debug.dAssert(var2 != null);
      Debug.dAssert(var3 != null);
      int var4 = Math.max(var2.length, var3.length);
      Debug.dAssert(var4 > 1);
      this.choices = new String[var4];
      this.numbers = new int[var4];

      for (int var5 = 0; var5 < var4; var5++) {
         if (var5 < var2.length) {
            this.choices[var5] = var2[var5];
         } else {
            this.choices[var5] = var2[var2.length - 1] + var5;
         }

         if (var5 < var3.length) {
            this.numbers[var5] = var3[var5];
         } else {
            this.numbers[var5] = var3[var3.length - 1] + var5 - var3.length;
         }
      }
   }

   public PolledDialog edit(EditTile var1, String var2) {
      return new EnumFieldEditorDialog(var1, var2, this.property, this.choices, this.numbers);
   }

   public static Property make(Property var0, String[] var1, int[] var2) {
      var0.setPropertyType(5);
      return var0.setEditor(new EnumPropertyEditor(var0, var1, var2));
   }
}
