package NET.worlds.console;

import java.awt.FlowLayout;
import java.awt.Frame;

public class MapFrame extends Frame {
   MapTile mp;

   public MapFrame() {
      super(Console.message("Map-Tile"));
      this.setLayout(new FlowLayout());
      this.mp = new MapTile();
      this.add(this.mp);
      this.resize(325, 300);
      this.validate();
      this.show();
   }
}
