package java.awt.event;

import java.awt.AWTEvent;

public class TextEvent extends AWTEvent {
   public static final int TEXT_FIRST = 900;
   public static final int TEXT_LAST = 900;
   public static final int TEXT_VALUE_CHANGED = TEXT_FIRST;

   public TextEvent(Object source, int id) {
      super(source, id);
   }

   public String paramString() {
      return id == TEXT_VALUE_CHANGED ? "TEXT_VALUE_CHANGED" : "unknown type";
   }
}
