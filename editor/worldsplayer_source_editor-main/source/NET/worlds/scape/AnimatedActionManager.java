package NET.worlds.scape;

import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import NET.worlds.network.NetUpdate;
import NET.worlds.network.URL;
import java.awt.Menu;
import java.awt.MenuItem;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.Enumeration;
import java.util.StringTokenizer;
import java.util.Vector;

public class AnimatedActionManager implements ActionListener, BGLoaded {
   private AnimatedAction _currentAction = null;
   static final String actionFile = "actions/actions.dat";
   static final String localActionFile = "actions.dat";
   static final String version = "VERSION";
   static final String action = "ACTION";
   private Vector actionList;
   private Vector currentMenuActions;
   private static AnimatedActionManager theAnimatedActionManager = null;

   public static AnimatedActionManager get() {
      if (theAnimatedActionManager == null) {
         theAnimatedActionManager = new AnimatedActionManager();
      }

      return theAnimatedActionManager;
   }

   private Vector getActionList(URL var1, URL var2) {
      if (this.actionList != null && var1 != null && var2 != null) {
         String var3 = PosableShape.getBodyType(var1);
         if (var3 == null) {
            return null;
         }

         String var4 = var2.toString();
         int var5 = var4.lastIndexOf(".");
         if (var5 != -1) {
            var4 = var4.substring(0, var5);
         }

         Vector var6 = new Vector();
         Enumeration var7 = this.actionList.elements();

         while (var7.hasMoreElements()) {
            AnimatedAction var8 = (AnimatedAction)var7.nextElement();
            if (this.vectorCheck(var3, var8.avatarNames) && this.vectorCheck(var4, var8.targetObjects)) {
               var6.addElement(var8);
            }
         }

         return var6;
      } else {
         return null;
      }
   }

   private boolean vectorCheck(String var1, Vector var2) {
      Enumeration var3 = var2.elements();

      while (var3.hasMoreElements()) {
         String var4 = (String)var3.nextElement();
         if (var1.toLowerCase().endsWith(var4.toLowerCase())) {
            return true;
         }

         if (var4.equals("any")) {
            return true;
         }
      }

      return false;
   }

   public boolean buildActionMenu(Menu var1, Shape var2) {
      Debug.dAssert(var1 != null);
      if (this._currentAction != null) {
         return false;
      }

      SuperRoot var3 = var2;

      while (var3.getOwner() != null) {
         var3 = var3.getOwner();
         if (var3 instanceof PosableShape) {
            var2 = (Shape)var3;
            break;
         }
      }

      Pilot var4 = Pilot.getActive();
      if (var4 == null) {
         return false;
      }

      if (!(var4 instanceof HoloPilot)) {
         return false;
      }

      HoloPilot var5 = (HoloPilot)var4;
      if (var5.getInternalDrone().getRoom() != var2.getRoom()) {
         return false;
      }

      Vector var6 = this.getActionList(var5.getInternalDrone().getCurrentURL(), var2.getURL());
      this.currentMenuActions = var6;
      if (var6 == null) {
         return false;
      }

      if (var6.size() == 0) {
         return false;
      }

      Enumeration var7 = var6.elements();

      while (var7.hasMoreElements()) {
         AnimatedAction var8 = (AnimatedAction)var7.nextElement();
         var8.setTargetShape(var2);
         int var9 = var8.actionName.indexOf("\\");
         if (var9 != -1) {
            String var10 = var8.actionName.substring(var9 + 1);
            String var11 = var8.actionName.substring(0, var9);
            int var12 = var1.getItemCount();
            boolean var13 = false;

            for (int var14 = 0; var14 < var12; var14++) {
               MenuItem var15 = var1.getItem(var14);
               if (var15.getLabel().equals(var11) && var15 instanceof Menu) {
                  ((Menu)var15).add(var10);
                  var13 = true;
                  break;
               }
            }

            if (!var13) {
               Menu var16 = new Menu(var11);
               var16.addActionListener(this);
               var16.add(var10);
               var1.add(var16);
            }
         } else {
            var1.add(var8.actionName);
         }
      }

      return true;
   }

   public boolean processMenuClick(String var1) {
      if (this.currentMenuActions == null) {
         return false;
      }

      Enumeration var2 = this.currentMenuActions.elements();

      while (var2.hasMoreElements()) {
         AnimatedAction var3 = (AnimatedAction)var2.nextElement();
         String var4 = var3.actionName;
         int var5 = var4.indexOf(92);
         if (var5 != -1) {
            var4 = var4.substring(var5 + 1);
         }

         if (var4.equals(var1)) {
            Pilot var6 = Pilot.getActive();
            if (var6 == null) {
               return false;
            }

            if (!(var6 instanceof HoloPilot)) {
               return false;
            }

            HoloPilot var7 = (HoloPilot)var6;
            if (this._currentAction != null) {
               this._currentAction.abort();
            }

            this._currentAction = var3;
            var3.execute(var7);
            return true;
         }
      }

      return false;
   }

   public void actionCompleted(AnimatedAction var1) {
      Debug.dAssert(var1 == this._currentAction);
      this._currentAction = null;
   }

   public void actionPerformed(ActionEvent var1) {
      this.processMenuClick(var1.getActionCommand());
   }

   private AnimatedActionManager() {
      System.out.println("Loading action manager");
      this.actionList = new Vector();
      this.loadActionsFile();
   }

   private void loadActionsFile() {
      File var1 = new File("actions.dat");
      if (var1.exists()) {
         this.parseActionFile("actions.dat");
      }

      String var2 = NetUpdate.getUpgradeServerURL();
      String var3 = IniFile.override().getIniString("actionFile", "actions/actions.dat");
      BackgroundLoader.get(this, URL.make(var2 + var3));
   }

   public synchronized Object asyncBackgroundLoad(String var1, URL var2) {
      return var1;
   }

   public boolean syncBackgroundLoad(Object var1, URL var2) {
      System.out.println("Got actions file ");
      String var3 = (String)var1;
      if (var3 != null && new File(var3).exists()) {
         this.parseActionFile(var3);
      }

      return false;
   }

   public Room getBackgroundLoadRoom() {
      return null;
   }

   private String getLine(RandomAccessFile var1) throws IOException {
      while (var1.getFilePointer() < var1.length()) {
         String var2 = var1.readLine().trim();
         if (var2 == null) {
            return null;
         }

         if (!var2.startsWith("//") && var2.length() != 0) {
            return var2;
         }
      }

      return null;
   }

   private void parseActionFile(String var1) {
      byte var3 = 0;
      Debug.dAssert(this.actionList != null);
      this.actionList.removeAllElements();

      try {
         RandomAccessFile var2 = new RandomAccessFile(var1, "r");

         String var4;
         while ((var4 = this.getLine(var2)) != null) {
            StringTokenizer var5 = new StringTokenizer(var4);
            String var6 = var5.nextToken();
            if (var6.equals("VERSION")) {
               String var7 = var5.nextToken();
               if (var7.equals("1")) {
                  var3 = 1;
               } else {
                  if (!var7.equals("2")) {
                     throw new Exception("Bad version.");
                  }

                  var3 = 2;
               }
            } else if (var6.equals("ACTION")) {
               if (var3 == 0) {
                  throw new Exception("Actions file version not specified.");
               }

               AnimatedAction var13 = new AnimatedAction();
               var13.actionName = var4.substring("ACTION".length() + 1);
               this.readVector(var2, var13.avatarNames);
               this.readVector(var2, var13.targetObjects);
               if (var3 > 1) {
                  var13.consentRequired = this.getLine(var2).toLowerCase().equals("consent");
               }

               StringTokenizer var8 = new StringTokenizer(this.getLine(var2));
               Float var9 = new Float(var8.nextToken());
               Float var10 = new Float(var8.nextToken());
               var13.targetRelPosition = new Point2(var9, var10);
               Float var11 = new Float(this.getLine(var2));
               var13.targetRelYaw = var11.floatValue();
               var13.preAnimationAction = AnimatedAction.getAction(this.getLine(var2));
               var13.preAnimationParameter = this.getLine(var2);
               var13.actionName1 = this.getLine(var2);
               if (var3 > 1) {
                  var13.simultaneousAction = AnimatedAction.getAction(this.getLine(var2));
                  var13.simultaneousParameter = this.getLine(var2);
               }

               var13.postAnimationAction = AnimatedAction.getAction(this.getLine(var2));
               var13.postAnimationParameter = this.getLine(var2);
               var13.actionName2 = this.getLine(var2);
               this.actionList.addElement(var13);
            }
         }

         var2.close();
      } catch (Exception var12) {
         System.out.println("Error reading actions.dat: " + var12.toString());
      }
   }

   private void readVector(RandomAccessFile var1, Vector var2) throws IOException {
      String var3 = this.getLine(var1);
      StringTokenizer var4 = new StringTokenizer(var3);

      while (var4.hasMoreTokens()) {
         var2.addElement(var4.nextToken());
      }
   }
}
