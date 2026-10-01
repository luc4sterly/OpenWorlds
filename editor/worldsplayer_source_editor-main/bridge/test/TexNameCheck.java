package NET.worlds.core;

import java.io.File;
import java.nio.file.Files;

/**
 * Texture names and lookup: gamma.dll's name (FUN_00421420), RW's base
 * name and comparison (FUN_10043e80 / FUN_10043f20), the
 * reference-counted dictionary (FUN_004183e0, FUN_00418370,
 * RwAddTextureToDict) and RwGetNamedTexture reading from the shapes path
 * ".;.." with the extension order of FUN_10021350. Exits with 1 if anything
 * fails.
 */
public final class TexNameCheck {
   private static int failures = 0;

   public static void main(String[] args) throws Exception {
      // FUN_00421420: '\\' ':' '.' '/' -> '|', A-Z lowercased, "|frame" if > 0
      eqs("dictName", NativeTextures.dictName("home:GroundZero/tex/Wall.CMP", 0), "home|groundzero|tex|wall|cmp");
      eqs("dictName frame 3", NativeTextures.dictName("avatar:pengo.mov", 3), "avatar|pengo|mov|3");
      eqs("dictName Java base name", NativeTextures.dictName("ROCK1A", 0), "rock1a");

      // FUN_10043e80
      eqs("base c:\\a\\Wall.BMP", NativeTextures.rwBaseName("c:\\a\\Wall.BMP"), "Wall");
      eqs("base c:wall.bmp", NativeTextures.rwBaseName("c:wall.bmp"), "wall");
      eqs("base flrlite5a.cmp", NativeTextures.rwBaseName("flrlite5a.cmp"), "flrlite5a");
      eqs("base a.b\\c (dot before the directory)", NativeTextures.rwBaseName("a.b\\c"), "c");
      eqs("base u:/x/y/wall.cmp ('/' does not separate)", NativeTextures.rwBaseName("u:/x/y/wall.cmp"), "/x/y/wall");
      eqs("base gamma name", NativeTextures.rwBaseName("home|groundzero|tex|wall|cmp"), "home|groundzero|tex|wall|cmp");

      // as ShapeTextureLoader registers it (url.getBaseWithoutExt) and the .rwx asks for it
      short[] px = new short[128 * 128];
      int h = NativeTextures.userTexture("rock1a", 0, px, 128, 128);
      check("created", h != 0);
      eq("RW finds ROCK1A.BMP", handle(NativeTextures.find("ROCK1A.BMP")), h);
      eq("RW finds tex\\rock1a.cMP", handle(NativeTextures.find("tex\\rock1a.cMP")), h);
      eq("RW does not find tex/rock1a.cmp", handle(NativeTextures.find("tex/rock1a.cmp")), 0);
      eq("find does not raise the count", NativeTextures.texture(h).data, 1);

      // FUN_004183e0 raises the count; FUN_00418370 lowers it and destroys on the last one
      eq("lookup raises", NativeTextures.lookupOrRead("ROCK1A", null, 0), h);
      eq("count 2", NativeTextures.texture(h).data, 2);
      NativeTextures.release(h);
      eq("count 1", NativeTextures.texture(h).data, 1);
      NativeTextures.release(h);
      check("destroyed", NativeTextures.texture(h) == null);
      eq("outside the dictionary", handle(NativeTextures.find("rock1a")), 0);

      // RwAddTextureToDict: a repeated name leaves the second one out (error 0x69)
      int a = NativeTextures.userTexture("dup", 0, new short[128 * 128], 128, 128);
      int b = NativeTextures.create("dup", new short[128 * 128], 128, 128);
      check("two textures", a != 0 && b != 0 && a != b);
      eq("the dictionary keeps the first one", handle(NativeTextures.find("DUP")), a);

      // shapes path ".;..": dir/sub is the working directory; wall.bmp in
      // dir/sub, rock.bmp in dir (".."). Without an extension .ras, .tex,
      // .env, .bmp, .rle are tried in that order: with both.ras and both.bmp .ras wins.
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
         check("Wall read from .", w != 0);
         eq("Wall red", w == 0 ? -1 : NativeTextures.texture(w).pixels[0] & 0xFFFF, 0xF800);
         eq("Wall data 0 (from RW)", w == 0 ? -1 : NativeTextures.texture(w).data, 0);
         eq("Wall in the dictionary with its base name", handle(NativeTextures.find("x\\WALL.cmp")), w);
         int r = NativeTextures.rwGetNamed("rock.bmp");
         eq("rock.bmp read from ..", r == 0 ? -1 : NativeTextures.texture(r).pixels[0] & 0xFFFF, 0x07E0);
         int bo = NativeTextures.rwGetNamed("both");
         eq("both: .ras before .bmp", bo == 0 ? -1 : NativeTextures.texture(bo).pixels[0] & 0xFFFF, 25 << 11 | 50 << 5 | 25);
         eq("repeated rwGetNamed: the same one", NativeTextures.rwGetNamed("BOTH.env"), bo);
         check("nonexistent", NativeTextures.rwGetNamed("missing") == 0);
         // gamma.dll finds the RW one (data 0): destroys it and returns 0
         eq("FUN_004183e0 on an RW one", NativeTextures.lookupOrRead("wall", null, 0), 0);
         check("Wall destroyed", NativeTextures.texture(w) == null);
      } finally {
         NativeTextures.rwCwd = null;
      }

      if (failures > 0) {
         System.out.println("TexNameCheck: " + failures + " failures");
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
         System.out.println("FAIL " + what);
      }
   }

   private static void eq(String what, long got, long want) {
      if (got != want) {
         failures++;
         System.out.println("FAIL " + what + ": " + got + " (expected " + want + ")");
      }
   }

   private static void eqs(String what, String got, String want) {
      if (!want.equals(got)) {
         failures++;
         System.out.println("FAIL " + what + ": '" + got + "' (expected '" + want + "')");
      }
   }
}
