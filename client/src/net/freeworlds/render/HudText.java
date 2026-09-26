package net.freeworlds.render;

import org.lwjgl.BufferUtils;

import java.awt.Color;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.image.BufferedImage;
import java.nio.ByteBuffer;

import static org.lwjgl.opengl.GL11.*;

/**
 * Screen text for the viewer's HUD and menu, in the same fixed-function GL
 * as the rest of the viewer: the glyphs of Latin-1 (32..255, so the Spanish
 * of the menus fits) are drawn once with Java2D into an atlas texture and
 * each string is a row of textured quads. Java2D only draws into a
 * BufferedImage (no AWT window), which works headless and does not fight
 * GLFW for the main thread on macOS.
 */
final class HudText {
   private static final int FIRST = 32;
   private static final int LAST = 255;
   private static final int COLS = 16;

   private final int texture;
   private final int cellW;
   private final int cellH;
   private final int atlasW;
   private final int atlasH;
   private final int[] advance = new int[LAST + 1];
   final int lineHeight;

   HudText(int size) {
      Font font = new Font(Font.SANS_SERIF, Font.BOLD, size);
      BufferedImage probe = new BufferedImage(1, 1, BufferedImage.TYPE_INT_ARGB);
      Graphics2D pg = probe.createGraphics();
      pg.setFont(font);
      FontMetrics fm = pg.getFontMetrics();
      int maxW = 1;
      for (int c = FIRST; c <= LAST; c++) {
         advance[c] = fm.charWidth((char) c);
         maxW = Math.max(maxW, advance[c]);
      }
      cellW = maxW + 2;
      cellH = fm.getHeight() + 2;
      lineHeight = fm.getHeight();
      int ascent = fm.getAscent();
      pg.dispose();
      int rows = (LAST - FIRST + COLS) / COLS;
      atlasW = pot(cellW * COLS);
      atlasH = pot(cellH * rows);
      BufferedImage img = new BufferedImage(atlasW, atlasH, BufferedImage.TYPE_INT_ARGB);
      Graphics2D g = img.createGraphics();
      g.setRenderingHint(RenderingHints.KEY_TEXT_ANTIALIASING, RenderingHints.VALUE_TEXT_ANTIALIAS_ON);
      g.setFont(font);
      g.setColor(Color.WHITE);
      for (int c = FIRST; c <= LAST; c++) {
         int i = c - FIRST;
         g.drawString(String.valueOf((char) c), (i % COLS) * cellW + 1, (i / COLS) * cellH + 1 + ascent);
      }
      g.dispose();
      ByteBuffer buf = BufferUtils.createByteBuffer(atlasW * atlasH * 4);
      int[] argb = img.getRGB(0, 0, atlasW, atlasH, null, 0, atlasW);
      for (int p : argb) {
         buf.put((byte) 0xFF).put((byte) 0xFF).put((byte) 0xFF).put((byte) (p >>> 24));
      }
      buf.flip();
      texture = glGenTextures();
      glBindTexture(GL_TEXTURE_2D, texture);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
      glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, atlasW, atlasH, 0, GL_RGBA, GL_UNSIGNED_BYTE, buf);
      glBindTexture(GL_TEXTURE_2D, 0);
   }

   private static int pot(int n) {
      int p = 64;
      while (p < n) {
         p <<= 1;
      }
      return p;
   }

   int width(String s) {
      int w = 0;
      for (int i = 0; i < s.length(); i++) {
         char c = s.charAt(i);
         w += c >= FIRST && c <= LAST ? advance[c] : advance['?'];
      }
      return w;
   }

   /** 2D pass over the 3D frame: pixel coordinates, origin top-left. */
   static void begin(int w, int h) {
      glPushAttrib(GL_ALL_ATTRIB_BITS);
      glDisable(GL_DEPTH_TEST);
      glDisable(GL_LIGHTING);
      glDisable(org.lwjgl.opengl.GL14.GL_COLOR_SUM); // the 3D pass adds DriverLight's secondary colour
      glDisable(GL_CULL_FACE);
      glDisable(GL_FOG);
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      glMatrixMode(GL_PROJECTION);
      glPushMatrix();
      glLoadIdentity();
      glOrtho(0, w, h, 0, -1, 1);
      glMatrixMode(GL_MODELVIEW);
      glPushMatrix();
      glLoadIdentity();
   }

   static void end() {
      glMatrixMode(GL_MODELVIEW);
      glPopMatrix();
      glMatrixMode(GL_PROJECTION);
      glPopMatrix();
      glMatrixMode(GL_MODELVIEW);
      glPopAttrib();
   }

   static void rect(float x, float y, float w, float h, float r, float g, float b, float a) {
      glDisable(GL_TEXTURE_2D);
      glColor4f(r, g, b, a);
      glBegin(GL_QUADS);
      glVertex2f(x, y);
      glVertex2f(x + w, y);
      glVertex2f(x + w, y + h);
      glVertex2f(x, y + h);
      glEnd();
   }

   /** Draws s with its top-left corner at (x, y); returns the x after it. */
   float draw(float x, float y, String s, float r, float g, float b, float a) {
      glEnable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D, texture);
      glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
      glColor4f(r, g, b, a);
      glBegin(GL_QUADS);
      for (int i = 0; i < s.length(); i++) {
         char c = s.charAt(i);
         if (c < FIRST || c > LAST) {
            c = '?';
         }
         int k = c - FIRST;
         float u0 = (float) ((k % COLS) * cellW) / atlasW, v0 = (float) ((k / COLS) * cellH) / atlasH;
         float u1 = u0 + (float) cellW / atlasW, v1 = v0 + (float) cellH / atlasH;
         glTexCoord2f(u0, v0);
         glVertex2f(x, y);
         glTexCoord2f(u1, v0);
         glVertex2f(x + cellW, y);
         glTexCoord2f(u1, v1);
         glVertex2f(x + cellW, y + cellH);
         glTexCoord2f(u0, v1);
         glVertex2f(x, y + cellH);
         x += advance[c];
      }
      glEnd();
      glBindTexture(GL_TEXTURE_2D, 0);
      glDisable(GL_TEXTURE_2D);
      return x;
   }

   /** Text with a 1-pixel dark shadow, readable over any scene. */
   float drawShadowed(float x, float y, String s, float r, float g, float b) {
      draw(x + 1, y + 1, s, 0f, 0f, 0f, 0.75f);
      return draw(x, y, s, r, g, b, 1f);
   }
}
