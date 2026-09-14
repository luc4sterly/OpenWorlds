package NET.worlds.console;

import NET.worlds.core.Debug;
import java.util.Vector;

class StatTreeNode extends TreeNode {
   private StatMan _obj;

   public StatTreeNode(StatMan var1, TreeNode var2) {
      super(var2);
      Debug.dAssert(var1 != null);
      this._obj = var1;
   }

   public Vector getChildren() {
      Vector var1 = this._obj.getChildren();
      if (var1 == null) {
         return new Vector();
      }

      if (var1.size() <= 0) {
         return var1;
      }

      Vector var2 = new Vector();

      for (int var3 = 0; var3 <= var1.size() - 1; var3++) {
         var2.addElement(new StatTreeNode((StatMan)var1.elementAt(var3), this));
      }

      return var2;
   }

   public Object getObject() {
      return this._obj;
   }

   public String toString() {
      return this._obj.toString();
   }
}
