package NET.worlds.console;

import NET.worlds.core.IniFile;
import NET.worlds.scape.FrameEvent;
import java.awt.Color;
import java.awt.Container;
import java.awt.Event;
import java.awt.TextField;
import java.util.Observer;
import java.util.Vector;

public abstract class DuplexPart implements FramePart {
   private boolean classicTextArea;
   public TextField line = new FocusPreservingTextField();
   public SharedTextArea listen;
   private Vector talkVec = new Vector();

   public DuplexPart() {
      this(true);
   }

   public DuplexPart(boolean var1) {
      this(var1, 3);
   }

   public DuplexPart(boolean var1, int var2) {
      this.classicTextArea = IniFile.gamma().getIniInt("classicChatBox", 1) == 1;
      if (this.classicTextArea) {
         this.listen = new ClassicSharedTextArea(var2, 30, var1);
         this.listen.setBackground(Color.white);
      } else {
         this.listen = new NewSharedTextArea(var2, 30, var1);
         this.listen.setBackground(GammaTextArea.getBackgroundColor());
      }

      this.listen.setForeground(Color.black);
   }

   public void forceTakeFocus() {
      ((FocusPreservingTextField)this.line).takeNextFocus();
   }

   public void activate(Console var1, Container var2, Console var3) {
      if (this instanceof ChatPart) {
         ((FocusPreservingTextField)this.line).isChatLine();
      }

      if (!this.classicTextArea) {
         Color var4 = GammaTextArea.getBackgroundColor();
         this.line.setBackground(var4);
         this.listen.setBackground(var4);
         this.line.setForeground(Color.black);
         this.listen.setForeground(Color.black);
         this.line.repaint();
         this.listen.repaint();
      } else {
         this.listen.setBackground(Color.white);
         this.listen.setForeground(Color.black);
      }
   }

   public void deactivate() {
   }

   public void println(String var1) {
      this.listen.println(var1);
   }

   public synchronized void trigger() {
      this.talkVec.addElement(this.line.getText());
      this.line.setText("");
   }

   public synchronized void say(String var1) {
      this.talkVec.addElement(var1);
   }

   public void scrollToBottom() {
      this.listen.scrollToBottom();
   }

   public boolean action(Event var1, Object var2) {
      if (var1.target == this.line) {
         this.trigger();
         return true;
      } else {
         return false;
      }
   }

   public void enableLogging(String var1, String var2, boolean var3) {
      this.listen.enableLogging(var1, var2, var3);
   }

   public void disableLogging() {
      this.listen.disableLogging();
   }

   public static void addLogObserver(Observer var0) {
      NewSharedTextArea.addLogObserver(var0);
      ClassicSharedTextArea.addLogObserver(var0);
   }

   public static void deleteLogObserver(Observer var0) {
      NewSharedTextArea.deleteLogObserver(var0);
      ClassicSharedTextArea.addLogObserver(var0);
   }

   public synchronized boolean handle(FrameEvent var1) {
      this.listen.poll();

      while (this.talkVec.size() > 0) {
         this.sendText((String)this.talkVec.firstElement());
         this.talkVec.removeElementAt(0);
      }

      return true;
   }

   protected abstract void sendText(String var1);
}
