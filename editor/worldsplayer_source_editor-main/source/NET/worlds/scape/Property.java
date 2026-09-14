package NET.worlds.scape;

import NET.worlds.console.Main;
import NET.worlds.core.Debug;

public class Property {
   protected Properties owner;
   public static final int BOOL_TYPE = 0;
   public static final int INT_TYPE = 1;
   public static final int FLOAT_TYPE = 2;
   public static final int STRING_TYPE = 3;
   public static final int COLOR_TYPE = 4;
   public static final int ENUM_TYPE = 5;
   public static final int FLOAT_ARRAY_TYPE = 6;
   public static final int POINT2_TYPE = 7;
   public static final int POINT3_TYPE = 8;
   public static final int TRANSFORM_TYPE = 9;
   public static final int URL_TYPE = 10;
   protected int index;
   protected String name;
   protected int propertyType = 3;
   protected PropEditor editor;
   public boolean helpExists = false;
   protected boolean canSetNull = false;

   public Property(Properties var1, int var2, String var3) {
      this.owner = var1;
      this.index = var2;
      this.name = var3;
   }

   public Property(Properties var1, int var2, String var3, boolean var4) {
      this.owner = var1;
      this.index = var2;
      this.name = var3;
      this.helpExists = var4;
   }

   Property setEditor(PropEditor var1) {
      this.editor = var1;
      return this;
   }

   public PropEditor getEditor() {
      return this.editor;
   }

   public Property allowSetNull() {
      this.canSetNull = true;
      return this;
   }

   public boolean canSetNull() {
      return this.canSetNull;
   }

   public String getName() {
      return this.name;
   }

   public int getIndex() {
      return this.index;
   }

   public Properties getOwner() {
      return this.owner;
   }

   public Object get() {
      return this.operate(1, null);
   }

   public Object set(Object var1) {
      return this.operate(2, var1);
   }

   public boolean equals(Object var1) {
      return var1 instanceof Property && ((Property)var1).owner == this.owner && ((Property)var1).index == this.index;
   }

   public int hashCode() {
      return this.owner.hashCode() ^ this.index;
   }

   protected Object operate(int var1, Object var2) {
      return Main.isMainThread() ? this.safeOperate(var1, var2) : new CallbackPropertyOperator(this, var1, var2).getValue();
   }

   Object safeOperate(int var1, Object var2) {
      try {
         Object var3 = this.owner.properties(this.index, 0, var1, var2);
         if (var1 > 1 && var1 < 5 && this.owner instanceof SuperRoot) {
            ((SuperRoot)this.owner).markEdited();
         }

         return var3;
      } catch (NoSuchPropertyException var4) {
         Debug.assert_(false);
         return null;
      }
   }

   public String toString() {
      return this.getName();
   }

   public void setPropertyType(int var1) {
      this.propertyType = var1;
   }

   public String getPropertyType() {
      String var1;
      switch (this.propertyType) {
         case 0:
            var1 = "Boolean";
            break;
         case 1:
            var1 = "Integer";
            break;
         case 2:
            var1 = "Float";
            break;
         case 3:
            var1 = "String";
            break;
         case 4:
            var1 = "Color";
            break;
         case 5:
            var1 = "Enumeration";
            break;
         case 6:
            var1 = "Float Array";
            break;
         case 7:
            var1 = "2D Point";
            break;
         case 8:
            var1 = "3D Point";
            break;
         case 9:
            var1 = "Transform";
            break;
         default:
            var1 = "URL";
      }

      return var1;
   }
}
