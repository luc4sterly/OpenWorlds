package java.awt.event;

import java.awt.AWTEvent;
import java.awt.Component;

/** Present for InputMethodListener's signature; the Vita's IME delivers plain key events instead. */
public class InputMethodEvent extends AWTEvent {
   public static final int INPUT_METHOD_FIRST = 1100;
   public static final int INPUT_METHOD_TEXT_CHANGED = INPUT_METHOD_FIRST;
   public static final int CARET_POSITION_CHANGED = INPUT_METHOD_FIRST + 1;
   public static final int INPUT_METHOD_LAST = INPUT_METHOD_FIRST + 1;

   public InputMethodEvent(Component source, int id) {
      super(source, id);
   }
}
