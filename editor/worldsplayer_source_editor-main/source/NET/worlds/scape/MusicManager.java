package NET.worlds.scape;

import NET.worlds.console.DialogReceiver;
import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.core.Sort;
import NET.worlds.network.URL;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.StringTokenizer;

public class MusicManager implements MainCallback, DialogReceiver {
   private static Hashtable managers = new Hashtable();
   private static MusicManagerDialog dialog;
   private static boolean registered;
   private static URL lastWorldURL;
   private static boolean showDialog;
   private static MusicManager curManager;
   private static String lastRoomName = "";
   private static int lastCDTrack;
   private static URL lastMIDIFile;
   private String name;
   private Hashtable tracks = new Hashtable();
   private Hashtable rooms = new Hashtable();
   private World world;
   private String fileName;
   private boolean maybeMusicChange;

   public static void showDialog() {
      if (dialog == null) {
         showDialog = true;
      }
   }

   public MusicManager() {
      if (!registered) {
         Main.register(this);
         registered = true;
         curManager = this;
      }
   }

   private MusicManager(World var1, URL var2) {
      this.world = var1;
      this.name = var1.getName();
      String var3 = var2.unalias().toLowerCase();
      int var4 = var3.lastIndexOf(".world");
      if (var4 != -1) {
         this.fileName = var2.unalias().substring(0, var4) + ".music";
         this.load();
      }
   }

   public World getWorld() {
      return this.world;
   }

   public String getName() {
      return this.name;
   }

   public String getFileName() {
      return this.fileName;
   }

   public Hashtable getMusic() {
      return this.tracks;
   }

   public MusicTrack getMusic(String var1) {
      return (MusicTrack)this.tracks.get(var1);
   }

   public Hashtable getRooms() {
      return this.rooms;
   }

   public MusicRoom getRoom(String var1) {
      return (MusicRoom)this.rooms.get(var1);
   }

   public synchronized void maybeChangedMusic() {
      this.maybeMusicChange = true;
   }

   public void save() {
      PrintStream var1 = null;

      try {
         var1 = new PrintStream(new FileOutputStream(this.fileName));
         Enumeration var2 = this.tracks.elements();
         String[] var3 = Sort.sortKeys(this.tracks);

         for (int var4 = 0; var4 < var3.length; var4++) {
            MusicTrack var5 = (MusicTrack)this.tracks.get(var3[var4]);
            String var6 = var5.getMIDIFileName();
            if (var6.length() == 0) {
               var6 = "-";
            }

            var1.println("MUSIC|" + var5.getName() + "|" + var5.getVirtTrackNumber() + "|" + var6 + "|" + var5.getLooping());
         }

         var3 = Sort.sortKeys(this.rooms);

         for (int var13 = 0; var13 < var3.length; var13++) {
            MusicRoom var14 = (MusicRoom)this.rooms.get(var3[var13]);
            var1.println("ROOM|" + var14.getRoomName() + "|" + var14.getMusicName());
         }
      } catch (Exception var10) {
      } finally {
         if (var1 != null) {
            var1.close();
         }
      }
   }

   private void load() {
      this.tracks.clear();
      this.rooms.clear();
      DataInputStream var1 = null;
      String var2 = null;

      try {
         var1 = new DataInputStream(new FileInputStream(this.fileName));

         while ((var2 = var1.readLine()) != null) {
            StringTokenizer var3 = new StringTokenizer(var2, "|");
            String var4 = var3.nextToken();
            if (var4.equals("MUSIC")) {
               MusicTrack var5 = new MusicTrack(var3.nextToken(), Integer.parseInt(var3.nextToken()), var3.nextToken(), Boolean.valueOf(var3.nextToken()));
               this.tracks.put(var5.getName(), var5);
            } else if (var4.equals("ROOM")) {
               MusicRoom var18 = new MusicRoom(var3.nextToken(), var3.nextToken());
               this.rooms.put(var18.getRoomName(), var18);
            }
         }
      } catch (Exception var15) {
      } finally {
         try {
            if (var1 != null) {
               var1.close();
            }
         } catch (IOException var14) {
         }
      }
   }

   public void mainCallback() {
      Pilot var1 = Pilot.getActive();
      if (var1 != null) {
         World var2 = var1.getWorld();
         boolean var3 = false;
         String var4 = "";
         if (var2 != null) {
            URL var5 = var2.getSourceURL();
            if (!var5.equals(lastWorldURL)) {
               MusicManager var6 = (MusicManager)managers.get(var5);
               if (var6 == null) {
                  var6 = new MusicManager(var2, var5);
                  managers.put(var5, var6);
               }

               lastWorldURL = var5;
               curManager = var6;
               var3 = true;
            }

            Room var16 = var1.getRoom();
            if (var16 != null) {
               String var7 = var16.getName();
               if (var7 != null) {
                  var4 = var7;
               }
            }
         } else {
            lastWorldURL = null;
         }

         synchronized (this) {
            if (var3 || !var4.equals(lastRoomName) || curManager.maybeMusicChange) {
               curManager.maybeMusicChange = false;
               lastRoomName = var4;
               MusicRoom var17 = curManager.getRoom(lastRoomName);
               CDAudio var18 = CDAudio.get();
               boolean var8 = false;
               if (var17 != null) {
                  MusicTrack var9 = curManager.getMusic(var17.getMusicName());
                  if (var9 != null) {
                     var8 = true;
                     int var10 = var9.getVirtTrackNumber();
                     boolean var11 = false;
                     if (var10 != var18.getCDTrack()) {
                        lastCDTrack = var10;
                        var18.setCDTrack(var10);
                        var11 = true;
                     }

                     String var12 = var9.getMIDIFileName();
                     URL var13;
                     if (var12.length() != 0) {
                        var13 = URL.make(var2.getSourceURL(), var9.getMIDIFileName());
                     } else {
                        var13 = var18.getDefaultMIDIFile();
                     }

                     if (!var13.equals(var18.getMIDIFile())) {
                        lastMIDIFile = var13;
                        var18.setMIDIFile(var13);
                        var11 = true;
                     }

                     if (var11) {
                        var18.change(var9.getLooping());
                     }
                  }
               }

               if (!var8) {
                  if (lastCDTrack != 0 && var18.getCDTrack() == lastCDTrack || lastMIDIFile != null && lastMIDIFile.equals(var18.getMIDIFile())) {
                     var18.setCDTrack(0);
                     var18.setMIDIFile(var18.getDefaultMIDIFile());
                     var18.stop();
                  }

                  lastCDTrack = 0;
                  lastMIDIFile = null;
               }
            }
         }
      } else {
         lastWorldURL = null;
      }

      if (lastWorldURL != null && dialog == null && showDialog) {
         showDialog = false;
         dialog = new MusicManagerDialog((MusicManager)managers.get(lastWorldURL));
      }
   }

   public void dialogDone(Object var1, boolean var2) {
      if (var2) {
         this.save();
      } else {
         this.load();
         this.maybeChangedMusic();
      }

      dialog = null;
   }
}
