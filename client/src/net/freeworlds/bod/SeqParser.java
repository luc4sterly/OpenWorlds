package net.freeworlds.bod;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.FileSystems;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

/**
 * Parser del formato `.seq` del cliente original (animacion articular),
 * deducido INTEGRO del C decompilado de gamma.dll (ver
 * docs/seq-animation-reference.md) y verificado byte a byte (leftover=0
 * en todo el corpus real):
 *
 * <pre>
 * u8 version (=1)                                   [FUN_00436d50]
 * u8 nJoints                                        [local_4a9]
 * string nombre de figura (u8 len + bytes)          [FUN_0042f3b0]
 * u16le K (=nº de keyframes)                        [local_3a2[0]]
 * u8[K] diccionario de deltas de tiempo             [pbVar12]
 * u16le checksum (suma de bytes del dict; se lee, no se exige)
 * nJoints x { string nombre; track quat }           [bucle local_4c8]
 * u8 nExtra; nExtra tracks anonimos (los 3 primeros modo 4,
 *   el 4o (indice 3) modo quat)                     [bucle local_299]
 * </pre>
 *
 * Track quat (sizeFlag 0x10, FUN_00437550): 4 floats base (quaternion
 * unitario verificado: norma 1.0000 en todos los joints reales) +
 * (K-1) grupos de 3 bytes con deltas empaquetados (indice 5 bits +
 * signo en codebook CB32). Tiempos = suma acumulada del diccionario
 * (monotonos verificados).
 *
 * Track modo 4: 1 float base + (K-1) bytes (indice 7 bits + signo en
 * CB32... perdon, en CB128).
 *
 * Codebooks extraidos del binario original
 * (assets/WorldsPlayer/bin/gamma.dll, offsets de fichero 0x72a40 y
 * 0x729c0; RVA Ghidra 0x475c40/0x475bc0, base 0x400000).
 */
public final class SeqParser {
   private SeqParser() {
   }

      /** Codebook de 128 deltas (modo 4). */
   public static final float[] CB128 = {
      0.0f, 0.0027069998905062675f, 0.005621000193059444f, 0.008741999976336956f, 0.012070000171661377f, 0.015604999847710133f, 0.019347000867128372f, 0.023296000435948372f,
      0.027451999485492706f, 0.031814999878406525f, 0.03638499975204468f, 0.041161999106407166f, 0.046146001666784286f, 0.051336999982595444f, 0.056735001504421234f, 0.06233999878168106f,
      0.06815200299024582f, 0.07417099922895432f, 0.08039700239896774f, 0.08682999759912491f, 0.093469999730587f, 0.10031700134277344f, 0.1073710024356842f, 0.1146320030093193f,
      0.12210000306367874f, 0.1297750025987625f, 0.13765700161457062f, 0.14574599266052246f, 0.15404200553894043f, 0.16254499554634094f, 0.17125500738620758f, 0.18017199635505676f,
      0.18929600715637207f, 0.19862699508666992f, 0.2081650048494339f, 0.2179100066423416f, 0.22786200046539307f, 0.23802100121974945f, 0.24838699400424957f, 0.2589600086212158f,
      0.2697399854660034f, 0.28072699904441833f, 0.2919209897518158f, 0.3033219873905182f, 0.3149299919605255f, 0.32674500346183777f, 0.33876699209213257f, 0.3509959876537323f,
      0.36343199014663696f, 0.37607499957084656f, 0.3889249861240387f, 0.40198200941085815f, 0.41524600982666016f, 0.4287169873714447f, 0.44239500164985657f, 0.456279993057251f,
      0.4703719913959503f, 0.4846709966659546f, 0.4991770088672638f, 0.5138900279998779f, 0.5288100242614746f, 0.5439370274543762f, 0.559270977973938f, 0.5748119950294495f,
      0.5905600190162659f, 0.6065149903297424f, 0.6226770281791687f, 0.6390460133552551f, 0.6556220054626465f, 0.6724050045013428f, 0.689395010471344f, 0.7065920233726501f,
      0.7239959836006165f, 0.7416070103645325f, 0.7594249844551086f, 0.7774500250816345f, 0.7956820130348206f, 0.8141210079193115f, 0.8327670097351074f, 0.8516200184822083f,
      0.8706799745559692f, 0.8899469971656799f, 0.9094210267066956f, 0.9291020035743713f, 0.948989987373352f, 0.9690849781036377f, 0.9893869757652283f, 1.0098960399627686f,
      1.0306119918823242f, 1.0515350103378296f, 1.0726649761199951f, 1.0940020084381104f, 1.1155459880828857f, 1.1372970342636108f, 1.159255027770996f, 1.1814199686050415f,
      1.2037919759750366f, 1.2263710498809814f, 1.2491569519042969f, 1.2721500396728516f, 1.2953499555587769f, 1.3187570571899414f, 1.3423709869384766f, 1.3661919832229614f,
      1.390220046043396f, 1.4144550561904907f, 1.4388970136642456f, 1.4635460376739502f, 1.488402009010315f, 1.5134650468826294f, 1.538735032081604f, 1.5642119646072388f,
      1.5898959636688232f, 1.6157870292663574f, 1.6418850421905518f, 1.6681900024414062f, 1.6947020292282104f, 1.7214210033416748f, 1.7483470439910889f, 1.775480031967163f,
      1.8028199672698975f, 1.8303669691085815f, 1.8581210374832153f, 1.8860820531845093f, 1.9142500162124634f, 1.9426250457763672f, 1.9712070226669312f, 1.9999959468841553f
   };
   public static final float[] CB32 = {
      0.0f, 0.0063760001212358475f, 0.016628000885248184f, 0.03075600042939186f, 0.04876000061631203f, 0.07063999772071838f, 0.09639599919319153f, 0.12602800130844116f,
      0.15953600406646729f, 0.1969199925661087f, 0.2381799966096878f, 0.2833159863948822f, 0.3323279917240143f, 0.38521599769592285f, 0.4419800043106079f, 0.5026199817657471f,
      0.5671359896659851f, 0.635528028011322f, 0.7077959775924683f, 0.7839400172233582f, 0.8639600276947021f, 0.9478560090065002f, 1.0356279611587524f, 1.1272759437561035f,
      1.2228000164031982f, 1.3221999406814575f, 1.4254759550094604f, 1.532628059387207f, 1.6436560153961182f, 1.7585599422454834f, 1.8773399591445923f, 1.9999959468841553f
   };



   /** Un track: tiempos acumulados + valores por key. Quat = 4, modo4 = 1. */
   public static final class Track {
      public final int[] times;
      public final float[][] values;
      Track(int[] t, float[][] v) {
         times = t;
         values = v;
      }
      public int keys() {
         return times.length;
      }
   }

   /** Un .seq completo: figura, joints por nombre, extras anonimos. */
   public static final class SeqData {
      public final String figure;
      public final Map<String, Track> joints = new LinkedHashMap<>();
      public final List<Track> extras = new ArrayList<>();
      SeqData(String f) {
         figure = f;
      }
   }

   private static final class Reader {
      final byte[] b;
      int p;
      Reader(byte[] b) {
         this.b = b;
      }
      int u8() {
         return b[p++] & 0xFF;
      }
      int u16() {
         int v = (b[p] & 0xFF) | ((b[p + 1] & 0xFF) << 8);
         p += 2;
         return v;
      }
      float f32() {
         int v = (b[p] & 0xFF) | ((b[p + 1] & 0xFF) << 8) | ((b[p + 2] & 0xFF) << 16) | (b[p + 3] << 24);
         p += 4;
         return Float.intBitsToFloat(v);
      }
      String string() {
         int n = u8();
         String s = new String(b, p, n, java.nio.charset.StandardCharsets.US_ASCII);
         p += n;
         return s;
      }
   }

   public static SeqData parse(byte[] data) {
      Reader r = new Reader(data);
      int ver = r.u8();
      if (ver != 1) {
         throw new IllegalArgumentException(".seq version no soportada: " + ver);
      }
      int nj = r.u8();
      SeqData out = new SeqData(r.string());
      int k = r.u16();
      if (k < 1) {
         throw new IllegalArgumentException(".seq sin keyframes");
      }
      int[] dict = new int[k];
      int cks = 0;
      for (int i = 0; i < k; i++) {
         dict[i] = r.u8();
         cks += dict[i];
      }
      r.u16(); // checksum (se lee; no se exige — sitio de validacion sin verificar)
      for (int j = 0; j < nj; j++) {
         String name = r.string();
         out.joints.put(name, readQuatTrack(r, k, dict));
      }
      int n2 = r.u8();
      for (int i = 0; i < n2; i++) {
         if (i == 3) {
            int[] times = new int[k];
            float[][] vals = new float[k][];
            readQuatInto(r, k, dict, times, vals);
            out.extras.add(new Track(times, vals));
         } else {
            out.extras.add(readFloatTrack(r, k, dict));
         }
      }
      if (r.p != data.length) {
         throw new IllegalArgumentException(".seq con " + (data.length - r.p)
            + " bytes sin consumir (formato deducido incompleto)");
      }
      return out;
   }

   private static Track readQuatTrack(Reader r, int k, int[] dict) {
      int[] times = new int[k];
      float[][] vals = new float[k][];
      readQuatInto(r, k, dict, times, vals);
      return new Track(times, vals);
   }

   /** FUN_00437550 con sizeFlag 0x10: 4 floats + (K-1)x3B empaquetados. */
   private static void readQuatInto(Reader r, int k, int[] dict, int[] times, float[][] vals) {
      float x = r.f32(), y = r.f32(), z = r.f32(), w = r.f32();
      int t = dict[0];
      times[0] = t;
      vals[0] = new float[]{x, y, z, w};
      for (int i = 1; i < k; i++) {
         t += dict[i];
         int b0 = r.u8(), b1 = r.u8(), b2 = r.u8();
         int u = b0 >> 2;
         x += ((u > 0x1f) ? -1 : 1) * CB32[u & 0x1f];
         u = ((b1 >> 4) & 0xF) + (b0 & 3) * 0x10;
         y += ((u > 0x1f) ? -1 : 1) * CB32[u & 0x1f];
         u = (b2 >> 6) + (b1 & 0xF) * 4;
         z += ((u > 0x1f) ? -1 : 1) * CB32[u & 0x1f];
         u = b2;
         w += (((u & 0x3F) > 0x1f) ? -1 : 1) * CB32[u & 0x1f];
         times[i] = t;
         vals[i] = new float[]{x, y, z, w};
      }
   }

   /** FUN_00437550 con sizeFlag 4: 1 float + (K-1)x1B. */
   private static Track readFloatTrack(Reader r, int k, int[] dict) {
      float x = r.f32();
      int t = dict[0];
      int[] times = new int[k];
      float[][] vals = new float[k][];
      times[0] = t;
      vals[0] = new float[]{x};
      for (int i = 1; i < k; i++) {
         t += dict[i];
         int b = r.u8();
         x += ((b > 0x7f) ? -1 : 1) * CB128[b & 0x7f];
         times[i] = t;
         vals[i] = new float[]{x};
      }
      return new Track(times, vals);
   }

   /** Tabla oficial tag->nombre (tools/gdk-sdk/RWXTOBOD.PL %tags, :150-183). */
   public static final String[] TAG_NAMES = {
      null, "pelvis", "back", "neck", "head", "rtsternum", "rtshoulder",
      "rtelbow", "rtwrist", "rtfingers", "lfsternum", "lfshoulder", "lfelbow",
      "lfwrist", "lffingers", "rthip", "rtknee", "rtankle", "rttoes",
      "lfhip", "lfknee", "lfankle", "lftoes", "back2", "tail", "mouth",
      "nose", "lfear", "rtear", "back3", "tail2", "tail3", "tail4",
   };

   public static String tagName(int tag) {
      return (tag >= 0 && tag < TAG_NAMES.length) ? TAG_NAMES[tag] : null;
   }

   /** Utilidad de verificacion: parsea un .seq de disco exigiendo consumo total. */
   public static SeqData parseFile(String path) throws IOException {
      Path p = FileSystems.getDefault().getPath(path);
      return parse(Files.readAllBytes(p));
   }
}
