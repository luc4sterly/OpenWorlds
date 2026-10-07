package java.awt.event;

import java.awt.AWTEvent;
import java.awt.Component;

public class ComponentEvent extends AWTEvent {
   public static final int COMPONENT_FIRST = 100;
   public static final int COMPONENT_LAST = 103;
   public static final int COMPONENT_MOVED = COMPONENT_FIRST;
   public static final int COMPONENT_RESIZED = 1 + COMPONENT_FIRST;
   public static final int COMPONENT_SHOWN = 2 + COMPONENT_FIRST;
   public static final int COMPONENT_HIDDEN = 3 + COMPONENT_FIRST;

   public ComponentEvent(Component source, int id) {
      super(source, id);
   }

   public Component getComponent() {
      return (source instanceof Component) ? (Component) source : null;
   }

   public String paramString() {
      switch (id) {
         case COMPONENT_SHOWN:
            return "COMPONENT_SHOWN";
         case COMPONENT_HIDDEN:
            return "COMPONENT_HIDDEN";
         case COMPONENT_MOVED:
            return "COMPONENT_MOVED";
         case COMPONENT_RESIZED:
            return "COMPONENT_RESIZED";
         default:
            return "unknown type";
      }
   }
}
