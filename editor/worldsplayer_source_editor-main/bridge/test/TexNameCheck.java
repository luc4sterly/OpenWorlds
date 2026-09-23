package NET.worlds.core;

import java.io.File;
import java.nio.file.Files;

/**
 * Nombres y búsqueda de texturas: el nombre de gamma.dll (FUN_00421420), el
 * nombre base y la comparación de RW (FUN_10043e80 / FUN_10043f20), el
 * diccionario con cuenta de referencias (FUN_004183e0, FUN_00418370,
 * RwAddTextureToDict) y RwGetNamedTexture leyendo de la ruta de formas
 * ".;.." con el orden de extensiones de FUN_10021350. Sale con 1 si algo
 * falla.
 */
public final class TexNameCheck {
   private static int failures = 0;

   public static void main(String[] args) throws Exception {
      // FUN_00421420: '\\' ':' '.' '/' -> '|', A-Z en minúsculas, "|frame" si > 0
      eqs("dictName", NativeTextures.dictName("home:GroundZero/tex/Wall.CMP", 0), "home|groundzero|tex|wall|cmp");
      eqs("dictName frame 3", NativeTextures.dictName("avatar:pengo.mov", 3), "avatar|pengo|mov|3");
      eqs("dictName base de Java", NativeTextures.dictName("ROCK1A", 0), "rock1a");

      // FUN_10043e80
      eqs("base c:\\a\\Wall.BMP", NativeTextures.rwBaseName("c:\\a\\Wall.BMP"), "Wall");
      eqs("base c:wall.bmp", NativeTextures.rwBaseName("c:wall.bmp"), "wall");
      eqs("base flrlite5a.cmp", NativeTextures.rwBaseName("flrlite5a.cmp"), "flrlite5a");
      eqs("base a.b\\c (punto antes del directorio)", NativeTextures.rwBaseName("a.b\\c"), "c");
      eqs("base u:/x/y/wall.cmp ('/' no separa)", NativeTextures.rwBaseName("u:/x/y/wall.cmp"), "/x/y/wall");
      eqs("base nombre de gamma", NativeTextures.rwBaseName("home|groundzero|tex|wall|cmp"), "home|groundzero|tex|wall|cmp");

      // como la registra ShapeTextureLoader (url.getBaseWithoutExt) y la pide el .rwx
      short[] px = new short[128 * 128];
      int h = NativeTextures.userTexture("rock1a", 0, px, 128, 128);
      check("creada", h != 0);
      eq("RW encuentra ROCK1A.BMP", handle(NativeTextures.find("ROCK1A.BMP")), h);
      eq("RW encuentra tex\\rock1a.cMP", handle(NativeTextures.find("tex\\rock1a.cMP")), h);
      eq("RW no encuentra tex/rock1a.cmp", handle(NativeTextures.find("tex/rock1a.cmp")), 0);
      eq("find no sube la cuenta", NativeTextures.texture(h).data, 1);

      // FUN_004183e0 sube la cuenta; FUN_00418370 la baja y destruye en la última
      eq("lookup sube", NativeTextures.lookupOrRead("ROCK1A", null, 0), h);
      eq("cuenta 2", NativeTextures.texture(h).data, 2);
      NativeTextures.release(h);
      eq("cuenta 1", NativeTextures.texture(h).data, 1);
      NativeTextures.release(h);
      check("destruida", NativeTextures.texture(h) == null);
      eq("fuera del diccionario", handle(NativeTextures.find("rock1a")), 0);

      // RwAddTextureToDict: un nombre repetido deja la segunda fuera (error 0x69)
      int a = NativeTextures.userTexture("dup", 0, new short[128 * 128], 128, 128);
      int b = NativeTextures.create("dup", new short[128 * 128], 128, 128);
      check("dos texturas", a != 0 && b != 0 && a != b);
      eq("el diccionario conserva la primera", handle(NativeTextures.find("DUP")), a);

      // ruta de formas ".;..": dir/sub es el directorio de trabajo; wall.bmp en
      // dir/sub, rock.bmp en dir (".."). Sin extensión se prueban .ras, .tex,
      // .env, .bmp, .rle en ese orden: con both.ras y both.bmp gana el .ras.
      File dir = Files.createTempDirectory("texname").toFile();
      File sub = new File(dir, "sub");
      sub.mkdir();
      Files.write(new File(sub, "wall.bmp").toPath(), TexRwReadCheck.bmp24(2, 2, fill(0xFF0000)));
      Files.write(new File(dir, "rock.bmp").toPath(), TexRwReadCheck.bmp24(2, 2, fill(0x00FF00)));
      Files.write(new File(sub, "both.bmp").toPath(), TexRwReadCheck.bmp24(2, 2, fill(0x0000FF)));
      byte[] gray = new byte[16 * 16];
      java.util.Arrays.fill(gray, (byte) 200);
      Files.write(new File(sub, "both.ras").toPath(), TexRwReadCheck.ras8(16, 16, gray));
      NativeTextures.rwCwd = sub;
      try {
         int w = NativeTextures.rwGetNamed("Wall");
         check("Wall leída de .", w != 0);
         eq("Wall roja", w == 0 ? -1 : NativeTextures.texture(w).pixels[0] & 0xFFFF, 0xF800);
         eq("Wall data 0 (de RW)", w == 0 ? -1 : NativeTextures.texture(w).data, 0);
         eq("Wall en el diccionario con su nombre base", handle(NativeTextures.find("x\\WALL.cmp")), w);
         int r = NativeTextures.rwGetNamed("rock.bmp");
         eq("rock.bmp leída de ..", r == 0 ? -1 : NativeTextures.texture(r).pixels[0] & 0xFFFF, 0x07E0);
         int bo = NativeTextures.rwGetNamed("both");
         eq("both: .ras antes que .bmp", bo == 0 ? -1 : NativeTextures.texture(bo).pixels[0] & 0xFFFF, 25 << 11 | 50 << 5 | 25);
         eq("rwGetNamed repetido: la misma", NativeTextures.rwGetNamed("BOTH.env"), bo);
         check("inexistente", NativeTextures.rwGetNamed("nada") == 0);
         // gamma.dll encuentra la de RW (data 0): la destruye y devuelve 0
         eq("FUN_004183e0 sobre una de RW", NativeTextures.lookupOrRead("wall", null, 0), 0);
         check("Wall destruida", NativeTextures.texture(w) == null);
      } finally {
         NativeTextures.rwCwd = null;
      }

      if (failures > 0) {
         System.out.println("TexNameCheck: " + failures + " fallos");
         System.exit(1);
      }
      System.out.println("TexNameCheck: OK");
   }

   private static int[] fill(int c) {
      return new int[]{c, c, c, c};
   }

   private static int handle(NativeTextures.Texture t) {
      return t == null ? 0 : t.handle;
   }

   private static void check(String what, boolean ok) {
      if (!ok) {
         failures++;
         System.out.println("FALLA " + what);
      }
   }

   private static void eq(String what, long got, long want) {
      if (got != want) {
         failures++;
         System.out.println("FALLA " + what + ": " + got + " (esperado " + want + ")");
      }
   }

   private static void eqs(String what, String got, String want) {
      if (!want.equals(got)) {
         failures++;
         System.out.println("FALLA " + what + ": '" + got + "' (esperado '" + want + "')");
      }
   }
}
