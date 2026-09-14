package NET.worlds.scape;

import NET.worlds.core.Debug;
import java.util.Enumeration;
import java.util.Vector;

public class ShallowEnumeration extends DeepEnumeration {
   public ShallowEnumeration(SuperRoot var1) {
      this.roots.addElement(var1);
      var1.getChildren(this);
   }

   private ShallowEnumeration(Vector var1) {
   }

   private ShallowEnumeration(Enumeration var1) {
   }

   protected void getNextElement() {
      this.valueRetrieved = false;
      if (!this.roots.isEmpty()) {
         this.nextValue = (SuperRoot)this.roots.elementAt(this.roots.size() - 1);
         Debug.dAssert(this.nextValue != null);
         this.roots.removeElementAt(this.roots.size() - 1);
      } else if (this.currentIndex >= 0) {
         try {
            this.nextValue = (SuperRoot)this.currentVector.elementAt(this.currentIndex--);
         } catch (ArrayIndexOutOfBoundsException var2) {
            this.currentIndex = this.currentVector.size() - 1;
            this.getNextElement();
         }

         Debug.dAssert(this.nextValue != null);
      } else if (!this.vectors.isEmpty()) {
         this.currentVector = (Vector)this.vectors.elementAt(this.vectors.size() - 1);
         this.currentIndex = this.currentVector.size() - 1;
         this.vectors.removeElementAt(this.vectors.size() - 1);
         this.getNextElement();
      } else {
         this.nextValue = null;
      }
   }
}
