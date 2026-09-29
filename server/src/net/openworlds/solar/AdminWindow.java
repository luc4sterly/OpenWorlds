package net.openworlds.solar;

/** The admin window (placeholder until the window is written): runs the console. */
final class AdminWindow {
   private AdminWindow() {
   }

   static void open(SolarServer server) throws Exception {
      Main.runHeadless(server);
   }
}
