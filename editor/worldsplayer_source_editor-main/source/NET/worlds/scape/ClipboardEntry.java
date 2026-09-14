package NET.worlds.scape;

class ClipboardEntry {
   private SuperRoot original;
   private byte[] copy;
   private boolean canPasteOriginal;

   boolean copy(SuperRoot var1) {
      this.original = var1;
      this.copy = var1.getByteCopy();
      this.canPasteOriginal = false;
      return this.copy != null;
   }

   boolean cut(SuperRoot var1) {
      try {
         return this.copy(var1);
      } finally {
         this.canPasteOriginal = true;
      }
   }

   SuperRoot paste() {
      if (this.copy != null) {
         if (this.canPasteOriginal) {
            this.canPasteOriginal = false;
            return this.original;
         } else {
            return SuperRoot.getCopyFromBytes(this.copy);
         }
      } else {
         return null;
      }
   }

   void unPaste(SuperRoot var1) {
      if (var1 == this.original) {
         this.canPasteOriginal = true;
      }
   }
}
