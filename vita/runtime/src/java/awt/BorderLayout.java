package java.awt;

/** North, south, east, west and center, as JDK 1.4's java.awt.BorderLayout. */
public class BorderLayout implements LayoutManager2, java.io.Serializable {
   int hgap;
   int vgap;
   Component north;
   Component west;
   Component east;
   Component south;
   Component center;
   Component firstLine;
   Component lastLine;
   Component firstItem;
   Component lastItem;

   public static final String NORTH = "North";
   public static final String SOUTH = "South";
   public static final String EAST = "East";
   public static final String WEST = "West";
   public static final String CENTER = "Center";
   public static final String BEFORE_FIRST_LINE = "First";
   public static final String AFTER_LAST_LINE = "Last";
   public static final String BEFORE_LINE_BEGINS = "Before";
   public static final String AFTER_LINE_ENDS = "After";
   public static final String PAGE_START = BEFORE_FIRST_LINE;
   public static final String PAGE_END = AFTER_LAST_LINE;
   public static final String LINE_START = BEFORE_LINE_BEGINS;
   public static final String LINE_END = AFTER_LINE_ENDS;

   public BorderLayout() {
      this(0, 0);
   }

   public BorderLayout(int hgap, int vgap) {
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
         if ((constraints == null) || (constraints instanceof String)) {
            addLayoutComponent((String) constraints, comp);
         } else {
            throw new IllegalArgumentException("cannot add to layout: constraint must be a string (or null)");
         }
      }
   }

   /** @deprecated */
   @Deprecated
   public void addLayoutComponent(String name, Component comp) {
      synchronized (comp.getTreeLock()) {
         if (name == null) {
            name = "Center";
         }
         if ("Center".equals(name)) {
            center = comp;
         } else if ("North".equals(name)) {
            north = comp;
         } else if ("South".equals(name)) {
            south = comp;
         } else if ("East".equals(name)) {
            east = comp;
         } else if ("West".equals(name)) {
            west = comp;
         } else if (BEFORE_FIRST_LINE.equals(name)) {
            firstLine = comp;
         } else if (AFTER_LAST_LINE.equals(name)) {
            lastLine = comp;
         } else if (BEFORE_LINE_BEGINS.equals(name)) {
            firstItem = comp;
         } else if (AFTER_LINE_ENDS.equals(name)) {
            lastItem = comp;
         } else {
            throw new IllegalArgumentException("cannot add to layout: unknown constraint: " + name);
         }
      }
   }

   public void removeLayoutComponent(Component comp) {
      synchronized (comp.getTreeLock()) {
         if (comp == center) {
            center = null;
         } else if (comp == north) {
            north = null;
         } else if (comp == south) {
            south = null;
         } else if (comp == east) {
            east = null;
         } else if (comp == west) {
            west = null;
         }
         if (comp == firstLine) {
            firstLine = null;
         } else if (comp == lastLine) {
            lastLine = null;
         } else if (comp == firstItem) {
            firstItem = null;
         } else if (comp == lastItem) {
            lastItem = null;
         }
      }
   }

   public Dimension minimumLayoutSize(Container target) {
      synchronized (target.getTreeLock()) {
         return size(target, false);
      }
   }

   public Dimension preferredLayoutSize(Container target) {
      synchronized (target.getTreeLock()) {
         return size(target, true);
      }
   }

   private Dimension size(Container target, boolean preferred) {
      Dimension dim = new Dimension(0, 0);
      boolean ltr = target.getComponentOrientation().isLeftToRight();
      Component c;
      if ((c = getChild(EAST, ltr)) != null) {
         Dimension d = preferred ? c.getPreferredSize() : c.getMinimumSize();
         dim.width += d.width + hgap;
         dim.height = Math.max(d.height, dim.height);
      }
      if ((c = getChild(WEST, ltr)) != null) {
         Dimension d = preferred ? c.getPreferredSize() : c.getMinimumSize();
         dim.width += d.width + hgap;
         dim.height = Math.max(d.height, dim.height);
      }
      if ((c = getChild(CENTER, ltr)) != null) {
         Dimension d = preferred ? c.getPreferredSize() : c.getMinimumSize();
         dim.width += d.width;
         dim.height = Math.max(d.height, dim.height);
      }
      if ((c = getChild(NORTH, ltr)) != null) {
         Dimension d = preferred ? c.getPreferredSize() : c.getMinimumSize();
         dim.width = Math.max(d.width, dim.width);
         dim.height += d.height + vgap;
      }
      if ((c = getChild(SOUTH, ltr)) != null) {
         Dimension d = preferred ? c.getPreferredSize() : c.getMinimumSize();
         dim.width = Math.max(d.width, dim.width);
         dim.height += d.height + vgap;
      }
      Insets insets = target.getInsets();
      dim.width += insets.left + insets.right;
      dim.height += insets.top + insets.bottom;
      return dim;
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

   public void layoutContainer(Container target) {
      synchronized (target.getTreeLock()) {
         Insets insets = target.getInsets();
         int top = insets.top;
         int bottom = target.height - insets.bottom;
         int left = insets.left;
         int right = target.width - insets.right;
         boolean ltr = target.getComponentOrientation().isLeftToRight();
         Component c;
         if ((c = getChild(NORTH, ltr)) != null) {
            c.setSize(right - left, c.height);
            Dimension d = c.getPreferredSize();
            c.setBounds(left, top, right - left, d.height);
            top += d.height + vgap;
         }
         if ((c = getChild(SOUTH, ltr)) != null) {
            c.setSize(right - left, c.height);
            Dimension d = c.getPreferredSize();
            c.setBounds(left, bottom - d.height, right - left, d.height);
            bottom -= d.height + vgap;
         }
         if ((c = getChild(EAST, ltr)) != null) {
            c.setSize(c.width, bottom - top);
            Dimension d = c.getPreferredSize();
            c.setBounds(right - d.width, top, d.width, bottom - top);
            right -= d.width + hgap;
         }
         if ((c = getChild(WEST, ltr)) != null) {
            c.setSize(c.width, bottom - top);
            Dimension d = c.getPreferredSize();
            c.setBounds(left, top, d.width, bottom - top);
            left += d.width + hgap;
         }
         if ((c = getChild(CENTER, ltr)) != null) {
            c.setBounds(left, top, right - left, bottom - top);
         }
      }
   }

   private Component getChild(String key, boolean ltr) {
      Component result = null;
      if (key == NORTH) {
         result = (firstLine != null) ? firstLine : north;
      } else if (key == SOUTH) {
         result = (lastLine != null) ? lastLine : south;
      } else if (key == WEST) {
         result = ltr ? firstItem : lastItem;
         if (result == null) {
            result = west;
         }
      } else if (key == EAST) {
         result = ltr ? lastItem : firstItem;
         if (result == null) {
            result = east;
         }
      } else if (key == CENTER) {
         result = center;
      }
      if (result != null && !result.visible) {
         result = null;
      }
      return result;
   }

   public String toString() {
      return getClass().getName() + "[hgap=" + hgap + ",vgap=" + vgap + "]";
   }
}
