package NET.worlds.console;

import java.awt.Frame;

public class FileSysDialog implements Runnable, MainCallback {
   public static final int OPEN = 0;
   public static final int SAVE = 1;
   private String title;
   private String typesAndExts;
   private String fileName;
   private int hwnd;
   private int mode;
   private boolean done = false;
   private DialogReceiver receiver;
   private boolean parentDisabled = false;
   private Frame parent;

   public FileSysDialog(Frame var1, DialogReceiver var2, String var3, int var4, String var5, String var6, boolean var7) {
      this.receiver = var2;
      this.title = var3;
      this.typesAndExts = var5;
      this.mode = var4;
      this.fileName = var6;
      this.parent = var1;
      if (var7) {
         var1.disable();
         this.parentDisabled = true;
      }

      this.hwnd = Window.findWindow(var1.getTitle());
      if (this.hwnd == 0) {
         this.hwnd = Window.getFrameWindow();
      }

      new Thread(this).start();
      Main.register(this);
   }

   public int getMode() {
      return this.mode;
   }

   public void mainCallback() {
      if (this.done) {
         Main.unregister(this);
         if (this.parentDisabled) {
            this.parent.enable();
         }

         this.receiver.dialogDone(this, this.fileName != null);
      }
   }

   public String fileName() {
      return this.fileName;
   }

   public native String nativeRun();

   public void run() {
      this.fileName = this.nativeRun();
      this.done = true;
   }
}
