import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Canvas;
import java.awt.Checkbox;
import java.awt.CheckboxMenuItem;
import java.awt.Choice;
import java.awt.Color;
import java.awt.Component;
import java.awt.Event;
import java.awt.EventQueue;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Label;
import java.awt.List;
import java.awt.Menu;
import java.awt.MenuBar;
import java.awt.MenuItem;
import java.awt.MenuShortcut;
import java.awt.Panel;
import java.awt.Point;
import java.awt.PopupMenu;
import java.awt.ScrollPane;
import java.awt.TextArea;
import java.awt.TextField;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import java.io.File;
import java.util.ArrayList;

import net.openworlds.awt.HeadlessScreen;
import net.openworlds.awt.Screen;

/**
 * Runs our java.awt (vita/runtime) on a desktop JVM with only java.base, on
 * a screen in memory, the way the 2004 client uses AWT: a Frame with the
 * 1.0 event model (action/handleEvent), a menu bar with a shortcut, a
 * submenu and a check item, a Choice, a List, a TextField, a ScrollPane and
 * a PopupMenu shown from a mouse handler. Input is injected as the screen
 * would deliver it; each step checks what reached the client, and the
 * screen is saved as PNG files in the directory given (to look at).
 *
 *   vita/tools/run-awt-check.sh
 */
public class AwtCheck {
   static final ArrayList<String> log = new ArrayList<String>();
   static int failures;
   static int checks;
   static HeadlessScreen screen;
   static File out;

   static void record(String s) {
      synchronized (log) {
         log.add(s);
         log.notifyAll();
      }
   }

   static boolean logged(String s) {
      synchronized (log) {
         return log.contains(s);
      }
   }

   static void check(boolean ok, String what) {
      checks++;
      if (!ok) {
         failures++;
         synchronized (log) {
            System.out.println("FAIL " + what + "   (events: " + log + ")");
         }
      } else {
         System.out.println("ok   " + what);
      }
   }

   /** Waits until the input and the event queue are idle and the screen shows the result. */
   static void settle() throws Exception {
      for (int i = 0; i < 3; i++) {
         Thread.sleep(40);
         EventQueue.invokeAndWait(new Runnable() {
            public void run() {
            }
         });
      }
      Thread.sleep(30);
   }

   static void waitFor(String s) throws Exception {
      long end = System.currentTimeMillis() + 2000;
      synchronized (log) {
         while (!log.contains(s) && System.currentTimeMillis() < end) {
            log.wait(50);
         }
      }
   }

   static void save(String name) throws Exception {
      screen.savePng(new File(out, name + ".png"));
   }

   static Point at(Component c, int dx, int dy) {
      Point p = c.getLocationOnScreen();
      return new Point(p.x + dx, p.y + dy);
   }

   static void click(Point p) {
      screen.click(p.x, p.y);
   }

   static void move(int x, int y) {
      screen.inject(Screen.POINTER_MOVED, x, y, 0, 0, 0, 0);
   }

   static class Client extends Frame {
      final Choice choice = new Choice();
      final TextField field = new TextField(20);
      final Button go = new Button("Go");
      final Checkbox fast = new Checkbox("Fast");
      final List list = new List(6);
      final ScrollPane scroll = new ScrollPane(ScrollPane.SCROLLBARS_ALWAYS);
      final Panel big = new Panel(new GridBagLayout());
      final Canvas view = new Canvas() {
         public void paint(Graphics g) {
            g.setColor(new Color(0x20, 0x40, 0x80));
            g.fillRect(0, 0, getWidth(), getHeight());
            g.setColor(Color.white);
            g.drawString("3D view", 10, 20);
         }

         public boolean handleEvent(Event e) {
            if (e.id == Event.MOUSE_DOWN && (e.modifiers & Event.META_MASK) != 0) {
               // the client shows its action menus from mouse handlers (Shape.handle)
               PopupMenu pm = new PopupMenu();
               pm.add("Wave");
               pm.add("Dance");
               add(pm);
               record("before show");
               pm.show(this, e.x, e.y);
               record("after show");
               return true;
            }
            return super.handleEvent(e);
         }

         public boolean action(Event e, Object arg) {
            record("view action " + arg);
            return true;
         }
      };

      Client() {
         super("AwtCheck");
         MenuBar mb = new MenuBar();
         Menu file = new Menu("File");
         file.add(new MenuItem("Open"));
         file.add(new MenuItem("Save", new MenuShortcut(KeyEvent.VK_S)));
         file.addSeparator();
         Menu recent = new Menu("Recent");
         recent.add("one.world");
         recent.add("two.world");
         file.add(recent);
         file.add(new CheckboxMenuItem("Sound", true));
         MenuItem off = new MenuItem("Disabled");
         off.setEnabled(false);
         file.add(off);
         mb.add(file);
         Menu help = new Menu("Help");
         help.add("About");
         mb.add(help);
         setMenuBar(mb);

         Panel top = new Panel(new FlowLayout(FlowLayout.LEFT));
         top.add(go);
         choice.add("Red");
         choice.add("Green");
         choice.add("Blue");
         for (int i = 0; i < 12; i++) {
            choice.add("Colour " + i);
         }
         top.add(choice);
         top.add(fast);
         top.add(field);
         add("North", top);

         for (int i = 0; i < 20; i++) {
            list.add("item" + i);
         }
         add("East", list);
         add("South", new TextArea("A text area\nwith two lines", 4, 40));

         GridBagConstraints c = new GridBagConstraints();
         for (int i = 0; i < 30; i++) {
            c.gridx = 0;
            c.gridy = i;
            c.anchor = GridBagConstraints.WEST;
            c.weightx = 0;
            big.add(new Label("Name " + i), c);
            c.gridx = 1;
            c.weightx = 1;
            c.fill = GridBagConstraints.HORIZONTAL;
            big.add(new TextField("value " + i), c);
            c.fill = GridBagConstraints.NONE;
         }
         scroll.add(big);
         Panel center = new Panel(new BorderLayout());
         center.add("Center", view);
         center.add("West", scroll);
         scroll.setSize(260, 200);
         add("Center", center);
      }

      public boolean action(Event e, Object arg) {
         record("action " + e.target.getClass().getSimpleName() + " " + arg);
         return true;
      }

      public boolean handleEvent(Event e) {
         if (e.id == Event.LIST_SELECT) {
            record("list select " + e.arg);
         }
         return super.handleEvent(e);
      }
   }

   public static void main(String[] args) throws Exception {
      out = new File(args.length > 0 ? args[0] : "build/vita/awt-check");
      out.mkdirs();
      screen = new HeadlessScreen(960, 544);
      Screen.use(screen);

      final Client f = new Client();
      f.setSize(960, 544);
      f.show();
      settle();
      save("1-frame");
      check(f.getInsets().top == 19, "the frame's menu bar takes 19 lines (insets " + f.getInsets() + ")");
      check(f.isShowing() && f.choice.isShowing(), "the frame and its controls are showing");

      // a menu of the menu bar
      click(new Point(12, 9));
      settle();
      save("2-file-menu");
      click(new Point(30, 19 + 3 + 5));
      waitFor("action MenuItem Open");
      check(logged("action MenuItem Open"), "File > Open reaches Frame.action as a 1.0 ACTION_EVENT");

      // the shortcut, with Ctrl down
      f.field.requestFocus();
      settle();
      screen.inject(Screen.KEY_PRESSED, 0, 0, KeyEvent.VK_CONTROL, 0xFFFF, 0, 2);
      screen.inject(Screen.KEY_PRESSED, 0, 0, KeyEvent.VK_S, 's' & 0x1F, 0, 1);
      screen.inject(Screen.KEY_RELEASED, 0, 0, KeyEvent.VK_S, 's' & 0x1F, 0, 1);
      screen.inject(Screen.KEY_RELEASED, 0, 0, KeyEvent.VK_CONTROL, 0xFFFF, 0, 2);
      waitFor("action MenuItem Save");
      check(logged("action MenuItem Save"), "Ctrl+S chooses File > Save (MenuBar.handleShortcut)");

      // a submenu: hover opens it, a click chooses
      click(new Point(12, 9));
      settle();
      // a menu item is its font's height and a third (AwtMenuItem::MeasureItem); a separator 9
      int fh = java.awt.Toolkit.getDefaultToolkit().getFontMetrics(new java.awt.Font("Dialog", java.awt.Font.PLAIN, 12)).getHeight();
      int itemH = fh + fh / 3;
      int recentY = 19 + 3 + itemH * 2 + 9 + itemH / 2;
      move(30, recentY);
      settle();
      save("3-submenu");
      // the submenu opens to the right of the menu, its first item level with "Recent"
      // the menu's right edge, on the row of an item without a submenu (the submenu covers it on Recent's)
      int menuRight = findMenuRight(19 + 3 + itemH / 2);
      click(new Point(menuRight + 20, recentY + itemH));
      waitFor("action MenuItem two.world");
      check(logged("action MenuItem two.world"), "File > Recent > two.world (submenu opened by hovering)");

      // the check item flips and sends its new state
      click(new Point(12, 9));
      settle();
      int soundY = 19 + 3 + itemH * 3 + 9 + itemH / 2;
      click(new Point(30, soundY));
      waitFor("action CheckboxMenuItem false");
      check(logged("action CheckboxMenuItem false"), "File > Sound unchecks it (ACTION_EVENT with Boolean false)");

      // a disabled item does nothing and leaves the menu open; a press outside closes it
      click(new Point(12, 9));
      settle();
      int offY = 19 + 3 + itemH * 4 + 9 + itemH / 2;
      click(new Point(30, offY));
      settle();
      check(!logged("action MenuItem Disabled"), "a disabled item is not chosen");
      click(new Point(700, 300));
      settle();
      save("4-menus-closed");

      // the Choice: its list opens under it, a click on a row chooses
      Point cp = at(f.choice, 10, f.choice.getHeight() / 2);
      click(cp);
      settle();
      save("5-choice-open");
      int rowH = f.choice.getFontMetrics(f.choice.getFont()).getHeight();
      Point fieldBottom = at(f.choice, 10, f.choice.getHeight());
      click(new Point(fieldBottom.x, fieldBottom.y + 1 + rowH * 2 + rowH / 2));
      waitFor("action Choice Blue");
      check(logged("action Choice Blue") && f.choice.getSelectedIndex() == 2, "Choice: the third row chooses Blue");

      // the text field: typing and Enter
      click(at(f.field, 5, 5));
      settle();
      screen.type("hello");
      screen.key(KeyEvent.VK_ENTER, '\n');
      waitFor("action TextField hello");
      check(logged("action TextField hello"), "TextField: typed text and Enter give ACTION_EVENT with the text");

      click(at(f.go, 5, 5));
      waitFor("action Button Go");
      check(logged("action Button Go"), "Button: a click gives ACTION_EVENT with the label");

      click(at(f.fast, 5, f.fast.getHeight() / 2));
      waitFor("action Checkbox true");
      check(logged("action Checkbox true"), "Checkbox: a click checks it (ACTION_EVENT with Boolean true)");

      // the list: a click selects, a double click acts
      Point li = at(f.list, 10, 2 + rowH * 3 + rowH / 2);
      click(li);
      waitFor("list select 3");
      check(logged("list select 3"), "List: a click gives LIST_SELECT with the index");
      screen.click(li.x, li.y);
      screen.click(li.x, li.y);
      waitFor("action List item3");
      check(logged("action List item3"), "List: a double click gives ACTION_EVENT with the item");

      // the scroll pane's down arrow moves its child one pixel (the JDK's unit increment)
      int before = f.big.getY();
      Point down = at(f.scroll, f.scroll.getWidth() - 2 - 8, f.scroll.getHeight() - 2 - 16 - 8);
      click(down);
      settle();
      check(f.big.getY() == before - 1, "ScrollPane: the down arrow scrolls one pixel (" + before + " -> " + f.big.getY() + ")");

      // a PopupMenu shown from a mouse handler: show() returns once an item is chosen
      Point vp = at(f.view, 100, 100);
      screen.inject(Screen.POINTER_MOVED, vp.x, vp.y, 0, 0, 0, 0);
      screen.inject(Screen.POINTER_PRESSED, vp.x, vp.y, 3, 0, InputEvent.BUTTON3_DOWN_MASK, 0);
      screen.inject(Screen.POINTER_RELEASED, vp.x, vp.y, 3, 0, 0, 0);
      waitFor("before show");
      settle();
      save("6-popup");
      check(logged("before show") && !logged("after show"), "PopupMenu.show() is still waiting while the menu is open");
      click(new Point(vp.x + 30, vp.y + 3 + itemH + itemH / 2));
      waitFor("view action Dance");
      settle();
      synchronized (log) {
         int a = log.indexOf("after show");
         int d = log.indexOf("view action Dance");
         check(a >= 0 && d > a, "the chosen item's action comes after show() returned, as on Windows (" + log + ")");
      }

      save("7-end");

      // javax.swing.SwingUtilities.getWindowAncestor (the bridge's text fields) and a window's parent being its owner
      java.awt.Dialog dlg = new java.awt.Dialog(f, "owned");
      Panel inner = new Panel();
      dlg.add(inner);
      check(javax.swing.SwingUtilities.getWindowAncestor(inner) == dlg && javax.swing.SwingUtilities.getWindowAncestor(dlg) == f && dlg.getParent() == f
            && javax.swing.SwingUtilities.getWindowAncestor(f) == null, "getWindowAncestor, and a dialog's parent is its owner");
      dlg.dispose();

      // javax.imageio.ImageIO: a PNG written (the bridge's captures) and read back the same
      java.awt.image.BufferedImage img = new java.awt.image.BufferedImage(7, 5, java.awt.image.BufferedImage.TYPE_INT_ARGB);
      java.awt.image.BufferedImage rgb = new java.awt.image.BufferedImage(7, 5, java.awt.image.BufferedImage.TYPE_INT_RGB);
      for (int y = 0; y < 5; y++) {
         for (int x = 0; x < 7; x++) {
            img.setRGB(x, y, (x * 36) << 24 | (y * 50) << 16 | (x * 30) << 8 | (x + y) * 10);
            rgb.setRGB(x, y, (y * 50) << 16 | (x * 30) << 8 | (x + y) * 10);
         }
      }
      File png = new File(out, "imageio.png");
      File png2 = new File(out, "imageio-rgb.png");
      boolean wrote = javax.imageio.ImageIO.write(img, "png", png) && javax.imageio.ImageIO.write(rgb, "PNG", png2);
      java.awt.image.BufferedImage back = javax.imageio.ImageIO.read(png);
      java.awt.image.BufferedImage back2 = javax.imageio.ImageIO.read(png2);
      boolean same = wrote && back != null && back2 != null && back.getWidth() == 7 && back.getHeight() == 5;
      for (int y = 0; same && y < 5; y++) {
         for (int x = 0; x < 7; x++) {
            same &= back.getRGB(x, y) == img.getRGB(x, y) && back2.getRGB(x, y) == rgb.getRGB(x, y);
         }
      }
      check(same && !javax.imageio.ImageIO.write(img, "gif", new File(out, "x.gif")), "ImageIO writes PNG (with and without alpha) and reads it back; no other format");

      f.dispose();
      settle();
      System.out.println(checks - failures + "/" + checks + " checks passed; pictures in " + out);
      System.exit(failures == 0 ? 0 : 1);
   }

   /** The right edge of the open menu, found in the picture: the first dark shadow column right of x=40 at row y. */
   static int findMenuRight(int y) {
      for (int x = 40; x < 400; x++) {
         if ((screen.pixel(x, y) & 0xFFFFFF) == 0x404040) {
            return x;
         }
      }
      return 150;
   }
}
