package NET.worlds.scape;

import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.console.MainTerminalCallback;
import NET.worlds.core.IniFile;
import NET.worlds.network.URL;
import java.io.File;
import java.io.IOException;
import java.util.Vector;

public class CDAudio implements Runnable, MainCallback, MainTerminalCallback {
   private static final int STOP = 0;
   private static final int PLAY = 1;
   private static final int PAUSE = 2;
   private static final int NEXT = 3;
   private static final int PREV = 4;
   private static final int CHANGE = 5;
   private static final int CHANGE_MIDI = 6;
   private boolean performedStartupPlay;
   private boolean cancel;
   private Thread playerThread;
   private Vector commandBuffer = new Vector();
   private boolean paused;
   private int driveID;
   private CDTrackInfo tracks;
   private int trackOffset;
   private Object tracksMutex = new Object();
   private int pos;
   private SoundPlayer midiPlayer;
   private URL defaultMIDIFile = URL.make("home:start.mid");
   private URL curMIDIFile = this.defaultMIDIFile;
   private int trackToRepeat = -1;
   private int repeatingTrack = -1;
   private boolean enabled = true;
   private static CDAudio instance = new CDAudio();
   static boolean useMidiFlag = IniFile.gamma().getIniInt("MIDIONSTART", 1) != 0;
   static boolean useAutoCDFlag = IniFile.gamma().getIniInt("AUTOPLAYCD", 1) != 0;
   private boolean cdInDrive;
   private boolean allowMIDIAnyway;
   private boolean midiPaused;
   private boolean midiStarted;

   public static CDAudio get() {
      return instance;
   }

   public String getTimeReadout() {
      synchronized (this.tracksMutex) {
         if (this.tracks == null) {
            this.tracksMutex.notify();
            return "00 [00:00]";
         }

         int var2 = this.tracks.getNumTracks();
         if (this.pos != 0) {
            for (int var3 = 0; var3 < var2; var3++) {
               if (this.pos < this.tracks.getEndFrames(var3)) {
                  return fmt2(var3 + 1) + " " + fmtFrames(this.pos - this.tracks.getStartFrames(var3));
               }
            }
         }

         return fmt2(var2) + " " + fmtFrames(this.tracks.getEndFrames(var2 - 1));
      }
   }

   public void setEnabled(boolean var1) {
      if (this.enabled != var1) {
         this.enabled = var1;
         if (!this.enabled) {
            this.stop();
         } else {
            this.change(true);
         }
      }
   }

   public void play() {
      this.queueCommand(1);
   }

   public void pause() {
      this.queueCommand(2);
   }

   public void stop() {
      this.queueCommand(0);
   }

   public void next() {
      this.queueCommand(3);
   }

   public void prev() {
      this.queueCommand(4);
   }

   public void change(boolean var1) {
      this.queueCommand(5);
   }

   public static void startupPlay() {
      get();
   }

   public void setMIDIFile(URL var1) {
      this.curMIDIFile = var1;
   }

   public URL getDefaultMIDIFile() {
      return this.defaultMIDIFile;
   }

   public URL getMIDIFile() {
      return this.curMIDIFile;
   }

   public void setCDTrack(int var1) {
      this.trackToRepeat = var1 - 1;
   }

   public int getCDTrack() {
      return this.trackToRepeat + 1;
   }

   private CDAudio() {
      this.playerThread = new Thread(this);
      this.playerThread.start();
   }

   public void run() {
      Main.register(this);
      int var1 = CDPlayerAction.getNumDrives();

      while (!this.cancel) {
         for (int var2 = 0; var2 < var1; var2++) {
            this.cdInDrive = false;

            try {
               if ((this.driveID = CDPlayerAction.openDrive(var2)) != 0) {
                  if (!CDPlayerAction.isPlaying(this.driveID)) {
                     CDTrackInfo var3 = CDPlayerAction.getDriveTrackList(this.driveID);
                     char var4 = (char)(65 + CDPlayerAction.getDriveLetterOffset(var2));
                     File var5 = new File("" + var4 + ":\\WORLDS.CD");
                     if (var5.exists()) {
                        synchronized (this.tracksMutex) {
                           this.tracks = var3;
                           this.trackOffset = 0;
                           if (var5.length() == 1L) {
                              this.trackOffset = 1;
                           }
                        }

                        this.cdInDrive = true;
                        if (this.performedStartupPlay) {
                           this.flushPendingCommands();
                        } else {
                           this.performedStartupPlay = true;
                        }

                        this.change(true);
                        this.waitForCommands();
                     }
                  }

                  this.driveID = 0;
               }
            } catch (IOException var15) {
            }

            if (this.driveID != 0) {
               try {
                  CDPlayerAction.closeDrive(this.driveID);
               } catch (IOException var10) {
               }

               this.driveID = 0;
               this.paused = false;
               this.pos = 0;
            }
         }

         this.performedStartupPlay = true;
         this.cdInDrive = false;
         synchronized (this.tracksMutex) {
            this.tracks = null;
         }

         if (!this.cancel) {
            this.timedWait(10);
            synchronized (this.tracksMutex) {
               if (!this.cancel) {
                  try {
                     this.tracksMutex.wait();
                  } catch (InterruptedException var11) {
                  }
               }
            }
         }
      }

      Main.unregister(this);
   }

   public void useAutoCD(boolean var1) {
      if (var1 != useAutoCDFlag) {
         useAutoCDFlag = var1;
         IniFile.gamma().setIniInt("AUTOPLAYCD", useAutoCDFlag ? 1 : 0);
         if (var1) {
            if (this.trackToRepeat != -1) {
               this.queueCommand(5);
            }
         } else {
            this.queueCommand(0);
         }
      }
   }

   private synchronized void flushPendingCommands() {
      this.commandBuffer.removeAllElements();
   }

   private synchronized void prequeueCommand(int var1) {
      this.commandBuffer.insertElementAt(new Integer(var1), 0);
   }

   private synchronized void queueCommand(int var1) {
      if (var1 != 6) {
         this.allowMIDIAnyway = false;
      }

      this.commandBuffer.addElement(new Integer(var1));
   }

   private synchronized int getQueuedCommand(boolean var1) {
      if (this.commandBuffer.size() <= 0) {
         return -1;
      }

      int var2 = (Integer)this.commandBuffer.elementAt(0);
      if (var2 == 6) {
         if (!var1) {
            return -1;
         }
      } else if (var1 == this.cdInDrive) {
         return -1;
      }

      this.commandBuffer.removeElementAt(0);
      return var2;
   }

   private synchronized int peekQueuedCommand() {
      return this.commandBuffer.size() <= 0 ? -1 : (Integer)this.commandBuffer.elementAt(0);
   }

   private void waitForCommands() throws IOException {
      while (!this.cancel) {
         boolean var2 = CDPlayerAction.isPlaying(this.driveID);
         if (var2) {
            int var3 = CDPlayerAction.getPosition(this.driveID);
            if (var3 > this.pos) {
               this.pos = var3;
            }

            this.paused = false;
         } else {
            CDPlayerAction.checkDrive(this.driveID);
            if (!this.paused) {
               this.pos = 0;
            }

            if (this.repeatingTrack != -1) {
               this.pos = this.tracks.getStartFrames(this.repeatingTrack + this.trackOffset);
               CDPlayerAction.playAudio(this.driveID, this.pos, this.tracks.getEndFrames(this.repeatingTrack + this.trackOffset));
            }
         }

         int var1;
         if ((var1 = this.getQueuedCommand(false)) >= 0) {
            this.processCommand(var1, var2);
         } else {
            this.timedWait(1);
         }
      }

      CDPlayerAction.stopAudio(this.driveID);
   }

   private void processCommand(int var1, boolean var2) throws IOException {
      int var3 = this.repeatingTrack;
      this.repeatingTrack = -1;
      switch (var1) {
         case 0:
            if (var2 || this.paused) {
               CDPlayerAction.stopAudio(this.driveID);
            }

            this.paused = false;
            break;
         case 1:
            if (!var2) {
               this.play(-this.pos);
            }
            break;
         case 2:
            if (var2 && !this.paused) {
               CDPlayerAction.stopAudio(this.driveID);
               this.paused = true;
            }
            break;
         case 3:
            if (!var2 && !this.paused) {
               this.play(0);
            } else {
               for (int var5 = 0; var5 < this.tracks.getNumTracks() - 1; var5++) {
                  if (this.pos >= this.tracks.getStartFrames(var5) && this.pos < this.tracks.getEndFrames(var5)) {
                     this.play(var5 + 1);
                     return;
                  }
               }
            }
            break;
         case 4:
            if (var2 || this.paused) {
               for (int var4 = 0; var4 < this.tracks.getNumTracks(); var4++) {
                  if (this.pos < this.tracks.getEndFrames(var4)) {
                     if (var4 > 0 && this.pos < this.tracks.getStartFrames(var4) + 75) {
                        this.play(var4 - 1);
                     } else {
                        this.play(var4);
                     }
                     break;
                  }
               }
            }
            break;
         case 5:
            if (useAutoCDFlag && this.enabled) {
               if (this.trackToRepeat == -1 || this.trackToRepeat < this.tracks.getNumTracks()) {
                  this.repeatingTrack = this.trackToRepeat;
                  if (var3 == this.trackToRepeat && var3 != -1) {
                     return;
                  }
               }

               CDPlayerAction.stopAudio(this.driveID);
               if (this.repeatingTrack == -1) {
                  this.allowMIDIAnyway = true;
                  this.queueCommand(6);
               }

               this.paused = false;
            }
      }
   }

   private void play(int var1) throws IOException {
      if (var1 < 0) {
         this.pos = -var1;
      } else {
         this.pos = this.tracks.getStartFrames(var1);
      }

      CDPlayerAction.playAudio(this.driveID, this.pos, this.tracks.getEndFrames(this.tracks.getNumTracks() - 1));
      this.paused = false;
   }

   private void startMidi() {
      if (this.curMIDIFile != this.defaultMIDIFile) {
         if (this.midiPlayer != null) {
            this.midiPlayer.stop();
            this.midiPlayer.close();
            this.midiStarted = false;
            if (MCISoundPlayer.isActive() || WMPSoundPlayer.isActive()) {
               this.midiPlayer = null;
               return;
            }
         } else if (MCISoundPlayer.isActive() || WMPSoundPlayer.isActive()) {
            return;
         }

         Sound var1 = new Sound(this.curMIDIFile);
         if (!this.curMIDIFile.endsWith(".mid") && !this.curMIDIFile.endsWith(".wav")) {
            this.midiPlayer = new WMPSoundPlayer(var1);
         } else {
            this.midiPlayer = new MCISoundPlayer(var1);
         }

         this.midiPlayer.open(1.0F, 0.0F, false, false);
         if (!this.midiPaused) {
            this.midiPlayer.start(1);
         }
      }
   }

   private void killMidi() {
      if (this.midiPlayer != null) {
         this.midiStarted = false;
         this.midiPlayer.stop();
         this.midiPlayer.close();
         this.midiPlayer = null;
      }
   }

   private void useMidi() {
      if (useMidiFlag && this.enabled && (!this.cdInDrive || this.allowMIDIAnyway)) {
         if (this.midiPlayer == null) {
            this.startMidi();
         } else if (this.midiPlayer.getState() == 1) {
            if (this.midiStarted) {
               this.startMidi();
               this.midiStarted = false;
            }
         } else {
            this.midiStarted = true;
         }
      }

      if (!useMidiFlag || !this.enabled || this.cdInDrive && !this.allowMIDIAnyway) {
         this.killMidi();
      }
   }

   public void setMidiFlag(boolean var1) {
      useMidiFlag = var1;
      IniFile.gamma().setIniInt("MIDIONSTART", useMidiFlag ? 1 : 0);
   }

   public void mainCallback() {
      if (this.performedStartupPlay) {
         this.useMidi();

         while (this.midiPlayer != null || this.peekQueuedCommand() == 6) {
            if (this.cdInDrive && this.repeatingTrack != -1) {
               if (this.peekQueuedCommand() == 6) {
                  this.getQueuedCommand(true);
               }

               this.allowMIDIAnyway = false;
               this.useMidi();
               return;
            }

            int var1;
            if ((var1 = this.getQueuedCommand(true)) < 0) {
               return;
            }

            switch (var1) {
               case 0:
               case 2:
                  this.midiPaused = true;
                  this.midiPlayer.stop();
                  this.midiStarted = false;
                  break;
               case 1:
                  if (this.midiPaused || !this.midiStarted) {
                     this.midiPaused = false;
                     this.startMidi();
                  }
                  break;
               case 3:
               case 4:
                  this.startMidi();
                  break;
               case 5:
               case 6:
                  if (useMidiFlag && this.enabled) {
                     this.midiStarted = false;
                     this.midiPaused = false;
                     this.startMidi();
                  }
            }
         }
      }
   }

   private synchronized void timedWait(int var1) {
      if (!this.cancel) {
         try {
            this.wait(var1 * 1000);
         } catch (InterruptedException var3) {
         }
      }
   }

   public void terminalCallback() {
      this.cancel = true;
      this.killMidi();
      synchronized (this) {
         this.notify();
      }

      synchronized (this.tracksMutex) {
         this.tracksMutex.notify();
      }
   }

   private static String fmt2(int var0) {
      return var0 < 10 ? "0" + var0 : "" + var0;
   }

   private static String fmtFrames(int var0) {
      if (var0 < 0) {
         var0 = 0;
      }

      int var1 = var0 / 4500;
      var0 -= var1 * 4500;
      int var2 = var0 / 75;
      return "[" + fmt2(var1) + ":" + fmt2(var2) + "]";
   }
}
