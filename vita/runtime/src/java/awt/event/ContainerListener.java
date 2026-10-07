package java.awt.event;

import java.util.EventListener;

public interface ContainerListener extends EventListener {
   void componentAdded(ContainerEvent e);

   void componentRemoved(ContainerEvent e);
}
