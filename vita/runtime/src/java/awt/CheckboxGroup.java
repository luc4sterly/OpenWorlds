package java.awt;

/** Radio buttons, as java.awt.CheckboxGroup. */
public class CheckboxGroup implements java.io.Serializable {
   Checkbox selectedCheckbox;

   public CheckboxGroup() {
   }

   public Checkbox getSelectedCheckbox() {
      return getCurrent();
   }

   public Checkbox getCurrent() {
      return selectedCheckbox;
   }

   public void setSelectedCheckbox(Checkbox box) {
      setCurrent(box);
   }

   public synchronized void setCurrent(Checkbox box) {
      if (box != null && box.group != this) {
         return;
      }
      Checkbox old = selectedCheckbox;
      selectedCheckbox = box;
      if (old != null && old != box && old.group == this) {
         old.setStateInternal(false);
      }
      if (box != null && old != box && !box.getState()) {
         box.setStateInternal(true);
      }
   }

   void setCurrentInternal(Checkbox box) {
      setCurrent(box);
   }

   public String toString() {
      return getClass().getName() + "[selectedCheckbox=" + selectedCheckbox + "]";
   }
}
