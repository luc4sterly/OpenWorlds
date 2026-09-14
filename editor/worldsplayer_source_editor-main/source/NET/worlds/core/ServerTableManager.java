package NET.worlds.core;

import NET.worlds.console.Gamma;
import NET.worlds.network.Cache;
import NET.worlds.network.CacheFile;
import NET.worlds.network.NetUpdate;
import NET.worlds.network.ProgressDialog;
import NET.worlds.network.URL;
import NET.worlds.scape.BGLoaded;
import NET.worlds.scape.BackgroundLoader;
import NET.worlds.scape.Room;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.io.StringReader;
import java.util.StringTokenizer;
import java.util.Vector;

public class ServerTableManager implements BGLoaded {
   private Hashtable tables;
   private String tableFile;
   private int fileVersion = 0;
   public static ServerTableManager theTableManager = null;
   private static String tableStart = "private static String[] ";
   private static String version = "VERSION";

   public int getFileVersion() {
      return this.fileVersion;
   }

   public static ServerTableManager instance() {
      if (theTableManager == null) {
         theTableManager = new ServerTableManager();
      }

      return theTableManager;
   }

   public String[] getTable(String var1) {
      Object var2 = this.tables.get(var1);
      if (var2 == null) {
         System.out.println("Requested table " + var1 + " not found.");
      }

      return (String[])var2;
   }

   private ServerTableManager() {
      this.tables = new Hashtable();
      this.tableFile = IniFile.override().getIniString("ServerTableFile", "tables/tables.dat");
      if (IniFile.gamma().getIniInt("encryptTables", 0) == 1) {
         this.encryptTablesFile();
      }

      this.loadTableFile();
   }

   private boolean loadTableFile() {
      URL var1 = URL.make(NetUpdate.getUpgradeServerURL() + this.tableFile);
      boolean var2 = IniFile.gamma().getIniInt("synchronousTableLoad", 1) == 1;
      if (Gamma.loadProgress != null) {
         Gamma.loadProgress.setMessage("Downloading global server information...");
         Gamma.loadProgress.advance();
      }

      if (var2) {
         CacheFile var3 = Cache.getFile(var1);
         var3.waitUntilLoaded();
         if (!var3.error()) {
            this.syncBackgroundLoad(var3.getLocalName(), null);
         }
      }

      boolean var4 = this.parseFile();
      if (!var2) {
         BackgroundLoader.get(this, var1);
      }

      return var4;
   }

   public synchronized Object asyncBackgroundLoad(String var1, URL var2) {
      return var1;
   }

   public boolean syncBackgroundLoad(Object var1, URL var2) {
      String var3 = (String)var1;
      if (var3 != null && new File(var3).exists()) {
         ProgressDialog.copyFile(var3, this.tableFile);
      }

      return false;
   }

   public Room getBackgroundLoadRoom() {
      return null;
   }

   private boolean parseFile() {
      BufferedReader var1 = null;

      try {
         RandomAccessFile var2 = new RandomAccessFile(this.tableFile, "r");
         byte[] var3 = new byte[var2.readInt()];
         var2.readFully(var3);
         var2.close();
         String var4 = this.decrypt(var3);
         var1 = new BufferedReader(new StringReader(var4));

         String var5;
         while ((var5 = var1.readLine()) != null) {
            var5 = var5.trim();
            if (!var5.startsWith("//") && var5.length() != 0) {
               if (var5.startsWith(version)) {
                  StringTokenizer var6 = new StringTokenizer(var5);
                  String var7 = "";

                  while (var6.hasMoreTokens()) {
                     var7 = var6.nextToken();
                  }

                  if (var7 != "") {
                     this.fileVersion = Double.valueOf(var7).intValue();
                  }
               }

               if (var5.startsWith(tableStart)) {
                  String var12 = var5.substring(tableStart.length());
                  StringTokenizer var13 = new StringTokenizer(var12);
                  if (var13.hasMoreTokens()) {
                     this.parseTable(var1, var13.nextToken().trim());
                  }
               }
            }
         }

         var1.close();
         return true;
      } catch (FileNotFoundException var8) {
         System.out.println(var8);
         return false;
      } catch (IOException var9) {
         System.out.println(var9);
         return false;
      }
   }

   private String stripQuotes(String var1) {
      String var2 = new String(var1);
      if (var2.charAt(0) == '"') {
         var2 = var2.substring(1);
      }

      if (var2.charAt(var2.length() - 1) == '"') {
         var2 = var2.substring(0, var2.length() - 1);
      }

      int var3;
      while ((var3 = var2.indexOf(34)) != -1) {
         var2 = var2.substring(0, var3) + var2.substring(var3 + 1);
      }

      return var2;
   }

   private void parseTable(BufferedReader var1, String var2) throws IOException {
      String var4 = null;
      Vector var5 = new Vector();

      String var3;
      while ((var3 = var1.readLine()) != null) {
         var3 = var3.trim();
         if (var3.length() != 0 && !var3.startsWith("//")) {
            if (var3.startsWith("};")) {
               break;
            }

            StringTokenizer var6 = new StringTokenizer(var3, ",\n\r");

            while (var6.hasMoreTokens()) {
               String var7 = var6.nextToken().trim();
               if (var7.startsWith("+ \"")) {
                  if (var4 != null) {
                     var7 = var7.substring(2);
                     var4 = var4 + this.stripQuotes(var7);
                     var5.removeElement(var5.lastElement());
                     var5.addElement(var4);
                  }
               } else {
                  String var8 = this.stripQuotes(var7);
                  var4 = var8;
                  var5.addElement(var8);
               }
            }
         }
      }

      int var10 = var5.size();
      String[] var12 = new String[var10];

      for (int var13 = 0; var13 < var10; var13++) {
         var12[var13] = (String)var5.elementAt(var13);
      }

      System.out.println("Adding table " + var2);
      this.tables.put(var2, var12);
   }

   private byte[] encrypt(String var1) {
      byte[] var2;
      try {
         var2 = var1.getBytes("UTF8");
      } catch (Exception var6) {
         System.out.println("Error encoding to UTF8" + var6.toString());
         return null;
      }

      byte[] var3 = new byte[var2.length];
      int var4 = var2.length;
      var3[0] = var2[0];

      for (int var5 = 1; var5 < var4; var5++) {
         var3[var5] = (byte)(var2[var5] ^ var3[var5 - 1]);
      }

      return var3;
   }

   private String decrypt(byte[] var1) {
      byte[] var2 = new byte[var1.length];
      int var3 = var1.length;
      var2[0] = var1[0];

      for (int var4 = 1; var4 < var3; var4++) {
         var2[var4] = (byte)(var1[var4] ^ var1[var4 - 1]);
      }

      try {
         return new String(var2, "UTF8");
      } catch (Exception var6) {
         System.out.println("Error encoding UTF8 " + var6.toString());
         return null;
      }
   }

   private void encryptTablesFile() {
      try {
         System.out.println("Encoding tables file...");
         RandomAccessFile var1 = new RandomAccessFile("..\\tables.txt", "r");
         String var2 = new String();

         while (var1.getFilePointer() < var1.length()) {
            String var3 = var1.readLine();
            System.out.println(var3);
            var2 = var2 + var3 + "\r\n";
         }

         var1.close();
         byte[] var7 = this.encrypt(var2);
         RandomAccessFile var4 = new RandomAccessFile(this.tableFile, "rw");
         RandomAccessFile var5 = new RandomAccessFile("..\\tables.dat", "rw");
         var4.writeInt(var7.length);
         var5.writeInt(var7.length);
         var4.write(var7);
         var5.write(var7);
         var4.close();
         var5.close();
         System.out.println("Tables file " + this.tableFile + " successfully written.");
      } catch (Exception var6) {
         System.out.println("Error encoding tables file: " + var6.toString());
      }
   }
}
