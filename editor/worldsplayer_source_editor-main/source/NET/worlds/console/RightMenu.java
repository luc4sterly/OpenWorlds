package NET.worlds.console;

import NET.worlds.core.Debug;
import NET.worlds.scape.Action;
import NET.worlds.scape.RunningActionHandler;
import NET.worlds.scape.WObject;
import java.util.Enumeration;
import java.util.Hashtable;

public class RightMenu implements MainCallback {
   private static RightMenu _current = null;
   private WObject _obj;
   private Enumeration _acts;
   private Hashtable _inttobuttons = new Hashtable();
   private int _edit = 0;
   private int _pm = 0;
   private int _lastID = 0;

   public RightMenu(WObject var1, Enumeration var2) {
      this._obj = var1;
      this._acts = var2;
      Main.register(this);
   }

   private int add(String var1) {
      if (this._lastID == 0) {
         this._lastID = 100;
      }

      int var2 = this._lastID++;
      Debug.assert_(this._lastID < 200);
      nativeAdd(var1, var2, this._pm);
      return var2;
   }

   private static native int create();

   private static native void nativeAdd(String var0, int var1, int var2);

   private static native void addSeparator(int var0);

   private static native void show(int var0, int var1);

   private static native void discard(int var0);

   private static native int checkPressed();

   private void build(Enumeration var1) {
      if (_current != null) {
         _current.close();
      }

      _current = this;
      int var2 = 0;
      Hashtable var3 = new Hashtable();

      while (var1.hasMoreElements()) {
         Action var4 = (Action)var1.nextElement();
         String var5 = var4.rightMenuLabel;
         if (var5 != null && var5 != "") {
            var3.put(var5, var4);
            var2++;
         }
      }

      if (var2 <= 0 && Gamma.getShaper() == null) {
         this.close();
      } else {
         this._pm = create();
         if (Gamma.getShaper() != null) {
            this._edit = this.add("Edit Properties...");
            if (var2 > 0) {
               addSeparator(this._pm);
            }
         }

         Enumeration var6 = var3.keys();

         while (var6.hasMoreElements()) {
            String var7 = (String)var6.nextElement();
            this._inttobuttons.put(new Integer(this.add(var7)), var3.get(var7));
         }

         show(Window.getHWnd(), this._pm);
      }
   }

   private void close() {
      discard(this._pm);
      this._pm = 0;
      Main.unregister(this);
      _current = null;
   }

   private void checkButton() {
      int var1 = checkPressed();
      if (var1 != 0) {
         if (var1 == this._edit) {
            Console.getFrame().getEditTile().viewProperties(this._obj);
         } else {
            Action var2 = (Action)this._inttobuttons.get(new Integer(var1));
            RunningActionHandler.trigger(var2, this._obj.getWorld(), null);
         }

         this.close();
      }
   }

   public void mainCallback() {
      if (this._acts != null) {
         this.build(this._acts);
         this._acts = null;
      } else {
         this.checkButton();
      }
   }
}
