package java.awt;

import java.awt.event.AdjustmentEvent;
import java.awt.event.MouseEvent;
import java.awt.event.MouseWheelEvent;

/**
 * A container that scrolls its one child, as java.awt.ScrollPane (Windows'
 * scroll pane: a sunken edge and native scroll bars). The layout is the
 * JDK's; the scroll bars are drawn and worked here, with the JDK's unit
 * increment of one pixel. The child is clipped to the viewport (see
 * Component.visibleInWindow) and only found there (Container.childrenAt).
 */
public class ScrollPane extends Container {
   public static final int SCROLLBARS_AS_NEEDED = 0;
   public static final int SCROLLBARS_ALWAYS = 1;
   public static final int SCROLLBARS_NEVER = 2;

   private int scrollbarDisplayPolicy;
   private ScrollPaneAdjustable vAdjustable;
   private ScrollPaneAdjustable hAdjustable;
   private boolean wheelScrollingEnabled = true;
   /** Whether the native control shows each bar (decided when the child is resized, SB_AS_NEEDED). */
   private boolean vbarOn;
   private boolean hbarOn;
   private final ScrollState vState = new ScrollState(true);
   private final ScrollState hState = new ScrollState(false);
   private int barPressed = ScrollState.NONE;
   private boolean pressedVertical;
   private boolean dragging;
   private int dragOffset;

   private static int nameCounter;
   private static final int EDGE = 2;

   public ScrollPane() {
      this(SCROLLBARS_AS_NEEDED);
   }

   public ScrollPane(int scrollbarDisplayPolicy) {
      this.layoutMgr = null;
      this.width = 100;
      this.height = 100;
      switch (scrollbarDisplayPolicy) {
         case SCROLLBARS_NEVER:
         case SCROLLBARS_AS_NEEDED:
         case SCROLLBARS_ALWAYS:
            this.scrollbarDisplayPolicy = scrollbarDisplayPolicy;
            break;
         default:
            throw new IllegalArgumentException("illegal scrollbar display policy");
      }
      vAdjustable = new ScrollPaneAdjustable(this, Adjustable.VERTICAL);
      hAdjustable = new ScrollPaneAdjustable(this, Adjustable.HORIZONTAL);
   }

   String constructComponentName() {
      synchronized (ScrollPane.class) {
         return "scrollpane" + nameCounter++;
      }
   }

   /** A lightweight child goes in a Panel, as the JDK did (the native pane moved a child window). */
   private void addToPanel(Component comp, Object constraints, int index) {
      Panel child = new Panel();
      child.setLayout(new BorderLayout());
      child.add(comp);
      super.addImpl(child, constraints, index);
      validate();
   }

   protected final void addImpl(Component comp, Object constraints, int index) {
      synchronized (getTreeLock()) {
         if (getComponentCount() > 0) {
            remove(0);
         }
         if (index > 0) {
            throw new IllegalArgumentException("position greater than 0");
         }
         if (!comp.isLightweight()) {
            super.addImpl(comp, constraints, index);
         } else {
            addToPanel(comp, constraints, index);
         }
      }
   }

   public int getScrollbarDisplayPolicy() {
      return scrollbarDisplayPolicy;
   }

   /** The sunken edge, and the bars that are shown; nothing before the native control exists. */
   public Insets insets() {
      if (!displayable) {
         return new Insets(0, 0, 0, 0);
      }
      return new Insets(EDGE, EDGE, EDGE + (vbarOn ? Theme.SCROLLBAR : 0), EDGE + (hbarOn ? Theme.SCROLLBAR : 0));
   }

   public Dimension getViewportSize() {
      Insets i = getInsets();
      return new Dimension(width - i.right - i.left, height - i.top - i.bottom);
   }

   public int getHScrollbarHeight() {
      return scrollbarDisplayPolicy != SCROLLBARS_NEVER && displayable ? Theme.SCROLLBAR : 0;
   }

   public int getVScrollbarWidth() {
      return scrollbarDisplayPolicy != SCROLLBARS_NEVER && displayable ? Theme.SCROLLBAR : 0;
   }

   public Adjustable getVAdjustable() {
      return vAdjustable;
   }

   public Adjustable getHAdjustable() {
      return hAdjustable;
   }

   public void setScrollPosition(int x, int y) {
      synchronized (getTreeLock()) {
         if (getComponentCount() <= 0) {
            throw new NullPointerException("child is null");
         }
         hAdjustable.setValue(x);
         vAdjustable.setValue(y);
      }
   }

   public void setScrollPosition(Point p) {
      setScrollPosition(p.x, p.y);
   }

   public Point getScrollPosition() {
      if (getComponentCount() <= 0) {
         throw new NullPointerException("child is null");
      }
      return new Point(hAdjustable.getValue(), vAdjustable.getValue());
   }

   public final void setLayout(LayoutManager mgr) {
      throw new AWTError("ScrollPane controls layout");
   }

   public void doLayout() {
      layout();
   }

   /** The JDK's: the child's preferred size, at least the view (the bars it will need taken off). */
   Dimension calculateChildSize() {
      Dimension size = getSize();
      Insets insets = getInsets();
      int viewWidth = size.width - insets.left * 2;
      int viewHeight = size.height - insets.top * 2;
      boolean vbar;
      boolean hbar;
      Component child = getComponent(0);
      Dimension childSize = new Dimension(child.getPreferredSize());
      if (scrollbarDisplayPolicy == SCROLLBARS_AS_NEEDED) {
         vbar = childSize.height > viewHeight;
         hbar = childSize.width > viewWidth;
      } else if (scrollbarDisplayPolicy == SCROLLBARS_ALWAYS) {
         vbar = hbar = true;
      } else {
         vbar = hbar = false;
      }
      if (vbar) {
         viewWidth -= getVScrollbarWidth();
      }
      if (hbar) {
         viewHeight -= getHScrollbarHeight();
      }
      if (childSize.width < viewWidth) {
         childSize.width = viewWidth;
      }
      if (childSize.height < viewHeight) {
         childSize.height = viewHeight;
      }
      return childSize;
   }

   public void layout() {
      if (getComponentCount() > 0) {
         Component c = getComponent(0);
         Point p = getScrollPosition();
         Dimension cs = calculateChildSize();
         Insets i = getInsets();
         c.reshape(i.left - p.x, i.top - p.y, cs.width, cs.height);
         childResized(cs.width, cs.height);
         Dimension vs = getViewportSize();
         hAdjustable.setSpan(0, cs.width, vs.width);
         vAdjustable.setSpan(0, cs.height, vs.height);
         repaint();
      }
   }

   /** WScrollPanePeer.childResized: which bars Windows shows for a child this big. */
   private void childResized(int w, int h) {
      if (!displayable) {
         return;
      }
      if (scrollbarDisplayPolicy == SCROLLBARS_ALWAYS) {
         vbarOn = hbarOn = true;
      } else if (scrollbarDisplayPolicy == SCROLLBARS_NEVER) {
         vbarOn = hbarOn = false;
      } else {
         int vw = width - 2 * EDGE;
         int vh = height - 2 * EDGE;
         boolean v = h > vh;
         boolean hb = w > vw;
         if (v && !hb) {
            hb = w > vw - Theme.SCROLLBAR;
         }
         if (hb && !v) {
            v = h > vh - Theme.SCROLLBAR;
         }
         vbarOn = v;
         hbarOn = hb;
      }
   }

   /** The JDK's PeerFixer: the child follows the bar (here inside the edge, where the native child window was). */
   void adjustableMoved(ScrollPaneAdjustable adj, int value) {
      if (getComponentCount() <= 0) {
         return;
      }
      Component c = getComponent(0);
      Insets in = getInsets();
      if (adj.getOrientation() == Adjustable.VERTICAL) {
         c.move(c.x, in.top - value);
      } else {
         c.move(in.left - value, c.y);
      }
      repaint();
   }

   public void addNotify() {
      synchronized (getTreeLock()) {
         int vValue = 0;
         int hValue = 0;
         // bug 4124460 in the JDK: the values are kept over addNotify
         if (getComponentCount() > 0) {
            vValue = vAdjustable.getValue();
            hValue = hAdjustable.getValue();
            vAdjustable.setValue(0);
            hAdjustable.setValue(0);
         }
         super.addNotify();
         if (getComponentCount() > 0) {
            vAdjustable.setValue(vValue);
            hAdjustable.setValue(hValue);
         }
      }
   }

   public void setWheelScrollingEnabled(boolean handleWheel) {
      wheelScrollingEnabled = handleWheel;
   }

   public boolean isWheelScrollingEnabled() {
      return wheelScrollingEnabled;
   }

   public String paramString() {
      String sdpStr;
      switch (scrollbarDisplayPolicy) {
         case SCROLLBARS_AS_NEEDED:
            sdpStr = "as-needed";
            break;
         case SCROLLBARS_ALWAYS:
            sdpStr = "always";
            break;
         case SCROLLBARS_NEVER:
            sdpStr = "never";
            break;
         default:
            sdpStr = "invalid display policy";
      }
      Point p = getComponentCount() > 0 ? getScrollPosition() : new Point(0, 0);
      Insets i = getInsets();
      return super.paramString() + ",ScrollPosition=(" + p.x + "," + p.y + ")" + ",Insets=(" + i.top + "," + i.left + "," + i.bottom + ","
            + i.right + ")" + ",ScrollbarDisplayPolicy=" + sdpStr + ",wheelScrollingEnabled=" + isWheelScrollingEnabled();
   }

   // ------------------------------------------------------------- the native control

   /** Points over the edge or the bars are the pane's own, not the child's. */
   boolean childrenAt(int x, int y) {
      Insets i = getInsets();
      return x >= i.left && y >= i.top && x < width - i.right && y < height - i.bottom;
   }

   Rectangle viewport() {
      Insets i = getInsets();
      return new Rectangle(i.left, i.top, width - i.left - i.right, height - i.top - i.bottom);
   }

   boolean handlesWheel() {
      return wheelScrollingEnabled;
   }

   private Rectangle vBarBounds() {
      return new Rectangle(width - EDGE - Theme.SCROLLBAR, EDGE, Theme.SCROLLBAR, height - 2 * EDGE - (hbarOn ? Theme.SCROLLBAR : 0));
   }

   private Rectangle hBarBounds() {
      return new Rectangle(EDGE, height - EDGE - Theme.SCROLLBAR, width - 2 * EDGE - (vbarOn ? Theme.SCROLLBAR : 0), Theme.SCROLLBAR);
   }

   private void syncStates() {
      vState.set(vAdjustable.getValue(), vAdjustable.getVisibleAmount(), 0, vAdjustable.getMaximum());
      hState.set(hAdjustable.getValue(), hAdjustable.getVisibleAmount(), 0, hAdjustable.getMaximum());
   }

   void paintPeer(Graphics g) {
      Theme.sunken(g, 0, 0, width, height);
      syncStates();
      if (vbarOn) {
         Rectangle r = vBarBounds();
         vState.paint(g, r.x, r.y, r.width, r.height, enabled, pressedVertical ? barPressed : ScrollState.NONE);
      }
      if (hbarOn) {
         Rectangle r = hBarBounds();
         hState.paint(g, r.x, r.y, r.width, r.height, enabled, !pressedVertical ? barPressed : ScrollState.NONE);
      }
      if (vbarOn && hbarOn) {
         g.setColor(Theme.CONTROL);
         g.fillRect(width - EDGE - Theme.SCROLLBAR, height - EDGE - Theme.SCROLLBAR, Theme.SCROLLBAR, Theme.SCROLLBAR);
      }
   }

   void handlePeerEvent(AWTEvent e) {
      if (!enabled) {
         return;
      }
      switch (e.getID()) {
         case MouseEvent.MOUSE_PRESSED: {
            MouseEvent m = (MouseEvent) e;
            syncStates();
            Rectangle vb = vBarBounds();
            Rectangle hb = hBarBounds();
            if (vbarOn && vb.contains(m.getX(), m.getY())) {
               press(true, m.getY() - vb.y, vb.height);
            } else if (hbarOn && hb.contains(m.getX(), m.getY())) {
               press(false, m.getX() - hb.x, hb.width);
            }
            break;
         }
         case MouseEvent.MOUSE_DRAGGED:
            if (dragging) {
               MouseEvent m = (MouseEvent) e;
               ScrollPaneAdjustable adj = pressedVertical ? vAdjustable : hAdjustable;
               ScrollState st = pressedVertical ? vState : hState;
               Rectangle r = pressedVertical ? vBarBounds() : hBarBounds();
               int along = pressedVertical ? m.getY() - r.y : m.getX() - r.x;
               adj.setValueIsAdjusting(true);
               adj.setTypedValue(st.valueAt(along - dragOffset, pressedVertical ? r.height : r.width), AdjustmentEvent.TRACK);
            }
            break;
         case MouseEvent.MOUSE_RELEASED:
            Repeater.stop();
            if (dragging) {
               dragging = false;
               ScrollPaneAdjustable adj = pressedVertical ? vAdjustable : hAdjustable;
               adj.setValueIsAdjusting(false);
            }
            barPressed = ScrollState.NONE;
            repaint();
            break;
         case MouseEvent.MOUSE_WHEEL:
            wheel((MouseWheelEvent) e);
            break;
         default:
      }
   }

   private void press(boolean vertical, int along, int length) {
      pressedVertical = vertical;
      final ScrollState st = vertical ? vState : hState;
      final ScrollPaneAdjustable adj = vertical ? vAdjustable : hAdjustable;
      int part = vertical ? st.hit(0, along, Theme.SCROLLBAR, length) : st.hit(along, 0, length, Theme.SCROLLBAR);
      barPressed = part;
      if (part == ScrollState.THUMB) {
         dragging = true;
         dragOffset = along - st.thumb(length)[0];
         repaint();
         return;
      }
      final int type;
      switch (part) {
         case ScrollState.ARROW_DEC:
            type = AdjustmentEvent.UNIT_DECREMENT;
            break;
         case ScrollState.ARROW_INC:
            type = AdjustmentEvent.UNIT_INCREMENT;
            break;
         case ScrollState.TRACK_DEC:
            type = AdjustmentEvent.BLOCK_DECREMENT;
            break;
         case ScrollState.TRACK_INC:
            type = AdjustmentEvent.BLOCK_INCREMENT;
            break;
         default:
            return;
      }
      repaint();
      Repeater.start(new Runnable() {
         public void run() {
            if (barPressed == ScrollState.NONE) {
               return;
            }
            int v = adj.getValue();
            switch (type) {
               case AdjustmentEvent.UNIT_DECREMENT:
                  v -= adj.getUnitIncrement();
                  break;
               case AdjustmentEvent.UNIT_INCREMENT:
                  v += adj.getUnitIncrement();
                  break;
               case AdjustmentEvent.BLOCK_DECREMENT:
                  v -= adj.getBlockIncrement();
                  break;
               default:
                  v += adj.getBlockIncrement();
            }
            adj.setTypedValue(v, type);
         }
      });
   }

   /** The JDK's ScrollPaneWheelScroller: the vertical bar if shown, else the horizontal one. */
   private void wheel(MouseWheelEvent e) {
      if (e.getScrollAmount() == 0) {
         return;
      }
      ScrollPaneAdjustable adj = null;
      if (scrollbarDisplayPolicy == SCROLLBARS_AS_NEEDED) {
         if (vbarOn) {
            adj = vAdjustable;
         } else if (hbarOn) {
            adj = hAdjustable;
         }
      } else if (scrollbarDisplayPolicy == SCROLLBARS_ALWAYS) {
         adj = vAdjustable;
      }
      if (adj == null) {
         return;
      }
      int increment = e.getScrollType() == MouseWheelEvent.WHEEL_UNIT_SCROLL ? e.getUnitsToScroll() * adj.getUnitIncrement()
            : adj.getBlockIncrement() * e.getWheelRotation();
      int v = Math.max(adj.getMinimum(), Math.min(adj.getMaximum() - adj.getVisibleAmount(), adj.getValue() + increment));
      adj.setValue(v);
   }
}
