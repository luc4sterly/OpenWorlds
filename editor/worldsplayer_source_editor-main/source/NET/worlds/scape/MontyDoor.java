package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.network.URL;
import java.io.IOException;
import java.text.MessageFormat;
import java.util.Enumeration;

public class MontyDoor extends Portal implements MouseDownHandler, MainCallback {
   boolean setsAvatar = false;
   URL url;
   String description = "";
   DialogAction action;
   String viewName;
   URL viewURL;
   Persister lastTrigger;
   private static Object classCookie = new Object();

   public MontyDoor() {
      this.flags |= 262144;
   }

   public boolean handle(MouseDownEvent var1) {
      if ((var1.key & 1) == 0) {
         return false;
      }

      if (this.action == null && this.url != null) {
         if (this.setsAvatar) {
            SelectAvatarAction var2 = new SelectAvatarAction();
            var2.url = this.viewURL;
            var2.description = this.description;
            this.action = var2;
         } else {
            SendURLAction var3 = new SendURLAction();
            var3.destination = this.url;
            var3.description = this.description;
            this.action = var3;
         }

         this.action.cancelOnly = true;
         Main.register(this);
         return true;
      } else {
         return true;
      }
   }

   public void mainCallback() {
      if (this.action.cancelOnly) {
         this.lastTrigger = this.action.trigger(null, this.lastTrigger);
         if (this.lastTrigger != null) {
            return;
         }

         if (this.viewURL != null && this.viewName != null && this._farSideRoomName != null) {
            Room var1 = this.getRoom();
            World var2;
            if (var1 != null && (var2 = var1.getWorld()) != null) {
               var1 = var2.getRoom(this._farSideRoomName);
               if (var1 == null) {
                  Main.unregister(this);
                  this.action = null;
                  Object[] var5 = new Object[]{new String(this.getName()), new String(this._farSideRoomName)};
                  Console.println(MessageFormat.format(Console.message("MontyDoor"), var5));
                  return;
               }

               Enumeration var3 = var1.getDeepOwned();
               SetPropertyAction.propHelper(2, this.viewURL, "File", SuperRoot.nameSearch(var3, this.viewName));
            }
         }

         this.action.cancelOnly = false;
         this.flags &= -262145;
         this.reset();
      }

      this.lastTrigger = this.action.trigger(null, this.lastTrigger);
      if (this.lastTrigger == null) {
         Main.unregister(this);
         this.action = null;
         this.flags |= 262144;
         this.reset();
      }
   }

   public BumpCalc getBumpCalc(BumpEventTemp var1) {
      return standardPlaneBumpCalc;
   }

   public boolean handle(BumpEventTemp var1) {
      return true;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Avatar type"), "SendURL", "SelectAvatar");
            } else if (var3 == 1) {
               var5 = new Boolean(this.setsAvatar);
            } else if (var3 == 2) {
               this.setsAvatar = (Boolean)var4;
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = URLPropertyEditor.make(new Property(this, var1, "URL (used only for non-avatar)").allowSetNull(), null);
            } else if (var3 == 1) {
               var5 = this.url;
            } else if (var3 == 2) {
               this.url = (URL)var4;
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Description"));
            } else if (var3 == 1) {
               var5 = this.description;
            } else if (var3 == 2) {
               this.description = ((String)var4).toString().trim();
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = URLPropertyEditor.make(new Property(this, var1, "Display URL").allowSetNull(), null);
            } else if (var3 == 1) {
               var5 = this.viewURL;
            } else if (var3 == 2) {
               this.viewURL = (URL)var4;
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Display Name"));
            } else if (var3 == 1) {
               var5 = this.viewName;
            } else if (var3 == 2) {
               this.viewName = ((String)var4).toString().trim();
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 5, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      int var2 = this.flags;
      this.flags |= 262144;
      super.saveState(var1);
      this.flags = var2;
      var1.saveBoolean(this.setsAvatar);
      URL.save(var1, this.url);
      var1.saveString(this.description);
      URL.save(var1, this.viewURL);
      var1.saveString(this.viewName);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.setsAvatar = var1.restoreBoolean();
            this.url = URL.restore(var1);
            this.description = var1.restoreString();
            this.viewURL = URL.restore(var1);
            this.viewName = var1.restoreString();
            return;
         default:
            throw new TooNewException();
      }
   }
}
