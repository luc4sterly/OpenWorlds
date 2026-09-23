package net.freeworlds.world;

/**
 * PortalLink con casos calculados a mano: getYaw (gamma.dll 0x00425440),
 * recomputeFarPosition, _p2pxform (0x0041b170), el lado de cruce de
 * BumpEventTemp.isCollision y el rumbo de llegada. Sale con 1 si falla.
 */
public final class PortalLinkCheck {
   private static int failures = 0;

   public static void main(String[] args) {
      // getYaw: rumbo del +Y local, 0 = Norte (+Y), horario.
      // Identidad: v = (0,1,0), r = 1, f = 0 -> 180*(pi/2 - 0)/pi = 90 -> 90-90 = 0.
      near("yaw identidad", PortalLink.getYaw(rotZ(0, 1, 1, 1), 1, 1, 1), 0f);
      // Giro +90 (CCW): +Y -> (-1,0): vx = -r -> 180; vy = 0 no niega;
      // 90-180 = -90 -> +360 = 270 (Oeste).
      near("yaw +90", PortalLink.getYaw(rotZ(90, 1, 1, 1), 1, 1, 1), 270f);
      // Giro -90: +Y -> (1,0): vx >= r -> 0 -> 90 (Este).
      near("yaw -90", PortalLink.getYaw(rotZ(-90, 1, 1, 1), 1, 1, 1), 90f);
      // Giro +45: +Y -> (-0.707, 0.707): f = -0.707, asin = -45 grados ->
      // 180*(90+45)/180 = 135 -> 90-135 = -45 -> 315 (Noroeste).
      near("yaw +45", PortalLink.getYaw(rotZ(45, 1, 1, 1), 1, 1, 1), 315f);
      // La escala propia se deshace antes (RwScaleMatrix pre por 1/escala).
      near("yaw +45 con escala (500,1.2,290)", PortalLink.getYaw(rotZ(45, 500, 1.2f, 290), 500, 1.2f, 290), 315f);
      // +Y vertical: r = 0 -> vx < r es falso -> 0 -> 90.
      float[] up = {1, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 0, 0, 1};
      near("yaw +Y vertical", PortalLink.getYaw(up, 1, 1, 1), 90f);

      // A: portal en el origen sin giro, 100 de ancho (xScale 100), 200 de
      // alto. B: girado +90 en (1000,0,0), mismo tamano.
      WNode b = new WNode("NET.worlds.scape.Portal");
      b.matrix = rotZ(90, 100, 1, 200);
      b.matrix[12] = 1000f;
      b.xScale = 100f;
      b.zScale = 200f;
      // recomputeFarPosition: (1,0,1).M = fila0 + fila2 = (0,100,0)+(0,0,200)
      // -> x/y + (0,100) -> (1000,100,0); fartheta = (-270+180) % 360 = -90.
      float[] far = PortalLink.recomputeFarPosition(b, false);
      near("far x", far[0], 1000f);
      near("far y", far[1], 100f);
      near("far z", far[2], 0f);
      near("fartheta", far[3], -90f);
      // Con A espejo no se suma el desplazamiento: (1000, 0).
      near("far y con espejo", PortalLink.recomputeFarPosition(b, true)[1], 0f);

      float[] a = rotZ(0, 100, 1, 200);
      // Borde inferior de A: (0,0) + (1,0,1).M = (100, 0). Cruza solo hacia
      // +Y (camino a la izquierda del borde): de (30,-5) a (30,5): d = 10*100
      // = 1000 > 0, rel = (30,-5): along = -(-5)*100 = 500 -> f = 0.5.
      near("isCollision +Y", PortalLink.isCollision(0, 0, 100, 0, 30, -5, 0, 10), 0.5f);
      near("isCollision -Y (lado que no cruza)", PortalLink.isCollision(0, 0, 100, 0, 30, 5, 0, -10), -1f);
      near("isCollision fuera del borde", PortalLink.isCollision(0, 0, 100, 0, 130, -5, 0, 10), -2f);

      // _p2pxform = inv(A sin escala = I) . Rz(-90) . T(1000,100,0). Rz(-90)
      // con vector fila: (x,y) -> (y, -x). Corte en (30,0) + 0.2 en +Y =
      // (30, 0.2) -> (0.2, -30) + (1000,100) = (1000.2, 70); resto del camino
      // (0, 5) -> (5, 0). Llegada (1005.2, 70, 0): en el marco de B (origen
      // (1000,0), X = +y, Y = -x) es x = 70 = 100 - 30 (simetrico sobre el
      // ancho) e y = -5.2 (detras de B). Avance (0,1) -> (1,0): rumbo 0,
      // alejandose de B por su -Y; para volver se cruza B hacia su +Y.
      float[] p2p = PortalLink.p2pTransform(a, 100, 1, 200, false, far[0], far[1], far[2], far[3]);
      float[] r = PortalLink.cross(p2p, new float[]{30, -5, 0}, 0, 10, 0, 0.5f, new float[]{0, 1, 0});
      near("llegada x", r[0], 1005.2f);
      near("llegada y", r[1], 70f);
      near("llegada z", r[2], 0f);
      near("rumbo de llegada", r[3], 0f);
      // La formula de antes (atan2(-fwd.y, fwd.x), fwd = +Y de B = (-1,0))
      // daba pi: mirando a B, en sentido contrario.

      // Espejo (flags & 4): se niega la columna x (m[0], m[4], m[8], m[12])
      // antes del giro: el punto (30, 0.2) pasa a (-30, 0.2).
      float[] pm = PortalLink.p2pTransform(a, 100, 1, 200, true, 0, 0, 0, 0);
      float[] q = PortalLink.transformPoint(pm, 30, 0.2f, 0);
      near("espejo x", q[0], -30f);
      near("espejo y", q[1], 0.2f);

      if (failures > 0) {
         System.out.println("PortalLinkCheck: " + failures + " fallos");
         System.exit(1);
      }
      System.out.println("PortalLinkCheck: OK");
   }

   /** Giro de deg grados sobre Z (vector fila) con escala previa (sx, sy, sz). */
   private static float[] rotZ(float deg, float sx, float sy, float sz) {
      double t = Math.toRadians(deg);
      float c = (float) Math.cos(t), s = (float) Math.sin(t);
      if (Math.abs(c) < 1e-7f) {
         c = 0f;
      }
      if (Math.abs(s) < 1e-7f) {
         s = 0f;
      }
      return new float[]{sx * c, sx * s, 0, 0, -sy * s, sy * c, 0, 0, 0, 0, sz, 0, 0, 0, 0, 1};
   }

   private static void near(String what, float got, float want) {
      if (Math.abs(got - want) > 1e-3f) {
         failures++;
         System.out.println("FALLO " + what + ": " + got + " (esperado " + want + ")");
      }
   }
}
