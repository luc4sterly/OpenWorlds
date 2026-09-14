package NET.worlds.console;

import java.util.Observable;

class PublicObservable extends Observable {
   public void setChanged(boolean var1) {
      if (var1) {
         this.setChanged();
      } else {
         this.clearChanged();
      }
   }
}
