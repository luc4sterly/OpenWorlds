package NET.worlds.scape;

import NET.worlds.console.TreeNode;
import NET.worlds.core.Debug;
import java.util.Vector;

class PropTreeNode extends TreeNode {
   private Object obj;
   private boolean allowSorting = true;

   public PropTreeNode(Object var1) {
      super(null);
      this.obj = var1;
      Debug.dAssert(var1 != null);
   }

   public PropTreeNode(Object var1, TreeNode var2) {
      super(var2);
      this.obj = var1;
      Debug.dAssert(var1 != null);
   }

   public boolean shouldSort() {
      return this.allowSorting;
   }

   public Vector getChildren() {
      Vector var1 = null;
      Object var2 = this.obj;
      if (var2 instanceof VectorProperty) {
         VectorProperty var3 = (VectorProperty)var2;
         this.allowSorting = var3.shouldSort();
         var1 = new Vector();
         Vector var4 = (Vector)var3.get();
         if (var4 != null) {
            int var5 = var4.size();

            for (int var6 = 0; var6 < var5; var6++) {
               Object var7 = var4.elementAt(var6);
               if (var7 == null) {
                  System.out.println("Error: VectorProperty " + var3.getName() + " of " + var3.getOwner() + " was null.");
               } else {
                  var1.addElement(new PropTreeNode(var7, this));
               }
            }
         }
      } else {
         if (var2 instanceof Property) {
            var2 = ((Property)var2).get();
         }

         if (var2 instanceof Properties) {
            var1 = new Vector();
            EnumProperties var8 = new EnumProperties(var2);

            while (var8.hasMoreElements()) {
               Property var9 = (Property)var8.nextElement();
               if (var9 instanceof VectorProperty || var9.getEditor() == null && var9.get() instanceof Properties) {
                  var1.addElement(new PropTreeNode(var9, this));
               }
            }
         }
      }

      return var1;
   }

   public Object getObject() {
      return this.obj;
   }

   public boolean displayAsTitle() {
      return this.obj instanceof VectorProperty || this.obj instanceof Property;
   }

   public boolean canEdit() {
      return false;
   }

   public VectorProperty getContainingVectorProperty() {
      Object var1 = this.obj;
      TreeNode var2 = this.getParent();
      return !(var1 instanceof VectorProperty) && (var2 == null || !((var1 = var2.getObject()) instanceof VectorProperty)) ? null : (VectorProperty)var1;
   }

   public PropAdder getAdder() {
      VectorProperty var1 = this.getContainingVectorProperty();
      return var1 != null ? var1.getAdder() : null;
   }

   public String getContainerName() {
      return this.getContainingVectorProperty().getName();
   }

   public boolean canAdd() {
      PropAdder var1 = this.getAdder();
      return var1 != null && var1.hasAddDialog();
   }

   public boolean canDelete() {
      TreeNode var2 = this.getParent();
      Object var1;
      Object var3;
      return var2 != null
         && (
            (var1 = var2.getObject()) instanceof VectorProperty && ((VectorProperty)var1).getAdder() != null
               || (var3 = this.getObject()) instanceof Property && ((Property)var3).canSetNull() && ((Property)var3).get() != null
         );
   }

   public Undoable delete(boolean var1) {
      Debug.dAssert(this.canDelete());
      Object var2 = this.getParent().getObject();
      if (var2 instanceof VectorProperty) {
         VectorProperty var3 = (VectorProperty)var2;
         Vector var4 = (Vector)var3.get();
         int var5 = var4.indexOf(this.obj);
         Debug.dAssert(var5 != -1);
         return var1 ? new UndoablCut(var3, var5) : new UndoablDelete(var3, var5);
      } else {
         return new UndoablSet((Property)this.getObject(), null);
      }
   }

   public String toString() {
      if (this.obj instanceof SuperRoot) {
         return ((SuperRoot)this.obj).getName();
      } else {
         return this.obj instanceof Property ? ((Property)this.obj).getName() : this.obj.toString();
      }
   }
}
