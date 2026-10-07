package java.awt;

import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;

/**
 * An open menu: a menu bar's menu, a submenu or a PopupMenu, drawn as the
 * Windows peers drew them (owner-drawn items: the item's font, a check
 * column, the shortcut on the right, the system's submenu arrow) and run
 * as Windows' menu loop: hover selects and opens submenus, a release on an
 * item chooses it, a press outside closes every menu, the arrows, Enter and
 * Escape work the keyboard. A menu taller than the screen (the Vita's 544
 * lines) scrolls with arrows at its ends, as Windows' long menus did.
 *
 * Also draws the menu bar of a Frame (Window decorations) and opens its
 * menus. Everything here runs under {@link PopupWindow#POPUP}.
 */
final class MenuWindow extends PopupWindow {
   /** The 3D frame around a menu. */
   static final int BORDER = 3;
   /** SM_CXMENUCHECK: the check column on the left, the arrow column on the right. */
   static final int CHECK = 13;
   /** A separator: SM_CYMENU / 2. */
   static final int SEPARATOR = Theme.MENUBAR_HEIGHT / 2;
   static final int SCROLL_ARROW = 12;
   /** Room around a menu bar title. */
   static final int BAR_PAD = 6;

   /** The menu bar whose menu is open (its title is drawn selected), or null. */
   private static volatile Frame barFrame;
   private static volatile int barIndex = -1;

   final Menu menu;
   final MenuWindow parentMenu;
   MenuWindow child;
   int selected = -1;
   /** The first item shown when the menu scrolls. */
   int first;
   boolean scrolls;
   private int[] tops = new int[0];
   private int[] heights = new int[0];
   private int contentHeight;
   private int contentWidth;
   /** The root of a menu bar's menu. */
   private boolean isBarMenu;
   /** The pointer moved with a button down since the menus opened (a drag: a release outside closes them). */
   private boolean dragged;
   private int scrollingDir;

   private MenuWindow(Menu menu, MenuWindow parentMenu) {
      this.menu = menu;
      this.parentMenu = parentMenu;
   }

   // ------------------------------------------------------------- opening

   /** PopupMenu.show: the menu with its top left corner at this screen point (TPM_LEFTALIGN | TPM_TOPALIGN). */
   static MenuWindow showPopup(PopupMenu pm, Component origin, int sx, int sy) {
      synchronized (POPUP) {
         closeAllLocked();
         if (pm.getItemCount() == 0) {
            return null;
         }
         MenuWindow w = new MenuWindow(pm, null);
         w.invoker = origin.windowAncestor();
         w.measure();
         Dimension screen = screenSize();
         int ww = w.contentWidth + 2 * BORDER;
         int wh = w.fullHeight(screen.height);
         int x = sx;
         int y = sy;
         if (x + ww > screen.width) {
            x = sx - ww;
         }
         if (x < 0) {
            x = Math.max(0, screen.width - ww);
         }
         if (y + wh > screen.height) {
            y = sy - wh;
         }
         if (y < 0) {
            y = Math.max(0, screen.height - wh);
         }
         w.popUp(x, y, ww, wh);
         return w;
      }
   }

   /** A press on a frame's menu bar (input thread, no menu open): opens the menu under it. */
   static void menuBarPressed(Frame f, int wx, int wy) {
      synchronized (POPUP) {
         int i = barIndexAt(f, wx);
         if (i >= 0) {
            openBarMenu(f, i, false);
         }
      }
   }

   private static void openBarMenu(Frame f, int index, boolean selectFirst) {
      closeAllLocked();
      MenuBar mb = f.menuBar;
      if (mb == null || index < 0 || index >= mb.getMenuCount()) {
         return;
      }
      Menu m = mb.getMenu(index);
      if (!m.isEnabled() || m.getItemCount() == 0) {
         return;
      }
      int[] r = barItemBounds(f, index);
      MenuWindow w = new MenuWindow(m, null);
      w.invoker = f;
      w.isBarMenu = true;
      w.measure();
      Dimension screen = screenSize();
      int ww = w.contentWidth + 2 * BORDER;
      int x = f.x + r[0];
      int y = f.y + Theme.menuBarTop(f) + Theme.MENUBAR_HEIGHT;
      int wh = w.fullHeight(screen.height - y);
      if (x + ww > screen.width) {
         x = Math.max(0, screen.width - ww);
      }
      barFrame = f;
      barIndex = index;
      WindowSystem.decorationsChanged(f);
      w.popUp(x, y, ww, wh);
      if (selectFirst) {
         w.moveSelection(1);
      }
   }

   private void openChild(int i) {
      MenuItem mi = item(i);
      if (!(mi instanceof Menu)) {
         return;
      }
      Menu sub = (Menu) mi;
      if (child != null) {
         if (child.menu == sub && child.isOpen()) {
            return;
         }
         child.popDown();
         child = null;
      }
      if (!enabled(sub) || sub.getItemCount() == 0) {
         return;
      }
      MenuWindow c = new MenuWindow(sub, this);
      c.invoker = invoker;
      c.measure();
      Dimension screen = screenSize();
      int cw = c.contentWidth + 2 * BORDER;
      int ch = c.fullHeight(screen.height);
      int cx = x + width - BORDER;
      if (cx + cw > screen.width) {
         cx = Math.max(0, x - cw + BORDER);
      }
      int cy = y + itemY(i) - BORDER;
      if (cy + ch > screen.height) {
         cy = screen.height - ch;
      }
      if (cy < 0) {
         cy = 0;
      }
      child = c;
      c.popUp(cx, cy, cw, ch);
   }

   void closed() {
      Repeater.stop();
      if (parentMenu != null && parentMenu.child == this) {
         parentMenu.child = null;
      }
      if (isBarMenu) {
         Frame f = barFrame;
         barFrame = null;
         barIndex = -1;
         if (f != null) {
            WindowSystem.decorationsChanged(f);
         }
      }
   }

   // ------------------------------------------------------------- measuring

   private MenuItem item(int i) {
      try {
         return menu.getItem(i);
      } catch (ArrayIndexOutOfBoundsException e) {
         return null;
      }
   }

   private int count() {
      return Math.min(menu.getItemCount(), tops.length);
   }

   static FontMetrics metrics(MenuComponent mc) {
      Font f = mc.getFont();
      return Toolkit.getDefaultToolkit().getFontMetrics(f != null ? f : Theme.MENU_FONT);
   }

   private static String text(MenuItem mi) {
      String s = mi.getLabel();
      return s == null ? "" : s;
   }

   /** AwtMenuItem::MeasureItem: text height plus a third, the label, the check column and the shortcut. */
   private void measure() {
      int n = menu.getItemCount();
      tops = new int[n];
      heights = new int[n];
      int y = 0;
      int widest = 0;
      for (int i = 0; i < n; i++) {
         MenuItem mi = menu.getItem(i);
         int h;
         if (mi.isSeparator()) {
            h = SEPARATOR;
         } else {
            FontMetrics fm = metrics(mi);
            int fh = fm.getHeight();
            h = fh + fh / 3;
            int w = fm.stringWidth(text(mi)) + CHECK;
            MenuShortcut s = mi.getShortcut();
            if (s != null && !(mi instanceof Menu)) {
               w += fm.stringWidth(s.toString()) + CHECK;
            }
            widest = Math.max(widest, w);
         }
         tops[i] = y;
         heights[i] = h;
         y += h;
      }
      contentHeight = y;
      // the system's room for the submenu arrow
      contentWidth = widest + CHECK;
      if (selected >= n) {
         selected = -1;
      }
   }

   /** The window's height: all the items, or the room there is with scroll arrows. */
   private int fullHeight(int room) {
      int h = contentHeight + 2 * BORDER;
      scrolls = h > room;
      if (scrolls) {
         h = Math.max(2 * BORDER + 2 * SCROLL_ARROW + SEPARATOR, room);
      }
      if (!scrolls) {
         first = 0;
      }
      return h;
   }

   private int itemsTop() {
      return BORDER + (scrolls ? SCROLL_ARROW : 0);
   }

   private int itemsBottom() {
      return height - BORDER - (scrolls ? SCROLL_ARROW : 0);
   }

   /** The item's top in the window. */
   private int itemY(int i) {
      return itemsTop() + tops[i] - (scrolls ? tops[first] : 0);
   }

   private int itemAt(int lx, int ly) {
      if (lx < BORDER || lx >= width - BORDER || ly < itemsTop() || ly >= itemsBottom()) {
         return -1;
      }
      int n = count();
      for (int i = scrolls ? first : 0; i < n; i++) {
         int top = itemY(i);
         if (ly >= top && ly < top + heights[i]) {
            return i;
         }
      }
      return -1;
   }

   /** -1 over the up arrow, 1 over the down arrow, 0 elsewhere. */
   private int scrollArrowAt(int lx, int ly) {
      if (!scrolls || lx < 0 || lx >= width) {
         return 0;
      }
      if (ly >= BORDER && ly < BORDER + SCROLL_ARROW) {
         return -1;
      }
      if (ly >= height - BORDER - SCROLL_ARROW && ly < height - BORDER) {
         return 1;
      }
      return 0;
   }

   private boolean enabled(MenuItem mi) {
      // a disabled PopupMenu disables its items (IsDisabledAndPopup)
      return mi.isEnabled() && (!(menu instanceof PopupMenu) || menu.isEnabled());
   }

   void contentChanged() {
      measure();
      if (child != null && (child.parentIndex() < 0)) {
         child.popDown();
      }
      int ww = contentWidth + 2 * BORDER;
      Dimension screen = screenSize();
      int room = isBarMenu ? screen.height - y : screen.height;
      int wh = fullHeight(room);
      int nx = x;
      int ny = y;
      if (nx + ww > screen.width) {
         nx = Math.max(0, screen.width - ww);
      }
      if (ny + wh > screen.height) {
         ny = Math.max(0, screen.height - wh);
      }
      if (scrolls && first >= count()) {
         first = Math.max(0, count() - 1);
      }
      moveTo(nx, ny, ww, wh);
   }

   /** Which item of the parent menu opened this one, or -1 if it is gone. */
   private int parentIndex() {
      MenuWindow p = parentMenu;
      if (p == null) {
         return -1;
      }
      int n = p.menu.getItemCount();
      for (int i = 0; i < n; i++) {
         if (p.menu.getItem(i) == menu) {
            return i;
         }
      }
      return -1;
   }

   // ------------------------------------------------------------- selection

   private void select(int i) {
      if (i >= 0 && (item(i) == null || item(i).isSeparator())) {
         i = -1;
      }
      if (i == selected) {
         return;
      }
      selected = i;
      if (i >= 0) {
         ensureVisible(i);
      }
      paintSelf();
   }

   /** Up and Down: the next item that is not a separator (disabled ones too, as Windows), around the ends. */
   private void moveSelection(int dir) {
      int n = count();
      if (n == 0) {
         return;
      }
      int i = selected;
      for (int k = 0; k < n; k++) {
         i = i < 0 ? (dir > 0 ? 0 : n - 1) : (i + dir + n) % n;
         MenuItem mi = item(i);
         if (mi != null && !mi.isSeparator()) {
            select(i);
            return;
         }
      }
   }

   private void ensureVisible(int i) {
      if (!scrolls) {
         return;
      }
      int room = itemsBottom() - itemsTop();
      if (i < first) {
         first = i;
      }
      while (first < i && tops[i] + heights[i] - tops[first] > room) {
         first++;
      }
   }

   private void scrollBy(int dir) {
      if (!scrolls) {
         return;
      }
      int n = count();
      int room = itemsBottom() - itemsTop();
      int last = Math.max(0, n - 1);
      // the first item that still fills the window to the end
      int maxFirst = last;
      while (maxFirst > 0 && contentHeight - tops[maxFirst - 1] <= room) {
         maxFirst--;
      }
      int nf = Math.max(0, Math.min(maxFirst, first + dir));
      if (nf != first) {
         first = nf;
         paintSelf();
      }
   }

   private void startScrolling(final int dir) {
      if (scrollingDir == dir) {
         return;
      }
      scrollingDir = dir;
      Repeater.start(new Runnable() {
         public void run() {
            synchronized (POPUP) {
               if (isOpen() && scrollingDir == dir) {
                  scrollBy(dir);
               }
            }
         }
      });
   }

   private void stopScrolling() {
      if (scrollingDir != 0) {
         scrollingDir = 0;
         Repeater.stop();
      }
   }

   private MenuWindow deepest() {
      MenuWindow d = this;
      while (d.child != null && d.child.isOpen()) {
         d = d.child;
      }
      return d;
   }

   private void choose(MenuItem mi, long when, int modifiers) {
      closeAllLocked();
      mi.doMenuEvent(when, modifiers & (InputEvent.SHIFT_MASK | InputEvent.CTRL_MASK | InputEvent.META_MASK | InputEvent.ALT_MASK));
   }

   // ------------------------------------------------------------- input

   void rootPointer(PopupWindow at, int id, int sx, int sy, int button, int modifiers, long when) {
      boolean buttonDown = (modifiers & (InputEvent.BUTTON1_DOWN_MASK | InputEvent.BUTTON2_DOWN_MASK | InputEvent.BUTTON3_DOWN_MASK)) != 0;
      if (id == MouseEvent.MOUSE_MOVED && buttonDown) {
         dragged = true;
      }
      if (id == MouseEvent.MOUSE_PRESSED) {
         dragged = false;
      }
      if (at instanceof MenuWindow) {
         ((MenuWindow) at).pointerInside(id, sx - at.x, sy - at.y, modifiers, when);
         return;
      }
      for (PopupWindow p : openPopups()) {
         if (p instanceof MenuWindow) {
            ((MenuWindow) p).stopScrolling();
         }
      }
      Frame f = barFrame;
      if (isBarMenu && f != null && isMenuBarHit(f, sx, sy)) {
         int i = barIndexAt(f, sx - f.x);
         if (id == MouseEvent.MOUSE_PRESSED) {
            if (i == barIndex) {
               closeAllLocked();
            } else if (i >= 0) {
               openBarMenu(f, i, false);
            }
         } else if (id == MouseEvent.MOUSE_MOVED && i >= 0 && i != barIndex) {
            openBarMenu(f, i, false);
            dragged = buttonDown;
         }
         return;
      }
      if (id == MouseEvent.MOUSE_PRESSED || (id == MouseEvent.MOUSE_RELEASED && dragged)) {
         closeAllLocked();
         return;
      }
      if (id == MouseEvent.MOUSE_MOVED) {
         // off the menus: the deepest one shows no selection, unless it opened a submenu
         MenuWindow d = deepest();
         if (d.child == null) {
            d.select(-1);
         }
      }
   }

   private void pointerInside(int id, int lx, int ly, int modifiers, long when) {
      int arrow = scrollArrowAt(lx, ly);
      if (arrow != 0) {
         if (id != MouseEvent.MOUSE_RELEASED) {
            startScrolling(arrow);
         } else {
            stopScrolling();
         }
         return;
      }
      stopScrolling();
      int i = itemAt(lx, ly);
      switch (id) {
         case MouseEvent.MOUSE_MOVED:
         case MouseEvent.MOUSE_PRESSED:
            hover(i);
            break;
         case MouseEvent.MOUSE_RELEASED:
            if (i >= 0) {
               MenuItem mi = item(i);
               if (mi instanceof Menu) {
                  hover(i);
               } else if (mi != null && !mi.isSeparator() && enabled(mi)) {
                  choose(mi, when, modifiers);
               }
            }
            break;
         default:
      }
   }

   private void hover(int i) {
      if (i >= 0 && item(i) != null && item(i).isSeparator()) {
         i = -1;
      }
      if (i < 0) {
         if (child == null) {
            select(-1);
         }
         return;
      }
      select(i);
      MenuItem mi = item(i);
      if (child != null && child.menu != mi) {
         child.popDown();
         child = null;
      }
      if (mi instanceof Menu) {
         openChild(i);
      }
   }

   void rootKey(boolean press, int keyCode, char keyChar, int modifiers) {
      if (!press) {
         return;
      }
      MenuWindow d = deepest();
      MenuBar mb = barFrame != null ? barFrame.menuBar : null;
      int bars = mb != null && isBarMenu ? mb.getMenuCount() : 0;
      switch (keyCode) {
         case KeyEvent.VK_UP:
            d.moveSelection(-1);
            break;
         case KeyEvent.VK_DOWN:
            d.moveSelection(1);
            break;
         case KeyEvent.VK_RIGHT:
            if (d.selected >= 0 && d.item(d.selected) instanceof Menu && d.enabled(d.item(d.selected))) {
               d.openChild(d.selected);
               if (d.child != null) {
                  d.child.moveSelection(1);
               }
            } else if (bars > 0) {
               openBarMenu(barFrame, (barIndex + 1) % bars, true);
            }
            break;
         case KeyEvent.VK_LEFT:
            if (d.parentMenu != null) {
               d.popDown();
            } else if (bars > 0) {
               openBarMenu(barFrame, (barIndex - 1 + bars) % bars, true);
            }
            break;
         case KeyEvent.VK_ENTER:
         case KeyEvent.VK_SPACE:
            if (d.selected >= 0) {
               MenuItem mi = d.item(d.selected);
               if (mi instanceof Menu) {
                  d.openChild(d.selected);
                  if (d.child != null) {
                     d.child.moveSelection(1);
                  }
               } else if (mi != null && !mi.isSeparator() && d.enabled(mi)) {
                  choose(mi, System.currentTimeMillis(), modifiers);
               }
            }
            break;
         case KeyEvent.VK_ESCAPE:
            if (d.parentMenu != null) {
               d.popDown();
            } else {
               closeAllLocked();
            }
            break;
         case KeyEvent.VK_ALT:
         case KeyEvent.VK_F10:
            closeAllLocked();
            break;
         default:
      }
   }

   void rootWheel(PopupWindow at, int rotation) {
      if (at instanceof MenuWindow) {
         ((MenuWindow) at).scrollBy(rotation);
      }
   }

   // ------------------------------------------------------------- drawing

   void paintPeer(Graphics g) {
      g.setColor(Theme.CONTROL);
      g.fillRect(0, 0, width, height);
      windowEdge(g, 0, 0, width, height);
      int top = itemsTop();
      int bottom = itemsBottom();
      Graphics ig = g.create(BORDER, top, width - 2 * BORDER, bottom - top);
      try {
         int n = count();
         for (int i = scrolls ? first : 0; i < n; i++) {
            int iy = itemY(i) - top;
            if (iy >= bottom - top) {
               break;
            }
            MenuItem mi = item(i);
            if (mi != null) {
               paintItem(ig, mi, i == selected, 0, iy, width - 2 * BORDER, heights[i]);
            }
         }
      } finally {
         ig.dispose();
      }
      if (scrolls) {
         int n = count();
         boolean up = first > 0;
         boolean down = n > 0 && itemY(n - 1) + heights[n - 1] > bottom;
         Theme.arrow(g, BORDER, BORDER, width - 2 * BORDER, SCROLL_ARROW, Theme.UP, up ? Color.black : Theme.SHADOW);
         Theme.arrow(g, BORDER, height - BORDER - SCROLL_ARROW, width - 2 * BORDER, SCROLL_ARROW, Theme.DOWN,
               down ? Color.black : Theme.SHADOW);
      }
   }

   /** Windows' EDGE_RAISED around a menu. */
   static void windowEdge(Graphics g, int x, int y, int w, int h) {
      g.setColor(Theme.LIGHT);
      g.drawLine(x, y, x + w - 2, y);
      g.drawLine(x, y, x, y + h - 2);
      g.setColor(Theme.HIGHLIGHT);
      g.drawLine(x + 1, y + 1, x + w - 3, y + 1);
      g.drawLine(x + 1, y + 1, x + 1, y + h - 3);
      g.setColor(Theme.DARK_SHADOW);
      g.drawLine(x, y + h - 1, x + w - 1, y + h - 1);
      g.drawLine(x + w - 1, y, x + w - 1, y + h - 1);
      g.setColor(Theme.SHADOW);
      g.drawLine(x + 1, y + h - 2, x + w - 2, y + h - 2);
      g.drawLine(x + w - 2, y + 1, x + w - 2, y + h - 2);
   }

   /** AwtMenuItem::DrawSelf (and DrawSeparator) for an item of an open menu. */
   private void paintItem(Graphics g, MenuItem mi, boolean sel, int x, int y, int w, int h) {
      if (mi.isSeparator()) {
         int ly = y + h / 2;
         g.setColor(Theme.SHADOW);
         g.drawLine(x, ly, x + w - 1, ly);
         g.setColor(Theme.HIGHLIGHT);
         g.drawLine(x, ly + 1, x + w - 1, ly + 1);
         return;
      }
      boolean en = enabled(mi);
      Color back = sel ? Theme.SELECTION : Theme.CONTROL;
      Color fore = sel ? (en ? Theme.SELECTION_TEXT : Theme.DISABLED_TEXT) : (en ? Theme.TEXT : Theme.DISABLED_TEXT);
      g.setColor(back);
      g.fillRect(x, y, w, h);
      Font f = mi.getFont();
      g.setFont(f != null ? f : Theme.MENU_FONT);
      FontMetrics fm = g.getFontMetrics();
      String s = text(mi);
      int ty = y + (h - fm.getHeight()) / 2 + fm.getAscent();
      if (mi instanceof CheckboxMenuItem && ((CheckboxMenuItem) mi).getState()) {
         drawCheck(g, x, y, CHECK, h, fore);
      }
      int tx = x + CHECK;
      if (!en && !sel) {
         Theme.disabledString(g, s, tx, ty);
      } else {
         g.setColor(fore);
         g.drawString(s, tx, ty);
      }
      MenuShortcut sc = mi.getShortcut();
      if (sc != null && !(mi instanceof Menu)) {
         String ss = sc.toString();
         int sx = x + w - CHECK - fm.stringWidth(ss);
         if (!en && !sel) {
            Theme.disabledString(g, ss, sx, ty);
         } else {
            g.setColor(fore);
            g.drawString(ss, sx, ty);
         }
      }
      if (mi instanceof Menu) {
         Theme.arrow(g, x + w - CHECK, y, CHECK, h, Theme.RIGHT, fore);
      }
   }

   /** The menu check mark (DFCS_MENUCHECK), 7 by 7, centred in the check column. */
   private static final String[] CHECK_MARK = {
         "......X",
         ".....XX",
         "X...XXX",
         "XX.XXX.",
         "XXXXX..",
         ".XXX...",
         "..X...."};

   static void drawCheck(Graphics g, int x, int y, int w, int h, Color c) {
      g.setColor(c);
      int ox = x + (w - 7) / 2;
      int oy = y + (h - 7) / 2;
      for (int row = 0; row < CHECK_MARK.length; row++) {
         String line = CHECK_MARK[row];
         int start = -1;
         for (int col = 0; col <= line.length(); col++) {
            boolean on = col < line.length() && line.charAt(col) == 'X';
            if (on && start < 0) {
               start = col;
            } else if (!on && start >= 0) {
               g.drawLine(ox + start, oy + row, ox + col - 1, oy + row);
               start = -1;
            }
         }
      }
   }

   // ------------------------------------------------------------- the menu bar

   /** The bar's titles keep the default font if theirs is taller than the bar (4700350). */
   private static FontMetrics barMetrics(Menu m) {
      FontMetrics fm = metrics(m);
      if (fm.getHeight() > Theme.MENUBAR_HEIGHT) {
         fm = Toolkit.getDefaultToolkit().getFontMetrics(Theme.MENU_FONT);
      }
      return fm;
   }

   /** x and width of a title, in the frame's coordinates. */
   static int[] barItemBounds(Frame f, int index) {
      MenuBar mb = f.menuBar;
      int x = 0;
      if (mb == null) {
         return new int[]{0, 0};
      }
      int n = mb.getMenuCount();
      for (int i = 0; i < n && i <= index; i++) {
         Menu m = mb.getMenu(i);
         int w = barMetrics(m).stringWidth(text(m)) + 2 * BAR_PAD;
         if (i == index) {
            return new int[]{x, w};
         }
         x += w;
      }
      return new int[]{x, 0};
   }

   static int barIndexAt(Frame f, int wx) {
      MenuBar mb = f.menuBar;
      if (mb == null) {
         return -1;
      }
      int x = 0;
      int n = mb.getMenuCount();
      for (int i = 0; i < n; i++) {
         Menu m = mb.getMenu(i);
         int w = barMetrics(m).stringWidth(text(m)) + 2 * BAR_PAD;
         if (wx >= x && wx < x + w) {
            return i;
         }
         x += w;
      }
      return -1;
   }

   /** Whether a screen point is on the menu bar of this window. */
   static boolean isMenuBarHit(Window w, int sx, int sy) {
      return w instanceof Frame && Theme.decorationHit(w, sx - w.x, sy - w.y) == Theme.HIT_MENUBAR;
   }

   /** Theme.paintDecorations: the titles, the open menu's one selected (an owner-drawn top item). */
   static void paintMenuBar(Frame f, Graphics g, int top) {
      MenuBar mb = f.menuBar;
      if (mb == null) {
         return;
      }
      int n = mb.getMenuCount();
      int x = 0;
      Frame open = barFrame;
      int openIndex = barIndex;
      for (int i = 0; i < n; i++) {
         Menu m;
         try {
            m = mb.getMenu(i);
         } catch (ArrayIndexOutOfBoundsException e) {
            break;
         }
         FontMetrics fm = barMetrics(m);
         String s = text(m);
         int w = fm.stringWidth(s) + 2 * BAR_PAD;
         boolean sel = open == f && openIndex == i;
         boolean en = m.isEnabled();
         int h = Theme.MENUBAR_HEIGHT - 1;
         if (sel) {
            g.setColor(Theme.SELECTION);
            g.fillRect(x, top, w, h);
         }
         g.setFont(fm.getFont());
         int tx = x + (w - fm.stringWidth(s)) / 2;
         int ty = top + (h - fm.getHeight()) / 2 + fm.getAscent();
         if (!en && !sel) {
            Theme.disabledString(g, s, tx, ty);
         } else {
            g.setColor(sel ? (en ? Theme.SELECTION_TEXT : Theme.DISABLED_TEXT) : Theme.TEXT);
            g.drawString(s, tx, ty);
         }
         x += w;
      }
   }
}
