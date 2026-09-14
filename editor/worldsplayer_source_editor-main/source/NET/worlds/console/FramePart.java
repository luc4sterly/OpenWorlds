package NET.worlds.console;

import NET.worlds.scape.FrameEvent;
import java.awt.Container;
import java.awt.Event;

public interface FramePart {
   void activate(Console var1, Container var2, Console var3);

   void deactivate();

   boolean action(Event var1, Object var2);

   boolean handle(FrameEvent var1);
}
