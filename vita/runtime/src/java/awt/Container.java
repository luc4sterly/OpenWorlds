package java.awt;

import java.awt.event.ContainerEvent;
import java.awt.event.ContainerListener;
import java.util.ArrayList;

/** A component that holds others, as java.awt.Container. */
public class Container extends Component {
   final ArrayList<Component> component = new ArrayList<Component>();
   LayoutManager layoutMgr;
   transient ContainerListener containerListener;

   public Container() {
   }

   public int getComponentCount() {
      return countComponents();
   }

   public int countComponents() {
      synchronized (LOCK) {
         return component.size();
      }
   }

   public Component getComponent(int n) {
      synchronized (LOCK) {
         if (n < 0 || n >= component.size()) {
            throw new ArrayIndexOutOfBoundsException("No such child: " + n);
         }
         return component.get(n);
      }
   }

   public Component[] getComponents() {
      synchronized (LOCK) {
         return component.toArray(new Component[component.size()]);
      }
   }

   public Insets getInsets() {
      return insets();
   }

   public Insets insets() {
      return new Insets(0, 0, 0, 0);
   }

   public Component add(Component comp) {
      addImpl(comp, null, -1);
      return comp;
   }

   public Component add(String name, Component comp) {
      addImpl(comp, name, -1);
      return comp;
   }

   public Component add(Component comp, int index) {
      addImpl(comp, null, index);
      return comp;
   }

   public void add(Component comp, Object constraints) {
      addImpl(comp, constraints, -1);
   }

   public void add(Component comp, Object constraints, int index) {
      addImpl(comp, constraints, index);
   }

   protected void addImpl(Component comp, Object constraints, int index) {
      synchronized (LOCK) {
         if (index > component.size() || (index < 0 && index != -1)) {
            throw new IllegalArgumentException("illegal component position");
         }
         if (comp instanceof Container) {
            for (Container cn = this; cn != null; cn = cn.parent) {
               if (cn == comp) {
                  throw new IllegalArgumentException("adding container's parent to itself");
               }
            }
         }
         if (comp instanceof Window) {
            throw new IllegalArgumentException("adding a window to a container");
         }
         if (comp.parent != null) {
            comp.parent.remove(comp);
            if (index > component.size()) {
               throw new IllegalArgumentException("illegal component position");
            }
         }
         if (index == -1) {
            component.add(comp);
         } else {
            component.add(index, comp);
         }
         comp.parent = this;
         invalidate();
         if (displayable) {
            comp.addNotify();
         }
         if (layoutMgr != null) {
            if (layoutMgr instanceof LayoutManager2) {
               ((LayoutManager2) layoutMgr).addLayoutComponent(comp, constraints);
            } else if (constraints instanceof String) {
               layoutMgr.addLayoutComponent((String) constraints, comp);
            }
         }
      }
      if (containerListener != null || (eventMask & AWTEvent.CONTAINER_EVENT_MASK) != 0) {
         EventQueue.post(new ContainerEvent(this, ContainerEvent.COMPONENT_ADDED, comp));
      }
      if (comp.visible && isShowing()) {
         repaint(comp.x, comp.y, comp.width, comp.height);
      }
   }

   public void remove(int index) {
      Component comp;
      synchronized (LOCK) {
         if (index < 0 || index >= component.size()) {
            throw new ArrayIndexOutOfBoundsException(index);
         }
         comp = component.get(index);
         if (displayable) {
            comp.removeNotify();
         }
         if (layoutMgr != null) {
            layoutMgr.removeLayoutComponent(comp);
         }
         comp.parent = null;
         component.remove(index);
         invalidate();
      }
      if (containerListener != null || (eventMask & AWTEvent.CONTAINER_EVENT_MASK) != 0) {
         EventQueue.post(new ContainerEvent(this, ContainerEvent.COMPONENT_REMOVED, comp));
      }
      if (comp.visible && isShowing()) {
         repaint(comp.x, comp.y, comp.width, comp.height);
      }
   }

   public void remove(Component comp) {
      synchronized (LOCK) {
         if (comp.parent == this) {
            int index = component.indexOf(comp);
            if (index >= 0) {
               remove(index);
            }
         }
      }
   }

   public void removeAll() {
      synchronized (LOCK) {
         while (!component.isEmpty()) {
            remove(component.size() - 1);
         }
      }
   }

   public int getComponentZOrder(Component comp) {
      synchronized (LOCK) {
         return comp.parent == this ? component.indexOf(comp) : -1;
      }
   }

   public void setComponentZOrder(Component comp, int index) {
      synchronized (LOCK) {
         if (comp.parent != this) {
            add(comp, index);
            return;
         }
         component.remove(comp);
         component.add(index, comp);
      }
      repaint(comp.x, comp.y, comp.width, comp.height);
   }

   public LayoutManager getLayout() {
      return layoutMgr;
   }

   public void setLayout(LayoutManager mgr) {
      layoutMgr = mgr;
      if (valid) {
         invalidate();
      }
   }

   public void doLayout() {
      layout();
   }

   public void layout() {
      LayoutManager mgr = layoutMgr;
      if (mgr != null) {
         mgr.layoutContainer(this);
      }
   }

   public void invalidate() {
      LayoutManager mgr = layoutMgr;
      if (mgr instanceof LayoutManager2) {
         ((LayoutManager2) mgr).invalidateLayout(this);
      }
      super.invalidate();
   }

   public void validate() {
      synchronized (LOCK) {
         if (!isValid() && displayable) {
            validateTree();
         }
      }
   }

   protected void validateTree() {
      if (!isValid()) {
         doLayout();
         for (int i = 0; i < component.size(); i++) {
            Component comp = component.get(i);
            if (comp instanceof Container && !(comp instanceof Window) && !comp.isValid()) {
               ((Container) comp).validateTree();
            } else {
               comp.validate();
            }
         }
      }
      super.validate();
   }

   public void invalidateTree() {
      synchronized (LOCK) {
         for (Component comp : component) {
            if (comp instanceof Container) {
               ((Container) comp).invalidateTree();
            } else {
               comp.invalidate();
            }
         }
         invalidate();
      }
   }

   public void setFont(Font f) {
      super.setFont(f);
   }

   public Dimension preferredSize() {
      Dimension d = prefSize;
      if (d != null) {
         return new Dimension(d);
      }
      LayoutManager mgr = layoutMgr;
      if (mgr != null) {
         synchronized (LOCK) {
            Dimension cached = prefSizeCache;
            if (cached != null && isValid()) {
               return new Dimension(cached);
            }
            cached = mgr.preferredLayoutSize(this);
            prefSizeCache = cached;
            return new Dimension(cached);
         }
      }
      return super.preferredSize();
   }

   public Dimension minimumSize() {
      Dimension d = minSize;
      if (d != null) {
         return new Dimension(d);
      }
      LayoutManager mgr = layoutMgr;
      if (mgr != null) {
         synchronized (LOCK) {
            return mgr.minimumLayoutSize(this);
         }
      }
      return super.minimumSize();
   }

   public Dimension getMaximumSize() {
      Dimension d = maxSize;
      if (d != null) {
         return new Dimension(d);
      }
      if (layoutMgr instanceof LayoutManager2) {
         synchronized (LOCK) {
            return ((LayoutManager2) layoutMgr).maximumLayoutSize(this);
         }
      }
      return super.getMaximumSize();
   }

   public float getAlignmentX() {
      if (layoutMgr instanceof LayoutManager2) {
         synchronized (LOCK) {
            return ((LayoutManager2) layoutMgr).getLayoutAlignmentX(this);
         }
      }
      return super.getAlignmentX();
   }

   public float getAlignmentY() {
      if (layoutMgr instanceof LayoutManager2) {
         synchronized (LOCK) {
            return ((LayoutManager2) layoutMgr).getLayoutAlignmentY(this);
         }
      }
      return super.getAlignmentY();
   }

   /** As the JDK: a container's paint draws its lightweight children (heavyweight ones draw themselves). */
   public void paint(Graphics g) {
      if (isShowing()) {
         paintLightweights(g);
      }
   }

   void paintLightweights(Graphics g) {
      Component[] children = getComponents();
      Rectangle clip = g.getClipBounds();
      for (int i = children.length - 1; i >= 0; i--) {
         Component c = children[i];
         if (c.visible && c.isLightweight() && c.width > 0 && c.height > 0
               && (clip == null || clip.intersects(new Rectangle(c.x, c.y, c.width, c.height)))) {
            Graphics cg = g.create(c.x, c.y, c.width, c.height);
            try {
               cg.setColor(c.getForeground());
               cg.setFont(c.getFont());
               c.paint(cg);
            } finally {
               cg.dispose();
            }
         }
      }
   }

   public void update(Graphics g) {
      if (isShowing()) {
         if (!isLightweight() && (this instanceof Panel || this instanceof Window)) {
            g.clearRect(0, 0, width, height);
         }
         paint(g);
      }
   }

   public void print(Graphics g) {
      paint(g);
   }

   public void paintComponents(Graphics g) {
      if (isShowing()) {
         Component[] children = getComponents();
         for (int i = children.length - 1; i >= 0; i--) {
            Component c = children[i];
            if (c.visible) {
               Graphics cg = g.create(c.x, c.y, c.width, c.height);
               try {
                  c.paintAll(cg);
               } finally {
                  cg.dispose();
               }
            }
         }
      }
   }

   public void printComponents(Graphics g) {
      paintComponents(g);
   }

   boolean postsOldMouseEvents() {
      return true;
   }

   public void deliverEvent(Event e) {
      Component comp = getComponentAt(e.x, e.y);
      if (comp != null && comp != this) {
         e.translate(-comp.x, -comp.y);
         comp.deliverEvent(e);
      } else {
         postEvent(e);
      }
   }

   public Component getComponentAt(int x, int y) {
      return locate(x, y);
   }

   public Component locate(int x, int y) {
      if (!contains(x, y)) {
         return null;
      }
      if (!childrenAt(x, y)) {
         return this;
      }
      synchronized (LOCK) {
         for (Component comp : component) {
            if (!comp.isLightweight() && comp.contains(x - comp.x, y - comp.y)) {
               return comp;
            }
         }
         for (Component comp : component) {
            if (comp.isLightweight() && comp.contains(x - comp.x, y - comp.y)) {
               return comp;
            }
         }
      }
      return this;
   }

   public Component getComponentAt(Point p) {
      return getComponentAt(p.x, p.y);
   }

   public Component findComponentAt(int x, int y) {
      synchronized (LOCK) {
         return findComponentAt(x, y, true);
      }
   }

   public Component findComponentAt(Point p) {
      return findComponentAt(p.x, p.y);
   }

   /** The deepest visible component at (x, y), heavyweights before lightweights as the JDK. */
   Component findComponentAt(int x, int y, boolean ignoreEnabled) {
      if (!(contains(x, y) && visible && (ignoreEnabled || enabled))) {
         return null;
      }
      if (!childrenAt(x, y)) {
         return this;
      }
      for (int pass = 0; pass < 2; pass++) {
         for (Component comp : component) {
            if (comp.isLightweight() != (pass == 1) || !comp.visible) {
               continue;
            }
            if (comp instanceof Container) {
               Component found = ((Container) comp).findComponentAt(x - comp.x, y - comp.y, ignoreEnabled);
               if (found != null) {
                  return found;
               }
            } else if (comp.contains(x - comp.x, y - comp.y) && (ignoreEnabled || comp.enabled)) {
               return comp;
            }
         }
      }
      return this;
   }

   /** Whether children can be at this point (not on a scroll pane's edge or bars). */
   boolean childrenAt(int x, int y) {
      return true;
   }

   public boolean isAncestorOf(Component c) {
      Container p;
      if (c == null || (p = c.parent) == null) {
         return false;
      }
      while (p != null) {
         if (p == this) {
            return true;
         }
         p = p.parent;
      }
      return false;
   }

   public void addNotify() {
      synchronized (LOCK) {
         super.addNotify();
         for (Component comp : component) {
            comp.addNotify();
         }
      }
   }

   public void removeNotify() {
      synchronized (LOCK) {
         for (int i = component.size() - 1; i >= 0; i--) {
            component.get(i).removeNotify();
         }
         super.removeNotify();
      }
   }

   public synchronized void addContainerListener(ContainerListener l) {
      if (l == null) {
         return;
      }
      containerListener = AWTEventMulticaster.add(containerListener, l);
      newEventsOnly = true;
   }

   public synchronized void removeContainerListener(ContainerListener l) {
      if (l == null) {
         return;
      }
      containerListener = AWTEventMulticaster.remove(containerListener, l);
   }

   public synchronized ContainerListener[] getContainerListeners() {
      ArrayList<ContainerListener> out = new ArrayList<ContainerListener>();
      collect(containerListener, out);
      return out.toArray(new ContainerListener[out.size()]);
   }

   private static void collect(ContainerListener l, ArrayList<ContainerListener> out) {
      if (l instanceof AWTEventMulticaster) {
         AWTEventMulticaster m = (AWTEventMulticaster) l;
         collect((ContainerListener) m.a, out);
         collect((ContainerListener) m.b, out);
      } else if (l != null) {
         out.add(l);
      }
   }

   boolean eventEnabled(AWTEvent e) {
      int id = e.getID();
      if (id == ContainerEvent.COMPONENT_ADDED || id == ContainerEvent.COMPONENT_REMOVED) {
         return (eventMask & AWTEvent.CONTAINER_EVENT_MASK) != 0 || containerListener != null;
      }
      return super.eventEnabled(e);
   }

   protected void processEvent(AWTEvent e) {
      if (e instanceof ContainerEvent) {
         processContainerEvent((ContainerEvent) e);
         return;
      }
      super.processEvent(e);
   }

   protected void processContainerEvent(ContainerEvent e) {
      ContainerListener listener = containerListener;
      if (listener != null) {
         if (e.getID() == ContainerEvent.COMPONENT_ADDED) {
            listener.componentAdded(e);
         } else if (e.getID() == ContainerEvent.COMPONENT_REMOVED) {
            listener.componentRemoved(e);
         }
      }
   }

   public boolean isFocusCycleRoot() {
      return false;
   }

   protected String paramString() {
      String str = super.paramString();
      LayoutManager mgr = layoutMgr;
      if (mgr != null) {
         str += ",layout=" + mgr.getClass().getName();
      }
      return str;
   }

   public void list(java.io.PrintStream out, int indent) {
      super.list(out, indent);
      for (Component comp : getComponents()) {
         comp.list(out, indent + 1);
      }
   }

   public void list(java.io.PrintWriter out, int indent) {
      super.list(out, indent);
      for (Component comp : getComponents()) {
         comp.list(out, indent + 1);
      }
   }
}
