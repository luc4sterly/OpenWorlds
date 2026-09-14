package NET.worlds.scape;

public abstract class TriggeredSwitchableBehavior extends SwitchableBehavior {
   public String trigger;
   public String externalTriggerTag;
   public int sequence_no;
   public int event_no;
   Trigger trigger_source = null;

   public abstract void ExternalTrigger(Trigger var1, int var2, int var3);
}
