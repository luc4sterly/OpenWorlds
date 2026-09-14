package NET.worlds.scape;

import NET.worlds.network.URL;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.net.MalformedURLException;
import java.util.Hashtable;

public class WorldRedirector {
   private Hashtable _ht = new Hashtable();

   public WorldRedirector() {
   }

   public WorldRedirector(URL var1) {
      try {
         BufferedReader var2 = new BufferedReader(new FileReader(var1.unalias()));
         this.addFile(var2);
      } catch (IOException var3) {
         System.out.println("Reading " + var1 + " got " + var3);
      }
   }

   void addFile(BufferedReader var1) throws IOException {
      String var2;
      while ((var2 = var1.readLine()) != null) {
         this.addLine(var2);
      }
   }

   void addLine(String var1) {
      if (!var1.startsWith("#")) {
         int var2 = var1.indexOf("=>");
         if (var2 > 0) {
            String var3 = var1.substring(0, var2);
            String var4 = var1.substring(var2 + 2);
            this._ht.put(var3, var4);
         }
      }
   }

   public URL get(URL var1) {
      String var2 = var1.toString();
      String var3 = "";

      while (true) {
         Object var5 = this._ht.get(var2);
         if (var5 != null) {
            try {
               URL var6;
               if (var3 == "") {
                  var6 = new URL((String)var5);
               } else {
                  var6 = new URL((String)var5 + "/" + var3);
               }

               System.out.println("Redirecting " + var1 + " => " + var6);
               return var6;
            } catch (MalformedURLException var7) {
               System.out.println("Failed: " + var7);
            }
         }

         int var4 = var2.lastIndexOf(47);
         if (var4 == -1) {
            return var1;
         }

         if (var3 == "") {
            var3 = var2.substring(var4 + 1);
         } else {
            var3 = var2.substring(var4 + 1) + "/" + var3;
         }

         var2 = var2.substring(0, var4);
      }
   }
}
