package NET.worlds.scape;

import NET.worlds.console.Main;
import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import NET.worlds.network.CacheFile;
import NET.worlds.network.URL;
import java.io.IOException;
import java.util.Vector;

public class Sound extends Action implements BGLoaded, StateContext {
   static int debugLevel = IniFile.gamma().getIniInt("sounddebug", 0);
   private String cachedName;
   private URL soundURL;
   protected CacheFile cachedFile = null;
   protected float soundVolume = 1.0F;
   protected float stopDistance = 1000.0F;
   private int repeat = 1;
   private boolean continuous = false;
   private boolean attenuateOn = true;
   private boolean panningOn = true;
   protected SuperRoot activeSeq;
   SoundPlayer player;
   AudibilityFilter aFilter = null;
   private int maxHopcount = 1;
   private boolean doorMovementFlag = false;
   private static boolean soundOn = true;
   boolean playAfterLoading = true;
   protected int state = 0;
   protected static final int SYNC = 1;
   protected static final int ASYNC = 2;
   protected int backgroundState = 1;
   private static SoundCallback closer;
   static Vector cachedEntries;
   private static Vector pendingEntries;
   private boolean mainRan;
   private boolean opened;
   private static Object classCookie = new Object();

   private static void debugOut(int var0, String var1) {
      if (debugLevel > var0) {
         System.out.println(var1);
      }
   }

   public Sound(URL var1) {
      Transform.countClass(this, 1);
      debugOut(9, "Sound " + var1);
      this.setURL(var1);
   }

   public Sound() {
      Transform.countClass(this, 1);
      debugOut(9, "Sound ");
      this.setURL(null);
   }

   public final void setURL(URL var1) {
      if (this.activeSeq != null) {
         this.closePlayer();
      }

      this.soundURL = var1;
   }

   public final URL getURL() {
      return this.soundURL;
   }

   public final void setSoundVolume(float var1) {
      this.soundVolume = var1;
   }

   public final float getSoundVolume() {
      return this.soundVolume;
   }

   public final void setStopDistance(float var1) {
      this.stopDistance = var1;
   }

   public final float getStopDistance() {
      return this.stopDistance;
   }

   public final void setRepeat(int var1) {
      this.repeat = var1;
   }

   public final int getRepeat() {
      return this.repeat;
   }

   public final void setContinuous(boolean var1) {
      this.continuous = var1;
   }

   public final boolean isContinuous() {
      return this.continuous;
   }

   public final void setAttenuate(boolean var1) {
      this.attenuateOn = var1;
   }

   public final boolean getAttenuate() {
      return this.attenuateOn;
   }

   public final void setPanning(boolean var1) {
      this.panningOn = var1;
   }

   public final boolean getPanning() {
      return this.panningOn;
   }

   public final int getState() {
      return this.player.getState();
   }

   public final int getHopcount() {
      return this.maxHopcount;
   }

   public final void setHopcount(int var1) {
      this.maxHopcount = var1;
      if (this.aFilter != null) {
         this.aFilter.setHopcount(this.maxHopcount);
      }
   }

   public boolean getDoorMovementFlag() {
      return this.doorMovementFlag;
   }

   public void setDoorMovementFlag(boolean var1) {
      this.doorMovementFlag = var1;
      if (this.aFilter != null) {
         this.startAudibilityFilter();
      }
   }

   private void startAudibilityFilter() {
      debugOut(9, "startAudibilityFilter " + this.getURL());
      WObject var1 = (WObject)this.getOwner();
      if (var1 != null) {
         if (this.doorMovementFlag) {
            this.aFilter = new DoorBasedFilter(this, var1, this.maxHopcount, this.stopDistance);
         } else {
            this.aFilter = new AudibilityFilter(this, var1, this.maxHopcount);
         }

         this.aFilter.moveEmitter();
      }
   }

   public static void turnSoundOn() {
      soundOn = true;
   }

   public static void turnSoundOff() {
      soundOn = false;
   }

   public void setPlayAfterLoading(boolean var1) {
      this.playAfterLoading = var1;
   }

   protected boolean isRealAudio(URL var1) {
      return var1.endsWith(".ram") || var1.endsWith(".ra") || var1.endsWith(".rm");
   }

   public void changeState(int var1) {
      debugOut(9, "changeState to " + var1);
      this.state = var1;
   }

   protected Object doState(Object var1) {
      return SoundState.instance().doState(this, var1);
   }

   private boolean isBackgroundProcessing() {
      if (this.state != 0) {
         debugOut(9, "backgroundProcessing " + this.state);
      }

      return this.state != 0;
   }

   private void startSound() {
      this.backgroundState = 1;
      if (this.aFilter == null) {
         this.startAudibilityFilter();
      }

      if (this.aFilter != null) {
         this.aFilter.setEmitterOn(true);
      }

      if (this.state == 0) {
         this.state = 1;
      }

      this.doState(this.soundURL);
   }

   public Object asyncBackgroundLoad(String var1, URL var2) {
      this.backgroundState = 2;
      return this.doState(URL.make(var1));
   }

   public boolean syncBackgroundLoad(Object var1, URL var2) {
      this.backgroundState = 1;
      this.doState(var1);
      return false;
   }

   public Room getBackgroundLoadRoom() {
      WObject var1 = (WObject)this.getOwner();
      return var1 == null ? null : var1.getRoom();
   }

   protected void ensureClosure() {
      if (closer == null) {
         closer = new SoundCallback();
         Main.register(closer);
      }

      if (cachedEntries == null) {
         cachedEntries = new Vector();
      }

      cachedEntries.addElement(this.cachedFile);
   }

   protected void unlockCache() {
      if (this.cachedFile != null) {
         debugOut(6, "unlocking " + this.soundURL);
         this.cachedFile.finalize();
         Debug.dAssert(cachedEntries != null);
         Debug.dAssert(cachedEntries.indexOf(this.cachedFile, 0) >= 0);
         cachedEntries.removeElement(this.cachedFile);
         this.cachedFile = null;
      }
   }

   synchronized boolean openPlayer(URL var1) {
      Debug.dAssert(this.player == null);
      this.cachedName = var1.unalias();
      debugOut(4, "openPlayer on:: " + this.cachedName);
      if (var1.endsWith(".wav")) {
         this.player = new WavSoundPlayer(this);
      } else if (var1.endsWith(".mid")) {
         this.player = new MCISoundPlayer(this);
      } else {
         this.player = new WMPSoundPlayer(this);
      }

      if (Main.isMainThread()) {
         this.openInMainThread();
      } else {
         this.mainRan = false;
         Main.register(new Sound$1(this));

         while (!this.mainRan) {
            try {
               this.wait();
            } catch (InterruptedException var3) {
            }
         }
      }

      return this.opened;
   }

   public synchronized void openInMainThread() {
      this.opened = this.player.open(this.soundVolume, this.stopDistance, this.attenuateOn, this.panningOn);
      if (!this.opened) {
         this.closePlayer();
      }

      this.mainRan = true;
      this.notify();
   }

   void closePlayer() {
      if (this.player != null) {
         this.player.stop();
         this.unlockCache();
         if (SoundResource.instance().syncUnlock()) {
            this.player.close();
         }

         this.player = null;
      }

      debugOut(2, "   closePlayer");
   }

   public Persister trigger(Event var1, Persister var2) {
      debugOut(9, "trigger in: seqID " + var2 + " activeSeq " + this.activeSeq);
      if (this.isBackgroundProcessing()) {
         return this.activeSeq;
      }

      if (var2 == null) {
         if (this.soundURL == null || this.getOwner() == null) {
            return null;
         }

         if (this.activeSeq != null) {
            this.closePlayer();
         }

         this.activeSeq = this;
         var2 = this.activeSeq;
         debugOut(6, "triggering new sound " + var2);
         this.startSound();
      } else if (var2 != this.activeSeq) {
         this.unlockCache();
         if (!this.isContinuous()) {
            this.aFilter.setEmitterOn(false);
         }

         return null;
      }

      if (this.player != null && this.player.getState() != 0 && !this.isContinuous()) {
         this.aFilter.setEmitterOn(false);
      }

      if ((this.isBackgroundProcessing() || this.updateSound() && this.player.getState() == 0) && this.getOwner() != null) {
         return this.activeSeq;
      }

      this.activeSeq = null;
      this.closePlayer();
      return null;
   }

   boolean updateSound() {
      debugOut(9, "Sound::updateSound:: in");
      if (this.player == null) {
         debugOut(6, "update returning false because player is null");
         return false;
      }

      if (!SoundResource.instance().isOK()) {
         debugOut(2, "update registering not OK");
         return false;
      }

      if (!this.aFilter.isAudible()) {
         debugOut(4, "update stopping sound because isAudible false");
         return false;
      }

      Point3Temp var1 = Point3Temp.make();
      Point3Temp var2 = Point3Temp.make();
      Point3Temp var3 = Point3Temp.make();
      Point3Temp var4 = Point3Temp.make();
      this.aFilter.getListenerPosition(var1, var2, var3);
      this.aFilter.getEmitterPosition(var4);
      if (!this.player.position(var1, var4, var3, var2)) {
         debugOut(6, "update returning false because position false");
         return false;
      }

      float var5 = -1.0F;
      if (soundOn) {
         var5 = this.aFilter.getEmitterVolume();
      }

      if (!this.player.setVolume(var5 * this.soundVolume)) {
         debugOut(6, "update returning false because volume false");
         return false;
      } else {
         return true;
      }
   }

   public void postRestore(int var1) {
      super.postRestore(var1);
      this.startAudibilityFilter();
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = URLPropertyEditor.make(new Property(this, var1, "Sound File URL").allowSetNull(), "asf;wav;mid;ram;ra;rm;mp3");
            } else if (var3 == 1) {
               var5 = this.soundURL;
            } else if (var3 == 2) {
               this.soundURL = (URL)var4;
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Max Volume"));
            } else if (var3 == 1) {
               var5 = new Float(this.soundVolume);
            } else if (var3 == 2) {
               this.soundVolume = (Float)var4;
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Stop Distance"));
            } else if (var3 == 1) {
               var5 = new Float(this.stopDistance);
            } else if (var3 == 2) {
               this.stopDistance = (Float)var4;
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Times to Repeat"));
            } else if (var3 == 1) {
               var5 = new Integer(this.repeat);
            } else if (var3 == 2) {
               this.repeat = (Integer)var4;
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Attenuate With Distance"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.attenuateOn);
            } else if (var3 == 2) {
               this.attenuateOn = (Boolean)var4;
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Do panning"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.panningOn);
            } else if (var3 == 2) {
               this.panningOn = (Boolean)var4;
            }
            break;
         case 6:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Room hops till sound dies"));
            } else if (var3 == 1) {
               var5 = new Integer(this.maxHopcount);
            } else if (var3 == 2) {
               this.setHopcount((Integer)var4);
            }
            break;
         case 7:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Door based audibility"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getDoorMovementFlag());
            } else if (var3 == 2) {
               this.setDoorMovementFlag((Boolean)var4);
            }
            break;
         case 8:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Play after loading"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.playAfterLoading);
            } else if (var3 == 2) {
               this.setPlayAfterLoading((Boolean)var4);
            }
            break;
         case 9:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Loop Infinite"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.continuous);
            } else if (var3 == 2) {
               this.setContinuous((Boolean)var4);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 10, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(7, classCookie);
      var1.saveBoolean(this.playAfterLoading);
      var1.saveBoolean(this.doorMovementFlag);
      var1.saveBoolean(this.panningOn);
      var1.saveBoolean(this.attenuateOn);
      var1.saveInt(this.maxHopcount);
      super.saveState(var1);
      URL.save(var1, this.soundURL);
      var1.saveFloat(this.soundVolume);
      var1.saveFloat(this.stopDistance);
      var1.saveInt(this.repeat);
      var1.saveBoolean(this.continuous);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      int var2 = var1.restoreVersion(classCookie);
      switch (var2) {
         case 0:
            this.setURL(URL.restore(var1));
            break;
         case 1:
            this.setURL(URL.restore(var1));
            this.soundVolume = var1.restoreFloat();
            this.stopDistance = var1.restoreFloat();
            this.repeat = var1.restoreInt();
            if (this.repeat < 0) {
               this.setContinuous(true);
            }
            break;
         case 2:
            super.restoreState(var1);
            this.setURL(URL.restore(var1));
            this.soundVolume = var1.restoreFloat();
            this.stopDistance = var1.restoreFloat();
            this.repeat = var1.restoreInt();
            if (this.repeat < 0) {
               this.setContinuous(true);
            }
            break;
         case 3:
            this.setHopcount(var1.restoreInt());
            super.restoreState(var1);
            this.setURL(URL.restore(var1));
            this.soundVolume = var1.restoreFloat();
            this.stopDistance = var1.restoreFloat();
            this.repeat = var1.restoreInt();
            if (this.repeat < 0) {
               this.setContinuous(true);
            }
            break;
         case 4:
            this.setDoorMovementFlag(var1.restoreBoolean());
            this.setPanning(var1.restoreBoolean());
            this.setAttenuate(var1.restoreBoolean());
            this.setHopcount(var1.restoreInt());
            super.restoreState(var1);
            this.setURL(URL.restore(var1));
            this.soundVolume = var1.restoreFloat();
            this.stopDistance = var1.restoreFloat();
            this.repeat = var1.restoreInt();
            if (this.repeat < 0) {
               this.setContinuous(true);
            }
            break;
         case 5:
            this.setPlayAfterLoading(var1.restoreBoolean());
            this.setDoorMovementFlag(var1.restoreBoolean());
            this.setPanning(var1.restoreBoolean());
            this.setAttenuate(var1.restoreBoolean());
            this.setHopcount(var1.restoreInt());
            super.restoreState(var1);
            this.setURL(URL.restore(var1));
            this.soundVolume = var1.restoreFloat();
            this.stopDistance = var1.restoreFloat();
            this.repeat = var1.restoreInt();
            if (this.repeat < 0) {
               this.setContinuous(true);
            }
            break;
         case 6:
            this.setPlayAfterLoading(var1.restoreBoolean());
            this.setDoorMovementFlag(var1.restoreBoolean());
            this.setPanning(var1.restoreBoolean());
            this.setAttenuate(var1.restoreBoolean());
            this.setHopcount(var1.restoreInt());
            super.restoreState(var1);
            this.setURL(URL.restore(var1));
            this.soundVolume = var1.restoreFloat();
            this.stopDistance = var1.restoreFloat();
            this.repeat = var1.restoreInt();
            if (this.repeat < 0) {
               this.setContinuous(true);
            }
            break;
         case 7:
            this.setPlayAfterLoading(var1.restoreBoolean());
            this.setDoorMovementFlag(var1.restoreBoolean());
            this.setPanning(var1.restoreBoolean());
            this.setAttenuate(var1.restoreBoolean());
            this.setHopcount(var1.restoreInt());
            super.restoreState(var1);
            this.setURL(URL.restore(var1));
            this.soundVolume = var1.restoreFloat();
            this.stopDistance = var1.restoreFloat();
            this.repeat = var1.restoreInt();
            this.setContinuous(var1.restoreBoolean());
            break;
         default:
            throw new TooNewException();
      }

      if (var2 < 6 && this.continuous) {
         this.setContinuous(false);
      }
   }

   static {
      debugOut(1, "SOUND DEBUGGING LEVEL = " + debugLevel);
   }
}
