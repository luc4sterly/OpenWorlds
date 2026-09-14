package NET.worlds.console;

public interface NameListOwner {
   int getNameListCount();

   String getNameListName(int var1);

   void removeNameListName(int var1);

   boolean mayAddNameListName(java.awt.Window var1);

   int addNameListName(String var1);
}
