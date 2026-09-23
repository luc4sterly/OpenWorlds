package net.freeworlds.world;

import java.util.List;

/**
 * MaterialTiles con casos calculados a mano (Material.calcRes /
 * loadTextures / syncBackgroundLoad y Surface.addSubPolys 0x004206d0).
 * Sale con 1 si algo falla.
 */
public final class MaterialTilesCheck {
   private static int failures = 0;

   public static void main(String[] args) {
      // "cbirda42h*2v*.mov": sufijo "2h*2v*.mov" (10), fichero cbirda4.mov;
      // textura[k*2+c] = frame (2-1-k)*2 + c -> [2, 3, 0, 1].
      MaterialTiles t = MaterialTiles.of("tex/cbirda42h*2v*.mov");
      eq("cbirda4 hRes", t.hRes, 2);
      eq("cbirda4 vRes", t.vRes, 2);
      eq("cbirda4 sPos", t.sPos, 0);
      eq("cbirda4 frames pedidos", t.framesNeeded(), 4);
      eqs("cbirda4 fichero", t.files[3], "cbirda4.mov");
      eqa("cbirda4 frame por textura", t.frames, new int[]{2, 3, 0, 1});

      // Rect u=v=1 sin offsets, 2x2: v1 = (0,0,0) uv (0,1), v2 = (1,0,0)
      // uv (1,1), v4 = (0,0,1) uv (0,0). dz = 1/(2*(0-1)) = -0.5,
      // dx = 1/(2*1) = 0.5. Fila de bloque 0, sv = 1 primero: iv = 1,
      // a = min(2, 2) = 2, b = max(1, 0) = 1 -> za = (2-2)*-0.5 = 0,
      // zb = (1-2)*-0.5 = 0.5; a,b -> 1,0. Celdas: {x0,x1,za,zb,c,d,a,b,m}.
      List<float[]> c = MaterialTiles.rectCells(1f, 1f, 0f, 0f, 0x3, 2, 2);
      eq("2x2 celdas", c.size(), 4);
      cell("2x2 celda 0 (abajo izq.)", c.get(0), 0f, 0.5f, 0f, 0.5f, 0f, 1f, 1f, 0f, 0);
      cell("2x2 celda 1 (abajo der.)", c.get(1), 0.5f, 1f, 0f, 0.5f, 0f, 1f, 1f, 0f, 1);
      cell("2x2 celda 2 (arriba izq.)", c.get(2), 0f, 0.5f, 0.5f, 1f, 0f, 1f, 1f, 0f, 2);
      cell("2x2 celda 3 (arriba der.)", c.get(3), 0.5f, 1f, 0.5f, 1f, 0f, 1f, 1f, 0f, 3);
      // Frame visible arriba a la izquierda = frames[material de la celda 2]
      // = frames[2] = 0: el frame 0 de la pelicula queda arriba a la izquierda.
      eq("2x2 frame arriba izq.", t.frames[(int) c.get(2)[8]], 0);
      eq("2x2 frame abajo der.", t.frames[(int) c.get(1)[8]], 3);

      // "f12h*.mov": 2 texturas en horizontal, frames [0, 1]; una banda
      // (sv = 0), frame 0 a la izquierda.
      MaterialTiles f = MaterialTiles.of("tex/f12h*.mov");
      eqs("f1 fichero", f.files[0], "f1.mov");
      eqa("f1 frames", f.frames, new int[]{0, 1});
      List<float[]> fc = MaterialTiles.rectCells(1f, 1f, 0f, 0f, 0x3, 2, 1);
      eq("f1 celdas", fc.size(), 2);
      cell("f1 celda 0", fc.get(0), 0f, 0.5f, 0f, 1f, 0f, 1f, 1f, 0f, 0);

      // "drs52v*.mov": 2 en vertical, frames [1, 0]; celda 0 = banda de
      // abajo (textura 0 = frame 1), celda 1 = arriba (frame 0).
      MaterialTiles d = MaterialTiles.of("tex/drs52v*.mov");
      eqs("drs5 fichero", d.files[0], "drs5.mov");
      eqa("drs5 frames", d.frames, new int[]{1, 0});
      List<float[]> dc = MaterialTiles.rectCells(1f, 1f, 0f, 0f, 0x3, 1, 2);
      cell("drs5 celda 0 (abajo)", dc.get(0), 0f, 1f, 0f, 0.5f, 0f, 1f, 1f, 0f, 0);
      cell("drs5 celda 1 (arriba)", dc.get(1), 0f, 1f, 0.5f, 1f, 0f, 1f, 1f, 0f, 1);

      // cv2h*2v*.mov del mundo real: uOff = 1 y flags 0x80001 (volteo en U).
      // uo = 1*1 - 2*floor(0.5) = 1 -> u en [1,2]: col0 = 2, uFlip de salida
      // = (2/2)&1 = 1 -> su empieza en 1: iu = 3, c = 3, d = min(4, 4) = 4,
      // xc = (3-2)*0.5 = 0.5, xd = 1, c,d -> 0,1 -> volteados 1,0.
      List<float[]> vc = MaterialTiles.rectCells(1f, 1f, 1f, 0f, 0x80001, 2, 2);
      eq("cv volteado celdas", vc.size(), 4);
      cell("cv volteado celda 0", vc.get(0), 0.5f, 1f, 0f, 0.5f, 1f, 0f, 1f, 0f, 0);
      cell("cv volteado celda 1", vc.get(1), 0f, 0.5f, 0f, 0.5f, 1f, 0f, 1f, 0f, 1);

      // u = 1.4 (no entero): la celda final se redondea hacia ARRIBA
      // (0x00480a78, RC = +inf): colEnd = ceil(1.4)*2 = 4, uHi = 2.8.
      // iu = 2: c = 2, d = 2.8 -> xc = 2/2.8, xd = 1; iu = 3: d < c ->
      // c = d = 2.8 -> celda degenerada en x = 1. Con redondeo al mas
      // cercano (1) el Rect se quedaria sin cubrir de x = 0.714 a 1.
      List<float[]> nc = MaterialTiles.rectCells(1.4f, 1f, 0f, 0f, 0x3, 2, 1);
      eq("u=1.4 celdas", nc.size(), 4);
      near("u=1.4 celda 2 xc", nc.get(2)[0], 2f / 2.8f);
      near("u=1.4 celda 2 xd", nc.get(2)[1], 1f);
      near("u=1.4 celda 3 xc", nc.get(3)[0], 1f);
      near("u=1.4 celda 3 xd", nc.get(3)[1], 1f);

      // .cmp con sufijo: un fichero por celda, nombre + fila (vRes..1) +
      // columna (1..hRes): k=0 -> "wall31", k=1 -> "wall32", k=5 -> "wall12".
      MaterialTiles w = MaterialTiles.of("tex/wall2h*3v*.cmp");
      eq("wall sPos", w.sPos, -1);
      eqs("wall k=0", w.files[0], "wall31.cmp");
      eqs("wall k=1", w.files[1], "wall32.cmp");
      eqs("wall k=5", w.files[5], "wall12.cmp");

      // Sin sufijo: una textura, frame 0; "Ns*" en un .mov elige el grupo.
      MaterialTiles p = MaterialTiles.of("http://host/dtex/foo.cmp");
      eqs("sin sufijo fichero", p.files[0], "foo.cmp");
      eq("sin sufijo hiRes", p.hiRes() ? 1 : 0, 0);
      MaterialTiles s3 = MaterialTiles.of("tex/x3s*.mov");
      eq("x3s* sPos", s3.sPos, 2);
      eq("x3s* frame", s3.frames[0], 2);
      eq("x3s* frames pedidos", s3.framesNeeded(), 3);

      if (failures > 0) {
         System.out.println("MaterialTilesCheck: " + failures + " fallos");
         System.exit(1);
      }
      System.out.println("MaterialTilesCheck: OK");
   }

   private static void cell(String what, float[] c, float x0, float x1, float za, float zb,
         float cu, float du, float a, float b, int m) {
      float[] want = {x0, x1, za, zb, cu, du, a, b, m};
      for (int i = 0; i < want.length; i++) {
         if (Math.abs(c[i] - want[i]) > 1e-6f) {
            failures++;
            System.out.println("FALLO " + what + " [" + i + "]: " + c[i] + " (esperado " + want[i] + ")");
         }
      }
   }

   private static void near(String what, float got, float want) {
      if (Math.abs(got - want) > 1e-6f) {
         failures++;
         System.out.println("FALLO " + what + ": " + got + " (esperado " + want + ")");
      }
   }

   private static void eq(String what, int got, int want) {
      if (got != want) {
         failures++;
         System.out.println("FALLO " + what + ": " + got + " (esperado " + want + ")");
      }
   }

   private static void eqs(String what, String got, String want) {
      if (!want.equals(got)) {
         failures++;
         System.out.println("FALLO " + what + ": " + got + " (esperado " + want + ")");
      }
   }

   private static void eqa(String what, int[] got, int[] want) {
      if (!java.util.Arrays.equals(got, want)) {
         failures++;
         System.out.println("FALLO " + what + ": " + java.util.Arrays.toString(got)
            + " (esperado " + java.util.Arrays.toString(want) + ")");
      }
   }
}
