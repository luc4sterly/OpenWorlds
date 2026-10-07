package java.awt.event;

import java.awt.AWTEvent;

public class ActionEvent extends AWTEvent {
   public static final int SHIFT_MASK = java.awt.Event.SHIFT_MASK;
   public static final int CTRL_MASK = java.awt.Event.CTRL_MASK;
   public static final int META_MASK = java.awt.Event.META_MASK;
   public static final int ALT_MASK = java.awt.Event.ALT_MASK;
   public static final int ACTION_FIRST = 1001;
   public static final int ACTION_LAST = 1001;
   public static final int ACTION_PERFORMED = ACTION_FIRST;

   String actionCommand;
   long when;
   int modifiers;

   public ActionEvent(Object source, int id, String command) {
      this(source, id, command, 0);
   }

   public ActionEvent(Object source, int id, String command, int modifiers) {
      this(source, id, command, System.currentTimeMillis(), modifiers);
   }

   public ActionEvent(Object source, int id, String command, long when, int modifiers) {
      super(source, id);
      this.actionCommand = command;
      this.when = when;
      this.modifiers = modifiers;
   }

   public String getActionCommand() {
      return actionCommand;
   }

   public long getWhen() {
      return when;
   }

   public int getModifiers() {
      return modifiers;
   }

   public String paramString() {
      return (id == ACTION_PERFORMED ? "ACTION_PERFORMED" : "unknown type") + ",cmd=" + actionCommand + ",when=" + when + ",modifiers=" + modifiers;
   }
}
