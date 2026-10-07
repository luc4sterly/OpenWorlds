package java.awt.event;

import java.awt.AWTEvent;
import java.awt.Adjustable;

public class AdjustmentEvent extends AWTEvent {
   public static final int ADJUSTMENT_FIRST = 601;
   public static final int ADJUSTMENT_LAST = 601;
   public static final int ADJUSTMENT_VALUE_CHANGED = ADJUSTMENT_FIRST;
   public static final int UNIT_INCREMENT = 1;
   public static final int UNIT_DECREMENT = 2;
   public static final int BLOCK_DECREMENT = 3;
   public static final int BLOCK_INCREMENT = 4;
   public static final int TRACK = 5;

   Adjustable adjustable;
   int value;
   int adjustmentType;
   boolean isAdjusting;

   public AdjustmentEvent(Adjustable source, int id, int type, int value) {
      this(source, id, type, value, false);
   }

   public AdjustmentEvent(Adjustable source, int id, int type, int value, boolean isAdjusting) {
      super(source, id);
      this.adjustable = source;
      this.adjustmentType = type;
      this.value = value;
      this.isAdjusting = isAdjusting;
   }

   public Adjustable getAdjustable() {
      return adjustable;
   }

   public int getValue() {
      return value;
   }

   public int getAdjustmentType() {
      return adjustmentType;
   }

   public boolean getValueIsAdjusting() {
      return isAdjusting;
   }
}
