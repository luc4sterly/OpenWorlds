package NET.worlds.core;

import java.io.File;
import java.nio.file.Files;

/**
 * Texturas de un .rwx: el mandato Texture/TextureExt de RWL21 (0x10014b00)
 * resuelve la textura al leer el script con RwGetNamedTexture y, si no la
 * encuentra, RwReadShape entero devuelve NULL (0x100163e0); y el barrido
 * previo de gamma.dll (ShapeLoader.loadTextFile 0x0041cba0) que pide las
 * texturas a Java antes. Sale con 1 si algo falla.
 */
public final class RwxTextureCheck {
   private static int failures = 0;

   public static void main(String[] args) throws Exception {
      File dir = Files.createTempDirectory("rwxtex").toFile();
      NativeTextures.rwCwd = dir;
      Files.write(new File(dir, "wall.bmp").toPath(), TexRwReadCheck.bmp24(2, 2, new int[]{0x00FF00, 0x00FF00, 0x00FF00, 0x00FF00}));

      // textura que existe (wall.bmp en ".", sin extensión en el script)
      int ok = read(dir, "ok.rwx", "Texture wall");
      check("Texture wall: clump", ok != 0);
      int wall = NativeTextures.rwGetNamed("wall");
      check("wall en el diccionario tras leer", wall != 0);
      if (ok != 0) {
         NativeScene.Material m = firstMaterial(ok);
         eq("material con el handle de RwGetNamedTexture", m.texture, wall);
         eq("y su nombre", m.textureName, "wall");
      }

      // textura que no existe: RwReadShape -> NULL
      eq("Texture nada -> clump 0", read(dir, "no.rwx", "Texture nada"), 0);
      // "null" en los 4 primeros caracteres, sin distinguir A-Z: sin textura
      int nul = read(dir, "nul.rwx", "Texture NULLx");
      check("Texture NULLx -> clump", nul != 0);
      if (nul != 0) {
         eq("NULLx deja el material sin textura", firstMaterial(nul).texture, 0);
      }
      // sin nombre (error 5) y palabra desconocida (error 4): FALSE
      eq("Texture sin nombre -> 0", read(dir, "vacio.rwx", "Texture"), 0);
      eq("Texture wall otra -> 0", read(dir, "kw.rwx", "Texture wall otra"), 0);
      eq("Texture wall mask (sin nombre) -> 0", read(dir, "mask.rwx", "Texture wall mask"), 0);

      // barrido de gamma.dll: minúsculas, primer token exacto, "null" exacto, ".bmp" sin punto
      File scan = new File(dir, "scan.rwx");
      Files.write(scan.toPath(), ("ModelBegin\r\n  TEXTURE Wall.CMP\r\ntextureext rock\r\nTexture NULL\r\n"
         + "Texture NULLX\r\n#texture comentada\r\nTextureModes Lit\r\ntexture\r\n\ttexture\tTab.bmp extra\nModelEnd\r\n")
         .getBytes("ISO-8859-1"));
      eq("scanTextures", NativeShapes.scanTextures(scan.getAbsolutePath()).toString(),
         "[wall.cmp, rock.bmp, nullx.bmp, tab.bmp]");

      if (failures > 0) {
         System.out.println(failures + " fallos");
         System.exit(1);
      }
      System.out.println("RwxTextureCheck OK");
   }

   /** Un clump de un triángulo con la línea de textura dada antes de los polígonos. */
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
         System.out.println("FALLA " + what);
      }
   }

   private static void eq(String what, Object got, Object want) {
      if (got == null ? want != null : !got.equals(want)) {
         failures++;
         System.out.println("FALLA " + what + ": " + got + " != " + want);
      }
   }

   private static void eq(String what, int got, int want) {
      eq(what, Integer.valueOf(got), Integer.valueOf(want));
   }
}
