package NET.worlds.scape;

import java.io.IOException;
import java.util.Enumeration;
import java.util.Vector;

public class DPState extends SuperRoot {
   public static final int INFINITY = 60000;
   protected Vector connections = new Vector();
   protected int currentDist = 60000;
   protected long currentTime = 0L;
   private static Object classCookie = new Object();

   public DPState(int var1, DPAction var2) {
      this.currentDist = var1;
      this.currentTime = 0L;
      this.addConnection(var2);
   }

   public DPState() {
   }

   public void setDist(int var1, int var2) {
      if (this.currentTime <= var2) {
         if (this.currentDist > var1 || this.currentTime != var2) {
            this.currentDist = var1;
            this.currentTime = var2;
            Enumeration var3 = this.connections.elements();

            while (var3.hasMoreElements()) {
               ((DPAction)var3.nextElement()).handleDist(var1, var2);
            }
         }
      }
   }

   public int getDist() {
      return this.currentDist;
   }

   public Enumeration getConnections() {
      return this.connections.elements();
   }

   public Enumeration getPortals() {
      Vector var1 = new Vector(this.connections.size());
      Enumeration var2 = this.connections.elements();

      while (var2.hasMoreElements()) {
         var1.addElement(((DPAction)var2.nextElement()).getOwner());
      }

      return var1.elements();
   }

   public void addConnection(DPAction var1) {
      if (!this.connections.contains(var1)) {
         this.connections.addElement(var1);
      }
   }

   public void dropConnection(DPAction var1) {
      this.connections.removeElement(var1);
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Current Distance"));
            } else if (var3 == 1) {
               var5 = new Integer(this.currentDist);
            } else if (var3 == 2) {
               this.currentDist = (Integer)var4;
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = new VectorProperty(this, var1, "Connections");
            } else if (var3 == 1) {
               var5 = this.connections.clone();
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 2, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
      var1.saveVector(this.connections);
      var1.saveInt(this.currentDist);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.connections = var1.restoreVector();
            this.currentDist = var1.restoreInt();
            return;
         default:
            throw new TooNewException();
      }
   }

   public String toString() {
      return super.getName();
   }
}
