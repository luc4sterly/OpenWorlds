package NET.worlds.scape;

import NET.worlds.core.Debug;
import java.util.Enumeration;
import java.util.NoSuchElementException;

public class EnumProperties implements Enumeration {
   private Properties props;
   private Property next;
   private int index = 0;

   public EnumProperties(Object var1) {
      if (var1 instanceof Properties) {
         this.props = (Properties)var1;
      }
   }

   public boolean hasMoreElements() {
      if (this.props != null && this.next == null) {
         try {
            this.next = (Property)this.props.properties(this.index++, 0, 0, null);
            Debug.dAssert(this.next.index == this.index - 1);
         } catch (NoSuchPropertyException var2) {
         }
      }

      return this.next != null;
   }

   public Object nextElement() {
      if (this.hasMoreElements()) {
         try {
            return this.next;
         } finally {
            this.next = null;
         }
      } else {
         throw new NoSuchElementException();
      }
   }
}
