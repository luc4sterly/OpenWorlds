package NET.worlds.scape;

import NET.worlds.core.Debug;

class PropPropEditorDialog extends ListChooserDialog {
   private SuperRoot _target;
   private Property _property;
   private boolean _nullHandling;

   PropPropEditorDialog(EditTile var1, String var2, Property var3, SuperRoot var4, boolean var5) {
      super(var1, var2);
      this._target = var4;
      this._property = var3;
      this._nullHandling = var5;
      this.ready();
   }

   protected String getEntry(int var1) {
      Property var2 = null;

      try {
         var2 = (Property)this._target.properties(var1, 0, 0, null);
      } catch (NoSuchPropertyException var4) {
      }

      return var2 == null ? null : var2.getName();
   }

   protected int getSelected() {
      if (this._property == null) {
         return -1;
      }

      Property var1 = (Property)this._property.get();
      return var1 == null ? -1 : var1.getIndex();
   }

   protected boolean setValue(String var1, int var2) {
      if (var2 == -1 && !this._nullHandling) {
         return false;
      }

      Object var3 = null;

      try {
         var3 = this._target.properties(var2, 0, 0, null);
      } catch (NoSuchPropertyException var5) {
         Debug.assert_(false);
      }

      this._parent.addUndoableSet(this._property, var3);
      return true;
   }
}
