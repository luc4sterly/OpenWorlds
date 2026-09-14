package NET.worlds.console;

import java.util.Vector;

public abstract class TreeNode {
   private int level;
   private TreeNode parent;
   private boolean isOpen;

   protected TreeNode(TreeNode var1) {
      this.parent = var1;
      if (var1 != null) {
         this.level = var1.getLevel() + 1;
      }
   }

   public int getLevel() {
      return this.level;
   }

   public TreeNode getParent() {
      return this.parent;
   }

   public boolean isDescendant(TreeNode var1) {
      while (var1 != null) {
         if ((var1 = var1.getParent()) == this) {
            return true;
         }
      }

      return false;
   }

   public boolean isOpen() {
      return this.isOpen;
   }

   public void setOpen(boolean var1) {
      this.isOpen = var1;
   }

   public boolean displayAsTitle() {
      return false;
   }

   public boolean equals(Object var1) {
      return var1 instanceof TreeNode && this.getObject().equals(((TreeNode)var1).getObject());
   }

   public int hashCode() {
      return this.getObject().hashCode();
   }

   public abstract Vector getChildren();

   public boolean shouldSort() {
      return true;
   }

   public abstract Object getObject();
}
