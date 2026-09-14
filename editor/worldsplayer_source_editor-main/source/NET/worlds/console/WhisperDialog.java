package NET.worlds.console;

import NET.worlds.core.IniFile;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Event;

public class WhisperDialog extends PolledDialog {
   protected static java.awt.Window parent;
   protected boolean building;
   protected boolean isTrading;
   protected WhisperPart whisperPart;
   protected String partner;
   protected boolean isBroadcast;
   protected boolean built;
   protected static int counter = 0;
   protected static final int OFFSET = 20;
   protected static final int OFF_TOT = 6;

   static void setParent(java.awt.Window var0) {
      parent = var0;
   }

   static void sendTalkMessage(String var0) {
      Main.register(new WhisperDialog$1(var0));
   }

   protected WhisperDialog(java.awt.Window var1, String var2) {
      super(var1, null, Console.message("Whisper-to-from2") + Console.parseExtended(var2), false);
      this.partner = var2;
      this.isBroadcast = true;
      if (var2.equals("room")) {
         this.setTitle(Console.message("Broadcast-Users"));
      } else if (var2.equals("world")) {
         this.setTitle(Console.message("Broadcast-All"));
      } else {
         this.isBroadcast = false;
      }

      this.whisperPart = new WhisperPart(var2);
      Console var3 = Console.getActive();
      if (var3 != null) {
         var3.addPart(this.whisperPart);
      }

      int var4 = counter / 6;
      int var5 = counter % 6;
      this.setAlignment(1, ((var5 + var4) % 12 - 5) * 20, (var5 % 6 - 5) * 20);
      counter++;
   }

   protected void takeFocus() {
      this.whisperPart.forceTakeFocus();
   }

   public void show() {
      super.show();
      this.whisperPart.scrollToBottom();
      int var1 = IniFile.override().getIniInt("whispersToFront", 0);
      if (var1 != 0) {
         this.toFront();
      }
   }

   protected void send(String var1) {
      this.whisperPart.println("< " + var1);
   }

   protected synchronized void print(String var1) {
      this.whisperPart.println("> " + var1);
   }

   protected synchronized void build() {
      this.building = false;
      if (this.built) {
         this.removeAll();
      }

      this.built = true;
      new Color(0, 0, 0);
      Color var2 = new Color(0, 192, 192);
      new Color(0, 160, 160);
      new Color(255, 255, 255);
      Color var8 = var2;
      this.setBackground(Color.white);
      this.setForeground(Color.black);
      Object var9 = null;
      this.whisperPart.line.setBackground(this.isTrading ? var8 : Color.white);
      this.whisperPart.listen.setBackground(Color.lightGray);
      InsetPanel var10 = new InsetPanel(new BorderLayout(), 3, 1, 1, 1);
      var10.setBackground(Color.lightGray);
      var10.add("Center", this.whisperPart.listen.getComponent());
      this.add("Center", var10);
      InsetPanel var11 = new InsetPanel(new BorderLayout(), 2, 1, 2, 1);
      var11.setBackground(Color.lightGray);
      var11.add("Center", this.whisperPart.line);
      this.add("South", var11);
      this.validate();
   }

   protected boolean setValue() {
      return true;
   }

   public synchronized boolean keyDown(Event var1, int var2) {
      this.whisperPart.line.requestFocus();
      if (var2 == 10) {
         this.whisperPart.trigger();
         return true;
      } else {
         return false;
      }
   }

   public Dimension preferredSize() {
      return super.preferredSize();
   }

   public Dimension minimumSize() {
      return super.minimumSize();
   }
}
