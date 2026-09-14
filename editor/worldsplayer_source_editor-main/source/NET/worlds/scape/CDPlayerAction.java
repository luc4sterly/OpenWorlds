package NET.worlds.scape;

import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.console.MainTerminalCallback;
import java.io.IOException;

public class CDPlayerAction extends Action implements Runnable, MainCallback, MainTerminalCallback {
   private static final boolean DISABLE_ALL = true;
   private static final int STATE_INITIAL = 0;
   private static final int STATE_WAITING = 1;
   private static final int STATE_DONE = 2;
   private static int numDrives = -1;
   private static CDPlayerAction active;
   private String artist;
   private String title;
   private String hash;
   private int start;
   private int stop;
   private boolean isStopper;
   private boolean cancel;
   private int state = 0;
   private static Object classCookie = new Object();

   private boolean same(String var1, String var2) {
      if (var1 == null) {
         return var2 == null;
      } else {
         return var2 == null ? false : var1.equals(var2);
      }
   }

   private boolean same(CDPlayerAction var1) {
      return var1 != null
         && this.same(this.artist, var1.artist)
         && this.same(this.title, var1.title)
         && this.same(this.hash, var1.hash)
         && this.start == var1.start
         && this.stop == var1.stop;
   }

   public Persister trigger(Event var1, Persister var2) {
      return null;
   }

   public void run() {
      if (numDrives == -1) {
         numDrives = getNumDrives();
      }

      for (int var1 = 0; var1 < numDrives; var1++) {
         try {
            CDTrackInfo var2 = getTrackList(var1);
            String var3 = null;
            if (var2 != null) {
               var3 = CDDBHash.hashString(var2);
               if (var3.equals(this.hash)) {
                  this.play(var1);
                  break;
               }
            }

            if (this.cancel) {
               break;
            }
         } catch (IOException var4) {
         }
      }

      this.state = 2;
   }

   public void mainCallback() {
   }

   public void terminalCallback() {
      this.cancel = true;
      if (this.state == 2) {
         Main.unregister(this);
      }
   }

   private void play(int var1) throws IOException {
      int var2;
      if ((var2 = openDrive(var1)) != 0) {
         playAudio(var2, this.start, this.stop);

         while (isPlaying(var2)) {
            try {
               Thread.sleep(1000L);
            } catch (InterruptedException var4) {
            }

            if (this.cancel) {
               stopAudio(var2);
               break;
            }
         }

         closeDrive(var2);
      }
   }

   public static CDTrackInfo getTrackList(int var0) throws IOException {
      CDTrackInfo var2 = null;
      int var1;
      if ((var1 = openDrive(var0)) != 0) {
         var2 = getDriveTrackList(var1);
         closeDrive(var1);
      }

      return var2;
   }

   public static native int getNumDrives();

   public static native int getDriveLetterOffset(int var0);

   public static native int openDrive(int var0) throws IOException;

   public static native void closeDrive(int var0) throws IOException;

   public static native void checkDrive(int var0) throws IOException;

   public static native CDTrackInfo getDriveTrackList(int var0) throws IOException;

   public static native void playAudio(int var0, int var1, int var2) throws IOException;

   public static native void stopAudio(int var0) throws IOException;

   public static native void pauseAudio(int var0) throws IOException;

   public static native void resumeAudio(int var0) throws IOException;

   public static native boolean isPlaying(int var0) throws IOException;

   public static native int getPosition(int var0) throws IOException;

   public static native void setNTAutoPlayCode(int var0);

   public static native boolean launchVolumeControlApp();

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Artist"));
            } else if (var3 == 1) {
               var5 = this.artist;
            } else if (var3 == 2) {
               this.artist = (String)var4;
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Title"));
            } else if (var3 == 1) {
               var5 = this.title;
            } else if (var3 == 2) {
               this.title = (String)var4;
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Disk ID (Edit or Delete to read CD)").allowSetNull());
            } else if (var3 == 1) {
               if (this.hash == null) {
                  try {
                     CDTrackInfo var6 = getTrackList(0);
                     if (var6 != null) {
                        this.hash = CDDBHash.hashString(var6);
                     }
                  } catch (IOException var7) {
                  }
               }

               var5 = this.hash;
            } else if (var3 == 2) {
               this.hash = (String)var4;
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = CDPositionPropertyEditor.make(new Property(this, var1, "Start (75ths of a second)"), false);
            } else if (var3 == 1) {
               var5 = new Integer(this.start);
            } else if (var3 == 2) {
               this.start = (Integer)var4;
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = CDPositionPropertyEditor.make(new Property(this, var1, "Stop (75ths of a second)"), true);
            } else if (var3 == 1) {
               var5 = new Integer(this.stop);
            } else if (var3 == 2) {
               this.stop = (Integer)var4;
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Stop identical CDPlayerAction"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.isStopper);
            } else if (var3 == 2) {
               this.isStopper = (Boolean)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 6, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(2, classCookie);
      super.saveState(var1);
      var1.saveString(this.artist);
      var1.saveString(this.title);
      var1.saveString(this.hash);
      var1.saveInt(this.start);
      var1.saveInt(this.stop);
      var1.saveBoolean(this.isStopper);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            super.restoreState(var1);
            this.artist = var1.restoreString();
            this.title = var1.restoreString();
            this.hash = var1.restoreString();
            this.start = var1.restoreInt();
            this.stop = var1.restoreInt();
            break;
         case 2:
            super.restoreState(var1);
            this.artist = var1.restoreString();
            this.title = var1.restoreString();
            this.hash = var1.restoreString();
            this.start = var1.restoreInt();
            this.stop = var1.restoreInt();
            this.isStopper = var1.restoreBoolean();
            break;
         default:
            throw new TooNewException();
      }
   }
}
