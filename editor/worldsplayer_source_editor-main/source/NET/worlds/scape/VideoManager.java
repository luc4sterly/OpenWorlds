package NET.worlds.scape;

import java.util.Hashtable;

public class VideoManager {
   static Hashtable streams = new Hashtable();

   public static VideoSurface get(String var0, int var1, int var2, int var3) {
      Object var4 = streams.get(var0);
      VideoSurface var5;
      if (var4 == null) {
         var5 = new VideoSurface(null, var1, var2, var3);
         streams.put(var0, var5);
      } else {
         var5 = (VideoSurface)var4;
      }

      var5.incReferenceCount();
      var5.open(var0);
      return var5;
   }

   public static void release(VideoSurface var0) {
      var0.decReferenceCount();
      if (var0.getReferenceCount() == 0) {
         streams.remove(var0.getVideoUrl());
      }
   }
}
