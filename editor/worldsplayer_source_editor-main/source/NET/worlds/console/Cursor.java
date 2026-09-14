package NET.worlds.console;

import NET.worlds.core.Debug;
import NET.worlds.network.URL;
import NET.worlds.scape.BGLoaded;
import NET.worlds.scape.BackgroundLoader;
import NET.worlds.scape.NoSuchPropertyException;
import NET.worlds.scape.Property;
import NET.worlds.scape.Restorer;
import NET.worlds.scape.Room;
import NET.worlds.scape.Saver;
import NET.worlds.scape.SuperRoot;
import NET.worlds.scape.TooNewException;
import NET.worlds.scape.URLPropertyEditor;
import java.io.IOException;
import java.text.MessageFormat;
import java.util.Enumeration;
import java.util.Hashtable;

public class Cursor extends SuperRoot implements BGLoaded {
   private URL url = URL.make("system:DEFAULT_CURSOR");
   private int hCursor;
   private static Cursor active;
   private static Hashtable sysCursors = new Hashtable();
   private static int defaultCursor = retrieveSystemCursor(addCursor("DEFAULT_CURSOR", "IDC_ARROW"));
   private static Object classCookie = new Object();

   private static URL addCursor(String var0, String var1) {
      URL var2 = URL.make("system:" + var0);
      sysCursors.put(var2, var1);
      return var2;
   }

   public Cursor() {
   }

   public Cursor(URL var1) {
      this.setURL(var1);
   }

   public void setURL(URL var1) {
      this.url = var1;
      if (!var1.unalias().startsWith("system:")) {
         BackgroundLoader.get(this, var1);
      } else {
         this.activate();
      }
   }

   public static Cursor getActive() {
      return active;
   }

   public void activate() {
      SuperRoot var1 = this.getOwner();
      if (var1 != null && var1 == Console.getActive()) {
         int var2 = retrieveSystemCursor(this.url);
         if (var2 != 0) {
            Window.setCursor(var2);
            this.maybeDestroyCursor();
            this.hCursor = var2;
         } else if (this.hCursor != 0) {
            Window.setCursor(this.hCursor);
         }

         active = this;
      }
   }

   public void deactivate() {
      if (active == this) {
         active = null;
      }
   }

   public URL getURL() {
      return this.url;
   }

   public static Enumeration getSysCursorURLs() {
      return sysCursors.keys();
   }

   public static native int getSystemCursorWidth();

   public static native int getSystemCursorHeight();

   public static native int getSystemCursorDepth();

   private static native int loadCursor(String var0);

   private static native int loadSystemCursor(String var0);

   private static native void destroyCursor(int var0);

   private static int retrieveSystemCursor(URL var0) {
      int var1 = 0;
      Object var2 = sysCursors.get(var0);
      if (var2 != null) {
         if (var2 instanceof String) {
            var1 = loadSystemCursor((String)var2);
            sysCursors.put(var0, new Integer(var1));
         } else {
            var1 = (Integer)var2;
         }
      }

      return var1;
   }

   private void maybeDestroyCursor() {
      if (this.hCursor != 0) {
         if (!sysCursors.contains(new Integer(this.hCursor))) {
            destroyCursor(this.hCursor);
         }

         this.hCursor = 0;
      }
   }

   public Object asyncBackgroundLoad(String var1, URL var2) {
      this.deactivate();
      this.maybeDestroyCursor();
      if (var1 == null) {
         return null;
      }

      if ((this.hCursor = loadCursor(var1)) != 0) {
         this.activate();
      }

      return null;
   }

   public boolean syncBackgroundLoad(Object var1, URL var2) {
      if (this.hCursor == 0) {
         Object[] var3 = new Object[]{new String("" + this.url)};
         Console.println(MessageFormat.format(Console.message("Load-cursor"), var3));
      }

      return false;
   }

   public Room getBackgroundLoadRoom() {
      SuperRoot var1 = this.getOwner();
      return var1 != null && var1 instanceof Console ? ((Console)var1).getPilot().getRoom() : null;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = URLPropertyEditor.make(new Property(this, var1, "File"), "cur;ani", getSysCursorURLs());
            } else if (var3 == 1) {
               var5 = this.getURL();
            } else if (var3 == 2) {
               this.setURL((URL)var4);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 1, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      super.saveState(var1);
      URL.save(var1, this.url);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            var1.restoreMaybeNull();
            String var2 = var1.restoreString();
            if (!var2.endsWith(".cur") && !var2.endsWith(".ani")) {
               this.setURL(URL.make("system:" + this.url));
            } else {
               this.setURL(URL.restore(var1, var2, null));
            }
            break;
         case 1:
            super.restoreState(var1);
            this.setURL(URL.restore(var1));
            break;
         default:
            throw new TooNewException();
      }
   }

   static {
      Debug.dAssert(defaultCursor != 0);
      addCursor("CROSSHAIR_CURSOR", "IDC_CROSS");
      addCursor("TEXT_CURSOR", "IDC_IBEAM");
      addCursor("WAIT_CURSOR", "IDC_WAIT");
      addCursor("NE_RESIZE_CURSOR", "IDC_SIZENESW");
      addCursor("SW_RESIZE_CURSOR", "IDC_SIZENESW");
      addCursor("NW_RESIZE_CURSOR", "IDC_SIZENWSE");
      addCursor("SE_RESIZE_CURSOR", "IDC_SIZENWSE");
      addCursor("N_RESIZE_CURSOR", "IDC_SIZENS");
      addCursor("S_RESIZE_CURSOR", "IDC_SIZENS");
      addCursor("W_RESIZE_CURSOR", "IDC_SIZEWE");
      addCursor("E_RESIZE_CURSOR", "IDC_SIZEWE");
      addCursor("HAND_CURSOR", "IDC_UPARROW");
      addCursor("MOVE_CURSOR", "IDC_SIZEALL");
      addCursor("CANNOT_CURSOR", "IDC_NO");
   }
}
