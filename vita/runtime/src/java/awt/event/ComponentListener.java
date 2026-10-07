package java.awt.event;

import java.util.EventListener;

public interface ComponentListener extends EventListener {
   void componentResized(ComponentEvent e);

   void componentMoved(ComponentEvent e);

   void componentShown(ComponentEvent e);

   void componentHidden(ComponentEvent e);
}
