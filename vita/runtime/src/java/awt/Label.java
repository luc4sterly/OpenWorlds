package java.awt;

/** A text label, as java.awt.Label (Windows' static control). */
public class Label extends Component {
   public static final int LEFT = 0;
   public static final int CENTER = 1;
   public static final int RIGHT = 2;

   String text;
   int alignment = LEFT;

   public Label() {
      this("", LEFT);
   }

   public Label(String text) {
      this(text, LEFT);
   }

   public Label(String text, int alignment) {
      this.text = text;
      setAlignment(alignment);
   }

   public int getAlignment() {
      return alignment;
   }

   public synchronized void setAlignment(int alignment) {
      if (alignment < LEFT || alignment > RIGHT) {
         throw new IllegalArgumentException("improper alignment: " + alignment);
      }
      this.alignment = alignment;
      repaint();
   }

   public String getText() {
      return text;
   }

   public void setText(String text) {
      boolean changed;
      synchronized (this) {
         changed = text != this.text && (text == null || !text.equals(this.text));
         this.text = text;
      }
      if (changed) {
         repaint();
      }
   }

   boolean acceptsFocus() {
      return false;
   }

   Dimension peerMinimumSize() {
      FontMetrics fm = getFontMetrics(getFont());
      String t = text == null ? "" : text;
      return new Dimension(fm.stringWidth(t) + 14, fm.getHeight() + 8);
   }

   void paintPeer(Graphics g) {
      Color bg = getBackground();
      if (bg != null) {
         g.setColor(bg);
         g.fillRect(0, 0, width, height);
      }
      String t = text == null ? "" : text;
      Font f = getFont();
      if (f != null) {
         g.setFont(f);
      }
      FontMetrics fm = g.getFontMetrics();
      int tw = fm.stringWidth(t);
      int x;
      switch (alignment) {
         case CENTER:
            x = (width - tw) / 2;
            break;
         case RIGHT:
            x = width - tw - 2;
            break;
         default:
            x = 2;
      }
      int y = (height - fm.getHeight()) / 2 + fm.getAscent();
      if (enabled) {
         Color fg = getForeground();
         g.setColor(fg != null ? fg : Color.black);
         g.drawString(t, x, y);
      } else {
         Theme.disabledString(g, t, x, y);
      }
   }

   protected String paramString() {
      String align = alignment == LEFT ? "left" : alignment == CENTER ? "center" : "right";
      return super.paramString() + ",align=" + align + ",text=" + text;
   }
}
