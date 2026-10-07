package java.awt;

import java.awt.event.MouseEvent;
import java.awt.event.MouseWheelEvent;
import java.util.ArrayList;

/**
 * Multi-line text, as java.awt.TextArea. Lines wrap at words when there is
 * no horizontal scroll bar (as the Windows edit control did); the scroll
 * bars a policy asks for are always shown, disabled when there is nothing
 * to scroll.
 */
public class TextArea extends TextComponent {
   public static final int SCROLLBARS_BOTH = 0;
   public static final int SCROLLBARS_VERTICAL_ONLY = 1;
   public static final int SCROLLBARS_HORIZONTAL_ONLY = 2;
   public static final int SCROLLBARS_NONE = 3;

   int rows;
   int columns;
   int scrollbarVisibility;
   /** Each visual line: start and end offsets in the text. */
   private int[] lineStarts = new int[]{0};
   private int[] lineEnds = new int[]{0};
   private int topLine;
   private int scrollX;
   private final ScrollState vbar = new ScrollState(true);
   private final ScrollState hbar = new ScrollState(false);
   private int barPressed;
   private boolean vertPressed;
   private boolean dragging;
   private int dragOffset;

   public TextArea() {
      this("", 0, 0, SCROLLBARS_BOTH);
   }

   public TextArea(String text) {
      this(text, 0, 0, SCROLLBARS_BOTH);
   }

   public TextArea(int rows, int columns) {
      this("", rows, columns, SCROLLBARS_BOTH);
   }

   public TextArea(String text, int rows, int columns) {
      this(text, rows, columns, SCROLLBARS_BOTH);
   }

   public TextArea(String text, int rows, int columns, int scrollbars) {
      super(text);
      this.rows = Math.max(0, rows);
      this.columns = Math.max(0, columns);
      this.scrollbarVisibility = scrollbars >= SCROLLBARS_BOTH && scrollbars <= SCROLLBARS_NONE ? scrollbars : SCROLLBARS_BOTH;
   }

   public int getScrollbarVisibility() {
      return scrollbarVisibility;
   }

   boolean handlesWheel() {
      return hasV();
   }

   private boolean hasV() {
      return scrollbarVisibility == SCROLLBARS_BOTH || scrollbarVisibility == SCROLLBARS_VERTICAL_ONLY;
   }

   private boolean hasH() {
      return scrollbarVisibility == SCROLLBARS_BOTH || scrollbarVisibility == SCROLLBARS_HORIZONTAL_ONLY;
   }

   public void insert(String str, int pos) {
      insertText(str, pos);
   }

   public synchronized void insertText(String str, int pos) {
      replaceRange(str, pos, pos);
   }

   public void append(String str) {
      appendText(str);
   }

   public void appendText(String str) {
      boolean atEnd;
      synchronized (this) {
         atEnd = caret == text.length();
      }
      replaceRange(str, text.length(), text.length());
      if (atEnd) {
         setCaretPosition(text.length());
      }
   }

   public void replaceRange(String str, int start, int end) {
      replaceText(str, start, end);
   }

   public void replaceText(String str, int start, int end) {
      synchronized (this) {
         int len = text.length();
         start = Math.max(0, Math.min(start, len));
         end = Math.max(start, Math.min(end, len));
         String s = str == null ? "" : str;
         text = text.substring(0, start) + s + text.substring(end);
         int delta = s.length() - (end - start);
         if (caret >= end) {
            caret += delta;
         } else if (caret > start) {
            caret = start + s.length();
         }
         if (anchor >= end) {
            anchor += delta;
         } else if (anchor > start) {
            anchor = start + s.length();
         }
      }
      textChanged();
   }

   public int getRows() {
      return rows;
   }

   public void setRows(int rows) {
      this.rows = Math.max(0, rows);
      invalidate();
   }

   public int getColumns() {
      return columns;
   }

   public void setColumns(int columns) {
      this.columns = Math.max(0, columns);
      invalidate();
   }

   public Dimension getPreferredSize(int rows, int columns) {
      return preferredSize(rows, columns);
   }

   public Dimension preferredSize(int rows, int columns) {
      return minimumSize(rows, columns);
   }

   public Dimension getMinimumSize(int rows, int columns) {
      return minimumSize(rows, columns);
   }

   public Dimension minimumSize(int rows, int columns) {
      FontMetrics fm = getFontMetrics(getFont());
      return new Dimension(fm.charWidth('0') * columns + 20 + (hasV() ? Theme.SCROLLBAR : 0),
            fm.getHeight() * rows + 20 + (hasH() ? Theme.SCROLLBAR : 0));
   }

   Dimension peerMinimumSize() {
      return minimumSize(rows > 0 ? rows : 10, columns > 0 ? columns : 60);
   }

   private int textWidth() {
      return Math.max(1, width - 4 - 2 - (hasV() ? Theme.SCROLLBAR : 0));
   }

   private int textHeight() {
      return Math.max(1, height - 4 - (hasH() ? Theme.SCROLLBAR : 0));
   }

   private int lineHeight() {
      return Math.max(1, getFontMetrics(getFont()).getHeight());
   }

   int pageLines() {
      return Math.max(1, textHeight() / lineHeight());
   }

   void layoutText() {
      FontMetrics fm = getFontMetrics(getFont());
      ArrayList<int[]> lines = new ArrayList<int[]>();
      boolean wrap = !hasH();
      int maxW = textWidth();
      String t = text;
      int start = 0;
      int widest = 0;
      while (true) {
         int nl = t.indexOf('\n', start);
         int end = nl < 0 ? t.length() : nl;
         if (!wrap) {
            lines.add(new int[]{start, end});
            widest = Math.max(widest, fm.stringWidth(t.substring(start, end)));
         } else {
            int a = start;
            while (true) {
               int b = a;
               int w = 0;
               int lastSpace = -1;
               while (b < end) {
                  int cw = fm.charWidth(t.charAt(b));
                  if (w + cw > maxW && b > a) {
                     break;
                  }
                  if (t.charAt(b) == ' ') {
                     lastSpace = b;
                  }
                  w += cw;
                  b++;
               }
               if (b < end && lastSpace >= a) {
                  b = lastSpace + 1;
               }
               lines.add(new int[]{a, b});
               if (b >= end) {
                  break;
               }
               a = b;
            }
         }
         if (nl < 0) {
            break;
         }
         start = nl + 1;
      }
      int n = lines.size();
      int[] s = new int[n];
      int[] e = new int[n];
      for (int i = 0; i < n; i++) {
         s[i] = lines.get(i)[0];
         e[i] = lines.get(i)[1];
      }
      lineStarts = s;
      lineEnds = e;
      vbar.set(topLine, pageLines(), 0, Math.max(n, pageLines()));
      vbar.unit = 1;
      vbar.block = Math.max(1, pageLines() - 1);
      topLine = vbar.value;
      hbar.set(scrollX, maxW, 0, Math.max(widest + 4, maxW));
      hbar.unit = Math.max(1, fm.charWidth('0'));
      hbar.block = Math.max(1, maxW - 10);
      scrollX = hbar.value;
   }

   void boundsChanged(int oldX, int oldY, int oldW, int oldH, boolean resized, boolean moved) {
      if (resized) {
         layoutText();
      }
      super.boundsChanged(oldX, oldY, oldW, oldH, resized, moved);
   }

   public void setFont(Font f) {
      super.setFont(f);
      layoutText();
   }

   public void addNotify() {
      super.addNotify();
      layoutText();
   }

   private int lineOf(int offset) {
      int[] s = lineStarts;
      int[] e = lineEnds;
      for (int i = s.length - 1; i >= 0; i--) {
         if (offset >= s[i]) {
            if (offset > e[i] && i + 1 < s.length) {
               return i + 1;
            }
            return i;
         }
      }
      return 0;
   }

   void caretMoved() {
      int line = lineOf(caret);
      int page = pageLines();
      if (line < topLine) {
         topLine = line;
      } else if (line >= topLine + page) {
         topLine = line - page + 1;
      }
      vbar.value = vbar.clamp(topLine);
      topLine = vbar.value;
      if (hasH()) {
         FontMetrics fm = getFontMetrics(getFont());
         int ls = lineStarts[Math.min(line, lineStarts.length - 1)];
         int cx = fm.stringWidth(text.substring(ls, Math.min(caret, text.length())));
         int w = textWidth();
         if (cx - scrollX > w - 2) {
            scrollX = cx - w + 2;
         } else if (cx < scrollX) {
            scrollX = Math.max(0, cx - w / 4);
         }
         hbar.value = hbar.clamp(scrollX);
         scrollX = hbar.value;
      }
   }

   int offsetAt(int x, int y) {
      FontMetrics fm = getFontMetrics(getFont());
      int line = topLine + Math.max(0, (y - 2)) / lineHeight();
      if (line >= lineStarts.length) {
         return text.length();
      }
      int a = lineStarts[line];
      int b = lineEnds[line];
      int px = x - 3 + scrollX;
      int acc = 0;
      for (int i = a; i < b; i++) {
         int cw = fm.charWidth(text.charAt(i));
         if (px < acc + cw / 2) {
            return i;
         }
         acc += cw;
      }
      return b;
   }

   int verticalMove(int from, int lines) {
      FontMetrics fm = getFontMetrics(getFont());
      int line = lineOf(from);
      int x = fm.stringWidth(text.substring(lineStarts[line], Math.min(from, lineEnds[line])));
      int target = Math.max(0, Math.min(lineStarts.length - 1, line + lines));
      int a = lineStarts[target];
      int b = lineEnds[target];
      int acc = 0;
      for (int i = a; i < b; i++) {
         int cw = fm.charWidth(text.charAt(i));
         if (x < acc + cw / 2) {
            return i;
         }
         acc += cw;
      }
      return b;
   }

   void handlePeerEvent(AWTEvent e) {
      if (e instanceof MouseEvent && enabled) {
         MouseEvent m = (MouseEvent) e;
         int vx = width - 2 - Theme.SCROLLBAR;
         int hy = height - 2 - Theme.SCROLLBAR;
         boolean onV = hasV() && m.getX() >= vx && m.getY() >= 2 && m.getY() < height - 2 - (hasH() ? Theme.SCROLLBAR : 0);
         boolean onH = hasH() && m.getY() >= hy && m.getX() >= 2 && m.getX() < width - 2 - (hasV() ? Theme.SCROLLBAR : 0);
         switch (e.getID()) {
            case MouseEvent.MOUSE_PRESSED:
               if (onV || onH) {
                  pressBar(onV, onV ? m.getX() - vx : m.getX() - 2, onV ? m.getY() - 2 : m.getY() - hy);
                  return;
               }
               break;
            case MouseEvent.MOUSE_DRAGGED:
               if (dragging) {
                  ScrollState s = vertPressed ? vbar : hbar;
                  int along = (vertPressed ? m.getY() - 2 : m.getX() - 2) - dragOffset;
                  s.value = s.valueAt(along, vertPressed ? textHeight() : textWidth() + 2);
                  syncFromBars();
                  return;
               }
               if (barPressed != ScrollState.NONE) {
                  return;
               }
               break;
            case MouseEvent.MOUSE_RELEASED:
               if (barPressed != ScrollState.NONE || dragging) {
                  Repeater.stop();
                  barPressed = ScrollState.NONE;
                  dragging = false;
                  repaint();
                  return;
               }
               break;
            case MouseEvent.MOUSE_WHEEL:
               if (hasV()) {
                  vbar.value = vbar.clamp(vbar.value + ((MouseWheelEvent) e).getUnitsToScroll());
                  syncFromBars();
               }
               return;
            default:
         }
      }
      super.handlePeerEvent(e);
   }

   private void pressBar(final boolean vertical, int px, int py) {
      final ScrollState s = vertical ? vbar : hbar;
      int w = vertical ? Theme.SCROLLBAR : textWidth() + 2;
      int h = vertical ? textHeight() : Theme.SCROLLBAR;
      vertPressed = vertical;
      barPressed = s.hit(px, py, w, h);
      final int delta;
      switch (barPressed) {
         case ScrollState.ARROW_DEC:
            delta = -s.unit;
            break;
         case ScrollState.ARROW_INC:
            delta = s.unit;
            break;
         case ScrollState.TRACK_DEC:
            delta = -s.block;
            break;
         case ScrollState.TRACK_INC:
            delta = s.block;
            break;
         default: {
            int[] t = s.thumb(vertical ? h : w);
            dragOffset = (vertical ? py : px) - t[0];
            dragging = true;
            repaint();
            return;
         }
      }
      Repeater.start(new Runnable() {
         public void run() {
            s.value = s.clamp(s.value + delta);
            syncFromBars();
         }
      });
   }

   private void syncFromBars() {
      topLine = vbar.value;
      scrollX = hbar.value;
      repaint();
   }

   void paintPeer(Graphics g) {
      Theme.sunken(g, 0, 0, width, height);
      Color bg = getBackground();
      g.setColor(bg != null ? bg : Theme.WINDOW);
      g.fillRect(2, 2, width - 4, height - 4);
      Font f = getFont();
      if (f != null) {
         g.setFont(f);
      }
      FontMetrics fm = g.getFontMetrics();
      int tw = textWidth() + 2;
      int th = textHeight();
      Graphics inner = g.create(2, 2, tw, th);
      try {
         boolean focused = isFocusOwner();
         int lh = fm.getHeight();
         int y = fm.getAscent();
         for (int i = topLine; i < lineStarts.length && y - fm.getAscent() < th; i++, y += lh) {
            drawLine(inner, fm, 1 - scrollX, y, lineStarts[i], lineEnds[i], focused);
         }
      } finally {
         inner.dispose();
      }
      if (hasV()) {
         vbar.paint(g, width - 2 - Theme.SCROLLBAR, 2, Theme.SCROLLBAR, th, enabled && lineStarts.length > pageLines(),
               vertPressed ? barPressed : ScrollState.NONE);
      }
      if (hasH()) {
         hbar.paint(g, 2, height - 2 - Theme.SCROLLBAR, tw, Theme.SCROLLBAR, enabled && hbar.maximum > hbar.visible,
               !vertPressed ? barPressed : ScrollState.NONE);
      }
      if (hasV() && hasH()) {
         g.setColor(Theme.CONTROL);
         g.fillRect(width - 2 - Theme.SCROLLBAR, height - 2 - Theme.SCROLLBAR, Theme.SCROLLBAR, Theme.SCROLLBAR);
      }
   }

   protected String paramString() {
      String sbv;
      switch (scrollbarVisibility) {
         case SCROLLBARS_BOTH:
            sbv = "both";
            break;
         case SCROLLBARS_VERTICAL_ONLY:
            sbv = "vertical-only";
            break;
         case SCROLLBARS_HORIZONTAL_ONLY:
            sbv = "horizontal-only";
            break;
         default:
            sbv = "none";
      }
      return super.paramString() + ",rows=" + rows + ",columns=" + columns + ",scrollbarVisibility=" + sbv;
   }
}
