package java.awt;

/**
 * The look of the native controls the 2004 client had: Windows' classic
 * style (the JRE 1.4 that came with it used no visual styles). Colours,
 * 3D borders, window decorations and the mouse pointer.
 */
final class Theme {
   private Theme() {
   }

   static final Color CONTROL = new Color(0xD4, 0xD0, 0xC8);
   static final Color HIGHLIGHT = Color.white;
   static final Color LIGHT = new Color(0xD4, 0xD0, 0xC8);
   static final Color SHADOW = new Color(0x80, 0x80, 0x80);
   static final Color DARK_SHADOW = new Color(0x40, 0x40, 0x40);
   static final Color WINDOW = Color.white;
   static final Color TEXT = Color.black;
   static final Color DISABLED_TEXT = new Color(0x80, 0x80, 0x80);
   static final Color SELECTION = new Color(0x0A, 0x24, 0x6A);
   static final Color SELECTION_TEXT = Color.white;
   static final Color SCROLL_TRACK = new Color(0xEC, 0xEA, 0xE6);
   static final Color TITLE_ACTIVE = new Color(0x0A, 0x24, 0x6A);
   static final Color TITLE_ACTIVE_END = new Color(0xA6, 0xCA, 0xF0);
   static final Color TITLE_INACTIVE = new Color(0x80, 0x80, 0x80);
   static final Color TITLE_INACTIVE_END = new Color(0xC0, 0xC0, 0xC0);

   /** AWT's default font on Windows in JRE 1.4: Dialog 12, which was Arial. */
   static final Font DIALOG_FONT = new Font("Dialog", Font.PLAIN, 12);
   static final Font TITLE_FONT = new Font("Dialog", Font.BOLD, 11);
   static final Font MENU_FONT = new Font("Dialog", Font.PLAIN, 12);

   static final int TITLE_HEIGHT = 18;
   static final int DIALOG_BORDER = 3;
   static final int MENUBAR_HEIGHT = 19;
   static final int SCROLLBAR = 16;

   static final int HIT_NONE = 0;
   static final int HIT_TITLE = 1;
   static final int HIT_CLOSE = 2;
   static final int HIT_MENUBAR = 3;

   static Color windowBackground(Window w) {
      return CONTROL;
   }

   static boolean hasTitle(Window w) {
      return w instanceof Dialog && !((Dialog) w).undecorated;
   }

   static int menuBarTop(Window w) {
      return hasTitle(w) ? DIALOG_BORDER + TITLE_HEIGHT + 1 : 0;
   }

   static Insets decorationInsets(Window w) {
      if (hasTitle(w)) {
         return new Insets(DIALOG_BORDER + TITLE_HEIGHT + 1, DIALOG_BORDER, DIALOG_BORDER, DIALOG_BORDER);
      }
      if (w instanceof Frame && !((Frame) w).undecorated && ((Frame) w).menuBar != null) {
         return new Insets(MENUBAR_HEIGHT, 0, 0, 0);
      }
      return new Insets(0, 0, 0, 0);
   }

   static int decorationHit(Window w, int x, int y) {
      if (hasTitle(w)) {
         int top = DIALOG_BORDER;
         if (y >= top && y < top + TITLE_HEIGHT && x >= DIALOG_BORDER && x < w.width - DIALOG_BORDER) {
            Rectangle close = closeBox(w);
            return close.contains(x, y) ? HIT_CLOSE : HIT_TITLE;
         }
      }
      if (w instanceof Frame && ((Frame) w).menuBar != null && !((Frame) w).undecorated) {
         int top = menuBarTop(w);
         if (y >= top && y < top + MENUBAR_HEIGHT) {
            return HIT_MENUBAR;
         }
      }
      return HIT_NONE;
   }

   private static Rectangle closeBox(Window w) {
      return new Rectangle(w.width - DIALOG_BORDER - 2 - 16, DIALOG_BORDER + 2, 16, 14);
   }

   /** The frame of a dialog, its title bar and a frame's menu bar (Window.paintPeer). */
   static void paintDecorations(Window w, Graphics g) {
      int width = w.width;
      int height = w.height;
      Color bg = w.getBackground();
      if (hasTitle(w)) {
         // the raised frame
         g.setColor(LIGHT);
         g.drawLine(0, 0, width - 2, 0);
         g.drawLine(0, 0, 0, height - 2);
         g.setColor(HIGHLIGHT);
         g.drawLine(1, 1, width - 3, 1);
         g.drawLine(1, 1, 1, height - 3);
         g.setColor(DARK_SHADOW);
         g.drawLine(0, height - 1, width - 1, height - 1);
         g.drawLine(width - 1, 0, width - 1, height - 1);
         g.setColor(SHADOW);
         g.drawLine(1, height - 2, width - 2, height - 2);
         g.drawLine(width - 2, 1, width - 2, height - 2);
         g.setColor(CONTROL);
         g.drawRect(2, 2, width - 5, height - 5);
         // the title bar
         boolean activeWindow = w.isActive();
         Color a = activeWindow ? TITLE_ACTIVE : TITLE_INACTIVE;
         Color b = activeWindow ? TITLE_ACTIVE_END : TITLE_INACTIVE_END;
         int tx = DIALOG_BORDER;
         int ty = DIALOG_BORDER;
         int tw = width - 2 * DIALOG_BORDER;
         for (int i = 0; i < tw; i++) {
            int r = a.getRed() + (b.getRed() - a.getRed()) * i / Math.max(1, tw - 1);
            int gg = a.getGreen() + (b.getGreen() - a.getGreen()) * i / Math.max(1, tw - 1);
            int bb = a.getBlue() + (b.getBlue() - a.getBlue()) * i / Math.max(1, tw - 1);
            g.setColor(new Color(r, gg, bb));
            g.drawLine(tx + i, ty, tx + i, ty + TITLE_HEIGHT - 1);
         }
         g.setColor(CONTROL);
         g.drawLine(tx, ty + TITLE_HEIGHT, tx + tw - 1, ty + TITLE_HEIGHT);
         String title = w instanceof Dialog ? ((Dialog) w).getTitle() : "";
         g.setFont(TITLE_FONT);
         FontMetrics fm = g.getFontMetrics();
         g.setColor(activeWindow ? Color.white : CONTROL);
         Rectangle close = closeBox(w);
         Graphics tg = g.create(tx + 3, ty, close.x - tx - 6, TITLE_HEIGHT);
         tg.drawString(title == null ? "" : title, 0, (TITLE_HEIGHT - fm.getHeight()) / 2 + fm.getAscent());
         tg.dispose();
         paintButtonFace(g, close.x, close.y, close.width, close.height, false);
         g.setColor(Color.black);
         int cx = close.x + 4;
         int cy = close.y + 3;
         for (int i = 0; i < 7; i++) {
            g.drawLine(cx + i, cy + i, cx + i + 1, cy + i);
            g.drawLine(cx + 6 - i, cy + i, cx + 7 - i, cy + i);
         }
      }
      if (w instanceof Frame && !((Frame) w).undecorated && ((Frame) w).menuBar != null) {
         int top = menuBarTop(w);
         g.setColor(CONTROL);
         g.fillRect(0, top, width, MENUBAR_HEIGHT);
         MenuWindow.paintMenuBar((Frame) w, g, top);
      }
      if (bg != null) {
         g.setColor(w.getForeground());
      }
   }

   static void paintButtonFace(Graphics g, int x, int y, int w, int h, boolean pressed) {
      g.setColor(CONTROL);
      g.fillRect(x, y, w, h);
      if (pressed) {
         g.setColor(DARK_SHADOW);
         g.drawRect(x, y, w - 1, h - 1);
         g.setColor(SHADOW);
         g.drawRect(x + 1, y + 1, w - 3, h - 3);
      } else {
         raised(g, x, y, w, h);
      }
   }

   /** Windows' raised 3D edge (EDGE_RAISED). */
   static void raised(Graphics g, int x, int y, int w, int h) {
      g.setColor(HIGHLIGHT);
      g.drawLine(x, y, x + w - 2, y);
      g.drawLine(x, y, x, y + h - 2);
      g.setColor(DARK_SHADOW);
      g.drawLine(x, y + h - 1, x + w - 1, y + h - 1);
      g.drawLine(x + w - 1, y, x + w - 1, y + h - 1);
      g.setColor(LIGHT);
      g.drawLine(x + 1, y + 1, x + w - 3, y + 1);
      g.drawLine(x + 1, y + 1, x + 1, y + h - 3);
      g.setColor(SHADOW);
      g.drawLine(x + 1, y + h - 2, x + w - 2, y + h - 2);
      g.drawLine(x + w - 2, y + 1, x + w - 2, y + h - 2);
   }

   /** Windows' sunken 3D edge (EDGE_SUNKEN): text fields, lists, check boxes. */
   static void sunken(Graphics g, int x, int y, int w, int h) {
      g.setColor(SHADOW);
      g.drawLine(x, y, x + w - 2, y);
      g.drawLine(x, y, x, y + h - 2);
      g.setColor(HIGHLIGHT);
      g.drawLine(x, y + h - 1, x + w - 1, y + h - 1);
      g.drawLine(x + w - 1, y, x + w - 1, y + h - 1);
      g.setColor(DARK_SHADOW);
      g.drawLine(x + 1, y + 1, x + w - 3, y + 1);
      g.drawLine(x + 1, y + 1, x + 1, y + h - 3);
      g.setColor(LIGHT);
      g.drawLine(x + 1, y + h - 2, x + w - 2, y + h - 2);
      g.drawLine(x + w - 2, y + 1, x + w - 2, y + h - 2);
   }

   /** The dotted rectangle of the focused control. */
   static void focusRect(Graphics g, int x, int y, int w, int h) {
      g.setColor(Color.black);
      for (int i = x; i < x + w; i += 2) {
         g.drawLine(i, y, i, y);
         g.drawLine(i, y + h - 1, i, y + h - 1);
      }
      for (int j = y; j < y + h; j += 2) {
         g.drawLine(x, j, x, j);
         g.drawLine(x + w - 1, j, x + w - 1, j);
      }
   }

   static final int UP = 0;
   static final int DOWN = 1;
   static final int LEFT = 2;
   static final int RIGHT = 3;

   /** A small solid triangle (scroll bar and choice arrows), centred in the box. */
   static void arrow(Graphics g, int x, int y, int w, int h, int direction, Color c) {
      g.setColor(c);
      int size = Math.max(2, Math.min(4, Math.min(w, h) / 4));
      int cx = x + w / 2;
      int cy = y + h / 2;
      for (int i = 0; i < size; i++) {
         switch (direction) {
            case UP:
               g.drawLine(cx - i, cy - size / 2 + i, cx + i, cy - size / 2 + i);
               break;
            case DOWN:
               g.drawLine(cx - (size - 1 - i), cy - size / 2 + i, cx + (size - 1 - i), cy - size / 2 + i);
               break;
            case LEFT:
               g.drawLine(cx - size / 2 + i, cy - i, cx - size / 2 + i, cy + i);
               break;
            default:
               g.drawLine(cx - size / 2 + i, cy - (size - 1 - i), cx - size / 2 + i, cy + (size - 1 - i));
         }
      }
   }

   /** Disabled text: embossed, as Windows drew it. */
   static void disabledString(Graphics g, String s, int x, int y) {
      g.setColor(HIGHLIGHT);
      g.drawString(s, x + 1, y + 1);
      g.setColor(SHADOW);
      g.drawString(s, x, y);
   }

   private static final String[] ARROW = {
         "X           ",
         "XX          ",
         "X.X         ",
         "X..X        ",
         "X...X       ",
         "X....X      ",
         "X.....X     ",
         "X......X    ",
         "X.......X   ",
         "X........X  ",
         "X.....XXXXX ",
         "X..X..X     ",
         "X.X X..X    ",
         "XX  X..X    ",
         "X    X..X   ",
         "     X..X   ",
         "      XX    "};

   /** The arrow pointer, drawn by us when the screen has no cursor of its own (the Vita's stick). */
   static void drawCursor(int[] screen, int sw, int sh, int px, int py, Rectangle clip) {
      for (int row = 0; row < ARROW.length; row++) {
         int y = py + row;
         if (y < clip.y || y >= clip.y + clip.height || y >= sh) {
            continue;
         }
         String line = ARROW[row];
         for (int col = 0; col < line.length(); col++) {
            int x = px + col;
            if (x < clip.x || x >= clip.x + clip.width || x >= sw) {
               continue;
            }
            char ch = line.charAt(col);
            if (ch == 'X') {
               screen[y * sw + x] = 0xFF000000;
            } else if (ch == '.') {
               screen[y * sw + x] = 0xFFFFFFFF;
            }
         }
      }
   }
}
