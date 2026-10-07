package java.awt;

public class BufferCapabilities implements Cloneable {
   public BufferCapabilities(ImageCapabilities front, ImageCapabilities back, Object flipContents) {
   }

   public boolean isPageFlipping() {
      return false;
   }

   public Object clone() {
      try {
         return super.clone();
      } catch (CloneNotSupportedException e) {
         throw new InternalError();
      }
   }
}
