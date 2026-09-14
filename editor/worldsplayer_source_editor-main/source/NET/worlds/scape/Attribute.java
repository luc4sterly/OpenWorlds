package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.core.Debug;
import NET.worlds.network.InfiniteWaitException;
import NET.worlds.network.NetworkObject;
import NET.worlds.network.ObjID;
import NET.worlds.network.PacketTooLargeException;
import NET.worlds.network.WorldServer;
import NET.worlds.network.propReqCmd;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.util.Vector;

public abstract class Attribute extends Sensor {
   public int _shorthandVersion = this.getMaxShorthandVersion();
   int _attrID;
   byte[] _serverData;
   boolean _waitingForFeedback;
   byte[] _outgoing;
   boolean loaded;
   Vector callbacks;
   private Attribute _to;
   private int _storedForwardAttrID = -1;
   protected int _propertyFlags = 208;
   protected int _accessFlags = 0;
   private static Object classCookie = new Object();

   public int getMaxShorthandVersion() {
      return 0;
   }

   public void load(LoadedAttribute var1) {
      if (this.loaded) {
         if (var1 != null) {
            var1.loadedAttribute(this, null);
         }
      } else {
         Sharer var2 = (Sharer)this.getOwner();
         if (var2 != null && var2.isShared()) {
            if (var1 != null) {
               if (this.callbacks == null) {
                  this.callbacks = new Vector();
               }

               this.callbacks.addElement(var1);
            }

            Attribute var3 = this.getForwardAttribute();
            if (var3 != null) {
               var3.load(null);
            } else {
               Debug.dAssert((var2.getMode() & 1) == 0);
               SuperRoot var4 = var2.getOwner();

               try {
                  WorldServer var5;
                  String var6;
                  if (var4 instanceof Room) {
                     var5 = ((Room)var4).getServer();
                     var6 = ((Room)var4).getNetworkRoom().getLongID();
                  } else {
                     var5 = ((NetworkObject)var4).getServer();
                     var6 = ((NetworkObject)var4).getLongID();
                  }

                  var5.sendNetworkMsg(new propReqCmd(new ObjID(var6), this._attrID));
               } catch (InfiniteWaitException var7) {
               } catch (PacketTooLargeException var8) {
                  Debug.dAssert(false);
               }
            }
         } else {
            if (var1 != null) {
               var1.loadedAttribute(this, "unshared");
            }
         }
      }
   }

   public int getAttrID() {
      return this._attrID;
   }

   public Attribute(int var1) {
      this._attrID = var1;
   }

   public Attribute() {
   }

   public void setAttrID(int var1) {
      this.flushBuffers();
      Sharer var2 = (Sharer)this.getOwner();
      if (var2 == null) {
         this._attrID = var1;
      } else {
         var2.resetAttributeID(this, var1);
      }
   }

   private void flushBuffers() {
      this._serverData = null;
      this._waitingForFeedback = false;
      this._outgoing = null;
   }

   public int getForwardAttrID() {
      return this._to != null ? this._to._attrID : this._storedForwardAttrID;
   }

   public void unforward() {
      if (this._to != null) {
         this._storedForwardAttrID = this._to.getAttrID();
         Sharer var1 = (Sharer)this._to.getOwner();
         if (var1 != null) {
            var1.removeAttribute(this._to);
         }
      }

      this.flushBuffers();
   }

   public boolean isForwarded() {
      return this._to != null;
   }

   public Attribute getForwardAttribute() {
      return this._to;
   }

   public void setForwardAttrID(int var1) {
      if (this._to != null) {
         this._to.setAttrID(var1);
      } else {
         this._storedForwardAttrID = var1;
         Sharer var2 = (Sharer)this.getOwner();
      }
   }

   public void noteChange() {
      Sharer var1 = (Sharer)this.getOwner();
      if (var1 != null) {
         var1.noteChange(this, this.actions.size() > 0);
      }
   }

   public void addForwarding() {
      if (!this.isForwarded()) {
         Sharer var1 = (Sharer)this.getOwner();
         Debug.dAssert(((WObject)var1.getOwner()).getSharerMode() == 3);
         WObject var2 = ((WObject)var1.getOwner()).getServed();
         if (var2 != null) {
            if (this.getOwner().getOwner() != var2) {
               ForwardAttribute var3 = new ForwardAttribute(this, this._storedForwardAttrID);
               var2.addShareableAttribute(var3);
               this._to = var3;
            }
         }
      }
   }

   public abstract void generateNetData(DataOutputStream var1) throws IOException;

   public abstract void setFromNetData(DataInputStream var1, int var2) throws IOException;

   public void detach() {
      super.detach();
      this.unforward();
   }

   public int getFlags() {
      return this._propertyFlags;
   }

   public void setFlag(int var1, boolean var2) {
      if (var2) {
         this._propertyFlags |= var1;
      } else {
         this._propertyFlags &= ~var1;
      }
   }

   public void setFinger(boolean var1) {
      this.setFlag(32, var1);
   }

   public boolean getFinger() {
      return (this.getFlags() & 32) != 0;
   }

   public void setAutoUpdate(boolean var1) {
      this.setFlag(64, var1);
   }

   public boolean getAutoUpdate() {
      return (this.getFlags() & 64) != 0;
   }

   public void setDatabase(boolean var1) {
      this.setFlag(128, var1);
   }

   public boolean getDatabase() {
      return (this.getFlags() & 128) != 0;
   }

   public void setBinary(boolean var1) {
      this.setFlag(16, var1);
   }

   public boolean getBinary() {
      return (this.getFlags() & 16) != 0;
   }

   public int getAccessFlags() {
      return this._accessFlags;
   }

   public void setAccessFlags(int var1) {
      this._accessFlags = var1;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Attribute ID"));
            } else if (var3 == 1) {
               var5 = new Integer(this._attrID);
            } else if (var3 == 2) {
               int var8 = (Integer)var4;
               if (var8 >= 0 && var8 <= 255) {
                  this.setAttrID(var8);
               } else {
                  Console.println(Console.message("Attribute-id"));
               }
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Fingerable"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getFinger());
            } else if (var3 == 2) {
               this.setFinger((Boolean)var4);
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Auto Update"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getAutoUpdate());
            } else if (var3 == 2) {
               this.setAutoUpdate((Boolean)var4);
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Store in Database"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getDatabase());
            } else if (var3 == 2) {
               this.setDatabase((Boolean)var4);
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Shorthand version"));
            } else if (var3 == 1) {
               var5 = new Integer(this._shorthandVersion);
            } else if (var3 == 2) {
               int var7 = (Integer)var4;
               if (var7 >= 0 && var7 <= this.getMaxShorthandVersion()) {
                  this._shorthandVersion = var7;
               } else {
                  Console.println(Console.message("Shorthand-version") + " " + this.getMaxShorthandVersion());
               }
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Forwarder attrID"));
            } else if (var3 == 1) {
               var5 = new Integer(this.getForwardAttrID());
            } else if (var3 == 2) {
               int var6 = (Integer)var4;
               if (var6 >= 0 && var6 <= 255) {
                  this.setForwardAttrID(var6);
               } else {
                  Console.println(Console.message("Attribute-id"));
               }
            }
            break;
         case 6:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Load Now"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(false);
            } else if (var3 == 2 && (Boolean)var4) {
               this.load(null);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 7, var3, var4);
      }

      return var5;
   }

   public Object propertyParent() {
      return this.getOwner().getOwner();
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(5, classCookie);
      super.saveState(var1);
      var1.saveInt(this._attrID);
      var1.saveInt(this.getForwardAttrID());
      var1.saveInt(this._propertyFlags);
      var1.saveInt(this._shorthandVersion);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            this._attrID = var1.restoreInt();
            if (var1.restoreBoolean()) {
               this._storedForwardAttrID = var1.restoreInt();
            } else {
               var1.restoreInt();
            }
            break;
         case 1:
            this._attrID = var1.restoreInt();
            this._storedForwardAttrID = var1.restoreInt();
            break;
         case 2:
            this._attrID = var1.restoreInt();
            this._storedForwardAttrID = var1.restoreInt();
            this._propertyFlags = var1.restoreInt();
            break;
         case 3:
            this.restoreStateSuperRoot(var1);
            this._attrID = var1.restoreInt();
            this._storedForwardAttrID = var1.restoreInt();
            this._propertyFlags = var1.restoreInt();
            break;
         case 4:
            this.restoreStateSuperRoot(var1);
            this._attrID = var1.restoreInt();
            this._storedForwardAttrID = var1.restoreInt();
            this._propertyFlags = var1.restoreInt();
            this._shorthandVersion = var1.restoreInt();
            break;
         case 5:
            super.restoreState(var1);
            this._attrID = var1.restoreInt();
            this._storedForwardAttrID = var1.restoreInt();
            this._propertyFlags = var1.restoreInt();
            this._shorthandVersion = var1.restoreInt();
            break;
         default:
            throw new TooNewException();
      }
   }

   public String toString() {
      return this.isForwarded() ? super.toString() + "[forwarded to " + this._to.getName() + "]" : super.toString();
   }

   public void releaseAuxilaryData() {
   }
}
