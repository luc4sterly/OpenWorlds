package java.util;

/** The root of every event, as java.util.EventObject (AWTEvent extends it). */
public class EventObject implements java.io.Serializable {
   protected transient Object source;

   public EventObject(Object source) {
      if (source == null) {
         throw new IllegalArgumentException("null source");
      }
      this.source = source;
   }

   public Object getSource() {
      return source;
   }

   public String toString() {
      return getClass().getName() + "[source=" + source + "]";
   }
}
