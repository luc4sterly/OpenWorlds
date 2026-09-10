package net.freeworlds.render;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.nio.ByteBuffer;

import javax.imageio.ImageIO;

import org.lwjgl.system.MemoryStack;

import static org.lwjgl.opengl.GL11.*;

/**
 * Helpers GL compartidos por los viewers (fase 2).
 *
 * Solo factoriza codigo ya duplicado byte a byte en RwxViewer,
 * RwxSceneViewer, RwgViewer y WorldViewer: perspectiva, lookAt y captura
 * por glReadPixels. No cambia ningun comportamiento de renderizado ni
 * introduce tecnica nueva — el pipeline sigue siendo funcion fija
 * (glFrustum/glMultMatrixf/glReadPixels), replica fiel de RenderWare 2.
 */
final class GlUtil {
   private GlUtil() {
   }

   static void perspective(float fovYDeg, float aspect, float near, float far) {
      float fH = (float) Math.tan(Math.toRadians(fovYDeg) / 2) * near;
      float fW = fH * aspect;
      glFrustum(-fW, fW, -fH, fH, near, far);
   }

   static void lookAt(float ex, float ey, float ez, float cx, float cy, float cz,
         float ux, float uy, float uz) {
      float[] f = normalize(cx - ex, cy - ey, cz - ez);
      float[] u = normalize(ux, uy, uz);
      float[] s = normalize(f[1] * u[2] - f[2] * u[1], f[2] * u[0] - f[0] * u[2], f[0] * u[1] - f[1] * u[0]);
      float[] u2 = {s[1] * f[2] - s[2] * f[1], s[2] * f[0] - s[0] * f[2], s[0] * f[1] - s[1] * f[0]};
      try (MemoryStack stack = MemoryStack.stackPush()) {
         var m = stack.mallocFloat(16);
         m.put(0, s[0]).put(4, s[1]).put(8, s[2]).put(12, 0);
         m.put(1, u2[0]).put(5, u2[1]).put(9, u2[2]).put(13, 0);
         m.put(2, -f[0]).put(6, -f[1]).put(10, -f[2]).put(14, 0);
         m.put(3, 0).put(7, 0).put(11, 0).put(15, 1);
         glMultMatrixf(m);
         glTranslatef(-ex, -ey, -ez);
      }
   }

   static float[] normalize(float x, float y, float z) {
      float len = (float) Math.sqrt(x * x + y * y + z * z);
      if (len < 1e-8f) {
         return new float[]{0, 0, 0};
      }
      return new float[]{x / len, y / len, z / len};
   }

   static void saveScreenshot(int width, int height, String path) throws IOException {
      ByteBuffer buf = ByteBuffer.allocateDirect(width * height * 4);
      glReadPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, buf);
      BufferedImage image = new BufferedImage(width, height, BufferedImage.TYPE_INT_ARGB);
      for (int y = 0; y < height; y++) {
         for (int x = 0; x < width; x++) {
            int i = (x + (height - 1 - y) * width) * 4; // flip vertical: origen GL abajo-izquierda
            int r = buf.get(i) & 0xFF;
            int g = buf.get(i + 1) & 0xFF;
            int b = buf.get(i + 2) & 0xFF;
            image.setRGB(x, y, 0xFF000000 | (r << 16) | (g << 8) | b);
         }
      }
      ImageIO.write(image, "png", new File(path));
   }
}
