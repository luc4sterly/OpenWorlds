package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.core.Debug;
import NET.worlds.core.Std;
import NET.worlds.network.InfiniteWaitException;
import NET.worlds.network.ObjID;
import NET.worlds.network.PacketTooLargeException;
import NET.worlds.network.PropertyList;
import NET.worlds.network.PropertySetCmd;
import NET.worlds.network.WorldServer;
import NET.worlds.network.net2Property;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.text.MessageFormat;
import java.util.Enumeration;
import java.util.Vector;

public class Sharer extends SuperRoot implements MainCallback {
   private Vector attributes;
   private ByteArrayOutputStream bs = new ByteArrayOutputStream();
   private boolean shared = false;
   public static final int FIRST_TIME = 0;
   public static final int STATIC = 2;
   public static final int FORWARDED_STATIC = 3;
   public static final int DYNAMIC = 4;
   public static final int FORWARDED_DYNAMIC = 5;
   public static final int FORWARDED = 1;
   private boolean createdFromNet;
   Vector noteQ;
   Vector prepQ;
   Vector sendQ;
   private DynamicForwardAttribute dfa;
   int lastSendTime;
   private static Object classCookie = new Object();
   private Vector restoredAttributes = null;

   public Sharer() {
      this.attributes = new Vector(256);
      this.attributes.setSize(256);
   }

   public boolean isShared() {
      return this.shared;
   }

   private int getMaybeDefaultMode() {
      return ((WObject)this.getOwner()).getSharerMode();
   }

   public int getMode() {
      int var1 = this.getMaybeDefaultMode();
      if (var1 == 0) {
         this.setMode(var1);
      }

      return var1;
   }

   public void setMode(int var1) {
      WObject var2 = (WObject)this.getOwner();
      if (var2 instanceof Room) {
         var1 = 2;
      } else if (this.createdFromNet) {
         var1 = 4;
      } else if (var1 == 2 || var1 == 4) {
         var1 = 0;
      }

      if (var1 == 0) {
         var1 = 3;
      }

      int var3 = this.getMaybeDefaultMode();
      if (var3 != var1) {
         this.unshare();
         var2.setSharerMode(var1);
      }

      this.share();
   }

   public void createDynamicForwardedFromNet(DynamicForwardAttribute var1) {
      Debug.dAssert(!((WObject)this.getOwner()).isActive());
      this.dfa = var1;
      ((WObject)this.getOwner()).setSharerMode(5);
   }

   public void createDynamicFromNet() {
      Debug.dAssert(!((WObject)this.getOwner()).isActive() || this.createdFromNet);
      this.createdFromNet = true;
      ((WObject)this.getOwner()).setSharerMode(4);
   }

   public void adjustShare() {
      this.share();
   }

   private void share() {
      if (!this.shared) {
         int var1 = this.getMaybeDefaultMode();
         switch (var1) {
            case 0:
               this.setMode(0);
            case 1:
            case 2:
            default:
               break;
            case 3:
               this.flushQueue();
               Enumeration var4 = this.getAttributes();

               while (var4.hasMoreElements()) {
                  ((Attribute)var4.nextElement()).addForwarding();
               }
               break;
            case 4:
               Debug.dAssert(this.createdFromNet);
               break;
            case 5:
               if (this.dfa == null) {
                  this.flushQueue();
                  WObject var2 = (WObject)this.getOwner();
                  WObject var3 = var2.getServed();
                  if (var2.getSourceURL() != null && var3 != null) {
                     this.dfa = new DynamicForwardAttribute(-1);
                     if (var3.getSharer().addAttribute(this.dfa) == -1) {
                        this.dfa = null;
                     } else {
                        this.dfa.connect(var2);
                     }
                  }
               }
         }

         this.shared = true;
      }
   }

   private void unshare() {
      if (this.shared) {
         int var1 = this.getMaybeDefaultMode();
         switch (var1) {
            case 2:
            case 4:
            default:
               break;
            case 3:
               Enumeration var2 = this.getAttributes();

               while (var2.hasMoreElements()) {
                  ((Attribute)var2.nextElement()).unforward();
               }
               break;
            case 5:
               if (this.dfa != null) {
                  this.dfa.unconnect();
                  this.dfa = null;
               }
         }

         this.shared = false;
      }
   }

   public int addAttribute(Attribute var1) {
      this.setMode(this.getMaybeDefaultMode());
      var1._attrID = this.getFreeAttrIDFor(var1, var1._attrID);
      if (var1._attrID == -1) {
         return var1._attrID;
      }

      try {
         this.add(var1);
      } catch (ClassCastException var3) {
         Console.println(Console.message("Cant-attach") + var3);
         var1._attrID = -1;
         return var1._attrID;
      }

      this.attributes.setElementAt(var1, var1._attrID);
      if (this.getMaybeDefaultMode() == 3) {
         var1.addForwarding();
      }

      return var1._attrID;
   }

   public boolean attrIDAvailable(int var1) {
      return this.attributes.elementAt(var1) == null;
   }

   private int getFreeAttrID(int var1, int var2, int var3) {
      if (var1 >= 20 && var1 <= 255 && this.attrIDAvailable(var1)) {
         return var1;
      }

      int var4 = this.countFree(var2, var3);
      if (var4 == 0) {
         return -1;
      }

      int var5;
      label41:
      while (true) {
         int var6 = (int)(Math.random() * var4);
         var5 = var2;

         while (true) {
            if (this.attributes.elementAt(var5) == null) {
               if (--var6 < 0) {
                  Debug.dAssert(var5 <= var3);
                  if (var5 != 150 && var5 != 155 && var5 != 160) {
                     break label41;
                  }
                  break;
               }
            }

            var5++;
         }
      }

      return var5;
   }

   public int getFreeAttrIDFor(Attribute var1, int var2) {
      return var1 instanceof DynamicForwardAttribute ? this.getFreeAttrID(var2, 210, 249) : this.getFreeAttrID(var2, 100, 249);
   }

   public void removeAttribute(Attribute var1) {
      var1.detach();
      if (var1.getOwner() == null) {
         this.attributes.setElementAt(null, var1._attrID);
      }
   }

   public int resetAttributeID(Attribute var1, int var2) {
      var2 = this.getFreeAttrIDFor(var1, var2);
      if (var2 == -1) {
         return var2;
      }

      if (this.attributes.elementAt(var2) == null) {
         int var3 = var1._attrID;
         this.attributes.setElementAt(var1, var2);
         this.attributes.setElementAt(null, var3);
         var1._attrID = var2;
      }

      return var2;
   }

   public void moveToSlot(WObject var1, int var2) {
      if (var1.isDynamic()) {
         Sharer var3 = var1.getSharer();
         if (var3.dfa != null) {
            this.resetAttributeID(var3.dfa, var2);
         }
      }
   }

   public Enumeration getAttributes() {
      return this.getAttributesList().elements();
   }

   public Vector getAttributesList() {
      Vector var1 = new Vector(this.attributes.size());
      this.fillAttributesList(var1);
      return var1;
   }

   public void fillAttributesList(Vector var1) {
      int var2 = this.attributes.size();

      for (int var3 = 0; var3 < var2; var3++) {
         Attribute var4 = (Attribute)this.attributes.elementAt(var3);
         if (var4 != null) {
            var1.addElement(var4);
         }
      }
   }

   public Attribute getAttribute(int var1) {
      try {
         return (Attribute)this.attributes.elementAt(var1);
      } catch (ArrayIndexOutOfBoundsException var3) {
         return null;
      }
   }

   public boolean isEmpty() {
      return this.countFree(0, 255) == 256;
   }

   public int countFree(int var1, int var2) {
      int var3 = 0;

      for (int var4 = var1; var4 <= var2; var4++) {
         if (this.attributes.elementAt(var4) == null) {
            var3++;
         }
      }

      return var3;
   }

   public void getChildren(DeepEnumeration var1) {
      var1.addChildVectorWithNulls(this.attributes);
   }

   public void noteChange(Attribute var1, boolean var2) {
      Debug.dAssert(Main.isMainThread());
      if (this.prepQ == null) {
         this.noteQ = new Vector();
         this.prepQ = new Vector();
         this.sendQ = new Vector();
      }

      if (var2 && !this.noteQ.contains(var1)) {
         if (this.noteQ.isEmpty() && this.prepQ.isEmpty() && this.sendQ.isEmpty()) {
            Main.register(this);
         }

         this.noteQ.addElement(var1);
      }

      Attribute var3;
      if (this.getMode() == 3 && (var3 = var1.getForwardAttribute()) != null) {
         var3.noteChange();
      } else if (this.dfa != null) {
         this.dfa.noteChange();
      } else if (!this.prepQ.contains(var1)) {
         if (this.noteQ.isEmpty() && this.prepQ.isEmpty() && this.sendQ.isEmpty()) {
            Main.register(this);
         }

         this.prepQ.addElement(var1);
      }
   }

   private void prepQueue() {
      if (!this.noteQ.isEmpty()) {
         int var1 = this.noteQ.size();

         for (int var2 = 0; var2 < var1; var2++) {
            Attribute var3 = (Attribute)this.noteQ.elementAt(var2);
            ValueEvent var4 = new ValueEvent(Std.getFastTime(), this.getOwner(), (WObject)this.getOwner(), var3);
            var3.trigger(var4);
         }

         this.noteQ.removeAllElements();
      }

      int var6 = this.prepQ.size();

      for (int var7 = 0; var7 < var6; var7++) {
         Attribute var8 = (Attribute)this.prepQ.elementAt(var7);
         this.bs.reset();

         try {
            var8.generateNetData(new DataOutputStream(this.bs));
         } catch (IOException var5) {
            System.err.println(var5);
            throw new Error("Fatal in generateNetData");
         }

         var8._outgoing = this.bs.toByteArray();
         if (Std.byteArraysEqual(var8._outgoing, var8._serverData)) {
            var8._outgoing = null;
         } else if (!this.sendQ.contains(var8)) {
            this.sendQ.addElement(var8);
         }
      }

      this.prepQ.removeAllElements();
   }

   public void mainCallback() {
      if (this.noteQ.isEmpty() && this.prepQ.isEmpty() && this.sendQ.isEmpty()) {
         Main.unregister(this);
      } else {
         int var1 = Std.getFastTime();
         if (var1 > this.lastSendTime + 250) {
            this.sendQueue();
            Main.unregister(this);
            this.lastSendTime = var1;
         }
      }
   }

   private void flushQueue() {
      if (this.prepQ != null) {
         this.prepQueue();
         if (!this.sendQ.isEmpty()) {
            int var1 = this.sendQ.size();

            while (--var1 >= 0) {
               Attribute var2 = (Attribute)this.sendQ.elementAt(var1);
               var2._waitingForFeedback = false;
               var2._serverData = null;
               var2._outgoing = null;
            }

            this.sendQ.removeAllElements();
         }
      }
   }

   private void sendQueue() {
      this.prepQueue();
      WorldServer var1 = ((WObject)this.getOwner()).getServer();
      if (var1 != null) {
         int var2 = this.sendQ.size();

         for (int var3 = 0; var3 < var2; var3++) {
            Attribute var4 = (Attribute)this.sendQ.elementAt(var3);
            if (var4._outgoing != null) {
               this.share(var1, var4);
               var4._serverData = var4._outgoing;
               var4._outgoing = null;
               var4._waitingForFeedback = true;
            }
         }
      }

      this.sendQ.removeAllElements();
   }

   private void share(WorldServer var1, Attribute var2) {
      SuperRoot var3 = this.getOwner();
      ObjID var4 = null;
      if (var3 instanceof Room) {
         Pilot var5 = Pilot.getActive();
         if (var5 != null && var5.getLastServedRoom() != var3) {
            var4 = new ObjID(((Room)var3).getNetworkRoom().getLongID());
         } else {
            var4 = new ObjID(253);
         }
      } else if (var3 instanceof Pilot) {
         var4 = new ObjID(1);
      } else {
         var4 = new ObjID(var3.getName());
      }

      try {
         PropertyList var9 = new PropertyList();
         var9.addProperty(new net2Property(var2._attrID, var2.getFlags(), var2.getAccessFlags(), var2._outgoing));
         var1.sendNetworkMsg(new PropertySetCmd(var4, var9));
      } catch (InfiniteWaitException var6) {
         Console.println(Console.message("Net-shutdown") + var6.toString());
      } catch (PacketTooLargeException var7) {
         Debug.dAssert(false);
      }
   }

   public void setFromNetData(int var1, byte[] var2) {
      if (this.prepQ != null) {
         this.prepQueue();
      }

      Attribute var3 = this.getAttribute(var1);
      if (var3 == null) {
         if ((this.getMode() & 1) != 0) {
            Object[] var6 = new Object[]{new String("" + var1), new String(this.getOwner().getName())};
            Console.println(MessageFormat.format(Console.message("Unknown-attr"), var6));
            return;
         }

         var3 = new DynamicForwardAttribute(var1);
         this.addAttribute(var3);
      }

      this.setData(var3, var2);
      if (!var3.loaded) {
         var3.loaded = true;
         if (var3.callbacks != null && var3.callbacks.size() > 0) {
            Enumeration var4 = var3.callbacks.elements();

            while (var4.hasMoreElements()) {
               LoadedAttribute var5 = (LoadedAttribute)var4.nextElement();
               var5.loadedAttribute(var3, null);
            }

            var3.callbacks.removeAllElements();
         }
      }
   }

   private void setData(Attribute var1, byte[] var2) {
      boolean var3 = Std.byteArraysEqual(var2, var1._serverData);
      if (var1._waitingForFeedback) {
         if (!var3) {
            return;
         }

         var1._waitingForFeedback = false;
         if (var2.length != 0 || var1._outgoing != null) {
            return;
         }
      } else if (var3) {
         return;
      }

      var1._serverData = var2;
      if (Std.byteArraysEqual(var2, var1._outgoing)) {
         var1._outgoing = null;
      } else if (var1._outgoing == null) {
         try {
            var1.setFromNetData(new DataInputStream(new ByteArrayInputStream(var2)), var2.length);
         } catch (IOException var5) {
            Console.println(Console.message("Unrec-format") + var1.getName());
         }

         ValueEvent var4 = new ValueEvent(Std.getFastTime(), this, (WObject)this.getOwner(), var1);
         var1.trigger(var4);
      }
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      throw new NoSuchPropertyException();
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(2, classCookie);
      super.saveState(var1);
      var1.saveVector(this.getAttributesList());
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            this.setName(var1.restoreString());
            int var2 = var1.restoreInt();
            this.restoredAttributes = new Vector(var2);

            for (int var3 = 0; var3 < var2; var3++) {
               this.restoredAttributes.addElement(var1.restoreString());
            }
            break;
         case 1:
            this.setName(var1.restoreString());
            this.restoredAttributes = var1.restoreVector();
            break;
         case 2:
            super.restoreState(var1);
            this.restoredAttributes = var1.restoreVector();
            break;
         default:
            throw new TooNewException();
      }
   }

   public void ownerPostRestore() {
      int var1 = this.getMaybeDefaultMode();
      ((WObject)this.getOwner()).setSharerMode(0);
      this.setMode(var1);
      Enumeration var2 = this.restoredAttributes.elements();

      while (var2.hasMoreElements()) {
         Attribute var3 = (Attribute)var2.nextElement();
         this.addAttribute(var3);
      }

      this.restoredAttributes = null;
   }

   public void releaseAuxilaryData() {
      for (int var1 = 0; var1 < 256; var1++) {
         Attribute var2 = (Attribute)this.attributes.elementAt(var1);
         if (var2 != null) {
            var2.releaseAuxilaryData();
         }
      }
   }
}
