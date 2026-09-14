package NET.worlds.scape;

public interface Properties {
   int ENUM = 0;
   int GET = 1;
   int SET = 2;
   int ADD = 3;
   int DEL = 4;
   int ADD_TEST = 5;

   Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException;

   Object propertyParent();
}
