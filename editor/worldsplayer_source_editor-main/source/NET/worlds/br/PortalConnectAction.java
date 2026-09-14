package NET.worlds.br;

import NET.worlds.network.URL;
import NET.worlds.scape.Action;
import NET.worlds.scape.BooleanPropertyEditor;
import NET.worlds.scape.Event;
import NET.worlds.scape.NoSuchPropertyException;
import NET.worlds.scape.Persister;
import NET.worlds.scape.Portal;
import NET.worlds.scape.Property;
import NET.worlds.scape.Restorer;
import NET.worlds.scape.Saver;
import NET.worlds.scape.StringPropertyEditor;
import NET.worlds.scape.SuperRoot;
import NET.worlds.scape.TooNewException;
import java.io.IOException;
import java.net.MalformedURLException;

public class PortalConnectAction extends Action {
   protected String _farSideWorld;
   protected String _farSideRoomName;
   protected String _farSidePortalName;
   protected boolean biconnect = true;
   private static Object classCookie = new Object();

   public Persister trigger(Event var1, Persister var2) {
      SuperRoot var3 = this.getOwner();
      if (var3 != null && var3 instanceof Portal) {
         Portal var4 = (Portal)var3;
         if (var2 == null) {
            try {
               var4.disconnect();
               var4.setFarSideInfo(new URL((SuperRoot)null, this._farSideWorld), this._farSideRoomName, this._farSidePortalName);
               var4.reset();
               var4.triggerLoad();
            } catch (MalformedURLException var6) {
               System.out.println("PortalConnectAction.trigger: bad URL." + var6);
            }
         }

         if (!this.biconnect) {
            return null;
         } else if (var4.connected()) {
            Portal var5 = var4.farSide();
            var5.disconnect();
            var5.connectTo(var4);
            return null;
         } else {
            return this;
         }
      } else {
         return null;
      }
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Target World (or null)"));
            } else if (var3 == 1) {
               var5 = this._farSideWorld == null ? "" : this._farSideWorld;
            } else if (var3 == 2) {
               this._farSideWorld = (String)var4;
               if ("".equals(this._farSideWorld)) {
                  this._farSideWorld = null;
               }
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Target Room"));
            } else if (var3 == 1) {
               var5 = this._farSideRoomName == null ? "" : this._farSideRoomName;
            } else if (var3 == 2) {
               this._farSideRoomName = (String)var4;
               if ("".equals(this._farSideRoomName)) {
                  this._farSideRoomName = null;
               }
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Target Portal"));
            } else if (var3 == 1) {
               var5 = this._farSidePortalName == null ? "" : this._farSidePortalName;
            } else if (var3 == 2) {
               this._farSidePortalName = (String)var4;
               if ("".equals(this._farSidePortalName)) {
                  this._farSidePortalName = null;
               }
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Biconnect"), "No (connect one way)", "Yes (connect both ways)");
            } else if (var3 == 1) {
               var5 = new Boolean(this.biconnect);
            } else if (var3 == 2) {
               this.biconnect = (Boolean)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 4, var3, var4);
      }

      return var5;
   }

   public String toString() {
      return super.toString() + "PCAction";
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(2, classCookie);
      super.saveState(var1);
      var1.saveString(this._farSideWorld);
      var1.saveString(this._farSideRoomName);
      var1.saveString(this._farSidePortalName);
      var1.saveBoolean(this.biconnect);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      this.restoreStateHelper(var1, classCookie);
   }

   public void restoreStateHelper(Restorer var1, Object var2) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            super.restoreState(var1);
            this._farSideWorld = var1.restoreString();
            this._farSideRoomName = var1.restoreString();
            this._farSidePortalName = var1.restoreString();
            break;
         case 2:
            super.restoreState(var1);
            this._farSideWorld = var1.restoreString();
            this._farSideRoomName = var1.restoreString();
            this._farSidePortalName = var1.restoreString();
            this.biconnect = var1.restoreBoolean();
            break;
         default:
            throw new TooNewException();
      }
   }
}
