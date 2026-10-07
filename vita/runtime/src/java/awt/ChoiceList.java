package java.awt;

import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;

/**
 * A Choice's open list (the drop-down list box of Windows' combo box):
 * under the field (over it if there is no room), at most eight rows and a
 * scroll bar for more, the row under the pointer highlighted. A release on
 * a row chooses it; a press outside, or on the field, closes the list.
 * Runs under {@link PopupWindow#POPUP} (see there): it only reads the
 * Choice's items, never takes its lock.
 */
final class ChoiceList extends PopupWindow {
   /** Rows shown before the list scrolls. */
   static final int MAX_ROWS = 8;

   final Choice choice;
   private int hot;
   private int top;
   private int rows;
   private int rowHeight;
   private boolean hasBar;
   private final ScrollState bar = new ScrollState(true);
   private int barPressed;
   private boolean draggingThumb;
   private int dragOffset;

   private ChoiceList(Choice choice) {
      this.choice = choice;
   }

   static void open(Choice c) {
      synchronized (POPUP) {
         closeAllLocked();
         if (!c.isShowing() || c.pItems.size() == 0) {
            return;
         }
         ChoiceList l = new ChoiceList(c);
         l.invoker = c.windowAncestor();
         l.hot = c.selectedIndex;
         Rectangle b = l.place();
         l.scrollTo(l.hot);
         l.popUp(b.x, b.y, b.width, b.height);
      }
      c.repaint();
   }

   static boolean isOpenFor(Choice c) {
      if (!anyOpen()) {
         return false;
      }
      synchronized (POPUP) {
         PopupWindow r = root();
         return r instanceof ChoiceList && ((ChoiceList) r).choice == c;
      }
   }

   /** The items changed while open: measured again, or closed if there is nothing left. */
   static void choiceChanged(Choice c) {
      if (!anyOpen()) {
         return;
      }
      synchronized (POPUP) {
         PopupWindow r = root();
         if (r instanceof ChoiceList && ((ChoiceList) r).choice == c) {
            r.contentChanged();
         }
      }
   }

   /** The next item after from (around the end) whose first letter is c, as a list box's type-ahead. */
   static int nextStartingWith(Choice choice, int from, char c) {
      int n = choice.pItems.size();
      char lc = Character.toLowerCase(c);
      for (int k = 1; k <= n; k++) {
         int i = ((from < 0 ? -1 : from) + k) % n;
         String s;
         try {
            s = choice.pItems.elementAt(i);
         } catch (ArrayIndexOutOfBoundsException e) {
            return -1;
         }
         if (s.length() > 0 && Character.toLowerCase(s.charAt(0)) == lc) {
            return i;
         }
      }
      return -1;
   }

   private int count() {
      return choice.pItems.size();
   }

   private String itemText(int i) {
      try {
         String s = choice.pItems.elementAt(i);
         return s == null ? "" : s;
      } catch (ArrayIndexOutOfBoundsException e) {
         return "";
      }
   }

   private FontMetrics metrics() {
      Font f = choice.getFont();
      return Toolkit.getDefaultToolkit().getFontMetrics(f != null ? f : Theme.DIALOG_FONT);
   }

   /** The list's bounds on the screen: the field's width, under the field or over it. */
   private Rectangle place() {
      int n = count();
      rowHeight = Math.max(1, metrics().getHeight());
      rows = Math.min(n, MAX_ROWS);
      hasBar = n > MAX_ROWS;
      Rectangle f = choice.fieldBounds();
      Point o = choice.locationOnScreen();
      Dimension screen = screenSize();
      int w = Math.max(f.width, 1);
      int h = rows * rowHeight + 2;
      int below = screen.height - (o.y + f.y + f.height);
      int above = o.y + f.y;
      if (h > below && h > above) {
         // what fits on the larger side
         int room = Math.max(below, above);
         rows = Math.max(1, (room - 2) / rowHeight);
         hasBar = n > rows;
         h = rows * rowHeight + 2;
      }
      int y = h <= below ? o.y + f.y + f.height : o.y + f.y - h;
      int x = Math.max(0, Math.min(o.x + f.x, screen.width - w));
      bar.set(top, rows, 0, Math.max(n, rows));
      return new Rectangle(x, Math.max(0, y), w, h);
   }

   void contentChanged() {
      if (count() == 0) {
         popDown();
         return;
      }
      if (hot >= count()) {
         hot = count() - 1;
      }
      Rectangle b = place();
      scrollTo(Math.max(0, hot));
      moveTo(b.x, b.y, b.width, b.height);
   }

   void closed() {
      Repeater.stop();
      choice.repaint();
   }

   private void scrollTo(int i) {
      int n = count();
      if (i < top) {
         top = i;
      } else if (i >= top + rows) {
         top = i - rows + 1;
      }
      top = Math.max(0, Math.min(top, n - rows));
      bar.set(top, rows, 0, Math.max(n, rows));
   }

   private void setHot(int i) {
      if (i == hot) {
         return;
      }
      hot = i;
      if (i >= 0) {
         scrollTo(i);
      }
      paintSelf();
   }

   private int rowAt(int lx, int ly) {
      int listWidth = width - 2 - (hasBar ? Theme.SCROLLBAR : 0);
      if (lx < 1 || lx >= 1 + listWidth || ly < 1 || ly >= height - 1) {
         return -1;
      }
      int i = top + (ly - 1) / rowHeight;
      return i < count() ? i : -1;
   }

   private boolean onBar(int lx, int ly) {
      return hasBar && lx >= width - 1 - Theme.SCROLLBAR && lx < width - 1 && ly >= 1 && ly < height - 1;
   }

   private void choose(int i) {
      Choice c = choice;
      popDown();
      if (i >= 0) {
         // ⚠️ VERIFY: a click on the selected row sends CBN_SELCHANGE (an ItemEvent) again, as assumed here
         c.userSelected(i);
      }
   }

   void rootPointer(PopupWindow at, int id, int sx, int sy, int button, int modifiers, long when) {
      int lx = sx - x;
      int ly = sy - y;
      if (draggingThumb) {
         if (id == MouseEvent.MOUSE_RELEASED) {
            draggingThumb = false;
            barPressed = ScrollState.NONE;
            paintSelf();
         } else if (id == MouseEvent.MOUSE_MOVED) {
            int v = bar.valueAt(ly - 1 - dragOffset, height - 2);
            if (v != top) {
               top = v;
               bar.set(top, rows, 0, Math.max(count(), rows));
               paintSelf();
            }
         }
         return;
      }
      if (at != this) {
         if (id == MouseEvent.MOUSE_PRESSED) {
            // on the field too: the press closes the list (and the field does not see it)
            popDown();
         }
         if (id == MouseEvent.MOUSE_RELEASED) {
            stopBar();
         }
         return;
      }
      if (onBar(lx, ly)) {
         if (id == MouseEvent.MOUSE_PRESSED) {
            pressBar(ly - 1);
         } else if (id == MouseEvent.MOUSE_RELEASED) {
            stopBar();
         }
         return;
      }
      int i = rowAt(lx, ly);
      switch (id) {
         case MouseEvent.MOUSE_MOVED:
         case MouseEvent.MOUSE_PRESSED:
            if (i >= 0) {
               setHot(i);
            }
            break;
         case MouseEvent.MOUSE_RELEASED:
            stopBar();
            if (i >= 0) {
               choose(i);
            }
            break;
         default:
      }
   }

   private void pressBar(int along) {
      int h = height - 2;
      int part = bar.hit(0, along, Theme.SCROLLBAR, h);
      barPressed = part;
      if (part == ScrollState.THUMB) {
         int[] t = bar.thumb(h);
         draggingThumb = true;
         dragOffset = along - t[0];
         paintSelf();
         return;
      }
      final int delta;
      switch (part) {
         case ScrollState.ARROW_DEC:
            delta = -1;
            break;
         case ScrollState.ARROW_INC:
            delta = 1;
            break;
         case ScrollState.TRACK_DEC:
            delta = -rows;
            break;
         case ScrollState.TRACK_INC:
            delta = rows;
            break;
         default:
            return;
      }
      Repeater.start(new Runnable() {
         public void run() {
            synchronized (POPUP) {
               if (isOpen() && barPressed != ScrollState.NONE) {
                  scrollBy(delta);
               }
            }
         }
      });
   }

   private void stopBar() {
      if (barPressed != ScrollState.NONE) {
         barPressed = ScrollState.NONE;
         Repeater.stop();
         paintSelf();
      }
   }

   private void scrollBy(int delta) {
      int n = count();
      int nt = Math.max(0, Math.min(n - rows, top + delta));
      if (nt != top) {
         top = nt;
         bar.set(top, rows, 0, Math.max(n, rows));
      }
      paintSelf();
   }

   void rootKey(boolean press, int keyCode, char keyChar, int modifiers) {
      if (!press) {
         return;
      }
      int n = count();
      switch (keyCode) {
         case KeyEvent.VK_UP:
            if ((modifiers & InputEvent.ALT_MASK) != 0) {
               choose(hot);
            } else {
               setHot(Math.max(0, hot - 1));
            }
            break;
         case KeyEvent.VK_DOWN:
            setHot(Math.min(n - 1, hot + 1));
            break;
         case KeyEvent.VK_PAGE_UP:
            setHot(Math.max(0, hot - rows + 1));
            break;
         case KeyEvent.VK_PAGE_DOWN:
            setHot(Math.min(n - 1, hot + rows - 1));
            break;
         case KeyEvent.VK_HOME:
            setHot(0);
            break;
         case KeyEvent.VK_END:
            setHot(n - 1);
            break;
         case KeyEvent.VK_ENTER:
         case KeyEvent.VK_F4:
            choose(hot);
            break;
         case KeyEvent.VK_ESCAPE:
         case KeyEvent.VK_TAB:
            popDown();
            break;
         default:
            if (keyChar > ' ' && keyChar != KeyEvent.CHAR_UNDEFINED) {
               int i = nextStartingWith(choice, hot, keyChar);
               if (i >= 0) {
                  setHot(i);
               }
            }
      }
   }

   void rootWheel(PopupWindow at, int rotation) {
      scrollBy(rotation * 3);
   }

   void paintPeer(Graphics g) {
      Color back = choice.fieldBackground();
      Color fore = choice.fieldForeground();
      g.setColor(Color.black);
      g.drawRect(0, 0, width - 1, height - 1);
      int listWidth = width - 2 - (hasBar ? Theme.SCROLLBAR : 0);
      Graphics lg = g.create(1, 1, listWidth, height - 2);
      try {
         lg.setColor(back);
         lg.fillRect(0, 0, listWidth, height - 2);
         FontMetrics fm = metrics();
         lg.setFont(fm.getFont());
         int n = count();
         for (int r = 0; r < rows && top + r < n; r++) {
            int i = top + r;
            int ry = r * rowHeight;
            if (i == hot) {
               lg.setColor(Theme.SELECTION);
               lg.fillRect(0, ry, listWidth, rowHeight);
               lg.setColor(Theme.SELECTION_TEXT);
            } else {
               lg.setColor(fore);
            }
            lg.drawString(itemText(i), 2, ry + fm.getAscent());
         }
      } finally {
         lg.dispose();
      }
      if (hasBar) {
         bar.paint(g, width - 1 - Theme.SCROLLBAR, 1, Theme.SCROLLBAR, height - 2, true, barPressed);
      }
   }
}
