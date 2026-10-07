package java.awt;

/**
 * A scroll bar's numbers, drawing and hit testing, shared by Scrollbar and
 * the scroll bars inside List, TextArea and ScrollPane (Windows' classic
 * scroll bar: 16 pixel arrow buttons, a raised thumb, a light track).
 */
final class ScrollState {
   static final int NONE = 0;
   static final int ARROW_DEC = 1;
   static final int ARROW_INC = 2;
   static final int TRACK_DEC = 3;
   static final int TRACK_INC = 4;
   static final int THUMB = 5;

   boolean vertical;
   int minimum;
   int maximum = 100;
   int visible = 10;
   int value;
   int unit = 1;
   int block = 10;

   ScrollState(boolean vertical) {
      this.vertical = vertical;
   }

   /** Sets the values with the JDK's corrections (Scrollbar.setValues). */
   void set(int value, int visible, int minimum, int maximum) {
      if (minimum == Integer.MAX_VALUE) {
         minimum = Integer.MAX_VALUE - 1;
      }
      if (maximum <= minimum) {
         maximum = minimum + 1;
      }
      long maxMinusMin = (long) maximum - (long) minimum;
      if (maxMinusMin > Integer.MAX_VALUE) {
         maxMinusMin = Integer.MAX_VALUE;
         maximum = minimum + (int) maxMinusMin;
      }
      if (visible > (int) maxMinusMin) {
         visible = (int) maxMinusMin;
      }
      if (visible < 1) {
         visible = 1;
      }
      if (value < minimum) {
         value = minimum;
      }
      if (value > maximum - visible) {
         value = maximum - visible;
      }
      this.value = value;
      this.visible = visible;
      this.minimum = minimum;
      this.maximum = maximum;
   }

   int clamp(int v) {
      return Math.max(minimum, Math.min(maximum - visible, v));
   }

   /** The thumb's offset and length along the track, in pixels, for a bar of this length. */
   int[] thumb(int length) {
      int track = Math.max(0, length - 2 * Theme.SCROLLBAR);
      int range = Math.max(1, maximum - minimum);
      int size = Math.max(8, (int) ((long) track * visible / range));
      if (size > track) {
         size = track;
      }
      int span = range - visible;
      int pos = span <= 0 ? 0 : (int) ((long) (track - size) * (value - minimum) / span);
      return new int[]{Theme.SCROLLBAR + pos, size};
   }

   int hit(int px, int py, int w, int h) {
      int along = vertical ? py : px;
      int length = vertical ? h : w;
      if (along < Theme.SCROLLBAR) {
         return ARROW_DEC;
      }
      if (along >= length - Theme.SCROLLBAR) {
         return ARROW_INC;
      }
      int[] t = thumb(length);
      if (along < t[0]) {
         return TRACK_DEC;
      }
      if (along >= t[0] + t[1]) {
         return TRACK_INC;
      }
      return THUMB;
   }

   /** The value for the thumb's start dragged to this pixel offset. */
   int valueAt(int thumbStart, int length) {
      int track = Math.max(1, length - 2 * Theme.SCROLLBAR);
      int[] t = thumb(length);
      int free = Math.max(1, track - t[1]);
      int span = maximum - minimum - visible;
      return clamp(minimum + (int) Math.round((double) (thumbStart - Theme.SCROLLBAR) * span / free));
   }

   void paint(Graphics g, int x, int y, int w, int h, boolean enabled, int pressed) {
      g.setColor(Theme.SCROLL_TRACK);
      g.fillRect(x, y, w, h);
      int a = Theme.SCROLLBAR;
      if (vertical) {
         Theme.paintButtonFace(g, x, y, w, a, pressed == ARROW_DEC);
         Theme.arrow(g, x, y, w, a, Theme.UP, enabled ? Color.black : Theme.SHADOW);
         Theme.paintButtonFace(g, x, y + h - a, w, a, pressed == ARROW_INC);
         Theme.arrow(g, x, y + h - a, w, a, Theme.DOWN, enabled ? Color.black : Theme.SHADOW);
      } else {
         Theme.paintButtonFace(g, x, y, a, h, pressed == ARROW_DEC);
         Theme.arrow(g, x, y, a, h, Theme.LEFT, enabled ? Color.black : Theme.SHADOW);
         Theme.paintButtonFace(g, x + w - a, y, a, h, pressed == ARROW_INC);
         Theme.arrow(g, x + w - a, y, a, h, Theme.RIGHT, enabled ? Color.black : Theme.SHADOW);
      }
      if (!enabled || maximum - minimum <= visible) {
         return;
      }
      int[] t = thumb(vertical ? h : w);
      if (pressed == TRACK_DEC || pressed == TRACK_INC) {
         g.setColor(Theme.DARK_SHADOW);
         if (vertical) {
            if (pressed == TRACK_DEC) {
               g.fillRect(x, y + a, w, t[0] - a);
            } else {
               g.fillRect(x, y + t[0] + t[1], w, h - a - t[0] - t[1]);
            }
         } else {
            if (pressed == TRACK_DEC) {
               g.fillRect(x + a, y, t[0] - a, h);
            } else {
               g.fillRect(x + t[0] + t[1], y, w - a - t[0] - t[1], h);
            }
         }
      }
      if (vertical) {
         Theme.paintButtonFace(g, x, y + t[0], w, t[1], false);
      } else {
         Theme.paintButtonFace(g, x + t[0], y, t[1], h, false);
      }
   }
}
