package NET.worlds.scape;

import NET.worlds.network.URL;
import java.io.IOException;

public class LibraryEntry extends SuperRoot implements Iconic {
   protected URL iconURL;
   protected URL contentURL;
   protected String propertyName;
   private static Object classCookie = new Object();

   public LibraryEntry() {
   }

   public LibraryEntry(String var1, URL var2) {
      this.setName(var1);
      this.iconURL = var2;
   }

   private void changed() {
      Library var1 = (Library)this.getOwner();
      if (var1 != null) {
         var1.entryChanged(this);
      }
   }

   public String getIconCaption() {
      return this.getName();
   }

   public URL getIconURL() {
      return this.iconURL;
   }

   public URL getContentURL() {
      return this.contentURL;
   }

   public String getPropertyName(boolean var1) {
      Library var2;
      return this.propertyName == null && var1 && (var2 = (Library)this.getOwner()) != null ? var2.getPropertyName() : this.propertyName;
   }

   public void setName(String var1) {
      super.setName(var1);
      this.changed();
   }

   public void setIconURL(URL var1) {
      this.iconURL = var1;
      this.changed();
   }

   public void setContentURL(URL var1) {
      this.contentURL = var1;
      this.changed();
   }

   public void setPropertyName(String var1) {
      this.propertyName = var1;
      this.changed();
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = URLPropertyEditor.make(new Property(this, var1, "Icon").allowSetNull(), TextureDecoder.getJavaExts());
            } else if (var3 == 1) {
               var5 = this.getIconURL();
            } else if (var3 == 2) {
               this.setIconURL((URL)var4);
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = URLPropertyEditor.make(new Property(this, var1, "Content URL").allowSetNull(), "*wob");
            } else if (var3 == 1) {
               var5 = this.contentURL;
            } else if (var3 == 2) {
               this.setContentURL((URL)var4);
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Property Name").allowSetNull());
            } else if (var3 == 1) {
               var5 = this.getPropertyName(false);
            } else if (var3 == 2) {
               this.setPropertyName((String)var4);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 3, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(3, classCookie);
      super.saveState(var1);
      URL.save(var1, this.iconURL);
      URL.save(var1, this.contentURL);
      var1.saveString(this.propertyName);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            super.restoreState(var1);
         case 0:
            this.setName(var1.restoreString());
            this.iconURL = URL.restore(var1);
            this.contentURL = URL.restore(var1);
            var1.restoreMaybeNull();
            break;
         case 2:
            super.restoreState(var1);
            this.setName(var1.restoreString());
            this.iconURL = URL.restore(var1);
            this.contentURL = URL.restore(var1);
            break;
         case 3:
            super.restoreState(var1);
            this.iconURL = URL.restore(var1);
            this.contentURL = URL.restore(var1);
            this.propertyName = var1.restoreString();
            break;
         default:
            throw new TooNewException();
      }
   }
}
