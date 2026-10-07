package java.awt;

import java.awt.event.KeyEvent;

/** A menu item's keyboard accelerator (with Ctrl, and maybe Shift), as java.awt.MenuShortcut. */
public class MenuShortcut implements java.io.Serializable {
   int key;
   boolean usesShift;

   public MenuShortcut(int key) {
      this(key, false);
   }

   public MenuShortcut(int key, boolean useShiftModifier) {
      this.key = key;
      this.usesShift = useShiftModifier;
   }

   public int getKey() {
      return key;
   }

   public boolean usesShiftModifier() {
      return usesShift;
   }

   public boolean equals(MenuShortcut s) {
      return s != null && s.getKey() == key && s.usesShiftModifier() == usesShift;
   }

   public boolean equals(Object obj) {
      if (obj instanceof MenuShortcut) {
         return equals((MenuShortcut) obj);
      }
      return false;
   }

   public int hashCode() {
      return usesShift ? ~key : key;
   }

   /** "Ctrl+X" or "Ctrl+Shift+X", as the Windows peer showed it next to the item. */
   public String toString() {
      int modifiers = Toolkit.getDefaultToolkit().getMenuShortcutKeyMask();
      if (usesShift) {
         modifiers |= java.awt.event.InputEvent.SHIFT_MASK;
      }
      return KeyEvent.getKeyModifiersText(modifiers) + "+" + KeyEvent.getKeyText(key);
   }

   protected String paramString() {
      String str = "key=" + key;
      if (usesShift) {
         str += ",usesShiftModifier";
      }
      return str;
   }
}
