package java.awt;

import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;
import java.awt.event.TextEvent;
import java.awt.event.TextListener;
import java.util.ArrayList;

/**
 * Editable text, as java.awt.TextComponent, with the editing a Windows edit
 * control did: caret and selection by keys and mouse, typing, Backspace and
 * Delete, Ctrl+A/C/X/V with a clipboard of our own. TextEvents are posted on
 * every change, also those made by the program (as Windows' EN_CHANGE did).
 */
public class TextComponent extends Component {
   String text;
   boolean editable = true;
   int caret;
   /** The selection is between anchor and caret. */
   int anchor;
   transient TextListener textListener;
   private boolean mouseSelecting;
   private static String clipboard = "";

   TextComponent(String text) {
      this.text = text == null ? "" : text;
      setCursor(Cursor.getPredefinedCursor(Cursor.TEXT_CURSOR));
   }

   public synchronized String getText() {
      return text;
   }

   public void setText(String t) {
      synchronized (this) {
         t = t == null ? "" : t;
         if (t.equals(text)) {
            return;
         }
         text = t;
         caret = Math.min(caret, text.length());
         anchor = caret;
      }
      textChanged();
   }

   void textChanged() {
      layoutText();
      repaint();
      EventQueue.post(new TextEvent(this, TextEvent.TEXT_VALUE_CHANGED));
   }

   /** Subclasses recompute their lines. */
   void layoutText() {
   }

   public synchronized String getSelectedText() {
      return text.substring(getSelectionStart(), getSelectionEnd());
   }

   public boolean isEditable() {
      return editable;
   }

   public synchronized void setEditable(boolean b) {
      editable = b;
      repaint();
   }

   public Color getBackground() {
      if (background == null && displayable) {
         return editable ? Theme.WINDOW : Theme.CONTROL;
      }
      return super.getBackground();
   }

   public synchronized int getSelectionStart() {
      return Math.min(anchor, caret);
   }

   public synchronized void setSelectionStart(int selectionStart) {
      select(selectionStart, getSelectionEnd());
   }

   public synchronized int getSelectionEnd() {
      return Math.max(anchor, caret);
   }

   public synchronized void setSelectionEnd(int selectionEnd) {
      select(getSelectionStart(), selectionEnd);
   }

   public synchronized void select(int selectionStart, int selectionEnd) {
      int len = text.length();
      selectionStart = Math.max(0, Math.min(selectionStart, len));
      selectionEnd = Math.max(selectionStart, Math.min(selectionEnd, len));
      anchor = selectionStart;
      caret = selectionEnd;
      caretMoved();
      repaint();
   }

   public synchronized void selectAll() {
      anchor = 0;
      caret = text.length();
      caretMoved();
      repaint();
   }

   public synchronized void setCaretPosition(int position) {
      if (position < 0) {
         throw new IllegalArgumentException("position less than zero.");
      }
      caret = anchor = Math.min(position, text.length());
      caretMoved();
      repaint();
   }

   public synchronized int getCaretPosition() {
      return caret;
   }

   /** Scrolls so the caret shows. */
   void caretMoved() {
   }

   public synchronized void addTextListener(TextListener l) {
      if (l == null) {
         return;
      }
      textListener = AWTEventMulticaster.add(textListener, l);
      newEventsOnly = true;
   }

   public synchronized void removeTextListener(TextListener l) {
      if (l == null) {
         return;
      }
      textListener = AWTEventMulticaster.remove(textListener, l);
   }

   public synchronized TextListener[] getTextListeners() {
      ArrayList<TextListener> out = new ArrayList<TextListener>();
      collect(textListener, out);
      return out.toArray(new TextListener[out.size()]);
   }

   private static void collect(TextListener l, ArrayList<TextListener> out) {
      if (l instanceof AWTEventMulticaster) {
         collect((TextListener) ((AWTEventMulticaster) l).a, out);
         collect((TextListener) ((AWTEventMulticaster) l).b, out);
      } else if (l != null) {
         out.add(l);
      }
   }

   boolean eventEnabled(AWTEvent e) {
      if (e.id == TextEvent.TEXT_VALUE_CHANGED) {
         return (eventMask & AWTEvent.TEXT_EVENT_MASK) != 0 || textListener != null;
      }
      return super.eventEnabled(e);
   }

   protected void processEvent(AWTEvent e) {
      if (e instanceof TextEvent) {
         processTextEvent((TextEvent) e);
         return;
      }
      super.processEvent(e);
   }

   protected void processTextEvent(TextEvent e) {
      TextListener listener = textListener;
      if (listener != null && e.getID() == TextEvent.TEXT_VALUE_CHANGED) {
         listener.textValueChanged(e);
      }
   }

   boolean traversable() {
      return true;
   }

   void focusEventArrived(java.awt.event.FocusEvent e) {
      super.focusEventArrived(e);
      repaint();
      WindowSystem.textFocus(this, e.getID() == java.awt.event.FocusEvent.FOCUS_GAINED);
   }

   // ------------------------------------------------------------------ editing

   /** Replaces the selection with s (typing, pasting). */
   void replaceSelection(String s) {
      synchronized (this) {
         int a = getSelectionStart();
         int b = getSelectionEnd();
         text = text.substring(0, a) + s + text.substring(b);
         caret = anchor = a + s.length();
      }
      textChanged();
      caretMoved();
   }

   /** The text offset nearest to a point of the component (subclasses know the layout). */
   int offsetAt(int x, int y) {
      return 0;
   }

   /** The offset a line above or below the caret (TextArea), or -1. */
   int verticalMove(int from, int lines) {
      return -1;
   }

   /** The character typed: inserted, or what Windows did with Backspace, Enter and Tab. */
   void typed(KeyEvent e) {
      char c = e.getKeyChar();
      if ((e.getModifiers() & (InputEvent.CTRL_MASK | InputEvent.ALT_MASK)) != 0 && c < ' ') {
         return;
      }
      if (c == '\b') {
         if (!editable) {
            return;
         }
         synchronized (this) {
            if (anchor == caret && caret > 0) {
               anchor = caret - 1;
            }
         }
         if (getSelectionStart() != getSelectionEnd()) {
            replaceSelection("");
         }
         return;
      }
      if (c == '\n' || c == '\r') {
         enterTyped(e);
         return;
      }
      if (c == '\t' && !(this instanceof TextArea)) {
         return;
      }
      if (c == KeyEvent.CHAR_UNDEFINED || c == 127 || (c < ' ' && c != '\t')) {
         return;
      }
      if (editable) {
         replaceSelection(String.valueOf(c));
      }
   }

   void enterTyped(KeyEvent e) {
   }

   void handlePeerEvent(AWTEvent e) {
      switch (e.getID()) {
         case KeyEvent.KEY_TYPED:
            if (enabled) {
               typed((KeyEvent) e);
            }
            break;
         case KeyEvent.KEY_PRESSED:
            if (enabled) {
               pressed((KeyEvent) e);
            }
            break;
         case MouseEvent.MOUSE_PRESSED: {
            MouseEvent m = (MouseEvent) e;
            if (!enabled || m.getButton() == MouseEvent.BUTTON3) {
               break;
            }
            int off = offsetAt(m.getX(), m.getY());
            synchronized (this) {
               if (m.getClickCount() == 2) {
                  int a = off;
                  int b = off;
                  while (a > 0 && Character.isLetterOrDigit(text.charAt(a - 1))) {
                     a--;
                  }
                  while (b < text.length() && Character.isLetterOrDigit(text.charAt(b))) {
                     b++;
                  }
                  anchor = a;
                  caret = b;
               } else if (m.getClickCount() >= 3) {
                  anchor = 0;
                  caret = text.length();
               } else {
                  caret = off;
                  if (!m.isShiftDown()) {
                     anchor = off;
                  }
                  mouseSelecting = true;
               }
            }
            caretMoved();
            repaint();
            break;
         }
         case MouseEvent.MOUSE_DRAGGED:
            if (mouseSelecting) {
               MouseEvent m = (MouseEvent) e;
               synchronized (this) {
                  caret = offsetAt(m.getX(), m.getY());
               }
               caretMoved();
               repaint();
            }
            break;
         case MouseEvent.MOUSE_RELEASED:
            mouseSelecting = false;
            break;
         default:
      }
   }

   private void pressed(KeyEvent e) {
      boolean shift = e.isShiftDown();
      boolean ctrl = e.isControlDown();
      int k = e.getKeyCode();
      int len = text.length();
      int nc = -1;
      switch (k) {
         case KeyEvent.VK_LEFT:
            nc = ctrl ? wordLeft(caret) : (!shift && anchor != caret ? getSelectionStart() : Math.max(0, caret - 1));
            break;
         case KeyEvent.VK_RIGHT:
            nc = ctrl ? wordRight(caret) : (!shift && anchor != caret ? getSelectionEnd() : Math.min(len, caret + 1));
            break;
         case KeyEvent.VK_HOME:
            nc = ctrl ? 0 : lineStart(caret);
            break;
         case KeyEvent.VK_END:
            nc = ctrl ? len : lineEnd(caret);
            break;
         case KeyEvent.VK_UP:
            nc = verticalMove(caret, -1);
            break;
         case KeyEvent.VK_DOWN:
            nc = verticalMove(caret, 1);
            break;
         case KeyEvent.VK_PAGE_UP:
            nc = verticalMove(caret, -pageLines());
            break;
         case KeyEvent.VK_PAGE_DOWN:
            nc = verticalMove(caret, pageLines());
            break;
         case KeyEvent.VK_DELETE:
            if (editable) {
               synchronized (this) {
                  if (anchor == caret && caret < len) {
                     anchor = caret + 1;
                  }
               }
               if (getSelectionStart() != getSelectionEnd()) {
                  if (shift) {
                     clipboard = getSelectedText();
                  }
                  replaceSelection("");
               }
            }
            return;
         case KeyEvent.VK_INSERT:
            if (shift && editable) {
               replaceSelection(filterPaste(clipboard));
            } else if (ctrl && getSelectionStart() != getSelectionEnd()) {
               clipboard = getSelectedText();
            }
            return;
         default:
            if (ctrl) {
               if (k == KeyEvent.VK_A) {
                  selectAll();
               } else if (k == KeyEvent.VK_C && getSelectionStart() != getSelectionEnd()) {
                  clipboard = getSelectedText();
               } else if (k == KeyEvent.VK_X && editable && getSelectionStart() != getSelectionEnd()) {
                  clipboard = getSelectedText();
                  replaceSelection("");
               } else if (k == KeyEvent.VK_V && editable) {
                  replaceSelection(filterPaste(clipboard));
               }
            }
            return;
      }
      if (nc < 0) {
         return;
      }
      synchronized (this) {
         caret = nc;
         if (!shift) {
            anchor = nc;
         }
      }
      caretMoved();
      repaint();
   }

   String filterPaste(String s) {
      return s;
   }

   int pageLines() {
      return 1;
   }

   int lineStart(int at) {
      return at <= 0 ? 0 : text.lastIndexOf('\n', at - 1) + 1;
   }

   int lineEnd(int at) {
      int i = text.indexOf('\n', at);
      return i < 0 ? text.length() : i;
   }

   private int wordLeft(int at) {
      int i = at;
      while (i > 0 && !Character.isLetterOrDigit(text.charAt(i - 1))) {
         i--;
      }
      while (i > 0 && Character.isLetterOrDigit(text.charAt(i - 1))) {
         i--;
      }
      return i;
   }

   private int wordRight(int at) {
      int i = at;
      int n = text.length();
      while (i < n && Character.isLetterOrDigit(text.charAt(i))) {
         i++;
      }
      while (i < n && !Character.isLetterOrDigit(text.charAt(i))) {
         i++;
      }
      return i;
   }

   /** What is shown for the text (TextField's echo character). */
   String shown(String s) {
      return s;
   }

   /** Draws one line of text with its part of the selection and the caret, at baseline y. */
   void drawLine(Graphics g, FontMetrics fm, int x, int y, int lineStart, int lineEnd, boolean focused) {
      String line = shown(text.substring(lineStart, lineEnd));
      int selA = Math.max(getSelectionStart(), lineStart) - lineStart;
      int selB = Math.min(getSelectionEnd(), lineEnd) - lineStart;
      Color fg = enabled ? (getForeground() != null ? getForeground() : Color.black) : Theme.DISABLED_TEXT;
      if (focused && selB > selA) {
         int sx = x + fm.stringWidth(line.substring(0, selA));
         int sw = fm.stringWidth(line.substring(selA, selB));
         g.setColor(fg);
         g.drawString(line.substring(0, selA), x, y);
         g.setColor(Theme.SELECTION);
         g.fillRect(sx, y - fm.getAscent(), sw, fm.getHeight());
         g.setColor(Theme.SELECTION_TEXT);
         g.drawString(line.substring(selA, selB), sx, y);
         g.setColor(fg);
         g.drawString(line.substring(selB), sx + sw, y);
      } else {
         g.setColor(fg);
         g.drawString(line, x, y);
      }
      if (focused && caret >= lineStart && caret <= lineEnd && anchor == caret && editable) {
         int cx = x + fm.stringWidth(line.substring(0, caret - lineStart));
         g.setColor(fg);
         g.drawLine(cx, y - fm.getAscent(), cx, y + fm.getDescent() - 1);
      }
   }

   protected String paramString() {
      String str = super.paramString() + ",text=" + getText();
      if (editable) {
         str += ",editable";
      }
      return str + ",selection=" + getSelectionStart() + "-" + getSelectionEnd();
   }
}
