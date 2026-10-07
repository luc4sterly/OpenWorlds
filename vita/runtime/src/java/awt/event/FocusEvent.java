package java.awt.event;

import java.awt.Component;

public class FocusEvent extends ComponentEvent {
   public static final int FOCUS_FIRST = 1004;
   public static final int FOCUS_LAST = 1005;
   public static final int FOCUS_GAINED = FOCUS_FIRST;
   public static final int FOCUS_LOST = 1 + FOCUS_FIRST;

   boolean temporary;
   transient Component opposite;

   public FocusEvent(Component source, int id, boolean temporary, Component opposite) {
      super(source, id);
      this.temporary = temporary;
      this.opposite = opposite;
   }

   public FocusEvent(Component source, int id, boolean temporary) {
      this(source, id, temporary, null);
   }

   public FocusEvent(Component source, int id) {
      this(source, id, false);
   }

   public boolean isTemporary() {
      return temporary;
   }

   public Component getOppositeComponent() {
      return opposite;
   }

   public String paramString() {
      return (id == FOCUS_GAINED ? "FOCUS_GAINED" : id == FOCUS_LOST ? "FOCUS_LOST" : "unknown type")
            + (temporary ? ",temporary" : ",permanent") + ",opposite=" + opposite;
   }
}
