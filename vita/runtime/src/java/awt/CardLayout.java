package java.awt;

import java.util.Enumeration;
import java.util.Hashtable;

/** One component shown at a time, picked by name, as JDK 1.4's java.awt.CardLayout. */
public class CardLayout implements LayoutManager2, java.io.Serializable {
   Hashtable<String, Component> tab = new Hashtable<String, Component>();
   int hgap;
   int vgap;

   public CardLayout() {
      this(0, 0);
   }

   public CardLayout(int hgap, int vgap) {
      this.hgap = hgap;
      this.vgap = vgap;
   }

   public int getHgap() {
      return hgap;
   }

   public void setHgap(int hgap) {
      this.hgap = hgap;
   }

   public int getVgap() {
      return vgap;
   }

   public void setVgap(int vgap) {
      this.vgap = vgap;
   }

   public void addLayoutComponent(Component comp, Object constraints) {
      synchronized (comp.getTreeLock()) {
         if (constraints instanceof String) {
            addLayoutComponent((String) constraints, comp);
         } else {
            throw new IllegalArgumentException("cannot add to layout: constraint must be a string");
         }
      }
   }

   /** @deprecated */
   @Deprecated
   public void addLayoutComponent(String name, Component comp) {
      synchronized (comp.getTreeLock()) {
         if (!tab.isEmpty()) {
            comp.setVisible(false);
         }
         tab.put(name, comp);
      }
   }

   public void removeLayoutComponent(Component comp) {
      synchronized (comp.getTreeLock()) {
         for (Enumeration<String> e = tab.keys(); e.hasMoreElements();) {
            String key = e.nextElement();
            if (tab.get(key) == comp) {
               tab.remove(key);
               return;
            }
         }
      }
   }

   public Dimension preferredLayoutSize(Container parent) {
      synchronized (parent.getTreeLock()) {
         return size(parent, true);
      }
   }

   public Dimension minimumLayoutSize(Container parent) {
      synchronized (parent.getTreeLock()) {
         return size(parent, false);
      }
   }

   private Dimension size(Container parent, boolean preferred) {
      Insets insets = parent.getInsets();
      int ncomponents = parent.getComponentCount();
      int w = 0;
      int h = 0;
      for (int i = 0; i < ncomponents; i++) {
         Component comp = parent.getComponent(i);
         Dimension d = preferred ? comp.getPreferredSize() : comp.getMinimumSize();
         if (d.width > w) {
            w = d.width;
         }
         if (d.height > h) {
            h = d.height;
         }
      }
      return new Dimension(insets.left + insets.right + w + hgap * 2, insets.top + insets.bottom + h + vgap * 2);
   }

   public Dimension maximumLayoutSize(Container target) {
      return new Dimension(Integer.MAX_VALUE, Integer.MAX_VALUE);
   }

   public float getLayoutAlignmentX(Container parent) {
      return 0.5f;
   }

   public float getLayoutAlignmentY(Container parent) {
      return 0.5f;
   }

   public void invalidateLayout(Container target) {
   }

   public void layoutContainer(Container parent) {
      synchronized (parent.getTreeLock()) {
         Insets insets = parent.getInsets();
         int ncomponents = parent.getComponentCount();
         boolean currentFound = false;
         for (int i = 0; i < ncomponents; i++) {
            Component comp = parent.getComponent(i);
            comp.setBounds(hgap + insets.left, vgap + insets.top, parent.width - (hgap * 2 + insets.left + insets.right),
                  parent.height - (vgap * 2 + insets.top + insets.bottom));
            if (comp.visible) {
               currentFound = true;
            }
         }
         if (!currentFound && ncomponents > 0) {
            parent.getComponent(0).setVisible(true);
         }
      }
   }

   void checkLayout(Container parent) {
      if (parent.getLayout() != this) {
         throw new IllegalArgumentException("wrong parent for CardLayout");
      }
   }

   public void first(Container parent) {
      synchronized (parent.getTreeLock()) {
         checkLayout(parent);
         int ncomponents = parent.getComponentCount();
         for (int i = 0; i < ncomponents; i++) {
            Component comp = parent.getComponent(i);
            if (comp.visible) {
               comp.setVisible(false);
               break;
            }
         }
         if (ncomponents > 0) {
            parent.getComponent(0).setVisible(true);
            parent.validate();
         }
      }
   }

   public void next(Container parent) {
      synchronized (parent.getTreeLock()) {
         checkLayout(parent);
         int ncomponents = parent.getComponentCount();
         for (int i = 0; i < ncomponents; i++) {
            Component comp = parent.getComponent(i);
            if (comp.visible) {
               comp.setVisible(false);
               comp = parent.getComponent((i + 1 < ncomponents) ? i + 1 : 0);
               comp.setVisible(true);
               parent.validate();
               return;
            }
         }
      }
   }

   public void previous(Container parent) {
      synchronized (parent.getTreeLock()) {
         checkLayout(parent);
         int ncomponents = parent.getComponentCount();
         for (int i = 0; i < ncomponents; i++) {
            Component comp = parent.getComponent(i);
            if (comp.visible) {
               comp.setVisible(false);
               comp = parent.getComponent((i > 0) ? i - 1 : ncomponents - 1);
               comp.setVisible(true);
               parent.validate();
               return;
            }
         }
      }
   }

   public void last(Container parent) {
      synchronized (parent.getTreeLock()) {
         checkLayout(parent);
         int ncomponents = parent.getComponentCount();
         for (int i = 0; i < ncomponents; i++) {
            Component comp = parent.getComponent(i);
            if (comp.visible) {
               comp.setVisible(false);
               break;
            }
         }
         if (ncomponents > 0) {
            parent.getComponent(ncomponents - 1).setVisible(true);
            parent.validate();
         }
      }
   }

   public void show(Container parent, String name) {
      synchronized (parent.getTreeLock()) {
         checkLayout(parent);
         Component next = tab.get(name);
         if ((next != null) && !next.visible) {
            int ncomponents = parent.getComponentCount();
            for (int i = 0; i < ncomponents; i++) {
               Component comp = parent.getComponent(i);
               if (comp.visible) {
                  comp.setVisible(false);
                  break;
               }
            }
            next.setVisible(true);
            parent.validate();
         }
      }
   }

   public String toString() {
      return getClass().getName() + "[hgap=" + hgap + ",vgap=" + vgap + "]";
   }
}
