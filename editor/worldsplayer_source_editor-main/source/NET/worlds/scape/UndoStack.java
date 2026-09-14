package NET.worlds.scape;

import NET.worlds.console.Console;

class UndoStack {
   private Undoable[] stack = new Undoable[100];
   private int stackPtr;

   Undoable peek() {
      return this.stackPtr - 1 >= 0 ? this.stack[this.stackPtr - 1] : this.stack[this.stack.length - 1];
   }

   void push(Undoable var1) {
      while (true) {
         try {
            this.stack[this.stackPtr++] = var1;
            return;
         } catch (IndexOutOfBoundsException var3) {
            this.stackPtr = 0;
         }
      }
   }

   boolean undo() {
      while (true) {
         try {
            Undoable var1 = this.stack[--this.stackPtr];
            if (var1 != null) {
               var1.undo();
               this.stack[this.stackPtr] = null;
               return true;
            }

            Console.println(Console.message("No-undo"));
            return false;
         } catch (IndexOutOfBoundsException var2) {
            this.stackPtr = this.stack.length;
         }
      }
   }
}
