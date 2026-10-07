package java.awt;

import java.awt.event.ComponentEvent;
import java.awt.event.ComponentListener;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import java.awt.event.HierarchyBoundsListener;
import java.awt.event.HierarchyEvent;
import java.awt.event.HierarchyListener;
import java.awt.event.InputEvent;
import java.awt.event.InputMethodEvent;
import java.awt.event.InputMethodListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;
import java.awt.event.PaintEvent;
import java.awt.image.ColorModel;
import java.awt.image.ImageObserver;
import java.awt.image.ImageProducer;
import java.util.ArrayList;
import java.util.EventListener;
import java.util.Locale;

/**
 * A component of the 2004 client's interface, as java.awt.Component.
 *
 * There are no native peers: every component is drawn by us into the pixels
 * of its window ({@link WindowSystem}), widgets in the look of the Windows
 * controls the client had. What the peers did is done here with the same
 * order the JDK has: the 1.1 listeners (or, for components without any, the
 * 1.0 handleEvent chain), then the widget's own reaction if the event was
 * not consumed ({@link #handlePeerEvent}).
 */
public abstract class Component implements ImageObserver, MenuContainer, java.io.Serializable {
   public static final float TOP_ALIGNMENT = 0.0f;
   public static final float CENTER_ALIGNMENT = 0.5f;
   public static final float BOTTOM_ALIGNMENT = 1.0f;
   public static final float LEFT_ALIGNMENT = 0.0f;
   public static final float RIGHT_ALIGNMENT = 1.0f;

   /** AWT's tree lock: layout, the component tree and focus. */
   static final Object LOCK = new AWTTreeLock();

   static final class AWTTreeLock {
   }

   transient Container parent;
   int x;
   int y;
   int width;
   int height;
   Color foreground;
   Color background;
   Font font;
   Cursor cursor;
   Locale locale;
   boolean visible = true;
   boolean enabled = true;
   volatile boolean valid;
   boolean focusable = true;
   boolean ignoreRepaint;
   String name;
   boolean nameExplicitlySet;
   /** Between addNotify and removeNotify: what a peer meant. */
   volatile boolean displayable;
   Dimension prefSize;
   Dimension minSize;
   Dimension maxSize;
   ArrayList<PopupMenu> popups;

   long eventMask = AWTEvent.INPUT_METHOD_EVENT_MASK;
   /** Set once a listener is added or events are enabled: from then on no 1.0 events (as the JDK). */
   boolean newEventsOnly;

   transient ComponentListener componentListener;
   transient FocusListener focusListener;
   transient HierarchyListener hierarchyListener;
   transient HierarchyBoundsListener hierarchyBoundsListener;
   transient KeyListener keyListener;
   transient MouseListener mouseListener;
   transient MouseMotionListener mouseMotionListener;
   transient MouseWheelListener mouseWheelListener;
   transient InputMethodListener inputMethodListener;
   private final ArrayList<EventListener> listeners = new ArrayList<EventListener>();

   private static int nameCounter;

   protected Component() {
   }

   String constructComponentName() {
      synchronized (Component.class) {
         String base = getClass().getName();
         int dot = base.lastIndexOf('.');
         base = base.substring(dot + 1).toLowerCase(Locale.ROOT);
         return base + nameCounter++;
      }
   }

   public String getName() {
      if (name == null && !nameExplicitlySet) {
         synchronized (this) {
            if (name == null && !nameExplicitlySet) {
               name = constructComponentName();
            }
         }
      }
      return name;
   }

   public void setName(String name) {
      synchronized (this) {
         this.name = name;
         nameExplicitlySet = true;
      }
   }

   public Container getParent() {
      return parent;
   }

   public final Object getTreeLock() {
      return LOCK;
   }

   public Toolkit getToolkit() {
      return Toolkit.getDefaultToolkit();
   }

   public GraphicsConfiguration getGraphicsConfiguration() {
      return GraphicsEnvironment.getLocalGraphicsEnvironment().getDefaultScreenDevice().getDefaultConfiguration();
   }

   public boolean isValid() {
      return displayable && valid;
   }

   public boolean isDisplayable() {
      return displayable;
   }

   public boolean isVisible() {
      return visible;
   }

   /** Visible, and so are all its ancestors up to a showing window. */
   public boolean isShowing() {
      if (visible && displayable) {
         Container p = parent;
         return p == null ? this instanceof Window && WindowSystem.isOnScreen((Window) this) : p.isShowing();
      }
      return false;
   }

   public boolean isEnabled() {
      return enabled;
   }

   public void setEnabled(boolean b) {
      enable(b);
   }

   public void enable() {
      if (!enabled) {
         enabled = true;
         repaint();
      }
   }

   public void enable(boolean b) {
      if (b) {
         enable();
      } else {
         disable();
      }
   }

   public void disable() {
      if (enabled) {
         enabled = false;
         KeyboardFocusManager.getCurrentKeyboardFocusManager().componentDisabled(this);
         repaint();
      }
   }

   public boolean isLightweight() {
      return false;
   }

   public boolean isOpaque() {
      return !isLightweight();
   }

   public boolean isDoubleBuffered() {
      return false;
   }

   public void setVisible(boolean b) {
      show(b);
   }

   public void show() {
      if (!visible) {
         synchronized (LOCK) {
            visible = true;
            if (parent != null) {
               parent.invalidate();
            }
         }
         if (parent != null && parent.isShowing()) {
            parent.repaint(x, y, width, height);
         }
         postComponentEvent(ComponentEvent.COMPONENT_SHOWN);
      }
   }

   public void show(boolean b) {
      if (b) {
         show();
      } else {
         hide();
      }
   }

   public void hide() {
      if (visible) {
         boolean wasShowing = isShowing();
         synchronized (LOCK) {
            visible = false;
            if (parent != null) {
               parent.invalidate();
            }
         }
         KeyboardFocusManager.getCurrentKeyboardFocusManager().componentHidden(this);
         if (wasShowing && parent != null) {
            parent.repaint(x, y, width, height);
         }
         postComponentEvent(ComponentEvent.COMPONENT_HIDDEN);
      }
   }

   public Color getForeground() {
      Color c = foreground;
      if (c != null) {
         return c;
      }
      Container p = parent;
      return p != null ? p.getForeground() : null;
   }

   public void setForeground(Color c) {
      foreground = c;
      repaint();
   }

   public boolean isForegroundSet() {
      return foreground != null;
   }

   public Color getBackground() {
      Color c = background;
      if (c != null) {
         return c;
      }
      Container p = parent;
      return p != null ? p.getBackground() : null;
   }

   public void setBackground(Color c) {
      background = c;
      repaint();
   }

   public boolean isBackgroundSet() {
      return background != null;
   }

   public Font getFont() {
      Font f = font;
      if (f != null) {
         return f;
      }
      Container p = parent;
      return p != null ? p.getFont() : null;
   }

   public void setFont(Font f) {
      synchronized (LOCK) {
         font = f;
      }
      if (valid) {
         invalidate();
      }
      repaint();
   }

   public boolean isFontSet() {
      return font != null;
   }

   public Locale getLocale() {
      Locale l = locale;
      if (l != null) {
         return l;
      }
      Container p = parent;
      return p != null ? p.getLocale() : Locale.getDefault();
   }

   public void setLocale(Locale l) {
      locale = l;
   }

   public ColorModel getColorModel() {
      return getToolkit().getColorModel();
   }

   public Point getLocation() {
      return location();
   }

   public Point location() {
      synchronized (LOCK) {
         return new Point(x, y);
      }
   }

   public Point getLocation(Point rv) {
      rv.x = x;
      rv.y = y;
      return rv;
   }

   public Point getLocationOnScreen() {
      synchronized (LOCK) {
         if (!isShowing()) {
            throw new IllegalComponentStateException("component must be showing on the screen to determine its location");
         }
         return locationOnScreen();
      }
   }

   Point locationOnScreen() {
      int sx = 0;
      int sy = 0;
      for (Component c = this; c != null; c = c.parent) {
         sx += c.x;
         sy += c.y;
      }
      return new Point(sx, sy);
   }

   public void setLocation(int x, int y) {
      move(x, y);
   }

   public void setLocation(Point p) {
      setLocation(p.x, p.y);
   }

   public void move(int x, int y) {
      setBounds(x, y, width, height);
   }

   public Dimension getSize() {
      return size();
   }

   public Dimension size() {
      return new Dimension(width, height);
   }

   public Dimension getSize(Dimension rv) {
      rv.width = width;
      rv.height = height;
      return rv;
   }

   public void setSize(int width, int height) {
      resize(width, height);
   }

   public void setSize(Dimension d) {
      resize(d.width, d.height);
   }

   public void resize(int width, int height) {
      setBounds(x, y, width, height);
   }

   public void resize(Dimension d) {
      setSize(d.width, d.height);
   }

   public Rectangle getBounds() {
      return bounds();
   }

   public Rectangle bounds() {
      return new Rectangle(x, y, width, height);
   }

   public Rectangle getBounds(Rectangle rv) {
      rv.setBounds(x, y, width, height);
      return rv;
   }

   public int getX() {
      return x;
   }

   public int getY() {
      return y;
   }

   public int getWidth() {
      return width;
   }

   public int getHeight() {
      return height;
   }

   public void setBounds(int x, int y, int width, int height) {
      reshape(x, y, width, height);
   }

   public void setBounds(Rectangle r) {
      setBounds(r.x, r.y, r.width, r.height);
   }

   public void reshape(int x, int y, int width, int height) {
      boolean resized;
      boolean moved;
      int oldX, oldY, oldW, oldH;
      synchronized (LOCK) {
         resized = this.width != width || this.height != height;
         moved = this.x != x || this.y != y;
         if (!resized && !moved) {
            return;
         }
         oldX = this.x;
         oldY = this.y;
         oldW = this.width;
         oldH = this.height;
         this.x = x;
         this.y = y;
         this.width = width;
         this.height = height;
         if (resized) {
            invalidate();
         }
         if (parent != null && parent.valid) {
            parent.invalidate();
         }
      }
      boundsChanged(oldX, oldY, oldW, oldH, resized, moved);
      if (resized) {
         postComponentEvent(ComponentEvent.COMPONENT_RESIZED);
      }
      if (moved) {
         postComponentEvent(ComponentEvent.COMPONENT_MOVED);
      }
   }

   /** Repaints what the move uncovered and where it went (windows: the window system re-places it). */
   void boundsChanged(int oldX, int oldY, int oldW, int oldH, boolean resized, boolean moved) {
      Container p = parent;
      if (p != null && p.isShowing() && visible) {
         p.repaint(oldX, oldY, oldW, oldH);
         p.repaint(x, y, width, height);
      }
   }

   public Dimension getPreferredSize() {
      return preferredSize();
   }

   /** As JDK 1.4: what the native control asks for once it exists, its minimum size before. */
   public Dimension preferredSize() {
      Dimension d = prefSize;
      if (d != null) {
         return new Dimension(d);
      }
      if (displayable) {
         Dimension peer = peerPreferredSize();
         if (peer != null) {
            return peer;
         }
      }
      return getMinimumSize();
   }

   Dimension peerPreferredSize() {
      return peerMinimumSize();
   }

   public void setPreferredSize(Dimension d) {
      prefSize = d == null ? null : new Dimension(d);
   }

   public boolean isPreferredSizeSet() {
      return prefSize != null;
   }

   public Dimension getMinimumSize() {
      return minimumSize();
   }

   public Dimension minimumSize() {
      Dimension d = minSize;
      if (d != null) {
         return new Dimension(d);
      }
      if (displayable) {
         Dimension peer = peerMinimumSize();
         if (peer != null) {
            return peer;
         }
      }
      return size();
   }

   /** The size the native control would ask for (Windows' peers' getMinimumSize); null for plain components. */
   Dimension peerMinimumSize() {
      return null;
   }

   public void setMinimumSize(Dimension d) {
      minSize = d == null ? null : new Dimension(d);
   }

   public boolean isMinimumSizeSet() {
      return minSize != null;
   }

   public Dimension getMaximumSize() {
      Dimension d = maxSize;
      if (d != null) {
         return new Dimension(d);
      }
      return new Dimension(Short.MAX_VALUE, Short.MAX_VALUE);
   }

   public void setMaximumSize(Dimension d) {
      maxSize = d == null ? null : new Dimension(d);
   }

   public float getAlignmentX() {
      return CENTER_ALIGNMENT;
   }

   public float getAlignmentY() {
      return CENTER_ALIGNMENT;
   }

   public void doLayout() {
      layout();
   }

   public void layout() {
   }

   public void validate() {
      synchronized (LOCK) {
         valid = true;
      }
   }

   public void invalidate() {
      synchronized (LOCK) {
         valid = false;
         prefSizeCache = null;
         if (parent != null && parent.valid) {
            parent.invalidate();
         }
      }
   }

   /** Containers keep their computed preferred size until invalidated. */
   Dimension prefSizeCache;

   public void revalidate() {
      invalidate();
      Component top = this;
      while (top.parent != null) {
         top = top.parent;
      }
      if (top instanceof Container) {
         ((Container) top).validate();
      }
   }

   // ---------------------------------------------------------------- painting

   public Graphics getGraphics() {
      if (!isShowing()) {
         return null;
      }
      return WindowSystem.graphicsFor(this);
   }

   public FontMetrics getFontMetrics(Font font) {
      return FontMetrics.of(font);
   }

   public void setCursor(Cursor cursor) {
      this.cursor = cursor;
      WindowSystem.cursorChanged(this);
   }

   public Cursor getCursor() {
      Cursor c = cursor;
      if (c != null) {
         return c;
      }
      Container p = parent;
      return p != null ? p.getCursor() : Cursor.getDefaultCursor();
   }

   public boolean isCursorSet() {
      return cursor != null;
   }

   public void paint(Graphics g) {
   }

   /**
    * As the JDK: heavyweight containers and canvases have their background
    * cleared first.
    */
   public void update(Graphics g) {
      if (this instanceof Canvas || this instanceof Panel || this instanceof Frame || this instanceof Dialog
            || this instanceof Window) {
         if (!isLightweight()) {
            g.clearRect(0, 0, width, height);
         }
      }
      paint(g);
   }

   public void paintAll(Graphics g) {
      if (isShowing()) {
         WindowSystem.paintTree(this, g, false);
      }
   }

   public void repaint() {
      repaint(0, 0, 0, width, height);
   }

   public void repaint(long tm) {
      repaint(tm, 0, 0, width, height);
   }

   public void repaint(int x, int y, int width, int height) {
      repaint(0, x, y, width, height);
   }

   public void repaint(long tm, int x, int y, int width, int height) {
      if (ignoreRepaint || !isShowing() || width <= 0 || height <= 0) {
         return;
      }
      if (isLightweight()) {
         // drawn by its parent's paint, as the JDK's lightweights
         Container p = parent;
         if (p != null) {
            p.repaint(tm, this.x + x, this.y + y, width, height);
         }
         return;
      }
      EventQueue.postRepaint(this, new Rectangle(x, y, width, height));
   }

   public void print(Graphics g) {
      paint(g);
   }

   public void printAll(Graphics g) {
      paintAll(g);
   }

   public void setIgnoreRepaint(boolean ignoreRepaint) {
      this.ignoreRepaint = ignoreRepaint;
   }

   public boolean getIgnoreRepaint() {
      return ignoreRepaint;
   }

   /** The control's own drawing, before paint(): what Windows drew for it. Plain components draw nothing. */
   void paintPeer(Graphics g) {
   }

   /** Whether update() and paint() are called for this component (widgets draw only themselves unless subclassed). */
   boolean callsPaint() {
      return true;
   }

   public boolean imageUpdate(Image img, int infoflags, int x, int y, int w, int h) {
      if ((infoflags & (FRAMEBITS | ALLBITS)) != 0) {
         repaint();
      } else if ((infoflags & SOMEBITS) != 0) {
         repaint(x, y, w, h);
      }
      return (infoflags & (ALLBITS | ABORT)) == 0;
   }

   public Image createImage(ImageProducer producer) {
      return getToolkit().createImage(producer);
   }

   /** An offscreen image filled with the background, as the JDK's peers make it. */
   public Image createImage(int width, int height) {
      if (!displayable) {
         return null;
      }
      java.awt.image.BufferedImage img = new java.awt.image.BufferedImage(Math.max(1, width), Math.max(1, height),
            java.awt.image.BufferedImage.TYPE_INT_RGB);
      Color bg = getBackground();
      if (bg != null) {
         Graphics g = img.getGraphics();
         g.setColor(bg);
         g.fillRect(0, 0, width, height);
         g.dispose();
      }
      return img;
   }

   public boolean prepareImage(Image image, ImageObserver observer) {
      return prepareImage(image, -1, -1, observer);
   }

   public boolean prepareImage(Image image, int width, int height, ImageObserver observer) {
      return getToolkit().prepareImage(image, width, height, observer);
   }

   public int checkImage(Image image, ImageObserver observer) {
      return checkImage(image, -1, -1, observer);
   }

   public int checkImage(Image image, int width, int height, ImageObserver observer) {
      return getToolkit().checkImage(image, width, height, observer);
   }

   // ---------------------------------------------------------------- geometry

   public boolean contains(int x, int y) {
      return inside(x, y);
   }

   public boolean contains(Point p) {
      return contains(p.x, p.y);
   }

   public boolean inside(int x, int y) {
      return x >= 0 && x < width && y >= 0 && y < height;
   }

   public Component getComponentAt(int x, int y) {
      return locate(x, y);
   }

   public Component getComponentAt(Point p) {
      return getComponentAt(p.x, p.y);
   }

   public Component locate(int x, int y) {
      return contains(x, y) ? this : null;
   }

   /** The window this component is drawn in (itself for a window). */
   Window windowAncestor() {
      Component c = this;
      while (c != null && !(c instanceof Window)) {
         c = c.parent;
      }
      return (Window) c;
   }

   /** Where this component's (0, 0) is in its window's pixels. */
   Point originInWindow() {
      int ox = 0;
      int oy = 0;
      for (Component c = this; c != null && !(c instanceof Window); c = c.parent) {
         ox += c.x;
         oy += c.y;
      }
      return new Point(ox, oy);
   }

   /** The part of this component that its ancestors do not cut off, in its window's pixels. */
   Rectangle visibleInWindow() {
      Point o = originInWindow();
      Rectangle r = new Rectangle(o.x, o.y, width, height);
      int ox = o.x - x;
      int oy = o.y - y;
      for (Container p = parent; p != null && !(p instanceof Window); p = p.parent) {
         Rectangle pr = new Rectangle(ox, oy, p.width, p.height);
         if (p instanceof ScrollPane) {
            // a scroll pane's child shows only in the viewport
            Rectangle v = ((ScrollPane) p).viewport();
            pr = new Rectangle(ox + v.x, oy + v.y, v.width, v.height);
         }
         r = r.intersection(pr);
         ox -= p.x;
         oy -= p.y;
      }
      Window w = windowAncestor();
      if (w != null && w != this) {
         r = r.intersection(new Rectangle(0, 0, w.width, w.height));
      }
      return r;
   }

   // ---------------------------------------------------------------- events

   public void deliverEvent(Event e) {
      postEvent(e);
   }

   public final void dispatchEvent(AWTEvent e) {
      dispatchEventImpl(e);
   }

   /** The JDK's Component.dispatchEventImpl, without peers. */
   void dispatchEventImpl(AWTEvent e) {
      int id = e.getID();
      Toolkit.getDefaultToolkit().notifyAWTEventListeners(e);

      if (e instanceof KeyEvent && KeyboardFocusManager.getCurrentKeyboardFocusManager().preDispatchKey(this, (KeyEvent) e)) {
         return;
      }
      if (id == PaintEvent.PAINT || id == PaintEvent.UPDATE) {
         WindowSystem.paintNow(this, ((PaintEvent) e).getUpdateRect(), id == PaintEvent.UPDATE);
         return;
      }
      if (e instanceof FocusEvent) {
         focusEventArrived((FocusEvent) e);
      }

      if (id == MouseEvent.MOUSE_WHEEL && !handlesWheel() && !(newEventsOnly && eventEnabled(e))) {
         // as dispatchMouseWheelToAncestor: a component that does not take the wheel hands it to its parent
         Container p = parent;
         if (p != null && !(this instanceof Window)) {
            MouseWheelEvent w = (MouseWheelEvent) e;
            w.translatePoint(x, y);
            w.setSource(p);
            p.dispatchEvent(w);
         }
         return;
      }
      if (newEventsOnly) {
         if (eventEnabled(e)) {
            processEvent(e);
         }
      } else if (id == MouseEvent.MOUSE_WHEEL) {
         // no 1.0 event for the wheel: the control scrolls itself (handlePeerEvent)
      } else if (!(e instanceof MouseEvent && !postsOldMouseEvents())) {
         Event olde = e.convertToOld();
         if (olde != null) {
            int key = olde.key;
            int modifiers = olde.modifiers;
            postEvent(olde);
            if (olde.isConsumed()) {
               e.consumeAny();
            }
            switch (olde.id) {
               case Event.KEY_PRESS:
               case Event.KEY_RELEASE:
               case Event.KEY_ACTION:
               case Event.KEY_ACTION_RELEASE:
                  if (olde.key != key) {
                     ((KeyEvent) e).setKeyChar(olde.getKeyEventChar());
                  }
                  if (olde.modifiers != modifiers) {
                     ((KeyEvent) e).setModifiers(olde.modifiers);
                  }
                  break;
               default:
            }
         }
      }

      if (!e.consumedFlag() || !(e instanceof InputEvent)) {
         handlePeerEvent(e);
      }
      if (e instanceof KeyEvent) {
         KeyboardFocusManager.getCurrentKeyboardFocusManager().postDispatchKey(this, (KeyEvent) e);
      }
   }

   /** What the native control does with an event Java did not consume. */
   void handlePeerEvent(AWTEvent e) {
   }

   /** Controls that scroll with the mouse wheel themselves (lists, text areas, scroll panes). */
   boolean handlesWheel() {
      return false;
   }

   /** Called on the event thread when this component gains or loses the keyboard focus, before any listener. */
   void focusEventArrived(FocusEvent e) {
      if (focusDrawn()) {
         repaint();
      }
   }

   /** Whether the control shows a focus mark (buttons, check boxes, lists). */
   boolean focusDrawn() {
      return false;
   }

   boolean postsOldMouseEvents() {
      return false;
   }

   boolean eventEnabled(AWTEvent e) {
      int type = e.id;
      switch (type) {
         case ComponentEvent.COMPONENT_MOVED:
         case ComponentEvent.COMPONENT_RESIZED:
         case ComponentEvent.COMPONENT_SHOWN:
         case ComponentEvent.COMPONENT_HIDDEN:
            return (eventMask & AWTEvent.COMPONENT_EVENT_MASK) != 0 || componentListener != null;
         case FocusEvent.FOCUS_GAINED:
         case FocusEvent.FOCUS_LOST:
            return (eventMask & AWTEvent.FOCUS_EVENT_MASK) != 0 || focusListener != null;
         case KeyEvent.KEY_PRESSED:
         case KeyEvent.KEY_RELEASED:
         case KeyEvent.KEY_TYPED:
            return (eventMask & AWTEvent.KEY_EVENT_MASK) != 0 || keyListener != null;
         case MouseEvent.MOUSE_PRESSED:
         case MouseEvent.MOUSE_RELEASED:
         case MouseEvent.MOUSE_ENTERED:
         case MouseEvent.MOUSE_EXITED:
         case MouseEvent.MOUSE_CLICKED:
            return (eventMask & AWTEvent.MOUSE_EVENT_MASK) != 0 || mouseListener != null;
         case MouseEvent.MOUSE_MOVED:
         case MouseEvent.MOUSE_DRAGGED:
            return (eventMask & AWTEvent.MOUSE_MOTION_EVENT_MASK) != 0 || mouseMotionListener != null;
         case MouseEvent.MOUSE_WHEEL:
            return (eventMask & AWTEvent.MOUSE_WHEEL_EVENT_MASK) != 0 || mouseWheelListener != null;
         case HierarchyEvent.HIERARCHY_CHANGED:
            return (eventMask & AWTEvent.HIERARCHY_EVENT_MASK) != 0 || hierarchyListener != null;
         case HierarchyEvent.ANCESTOR_MOVED:
         case HierarchyEvent.ANCESTOR_RESIZED:
            return (eventMask & AWTEvent.HIERARCHY_BOUNDS_EVENT_MASK) != 0 || hierarchyBoundsListener != null;
         case java.awt.event.ActionEvent.ACTION_PERFORMED:
            return (eventMask & AWTEvent.ACTION_EVENT_MASK) != 0;
         case java.awt.event.TextEvent.TEXT_VALUE_CHANGED:
            return (eventMask & AWTEvent.TEXT_EVENT_MASK) != 0;
         case java.awt.event.ItemEvent.ITEM_STATE_CHANGED:
            return (eventMask & AWTEvent.ITEM_EVENT_MASK) != 0;
         case java.awt.event.AdjustmentEvent.ADJUSTMENT_VALUE_CHANGED:
            return (eventMask & AWTEvent.ADJUSTMENT_EVENT_MASK) != 0;
         default:
      }
      return type > AWTEvent.RESERVED_ID_MAX;
   }

   protected final void enableEvents(long eventsToEnable) {
      synchronized (this) {
         eventMask |= eventsToEnable;
         newEventsOnly = true;
      }
   }

   protected final void disableEvents(long eventsToDisable) {
      synchronized (this) {
         eventMask &= ~eventsToDisable;
      }
   }

   protected AWTEvent coalesceEvents(AWTEvent existingEvent, AWTEvent newEvent) {
      return null;
   }

   protected void processEvent(AWTEvent e) {
      if (e instanceof FocusEvent) {
         processFocusEvent((FocusEvent) e);
      } else if (e instanceof MouseEvent) {
         switch (e.getID()) {
            case MouseEvent.MOUSE_PRESSED:
            case MouseEvent.MOUSE_RELEASED:
            case MouseEvent.MOUSE_CLICKED:
            case MouseEvent.MOUSE_ENTERED:
            case MouseEvent.MOUSE_EXITED:
               processMouseEvent((MouseEvent) e);
               break;
            case MouseEvent.MOUSE_MOVED:
            case MouseEvent.MOUSE_DRAGGED:
               processMouseMotionEvent((MouseEvent) e);
               break;
            case MouseEvent.MOUSE_WHEEL:
               processMouseWheelEvent((MouseWheelEvent) e);
               break;
            default:
         }
      } else if (e instanceof KeyEvent) {
         processKeyEvent((KeyEvent) e);
      } else if (e instanceof ComponentEvent) {
         processComponentEvent((ComponentEvent) e);
      } else if (e instanceof InputMethodEvent) {
         processInputMethodEvent((InputMethodEvent) e);
      } else if (e instanceof HierarchyEvent) {
         switch (e.getID()) {
            case HierarchyEvent.HIERARCHY_CHANGED:
               processHierarchyEvent((HierarchyEvent) e);
               break;
            case HierarchyEvent.ANCESTOR_MOVED:
            case HierarchyEvent.ANCESTOR_RESIZED:
               processHierarchyBoundsEvent((HierarchyEvent) e);
               break;
            default:
         }
      }
   }

   protected void processComponentEvent(ComponentEvent e) {
      ComponentListener listener = componentListener;
      if (listener != null) {
         switch (e.getID()) {
            case ComponentEvent.COMPONENT_RESIZED:
               listener.componentResized(e);
               break;
            case ComponentEvent.COMPONENT_MOVED:
               listener.componentMoved(e);
               break;
            case ComponentEvent.COMPONENT_SHOWN:
               listener.componentShown(e);
               break;
            case ComponentEvent.COMPONENT_HIDDEN:
               listener.componentHidden(e);
               break;
            default:
         }
      }
   }

   protected void processFocusEvent(FocusEvent e) {
      FocusListener listener = focusListener;
      if (listener != null) {
         if (e.getID() == FocusEvent.FOCUS_GAINED) {
            listener.focusGained(e);
         } else if (e.getID() == FocusEvent.FOCUS_LOST) {
            listener.focusLost(e);
         }
      }
   }

   protected void processKeyEvent(KeyEvent e) {
      KeyListener listener = keyListener;
      if (listener != null) {
         switch (e.getID()) {
            case KeyEvent.KEY_TYPED:
               listener.keyTyped(e);
               break;
            case KeyEvent.KEY_PRESSED:
               listener.keyPressed(e);
               break;
            case KeyEvent.KEY_RELEASED:
               listener.keyReleased(e);
               break;
            default:
         }
      }
   }

   protected void processMouseEvent(MouseEvent e) {
      MouseListener listener = mouseListener;
      if (listener != null) {
         switch (e.getID()) {
            case MouseEvent.MOUSE_PRESSED:
               listener.mousePressed(e);
               break;
            case MouseEvent.MOUSE_RELEASED:
               listener.mouseReleased(e);
               break;
            case MouseEvent.MOUSE_CLICKED:
               listener.mouseClicked(e);
               break;
            case MouseEvent.MOUSE_EXITED:
               listener.mouseExited(e);
               break;
            case MouseEvent.MOUSE_ENTERED:
               listener.mouseEntered(e);
               break;
            default:
         }
      }
   }

   protected void processMouseMotionEvent(MouseEvent e) {
      MouseMotionListener listener = mouseMotionListener;
      if (listener != null) {
         if (e.getID() == MouseEvent.MOUSE_MOVED) {
            listener.mouseMoved(e);
         } else if (e.getID() == MouseEvent.MOUSE_DRAGGED) {
            listener.mouseDragged(e);
         }
      }
   }

   protected void processMouseWheelEvent(MouseWheelEvent e) {
      MouseWheelListener listener = mouseWheelListener;
      if (listener != null && e.getID() == MouseEvent.MOUSE_WHEEL) {
         listener.mouseWheelMoved(e);
      }
   }

   protected void processInputMethodEvent(InputMethodEvent e) {
      InputMethodListener listener = inputMethodListener;
      if (listener != null) {
         if (e.getID() == InputMethodEvent.INPUT_METHOD_TEXT_CHANGED) {
            listener.inputMethodTextChanged(e);
         } else if (e.getID() == InputMethodEvent.CARET_POSITION_CHANGED) {
            listener.caretPositionChanged(e);
         }
      }
   }

   protected void processHierarchyEvent(HierarchyEvent e) {
      HierarchyListener listener = hierarchyListener;
      if (listener != null && e.getID() == HierarchyEvent.HIERARCHY_CHANGED) {
         listener.hierarchyChanged(e);
      }
   }

   protected void processHierarchyBoundsEvent(HierarchyEvent e) {
      HierarchyBoundsListener listener = hierarchyBoundsListener;
      if (listener != null) {
         if (e.getID() == HierarchyEvent.ANCESTOR_MOVED) {
            listener.ancestorMoved(e);
         } else if (e.getID() == HierarchyEvent.ANCESTOR_RESIZED) {
            listener.ancestorResized(e);
         }
      }
   }

   void postComponentEvent(int id) {
      if (componentListener != null || (eventMask & AWTEvent.COMPONENT_EVENT_MASK) != 0
            || (!newEventsOnly && id == ComponentEvent.COMPONENT_MOVED && (this instanceof Frame || this instanceof Dialog))) {
         EventQueue.post(new ComponentEvent(this, id));
      }
   }

   // ---------------------------------------------------------------- 1.0 events

   public boolean postEvent(Event e) {
      if (handleEvent(e)) {
         e.consume();
         return true;
      }
      Component parent = this.parent;
      int eventx = e.x;
      int eventy = e.y;
      if (parent != null) {
         e.translate(x, y);
         if (parent.postEvent(e)) {
            e.consume();
            return true;
         }
         e.x = eventx;
         e.y = eventy;
      }
      return false;
   }

   public boolean handleEvent(Event evt) {
      switch (evt.id) {
         case Event.MOUSE_ENTER:
            return mouseEnter(evt, evt.x, evt.y);
         case Event.MOUSE_EXIT:
            return mouseExit(evt, evt.x, evt.y);
         case Event.MOUSE_MOVE:
            return mouseMove(evt, evt.x, evt.y);
         case Event.MOUSE_DOWN:
            return mouseDown(evt, evt.x, evt.y);
         case Event.MOUSE_DRAG:
            return mouseDrag(evt, evt.x, evt.y);
         case Event.MOUSE_UP:
            return mouseUp(evt, evt.x, evt.y);
         case Event.KEY_PRESS:
         case Event.KEY_ACTION:
            return keyDown(evt, evt.key);
         case Event.KEY_RELEASE:
         case Event.KEY_ACTION_RELEASE:
            return keyUp(evt, evt.key);
         case Event.ACTION_EVENT:
            return action(evt, evt.arg);
         case Event.GOT_FOCUS:
            return gotFocus(evt, evt.arg);
         case Event.LOST_FOCUS:
            return lostFocus(evt, evt.arg);
         default:
      }
      return false;
   }

   public boolean mouseDown(Event evt, int x, int y) {
      return false;
   }

   public boolean mouseDrag(Event evt, int x, int y) {
      return false;
   }

   public boolean mouseUp(Event evt, int x, int y) {
      return false;
   }

   public boolean mouseMove(Event evt, int x, int y) {
      return false;
   }

   public boolean mouseEnter(Event evt, int x, int y) {
      return false;
   }

   public boolean mouseExit(Event evt, int x, int y) {
      return false;
   }

   public boolean keyDown(Event evt, int key) {
      return false;
   }

   public boolean keyUp(Event evt, int key) {
      return false;
   }

   public boolean action(Event evt, Object what) {
      return false;
   }

   public boolean gotFocus(Event evt, Object what) {
      return false;
   }

   public boolean lostFocus(Event evt, Object what) {
      return false;
   }

   // ---------------------------------------------------------------- listeners

   private <T extends EventListener> T[] listenersOf(Class<T> type, T[] empty) {
      synchronized (listeners) {
         ArrayList<T> out = new ArrayList<T>();
         for (EventListener l : listeners) {
            if (type.isInstance(l)) {
               out.add(type.cast(l));
            }
         }
         return out.toArray(empty);
      }
   }

   private void addListener(EventListener l) {
      synchronized (listeners) {
         listeners.add(l);
      }
   }

   private void removeListener(EventListener l) {
      synchronized (listeners) {
         listeners.remove(l);
      }
   }

   public synchronized void addComponentListener(ComponentListener l) {
      if (l == null) {
         return;
      }
      componentListener = AWTEventMulticaster.add(componentListener, l);
      addListener(l);
      newEventsOnly = true;
   }

   public synchronized void removeComponentListener(ComponentListener l) {
      if (l == null) {
         return;
      }
      componentListener = AWTEventMulticaster.remove(componentListener, l);
      removeListener(l);
   }

   public synchronized ComponentListener[] getComponentListeners() {
      return listenersOf(ComponentListener.class, new ComponentListener[0]);
   }

   public synchronized void addFocusListener(FocusListener l) {
      if (l == null) {
         return;
      }
      focusListener = AWTEventMulticaster.add(focusListener, l);
      addListener(l);
      newEventsOnly = true;
   }

   public synchronized void removeFocusListener(FocusListener l) {
      if (l == null) {
         return;
      }
      focusListener = AWTEventMulticaster.remove(focusListener, l);
      removeListener(l);
   }

   public synchronized FocusListener[] getFocusListeners() {
      return listenersOf(FocusListener.class, new FocusListener[0]);
   }

   public void addHierarchyListener(HierarchyListener l) {
      if (l == null) {
         return;
      }
      synchronized (this) {
         hierarchyListener = AWTEventMulticaster.add(hierarchyListener, l);
         addListener(l);
         newEventsOnly = true;
      }
   }

   public void removeHierarchyListener(HierarchyListener l) {
      if (l == null) {
         return;
      }
      synchronized (this) {
         hierarchyListener = AWTEventMulticaster.remove(hierarchyListener, l);
         removeListener(l);
      }
   }

   public synchronized HierarchyListener[] getHierarchyListeners() {
      return listenersOf(HierarchyListener.class, new HierarchyListener[0]);
   }

   public void addHierarchyBoundsListener(HierarchyBoundsListener l) {
      if (l == null) {
         return;
      }
      synchronized (this) {
         hierarchyBoundsListener = AWTEventMulticaster.add(hierarchyBoundsListener, l);
         addListener(l);
         newEventsOnly = true;
      }
   }

   public void removeHierarchyBoundsListener(HierarchyBoundsListener l) {
      if (l == null) {
         return;
      }
      synchronized (this) {
         hierarchyBoundsListener = AWTEventMulticaster.remove(hierarchyBoundsListener, l);
         removeListener(l);
      }
   }

   public synchronized HierarchyBoundsListener[] getHierarchyBoundsListeners() {
      return listenersOf(HierarchyBoundsListener.class, new HierarchyBoundsListener[0]);
   }

   public synchronized void addKeyListener(KeyListener l) {
      if (l == null) {
         return;
      }
      keyListener = AWTEventMulticaster.add(keyListener, l);
      addListener(l);
      newEventsOnly = true;
   }

   public synchronized void removeKeyListener(KeyListener l) {
      if (l == null) {
         return;
      }
      keyListener = AWTEventMulticaster.remove(keyListener, l);
      removeListener(l);
   }

   public synchronized KeyListener[] getKeyListeners() {
      return listenersOf(KeyListener.class, new KeyListener[0]);
   }

   public synchronized void addMouseListener(MouseListener l) {
      if (l == null) {
         return;
      }
      mouseListener = AWTEventMulticaster.add(mouseListener, l);
      addListener(l);
      newEventsOnly = true;
   }

   public synchronized void removeMouseListener(MouseListener l) {
      if (l == null) {
         return;
      }
      mouseListener = AWTEventMulticaster.remove(mouseListener, l);
      removeListener(l);
   }

   public synchronized MouseListener[] getMouseListeners() {
      return listenersOf(MouseListener.class, new MouseListener[0]);
   }

   public synchronized void addMouseMotionListener(MouseMotionListener l) {
      if (l == null) {
         return;
      }
      mouseMotionListener = AWTEventMulticaster.add(mouseMotionListener, l);
      addListener(l);
      newEventsOnly = true;
   }

   public synchronized void removeMouseMotionListener(MouseMotionListener l) {
      if (l == null) {
         return;
      }
      mouseMotionListener = AWTEventMulticaster.remove(mouseMotionListener, l);
      removeListener(l);
   }

   public synchronized MouseMotionListener[] getMouseMotionListeners() {
      return listenersOf(MouseMotionListener.class, new MouseMotionListener[0]);
   }

   public synchronized void addMouseWheelListener(MouseWheelListener l) {
      if (l == null) {
         return;
      }
      mouseWheelListener = AWTEventMulticaster.add(mouseWheelListener, l);
      addListener(l);
      newEventsOnly = true;
   }

   public synchronized void removeMouseWheelListener(MouseWheelListener l) {
      if (l == null) {
         return;
      }
      mouseWheelListener = AWTEventMulticaster.remove(mouseWheelListener, l);
      removeListener(l);
   }

   public synchronized MouseWheelListener[] getMouseWheelListeners() {
      return listenersOf(MouseWheelListener.class, new MouseWheelListener[0]);
   }

   public synchronized void addInputMethodListener(InputMethodListener l) {
      if (l == null) {
         return;
      }
      inputMethodListener = AWTEventMulticaster.add(inputMethodListener, l);
      addListener(l);
      newEventsOnly = true;
   }

   public synchronized void removeInputMethodListener(InputMethodListener l) {
      if (l == null) {
         return;
      }
      inputMethodListener = AWTEventMulticaster.remove(inputMethodListener, l);
      removeListener(l);
   }

   public synchronized InputMethodListener[] getInputMethodListeners() {
      return listenersOf(InputMethodListener.class, new InputMethodListener[0]);
   }

   @SuppressWarnings("unchecked")
   public <T extends EventListener> T[] getListeners(Class<T> listenerType) {
      synchronized (listeners) {
         ArrayList<T> out = new ArrayList<T>();
         for (EventListener l : listeners) {
            if (listenerType.isInstance(l)) {
               out.add(listenerType.cast(l));
            }
         }
         return out.toArray((T[]) java.lang.reflect.Array.newInstance(listenerType, out.size()));
      }
   }

   // ---------------------------------------------------------------- peers and focus

   /** Makes the component displayable (the JDK creates its native peer here). */
   public void addNotify() {
      synchronized (LOCK) {
         displayable = true;
         valid = false;
         if (popups != null) {
            for (PopupMenu p : popups) {
               p.addNotify();
            }
         }
      }
   }

   public void removeNotify() {
      KeyboardFocusManager.getCurrentKeyboardFocusManager().componentRemoved(this);
      synchronized (LOCK) {
         if (popups != null) {
            for (PopupMenu p : popups) {
               p.removeNotify();
            }
         }
         displayable = false;
         valid = false;
      }
      WindowSystem.componentRemoved(this);
   }

   public boolean isFocusTraversable() {
      return isFocusable();
   }

   public boolean isFocusable() {
      return focusable && acceptsFocus();
   }

   /** Whether the control takes the keyboard focus at all (labels do not). */
   boolean acceptsFocus() {
      return true;
   }

   /** Whether Tab stops here: the controls (buttons, fields, lists...), not panels or canvases. */
   boolean traversable() {
      return false;
   }

   public void setFocusable(boolean focusable) {
      this.focusable = focusable;
   }

   public void setFocusTraversalKeysEnabled(boolean focusTraversalKeysEnabled) {
      this.focusTraversalKeysEnabled = focusTraversalKeysEnabled;
   }

   public boolean getFocusTraversalKeysEnabled() {
      return focusTraversalKeysEnabled;
   }

   boolean focusTraversalKeysEnabled = true;

   public void requestFocus() {
      KeyboardFocusManager.getCurrentKeyboardFocusManager().requestFocus(this, false);
   }

   public boolean requestFocusInWindow() {
      return KeyboardFocusManager.getCurrentKeyboardFocusManager().requestFocus(this, true);
   }

   public void transferFocus() {
      nextFocus();
   }

   public void nextFocus() {
      KeyboardFocusManager.getCurrentKeyboardFocusManager().focusNextComponent(this);
   }

   public void transferFocusBackward() {
      KeyboardFocusManager.getCurrentKeyboardFocusManager().focusPreviousComponent(this);
   }

   public boolean hasFocus() {
      return isFocusOwner();
   }

   public boolean isFocusOwner() {
      return KeyboardFocusManager.getCurrentKeyboardFocusManager().getFocusOwner() == this;
   }

   public synchronized void add(PopupMenu popup) {
      if (popup.parent != null) {
         popup.parent.remove(popup);
      }
      if (popups == null) {
         popups = new ArrayList<PopupMenu>();
      }
      popups.add(popup);
      popup.parent = this;
      if (displayable) {
         popup.addNotify();
      }
   }

   public synchronized void remove(MenuComponent popup) {
      if (popups != null && popups.remove(popup)) {
         popup.removeNotify();
         popup.parent = null;
      }
   }

   // ---------------------------------------------------------------- misc

   protected String paramString() {
      String thisName = getName();
      String str = (thisName != null ? thisName : "") + "," + x + "," + y + "," + width + "x" + height;
      if (!isValid()) {
         str += ",invalid";
      }
      if (!visible) {
         str += ",hidden";
      }
      if (!enabled) {
         str += ",disabled";
      }
      return str;
   }

   public String toString() {
      return getClass().getName() + "[" + paramString() + "]";
   }

   public void list() {
      list(System.out, 0);
   }

   public void list(java.io.PrintStream out) {
      list(out, 0);
   }

   public void list(java.io.PrintStream out, int indent) {
      for (int i = 0; i < indent; i++) {
         out.print(" ");
      }
      out.println(this);
   }

   public void list(java.io.PrintWriter out, int indent) {
      for (int i = 0; i < indent; i++) {
         out.print(" ");
      }
      out.println(this);
   }

   public void applyComponentOrientation(ComponentOrientation o) {
   }

   public void setComponentOrientation(ComponentOrientation o) {
   }

   public ComponentOrientation getComponentOrientation() {
      return ComponentOrientation.LEFT_TO_RIGHT;
   }
}
