package java.awt.event;

import java.awt.Component;

/** Keys and mouse buttons held, in both the JDK 1.3 masks and the "extended" ones, kept in step as the JDK does. */
public abstract class InputEvent extends ComponentEvent {
   public static final int SHIFT_MASK = 1 << 0;
   public static final int CTRL_MASK = 1 << 1;
   public static final int META_MASK = 1 << 2;
   public static final int ALT_MASK = 1 << 3;
   public static final int ALT_GRAPH_MASK = 1 << 5;
   public static final int BUTTON1_MASK = 1 << 4;
   public static final int BUTTON2_MASK = ALT_MASK;
   public static final int BUTTON3_MASK = META_MASK;
   public static final int SHIFT_DOWN_MASK = 1 << 6;
   public static final int CTRL_DOWN_MASK = 1 << 7;
   public static final int META_DOWN_MASK = 1 << 8;
   public static final int ALT_DOWN_MASK = 1 << 9;
   public static final int BUTTON1_DOWN_MASK = 1 << 10;
   public static final int BUTTON2_DOWN_MASK = 1 << 11;
   public static final int BUTTON3_DOWN_MASK = 1 << 12;
   public static final int ALT_GRAPH_DOWN_MASK = 1 << 13;

   static final int JDK_1_3_MODIFIERS = SHIFT_DOWN_MASK - 1;

   long when;
   int modifiers;

   InputEvent(Component source, int id, long when, int modifiers) {
      super(source, id);
      this.when = when;
      this.modifiers = modifiers;
   }

   public boolean isShiftDown() {
      return (modifiers & SHIFT_MASK) != 0;
   }

   public boolean isControlDown() {
      return (modifiers & CTRL_MASK) != 0;
   }

   public boolean isMetaDown() {
      return (modifiers & META_MASK) != 0;
   }

   public boolean isAltDown() {
      return (modifiers & ALT_MASK) != 0;
   }

   public boolean isAltGraphDown() {
      return (modifiers & ALT_GRAPH_MASK) != 0;
   }

   public long getWhen() {
      return when;
   }

   public int getModifiers() {
      return modifiers & JDK_1_3_MODIFIERS;
   }

   public int getModifiersEx() {
      return modifiers & ~JDK_1_3_MODIFIERS;
   }

   public void consume() {
      consumed = true;
   }

   public boolean isConsumed() {
      return consumed;
   }

   /** The extended masks of the 1.3 ones. */
   void setNewModifiers() {
      if ((modifiers & BUTTON1_MASK) != 0) {
         modifiers |= BUTTON1_DOWN_MASK;
      }
      if ((modifiers & BUTTON2_MASK) != 0 && this instanceof MouseEvent) {
         modifiers |= BUTTON2_DOWN_MASK;
      }
      if ((modifiers & BUTTON3_MASK) != 0 && this instanceof MouseEvent) {
         modifiers |= BUTTON3_DOWN_MASK;
      }
      if ((modifiers & SHIFT_MASK) != 0) {
         modifiers |= SHIFT_DOWN_MASK;
      }
      if ((modifiers & CTRL_MASK) != 0) {
         modifiers |= CTRL_DOWN_MASK;
      }
      if ((modifiers & META_MASK) != 0) {
         modifiers |= META_DOWN_MASK;
      }
      if ((modifiers & ALT_MASK) != 0) {
         modifiers |= ALT_DOWN_MASK;
      }
      if ((modifiers & ALT_GRAPH_MASK) != 0) {
         modifiers |= ALT_GRAPH_DOWN_MASK;
      }
   }

   /** The 1.3 masks of the extended ones. */
   void setOldModifiers() {
      if ((modifiers & BUTTON1_DOWN_MASK) != 0) {
         modifiers |= BUTTON1_MASK;
      }
      if ((modifiers & BUTTON2_DOWN_MASK) != 0) {
         modifiers |= BUTTON2_MASK;
      }
      if ((modifiers & BUTTON3_DOWN_MASK) != 0) {
         modifiers |= BUTTON3_MASK;
      }
      if ((modifiers & SHIFT_DOWN_MASK) != 0) {
         modifiers |= SHIFT_MASK;
      }
      if ((modifiers & CTRL_DOWN_MASK) != 0) {
         modifiers |= CTRL_MASK;
      }
      if ((modifiers & META_DOWN_MASK) != 0) {
         modifiers |= META_MASK;
      }
      if ((modifiers & ALT_DOWN_MASK) != 0) {
         modifiers |= ALT_MASK;
      }
      if ((modifiers & ALT_GRAPH_DOWN_MASK) != 0) {
         modifiers |= ALT_GRAPH_MASK;
      }
   }

   void syncModifiers() {
      if (getModifiers() != 0 && getModifiersEx() == 0) {
         setNewModifiers();
      } else if (getModifiers() == 0 && getModifiersEx() != 0) {
         setOldModifiers();
      }
   }

   public static String getModifiersExText(int modifiers) {
      StringBuilder buf = new StringBuilder();
      if ((modifiers & META_DOWN_MASK) != 0) {
         buf.append("Meta+");
      }
      if ((modifiers & CTRL_DOWN_MASK) != 0) {
         buf.append("Ctrl+");
      }
      if ((modifiers & ALT_DOWN_MASK) != 0) {
         buf.append("Alt+");
      }
      if ((modifiers & SHIFT_DOWN_MASK) != 0) {
         buf.append("Shift+");
      }
      if ((modifiers & ALT_GRAPH_DOWN_MASK) != 0) {
         buf.append("Alt Graph+");
      }
      if ((modifiers & BUTTON1_DOWN_MASK) != 0) {
         buf.append("Button1+");
      }
      if ((modifiers & BUTTON2_DOWN_MASK) != 0) {
         buf.append("Button2+");
      }
      if ((modifiers & BUTTON3_DOWN_MASK) != 0) {
         buf.append("Button3+");
      }
      if (buf.length() > 0) {
         buf.setLength(buf.length() - 1);
      }
      return buf.toString();
   }
}
