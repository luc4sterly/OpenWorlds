package NET.worlds.scape;

import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.Vector;

public class Manifest {
   private IndentStream _out;
   private Hashtable _ht = new Hashtable();
   private int _lastID = 0;

   public Manifest(IndentStream var1) {
      this._out = var1;
      this._out.println("MANIFEST Worlds, Inc.");
      this._out.indent();
   }

   public Manifest(String var1) throws IOException {
      this(new IndentStream(new FileOutputStream(var1)));
   }

   public void done() {
      this._out.undent();
      this._out.println("END MANIFEST");
      this._out.close();
      this._out = null;
      this._ht = null;
   }

   private void printID(String var1) {
      this._out.print(" (#" + var1 + ")");
   }

   private void printRef(Object var1) {
      if (var1 instanceof SuperRoot) {
         this._out.print(((SuperRoot)var1).getName());
      } else {
         this._out.print("<anonymous>");
      }

      if (this._ht.containsKey(var1)) {
         this.printID((String)this._ht.get(var1));
         this._out.println(" --q.v.--");
      } else {
         String var2 = Integer.toString(this._lastID++);
         this._ht.put(var1, var2);
         this.printID(var2);
         this._out.println(":" + var1.getClass().getName() + " [");
         this._out.indent();
         this.saveProps((Properties)var1);
         this._out.undent();
         this._out.println("]");
      }
   }

   private void saveMaybeProp(Object var1) {
      if (var1 instanceof Properties && !var1.getClass().getName().equals("NET.worlds.scape.Transform")) {
         this.printRef(var1);
      } else {
         this._out.println(var1);
      }
   }

   public void saveProps(Properties var1) {
      EnumProperties var2 = new EnumProperties(var1);

      while (var2.hasMoreElements()) {
         Property var3 = (Property)var2.nextElement();
         this._out.print(var3.getName());
         this._out.print(" := ");
         if (var3 instanceof VectorProperty) {
            this._out.println("{");
            this._out.indent();
            Vector var4 = (Vector)var3.get();
            if (var4 != null) {
               Enumeration var5 = var4.elements();

               while (var5.hasMoreElements()) {
                  this.saveMaybeProp(var5.nextElement());
               }
            }

            this._out.undent();
            this._out.println("}");
         } else {
            this.saveMaybeProp(var3.get());
         }
      }
   }
}
