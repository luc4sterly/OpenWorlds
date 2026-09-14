package NET.worlds.scape;

import NET.worlds.core.Debug;
import java.util.Enumeration;
import java.util.Vector;

public class DeepEnumeration implements Enumeration {
   Vector roots = new Vector();
   Vector vectors = new Vector();
   Vector currentVector = null;
   int currentIndex = -1;
   SuperRoot nextValue = null;
   protected boolean valueRetrieved = true;

   public DeepEnumeration(SuperRoot var1) {
      this.addChildElement(var1);
   }

   public DeepEnumeration(Vector var1) {
      this.addChildVector(var1);
   }

   public DeepEnumeration(Enumeration var1) {
      this.addChildEnumeration(var1);
   }

   public DeepEnumeration() {
   }

   public boolean hasMoreElements() {
      if (this.valueRetrieved) {
         this.getNextElement();
      }

      return this.nextValue != null;
   }

   public Object nextElement() {
      if (this.valueRetrieved) {
         this.getNextElement();
      }

      this.valueRetrieved = true;
      return this.nextValue;
   }

   protected void getNextElement() {
      this.valueRetrieved = false;
      if (!this.roots.isEmpty()) {
         this.nextValue = (SuperRoot)this.roots.elementAt(this.roots.size() - 1);
         this.roots.removeElementAt(this.roots.size() - 1);
         Debug.dAssert(this.nextValue != null);
         this.nextValue.getChildren(this);
      } else if (this.currentIndex >= 0) {
         try {
            this.nextValue = (SuperRoot)this.currentVector.elementAt(this.currentIndex--);
         } catch (ArrayIndexOutOfBoundsException var2) {
            this.currentIndex = this.currentVector.size() - 1;
            this.getNextElement();
         }

         Debug.dAssert(this.nextValue != null);
         this.nextValue.getChildren(this);
      } else if (!this.vectors.isEmpty()) {
         this.currentVector = (Vector)this.vectors.elementAt(this.vectors.size() - 1);
         this.currentIndex = this.currentVector.size() - 1;
         this.vectors.removeElementAt(this.vectors.size() - 1);
         this.getNextElement();
      } else {
         this.nextValue = null;
      }
   }

   public void addChildVector(Vector var1) {
      Debug.dAssert(var1 != null);
      this.vectors.addElement(var1);
   }

   public void addChildEnumeration(Enumeration var1) {
      Debug.dAssert(var1 != null);

      while (var1.hasMoreElements()) {
         this.addChildElement(var1.nextElement());
      }
   }

   public void addChildVectorWithNulls(Vector var1) {
      Debug.dAssert(var1 != null);

      for (int var2 = var1.size() - 1; var2 >= 0; var2--) {
         Object var3 = var1.elementAt(var2--);
         if (var3 != null) {
            this.addChildElement(var3);
         }
      }
   }

   public void addChildElement(Object var1) {
      Debug.dAssert(var1 != null);
      this.roots.addElement(var1);
   }
}
