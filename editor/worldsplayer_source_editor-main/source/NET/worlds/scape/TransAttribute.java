package NET.worlds.scape;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class TransAttribute extends Attribute {
   private Point3 defPos;
   private Point3 defRAxis;
   private float defRotation;
   private Point3 defScale;
   private int _sharingMode = 57344;
   private static Object classCookie = new Object();

   public TransAttribute(int var1) {
      super(var1);
   }

   public TransAttribute() {
   }

   protected void noteAddingTo(SuperRoot var1) {
      WObject var2 = (WObject)((Sharer)var1).getOwner();
      var2._transformAttribute = this;
      this.initDefault();
   }

   public void detach() {
      WObject var1 = (WObject)((Sharer)this.getOwner()).getOwner();
      var1._transformAttribute = null;
      super.detach();
   }

   public void noteChange() {
      if (!TCompressor.dontSend) {
         super.noteChange();
      }
   }

   public void generateNetData(DataOutputStream var1) throws IOException {
      WObject var2 = (WObject)this.getOwner().getOwner();
      if (this._shorthandVersion == 0) {
         Point3Temp var3 = var2.getPosition();
         var1.writeFloat(var3.x);
         var1.writeFloat(var3.y);
         var1.writeFloat(var3.z);
         Point3Temp var4 = var2.getScale();
         var1.writeFloat(var4.x);
         var1.writeFloat(var4.y);
         var1.writeFloat(var4.z);
      } else {
         this.initDefault();
         TCompressor.compress(var2, this.defPos, this.defRAxis, this.defRotation, this.defScale, this._sharingMode, var1);
      }
   }

   private void initDefault() {
      if (this.defPos == null) {
         WObject var1 = (WObject)((Sharer)this.getOwner()).getOwner();
         this.defPos = new Point3(var1.getPosition());
         this.defRAxis = new Point3();
         this.defRotation = var1.getSpin(this.defRAxis);
         this.defScale = new Point3(var1.getScale());
      }
   }

   public void setFromNetData(DataInputStream var1, int var2) throws IOException {
      WObject var3 = (WObject)this.getOwner().getOwner();
      this.initDefault();

      try {
         TCompressor.decompress(var3, this.defPos, this.defRAxis, this.defRotation, this.defScale, this._sharingMode, var2, var1);
      } catch (IOException var5) {
         TCompressor.dontSend = false;
         throw var5;
      }
   }

   public boolean getSharingPosition() {
      return (this._sharingMode & 32768) != 0;
   }

   public void setSharingPosition(boolean var1) {
      if (var1) {
         this._sharingMode |= 32768;
      } else {
         this._sharingMode &= -32769;
      }
   }

   public boolean getSharingRotation() {
      return (this._sharingMode & 16384) != 0;
   }

   public void setSharingRotation(boolean var1) {
      if (var1) {
         this._sharingMode |= 16384;
      } else {
         this._sharingMode &= -16385;
      }
   }

   public boolean getSharingScale() {
      return (this._sharingMode & 8192) != 0;
   }

   public void setSharingScale(boolean var1) {
      if (var1) {
         this._sharingMode |= 8192;
      } else {
         this._sharingMode &= -8193;
      }
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Share Position"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getSharingPosition());
            } else if (var3 == 2) {
               this.setSharingPosition((Boolean)var4);
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Share Rotation"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getSharingRotation());
            } else if (var3 == 2) {
               this.setSharingRotation((Boolean)var4);
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Share Scale"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getSharingScale());
            } else if (var3 == 2) {
               this.setSharingScale((Boolean)var4);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 3, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(2, classCookie);
      super.saveState(var1);
      this.initDefault();
      var1.saveInt(this._sharingMode);
      var1.saveFloat(this.defPos.x);
      var1.saveFloat(this.defPos.y);
      var1.saveFloat(this.defPos.z);
      var1.saveFloat(this.defRAxis.x);
      var1.saveFloat(this.defRAxis.y);
      var1.saveFloat(this.defRAxis.z);
      var1.saveFloat(this.defRotation);
      var1.saveFloat(this.defScale.x);
      var1.saveFloat(this.defScale.y);
      var1.saveFloat(this.defScale.z);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      int var2 = var1.restoreVersion(classCookie);
      switch (var2) {
         case 0:
            super.restoreState(var1);
            break;
         case 1:
         case 2:
            this.defPos = new Point3();
            this.defRAxis = new Point3();
            this.defScale = new Point3();
            super.restoreState(var1);
            this._sharingMode = var1.restoreInt();
            this.defPos.x = var1.restoreFloat();
            this.defPos.y = var1.restoreFloat();
            this.defPos.z = var1.restoreFloat();
            this.defRAxis.x = var1.restoreFloat();
            this.defRAxis.y = var1.restoreFloat();
            this.defRAxis.z = var1.restoreFloat();
            this.defRotation = var1.restoreFloat();
            this.defScale.x = var1.restoreFloat();
            this.defScale.y = var1.restoreFloat();
            this.defScale.z = var1.restoreFloat();
            break;
         default:
            throw new TooNewException();
      }

      if (var2 < 2) {
         this._shorthandVersion = var2;
      }
   }

   public int getMaxShorthandVersion() {
      return 1;
   }
}
