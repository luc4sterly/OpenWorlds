import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.Component;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.Insets;
import java.awt.LayoutManager;

/**
 * Prints what the layout managers do with components of fixed sizes: the
 * preferred and minimum sizes and each component's bounds. Run on the JDK
 * (headless) and on our runtime, and compare (vita/tools/run-layout-conformance.sh).
 * Known differences, ours being JDK 1.4.2's: GridLayout keeps the leftover
 * pixels at the right and bottom (JDK 7 centres the grid), GridBagLayout
 * widens a cell that starts left of the container (JDK 5's 4969409), and
 * FlowLayout's minimum size counts a gap before the second component even
 * when the first is hidden (⚠️ VERIFY: as recalled of 1.4.2's source).
 */
public class LayoutConformance {
   static class Box extends Component {
      final Dimension pref;
      final Dimension min;

      Box(int pw, int ph, int mw, int mh) {
         pref = new Dimension(pw, ph);
         min = new Dimension(mw, mh);
      }

      public Dimension getPreferredSize() {
         return new Dimension(pref);
      }

      public Dimension getMinimumSize() {
         return new Dimension(min);
      }
   }

   static class Pane extends Container {
      final Insets in;

      Pane(LayoutManager lm, Insets in) {
         setLayout(lm);
         this.in = in;
      }

      public Insets getInsets() {
         return (Insets) in.clone();
      }
   }

   static void print(String name, Container c, int w, int h) {
      Dimension p = c.getPreferredSize();
      Dimension m = c.getMinimumSize();
      c.setSize(w, h);
      c.doLayout();
      StringBuilder sb = new StringBuilder(name + " " + w + "x" + h + " pref=" + p.width + "x" + p.height + " min=" + m.width + "x" + m.height + ":");
      for (int i = 0; i < c.getComponentCount(); i++) {
         Component k = c.getComponent(i);
         sb.append(' ').append(k.isVisible() ? "" : "!").append(k.getX()).append(',').append(k.getY()).append(',').append(k.getWidth()).append(',')
               .append(k.getHeight());
      }
      System.out.println(sb);
   }

   static Box box(int w, int h) {
      return new Box(w, h, w / 2, h / 2);
   }

   public static void main(String[] args) {
      Insets none = new Insets(0, 0, 0, 0);
      Insets some = new Insets(3, 5, 7, 2);

      for (int align = 0; align <= 4; align++) {
         for (int w : new int[]{60, 150, 301}) {
            Pane p = new Pane(new FlowLayout(align, 4, 6), some);
            p.add(box(40, 20));
            p.add(box(70, 30));
            Box hidden = box(10, 10);
            hidden.setVisible(false);
            p.add(hidden);
            p.add(box(25, 12));
            p.add(box(90, 18));
            print("flow" + align, p, w, 120);
         }
      }
      {
         Pane p = new Pane(new FlowLayout(), none);
         Box hidden = box(10, 10);
         hidden.setVisible(false);
         p.add(hidden);
         p.add(box(30, 30));
         print("flow-first-hidden", p, 100, 50);
      }

      for (int[] s : new int[][]{{300, 200}, {50, 40}, {121, 77}}) {
         Pane p = new Pane(new BorderLayout(3, 4), some);
         p.add(box(80, 20), BorderLayout.NORTH);
         p.add(box(60, 25), BorderLayout.SOUTH);
         p.add(box(30, 50), BorderLayout.EAST);
         p.add(box(35, 45), BorderLayout.WEST);
         p.add(box(100, 100), BorderLayout.CENTER);
         print("border", p, s[0], s[1]);
         Pane q = new Pane(new BorderLayout(), none);
         q.add(box(80, 20), BorderLayout.PAGE_START);
         q.add(box(40, 20), BorderLayout.NORTH);
         q.add(box(20, 20), BorderLayout.LINE_END);
         q.add(box(20, 20), BorderLayout.WEST);
         print("border-relative", q, s[0], s[1]);
      }

      for (int[] rc : new int[][]{{3, 0}, {0, 4}, {2, 2}, {1, 0}}) {
         for (int w : new int[]{200, 203}) {
            Pane p = new Pane(new GridLayout(rc[0], rc[1], 3, 2), some);
            for (int i = 0; i < 7; i++) {
               p.add(box(20 + i * 3, 10 + i));
            }
            print("grid" + rc[0] + "x" + rc[1], p, w, 101);
         }
      }

      {
         CardLayout cl = new CardLayout(4, 5);
         Pane p = new Pane(cl, some);
         p.add(box(50, 60), "one");
         p.add(box(70, 20), "two");
         p.add(box(30, 90), "three");
         print("card", p, 200, 150);
         cl.show(p, "three");
         print("card-three", p, 200, 150);
         cl.next(p);
         print("card-next", p, 200, 150);
         cl.previous(p);
         cl.previous(p);
         print("card-previous", p, 200, 150);
      }

      // GridBagLayout: a form, spans, REMAINDER/RELATIVE, fills, anchors, insets, pads, weights
      for (int[] s : new int[][]{{400, 300}, {250, 120}, {120, 60}, {401, 299}}) {
         GridBagLayout gb = new GridBagLayout();
         Pane p = new Pane(gb, some);
         GridBagConstraints c = new GridBagConstraints();
         for (int i = 0; i < 4; i++) {
            c.gridwidth = GridBagConstraints.RELATIVE;
            c.weightx = 0;
            c.fill = GridBagConstraints.NONE;
            c.anchor = GridBagConstraints.EAST;
            c.insets = new Insets(2, 4, 2, 4);
            Box l = box(40 + i * 7, 14);
            gb.setConstraints(l, c);
            p.add(l);
            c.gridwidth = GridBagConstraints.REMAINDER;
            c.weightx = 1.0;
            c.fill = GridBagConstraints.HORIZONTAL;
            c.anchor = GridBagConstraints.WEST;
            Box f = box(120, 20);
            gb.setConstraints(f, c);
            p.add(f);
         }
         c = new GridBagConstraints();
         c.gridwidth = GridBagConstraints.REMAINDER;
         c.weighty = 1.0;
         c.fill = GridBagConstraints.BOTH;
         c.ipadx = 6;
         c.ipady = 3;
         Box area = box(200, 80);
         gb.setConstraints(area, c);
         p.add(area);
         c = new GridBagConstraints();
         c.gridx = 1;
         c.gridy = 5;
         c.anchor = GridBagConstraints.SOUTHEAST;
         c.weighty = 0.3;
         Box ok = box(60, 22);
         p.add(ok, c);
         c.gridx = 2;
         c.anchor = GridBagConstraints.NORTHWEST;
         c.weightx = 0.5;
         Box cancel = box(66, 22);
         p.add(cancel, c);
         print("gridbag-form", p, s[0], s[1]);
      }
      for (int[] s : new int[][]{{300, 200}, {90, 50}, {301, 203}}) {
         GridBagLayout gb = new GridBagLayout();
         Pane p = new Pane(gb, none);
         GridBagConstraints c = new GridBagConstraints();
         c.gridx = 0;
         c.gridy = 0;
         c.gridwidth = 2;
         c.weightx = 0.25;
         c.fill = GridBagConstraints.BOTH;
         p.add(box(100, 30), c);
         c.gridx = 2;
         c.gridwidth = 1;
         c.gridheight = 2;
         c.weightx = 0.75;
         c.weighty = 1;
         p.add(box(40, 70), c);
         c.gridx = 0;
         c.gridy = 1;
         c.gridheight = 1;
         c.weightx = 0;
         c.weighty = 0.5;
         c.anchor = GridBagConstraints.NORTH;
         c.fill = GridBagConstraints.NONE;
         p.add(box(33, 17), c);
         c.gridx = 1;
         c.anchor = GridBagConstraints.SOUTHWEST;
         c.insets = new Insets(1, 2, 3, 4);
         p.add(box(51, 9), c);
         c.gridx = GridBagConstraints.RELATIVE;
         c.gridy = 2;
         c.anchor = GridBagConstraints.CENTER;
         c.insets = new Insets(0, 0, 0, 0);
         p.add(box(20, 20), c);
         p.add(box(21, 21), c);
         Box gone = box(15, 15);
         gone.setVisible(false);
         p.add(gone, c);
         p.add(box(22, 22), c);
         print("gridbag-spans", p, s[0], s[1]);
      }
      {
         // no weights at all: the grid is centred, and cut when the container is too small
         for (int w : new int[]{200, 60}) {
            GridBagLayout gb = new GridBagLayout();
            Pane p = new Pane(gb, none);
            GridBagConstraints c = new GridBagConstraints();
            p.add(box(50, 20), c);
            p.add(box(70, 30), c);
            c.gridwidth = GridBagConstraints.REMAINDER;
            p.add(box(30, 10), c);
            print("gridbag-noweights", p, w, 40);
         }
      }
      {
         GridBagLayout gb = new GridBagLayout();
         gb.columnWidths = new int[]{30, 0, 50};
         gb.rowHeights = new int[]{10, 40};
         gb.columnWeights = new double[]{0, 1, 0.5};
         gb.rowWeights = new double[]{1, 0};
         Pane p = new Pane(gb, some);
         GridBagConstraints c = new GridBagConstraints();
         c.fill = GridBagConstraints.BOTH;
         p.add(box(20, 20), c);
         c.gridx = 1;
         p.add(box(20, 20), c);
         c.gridy = 1;
         c.gridx = 2;
         p.add(box(20, 20), c);
         print("gridbag-arrays", p, 240, 160);
      }
   }
}
