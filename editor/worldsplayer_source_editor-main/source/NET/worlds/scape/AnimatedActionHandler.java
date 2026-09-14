package NET.worlds.scape;

public interface AnimatedActionHandler {
   void addCallback(AnimatedActionCallback var1);

   void removeCallback(AnimatedActionCallback var1);

   void notifyCallbacks(int var1);
}
