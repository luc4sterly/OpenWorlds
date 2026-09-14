package NET.worlds.scape;

import NET.worlds.console.PolledDialog;

public class PropPropEditor extends PropEditor {
   private boolean _nullHandling;
   private SuperRoot _target;

   private PropPropEditor(Property var1, SuperRoot var2, boolean var3) {
      super(var1);
      this._target = var2;
      this._nullHandling = var3;
   }

   public PolledDialog edit(EditTile var1, String var2) {
      return new PropPropEditorDialog(var1, var2, this.property, this._target, this._nullHandling);
   }

   public static Property make(Property var0, SuperRoot var1) {
      return var0.setEditor(new PropPropEditor(var0, var1, false));
   }

   public static Property make(Property var0, SuperRoot var1, boolean var2) {
      return var0.setEditor(new PropPropEditor(var0, var1, var2));
   }
}
