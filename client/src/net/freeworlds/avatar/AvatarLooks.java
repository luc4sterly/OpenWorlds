package net.freeworlds.avatar;

import net.freeworlds.cmp.CmpTexture;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * El aspecto que el nombre de avatar da a cada parte de un .bod (port de
 * PosableShape.createSubparts via {@link AvatarNameDecoder}). Solo la limb:
 * textura o color; origMat = sin cambio. Lo que no se puede aplicar se
 * informa, no se inventa.
 *
 * Una textura "avatar:NOMBREns*.mov" usa la subimagen n-1 del .mov como el
 * original: Material.calcRes pone hRes = vRes = 1 y sPos = n-1, y
 * Material.syncBackgroundLoad toma de ScapePicMovie la textura
 * hRes*vRes*sPos = sPos si el .mov tiene al menos sPos+1 frames; si no,
 * deja el material sin textura (var16 = null).
 *
 * Sacado de BodViewer (2026-09-25) para que WorldViewer lo use igual.
 */
public final class AvatarLooks {
   private AvatarLooks() {
   }

   /** Aspecto que el nombre de avatar asigna a la raiz de una parte. */
   public static final class Look {
      public final float r, g, b;
      /** Textura o null (color plano). */
      public final CmpTexture texture;

      public Look(float r, float g, float b, CmpTexture texture) {
         this.r = r;
         this.g = g;
         this.b = b;
         this.texture = texture;
      }
   }

   /** Resultado: aspecto por tag y lo que no se aplico (para el informe). */
   public static final class Result {
      public final Map<Integer, Look> byTag = new HashMap<>();
      public final List<String> skipped = new ArrayList<>();
      public final Map<String, CmpTexture[]> movies = new HashMap<>();
      public int textured;
      public int colored;
      public int unchanged;
   }

   /** Texturas ya decodificadas, compartidas entre avatares (clave: fichero en minusculas). */
   private static final Map<String, CmpTexture[]> MOV_CACHE = new HashMap<>();
   private static final Map<String, CmpTexture> CMP_CACHE = new HashMap<>();

   /**
    * @param fig     el nombre decodificado
    * @param bodFile el .bod que se dibuja: las partes que el nombre saca de
    *                otro .bod no se aplican (se informan)
    * @param texDir  donde buscar las texturas (el directorio de avatares)
    */
   public static Result resolve(AvatarFigure fig, File bodFile, File texDir) throws IOException {
      Result res = new Result();
      for (AvatarPart part : fig.partes) {
         if (!part.adjunta || part.limb().material < 0) {
            res.unchanged++;
            continue;
         }
         String partBod = part.bodFile();
         if (partBod != null && !partBod.equalsIgnoreCase(bodFile.getName())) {
            res.skipped.add(part.letra + " (usa otro .bod: " + partBod + ")");
            continue;
         }
         AvatarMaterial m = fig.paleta.get(part.limb().material);
         if (m.origMat) {
            res.unchanged++;
         } else if (m.kind == AvatarMaterial.Kind.COLOR) {
            res.byTag.put(part.tag, new Look(m.r / 255f, m.g / 255f, m.b / 255f, null));
            res.colored++;
         } else {
            File tf = findIgnoreCase(texDir, m.textureFile);
            if (tf == null) {
               res.skipped.add(part.letra + " (" + m.textureFile + " no esta en el corpus)");
               continue;
            }
            String key = tf.getAbsolutePath().toLowerCase(java.util.Locale.ROOT);
            CmpTexture tex;
            if (m.textureSubIndex >= 0) {
               CmpTexture[] frames;
               synchronized (MOV_CACHE) {
                  frames = MOV_CACHE.get(key);
                  if (frames == null) {
                     frames = CmpTexture.loadMovFrames(tf);
                     MOV_CACHE.put(key, frames);
                  }
               }
               res.movies.put(tf.getName(), frames);
               if (m.textureSubIndex + 1 > frames.length) {
                  res.skipped.add(part.letra + " (" + m.textureFile + " subimagen " + m.textureSubIndex
                     + ": el .mov solo tiene " + frames.length + " frames; el original deja el material sin textura)");
                  continue;
               }
               tex = frames[m.textureSubIndex];
            } else {
               synchronized (CMP_CACHE) {
                  tex = CMP_CACHE.get(key);
                  if (tex == null) {
                     tex = CmpTexture.loadRaw(tf);
                     CMP_CACHE.put(key, tex);
                  }
               }
            }
            res.byTag.put(part.tag, new Look(1f, 1f, 1f, tex));
            res.textured++;
         }
      }
      return res;
   }

   /** Una linea de resumen y una por cada cosa no aplicada. */
   public static String report(String name, AvatarFigure fig, Result res) {
      StringBuilder b = new StringBuilder();
      b.append("Avatar \"").append(name).append("\" (").append(fig.cadena).append("): partes con textura=")
         .append(res.textured).append(" con color=").append(res.colored).append(" sin cambio=")
         .append(res.unchanged).append(" no aplicables=").append(res.skipped.size());
      for (Map.Entry<String, CmpTexture[]> e : res.movies.entrySet()) {
         CmpTexture f0 = e.getValue().length > 0 ? e.getValue()[0] : null;
         b.append("\n   ").append(e.getKey()).append(": ").append(e.getValue().length).append(" frames")
            .append(f0 != null ? " de " + f0.width + "x" + f0.height : "");
      }
      for (String s : res.skipped) {
         b.append("\n   no aplicado: ").append(s);
      }
      return b.toString();
   }

   private static File findIgnoreCase(File dir, String name) {
      File f = new File(dir, name);
      if (f.isFile()) {
         return f;
      }
      File[] fs = dir.listFiles();
      if (fs != null) {
         for (File c : fs) {
            if (c.getName().equalsIgnoreCase(name) && c.isFile()) {
               return c;
            }
         }
      }
      return null;
   }
}
