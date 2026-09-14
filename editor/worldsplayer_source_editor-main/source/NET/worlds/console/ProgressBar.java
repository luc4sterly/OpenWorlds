package NET.worlds.console;

import NET.worlds.network.CacheEntry;
import java.awt.Button;
import java.awt.Canvas;
import java.awt.Color;
import java.awt.Event;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.GridLayout;
import java.awt.Image;
import java.awt.Label;
import java.awt.Panel;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ProgressBar extends Frame implements ActionListener {
   private int _total;
   private int _current = 0;
   private boolean _offline = false;
   private Canvas _barCanvas;
   private Label _header;
   private TextField _message;
   private Button _offlineButton;
   private static final int BAR_WIDTH = 250;
   private static final int BAR_HEIGHT = 20;
   private static final int BORDER = 10;

   public ProgressBar(String var1, int var2) {
      this._header = new Label(var1);
      this._total = var2;
      if (this._total < 1) {
         this._total = 1;
      }

      this.build();
      this.setTitle("Loading Progress");
   }

   public void advance() {
      this._current++;
      if (this._current > this._total) {
         this._current = this._total;
      }

      this.paintBar();
   }

   public int current() {
      return this._current;
   }

   public int total() {
      return this._total;
   }

   public int percentComplete() {
      return this._current * 100 / this._total;
   }

   public boolean offline() {
      return this._offline;
   }

   public void setMessage(String var1) {
      this._message.setText(var1);
      this.update(this.getGraphics());
   }

   protected int pixelsComplete() {
      return this._current * 250 / this._total;
   }

   protected void build() {
      this.setLayout(new GridLayout(3, 1, 10, 0));
      this._barCanvas = new Canvas();
      this._barCanvas.setSize(270, 40);
      this.add(this._barCanvas);
      this._message = new TextField("Working...");
      this._message.setEditable(false);
      this.add(this._message);
      Panel var1 = new Panel();
      this._offlineButton = new Button("Go Offline");
      this._offlineButton.addActionListener(this);
      var1.add(this._offlineButton);
      this.add(var1);
      this.pack();
   }

   public void paint(Graphics var1) {
      this.paintBar();
   }

   public void actionPerformed(ActionEvent var1) {
      if (var1.getSource() == this._offlineButton) {
         this._offline = true;
         CacheEntry.setOffline();
         this._offlineButton.setEnabled(false);
      }
   }

   public boolean handleEvent(Event var1) {
      if (var1.id == 201) {
         this.setVisible(false);
         this.dispose();
         Main.end();
         throw new Error("User cancelled startup.");
      } else {
         return super.handleEvent(var1);
      }
   }

   protected void paintBar() {
      Graphics var1 = this._barCanvas.getGraphics();
      Image var2 = this.createImage(270, 40);
      Graphics var3 = var2.getGraphics();
      var3.setColor(this.getBackground());
      var3.fillRect(0, 0, 270, 40);
      var3.setColor(Color.gray);
      var3.fillRect(10, 10, this.pixelsComplete(), 20);
      var3.setColor(Color.darkGray);
      var3.draw3DRect(11, 11, this.pixelsComplete() - 1, 18, true);
      var3.setColor(Color.black);
      var3.drawRect(10, 10, 250, 20);
      String var4 = Integer.toString(this.percentComplete()) + "% Complete";
      var1.setFont(new Font("Times Roman", 0, 12));
      FontMetrics var5 = var1.getFontMetrics();
      int var6 = var5.getHeight() / 2;
      int var7 = var5.stringWidth(var4) / 2;
      var3.drawString(var4, 135 - var7, 20 + var6);
      var1.drawImage(var2, 0, 0, null);
      var3.dispose();
      var2.flush();
   }
}
