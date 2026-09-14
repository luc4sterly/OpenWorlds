package NET.worlds.console;

import NET.worlds.scape.EventQueue;
import NET.worlds.scape.Pilot;
import java.awt.Event;
import java.awt.Font;
import java.awt.TextField;

class FocusPreservingTextField extends TextField {
   private static FocusPreservingTextField lostFocus;
   private static FocusPreservingTextField hasFocus;
   private static FocusPreservingTextField chatLine;
   private static Object hasFocusMutex = new Object();
   private static Font font = new Font(Console.message("GammaTextFont"), 0, 12);
   boolean preserveFocus;
   boolean takeNextFocus;

   public FocusPreservingTextField() {
      super(30);
      this.setFont(font);
   }

   public void isChatLine() {
      chatLine = this;
   }

   public void requestFocus() {
      if (!this.takeNextFocus) {
         synchronized (hasFocusMutex) {
            this.preserveFocus = hasFocus != null && hasFocus.getText().length() != 0 || chatLine != null && chatLine.getText().length() != 0;
         }
      } else {
         this.takeNextFocus = false;
      }

      if (!this.preserveFocus) {
         super.requestFocus();
      }
   }

   public void takeNextFocus() {
      this.preserveFocus = false;
      this.takeNextFocus = true;
   }

   public boolean handleEvent(Event var1) {
      synchronized (hasFocusMutex) {
         if (var1.id == 1005) {
            if (hasFocus == this) {
               lostFocus = this;
               hasFocus = null;
               this.preserveFocus = false;
            }
         } else if (var1.id == 1004) {
            hasFocus = this;
            if (this.preserveFocus && lostFocus != null) {
               lostFocus.takeNextFocus();
               lostFocus.requestFocus();
            }

            lostFocus = null;
            this.preserveFocus = false;
         }
      }

      if (var1.id == 401) {
         Console.wake();
         if (var1.key == 27) {
            this.setText("");
            return true;
         }

         if ((var1.modifiers & 2) != 0 && var1.key >= 1 && var1.key <= 26 && var1.key != 22) {
            Pilot var5 = Pilot.getActive();
            if (var5 != null) {
               var5.animate("abcdefghijklmnopqrstuvwxyz".substring(var1.key - 1, var1.key));
            }

            return true;
         }
      }

      return EventQueue.redirectDrivingKeys(var1) ? true : super.handleEvent(var1);
   }
}
