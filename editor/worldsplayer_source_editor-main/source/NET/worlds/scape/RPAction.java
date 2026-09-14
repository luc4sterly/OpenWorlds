package NET.worlds.scape;

public class RPAction extends Action {
   public Persister trigger(Event var1, Persister var2) {
      if (this.getOwner() instanceof Portal) {
         ((Portal)this.getOwner()).triggerLoad();
      }

      return null;
   }
}
