package NET.worlds.console;

class StatisticsRoot extends StatMan {
   private static StatisticsRoot _singleInstance = new StatisticsRoot();

   public static StatisticsRoot getNode() {
      return _singleInstance;
   }

   private StatisticsRoot() {
   }

   void updateList() {
   }

   public String toString() {
      return "Statistics Root";
   }
}
