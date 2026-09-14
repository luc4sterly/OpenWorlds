package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.Gamma;
import NET.worlds.console.RenderCanvas;
import NET.worlds.console.Window;
import NET.worlds.core.Debug;
import NET.worlds.network.URL;
import java.io.IOException;

public class Camera extends WObject implements MouseButtonHandler, MouseEnterHandler, MouseExitHandler, MouseMoveHandler, IncrementalRestorer, URLSelf {
   private RenderCanvas canvas;
   static final int CAMERA_SIZE = 20;
   private boolean mouseIsOverClickable = false;
   private boolean validMouseCoordinates = false;
   private float validMouseX = -1.0F;
   private float validMouseY = -1.0F;
   private static WObject cachedWObject = null;
   private static float cachedMouseX = -1.0F;
   private static float cachedMouseY = -1.0F;
   private int cameraID;
   private int cameraMode;
   private boolean alwaysClearBackground;
   private float xPick;
   private float yPick;
   private Point3Temp unpickSpot;
   private WObject pickedObj;
   public Transform lookAround = Transform.make();
   private static final int isBotMode = 0;
   private static final int isPickingMode = 1;
   private static final int isDrawingMode = 2;
   private static final int isThroughMode = 4;
   static WObject[] downWentTo = new WObject[3];
   static Point3 downAt = new Point3();
   private static Object classCookie = new Object();
   public float xForRoomPreAndPostRender;
   public float yForRoomPreAndPostRender;
   public float zForRoomPreAndPostRender;
   public float dForRoomPreAndPostRender;

   public Camera() {
      this.setVisible(false);
   }

   public static native void cameraNativeInit();

   public Window getWindow() {
      return this.canvas == null ? null : this.canvas.getWindow();
   }

   public BoundBoxTemp getBoundBox() {
      Transform var1 = this.getObjectToWorldMatrix();
      Point3Temp var2 = var1.getPosition();
      var1.recycle();
      Point3Temp var3 = Point3Temp.make(var2).minus(20.0F);
      return BoundBoxTemp.make(var3, var2.plus(20.0F));
   }

   public static WObject getMousePickWObject() {
      return cachedWObject;
   }

   public static float getMousePickX() {
      return cachedMouseX;
   }

   public static float getMousePickY() {
      return cachedMouseY;
   }

   protected WObject updateView(Window var1, int var2) {
      Room var3 = this.getRoom();
      if (!this.hasClump() && var3 != null) {
         var3.aboutToDraw();
      }

      Transform var4 = null;
      SuperRoot var5 = this.getOwner();
      Pilot var6 = null;
      if (var5 instanceof Pilot && var5.getOwner() == var3) {
         var6 = (Pilot)var5;
         if (var3 != null) {
            var6.aboutToDraw();
            this.detach();
            var3.add(this);
            var4 = this.getTransform();
            Point3Temp var7 = var4.getPosition().times(var6).minus(var6.getPosition());
            this.post(var6);
            if (var7.squaredLength() > 1.0F) {
               this.moveBy(Point3Temp.make().minus(var7));
               boolean var8 = var6.getBumpable();
               var6.setBumpable(false);
               this.moveThrough(var7);
               var6.setBumpable(var8);
               Room var9 = this.getRoom();
               if (!this.hasClump() && var9 != null && var9 != var3) {
                  var9.aboutToDraw();
               }
            }
         }
      }

      WObject var10 = this.renderScene(var1.getHwnd(), var1.fullWidth(), var1.fullHeight(), var2, var6);
      if (var4 != null) {
         this.detach();
         var6.add(this);
         this.setTransform(var4);
         var4.recycle();
      }

      return var10;
   }

   public void renderToCanvas() {
      Debug.assert_(this.cameraID == 0);
      if (this.isActive()) {
         Window var1 = this.getWindow();
         if (var1 != null) {
            if (this.validMouseCoordinates) {
               this.xPick = this.validMouseX;
               this.yPick = this.validMouseY;
               WObject var2 = this.updateView(var1, 7);
               boolean var3 = false;
               cachedWObject = var2;
               cachedMouseX = this.validMouseX;
               cachedMouseY = this.validMouseY;
               if (var2 != null && var2.acceptsLeftClicks()) {
                  if (!this.mouseIsOverClickable) {
                     this.mouseIsOverClickable = true;
                     var3 = true;
                  }
               } else if (this.mouseIsOverClickable) {
                  this.mouseIsOverClickable = false;
                  var3 = true;
               }

               if (var3) {
                  URL var4 = null;
                  if (this.mouseIsOverClickable) {
                     var4 = URL.make("home:HAND-M.CUR");
                  } else {
                     var4 = URL.make("system:DEFAULT_CURSOR");
                  }

                  Console.getActive().getCursor().setURL(var4);
               }
            } else {
               this.updateView(var1, 6);
            }
         }
      }
   }

   public native void nDrawText(String var1, int var2, int var3, int var4, int var5);

   public RenderCanvas getCanvas() {
      return this.canvas;
   }

   public void setCanvas(RenderCanvas var1) {
      this.canvas = var1;
   }

   public void setAlwaysClearBackground(boolean var1) {
      this.alwaysClearBackground = var1;
   }

   public Point3Temp lastPickSpot() {
      return this.unpickSpot;
   }

   public void transferFrom(Camera var1) {
      this.lookAround.setTransform(var1.lookAround);
   }

   synchronized native WObject renderScene(int var1, int var2, int var3, int var4, Pilot var5);

   public WObject getObjectAt(float var1, float var2, boolean var3, Point3Temp var4) {
      Window var5 = this.getWindow();
      if (var5 == null) {
         return null;
      }

      this.xPick = var1;
      this.yPick = var2;
      this.unpickSpot = null;
      WObject var6 = this.updateView(var5, 1 + (var3 ? 4 : 0));
      if (var4 != null && this.unpickSpot != null) {
         var4.copy(this.unpickSpot);
      }

      return var6;
   }

   private void sendClick(WObject var1, MouseButtonEvent var2) {
      WObject var3 = var2.target;
      var2.target = var1;
      var1.deliver(var2);
      var2.target = var3;
   }

   public boolean handle(MouseButtonEvent var1) {
      WObject var2 = null;
      byte var3 = 3;
      if (var1.key == '\ue301') {
         var3 = 0;
      } else if (var1.key == '\ue302') {
         var3 = 1;
      } else if (var1.key == '\ue304') {
         var3 = 2;
      }

      Debug.dAssert(var3 != 3);
      if (var1 instanceof MouseUpEvent) {
         var2 = downWentTo[var3];
         downWentTo[var3] = null;
      } else {
         Window var4 = this.getWindow();
         if (var4 != null && !var4.getDeltaMode()) {
            if (var3 == 1 && Gamma.getShaper() != null) {
               var2 = this.getObjectAt(var1.x, var1.y, false, null);
               if (var2 != null) {
                  var2.rightMenu();
               }
            } else {
               var2 = this.getObjectAt(var1.x, var1.y, true, downAt);
            }

            downWentTo[var3] = var2;
         }
      }

      if (var2 != null) {
         if (var3 == 0 && var1 instanceof MouseUpEvent) {
            var2.doAction(Console.getActive().getDefaultAction(), var1);
         }

         this.sendClick(var2, var1);
      }

      return false;
   }

   public boolean handle(MouseEnterEvent var1) {
      if (var1 != null) {
         URL var2 = URL.make("system:DEFAULT_CURSOR");
         Console.getActive().getCursor().setURL(var2);
         this.mouseIsOverClickable = false;
         this.validMouseCoordinates = true;
         this.validMouseX = var1.x;
         this.validMouseY = var1.y;
         cachedWObject = null;
         cachedMouseX = -1.0F;
         cachedMouseY = -1.0F;
      }

      return false;
   }

   public boolean handle(MouseExitEvent var1) {
      if (var1 != null) {
         URL var2 = URL.make("system:DEFAULT_CURSOR");
         Console.getActive().getCursor().setURL(var2);
         this.mouseIsOverClickable = false;
         this.validMouseCoordinates = false;
         this.validMouseX = -1.0F;
         this.validMouseY = -1.0F;
         cachedWObject = null;
         cachedMouseX = -1.0F;
         cachedMouseY = -1.0F;
      }

      return false;
   }

   public boolean handle(MouseMoveEvent var1) {
      if (var1 != null) {
         this.validMouseX = var1.x;
         this.validMouseY = var1.y;
      }

      return false;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         default:
            return super.properties(var1, var2 + 0, var3, var4);
      }
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(2, classCookie);
      super.saveState(var1);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
         case 2:
            super.restoreState(var1);
            break;
         case 1:
            super.restoreState(var1);
            var1.restoreFloat();
            var1.restore();
            var1.restore();
            break;
         default:
            throw new TooNewException();
      }
   }

   public int incRestore(int var1, Restorer var2, URLSelfLoader var3) throws Exception {
      if (var1 == 0) {
         this.restoreState(var2);
      }

      if (var2.version() != 3) {
         return -1;
      }

      if (var1 == 0) {
         var3.otemp1 = var2.restore(false);
      }

      World var4 = (World)var3.otemp1;
      if (var1 == 0) {
         var4.setSourceURL(this.getSourceURL());
      }

      return var4.incRestore(var1, var2, var3);
   }

   public void incRef() {
      Debug.assert_(false);
   }

   public void decRef() {
      Debug.assert_(false);
   }

   static {
      cameraNativeInit();
   }
}
