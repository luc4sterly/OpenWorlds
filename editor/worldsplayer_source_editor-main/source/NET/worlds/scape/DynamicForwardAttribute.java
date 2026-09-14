package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.core.Debug;
import NET.worlds.network.URL;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.text.MessageFormat;
import java.util.Enumeration;

public class DynamicForwardAttribute extends Attribute implements NonPersister, WobLoaded {
   WObject wob = null;
   static int DYNAMIC_CODE = 21990;
   WobLoader wobLoader;
   DataInputStream wobLoaderProps;
   private ByteArrayOutputStream _bs = new ByteArrayOutputStream();

   DynamicForwardAttribute(int var1) {
      super(var1);
   }

   private URL getDynamicHeader(DataInputStream var1) {
      try {
         return var1.readUnsignedShort() != DYNAMIC_CODE ? null : new URL(this, var1.readUTF());
      } catch (IOException var3) {
         return null;
      }
   }

   public void setFromNetData(DataInputStream var1, int var2) throws IOException {
      URL var3 = this.getDynamicHeader(var1);
      if (var3 != null && this.wob != null && var3.equals(this.wob.getSourceURL())) {
         this.setProps(var1);
      } else {
         if (this.wob != null) {
            WObject var4 = this.wob;
            this.wob = null;
            var4.detach();
         }

         if (var3 == null) {
            ((Sharer)this.getOwner()).removeAttribute(this);
            return;
         }

         if (this.wobLoader == null || !this.wobLoader.getWobName().equals(var3)) {
            this.wobLoader = new WobLoader(var3, this);
         }

         this.wobLoaderProps = var1;
      }
   }

   public void wobLoaded(WobLoader var1, SuperRoot var2) {
      if (var1 == this.wobLoader) {
         Object[] var3 = new Object[]{new String(var1.getWobName().toString())};
         if (var2 == null) {
            Console.println(MessageFormat.format(Console.message("Couldnt-load"), var3));
            this.wobLoaderProps = null;
         } else if (!(var2 instanceof WObject)) {
            Console.println(MessageFormat.format(Console.message("not-WObject"), var3));
            this.wobLoaderProps = null;
         } else {
            this.wob = (WObject)var2;
            this.wob.getSharer().createDynamicForwardedFromNet(this);
            ((WObject)this.getOwner().getOwner()).add(this.wob);
            this.setProps(this.wobLoaderProps);
            this.wobLoaderProps = null;
         }
      }
   }

   void connect(WObject var1) {
      Debug.dAssert(this.wob == null);
      this.wob = var1;
      this.noteChange();
   }

   void unconnect() {
      if (this.wob != null) {
         this.wob = null;
         this.noteChange();
      }
   }

   public void setProps(DataInputStream var1) {
      while (true) {
         byte[] var3;
         int var7;
         try {
            if ((var7 = var1.read()) == -1) {
               return;
            }

            byte var4 = var1.readByte();
            var3 = new byte[var4];
            var1.readFully(var3, 0, var4);
         } catch (IOException var6) {
            Object[] var2 = new Object[]{new String("" + this.getAttrID())};
            Console.println(MessageFormat.format(Console.message("Early-EOF"), var2));
            return;
         }

         this.wob.getSharer().setFromNetData(var7, var3);
      }
   }

   public void generateNetData(DataOutputStream var1) throws IOException {
      if (this.wob != null && this.wob.getSourceURL() != null) {
         var1.writeShort(DYNAMIC_CODE);
         var1.writeUTF(this.wob.getSourceURL().getRelativeTo(this));
         Enumeration var2 = this.wob.getSharer().getAttributes();

         while (var2.hasMoreElements()) {
            Attribute var3 = (Attribute)var2.nextElement();
            var1.writeByte(var3.getAttrID());
            this._bs.reset();

            try {
               var3.generateNetData(new DataOutputStream(this._bs));
            } catch (IOException var5) {
               System.err.println(var5);
               throw new Error("Fatal in generateNetData");
            }

            var1.writeByte(this._bs.size());
            this._bs.writeTo(var1);
         }
      }
   }

   protected void noteAddingTo(SuperRoot var1) {
      WObject var2 = (WObject)var1.getOwner();
      if ((var2.getSharer().getMode() & 1) != 0) {
         throw new ClassCastException("Must forward to unforwarded object");
      }
   }

   public void detach() {
      if (this.wob == null && !this._waitingForFeedback) {
         this.wobLoader = null;
         super.detach();
      } else {
         Console.println(Console.message("Shutting-down"));
         if (this.wob != null) {
            this.wob.detach();
         }
      }
   }

   public void setAttrID(int var1) {
      Console.println(Console.message("Cant-change-ID"));
   }

   public String toString() {
      return this.wob == null ? super.toString() : super.toString() + "[forwarding wob " + this.wob.getName() + "]";
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      Debug.assert_(false);
   }
}
