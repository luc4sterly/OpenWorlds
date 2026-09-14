package NET.worlds.console;

import NET.worlds.core.Debug;
import java.awt.List;
import java.util.Vector;

abstract class StatMan {
   protected Vector _children;
   protected List _grabbedList;
   protected Tree _tree;

   void createList() {
      this.updateList();
   }

   abstract void updateList();

   void releaseList(boolean var1) {
      this._grabbedList = null;
   }

   void grabList(List var1) {
      Debug.dAssert(this._grabbedList == null);
      this._grabbedList = var1;
      this._grabbedList.clear();
      this.createList();
   }

   void setTree(Tree var1) {
      this._tree = var1;
      if (this._children != null) {
         for (int var2 = this._children.size() - 1; var2 >= 0; var2--) {
            StatMan var3 = (StatMan)this._children.elementAt(var2);
            var3.setTree(this._tree);
         }
      }
   }

   Vector getChildren() {
      return this._children;
   }

   void addChild(StatMan var1) {
      Debug.dAssert(var1 != null);
      if (this._children == null) {
         this._children = new Vector();
      }

      Debug.dAssert(this._children.indexOf(var1) == -1);
      this._children.addElement(var1);
      if (this._tree != null) {
         var1.setTree(this._tree);
         this._tree.update();
      }
   }
}
