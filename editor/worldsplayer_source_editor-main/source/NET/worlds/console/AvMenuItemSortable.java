package NET.worlds.console;

class AvMenuItemSortable implements Comparable {
   public AvMenuItem menuItem;

   AvMenuItemSortable(AvMenuItem var1) {
      this.menuItem = var1;
   }

   public int compareTo(Object var1) {
      AvMenuItemSortable var2 = (AvMenuItemSortable)var1;
      return this.menuItem.prettyAvatar.compareTo(var2.menuItem.prettyAvatar);
   }
}
