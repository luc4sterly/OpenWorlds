package NET.worlds.core;

import NET.worlds.console.Console;
import NET.worlds.console.PolledDialog;
import NET.worlds.network.ProgressBar;
import NET.worlds.network.URL;
import NET.worlds.scape.FileList;
import NET.worlds.scape.Pilot;
import NET.worlds.scape.World;
import java.awt.Button;
import java.awt.Event;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.Label;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.text.MessageFormat;
import java.util.Enumeration;
import java.util.Vector;
import java.util.zip.CRC32;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;
import java.util.zip.ZipOutputStream;

public class ArchiveMaker extends PolledDialog {
   private static final String extensions = "cmp;mov";
   private URL sourceURL;
   private String path;
   private Label status = new Label("", 0);
   private Button goButton;
   private Button closeButton = new Button(Console.message("Close"));
   private ProgressBar progress = new ProgressBar(1);
   private boolean start;
   private boolean stop;
   private boolean finished;
   private boolean condense;

   public ArchiveMaker(boolean var1) {
      super(Console.getFrame(), null, var1 ? Console.message("Condense-Files") : Console.message("Expand-Files"), true);
      this.condense = var1;
      this.ready();
   }

   protected void build() {
      String var1 = null;
      Pilot var2 = Pilot.getActive();
      if (var2 != null) {
         World var3 = var2.getWorld();
         if (var3 != null) {
            this.sourceURL = var3.getSourceURL();
            this.path = this.sourceURL.unalias();
            this.path = this.path.substring(0, this.path.lastIndexOf(47));
            String var4 = URL.getHome().unalias();
            if (this.path.startsWith(var4)) {
               File var5 = new File(URL.make(this.sourceURL, "content.zip").unalias());
               if (this.condense) {
                  if (var5.exists()) {
                     var1 = Console.message("Must-expand");
                  }
               } else if (!var5.exists()) {
                  var1 = Console.message("Must-condense");
               }
            } else {
               var1 = Console.message("Not-a-home");
            }
         } else {
            var1 = Console.message("Cant-access-world");
         }
      } else {
         var1 = Console.message("Cant-access-pilot");
      }

      GridBagLayout var8 = new GridBagLayout();
      this.setLayout(var8);
      GridBagConstraints var9 = new GridBagConstraints();
      var9.weightx = 0.0;
      var9.gridwidth = 1;
      this.add(var8, new Label(Console.message("Status"), 2), var9);
      var9.weightx = 1.0;
      var9.gridwidth = 0;
      var9.fill = 2;
      this.add(var8, this.status, var9);
      var9.fill = 0;
      var9.weightx = 0.0;
      var9.gridwidth = 0;
      this.goButton = new Button(this.condense ? Console.message("Condense") : Console.message("Expand"));
      this.add(var8, this.goButton, var9);
      var9.weightx = 1.0;
      var9.fill = 2;
      Insets var10 = var9.insets;
      var9.insets = new Insets(5, 5, 5, 5);
      this.add(var8, this.progress, var9);
      var9.insets = var10;
      var9.fill = 0;
      var9.weightx = 0.0;
      this.add(var8, this.closeButton, var9);
      if (var1 != null) {
         this.status.setText(var1);
         this.goButton.setEnabled(false);
      } else {
         String var6 = this.sourceURL.getAbsolute();
         var6 = var6.substring(0, var6.lastIndexOf(47));
         Object[] var7 = new Object[]{new String(var6)};
         if (this.condense) {
            this.status.setText(MessageFormat.format(Console.message("condense-name"), var7));
         } else {
            this.status.setText(MessageFormat.format(Console.message("expand-name"), var7));
         }
      }
   }

   public boolean action(Event var1, Object var2) {
      Object var3 = var1.target;
      if (var3 == this.goButton) {
         if (!this.start) {
            this.start = true;
         } else {
            this.stop = true;
         }
      } else {
         if (var3 != this.closeButton) {
            return false;
         }

         if (!this.start || this.finished) {
            this.done(true);
         }
      }

      return true;
   }

   protected void activeCallback() {
      if (this.start && !this.finished) {
         this.goButton.setLabel(Console.message("Stop"));
         if (this.condense) {
            this.doCondense();
         } else {
            this.doExpand();
         }
      }
   }

   private void doCondense() {
      this.status.setText(Console.message("Scanning-dir"));
      Vector var1 = new Vector();
      getDirectories(var1, this.path);
      if (this.stop) {
         this.cancelled();
      } else {
         String var2 = "";
         int var3 = var1.size();

         for (int var4 = 0; var4 < var3; var4++) {
            if (var2.length() != 0) {
               var2 = var2 + ";";
            }

            var2 = var2 + var1.elementAt(var4);
         }

         Vector var24 = new FileList((String)var2, "cmp;mov").keepPathInfo().dontSort().getList();
         var3 = var24.size();
         String[] var5 = new String[var3];
         int var6 = this.path.length() + 1;

         for (int var7 = 0; var7 < var3; var7++) {
            var5[var7] = ((String)var24.elementAt(var7)).substring(var6).replace('\\', '/').toLowerCase();
         }

         this.status.setText(Console.message("Sorting-files"));
         Sort.sort(var5);
         if (this.stop) {
            this.cancelled();
         } else {
            this.status.setText(Console.message("Building-archive"));
            String var25 = this.path + "/" + "content.zip";
            boolean var8 = true;

            try {
               FileOutputStream var9 = new FileOutputStream(var25);
               ZipOutputStream var27 = new ZipOutputStream(var9);
               var27.setMethod(0);
               double var11 = var5.length;

               for (int var13 = 0; var13 < var5.length && !this.stop; var13++) {
                  Object[] var14 = new Object[]{new String(var5[var13])};
                  this.status.setText(MessageFormat.format(Console.message("Reading-list"), var14));
                  File var15 = new File(this.path + "/" + var5[var13]);
                  int var16 = (int)var15.length();
                  byte[] var17 = new byte[var16];
                  FileInputStream var18 = new FileInputStream(var15);
                  var18.read(var17);
                  var18.close();
                  CRC32 var19 = new CRC32();
                  var19.update(var17);
                  this.status.setText(MessageFormat.format(Console.message("Writing-list"), var14));
                  ZipEntry var20 = new ZipEntry(var5[var13]);
                  var20.setSize(var16);
                  var20.setTime(var15.lastModified());
                  var20.setCrc(var19.getValue());
                  var27.putNextEntry(var20);
                  var27.write(var17, 0, var16);
                  var27.closeEntry();
                  this.progress.setProgress((var13 + 1) / var11);
               }

               var27.finish();
               var27.close();
               if (!this.stop) {
                  var8 = false;
                  this.goButton.setEnabled(false);
                  Archive.flushAll();

                  for (int var28 = 0; var28 < var5.length; var28++) {
                     Object[] var30 = new Object[]{new String(var5[var28])};
                     this.status.setText(MessageFormat.format(Console.message("Deleting-list"), var30));
                     File var32 = new File(this.path + "/" + var5[var28]);
                     var32.delete();
                     this.progress.setProgress((var28 + 1) / var11);
                  }

                  this.status.setText(Console.message("Removing-empty"));
                  var3 = var1.size();

                  for (int var29 = 0; var29 < var3; var29++) {
                     File var31 = new File((String)var1.elementAt(var29));
                     if (var31.list().length == 0) {
                        var31.delete();
                     }
                  }

                  this.status.setText(Console.message("Done"));
                  this.finished = true;
                  return;
               }
            } catch (IOException var21) {
               Object[] var10 = new Object[]{new String(this.status.getText())};
               this.status.setText(MessageFormat.format(Console.message("IO-Error"), var10));
            }

            if (var8) {
               File var26 = new File(var25);
               var26.delete();
            }

            this.finished = true;
            if (this.stop) {
               this.cancelled();
            }
         }
      }
   }

   private void doExpand() {
      this.status.setText(Console.message("Scanning-archive"));
      boolean var1 = true;
      Vector var2 = new Vector();

      try {
         String var3 = this.path + "/" + "content.zip";
         ZipFile var23 = new ZipFile(var3);
         Enumeration var5 = var23.entries();
         int var6 = 0;

         while (var5.hasMoreElements() && !this.stop) {
            var6++;
            var5.nextElement();
         }

         String var7 = "";
         var5 = var23.entries();
         int var8 = 0;
         double var9 = var6;

         while (var5.hasMoreElements() && !this.stop) {
            ZipEntry var11 = (ZipEntry)var5.nextElement();
            String var12 = var11.getName();
            Object[] var13 = new Object[]{new String(var12)};
            this.status.setText(MessageFormat.format(Console.message("Checking-name"), var13));
            String var14 = this.path + "/" + var12;
            File var15 = new File(var14);
            if (var15.exists()) {
               this.stop = true;
               this.finished = true;
               this.status.setText(MessageFormat.format(Console.message("File-exists"), var13));
               break;
            }

            int var16 = var14.lastIndexOf(47);
            if (var16 != -1) {
               String var17 = var14.substring(0, var16);
               if (!var17.equals(var7)) {
                  this.status.setText(Console.message("Creating-dir"));
                  File var18 = new File(var17);
                  var18.mkdirs();
                  var7 = var17;
               }
            }

            this.status.setText(MessageFormat.format(Console.message("Reading-list"), var13));
            byte[] var25 = Archive.load(var23, var11);
            this.status.setText(MessageFormat.format(Console.message("Writing-list"), var13));
            FileOutputStream var26 = new FileOutputStream(var15);
            var2.addElement(var15);
            var26.write(var25);
            var26.close();
            var8++;
            this.progress.setProgress(var8 / var9);
         }

         var23.close();
         if (!this.stop) {
            this.goButton.setEnabled(false);
            var1 = false;
            synchronized (Archive.getMutex()) {
               Archive.flushAll();
               new File(var3).delete();
            }

            this.status.setText(Console.message("Done"));
            this.finished = true;
            return;
         }
      } catch (IOException var21) {
         Object[] var4 = new Object[]{new String(this.status.getText())};
         this.status.setText(MessageFormat.format(Console.message("IO-Error"), var4));
      }

      if (var1) {
         Enumeration var22 = var2.elements();

         while (var22.hasMoreElements()) {
            ((File)var22.nextElement()).delete();
         }
      }

      if (!this.finished) {
         this.finished = true;
         if (this.stop) {
            this.cancelled();
         }
      }
   }

   private void cancelled() {
      this.finished = true;
      this.status.setText(Console.message("Cancelled"));
   }

   protected boolean done(boolean var1) {
      return this.start && !this.finished ? true : super.done(var1);
   }

   private static void getDirectories(Vector var0, String var1) {
      var0.addElement(var1);
      File var2 = new File(var1);
      String[] var3 = var2.list();

      for (int var4 = 0; var4 < var3.length; var4++) {
         String var5 = var1 + '/' + var3[var4];
         File var6 = new File(var5);
         if (var6.isDirectory()) {
            getDirectories(var0, var5);
         }
      }
   }
}
