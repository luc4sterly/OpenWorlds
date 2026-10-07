package java.awt;

import java.awt.event.AdjustmentEvent;
import java.awt.event.AdjustmentListener;

/** One of a ScrollPane's two scroll bars, as java.awt.ScrollPaneAdjustable (unit increment 1, as the JDK's). */
public class ScrollPaneAdjustable implements Adjustable, java.io.Serializable {
   private final ScrollPane sp;
   private final int orientation;
   private int value;
   private int minimum;
   private int maximum;
   private int visibleAmount;
   private transient boolean isAdjusting;
   private int unitIncrement = 1;
   private int blockIncrement = 1;
   private transient AdjustmentListener adjustmentListener;

   ScrollPaneAdjustable(ScrollPane sp, int orientation) {
      this.sp = sp;
      this.orientation = orientation;
   }

   /** The ScrollPane sets these from its layout (setSpan in the JDK). */
   void setSpan(int min, int max, int visible) {
      minimum = min;
      maximum = Math.max(max, minimum + 1);
      visibleAmount = Math.min(visible, maximum - minimum);
      visibleAmount = Math.max(visibleAmount, 1);
      blockIncrement = Math.max((int) (visible * .90), 1);
      setValue(value);
   }

   public int getOrientation() {
      return orientation;
   }

   public void setMinimum(int min) {
      throw new AWTError("can be set only by scrollpane");
   }

   public int getMinimum() {
      return 0;
   }

   public void setMaximum(int max) {
      throw new AWTError("can be set only by scrollpane");
   }

   public int getMaximum() {
      return maximum;
   }

   public synchronized void setUnitIncrement(int u) {
      if (u != unitIncrement) {
         unitIncrement = u;
      }
   }

   public int getUnitIncrement() {
      return unitIncrement;
   }

   public synchronized void setBlockIncrement(int b) {
      blockIncrement = b;
   }

   public int getBlockIncrement() {
      return blockIncrement;
   }

   public void setVisibleAmount(int v) {
      throw new AWTError("can be set only by scrollpane");
   }

   public int getVisibleAmount() {
      return visibleAmount;
   }

   public void setValueIsAdjusting(boolean b) {
      isAdjusting = b;
   }

   public boolean getValueIsAdjusting() {
      return isAdjusting;
   }

   public void setValue(int v) {
      setTypedValue(v, AdjustmentEvent.TRACK);
   }

   /** Clamps, and if it changed tells the listeners and moves the ScrollPane's child (the JDK's PeerFixer). */
   void setTypedValue(int v, int type) {
      v = Math.max(v, minimum);
      v = Math.min(v, maximum - visibleAmount);
      if (v != value) {
         value = v;
         sp.adjustableMoved(this, value);
         AdjustmentListener l = adjustmentListener;
         if (l != null) {
            l.adjustmentValueChanged(new AdjustmentEvent(this, AdjustmentEvent.ADJUSTMENT_VALUE_CHANGED, type, value, isAdjusting));
         }
      }
   }

   public int getValue() {
      return value;
   }

   public synchronized void addAdjustmentListener(AdjustmentListener l) {
      if (l == null) {
         return;
      }
      adjustmentListener = AWTEventMulticaster.add(adjustmentListener, l);
   }

   public synchronized void removeAdjustmentListener(AdjustmentListener l) {
      if (l == null) {
         return;
      }
      adjustmentListener = AWTEventMulticaster.remove(adjustmentListener, l);
   }

   public String toString() {
      return getClass().getName() + "[" + paramString() + "]";
   }

   public String paramString() {
      return (orientation == Adjustable.VERTICAL ? "vertical," : "horizontal,") + "[0.." + maximum + "]" + ",val=" + value
            + ",vis=" + visibleAmount + ",unit=" + unitIncrement + ",block=" + blockIncrement + ",isAdjusting=" + isAdjusting;
   }
}
