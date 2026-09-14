package NET.worlds.console;

import java.io.IOException;

public class IWebBrowserApp extends IUnknown {
   public static final String CLSID_InternetExplorer = "{0002DF01-0000-0000-C000-000000000046}";
   public static final String IID_IWebBrowserApp = "{0002DF05-0000-0000-C000-000000000046}";

   public IWebBrowserApp() throws IOException {
      super("{0002DF01-0000-0000-C000-000000000046}", "{0002DF05-0000-0000-C000-000000000046}");
   }

   public IWebBrowserApp(IUnknown var1) throws IOException, OLEInvalidObjectException {
      super(var1, "{0002DF05-0000-0000-C000-000000000046}");
   }

   public native void put_Visible(boolean var1);

   public native void put_StatusBar(boolean var1);

   public native void put_MenuBar(boolean var1);

   public native void Navigate(String var1);

   public native void Quit();
}
