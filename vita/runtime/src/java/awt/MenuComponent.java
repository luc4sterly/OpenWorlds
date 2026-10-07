package java.awt;

import java.awt.event.ActionEvent;

/**
 * A menu bar, menu or menu item, as java.awt.MenuComponent. Menus are
 * drawn and run by {@link MenuWindow} (what Windows' menus did for the
 * JDK's peers); events reach the 2004 client as the JDK delivered them:
 * listeners if there are any, otherwise a 1.0 Event that climbs the
 * menu tree up to the Frame (or the component a PopupMenu was added to).
 */
public abstract class MenuComponent implements java.io.Serializable {
   transient MenuContainer parent;
   Font font;
   String name;
   boolean nameExplicitlySet;
   boolean newEventsOnly;
   /** Between addNotify and removeNotify: what a peer meant. */
   boolean displayable;

   public MenuComponent() {
   }

   String constructComponentName() {
      return null;
   }

   public String getName() {
      if (name == null && !nameExplicitlySet) {
         synchronized (this) {
            if (name == null && !nameExplicitlySet) {
               name = constructComponentName();
            }
         }
      }
      return name;
   }

   public void setName(String name) {
      synchronized (this) {
         this.name = name;
         nameExplicitlySet = true;
      }
   }

   public MenuContainer getParent() {
      return parent;
   }

   public Font getFont() {
      Font f = font;
      if (f != null) {
         return f;
      }
      MenuContainer p = parent;
      return p != null ? p.getFont() : null;
   }

   public void setFont(Font f) {
      font = f;
      changed();
   }

   public void removeNotify() {
      synchronized (getTreeLock()) {
         displayable = false;
      }
   }

   /** @deprecated As the JDK: the event goes to the parent. */
   @Deprecated
   public boolean postEvent(Event evt) {
      MenuContainer p = parent;
      if (p != null) {
         p.postEvent(evt);
      }
      return false;
   }

   public final void dispatchEvent(AWTEvent e) {
      dispatchEventImpl(e);
   }

   /** The JDK's MenuComponent.dispatchEventImpl. */
   void dispatchEventImpl(AWTEvent e) {
      Toolkit.getDefaultToolkit().notifyAWTEventListeners(e);
      MenuContainer p = parent;
      if (newEventsOnly || (p instanceof MenuComponent && ((MenuComponent) p).newEventsOnly)) {
         if (eventEnabled(e)) {
            processEvent(e);
         } else if (e instanceof ActionEvent && p != null) {
            e.setSource(p);
            ((MenuComponent) p).dispatchEvent(e);
         }
      } else {
         Event olde = e.convertToOld();
         if (olde != null) {
            postEvent(olde);
         }
      }
   }

   boolean eventEnabled(AWTEvent e) {
      return false;
   }

   protected void processEvent(AWTEvent e) {
   }

   protected String paramString() {
      String thisName = getName();
      return thisName != null ? thisName : "";
   }

   public String toString() {
      return getClass().getName() + "[" + paramString() + "]";
   }

   protected final Object getTreeLock() {
      return Component.LOCK;
   }

   /** What the native menu redrew after a change: the open menu showing this, or the menu bar. */
   void changed() {
      MenuContainer p = parent;
      if (p instanceof MenuBar) {
         ((MenuBar) p).barChanged();
      } else if (this instanceof MenuBar) {
         ((MenuBar) this).barChanged();
      }
      PopupWindow.menusChanged();
   }
}
