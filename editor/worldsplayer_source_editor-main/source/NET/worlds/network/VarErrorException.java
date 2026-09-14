package NET.worlds.network;

import NET.worlds.console.Console;
import NET.worlds.core.Debug;
import NET.worlds.core.Std;
import java.text.MessageFormat;

public class VarErrorException extends Exception {
   String _msg;
   String _altMsg;
   int _varError;
   int _RetryTimeout;
   int _RetryCount;
   boolean _retry;
   boolean _isStatus;
   Object[] arguments = new Object[]{new String(Std.getProductName())};

   public boolean getRetryFlag() {
      return this._retry;
   }

   public boolean getStatusFlag() {
      return this._isStatus;
   }

   public int getRetryCount() {
      return this._RetryCount;
   }

   public int getTimeout() {
      return this._RetryTimeout;
   }

   public int getErrorNum() {
      return this._varError;
   }

   public String getMsg() {
      return this._msg;
   }

   public String getAltMsg() {
      return this._altMsg != null ? this._altMsg : this._msg;
   }

   VarErrorException(int var1) {
      this._varError = var1;
      this._msg = "";
      this._altMsg = null;
      this._retry = false;
      this._RetryCount = 1;
      this._RetryTimeout = 60;
      this._isStatus = false;
      Debug.dAssert(this._varError > 0);
      switch (this._varError) {
         case 1:
            this._msg = Console.message("NAK_BAD_USER");
            break;
         case 2:
            this._msg = Console.message("NAK_MAX_ORDINARY");
            break;
         case 3:
            this._msg = Console.message("NAK_MAX_PRIORITY");
            break;
         case 4:
            Debug.dAssert(false);
            break;
         case 5:
            this._msg = Console.message("NAK_FATAL");
            this._retry = true;
            this._RetryTimeout = 8 + (int)(Math.random() * 10.0);
            break;
         case 6:
            this._msg = Console.message("NAK_BAD_PROTOCOL1") + Console.message("NAK_BAD_PROTOCOL2");
            break;
         case 7:
            this._msg = Console.message("NAK_BAD_CLIENTSW");
            break;
         case 8:
            Debug.dAssert(false);
            break;
         case 9:
            this._msg = Console.message("NAK_BAD_SERIAL");
            break;
         case 10:
            this._msg = Console.message("NAK_TAKEN_SERIAL1") + Console.message("NAK_TAKEN_SERIAL2");
            break;
         case 11:
            this._msg = Console.message("NAK_TAKEN_USER");
            break;
         case 12:
            this._msg = Console.message("NAK_NO_SUCH_USER");
            break;
         case 13:
            this._msg = Console.message("NAK_BAD_PASSWORD");
            break;
         case 14:
            this._msg = Console.message("NAK_BAD_ACCOUNT");
            break;
         case 15:
            this._msg = Console.message("NAK_NOT_LOGGEDON");
            break;
         case 16:
            this._msg = Console.message("NAK_BAD_IPADDRESS");
            break;
         case 17:
            this._msg = Console.message("NAK_LOGGEDON");
            break;
         case 21:
            this._altMsg = "A room server is full.  People might \nnot be visible nearby.";
            this._msg = "The set of rooms you are in are quite full.\nPlease wait several minutes and try again.";
            this._retry = true;
            this._RetryTimeout = 15 + (int)(Math.random() * 15.0);
            break;
         case 100:
         case 101:
         case 102:
         case 103:
            this._msg = MessageFormat.format(Console.message("NAK_UNEXPECTED1"), this.arguments) + Console.message("NAK_UNEXPECTED2");
            this._altMsg = MessageFormat.format(Console.message("NAK_UNEXPECTED3"), this.arguments);
            this._retry = true;
            this._RetryTimeout = 5 + (int)(Math.random() * 15.0);
            break;
         case 104:
         case 105:
         case 106:
         case 107:
            this._msg = MessageFormat.format(Console.message("NAK_UNREACHABLE1"), this.arguments)
               + Console.message("NAK_UNREACHABLE2")
               + Console.message("NAK_UNREACHABLE3")
               + Console.message("NAK_UNREACHABLE4");
            this._altMsg = MessageFormat.format(Console.message("NAK_UNREACHABLE5"), this.arguments);
            this._retry = true;
            this._RetryTimeout = 30 + (int)(Math.random() * 15.0);
            break;
         case 200:
            this._msg = "Connected.";
            this._isStatus = true;
            break;
         case 201:
            this._msg = "Shutting down server.";
            this._isStatus = true;
            break;
         case 202:
            this._msg = "Automatically attempting to reconnect.";
            this._isStatus = true;
            break;
         case 203:
            this._msg = "Server has disconnected normally.";
            this._isStatus = true;
            break;
         case 204:
            this._msg = "Server has disconnected abnormally.";
            this._isStatus = true;
            break;
         case 205:
            this._msg = "Going into single user mode.";
            this._isStatus = true;
            break;
         default:
            this._msg = "Login error #" + this._varError;
      }
   }

   public String toString() {
      return "VarErrorException[#" + this._varError + " retry=" + this._retry + " retryCount=" + this._RetryCount + " isStatus=" + this._isStatus + "]";
   }
}
