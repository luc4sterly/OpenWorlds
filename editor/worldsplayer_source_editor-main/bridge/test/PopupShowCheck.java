package NET.worlds.core;

import java.awt.Canvas;
import java.awt.EventQueue;
import java.awt.Frame;
import java.awt.GraphicsEnvironment;
import java.awt.Panel;
import java.awt.Point;
import java.awt.PopupMenu;

/**
 * The menu of another user's avatar (FriendsListPart.instanceDroneClick):
 * added to the friends list, a Canvas, and shown on the render canvas. With
 * today's Java that PopupMenu.show throws "origin not in parent's hierarchy"
 * (JDK bug 6278745, fixed in Java 6; the 2004 client ran on 1.4.2), so the
 * click on a user did nothing. AwtCompat.showPopupNow shows it from its
 * parent at the same point of the screen. Needs a display (xvfb-run).
 */
public final class PopupShowCheck {
   public static void main(String[] args) throws Exception {
      if (GraphicsEnvironment.isHeadless()) {
         System.out.println("PopupShowCheck: no display, not checked");
         return;
      }
      final Frame f = new Frame("PopupShowCheck");
      final Canvas friends = new Canvas();
      final Canvas render = new Canvas();
      friends.setSize(120, 200);
      render.setSize(300, 200);
      Panel p = new Panel(new java.awt.FlowLayout(java.awt.FlowLayout.LEFT, 0, 0));
      p.add(render);
      p.add(friends);
      f.add(p);
      final PopupMenu menu = new PopupMenu();
      menu.add("Add pepe to friends");
      friends.add(menu);
      f.pack();
      f.setLocation(40, 40);
      f.setVisible(true);
      long end = System.currentTimeMillis() + 10000;
      while (!(render.isShowing() && friends.isShowing()) && System.currentTimeMillis() < end) {
         Thread.sleep(50);
      }
      final boolean[] threw = {false};
      final Point[] at = {null};
      EventQueue.invokeAndWait(() -> {
         try {
            menu.show(render, 100, 50);
         } catch (IllegalArgumentException e) {
            threw[0] = e.getMessage() != null && e.getMessage().contains("hierarchy");
         }
      });
      EventQueue.invokeAndWait(() -> at[0] = AwtCompat.showPopupNow(menu, render, 100, 50));
      Point r = render.getLocationOnScreen();
      Point fr = friends.getLocationOnScreen();
      boolean place = at[0] != null && at[0].x == r.x + 100 - fr.x && at[0].y == r.y + 50 - fr.y;
      f.dispose();
      System.out.println("  " + (threw[0] ? "ok   " : "FAIL ") + " PopupMenu.show(render) throws \"origin not in parent's hierarchy\" (JDK 6278745)");
      System.out.println("  " + (place ? "ok   " : "FAIL ") + " AwtCompat shows it from the friends list at the same point: " + at[0]);
      System.exit(threw[0] && place ? 0 : 1);
   }
}
