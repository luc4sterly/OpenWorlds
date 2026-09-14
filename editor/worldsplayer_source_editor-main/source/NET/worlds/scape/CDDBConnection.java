package NET.worlds.scape;

import NET.worlds.network.DNSLookup;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;

class CDDBConnection {
   private Socket sock;
   private PrintStream sockOut;
   private DataInputStream sockIn;
   private boolean readOnly;
   private boolean debug;

   public CDDBConnection(CDDBHost var1, boolean var2) throws IOException {
      this.debug = var2;
      if (var2) {
         System.out.println("Contacting host " + var1);
      }

      this.sock = new Socket(DNSLookup.lookup(var1.getHost()), var1.getPort());
      CDDBLookup.markActivity();
      this.sockOut = new PrintStream(this.sock.getOutputStream(), true);
      this.sockIn = new DataInputStream(this.sock.getInputStream());
      String var3 = this.recv();
      if (var3.startsWith("200 ")) {
         this.readOnly = false;
      } else {
         if (!var3.startsWith("201 ")) {
            throw new IOException("Can't connect to " + var1 + ": " + var3);
         }

         this.readOnly = true;
      }
   }

   public String command(String var1) throws IOException {
      this.send(var1);
      return this.recv();
   }

   public String readBody() throws IOException {
      String var1 = this.recv();
      return var1.equals(".") ? null : var1;
   }

   public void close() {
      try {
         this.send("quit");
         this.recv();
         this.sock.close();
      } catch (IOException var2) {
      }
   }

   private void send(String var1) throws IOException {
      if (this.debug) {
         System.out.println("--> " + var1);
      }

      this.sockOut.println(var1);
      CDDBLookup.markActivity();
   }

   private String recv() throws IOException {
      String var1 = this.sockIn.readLine();
      CDDBLookup.markActivity();
      if (this.debug) {
         System.out.println("<-- " + var1);
      }

      return var1;
   }
}
