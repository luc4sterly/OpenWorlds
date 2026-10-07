package java.awt;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.util.ArrayList;

/** A one-line text field, as java.awt.TextField: Enter posts an ActionEvent with the text. */
public class TextField extends TextComponent {
   int columns;
   char echoChar;
   transient ActionListener actionListener;
   /** Pixels of text scrolled off to the left. */
   private int scroll;

   public TextField() {
      this("", 0);
   }

   public TextField(String text) {
      this(text, text != null ? text.length() : 0);
   }

   public TextField(int columns) {
      this("", columns);
   }

   public TextField(String text, int columns) {
      super(text);
      this.columns = Math.max(0, columns);
   }

   public char getEchoChar() {
      return echoChar;
   }

   public void setEchoChar(char c) {
      setEchoCharacter(c);
   }

   public synchronized void setEchoCharacter(char c) {
      echoChar = c;
      repaint();
   }

   public boolean echoCharIsSet() {
      return echoChar != 0;
   }

   public int getColumns() {
      return columns;
   }

   public synchronized void setColumns(int columns) {
      if (columns < 0) {
         throw new IllegalArgumentException("columns less than zero.");
      }
      this.columns = columns;
      invalidate();
   }

   public void setText(String t) {
      super.setText(t == null ? "" : t.replace('\n', ' '));
   }

   String shown(String s) {
      if (echoChar == 0) {
         return s;
      }
      char[] c = new char[s.length()];
      java.util.Arrays.fill(c, echoChar);
      return new String(c);
   }

   String filterPaste(String s) {
      return s.replace("\r", "").replace('\n', ' ');
   }

   public Dimension getPreferredSize(int columns) {
      return preferredSize(columns);
   }

   public Dimension preferredSize(int columns) {
      return minimumSize(columns);
   }

   public Dimension getMinimumSize(int columns) {
      return minimumSize(columns);
   }

   public Dimension minimumSize(int columns) {
      FontMetrics fm = getFontMetrics(getFont());
      return new Dimension(fm.charWidth('0') * columns + 24, fm.getHeight() + 8);
   }

   Dimension peerMinimumSize() {
      return minimumSize(columns > 0 ? columns : text.length());
   }

   public synchronized void addActionListener(ActionListener l) {
      if (l == null) {
         return;
      }
      actionListener = AWTEventMulticaster.add(actionListener, l);
      newEventsOnly = true;
   }

   public synchronized void removeActionListener(ActionListener l) {
      if (l == null) {
         return;
      }
      actionListener = AWTEventMulticaster.remove(actionListener, l);
   }

   public synchronized ActionListener[] getActionListeners() {
      ArrayList<ActionListener> out = new ArrayList<ActionListener>();
      Button.collect(actionListener, out);
      return out.toArray(new ActionListener[out.size()]);
   }

   boolean eventEnabled(AWTEvent e) {
      if (e.id == ActionEvent.ACTION_PERFORMED) {
         return (eventMask & AWTEvent.ACTION_EVENT_MASK) != 0 || actionListener != null;
      }
      return super.eventEnabled(e);
   }

   protected void processEvent(AWTEvent e) {
      if (e instanceof ActionEvent) {
         processActionEvent((ActionEvent) e);
         return;
      }
      super.processEvent(e);
   }

   protected void processActionEvent(ActionEvent e) {
      ActionListener listener = actionListener;
      if (listener != null) {
         listener.actionPerformed(e);
      }
   }

   void enterTyped(KeyEvent e) {
      EventQueue.post(new ActionEvent(this, ActionEvent.ACTION_PERFORMED, getText(), e.getWhen(), e.getModifiers()));
   }

   private int innerWidth() {
      return Math.max(1, width - 6);
   }

   void caretMoved() {
      FontMetrics fm = getFontMetrics(getFont());
      int cx = fm.stringWidth(shown(text.substring(0, Math.min(caret, text.length()))));
      int w = innerWidth();
      if (cx - scroll > w - 1) {
         scroll = cx - w + 1;
      } else if (cx - scroll < 0) {
         scroll = Math.max(0, cx - w / 3);
      }
      int total = fm.stringWidth(shown(text));
      if (total - scroll < w - 1) {
         scroll = Math.max(0, total - w + 1);
      }
   }

   int offsetAt(int x, int y) {
      FontMetrics fm = getFontMetrics(getFont());
      String s = shown(text);
      int px = x - 3 + scroll;
      int acc = 0;
      for (int i = 0; i < s.length(); i++) {
         int cw = fm.charWidth(s.charAt(i));
         if (px < acc + cw / 2) {
            return i;
         }
         acc += cw;
      }
      return s.length();
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
      Graphics inner = g.create(2, 2, width - 4, height - 4);
      try {
         int baseline = (height - 4 - fm.getHeight()) / 2 + fm.getAscent();
         drawLine(inner, fm, 1 - scroll, baseline, 0, text.length(), isFocusOwner());
      } finally {
         inner.dispose();
      }
   }

   protected String paramString() {
      String str = super.paramString();
      if (echoChar != 0) {
         str += ",echo=" + echoChar;
      }
      return str;
   }
}
