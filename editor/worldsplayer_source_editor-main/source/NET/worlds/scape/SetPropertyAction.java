package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.Gamma;
import NET.worlds.core.Debug;
import java.io.IOException;
import java.text.MessageFormat;
import java.util.Enumeration;

public abstract class SetPropertyAction extends Action {
   SuperRoot _target;
   String _targetName;
   String _roomName;
   String _propName;
   private int _propIndex = -1;
   private String _paramName = null;
   private static Object classCookie = new Object();

   public SuperRoot getTarget() {
      if (this._target == null && this._targetName != null) {
         Room var1 = null;
         if (this._roomName != null) {
            World var2 = this.getWorld();
            if (var2 != null) {
               var1 = var2.getRoom(this._roomName);
            }
         } else {
            var1 = this.getRoom();
         }

         if (var1 != null) {
            Enumeration var3 = var1.getDeepOwned();
            this._target = SuperRoot.nameSearch(var3, this._targetName);
         }
      }

      return this._target != null ? this._target : this.getOwner();
   }

   protected boolean useParam() {
      return this._paramName != null;
   }

   protected String paramName() {
      return this._paramName;
   }

   protected String param() {
      return this._paramName == null ? null : Gamma.getParam(this._paramName);
   }

   static int index(int var0, String var1, Object var2) {
      if (var0 == -1 && var1 != null) {
         EnumProperties var3 = new EnumProperties(var2);

         while (var3.hasMoreElements()) {
            Property var4 = (Property)var3.nextElement();
            if (var4.getName().equals(var1)) {
               var0 = var4.getIndex();
               break;
            }
         }
      }

      return var0;
   }

   public static Object propHelper(int var0, Object var1, String var2, SuperRoot var3) {
      Object var4 = null;
      int var5 = index(-1, var2, var3);
      if (var5 != -1) {
         try {
            var4 = var3.properties(var5, 0, var0, var1);
         } catch (NoSuchPropertyException var7) {
         }
      }

      return var4;
   }

   private Object propHelper(int var1, Object var2) {
      SuperRoot var3 = this.getTarget();
      Object var4 = null;
      if ((this._propIndex = index(this._propIndex, this._propName, var3)) != -1) {
         try {
            var4 = var3.properties(this._propIndex, 0, var1, var2);
         } catch (NoSuchPropertyException var6) {
            Debug.assert_(false);
         }
      } else if (var3 == null) {
         Console.println(this.getName() + Console.message("null-target"));
      } else if (this._propName == null) {
         Object[] var5 = new Object[]{new String(this.getName()), new String(this.getTarget().getName())};
         Console.println(MessageFormat.format(Console.message("null-property"), var5));
      } else {
         Object[] var7 = new Object[]{new String(this.getName()), new String(this._propName), new String(this.getTarget().getName())};
         Console.println(MessageFormat.format(Console.message("non-property"), var7));
      }

      return var4;
   }

   protected final void set(Object var1) {
      this.propHelper(2, var1);
   }

   protected final Object get() {
      return this.propHelper(1, null);
   }

   protected final void add(Object var1) {
      this.propHelper(3, var1);
   }

   protected final void remove(Object var1) {
      this.propHelper(4, var1);
   }

   protected final Property enum_() {
      return (Property)this.propHelper(0, null);
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               Property var8 = new Property(this, var1, "Target");
               var8.allowSetNull();
               var5 = ObjPropertyEditor.make(var8, this.getRoom(), "NET.worlds.scape.SuperRoot");
            } else if (var3 == 1) {
               var5 = this.getTarget();
            } else if (var3 == 2) {
               this._target = (SuperRoot)var4;
               this._propIndex = -1;
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Target Room"));
            } else if (var3 == 1) {
               var5 = this._roomName;
            } else if (var3 == 4) {
               this._roomName = null;
            } else if (var3 == 2) {
               this._roomName = (String)var4;
               this._target = null;
            }
            break;
         case 2:
            if (var3 == 0) {
               Property var7 = new Property(this, var1, "Target Name");
               var7.allowSetNull();
               var5 = StringPropertyEditor.make(var7);
            } else if (var3 == 1) {
               var5 = this._targetName;
            } else if (var3 == 4) {
               this._targetName = null;
            } else if (var3 == 2) {
               this._targetName = (String)var4;
               this._target = null;
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Property Name");
               if (this.getTarget() != null) {
                  var5 = PropPropEditor.make((Property)var5, this.getTarget(), true);
               }
            } else if (var3 == 1) {
               SuperRoot var6 = this.getTarget();
               if ((this._propIndex = index(this._propIndex, this._propName, var6)) != -1 && var6 != null) {
                  var5 = this.enum_();
               } else {
                  var5 = null;
               }
            } else if (var3 == 2) {
               if (var4 == null) {
                  this._propIndex = -1;
                  this._propName = null;
               } else if (var4 instanceof String) {
                  this._propIndex = -1;
                  this._propName = (String)var4;
               } else {
                  this._propIndex = ((Property)var4).getIndex();
                  this._propName = ((Property)var4).getName();
               }
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Use parameter"), "Use 'Set To' value", "Use parameter");
            } else if (var3 == 1) {
               var5 = new Boolean(this._paramName != null);
            } else if (var3 == 2) {
               if ((Boolean)var4) {
                  if (this._paramName == null) {
                     this._paramName = "";
                  }
               } else {
                  this._paramName = null;
               }
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Parameter Name");
               if (this._paramName != null) {
                  var5 = StringPropertyEditor.make((Property)var5);
               }
            } else if (var3 == 1) {
               var5 = this._paramName == null ? "" : this._paramName;
            } else if (var3 == 2) {
               this._paramName = (String)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 6, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(4, classCookie);
      super.saveState(var1);
      var1.saveMaybeNull(this.getTarget());
      var1.saveString(this._roomName);
      var1.saveString(this._targetName);
      var1.saveString(this._propName);
      var1.saveString(this._paramName);
   }

   protected void setPropertyActionRestoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            super.restoreState(var1);
            this._target = (SuperRoot)var1.restore();
            this._propName = var1.restoreString();
            break;
         case 2:
            super.restoreState(var1);
            this._target = (SuperRoot)var1.restoreMaybeNull();
            this._propName = var1.restoreString();
            break;
         case 3:
            super.restoreState(var1);
            this._target = (SuperRoot)var1.restoreMaybeNull();
            this._propName = var1.restoreString();
            this._paramName = var1.restoreString();
            break;
         case 4:
            super.restoreState(var1);
            this._target = (SuperRoot)var1.restoreMaybeNull();
            this._roomName = var1.restoreString();
            this._targetName = var1.restoreString();
            this._propName = var1.restoreString();
            this._paramName = var1.restoreString();
            break;
         default:
            throw new TooNewException();
      }
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      this.setPropertyActionRestoreState(var1);
   }
}
