package NET.worlds.scape;

import java.io.IOException;

public interface Persister {
   void saveState(Saver var1) throws IOException;

   void restoreState(Restorer var1) throws IOException, TooNewException;

   void postRestore(int var1);
}
