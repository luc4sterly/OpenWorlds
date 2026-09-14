package NET.worlds.scape;

class PitchWidget extends WidgetButton {
   public PitchWidget(ToolBar var1) {
      super(var1, "pitch.gif", "Pitch");
   }

   public String drag(boolean var1, float var2, float var3) {
      if (Math.abs(var2) > Math.abs(var3)) {
         var3 = 0.0F;
      }

      Transform var4 = Transform.make();
      this.applyWorldTransform(var1, var4.spin(this.getWorldAxis(1, 0, 0), -var3));
      var4.recycle();
      return "Pitch";
   }
}
