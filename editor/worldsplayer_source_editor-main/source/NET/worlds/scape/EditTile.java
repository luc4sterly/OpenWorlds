package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.DialogDisabled;
import NET.worlds.console.DialogReceiver;
import NET.worlds.console.ExposedPanel;
import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.console.PolledDialog;
import NET.worlds.console.RenderCanvas;
import NET.worlds.console.SnapTool;
import NET.worlds.console.Tree;
import NET.worlds.console.TreeCallback;
import NET.worlds.core.Debug;
import NET.worlds.network.URL;
import java.awt.Button;
import java.awt.Component;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Label;
import java.awt.Point;
import java.io.IOException;
import java.text.MessageFormat;
import java.util.Enumeration;
import java.util.Vector;

public class EditTile extends ExposedPanel implements DialogReceiver, TreeCallback, MainCallback, DialogDisabled {
   private Button editButton = new Button(Console.message("Edit"));
   private Button addButton = new Button(Console.message("Add"));
   private Button delButton = new Button(Console.message("Delete"));
   private Button helpButton = new Button(Console.message("Help"));
   private ToolBar toolbar = new ToolBar();
   private Label title = new Label();
   private String titleText = "";
   private boolean usingTitleAsPrompt;
   private PropList props = new PropList();
   private int queuedFunction = 0;
   private Object queuedObject;
   private Tree tree;
   private PolledDialog activePopup;
   private boolean startup = true;
   private World rootWorld = null;
   private boolean isDialogDisabled;
   private static final int NONE = 0;
   private static final int DELETE = 1;
   private static final int ADD = 2;
   private static final int CHANGE = 3;
   private static final int UPDATE = 4;
   private static final int CUT = 5;
   private static final int COPY = 6;
   private static final int PASTE = 7;
   private static final int UNDO = 8;
   private static final int EDIT = 9;
   private static final int DROP = 10;
   private static final int HELP = 11;
   private static ClipboardEntry clipboard;
   private static UndoStack undoStack = new UndoStack();
   private Undoable preAddStackTop;
   private boolean isAdd;
   private SendURLAction helpAction = new SendURLAction();
   private Persister helpBrowser;

   public void viewProperties(Object var1) {
      Console.getFrame().setShaperVisible(true);
      this.queue(3, var1);
   }

   public void libraryDrop(URL var1, String var2, Component var3, Point var4) {
      this.queue(10, new DropInfo(var1, var2, var3, var4));
   }

   public EditTile(Tree var1) {
      this.tree = var1;
      var1.setOwner(this);
      GridBagLayout var2 = new GridBagLayout();
      this.setLayout(var2);
      GridBagConstraints var3 = new GridBagConstraints();
      var3.fill = 2;
      var3.gridwidth = 0;
      var3.weightx = 1.0;
      var3.weighty = 0.0;
      var3.anchor = 18;
      this.add(var2, this.toolbar, var3);
      this.add(var2, this.title, var3);
      var3.weighty = 1.0;
      var3.fill = 1;
      var3.gridwidth = 2;
      var3.gridheight = 0;
      this.add(var2, this.props, var3);
      var3.weightx = 0.0;
      var3.weighty = 0.0;
      var3.gridwidth = 0;
      var3.gridheight = 1;
      var3.fill = 2;
      this.add(var2, this.editButton, var3);
      this.add(var2, this.addButton, var3);
      this.add(var2, this.delButton, var3);
      this.add(var2, this.helpButton, var3);
      Main.register(this);
   }

   public void update() {
      this.queue(4);
   }

   private void add(GridBagLayout var1, Component var2, GridBagConstraints var3) {
      var1.setConstraints(var2, var3);
      this.add(var2);
   }

   private boolean queue(int var1) {
      return this.queue(var1, null);
   }

   private synchronized boolean queue(int var1, Object var2) {
      if (this.queuedFunction == 0 && this.activePopup == null) {
         this.queuedFunction = var1;
         this.queuedObject = var2;
         this.disable();
      }

      return true;
   }

   public synchronized void mainCallback() {
      if (this.startup) {
         World var1 = Pilot.getActiveWorld();
         if (var1 != null) {
            this.change(var1);
            this.startup = false;
         }
      }

      if (this.rootWorld != null) {
         this.rootWorld.incRef();
      }

      boolean var3 = true;
      switch (this.queuedFunction) {
         case 0:
            return;
         case 1:
            this.delete(false);
            break;
         case 2:
            var3 = this.doAdd();
            break;
         case 3:
            this.change(this.queuedObject);
            break;
         case 4:
            this.tree.update();
            break;
         case 5:
            this.delete(true);
            break;
         case 6:
            this.doCopy();
            break;
         case 7:
            this.doPaste();
            break;
         case 8:
            this.doUndo();
            break;
         case 9:
            var3 = this.doEdit();
            break;
         case 10:
            if (!this.drop((DropInfo)this.queuedObject)) {
               Object[] var2 = new Object[]{new String("" + ((DropInfo)this.queuedObject).url)};
               Console.println(MessageFormat.format(Console.message("Target-doesnt"), var2));
            }
            break;
         case 11:
            this.doHelp();
      }

      this.enable(var3);
      this.queuedFunction = 0;
      this.queuedObject = null;
   }

   private void delete(boolean var1) {
      if (this.delButton.isEnabled()) {
         PropTreeNode var2 = (PropTreeNode)this.tree.getSelectedNode();
         if (var2 != null && this.tree.hasFocus()) {
            this.addUndoable(var2.delete(var1));
         } else {
            Property var3 = this.props.getSelectedProperty();
            Debug.dAssert(var3.canSetNull() && var3.get() != null);
            this.addUndoableSet(var3, null);
         }

         this.tree.update();
      }
   }

   public static void adjustDroppedSource(SuperRoot var0) {
      if (var0 != null && (!(var0 instanceof WObject) || !((WObject)var0).isDynamic())) {
         var0.setSourceURL(null);
      }
   }

   private boolean drop(DropInfo var1) {
      Object var2 = var1.url;
      if (var1.url.endsWith(".class") || var1.url.endsWith("." + WObject.getSaveExtension())) {
         SuperRoot var3 = WobLoader.immediateLoad(var1.url);
         adjustDroppedSource(var3);
         var2 = var3;
      }

      return this.drop(var2, var1.propertyName, false, var1.comp, var1.location);
   }

   private boolean drop(Object var1, String var2, boolean var3) {
      return this.drop(var1, var2, var3, null, null);
   }

   private boolean drop(Object var1, String var2, boolean var3, Component var4, Point var5) {
      if (var1 == null) {
         return false;
      }

      PropTreeNode var6 = null;
      Point3Temp var7 = null;
      if (var4 == null && this.tree.hasFocus()) {
         var6 = (PropTreeNode)this.tree.getSelectedNode();
      } else if (var4 == this.tree) {
         var6 = (PropTreeNode)this.tree.elementAt(var5);
      } else if (var4 instanceof RenderCanvas) {
         Camera var8 = ((RenderCanvas)var4).getCamera();
         var7 = Point3Temp.make();
         WObject var9 = var8.getObjectAt(var5.x, var5.y, false, var7);
         if (var9 != null) {
            if (var1 instanceof WObject) {
               var9 = var9.getRoom();
            }
         } else {
            Pilot var10 = Pilot.getActive();
            var9 = var10.getRoom();
            var7.set(0.0F, 180.0F, 0.0F);
            var7.times(var10);
         }

         if (var9 != null) {
            this.change(var9);
            var6 = (PropTreeNode)this.tree.getSelectedNode();
         }
      }

      if (var6 == null) {
         return false;
      }

      boolean var16 = false;
      VectorProperty var14;
      PropAdder var15;
      if ((var14 = var6.getContainingVectorProperty()) != null && (var15 = var14.getAdder()) != null) {
         var16 = var15.libraryDrop(this, var1, var3, true);
      }

      if (!var16) {
         Object var11 = null;

         while (var6 != null) {
            var11 = var6.getObject();
            if (var11 instanceof Properties) {
               break;
            }

            if (var11 instanceof Property) {
               Property var12 = (Property)var11;
               var11 = ((Property)var11).get();
               if (var11 instanceof Properties) {
                  break;
               }
            }

            var6 = (PropTreeNode)var6.getParent();
         }

         if (var6 != null) {
            Vector var18 = new Vector();
            int var13 = this.recurseFindDropTargets(var18, var1, var2, var3, new EnumProperties(var11), 0, 10);
            if (var13 == 1 || var13 == 0 && var18.size() == 1) {
               var16 = ((LibraryDrop)var18.elementAt(0)).libraryDrop(this, var1, var3, true);
            }
         }
      }

      if (var16) {
         if (var1 instanceof Properties) {
            this.change(var1);
         } else {
            this.tree.update();
         }
      }

      WObject var17;
      if (var7 != null && var1 instanceof WObject && !(var1 instanceof Room) && (var17 = (WObject)var1).isActive()) {
         var7.z = var17.getZ();
         var17.moveTo(SnapTool.snapTool().snapTo(var7));
      }

      return var16;
   }

   private int recurseFindDropTargets(Vector var1, Object var2, String var3, boolean var4, Enumeration var5, int var6, int var7) {
      int var8 = 0;
      if (var6 > var7) {
         return 0;
      }

      while (var5.hasMoreElements()) {
         Property var9 = (Property)var5.nextElement();
         boolean var10 = var3 == null || var3.equals(var9.getName());
         if (var10) {
            LibraryDrop var11 = null;
            if (var9 instanceof VectorProperty) {
               var11 = ((VectorProperty)var9).getAdder();
            } else {
               var11 = var9.getEditor();
            }

            if (var11 != null && var11.libraryDrop(this, var2, var4, false)) {
               if (var6 == 0) {
                  var1.insertElementAt(var11, var8++);
               } else {
                  var1.addElement(var11);
               }
               continue;
            }
         }

         if (!(var9 instanceof VectorProperty)) {
            int var13 = this.recurseFindDropTargets(var1, var2, var3, var4, new EnumProperties(var9.get()), var6 + 1, var7);
            if (var13 != 0) {
               return var13;
            }
         }
      }

      return var8;
   }

   private boolean change(Object var1) {
      Object var2 = var1;
      Vector var4 = new Vector();

      Object var3;
      while (var2 instanceof Properties && (var3 = ((Properties)var2).propertyParent()) != null) {
         if (var4 != null) {
            EnumProperties var5 = new EnumProperties(var3);
            boolean var6 = false;

            while (var5.hasMoreElements()) {
               Property var7 = (Property)var5.nextElement();
               Object var8 = var7.get();
               boolean var9 = var7 instanceof VectorProperty;
               if (var8 == var2 || var9 && var8 != null && ((Vector)var8).indexOf(var2) != -1) {
                  if (var9) {
                     var4.insertElementAt(var2, 0);
                  }

                  var4.insertElementAt(var7, 0);
                  var6 = true;
                  break;
               }
            }

            if (!var6) {
               var4 = null;
            }
         }

         var2 = var3;
      }

      this.rootWorld = null;
      if (var2 instanceof World) {
         this.rootWorld = (World)var2;
      }

      PropTreeNode var10 = new PropTreeNode(var2);
      if (var4 != null) {
         this.tree.change(var10, var4);
      } else {
         this.tree.change(var10, var1);
      }

      return true;
   }

   public void treeFocusChanged(boolean var1) {
      if (var1) {
         this.props.deselect(this.props.getSelectedIndex());
         this.adjustButtons();
      }
   }

   public void treeChange(Object var1) {
      if (var1 instanceof Property && !(var1 instanceof VectorProperty)) {
         var1 = ((Property)var1).get();
      }

      this.props.setObject(var1);
      this.toolbar.setCurrentObject(var1);
      String var2 = var1.getClass().getName();
      int var3;
      if ((var3 = var2.lastIndexOf(46)) != -1) {
         var2 = var2.substring(var3 + 1);
      }

      this.setTitle(var2 + " " + Console.message("Properties"));
      this.adjustButtons();
   }

   private void setTitle(String var1) {
      this.titleText = var1;
      if (!this.usingTitleAsPrompt) {
         this.title.setText(var1);
      }
   }

   public void setPrompt(String var1) {
      this.title.setText((this.usingTitleAsPrompt = var1 != null) ? var1 : this.titleText);
   }

   private void adjustButtons() {
      PropTreeNode var1 = (PropTreeNode)this.tree.getSelectedNode();
      if (var1 != null && this.tree.hasFocus()) {
         this.editButton.enable(var1.canEdit());
         this.delButton.enable(var1.canDelete());
         this.addButton.enable(var1.canAdd());
         this.helpButton.enable(true);
      } else {
         Property var2 = this.props.getSelectedProperty();
         if (var2 != null) {
            Object var3 = var2.get();
            this.editButton.enable(var2.getEditor() != null);
            this.delButton.enable(var2.canSetNull() && var3 != null);
            this.addButton.enable(var2.canSetNull() && var2.getEditor() != null && var3 == null);
            this.helpButton.enable(var2.helpExists);
         } else {
            this.editButton.disable();
            this.delButton.disable();
            this.addButton.disable();
            this.helpButton.disable();
         }
      }
   }

   public void dialogDisable(boolean var1) {
      this.isDialogDisabled = var1;
      this.toolbar.dialogDisable(var1);
   }

   public boolean handleEvent(java.awt.Event var1) {
      if (var1.id == 701) {
         if (var1.target == this.props) {
            this.tree.setFocus(false);
         }

         this.adjustButtons();
      }

      return this.isDialogDisabled ? false : super.handleEvent(var1);
   }

   public boolean action(java.awt.Event var1, Object var2) {
      Object var3 = var1.target;
      if (var3 == this.delButton) {
         return this.queue(1);
      } else if (var3 == this.addButton) {
         return this.queue(2);
      } else if (var3 != this.editButton && (var3 != this.props || !this.editButton.isEnabled())) {
         return var3 == this.helpButton ? this.queue(11) : false;
      } else {
         return this.queue(9);
      }
   }

   public void dialogDone(Object var1, boolean var2) {
      if (var1 == this.activePopup) {
         this.activePopup = null;
         this.tree.enable();
         if (var2) {
            Undoable var3;
            Object var4;
            if (this.isAdd
               && (var3 = undoStack.peek()) != this.preAddStackTop
               && var3 instanceof UndoablAdd
               && (var4 = ((UndoablAdd)var3).getObject()) instanceof Properties) {
               this.change(var4);
            } else {
               this.tree.update();
            }
         }

         this.enable();
      }
   }

   private boolean doEdit() {
      Property var1 = this.props.getSelectedProperty();
      PropEditor var2;
      if (var1 != null && (var2 = var1.getEditor()) != null) {
         this.isAdd = false;
         this.activePopup = var2.edit(this, "Edit " + var1.getName());
         this.tree.disable();
         return false;
      } else {
         return true;
      }
   }

   private boolean doAdd() {
      PropTreeNode var1 = (PropTreeNode)this.tree.getSelectedNode();
      PropAdder var2;
      if (var1 != null && this.tree.hasFocus() && (var2 = var1.getAdder()) != null) {
         this.preAddStackTop = undoStack.peek();
         this.isAdd = true;
         this.activePopup = var2.add(this, "Add to " + var1.getContainerName());
         this.tree.disable();
         return false;
      } else {
         return true;
      }
   }

   public void cut() {
      this.queue(5);
   }

   public void paste() {
      this.queue(7);
   }

   private boolean doPaste() {
      if (clipboard != null) {
         SuperRoot var1 = clipboard.paste();
         if (this.drop(var1, null, true)) {
            return true;
         }

         clipboard.unPaste(var1);
         Console.println(Console.message("Clip-contents"));
      } else {
         Console.println(Console.message("Clip-empty"));
      }

      return false;
   }

   private boolean doHelp() {
      this.helpAction.showDialog = false;
      if (this.tree.hasFocus() && this.props.getSelectedProperty() == null) {
         try {
            SuperRoot var6 = (SuperRoot)((PropTreeNode)this.tree.getSelectedNode()).getObject();
            if (var6 != null) {
               this.helpAction.setDestination(var6.getHelpURL());
            }
         } catch (ClassCastException var5) {
            Console.println(Console.message("No-help"));
         }
      } else {
         Property var1 = this.props.getSelectedProperty();
         if (var1 != null && var1.helpExists) {
            try {
               SuperRoot var3 = (SuperRoot)((PropTreeNode)this.tree.getSelectedNode()).getObject();
               if (var3 != null) {
                  this.helpAction.setDestination(var3.getHelpURL(var1));
               }
            } catch (ClassCastException var4) {
               Console.println(Console.message("No-help"));
            }
         }
      }

      this.helpBrowser = this.helpAction.trigger(null, this.helpBrowser);
      return true;
   }

   public void copy() {
      this.queue(6);
   }

   private void doCopy() {
      SuperRoot var1 = this.getCurSuperRoot(true);
      if (var1 != null) {
         ClipboardEntry var2 = new ClipboardEntry();
         if (var2.copy(var1)) {
            this.addUndoable(new UndoabCopy(var2));
         }
      }
   }

   public boolean save(String var1) {
      SuperRoot var2 = this.getCurSuperRoot(true);

      try {
         var2.saveFile(new URL(URL.getCurDir(), var1));
         return true;
      } catch (IOException var4) {
         return false;
      }
   }

   private SuperRoot getCurSuperRoot(boolean var1) {
      Object var2 = this.props.getObject();
      return var2 instanceof SuperRoot ? (SuperRoot)var2 : null;
   }

   public void addUndoable(Undoable var1) {
      undoStack.push(var1);
   }

   public void addUndoableSet(Property var1, Object var2) {
      this.addUndoable(new UndoablSet(var1, var2));
   }

   public void addUndoableAdd(VectorProperty var1, Object var2, boolean var3) {
      this.addUndoable(new UndoablAdd(var1, var2));
      if (!var3) {
         this.preAddStackTop = undoStack.peek();
      }
   }

   public void addUndoablePaste(VectorProperty var1, Object var2) {
      try {
         this.addUndoable(new UndoablPaste(var1, clipboard, var2));
      } catch (Error var4) {
         Console.println(var4.getMessage());
      }
   }

   public void undo() {
      if (Main.isMainThread()) {
         this.doUndo();
      } else {
         this.queue(8);
      }
   }

   private void doUndo() {
      if (undoStack.undo()) {
         this.tree.update();
      }
   }

   public static void setClipboard(ClipboardEntry var0) {
      clipboard = var0;
   }

   public static ClipboardEntry getClipboard() {
      return clipboard;
   }
}
