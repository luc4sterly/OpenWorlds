package NET.worlds.console;

import NET.worlds.network.URL;
import NET.worlds.scape.BGLoaded;
import NET.worlds.scape.BackgroundLoader;
import NET.worlds.scape.Room;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.MediaTracker;
import java.awt.Toolkit;

public class ImageCanvas extends Component implements BGLoaded {
   protected URL imageURL_;
   protected Image image_;
   protected boolean loaded_;
   protected Dimension dim_;
   protected static final URL defaultImageURL = URL.make("home:..\\default.gif");

   public ImageCanvas(URL var1) {
      this.imageURL_ = var1;
      this.loaded_ = false;
      this.loadRemoteImage();
   }

   protected ImageCanvas() {
   }

   public ImageCanvas(String var1) {
      this.imageURL_ = URL.make("home:" + var1);
      this.image_ = this.loadLocalImage(this.imageURL_.unalias());
      if (this.image_ == null) {
         this.imageURL_ = URL.make("home:..\\" + var1);
         this.image_ = this.loadLocalImage(this.imageURL_.unalias());
      }
   }

   public void setNewImage(URL var1, Graphics var2) {
      this.imageURL_ = var1;
      this.flushImage();
      this.loaded_ = false;
      this.loadRemoteImage();
   }

   protected void flushImage() {
      if (this.image_ != null) {
         this.image_.flush();
         this.image_ = null;
      }
   }

   public void update(Graphics var1) {
      Dimension var2 = this.getSize();
      if (this.image_ == null || var2.width > this.dim_.width || var2.height > this.dim_.height) {
         super.update(var1);
      }

      this.paint(var1);
   }

   public void paint(Graphics var1) {
      if (this.image_ != null) {
         var1.drawImage(this.image_, 0, 0, this);
      }
   }

   public Dimension imageSize() {
      if (this.image_ == null) {
         this.dim_ = new Dimension(0, 0);
      } else {
         int var1 = this.image_.getWidth(this);
         int var2 = this.image_.getHeight(this);
         if (var1 != -1 && var2 != -1) {
            this.dim_ = new Dimension(var1, var2);
         }
      }

      return this.dim_;
   }

   public Object asyncBackgroundLoad(String var1, URL var2) {
      this.image_ = this.loadLocalImage(var1);
      if (this.getGraphics() != null) {
         this.update(this.getGraphics());
      }

      return var1;
   }

   public boolean syncBackgroundLoad(Object var1, URL var2) {
      String var3 = (String)var1;
      this.image_ = this.loadLocalImage(var3);
      if (this.getGraphics() != null) {
         this.update(this.getGraphics());
      }

      return false;
   }

   public Room getBackgroundLoadRoom() {
      return null;
   }

   private void loadRemoteImage() {
      this.image_ = this.loadLocalImage(defaultImageURL.unalias());
      if (this.imageURL_ != defaultImageURL) {
         BackgroundLoader.get(this, this.imageURL_);
      }
   }

   private Image loadLocalImage(String var1) {
      Image var2 = Toolkit.getDefaultToolkit().getImage(var1);
      MediaTracker var3 = new MediaTracker(this);
      var3.addImage(var2, 0);

      try {
         var3.waitForAll();
      } catch (InterruptedException var5) {
      }

      if (!var3.isErrorAny()) {
         this.loaded_ = true;
         return var2;
      } else {
         return null;
      }
   }

   public static Image loadImage(URL var0, Component var1) {
      Image var2 = Toolkit.getDefaultToolkit().getImage(var0.unalias());
      MediaTracker var3 = new MediaTracker(var1);
      var3.addImage(var2, 0);

      try {
         var3.waitForAll();
      } catch (InterruptedException var5) {
      }

      return !var3.isErrorAny() ? var2 : null;
   }

   public static Image getSystemImage(String var0, Component var1) {
      for (int var2 = 0; var2 < 2; var2++) {
         Image var3 = loadImage(URL.make("home:" + var0), var1);
         if (var3 != null) {
            return var3;
         }

         if (var2 == 0) {
            var0 = "..\\" + var0;
         }
      }

      return null;
   }

   public Dimension preferredSize() {
      return this.imageSize();
   }

   public Dimension minimumSize() {
      return this.imageSize();
   }
}
