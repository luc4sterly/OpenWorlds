package java.awt.event;

import java.awt.Component;
import java.awt.Container;

public class ContainerEvent extends ComponentEvent {
   public static final int CONTAINER_FIRST = 300;
   public static final int CONTAINER_LAST = 301;
   public static final int COMPONENT_ADDED = CONTAINER_FIRST;
   public static final int COMPONENT_REMOVED = 1 + CONTAINER_FIRST;

   Component child;

   public ContainerEvent(Component source, int id, Component child) {
      super(source, id);
      this.child = child;
   }

   public Container getContainer() {
      return (source instanceof Container) ? (Container) source : null;
   }

   public Component getChild() {
      return child;
   }
}
