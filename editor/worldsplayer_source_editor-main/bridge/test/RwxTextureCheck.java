package NET.worlds.core;

import java.io.File;
import java.nio.file.Files;

/**
 * Textures of a .rwx: RWL21's Texture/TextureExt command (0x10014b00)
 * resolves the texture while reading the script with RwGetNamedTexture and,
 * if it does not find it, the whole RwReadShape returns NULL (0x100163e0); and
 * gamma.dll's earlier scan (ShapeLoader.loadTextFile 0x0041cba0), which asks
 * Java for the textures beforehand. Exits with 1 if anything fails.
 */
public final class RwxTextureCheck {
   private static int failures = 0;

   public static void main(String[] args) throws Exception {
      File dir = Files.createTempDirectory("rwxtex").toFile();
      NativeTextures.rwCwd = dir;
      Files.write(new File(dir, "wall.bmp").toPath(), TexRwReadCheck.bmp24(2, 2, new int[]{0x00FF00, 0x00FF00, 0x00FF00, 0x00FF00}));

      // texture that exists (wall.bmp in ".", no extension in the script)
      int ok = read(dir, "ok.rwx", "Texture wall");
      check("Texture wall: clump", ok != 0);
      int wall = NativeTextures.rwGetNamed("wall");
      check("wall in the dictionary after reading", wall != 0);
      if (ok != 0) {
         NativeScene.Material m = firstMaterial(ok);
         eq("material with RwGetNamedTexture's handle", m.texture, wall);
         eq("and its name", m.textureName, "wall");
      }

      // texture that does not exist: RwReadShape -> NULL
      eq("Texture nada -> clump 0", read(dir, "no.rwx", "Texture nada"), 0);
      // "null" in the first 4 characters, case-insensitive A-Z: no texture
      int nul = read(dir, "nul.rwx", "Texture NULLx");
      check("Texture NULLx -> clump", nul != 0);
      if (nul != 0) {
         eq("NULLx leaves the material without a texture", firstMaterial(nul).texture, 0);
      }
      // no name (error 5) and unknown word (error 4): FALSE
      eq("Texture without a name -> 0", read(dir, "vacio.rwx", "Texture"), 0);
      eq("Texture wall otra -> 0", read(dir, "kw.rwx", "Texture wall otra"), 0);
      eq("Texture wall mask (no name) -> 0", read(dir, "mask.rwx", "Texture wall mask"), 0);

      // gamma.dll scan: lowercase, exact first token, exact "null", ".bmp" without a dot
      File scan = new File(dir, "scan.rwx");
      Files.write(scan.toPath(), ("ModelBegin\r\n  TEXTURE Wall.CMP\r\ntextureext rock\r\nTexture NULL\r\n"
         + "Texture NULLX\r\n#texture comentada\r\nTextureModes Lit\r\ntexture\r\n\ttexture\tTab.bmp extra\nModelEnd\r\n")
         .getBytes("ISO-8859-1"));
      eq("scanTextures", NativeShapes.scanTextures(scan.getAbsolutePath()).toString(),
         "[wall.cmp, rock.bmp, nullx.bmp, tab.bmp]");

      if (failures > 0) {
         System.out.println(failures + " failures");
         System.exit(1);
      }
      System.out.println("RwxTextureCheck OK");
   }

   /** A one-triangle clump with the given texture line before the polygons. */
   private static int read(File dir, String name, String textureLine) throws Exception {
      File f = new File(dir, name);
      String s = "ModelBegin\nClumpBegin\nVertex 0 0 0 UV 0 0\nVertex 1 0 0 UV 1 0\nVertex 0 1 0 UV 0 1\n"
         + textureLine + "\nTriangle 1 2 3\nClumpEnd\nModelEnd\n";
      Files.write(f.toPath(), s.getBytes("ISO-8859-1"));
      return NativeShapes.readShape(f.getAbsolutePath()).clump;
   }

   private static NativeScene.Material firstMaterial(int clump) {
      NativeScene.Clump c = NativeScene.clump(clump);
      if (!c.polys.isEmpty()) {
         return NativeScene.material(c.polys.get(0).material);
      }
      for (int ch : NativeScene.childHandles(clump)) {
         NativeScene.Material m = firstMaterial(ch);
         if (m != null) {
            return m;
         }
      }
      return null;
   }

   private static void check(String what, boolean ok) {
      if (!ok) {
         failures++;
         System.out.println("FAIL " + what);
      }
   }

   private static void eq(String what, Object got, Object want) {
      if (got == null ? want != null : !got.equals(want)) {
         failures++;
         System.out.println("FAIL " + what + ": " + got + " != " + want);
      }
   }

   private static void eq(String what, int got, int want) {
      eq(what, Integer.valueOf(got), Integer.valueOf(want));
   }
}
