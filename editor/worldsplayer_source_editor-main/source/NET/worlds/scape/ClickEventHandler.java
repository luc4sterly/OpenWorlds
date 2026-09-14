package NET.worlds.scape;

import java.awt.Component;
import java.awt.Point;

public interface ClickEventHandler {
   int DOWN = 1;
   int UP = 2;
   int META = 4;
   int DRAG = 8;

   void clickEvent(Component var1, Point var2, int var3);
}
