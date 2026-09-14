package NET.worlds.console;

import NET.worlds.core.Debug;
import NET.worlds.scape.LibraryDropTarget;
import java.util.Hashtable;
import java.util.Vector;

public class Tree extends TreePanel implements MainCallback, LibraryDropTarget {
   private int openItem = -1;
   private int changeItem = -1;
   private TreeCallback owner;
   private boolean registered;

   public Tree() {
   }

   public Tree(TreeCallback var1) {
      this();
      this.setOwner(var1);
   }

   public void setOwner(TreeCallback var1) {
      this.owner = var1;
   }

   public void change(TreeNode var1, Object var2) {
      this.delayRepaints(true);
      this.removeAllElements();
      this.addElement(var1);
      int var3 = this.search(0, var2, new Hashtable());
      Debug.dAssert(var3 != -1);
      this.sync(var3);
   }

   public void change(TreeNode var1, Vector var2) {
      this.delayRepaints(true);
      this.removeAllElements();
      TreeNode var3 = var1;
      this.addElement(var1);
      int var4 = 1;

      for (int var5 = 0; var5 < var2.size(); var5++) {
         Object var6 = var2.elementAt(var5);
         Vector var7 = this.getSortedChildren(var3);
         var3.setOpen(true);
         int var8 = var7.size();
         int var9 = -1;

         for (int var10 = 0; var10 < var8; var10++) {
            TreeNode var11 = (TreeNode)var7.elementAt(var10);
            int var12 = var4 + var10;
            this.insertElementAt(var11, var12);
            if (var9 == -1 && var11.getObject().equals(var6)) {
               var9 = var12;
               var3 = var11;
            }
         }

         Debug.dAssert(var9 != -1);
         var4 = var9 + 1;
      }

      this.sync(var4 - 1);
   }

   public void update() {
      Vector var1 = new Vector();
      int var2 = this.countElements();

      for (int var3 = 0; var3 < var2; var3++) {
         TreeNode var4 = this.elementAt(var3);
         if (var4.getParent() == null) {
            var1.addElement(var4);
            this.recurseAddChildren(var1, var4);
         }
      }

      TreeNode var7 = this.getSelectedNode();
      var2 = var1.size();
      int var8 = 0;

      while (var8 < var2 && !((TreeNode)var1.elementAt(var8)).equals(var7)) {
         var8++;
      }

      int var5 = var8 < var2 ? var8 : Math.min(var2 - 1, this.getSelectedIndex());
      this.delayRepaints(true);
      this.reset(var1);
      this.sync(var5);
   }

   private void sync(int var1) {
      this.select(var1);
      this.owner.treeChange(this.getSelectedNode().getObject());
      this.delayRepaints(false);
   }

   private Vector getSortedChildren(TreeNode var1) {
      Vector var2 = var1.getChildren();
      Vector var3 = new Vector(var2.size());
      if (var2 != null) {
         int var4 = var2.size();

         for (int var5 = 0; var5 < var4; var5++) {
            TreeNode var6 = (TreeNode)var2.elementAt(var5);
            if (!var1.shouldSort()) {
               var3.insertElementAt(var6, var5);
            } else {
               int var7 = var3.size();
               int var8 = 0;

               while (var8 < var7 && var3.elementAt(var8).toString().compareTo(var6.toString()) <= 0) {
                  var8++;
               }

               var3.insertElementAt(var6, var8);
            }
         }
      }

      return var3;
   }

   private Vector getCurrentChildren(TreeNode var1) {
      Vector var2 = new Vector();
      int var3 = this.countElements();

      for (int var4 = 0; var4 < var3; var4++) {
         TreeNode var5 = this.elementAt(var4);
         if (var5.getParent() == var1) {
            var2.addElement(var5);
         }
      }

      return var2;
   }

   private static TreeNode maybeUseOldChild(TreeNode var0, Vector var1) {
      int var2 = var1.size();

      for (int var3 = 0; var3 < var2; var3++) {
         TreeNode var4 = (TreeNode)var1.elementAt(var3);
         if (var4.equals(var0)) {
            return var4;
         }
      }

      return var0;
   }

   private void recurseAddChildren(Vector var1, TreeNode var2) {
      if (var2.isOpen()) {
         Vector var3 = this.getCurrentChildren(var2);
         Vector var4 = this.getSortedChildren(var2);
         int var5 = var4.size();

         for (int var6 = 0; var6 < var5; var6++) {
            TreeNode var7 = (TreeNode)var4.elementAt(var6);
            var7 = maybeUseOldChild(var7, var3);
            var1.addElement(var7);
            this.recurseAddChildren(var1, var7);
         }
      }
   }

   private int search(int var1, Object var2, Hashtable var3) {
      TreeNode var4 = this.elementAt(var1);
      if (var4.getObject().equals(var2)) {
         return var1;
      }

      if (!var3.containsKey(var4)) {
         var3.put(var4, var4);
         var1++;
         Vector var5 = this.getSortedChildren(var4);
         var4.setOpen(true);
         if (var5 != null) {
            int var6 = var5.size();

            for (int var7 = 0; var7 < var6; var7++) {
               this.insertElementAt((TreeNode)var5.elementAt(var7), var1 + var7);
            }

            for (int var10 = 0; var10 < var6; var10++) {
               int var8 = this.search(var1 + var10, var2, var3);
               if (var8 != -1) {
                  return var8;
               }
            }

            for (int var11 = 0; var11 < var6; var11++) {
               this.removeElementAt(var1);
            }
         }

         var4.setOpen(false);
      }

      return -1;
   }

   private void register() {
      if (!this.registered) {
         Main.register(this);
         this.registered = true;
      }
   }

   public void treeSelect(int var1) {
      if (var1 != this.getSelectedIndex()) {
         this.select(var1);
         this.changeItem = var1;
         this.register();
      }
   }

   public void treeOpen(int var1) {
      if (this.openItem == -1) {
         this.openItem = var1;
         this.register();
      }
   }

   public void setFocus(boolean var1) {
      boolean var2 = this.hasFocus();
      super.setFocus(var1);
      if (var2 != var1) {
         this.owner.treeFocusChanged(var1);
      }
   }

   public synchronized void mainCallback() {
      this.delayRepaints(true);
      int var1 = this.changeItem;
      this.changeItem = -1;
      if (var1 != -1) {
         this.owner.treeChange(this.elementAt(var1).getObject());
      }

      var1 = this.openItem;
      this.openItem = -1;
      if (var1 != -1) {
         TreeNode var2 = this.elementAt(var1);
         boolean var3 = !var2.isOpen();
         var2.setOpen(var3);
         var1++;
         if (var3) {
            Vector var4 = this.getSortedChildren(var2);
            if (var4 != null) {
               int var5 = var4.size();

               for (int var6 = 0; var6 < var5; var6++) {
                  this.insertElementAt((TreeNode)var4.elementAt(var6), var1++);
               }
            }
         } else {
            while (var1 < this.countElements() && var2.isDescendant(this.elementAt(var1))) {
               this.removeElementAt(var1);
            }
         }

         this.repaint();
      }

      this.delayRepaints(false);
      this.registered = false;
      Main.unregister(this);
   }
}
