package NET.worlds.console;

import java.awt.Dimension;
import java.awt.Event;
import java.awt.Frame;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.List;
import java.awt.Point;

public class StatisticsWindow extends Frame implements MainCallback, MainTerminalCallback, TreeCallback {
   Tree _tree = new Tree(this);
   List _list = new List(10, false);
   StatMan _lastStat;

   public StatisticsWindow(java.awt.Window var1) {
      super("Statistics Manager");
      GridBagLayout var2 = new GridBagLayout();
      this.setLayout(var2);
      GridBagConstraints var3 = new GridBagConstraints();
      var3.fill = 1;
      var3.weightx = 0.4;
      var3.weighty = 1.0;
      var3.gridwidth = 1;
      var3.gridheight = 0;
      var2.setConstraints(this._tree, var3);
      this.add(this._tree);
      var3.weightx = 0.6;
      var3.gridwidth = 0;
      var2.setConstraints(this._list, var3);
      this.add(this._list);
      this.pack();
      Point var4 = var1.location();
      Dimension var5 = var1.size();
      this.reshape(var4.x + (var5.width - 512) / 2, var4.y + (var5.height - 240) / 2, 512, 240);
      this.show();
      StatisticsRoot var6 = StatisticsRoot.getNode();
      var6.setTree(this._tree);
      StatTreeNode var7 = new StatTreeNode(var6, null);
      this._tree.change(var7, var7.getObject());
      StatMemNode.getNode();
      StatNetRefNode.getNode();
      this._tree.change(var7, StatRateNode.getNode());
      Main.register(this);
   }

   public boolean handleEvent(Event var1) {
      switch (var1.id) {
         case 201:
            if (this._lastStat != null) {
               this._lastStat.releaseList(false);
            }

            this._lastStat = null;
            this.dispose();
            return true;
         default:
            return super.handleEvent(var1);
      }
   }

   public void treeChange(Object var1) {
      if (this._lastStat != null) {
         this._lastStat.releaseList(false);
      }

      this._lastStat = (StatMan)var1;
      this._lastStat.grabList(this._list);
   }

   public void treeFocusChanged(boolean var1) {
   }

   public void mainCallback() {
   }

   public void terminalCallback() {
      if (this._lastStat != null) {
         this._lastStat.releaseList(true);
      }

      this._lastStat = null;
      Main.unregister(this);
   }
}
