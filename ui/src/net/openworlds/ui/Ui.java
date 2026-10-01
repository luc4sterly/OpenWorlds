package net.openworlds.ui;

import javax.swing.AbstractButton;
import javax.swing.BorderFactory;
import javax.swing.ButtonGroup;
import javax.swing.ButtonModel;
import javax.swing.Icon;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JComponent;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JScrollBar;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.JToggleButton;
import javax.swing.SwingConstants;
import javax.swing.plaf.basic.BasicScrollBarUI;
import javax.swing.text.JTextComponent;
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Component;
import java.awt.Cursor;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GridLayout;
import java.awt.Insets;
import java.awt.LayoutManager;
import java.awt.Rectangle;
import java.awt.event.FocusAdapter;
import java.awt.event.FocusEvent;
import java.awt.geom.AffineTransform;
import java.awt.geom.Area;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Path2D;
import java.awt.geom.RoundRectangle2D;
import java.util.function.IntConsumer;

/** The controls of the OpenWorlds apps, in the icon's colours (see {@link Theme}). */
public final class Ui {
   private Ui() {
   }

   /**
    * The cross-platform look (everything visible is painted by these classes
    * anyway) with tooltips in the theme's colours. Call once, on the event
    * thread, after {@link Theme#use}.
    */
   public static void installLookAndFeel() {
      try {
         javax.swing.UIManager.setLookAndFeel(javax.swing.UIManager.getCrossPlatformLookAndFeelClassName());
      } catch (Exception ignored) {
         // the default look does just as well
      }
      javax.swing.UIManager.put("ToolTip.background", Theme.TIP);
      javax.swing.UIManager.put("ToolTip.foreground", Theme.TEXT);
      javax.swing.UIManager.put("ToolTip.font", Theme.regular(12f));
      javax.swing.UIManager.put("ToolTip.border", BorderFactory.createCompoundBorder(
         BorderFactory.createLineBorder(Theme.CARD_EDGE), BorderFactory.createEmptyBorder(5, 8, 5, 8)));
   }

   /** A filled circle of {@code size} px (status lights; Poppins has no U+25CF). */
   public static Icon dot(Color color, int size) {
      return new Icon() {
         @Override
         public void paintIcon(Component c, Graphics g, int x, int y) {
            Graphics2D g2 = Theme.smooth(g);
            g2.setColor(color);
            g2.fill(new Ellipse2D.Float(x, y, size, size));
            g2.dispose();
         }

         @Override
         public int getIconWidth() {
            return size;
         }

         @Override
         public int getIconHeight() {
            return size;
         }
      };
   }

   /** Small caps caption above a group of controls ("WORLD", "SERVER"). */
   public static JLabel caption(String text) {
      JLabel l = new JLabel(text.toUpperCase(java.util.Locale.ROOT));
      l.setFont(Theme.semibold(11f).deriveFont(java.util.Collections.singletonMap(
         java.awt.font.TextAttribute.TRACKING, 0.12f)));
      l.setForeground(Theme.MUTED);
      return l;
   }

   public static JLabel text(String text, Font font, Color color) {
      JLabel l = new JLabel(text);
      l.setFont(font);
      l.setForeground(color);
      return l;
   }

   public static JPanel row(int gap, Component... cs) {
      JPanel p = new JPanel(new FlowLayout(FlowLayout.LEFT, gap, 0));
      p.setOpaque(false);
      for (Component c : cs) {
         p.add(c);
      }
      return p;
   }

   // ------------------------------------------------------------------ buttons

   /** Rounded pill: PRIMARY wears the ring's gradient (the Play button), QUIET is a translucent one. */
   public static final class Pill extends JButton {
      public enum Kind { PRIMARY, QUIET }

      private Kind kind;

      public Pill(String text, Glyph glyph, Kind kind, float size) {
         super(text, glyph);
         setKind(kind);
         setFont(Theme.semibold(size));
         setIconTextGap(Math.round(size * 0.6f));
         setContentAreaFilled(false);
         setBorderPainted(false);
         setFocusPainted(false);
         setOpaque(false);
         setRolloverEnabled(true);
         setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
         int v = Math.round(size * 0.72f);
         setBorder(BorderFactory.createEmptyBorder(v, Math.round(size * 1.6f), v, Math.round(size * 1.6f)));
      }

      public void setKind(Kind k) {
         kind = k;
         repaint();
      }

      @Override
      protected void paintComponent(Graphics g) {
         Graphics2D g2 = Theme.smooth(g);
         int w = getWidth();
         int h = getHeight();
         ButtonModel m = getModel();
         RoundRectangle2D shape = new RoundRectangle2D.Float(1, 1, w - 2, h - 2, h - 2, h - 2);
         Color fg;
         if (!isEnabled()) {
            g2.setColor(new Color(255, 255, 255, 22));
            g2.fill(shape);
            fg = Theme.FAINT;
         } else if (kind == Kind.PRIMARY) {
            // colored shadow under the button
            g2.setColor(Theme.alpha(Theme.RING_A, m.isRollover() ? 70 : 40));
            g2.fill(new RoundRectangle2D.Float(4, 5, w - 8, h - 5, h - 5, h - 5));
            g2.setPaint(Theme.ring(0, w, 0));
            g2.fill(shape);
            if (m.isPressed()) {
               g2.setColor(new Color(0, 0, 0, 40));
               g2.fill(shape);
            } else if (m.isRollover()) {
               g2.setColor(new Color(255, 255, 255, 36));
               g2.fill(shape);
            }
            fg = Theme.INK;
         } else {
            g2.setColor(m.isPressed() ? new Color(255, 255, 255, 40) : m.isRollover() ? new Color(255, 255, 255, 30) : new Color(255, 255, 255, 18));
            g2.fill(shape);
            g2.setColor(m.isRollover() ? Theme.alpha(Theme.SEA, 170) : new Color(255, 255, 255, 46));
            g2.setStroke(new BasicStroke(1.2f));
            g2.draw(shape);
            fg = Theme.TEXT;
         }
         if (isFocusOwner()) {
            g2.setColor(Theme.alpha(Theme.SEA, 200));
            g2.setStroke(new BasicStroke(2f));
            g2.draw(new RoundRectangle2D.Float(2, 2, w - 4, h - 4, h - 4, h - 4));
         }
         paintLabel(g2, this, fg);
         g2.dispose();
      }
   }

   /** Flat text button with a hairline outline on hover (footer actions). */
   public static final class Ghost extends JButton {
      public Ghost(String text, Glyph glyph) {
         super(text, glyph);
         setFont(Theme.medium(12.5f));
         setIconTextGap(7);
         setContentAreaFilled(false);
         setBorderPainted(false);
         setFocusPainted(false);
         setOpaque(false);
         setRolloverEnabled(true);
         setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
         setBorder(BorderFactory.createEmptyBorder(6, 12, 6, 12));
      }

      @Override
      protected void paintComponent(Graphics g) {
         Graphics2D g2 = Theme.smooth(g);
         int w = getWidth();
         int h = getHeight();
         ButtonModel m = getModel();
         RoundRectangle2D shape = new RoundRectangle2D.Float(0.5f, 0.5f, w - 1, h - 1, 14, 14);
         if (isEnabled() && (m.isRollover() || m.isPressed())) {
            g2.setColor(m.isPressed() ? new Color(255, 255, 255, 34) : Theme.HOVER);
            g2.fill(shape);
            g2.setColor(new Color(255, 255, 255, 40));
            g2.draw(shape);
         }
         if (isFocusOwner()) {
            g2.setColor(Theme.alpha(Theme.SEA, 190));
            g2.setStroke(new BasicStroke(1.6f));
            g2.draw(new RoundRectangle2D.Float(1, 1, w - 2, h - 2, 14, 14));
         }
         paintLabel(g2, this, isEnabled() ? (m.isRollover() ? Theme.TEXT : Theme.MUTED) : Theme.FAINT);
         g2.dispose();
      }
   }

   /** Icon and text centred in the button, in one colour. */
   private static void paintLabel(Graphics2D g2, AbstractButton b, Color fg) {
      Insets in = b.getInsets();
      FontMetrics fm = b.getFontMetrics(b.getFont());
      String text = b.getText() == null ? "" : b.getText();
      Icon icon = b.getIcon();
      int tw = fm.stringWidth(text);
      int iw = icon == null ? 0 : icon.getIconWidth() + (text.isEmpty() ? 0 : b.getIconTextGap());
      int x = in.left + (b.getWidth() - in.left - in.right - tw - iw) / 2;
      int h = b.getHeight();
      if (icon instanceof Glyph) {
         ((Glyph) icon).paint(g2, x, (h - icon.getIconHeight()) / 2, fg);
      } else if (icon != null) {
         icon.paintIcon(b, g2, x, (h - icon.getIconHeight()) / 2);
      }
      g2.setFont(b.getFont());
      g2.setColor(fg);
      g2.drawString(text, x + iw, (h - fm.getHeight()) / 2 + fm.getAscent());
   }

   // ------------------------------------------------------------ surfaces

   /** Translucent rounded panel with a hairline edge. */
   public static class Card extends JPanel {
      private final int radius;

      public Card(LayoutManager layout, int radius) {
         super(layout);
         this.radius = radius;
         setOpaque(false);
      }

      @Override
      protected void paintComponent(Graphics g) {
         Graphics2D g2 = Theme.smooth(g);
         RoundRectangle2D shape = new RoundRectangle2D.Float(0.5f, 0.5f, getWidth() - 1, getHeight() - 1, radius, radius);
         g2.setColor(Theme.CARD_BASE);
         g2.fill(shape);
         g2.setColor(Theme.CARD);
         g2.fill(shape);
         g2.setColor(Theme.CARD_EDGE);
         g2.draw(shape);
         g2.dispose();
      }
   }

   // ------------------------------------------------------------ fields

   public static final class Field extends JTextField {
      private final String placeholder;

      public Field(int columns, String placeholder) {
         super(columns);
         this.placeholder = placeholder;
         styleText(this);
      }

      @Override
      protected void paintComponent(Graphics g) {
         paintField(g, this);
         super.paintComponent(g);
         paintPlaceholder(g, this, placeholder);
      }
   }

   public static final class Secret extends JPasswordField {
      private final String placeholder;

      public Secret(int columns, String placeholder) {
         super(columns);
         this.placeholder = placeholder;
         styleText(this);
         setEchoChar('•');
      }

      @Override
      protected void paintComponent(Graphics g) {
         paintField(g, this);
         super.paintComponent(g);
         paintPlaceholder(g, this, placeholder);
      }
   }

   private static void styleText(JTextComponent t) {
      t.setOpaque(false);
      t.setFont(Theme.regular(13.5f));
      t.setForeground(Theme.TEXT);
      t.setCaretColor(Theme.SEA);
      t.setSelectionColor(Theme.alpha(Theme.SEA, 90));
      t.setSelectedTextColor(Theme.TEXT);
      t.setDisabledTextColor(Theme.FAINT);
      t.setBorder(BorderFactory.createEmptyBorder(8, 12, 8, 12));
      t.addFocusListener(new FocusAdapter() {
         @Override
         public void focusGained(FocusEvent e) {
            t.repaint();
         }

         @Override
         public void focusLost(FocusEvent e) {
            t.repaint();
         }
      });
   }

   private static void paintField(Graphics g, JTextComponent t) {
      Graphics2D g2 = Theme.smooth(g);
      RoundRectangle2D shape = new RoundRectangle2D.Float(0.5f, 0.5f, t.getWidth() - 1, t.getHeight() - 1, 14, 14);
      g2.setColor(t.isEnabled() ? Theme.FIELD : Theme.FIELD_OFF);
      g2.fill(shape);
      g2.setColor(t.isFocusOwner() ? Theme.alpha(Theme.SEA, 210) : t.isEnabled() ? Theme.FIELD_EDGE : new Color(255, 255, 255, 18));
      g2.setStroke(new BasicStroke(t.isFocusOwner() ? 1.6f : 1f));
      g2.draw(shape);
      g2.dispose();
   }

   private static void paintPlaceholder(Graphics g, JTextComponent t, String placeholder) {
      if (placeholder == null || t.getDocument().getLength() > 0 || t.isFocusOwner()) {
         return;
      }
      Graphics2D g2 = Theme.smooth(g);
      Insets in = t.getInsets();
      FontMetrics fm = g2.getFontMetrics(t.getFont());
      g2.setFont(t.getFont());
      g2.setColor(t.isEnabled() ? Theme.FAINT : Theme.alpha(Theme.FAINT, 120));
      g2.drawString(placeholder, in.left, (t.getHeight() - fm.getHeight()) / 2 + fm.getAscent());
      g2.dispose();
   }

   // ------------------------------------------------------ segmented control

   /** A row of mutually exclusive choices on one track (the server mode). */
   public static final class Segmented extends JPanel {
      private final JToggleButton[] items;
      private final ButtonGroup group = new ButtonGroup();

      public Segmented(String... labels) {
         super(new GridLayout(1, labels.length, 4, 0));
         setOpaque(false);
         setBorder(BorderFactory.createEmptyBorder(4, 4, 4, 4));
         items = new JToggleButton[labels.length];
         for (int i = 0; i < labels.length; i++) {
            JToggleButton b = new Segment(labels[i]);
            items[i] = b;
            group.add(b);
            add(b);
         }
         items[0].setSelected(true);
      }

      public int selected() {
         for (int i = 0; i < items.length; i++) {
            if (items[i].isSelected()) {
               return i;
            }
         }
         return 0;
      }

      public void select(int i) {
         items[Math.max(0, Math.min(items.length - 1, i))].setSelected(true);
      }

      public void onChange(IntConsumer l) {
         for (JToggleButton b : items) {
            b.addItemListener(e -> {
               if (b.isSelected()) {
                  l.accept(selected());
               }
            });
         }
      }

      @Override
      public void setEnabled(boolean on) {
         super.setEnabled(on);
         for (JToggleButton b : items) {
            b.setEnabled(on);
         }
      }

      @Override
      protected void paintComponent(Graphics g) {
         Graphics2D g2 = Theme.smooth(g);
         RoundRectangle2D shape = new RoundRectangle2D.Float(0.5f, 0.5f, getWidth() - 1, getHeight() - 1, 16, 16);
         g2.setColor(Theme.FIELD);
         g2.fill(shape);
         g2.setColor(Theme.FIELD_EDGE);
         g2.draw(shape);
         g2.dispose();
      }
   }

   private static final class Segment extends JToggleButton {
      Segment(String text) {
         super(text);
         setFont(Theme.medium(12.5f));
         setContentAreaFilled(false);
         setBorderPainted(false);
         setFocusPainted(false);
         setOpaque(false);
         setRolloverEnabled(true);
         setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
         setBorder(BorderFactory.createEmptyBorder(7, 8, 7, 8));
      }

      @Override
      protected void paintComponent(Graphics g) {
         Graphics2D g2 = Theme.smooth(g);
         int w = getWidth();
         int h = getHeight();
         ButtonModel m = getModel();
         RoundRectangle2D shape = new RoundRectangle2D.Float(0.5f, 0.5f, w - 1, h - 1, 12, 12);
         if (isSelected()) {
            g2.setColor(Theme.SELECTED);
            g2.fill(shape);
            g2.setColor(Theme.alpha(Theme.SEA, isEnabled() ? 160 : 60));
            g2.draw(shape);
         } else if (m.isRollover() && isEnabled()) {
            g2.setColor(Theme.HOVER);
            g2.fill(shape);
         }
         if (isFocusOwner()) {
            g2.setColor(Theme.alpha(Theme.SEA, 220));
            g2.setStroke(new BasicStroke(1.6f));
            g2.draw(new RoundRectangle2D.Float(1.5f, 1.5f, w - 3, h - 3, 11, 11));
         }
         Color fg = !isEnabled() ? Theme.FAINT : isSelected() || m.isRollover() ? Theme.TEXT : Theme.MUTED;
         paintLabel(g2, this, fg);
         g2.dispose();
      }
   }

   // ------------------------------------------------------------ checkboxes

   public static JCheckBox check(String text) {
      JCheckBox c = new JCheckBox(text);
      c.setOpaque(false);
      c.setFont(Theme.regular(13f));
      c.setForeground(Theme.TEXT);
      c.setFocusPainted(false);
      c.setIconTextGap(10);
      c.setIcon(new CheckIcon(false, false));
      c.setSelectedIcon(new CheckIcon(true, false));
      c.setRolloverIcon(new CheckIcon(false, true));
      c.setRolloverSelectedIcon(new CheckIcon(true, true));
      c.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
      return c;
   }

   private static final class CheckIcon implements Icon {
      private final boolean on;
      private final boolean hover;

      CheckIcon(boolean on, boolean hover) {
         this.on = on;
         this.hover = hover;
      }

      @Override
      public void paintIcon(Component c, Graphics g, int x, int y) {
         Graphics2D g2 = Theme.smooth(g);
         RoundRectangle2D box = new RoundRectangle2D.Float(x + 0.5f, y + 0.5f, 17, 17, 6, 6);
         boolean enabled = c == null || c.isEnabled();
         if (on) {
            g2.setColor(enabled ? Theme.SEA : Theme.alpha(Theme.SEA, 90));
            g2.fill(box);
            Path2D.Float tick = new Path2D.Float();
            tick.moveTo(x + 4.5f, y + 9.5f);
            tick.lineTo(x + 7.8f, y + 12.8f);
            tick.lineTo(x + 13.8f, y + 5.8f);
            g2.setColor(Theme.INK);
            g2.setStroke(new BasicStroke(2.2f, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND));
            g2.draw(tick);
         } else {
            g2.setColor(Theme.FIELD);
            g2.fill(box);
            g2.setColor(hover && enabled ? Theme.alpha(Theme.SEA, 200) : new Color(255, 255, 255, enabled ? 80 : 40));
            g2.setStroke(new BasicStroke(1.3f));
            g2.draw(box);
         }
         g2.dispose();
      }

      @Override
      public int getIconWidth() {
         return 18;
      }

      @Override
      public int getIconHeight() {
         return 18;
      }
   }

   // ------------------------------------------------------ stepper (threads)

   /** "−  Auto  +": a small integer from 0 (shown as the zero label) to max. */
   public static final class Stepper extends JPanel {
      private final JLabel value = new JLabel("", SwingConstants.CENTER);
      private final String zero;
      private final int max;
      private int v;

      public Stepper(int initial, int max, String zero) {
         super(new FlowLayout(FlowLayout.LEFT, 4, 0));
         this.zero = zero;
         this.max = max;
         setOpaque(false);
         Ghost minus = new Ghost("", new Glyph(Glyph.Kind.MINUS, 12));
         Ghost plus = new Ghost("", new Glyph(Glyph.Kind.PLUS, 12));
         value.setFont(Theme.semibold(13f));
         value.setForeground(Theme.TEXT);
         value.setPreferredSize(new Dimension(58, 26));
         minus.addActionListener(e -> set(v - 1));
         plus.addActionListener(e -> set(v + 1));
         add(minus);
         add(value);
         add(plus);
         set(initial);
      }

      public void set(int n) {
         v = Math.max(0, Math.min(max, n));
         value.setText(v == 0 ? zero : Integer.toString(v));
      }

      public int get() {
         return v;
      }
   }

   // ------------------------------------------------------------ scroll

   public static JScrollPane scroll(JComponent view) {
      JScrollPane sp = new JScrollPane(view);
      sp.setOpaque(false);
      sp.getViewport().setOpaque(false);
      sp.setBorder(BorderFactory.createEmptyBorder());
      sp.setViewportBorder(null);
      JScrollBar bar = sp.getVerticalScrollBar();
      bar.setUI(new ThinScrollBar());
      bar.setOpaque(false);
      bar.setPreferredSize(new Dimension(10, 0));
      bar.setUnitIncrement(16);
      sp.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
      return sp;
   }

   private static final class ThinScrollBar extends BasicScrollBarUI {
      @Override
      protected void configureScrollBarColors() {
         thumbColor = new Color(255, 255, 255, 60);
         trackColor = new Color(0, 0, 0, 0);
      }

      @Override
      protected JButton createDecreaseButton(int orientation) {
         return zero();
      }

      @Override
      protected JButton createIncreaseButton(int orientation) {
         return zero();
      }

      private static JButton zero() {
         JButton b = new JButton();
         b.setPreferredSize(new Dimension(0, 0));
         b.setMinimumSize(new Dimension(0, 0));
         b.setMaximumSize(new Dimension(0, 0));
         return b;
      }

      @Override
      protected void paintTrack(Graphics g, JComponent c, Rectangle r) {
         // no track: just the thumb
      }

      @Override
      protected void paintThumb(Graphics g, JComponent c, Rectangle r) {
         if (r.isEmpty() || !scrollbar.isEnabled()) {
            return;
         }
         Graphics2D g2 = Theme.smooth(g);
         g2.setColor(isThumbRollover() ? new Color(255, 255, 255, 110) : thumbColor);
         g2.fill(new RoundRectangle2D.Float(r.x + 3, r.y + 2, r.width - 6, r.height - 4, r.width - 6, r.width - 6));
         g2.dispose();
      }
   }

   // ------------------------------------------------------------ text

   /**
    * A paragraph that wraps at its real width (an HTML JLabel measures its
    * CSS width in its own units and clips). Until it is laid out it asks for
    * the given width.
    */
   public static final class Note extends JComponent {
      private String text = "";
      private final int widthHint;
      private int laidOutWidth = -1;

      public Note(String text, Font font, Color color, int widthHint) {
         this.widthHint = widthHint;
         setFont(font);
         setForeground(color);
         setOpaque(false);
         setText(text);
      }

      public void setText(String t) {
         text = t == null ? "" : t;
         revalidate();
         repaint();
      }

      public String getText() {
         return text;
      }

      @Override
      public Dimension getPreferredSize() {
         int w = getWidth() > 0 ? getWidth() : widthHint;
         FontMetrics fm = getFontMetrics(getFont());
         return new Dimension(widthHint, Math.max(1, lines(fm, w).size()) * fm.getHeight());
      }

      @Override
      public Dimension getMinimumSize() {
         return new Dimension(40, getPreferredSize().height);
      }

      @Override
      public void setBounds(int x, int y, int w, int h) {
         super.setBounds(x, y, w, h);
         if (w != laidOutWidth) {
            laidOutWidth = w;
            javax.swing.SwingUtilities.invokeLater(this::revalidate);
         }
      }

      private java.util.List<String> lines(FontMetrics fm, int width) {
         java.util.List<String> out = new java.util.ArrayList<>();
         for (String para : text.split("\n", -1)) {
            StringBuilder line = new StringBuilder();
            for (String word : para.split(" ")) {
               String next = line.length() == 0 ? word : line + " " + word;
               if (fm.stringWidth(next) > width && line.length() > 0) {
                  out.add(line.toString());
                  line = new StringBuilder(word);
               } else {
                  line = new StringBuilder(next);
               }
            }
            out.add(line.toString());
         }
         return out;
      }

      @Override
      protected void paintComponent(Graphics g) {
         Graphics2D g2 = Theme.smooth(g);
         g2.setFont(getFont());
         g2.setColor(getForeground());
         FontMetrics fm = g2.getFontMetrics();
         int y = fm.getAscent();
         for (String l : lines(fm, getWidth())) {
            g2.drawString(l, 0, y);
            y += fm.getHeight();
         }
         g2.dispose();
      }
   }

   // ------------------------------------------------------------ lists

   /** A transparent panel for {@link #scroll} that follows the viewport's width and only scrolls vertically. */
   public static class ScrollPanel extends JPanel implements javax.swing.Scrollable {
      public ScrollPanel(LayoutManager layout) {
         super(layout);
         setOpaque(false);
      }

      @Override
      public Dimension getPreferredScrollableViewportSize() {
         return getPreferredSize();
      }

      @Override
      public int getScrollableUnitIncrement(Rectangle visible, int orientation, int direction) {
         return 18;
      }

      @Override
      public int getScrollableBlockIncrement(Rectangle visible, int orientation, int direction) {
         return Math.max(18, visible.height - 36);
      }

      @Override
      public boolean getScrollableTracksViewportWidth() {
         return true;
      }

      @Override
      public boolean getScrollableTracksViewportHeight() {
         return false;
      }
   }

   /**
    * A list on the card: rounded rows that light up under the mouse and when
    * selected, each painted by a {@link Painter} (see {@link #drawRow} for
    * the usual dot, title, subtitle and badges).
    */
   public static final class Rows<T> extends javax.swing.JList<T> {
      public interface Painter<T> {
         void paint(Graphics2D g, T value, int width, int height, boolean enabled);
      }

      private int hover = -1;

      public Rows(javax.swing.ListModel<T> model, int rowHeight, Painter<T> painter) {
         super(model);
         setOpaque(false);
         setBackground(new Color(0, 0, 0, 0));
         setSelectionMode(javax.swing.ListSelectionModel.SINGLE_SELECTION);
         setFixedCellHeight(rowHeight);
         setCellRenderer(new javax.swing.ListCellRenderer<T>() {
            private final RowView view = new RowView();

            @Override
            public Component getListCellRendererComponent(javax.swing.JList<? extends T> list, T value, int index,
                                                          boolean selected, boolean focus) {
               view.set(value, selected, index == hover, list.isEnabled());
               return view;
            }

            final class RowView extends JComponent {
               private T value;
               private boolean selected;
               private boolean hovered;
               private boolean enabled;

               void set(T v, boolean s, boolean h, boolean e) {
                  value = v;
                  selected = s;
                  hovered = h;
                  enabled = e;
               }

               @Override
               protected void paintComponent(Graphics g) {
                  Graphics2D g2 = Theme.smooth(g);
                  int w = getWidth();
                  int h = getHeight();
                  RoundRectangle2D row = new RoundRectangle2D.Float(1, 2, w - 4, h - 4, 14, 14);
                  if (selected) {
                     g2.setColor(Theme.SELECTED);
                     g2.fill(row);
                     g2.setColor(Theme.alpha(Theme.SEA, enabled ? 130 : 60));
                     g2.draw(row);
                  } else if (hovered && enabled) {
                     g2.setColor(Theme.HOVER);
                     g2.fill(row);
                  }
                  if (value != null) {
                     painter.paint(g2, value, w, h, enabled);
                  }
                  g2.dispose();
               }
            }
         });
         addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            @Override
            public void mouseMoved(java.awt.event.MouseEvent e) {
               int i = locationToIndex(e.getPoint());
               int h = i >= 0 && getCellBounds(i, i).contains(e.getPoint()) ? i : -1;
               if (h != hover) {
                  hover = h;
                  repaint();
               }
            }
         });
         addMouseListener(new java.awt.event.MouseAdapter() {
            @Override
            public void mouseExited(java.awt.event.MouseEvent e) {
               hover = -1;
               repaint();
            }
         });
      }
   }

   /**
    * The usual row: a status dot, a title and a subtitle, and small badges
    * ("VIP", "TLS"...) on the right.
    */
   public static void drawRow(Graphics2D g2, int w, int h, Color dot, String title, String subtitle, boolean enabled,
                              String... badges) {
      int right = w - 12;
      g2.setFont(Theme.semibold(10f));
      FontMetrics bm = g2.getFontMetrics();
      for (int i = badges.length - 1; i >= 0; i--) {
         String b = badges[i];
         if (b == null || b.isEmpty()) {
            continue;
         }
         int bw = bm.stringWidth(b) + 14;
         RoundRectangle2D pill = new RoundRectangle2D.Float(right - bw, h / 2f - 9, bw, 18, 18, 18);
         g2.setColor(Theme.alpha(Theme.SEA, enabled ? 40 : 20));
         g2.fill(pill);
         g2.setColor(Theme.alpha(Theme.SEA, enabled ? 150 : 70));
         g2.draw(pill);
         g2.setColor(enabled ? Theme.TEXT : Theme.FAINT);
         g2.drawString(b, right - bw + 7, h / 2 + bm.getAscent() / 2 - 1);
         right -= bw + 6;
      }
      if (dot != null) {
         g2.setColor(enabled ? dot : Theme.alpha(dot, 110));
         g2.fill(new Ellipse2D.Float(14, h / 2f - 4.5f, 9, 9));
      }
      int x = dot != null ? 34 : 14;
      g2.setFont(Theme.semibold(13.5f));
      g2.setColor(enabled ? Theme.TEXT : Theme.FAINT);
      g2.drawString(fit(title, g2.getFontMetrics(), right - x - 6), x, subtitle == null ? h / 2 + 5 : h / 2 - 2);
      if (subtitle != null) {
         g2.setFont(Theme.regular(11f));
         g2.setColor(enabled ? Theme.MUTED : Theme.FAINT);
         g2.drawString(fit(subtitle, g2.getFontMetrics(), right - x - 6), x, h / 2 + 13);
      }
   }

   /** {@code s} cut with an ellipsis to fit {@code width}. */
   public static String fit(String s, FontMetrics fm, int width) {
      if (s == null) {
         return "";
      }
      if (fm.stringWidth(s) <= width) {
         return s;
      }
      String t = s;
      while (t.length() > 1 && fm.stringWidth(t + "\u2026") > width) {
         t = t.substring(0, t.length() - 1);
      }
      return t + "\u2026";
   }

   // ------------------------------------------------------------ wordmark

   /** An app's name with one part in the ring's gradient: "Open" + "Worlds", or "J " + "Solar" + " Server". */
   public static final class Wordmark extends JComponent {
      private final Font font;
      private final String before;
      private final String accent;
      private final String after;

      /** "OpenWorlds". */
      public Wordmark(float size) {
         this("Open", "Worlds", "", size);
      }

      public Wordmark(String before, String accent, String after, float size) {
         this.before = before;
         this.accent = accent;
         this.after = after;
         font = Theme.bold(size);
         setOpaque(false);
         FontMetrics fm = getFontMetrics(font);
         setPreferredSize(new Dimension(fm.stringWidth(before + accent + after) + 4, fm.getAscent() + fm.getDescent()));
         setMaximumSize(getPreferredSize());
         setMinimumSize(getPreferredSize());
      }

      @Override
      protected void paintComponent(Graphics g) {
         Graphics2D g2 = Theme.smooth(g);
         g2.setFont(font);
         FontMetrics fm = g2.getFontMetrics();
         int x = (getWidth() - fm.stringWidth(before + accent + after)) / 2;
         int y = fm.getAscent();
         g2.setColor(Theme.TEXT);
         g2.drawString(before, x, y);
         int ax = x + fm.stringWidth(before);
         g2.setPaint(Theme.ring(ax, ax + fm.stringWidth(accent), 0));
         g2.drawString(accent, ax, y);
         g2.setColor(Theme.TEXT);
         g2.drawString(after, ax + fm.stringWidth(accent), y);
         g2.dispose();
      }
   }

   // ------------------------------------------------------------ dialogs

   /** A modal message in the app's colours; returns true if the first button was pressed. */
   public static boolean ask(Component parent, String title, String message, String yes, String no) {
      java.awt.Window owner = parent == null ? null : javax.swing.SwingUtilities.getWindowAncestor(parent);
      if (owner == null && parent instanceof java.awt.Window) {
         owner = (java.awt.Window) parent;
      }
      javax.swing.JDialog d = new javax.swing.JDialog(owner, title, java.awt.Dialog.ModalityType.APPLICATION_MODAL);
      boolean[] answer = {false};
      SpaceBackground root = new SpaceBackground(new java.awt.BorderLayout(0, 18), false);
      root.setBorder(BorderFactory.createEmptyBorder(22, 26, 18, 26));
      root.add(new Note(message, Theme.regular(13.5f), Theme.TEXT, 340), java.awt.BorderLayout.CENTER);
      JPanel buttons = new JPanel(new FlowLayout(FlowLayout.RIGHT, 8, 0));
      buttons.setOpaque(false);
      if (no != null) {
         Ghost n = new Ghost(no, null);
         n.addActionListener(e -> d.dispose());
         buttons.add(n);
      }
      Pill y = new Pill(yes, null, Pill.Kind.PRIMARY, 13f);
      y.addActionListener(e -> {
         answer[0] = true;
         d.dispose();
      });
      buttons.add(y);
      root.add(buttons, java.awt.BorderLayout.SOUTH);
      d.setContentPane(root);
      d.getRootPane().setDefaultButton(y);
      d.setResizable(false);
      d.pack();
      d.setLocationRelativeTo(owner);
      d.setVisible(true);
      return answer[0];
   }

   // ------------------------------------------------------------ icons

   /** Vector icons drawn in the text colour of their button (no emoji: they depend on the system fonts). */
   public static final class Glyph implements Icon {
      public enum Kind { PLAY, STOP, GEAR, FOLDER, DOWNLOAD, REFRESH, PLUS, MINUS, CLOSE, USER, LOCK, CHAT, SEND, COPY,
         TRASH, STAR, POWER, KEY, PUZZLE, CHECK, GLOBE }

      public final Kind kind;
      public final int size;

      public Glyph(Kind kind, int size) {
         this.kind = kind;
         this.size = size;
      }

      @Override
      public int getIconWidth() {
         return size;
      }

      @Override
      public int getIconHeight() {
         return size;
      }

      @Override
      public void paintIcon(Component c, Graphics g, int x, int y) {
         Graphics2D g2 = Theme.smooth(g);
         paint(g2, x, y, c == null ? Theme.TEXT : c.getForeground());
         g2.dispose();
      }

      public void paint(Graphics2D g, int x, int y, Color color) {
         Graphics2D g2 = (Graphics2D) g.create();
         g2.translate(x, y);
         float s = size;
         g2.setColor(color);
         g2.setStroke(new BasicStroke(Math.max(1.4f, s / 9f), BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND));
         switch (kind) {
            case PLAY: {
               Path2D.Float p = new Path2D.Float();
               p.moveTo(s * 0.2f, s * 0.08f);
               p.lineTo(s * 0.92f, s * 0.5f);
               p.lineTo(s * 0.2f, s * 0.92f);
               p.closePath();
               g2.fill(p);
               break;
            }
            case STOP:
               g2.fill(new RoundRectangle2D.Float(s * 0.15f, s * 0.15f, s * 0.7f, s * 0.7f, s * 0.2f, s * 0.2f));
               break;
            case GEAR: {
               Area a = new Area(new Ellipse2D.Float(s * 0.2f, s * 0.2f, s * 0.6f, s * 0.6f));
               for (int i = 0; i < 8; i++) {
                  RoundRectangle2D.Float tooth = new RoundRectangle2D.Float(s * 0.42f, 0, s * 0.16f, s * 0.3f, s * 0.08f, s * 0.08f);
                  a.add(new Area(AffineTransform.getRotateInstance(Math.PI / 4 * i, s / 2, s / 2).createTransformedShape(tooth)));
               }
               a.subtract(new Area(new Ellipse2D.Float(s * 0.36f, s * 0.36f, s * 0.28f, s * 0.28f)));
               g2.fill(a);
               break;
            }
            case FOLDER: {
               Path2D.Float p = new Path2D.Float();
               p.moveTo(s * 0.06f, s * 0.22f);
               p.lineTo(s * 0.38f, s * 0.22f);
               p.lineTo(s * 0.48f, s * 0.34f);
               p.lineTo(s * 0.94f, s * 0.34f);
               p.lineTo(s * 0.94f, s * 0.84f);
               p.lineTo(s * 0.06f, s * 0.84f);
               p.closePath();
               g2.draw(p);
               break;
            }
            case DOWNLOAD: {
               Path2D.Float p = new Path2D.Float();
               p.moveTo(s * 0.5f, s * 0.08f);
               p.lineTo(s * 0.5f, s * 0.64f);
               p.moveTo(s * 0.26f, s * 0.42f);
               p.lineTo(s * 0.5f, s * 0.66f);
               p.lineTo(s * 0.74f, s * 0.42f);
               p.moveTo(s * 0.1f, s * 0.9f);
               p.lineTo(s * 0.9f, s * 0.9f);
               g2.draw(p);
               break;
            }
            case REFRESH: {
               g2.draw(new java.awt.geom.Arc2D.Float(s * 0.14f, s * 0.14f, s * 0.72f, s * 0.72f, 40, 280, java.awt.geom.Arc2D.OPEN));
               Path2D.Float p = new Path2D.Float();
               p.moveTo(s * 0.9f, s * 0.08f);
               p.lineTo(s * 0.8f, s * 0.36f);
               p.lineTo(s * 0.54f, s * 0.26f);
               g2.draw(p);
               break;
            }
            case PLUS:
               g2.drawLine(Math.round(s * 0.5f), Math.round(s * 0.15f), Math.round(s * 0.5f), Math.round(s * 0.85f));
               g2.drawLine(Math.round(s * 0.15f), Math.round(s * 0.5f), Math.round(s * 0.85f), Math.round(s * 0.5f));
               break;
            case MINUS:
               g2.drawLine(Math.round(s * 0.15f), Math.round(s * 0.5f), Math.round(s * 0.85f), Math.round(s * 0.5f));
               break;
            case CLOSE:
               g2.drawLine(Math.round(s * 0.2f), Math.round(s * 0.2f), Math.round(s * 0.8f), Math.round(s * 0.8f));
               g2.drawLine(Math.round(s * 0.8f), Math.round(s * 0.2f), Math.round(s * 0.2f), Math.round(s * 0.8f));
               break;
            case USER:
               g2.fill(new Ellipse2D.Float(s * 0.32f, s * 0.06f, s * 0.36f, s * 0.36f));
               g2.fill(new java.awt.geom.Arc2D.Float(s * 0.12f, s * 0.5f, s * 0.76f, s * 0.8f, 0, 180, java.awt.geom.Arc2D.CHORD));
               break;
            case LOCK:
               g2.draw(new java.awt.geom.Arc2D.Float(s * 0.27f, s * 0.08f, s * 0.46f, s * 0.5f, 0, 180, java.awt.geom.Arc2D.OPEN));
               g2.drawLine(Math.round(s * 0.27f), Math.round(s * 0.33f), Math.round(s * 0.27f), Math.round(s * 0.44f));
               g2.drawLine(Math.round(s * 0.73f), Math.round(s * 0.33f), Math.round(s * 0.73f), Math.round(s * 0.44f));
               g2.fill(new RoundRectangle2D.Float(s * 0.14f, s * 0.42f, s * 0.72f, s * 0.52f, s * 0.14f, s * 0.14f));
               break;
            case CHAT: {
               Area a = new Area(new RoundRectangle2D.Float(s * 0.06f, s * 0.1f, s * 0.88f, s * 0.62f, s * 0.3f, s * 0.3f));
               Path2D.Float tail = new Path2D.Float();
               tail.moveTo(s * 0.24f, s * 0.6f);
               tail.lineTo(s * 0.2f, s * 0.92f);
               tail.lineTo(s * 0.5f, s * 0.66f);
               tail.closePath();
               a.add(new Area(tail));
               g2.draw(a);
               break;
            }
            case SEND: {
               Path2D.Float p = new Path2D.Float();
               p.moveTo(s * 0.06f, s * 0.46f);
               p.lineTo(s * 0.94f, s * 0.08f);
               p.lineTo(s * 0.62f, s * 0.92f);
               p.lineTo(s * 0.46f, s * 0.56f);
               p.closePath();
               g2.fill(p);
               break;
            }
            case COPY:
               g2.draw(new RoundRectangle2D.Float(s * 0.3f, s * 0.08f, s * 0.6f, s * 0.6f, s * 0.14f, s * 0.14f));
               g2.draw(new RoundRectangle2D.Float(s * 0.1f, s * 0.32f, s * 0.6f, s * 0.6f, s * 0.14f, s * 0.14f));
               break;
            case TRASH: {
               g2.drawLine(Math.round(s * 0.1f), Math.round(s * 0.22f), Math.round(s * 0.9f), Math.round(s * 0.22f));
               g2.drawLine(Math.round(s * 0.38f), Math.round(s * 0.08f), Math.round(s * 0.62f), Math.round(s * 0.08f));
               Path2D.Float p = new Path2D.Float();
               p.moveTo(s * 0.2f, s * 0.3f);
               p.lineTo(s * 0.26f, s * 0.92f);
               p.lineTo(s * 0.74f, s * 0.92f);
               p.lineTo(s * 0.8f, s * 0.3f);
               g2.draw(p);
               break;
            }
            case STAR: {
               Path2D.Float p = new Path2D.Float();
               for (int i = 0; i < 10; i++) {
                  double r = i % 2 == 0 ? s * 0.48 : s * 0.2;
                  double a = -Math.PI / 2 + i * Math.PI / 5;
                  float px = (float) (s / 2 + Math.cos(a) * r);
                  float py = (float) (s * 0.54 + Math.sin(a) * r);
                  if (i == 0) {
                     p.moveTo(px, py);
                  } else {
                     p.lineTo(px, py);
                  }
               }
               p.closePath();
               g2.fill(p);
               break;
            }
            case POWER:
               g2.draw(new java.awt.geom.Arc2D.Float(s * 0.12f, s * 0.14f, s * 0.76f, s * 0.76f, 125, 290, java.awt.geom.Arc2D.OPEN));
               g2.drawLine(Math.round(s * 0.5f), Math.round(s * 0.06f), Math.round(s * 0.5f), Math.round(s * 0.46f));
               break;
            case KEY:
               g2.draw(new Ellipse2D.Float(s * 0.06f, s * 0.3f, s * 0.38f, s * 0.38f));
               g2.drawLine(Math.round(s * 0.44f), Math.round(s * 0.49f), Math.round(s * 0.94f), Math.round(s * 0.49f));
               g2.drawLine(Math.round(s * 0.78f), Math.round(s * 0.49f), Math.round(s * 0.78f), Math.round(s * 0.7f));
               g2.drawLine(Math.round(s * 0.92f), Math.round(s * 0.49f), Math.round(s * 0.92f), Math.round(s * 0.66f));
               break;
            case PUZZLE: {
               Area a = new Area(new RoundRectangle2D.Float(s * 0.08f, s * 0.24f, s * 0.64f, s * 0.64f, s * 0.12f, s * 0.12f));
               a.add(new Area(new Ellipse2D.Float(s * 0.28f, s * 0.04f, s * 0.24f, s * 0.26f)));
               a.add(new Area(new Ellipse2D.Float(s * 0.66f, s * 0.44f, s * 0.26f, s * 0.24f)));
               g2.fill(a);
               break;
            }
            case CHECK: {
               Path2D.Float p = new Path2D.Float();
               p.moveTo(s * 0.12f, s * 0.52f);
               p.lineTo(s * 0.4f, s * 0.8f);
               p.lineTo(s * 0.9f, s * 0.22f);
               g2.draw(p);
               break;
            }
            case GLOBE:
               g2.draw(new Ellipse2D.Float(s * 0.08f, s * 0.08f, s * 0.84f, s * 0.84f));
               g2.draw(new Ellipse2D.Float(s * 0.3f, s * 0.08f, s * 0.4f, s * 0.84f));
               g2.drawLine(Math.round(s * 0.08f), Math.round(s * 0.5f), Math.round(s * 0.92f), Math.round(s * 0.5f));
               break;
            default:
               break;
         }
         g2.dispose();
      }
   }
}
