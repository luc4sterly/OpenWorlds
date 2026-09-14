package NET.worlds.scape;

import NET.worlds.network.URL;
import java.awt.Component;
import java.awt.Point;

class DropInfo {
   public URL url;
   public String propertyName;
   public Component comp;
   public Point location;

   DropInfo(URL var1, String var2, Component var3, Point var4) {
      this.url = var1;
      this.propertyName = var2;
      this.comp = var3;
      this.location = var4;
   }
}
