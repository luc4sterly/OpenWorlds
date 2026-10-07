package java.awt;

/**
 * A dialog, as java.awt.Dialog. A modal one blocks the input to the other
 * windows, and show() returns when it is hidden: on the event thread it
 * keeps dispatching events meanwhile, as the JDK's secondary loop.
 */
public class Dialog extends Window {
   boolean resizable = true;
   boolean undecorated;
   boolean modal;
   String title;

   public Dialog(Frame owner) {
      this(owner, "", false);
   }

   public Dialog(Frame owner, boolean modal) {
      this(owner, "", modal);
   }

   public Dialog(Frame owner, String title) {
      this(owner, title, false);
   }

   public Dialog(Frame owner, String title, boolean modal) {
      super();
      setOwner(owner);
      this.title = title == null ? "" : title;
      this.modal = modal;
   }

   public Dialog(Frame owner, String title, boolean modal, GraphicsConfiguration gc) {
      this(owner, title, modal);
   }

   public Dialog(Dialog owner) {
      this(owner, "", false);
   }

   public Dialog(Dialog owner, String title) {
      this(owner, title, false);
   }

   public Dialog(Dialog owner, String title, boolean modal) {
      super();
      setOwner(owner);
      this.title = title == null ? "" : title;
      this.modal = modal;
   }

   public Dialog(Window owner) {
      this(owner, "");
   }

   public Dialog(Window owner, String title) {
      super();
      setOwner(owner);
      this.title = title == null ? "" : title;
   }

   public boolean isModal() {
      return modal;
   }

   public void setModal(boolean modal) {
      this.modal = modal;
   }

   public String getTitle() {
      return title;
   }

   public void setTitle(String title) {
      this.title = title == null ? "" : title;
      WindowSystem.decorationsChanged(this);
   }

   public boolean isResizable() {
      return resizable;
   }

   public void setResizable(boolean resizable) {
      this.resizable = resizable;
   }

   public boolean isUndecorated() {
      return undecorated;
   }

   public void setUndecorated(boolean undecorated) {
      if (displayable) {
         throw new IllegalComponentStateException("The dialog is displayable.");
      }
      this.undecorated = undecorated;
   }

   private final Object modalLock = new Object();

   public void show() {
      boolean wasVisible = visible;
      super.show();
      if (modal && !wasVisible && visible) {
         if (EventQueue.isDispatchThread()) {
            EventQueue.pumpWhile(new EventQueue.Condition() {
               public boolean holds() {
                  return visible && displayable;
               }
            });
         } else {
            synchronized (modalLock) {
               while (visible && displayable) {
                  try {
                     modalLock.wait(250);
                  } catch (InterruptedException e) {
                     Thread.currentThread().interrupt();
                     break;
                  }
               }
            }
         }
      }
   }

   public void hide() {
      super.hide();
      synchronized (modalLock) {
         modalLock.notifyAll();
      }
      EventQueue.wakeUp();
   }

   public void dispose() {
      super.dispose();
      synchronized (modalLock) {
         modalLock.notifyAll();
      }
      EventQueue.wakeUp();
   }

   protected String paramString() {
      String str = super.paramString() + (modal ? ",modal" : ",modeless");
      if (title != null) {
         str += ",title=" + title;
      }
      return str;
   }
}
