package NET.worlds.console;

import NET.worlds.core.IniFile;
import java.awt.GridBagConstraints;
import java.awt.Label;
import java.awt.TextField;
import java.util.Properties;

class ProxyServerDialog extends OkCancelDialog {
   private String proxyIP;
   private Label ipLabel = new Label("Proxy IP");
   private TextField ipText = new TextField("", 15);
   private Label portLabel = new Label("Proxy Port");
   private TextField portText = new TextField("", 3);

   public ProxyServerDialog() {
      super(Console.getFrame(), null, Console.message("Proxy-Server"), "Cancel", "Ok", "", false);
      this.ipText.setText(IniFile.gamma().getIniString("Proxy Server IP", ""));
      this.portText.setText(IniFile.gamma().getIniString("Proxy Server Port", ""));
   }

   protected synchronized boolean done(boolean var1) {
      if (var1) {
         Properties var2 = System.getProperties();
         IniFile.gamma().setIniString("Proxy Server IP", this.ipText.getText());
         IniFile.gamma().setIniString("Proxy Server Port", this.portText.getText());
         var2.remove("socksProxyHost");
         var2.remove("socksProxyPort");
         var2.put("socksProxyHost", this.ipText.getText());
         var2.put("socksProxyPort", this.portText.getText());
         System.setProperties(var2);
      }

      return super.done(var1);
   }

   public void build() {
      GridBagConstraints var1 = new GridBagConstraints();
      var1.gridx = 1;
      var1.gridy = 1;
      var1.weightx = 1.0;
      var1.weighty = 1.0;
      this.add(this.gbag, this.ipLabel, var1);
      var1.gridy = 2;
      this.add(this.gbag, this.portLabel, var1);
      var1.gridx = 2;
      var1.gridy = 1;
      var1.weightx = 3.0;
      this.add(this.gbag, this.ipText, var1);
      var1.gridy = 2;
      this.add(this.gbag, this.portText, var1);
      this.okButton.setFont(bfont);
      this.cancelButton.setFont(bfont);
      var1.gridx = 1;
      var1.gridy = 3;
      var1.weightx = 1.0;
      this.add(this.gbag, this.okButton, var1);
      var1.gridx = 4;
      this.add(this.gbag, this.cancelButton, var1);
   }
}
