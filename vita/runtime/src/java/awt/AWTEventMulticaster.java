package java.awt;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.AdjustmentEvent;
import java.awt.event.AdjustmentListener;
import java.awt.event.ComponentEvent;
import java.awt.event.ComponentListener;
import java.awt.event.ContainerEvent;
import java.awt.event.ContainerListener;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import java.awt.event.HierarchyBoundsListener;
import java.awt.event.HierarchyEvent;
import java.awt.event.HierarchyListener;
import java.awt.event.InputMethodEvent;
import java.awt.event.InputMethodListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;
import java.awt.event.TextEvent;
import java.awt.event.TextListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowFocusListener;
import java.awt.event.WindowListener;
import java.awt.event.WindowStateListener;
import java.util.EventListener;

/** A chain of two listeners, as java.awt.AWTEventMulticaster. */
public class AWTEventMulticaster implements ComponentListener, ContainerListener, FocusListener, KeyListener, MouseListener,
      MouseMotionListener, WindowListener, WindowFocusListener, WindowStateListener, ActionListener, ItemListener,
      AdjustmentListener, TextListener, InputMethodListener, HierarchyListener, HierarchyBoundsListener, MouseWheelListener {

   protected final EventListener a;
   protected final EventListener b;

   protected AWTEventMulticaster(EventListener a, EventListener b) {
      this.a = a;
      this.b = b;
   }

   protected EventListener remove(EventListener oldl) {
      if (oldl == a) {
         return b;
      }
      if (oldl == b) {
         return a;
      }
      EventListener a2 = removeInternal(a, oldl);
      EventListener b2 = removeInternal(b, oldl);
      if (a2 == a && b2 == b) {
         return this;
      }
      return addInternal(a2, b2);
   }

   protected static EventListener addInternal(EventListener a, EventListener b) {
      if (a == null) {
         return b;
      }
      if (b == null) {
         return a;
      }
      return new AWTEventMulticaster(a, b);
   }

   protected static EventListener removeInternal(EventListener l, EventListener oldl) {
      if (l == oldl || l == null) {
         return null;
      } else if (l instanceof AWTEventMulticaster) {
         return ((AWTEventMulticaster) l).remove(oldl);
      } else {
         return l;
      }
   }

   public void componentResized(ComponentEvent e) {
      ((ComponentListener) a).componentResized(e);
      ((ComponentListener) b).componentResized(e);
   }

   public void componentMoved(ComponentEvent e) {
      ((ComponentListener) a).componentMoved(e);
      ((ComponentListener) b).componentMoved(e);
   }

   public void componentShown(ComponentEvent e) {
      ((ComponentListener) a).componentShown(e);
      ((ComponentListener) b).componentShown(e);
   }

   public void componentHidden(ComponentEvent e) {
      ((ComponentListener) a).componentHidden(e);
      ((ComponentListener) b).componentHidden(e);
   }

   public void componentAdded(ContainerEvent e) {
      ((ContainerListener) a).componentAdded(e);
      ((ContainerListener) b).componentAdded(e);
   }

   public void componentRemoved(ContainerEvent e) {
      ((ContainerListener) a).componentRemoved(e);
      ((ContainerListener) b).componentRemoved(e);
   }

   public void focusGained(FocusEvent e) {
      ((FocusListener) a).focusGained(e);
      ((FocusListener) b).focusGained(e);
   }

   public void focusLost(FocusEvent e) {
      ((FocusListener) a).focusLost(e);
      ((FocusListener) b).focusLost(e);
   }

   public void keyTyped(KeyEvent e) {
      ((KeyListener) a).keyTyped(e);
      ((KeyListener) b).keyTyped(e);
   }

   public void keyPressed(KeyEvent e) {
      ((KeyListener) a).keyPressed(e);
      ((KeyListener) b).keyPressed(e);
   }

   public void keyReleased(KeyEvent e) {
      ((KeyListener) a).keyReleased(e);
      ((KeyListener) b).keyReleased(e);
   }

   public void mouseClicked(MouseEvent e) {
      ((MouseListener) a).mouseClicked(e);
      ((MouseListener) b).mouseClicked(e);
   }

   public void mousePressed(MouseEvent e) {
      ((MouseListener) a).mousePressed(e);
      ((MouseListener) b).mousePressed(e);
   }

   public void mouseReleased(MouseEvent e) {
      ((MouseListener) a).mouseReleased(e);
      ((MouseListener) b).mouseReleased(e);
   }

   public void mouseEntered(MouseEvent e) {
      ((MouseListener) a).mouseEntered(e);
      ((MouseListener) b).mouseEntered(e);
   }

   public void mouseExited(MouseEvent e) {
      ((MouseListener) a).mouseExited(e);
      ((MouseListener) b).mouseExited(e);
   }

   public void mouseDragged(MouseEvent e) {
      ((MouseMotionListener) a).mouseDragged(e);
      ((MouseMotionListener) b).mouseDragged(e);
   }

   public void mouseMoved(MouseEvent e) {
      ((MouseMotionListener) a).mouseMoved(e);
      ((MouseMotionListener) b).mouseMoved(e);
   }

   public void windowOpened(WindowEvent e) {
      ((WindowListener) a).windowOpened(e);
      ((WindowListener) b).windowOpened(e);
   }

   public void windowClosing(WindowEvent e) {
      ((WindowListener) a).windowClosing(e);
      ((WindowListener) b).windowClosing(e);
   }

   public void windowClosed(WindowEvent e) {
      ((WindowListener) a).windowClosed(e);
      ((WindowListener) b).windowClosed(e);
   }

   public void windowIconified(WindowEvent e) {
      ((WindowListener) a).windowIconified(e);
      ((WindowListener) b).windowIconified(e);
   }

   public void windowDeiconified(WindowEvent e) {
      ((WindowListener) a).windowDeiconified(e);
      ((WindowListener) b).windowDeiconified(e);
   }

   public void windowActivated(WindowEvent e) {
      ((WindowListener) a).windowActivated(e);
      ((WindowListener) b).windowActivated(e);
   }

   public void windowDeactivated(WindowEvent e) {
      ((WindowListener) a).windowDeactivated(e);
      ((WindowListener) b).windowDeactivated(e);
   }

   public void windowStateChanged(WindowEvent e) {
      ((WindowStateListener) a).windowStateChanged(e);
      ((WindowStateListener) b).windowStateChanged(e);
   }

   public void windowGainedFocus(WindowEvent e) {
      ((WindowFocusListener) a).windowGainedFocus(e);
      ((WindowFocusListener) b).windowGainedFocus(e);
   }

   public void windowLostFocus(WindowEvent e) {
      ((WindowFocusListener) a).windowLostFocus(e);
      ((WindowFocusListener) b).windowLostFocus(e);
   }

   public void actionPerformed(ActionEvent e) {
      ((ActionListener) a).actionPerformed(e);
      ((ActionListener) b).actionPerformed(e);
   }

   public void itemStateChanged(ItemEvent e) {
      ((ItemListener) a).itemStateChanged(e);
      ((ItemListener) b).itemStateChanged(e);
   }

   public void adjustmentValueChanged(AdjustmentEvent e) {
      ((AdjustmentListener) a).adjustmentValueChanged(e);
      ((AdjustmentListener) b).adjustmentValueChanged(e);
   }

   public void textValueChanged(TextEvent e) {
      ((TextListener) a).textValueChanged(e);
      ((TextListener) b).textValueChanged(e);
   }

   public void inputMethodTextChanged(InputMethodEvent e) {
      ((InputMethodListener) a).inputMethodTextChanged(e);
      ((InputMethodListener) b).inputMethodTextChanged(e);
   }

   public void caretPositionChanged(InputMethodEvent e) {
      ((InputMethodListener) a).caretPositionChanged(e);
      ((InputMethodListener) b).caretPositionChanged(e);
   }

   public void hierarchyChanged(HierarchyEvent e) {
      ((HierarchyListener) a).hierarchyChanged(e);
      ((HierarchyListener) b).hierarchyChanged(e);
   }

   public void ancestorMoved(HierarchyEvent e) {
      ((HierarchyBoundsListener) a).ancestorMoved(e);
      ((HierarchyBoundsListener) b).ancestorMoved(e);
   }

   public void ancestorResized(HierarchyEvent e) {
      ((HierarchyBoundsListener) a).ancestorResized(e);
      ((HierarchyBoundsListener) b).ancestorResized(e);
   }

   public void mouseWheelMoved(MouseWheelEvent e) {
      ((MouseWheelListener) a).mouseWheelMoved(e);
      ((MouseWheelListener) b).mouseWheelMoved(e);
   }

   public static ComponentListener add(ComponentListener a, ComponentListener b) {
      return (ComponentListener) addInternal(a, b);
   }

   public static ContainerListener add(ContainerListener a, ContainerListener b) {
      return (ContainerListener) addInternal(a, b);
   }

   public static FocusListener add(FocusListener a, FocusListener b) {
      return (FocusListener) addInternal(a, b);
   }

   public static KeyListener add(KeyListener a, KeyListener b) {
      return (KeyListener) addInternal(a, b);
   }

   public static MouseListener add(MouseListener a, MouseListener b) {
      return (MouseListener) addInternal(a, b);
   }

   public static MouseMotionListener add(MouseMotionListener a, MouseMotionListener b) {
      return (MouseMotionListener) addInternal(a, b);
   }

   public static WindowListener add(WindowListener a, WindowListener b) {
      return (WindowListener) addInternal(a, b);
   }

   public static WindowStateListener add(WindowStateListener a, WindowStateListener b) {
      return (WindowStateListener) addInternal(a, b);
   }

   public static WindowFocusListener add(WindowFocusListener a, WindowFocusListener b) {
      return (WindowFocusListener) addInternal(a, b);
   }

   public static ActionListener add(ActionListener a, ActionListener b) {
      return (ActionListener) addInternal(a, b);
   }

   public static ItemListener add(ItemListener a, ItemListener b) {
      return (ItemListener) addInternal(a, b);
   }

   public static AdjustmentListener add(AdjustmentListener a, AdjustmentListener b) {
      return (AdjustmentListener) addInternal(a, b);
   }

   public static TextListener add(TextListener a, TextListener b) {
      return (TextListener) addInternal(a, b);
   }

   public static InputMethodListener add(InputMethodListener a, InputMethodListener b) {
      return (InputMethodListener) addInternal(a, b);
   }

   public static HierarchyListener add(HierarchyListener a, HierarchyListener b) {
      return (HierarchyListener) addInternal(a, b);
   }

   public static HierarchyBoundsListener add(HierarchyBoundsListener a, HierarchyBoundsListener b) {
      return (HierarchyBoundsListener) addInternal(a, b);
   }

   public static MouseWheelListener add(MouseWheelListener a, MouseWheelListener b) {
      return (MouseWheelListener) addInternal(a, b);
   }

   public static ComponentListener remove(ComponentListener l, ComponentListener oldl) {
      return (ComponentListener) removeInternal(l, oldl);
   }

   public static ContainerListener remove(ContainerListener l, ContainerListener oldl) {
      return (ContainerListener) removeInternal(l, oldl);
   }

   public static FocusListener remove(FocusListener l, FocusListener oldl) {
      return (FocusListener) removeInternal(l, oldl);
   }

   public static KeyListener remove(KeyListener l, KeyListener oldl) {
      return (KeyListener) removeInternal(l, oldl);
   }

   public static MouseListener remove(MouseListener l, MouseListener oldl) {
      return (MouseListener) removeInternal(l, oldl);
   }

   public static MouseMotionListener remove(MouseMotionListener l, MouseMotionListener oldl) {
      return (MouseMotionListener) removeInternal(l, oldl);
   }

   public static WindowListener remove(WindowListener l, WindowListener oldl) {
      return (WindowListener) removeInternal(l, oldl);
   }

   public static WindowStateListener remove(WindowStateListener l, WindowStateListener oldl) {
      return (WindowStateListener) removeInternal(l, oldl);
   }

   public static WindowFocusListener remove(WindowFocusListener l, WindowFocusListener oldl) {
      return (WindowFocusListener) removeInternal(l, oldl);
   }

   public static ActionListener remove(ActionListener l, ActionListener oldl) {
      return (ActionListener) removeInternal(l, oldl);
   }

   public static ItemListener remove(ItemListener l, ItemListener oldl) {
      return (ItemListener) removeInternal(l, oldl);
   }

   public static AdjustmentListener remove(AdjustmentListener l, AdjustmentListener oldl) {
      return (AdjustmentListener) removeInternal(l, oldl);
   }

   public static TextListener remove(TextListener l, TextListener oldl) {
      return (TextListener) removeInternal(l, oldl);
   }

   public static InputMethodListener remove(InputMethodListener l, InputMethodListener oldl) {
      return (InputMethodListener) removeInternal(l, oldl);
   }

   public static HierarchyListener remove(HierarchyListener l, HierarchyListener oldl) {
      return (HierarchyListener) removeInternal(l, oldl);
   }

   public static HierarchyBoundsListener remove(HierarchyBoundsListener l, HierarchyBoundsListener oldl) {
      return (HierarchyBoundsListener) removeInternal(l, oldl);
   }

   public static MouseWheelListener remove(MouseWheelListener l, MouseWheelListener oldl) {
      return (MouseWheelListener) removeInternal(l, oldl);
   }
}
