package java.awt;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;
import java.util.ArrayList;

/** A push button, as java.awt.Button: ActionEvent (1.0: ACTION_EVENT with the label) when clicked. */
public class Button extends Component {
   String label;
   String actionCommand;
   transient ActionListener actionListener;
   /** Pressed and the pointer still on it. */
   boolean armed;
   boolean mousePressed;

   public Button() {
      this("");
   }

   public Button(String label) {
      this.label = label;
   }

   public String getLabel() {
      return label;
   }

   public void setLabel(String label) {
      boolean changed;
      synchronized (this) {
         changed = label != this.label && (label == null || !label.equals(this.label));
         this.label = label;
      }
      if (changed) {
         if (valid) {
            invalidate();
         }
         repaint();
      }
   }

   public void setActionCommand(String command) {
      actionCommand = command;
   }

   public String getActionCommand() {
      return actionCommand == null ? label : actionCommand;
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
      collect(actionListener, out);
      return out.toArray(new ActionListener[out.size()]);
   }

   static void collect(ActionListener l, ArrayList<ActionListener> out) {
      if (l instanceof AWTEventMulticaster) {
         collect((ActionListener) ((AWTEventMulticaster) l).a, out);
         collect((ActionListener) ((AWTEventMulticaster) l).b, out);
      } else if (l != null) {
         out.add(l);
      }
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

   boolean traversable() {
      return true;
   }

   boolean focusDrawn() {
      return true;
   }

   Dimension peerMinimumSize() {
      FontMetrics fm = getFontMetrics(getFont());
      String l = label == null ? "" : label;
      return new Dimension(fm.stringWidth(l) + 14, fm.getHeight() + 8);
   }

   void handlePeerEvent(AWTEvent e) {
      if (!enabled) {
         return;
      }
      switch (e.getID()) {
         case MouseEvent.MOUSE_PRESSED:
            if (((MouseEvent) e).getButton() == MouseEvent.BUTTON1 || ((MouseEvent) e).getButton() == MouseEvent.NOBUTTON) {
               mousePressed = true;
               setArmed(true);
            }
            break;
         case MouseEvent.MOUSE_DRAGGED: {
            MouseEvent m = (MouseEvent) e;
            if (mousePressed) {
               setArmed(m.getX() >= 0 && m.getY() >= 0 && m.getX() < width && m.getY() < height);
            }
            break;
         }
         case MouseEvent.MOUSE_RELEASED: {
            boolean fire = mousePressed && armed;
            mousePressed = false;
            setArmed(false);
            if (fire) {
               fire(((MouseEvent) e).getModifiers());
            }
            break;
         }
         case KeyEvent.KEY_PRESSED: {
            int k = ((KeyEvent) e).getKeyCode();
            if (k == KeyEvent.VK_SPACE || k == KeyEvent.VK_ENTER) {
               setArmed(true);
            }
            break;
         }
         case KeyEvent.KEY_RELEASED: {
            int k = ((KeyEvent) e).getKeyCode();
            if ((k == KeyEvent.VK_SPACE || k == KeyEvent.VK_ENTER) && armed) {
               setArmed(false);
               fire(((KeyEvent) e).getModifiers());
            }
            break;
         }
         default:
      }
   }

   private void setArmed(boolean a) {
      if (armed != a) {
         armed = a;
         repaint();
      }
   }

   void fire(int modifiers) {
      EventQueue.post(new ActionEvent(this, ActionEvent.ACTION_PERFORMED, getActionCommand(), System.currentTimeMillis(), modifiers));
   }

   void paintPeer(Graphics g) {
      Color bg = background != null ? background : Theme.CONTROL;
      Theme.paintButtonFace(g, 0, 0, width, height, armed);
      if (background != null && !background.equals(Theme.CONTROL)) {
         g.setColor(bg);
         g.fillRect(2, 2, width - 4, height - 4);
      }
      String l = label == null ? "" : label;
      Font f = getFont();
      if (f != null) {
         g.setFont(f);
      }
      FontMetrics fm = g.getFontMetrics();
      int x = (width - fm.stringWidth(l)) / 2 + (armed ? 1 : 0);
      int y = (height - fm.getHeight()) / 2 + fm.getAscent() + (armed ? 1 : 0);
      if (enabled) {
         Color fg = getForeground();
         g.setColor(fg != null ? fg : Color.black);
         g.drawString(l, x, y);
      } else {
         Theme.disabledString(g, l, x, y);
      }
      if (isFocusOwner() && width > 8 && height > 8) {
         Theme.focusRect(g, 4, 4, width - 8, height - 8);
      }
   }

   protected String paramString() {
      return super.paramString() + ",label=" + label;
   }
}
