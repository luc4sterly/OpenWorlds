package NET.worlds.console;

class StatNetNode extends StatMan {
   private static StatNetNode _singleInstance = new StatNetNode();

   public static StatNetNode getNode() {
      return _singleInstance;
   }

   private StatNetNode() {
      StatisticsRoot.getNode().addChild(this);
   }

   public String toString() {
      return "Network";
   }

   void updateList() {
      this._grabbedList.addItem("Overall Networking Statistics");
   }
}
