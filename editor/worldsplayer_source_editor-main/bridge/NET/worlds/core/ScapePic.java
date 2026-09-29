package NET.worlds.core;

import java.io.IOException;
import net.openworlds.cmp.CmpFrames;

/**
 * gamma.dll's ScapePic header fields (FUN_00442750) around the frame
 * decoder: display size u16@20 / u16@22 (0 = image size), transparent
 * index 255 when mode bit 2 is set (param[6]). Pixels come from
 * formats/src/net/openworlds/cmp (CmpFrames), the verified translation of
 * gamma.dll's decoder.
 */
public final class ScapePic {
   public final CmpFrames image;
   public final int displayW;
   public final int displayH;
   public final boolean transparent;

   private ScapePic(CmpFrames image, int dw, int dh, boolean transparent) {
      this.image = image;
      this.displayW = dw;
      this.displayH = dh;
      this.transparent = transparent;
   }

   public static ScapePic read(byte[] file, int maxFrames) throws IOException {
      CmpFrames img = CmpFrames.decode(file, maxFrames);
      int dw = (file[20] & 0xFF) | (file[21] & 0xFF) << 8;
      int dh = (file[22] & 0xFF) | (file[23] & 0xFF) << 8;
      return new ScapePic(img, dw == 0 ? img.width : dw, dh == 0 ? img.height : dh, (file[4] & 0x04) != 0);
   }
}
