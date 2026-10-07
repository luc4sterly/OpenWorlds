package java.awt;

/** A plain container, as java.awt.Panel (FlowLayout by default). */
public class Panel extends Container {
   public Panel() {
      this(new FlowLayout());
   }

   public Panel(LayoutManager layout) {
      setLayout(layout);
   }

   public void addNotify() {
      synchronized (LOCK) {
         super.addNotify();
      }
   }
}
