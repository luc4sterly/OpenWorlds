package net.freeworlds.render;

import net.freeworlds.cmp.CmpTexture;
import net.freeworlds.bod.BodClump;
import net.freeworlds.bod.BodFile;
import net.freeworlds.bod.BodParser;
import net.freeworlds.bod.BodVertex;
import net.freeworlds.rwx.RwxMaterial;
import net.freeworlds.rwx.RwxModel;
import net.freeworlds.rwx.RwxParser;
import net.freeworlds.rwx.RwxVector3;
import net.freeworlds.world.MaterialTiles;
import net.freeworlds.world.PortalLink;
import net.freeworlds.world.TextureActions;
import net.freeworlds.world.WNode;
import net.freeworlds.world.WorldRestorer;

import org.lwjgl.glfw.GLFWErrorCallback;
import org.lwjgl.opengl.GL;
import org.lwjgl.system.MemoryStack;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.nio.ByteBuffer;
import java.nio.FloatBuffer;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.Enumeration;
import java.util.HashMap;
import java.util.HashSet;
import java.util.IdentityHashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

import static org.lwjgl.glfw.GLFW.*;
import static org.lwjgl.opengl.GL11.*;

/**
 * Loads a real .world file (WorldRestorer), picks one room, and renders
 * every real placed object in it using the exact same lit fixed-function
 * pipeline as RwxViewer/RwxSceneViewer - the point of this session: a
 * real .world positions and draws its own objects, not a handful placed
 * by hand. Geometry URLs ("tex/frame.rwx") are resolved relative to the
 * .world file's own directory (verified in docs/world-format-reference.md
 * against real content in assets/WorldsPlayer/GroundZero/tex/). Each
 * WObject's real 16-float transform matrix (see WNode.matrix) is applied
 * via the GL matrix stack, so the scene graph's own nesting (Room ->
 * RoomEnvironment -> ... -> Shape) composes transforms exactly like the
 * real client's scene graph would - no manual matrix math, no invented
 * layout.
 *
 * Avatares (2026-09-13): las referencias "avatar:Nombre.rwg"
 * (6 en GroundZero, todas en las galerias IconViewRoom1a/b/c/e/f/g)
 * SI se dibujan, en bind pose con el mismo pipeline fijo de 2 luces.
 * Resolucion real por nombre: "avatar:Roxanne.rwg" -> el .bod oficial
 * del mismo nombre en assets/gammatutorial-samples/base-avatars/
 * (jing/julie/paul/roxanne/simon existen ahi; Tre no existe y usa
 * aura.bod, el default real del cliente segun
 * PosableShape.defaultURL="avatar:aura.0PG.rwg"). Escala: los .bod
 * decodifican a ~0.17 unidades de alto y el cliente espera avatares de
 * ~189 (Drone.java avatarHeightChangedTo(189.0F)), asi que se aplica un
 * factor global x1000 documentado como heuristica (las proporciones,
 * colores por clump y colocacion por nodo son datos reales; solo la
 * escala absoluta es normalizada). Los pies quedan en el origen del
 * nodo y el eje +Y del .bod (up, verificado en BodViewer) se mapea a
 * +Z (el cliente es Z-up). Sin skinning/animacion: bind pose.
 *
 * Infinite background (see drawInfiniteBackground): the room's exterior
 * shell is drawn in its own pass with its own camera: positioned at the
 * shell's local origin (0,0,0) with the live camera's orientation — the
 * documented client behavior (Gamma_Procedures.html, "Infinite
 * Backgrounds": "the Infinite Background is viewed from a Camera at
 * 0,0,0"; authors center the shell on the origin via the grouping
 * WObject, verified: Reception's 33 Rects span x[-2100,700] y[-1000,
 * 1200], i.e. containing the origin). The room itself is drawn in a
 * second pass with the live camera. Consequence, honestamente: el fondo
 * no tiene paralaje de traslacion (escala "que nunca parece cambiar",
 * Gamma_Overview) — al caminar se nota fijo/pegado en los muros
 * cercanos porque el anillo esta modelado a medida de la sala; eso es
 * lo que el cliente original hace, no un efecto del visor.
 *
 * Textures (2026-09-11): each material's real "Texture" reference is
 * resolved against the scene's own real texture archive (content.zip,
 * sitting next to the .world file in the real install - see
 * resolveTextureArchive) and decoded through the verified net.freeworlds.
 * cmp pipeline (CmpTexture, backed by Stage2 + - once available - Stage1).
 * No invented pixels: a material whose texture can't be decoded (Stage 1
 * not implemented for it yet, a .bmp-named reference with no loader, or
 * genuinely missing from the archive) keeps its real parsed flat color
 * instead, and is counted/reported, never silently guessed. See
 * resolveTexture()'s javadoc for the exact fallback accounting.
 *
 * Usage: java -cp ... net.freeworlds.render.WorldViewer <file.world> <roomName> [--screenshot out.png] [--window]
 *        java -cp ... net.freeworlds.render.WorldViewer <file.world> ALL [--screenshot-dir outdir]
 *        java -cp ... net.freeworlds.render.WorldViewer <file.world> --list-rooms
 *        java -cp ... net.freeworlds.render.WorldViewer <file.world> --list-portals
 *
 * --window opens a real visible, interactive window for the room (ESC or
 * close button exits; slow auto-rotation while open). Without it the
 * window stays hidden (offscreen/Xvfb-friendly) and --screenshot saves a
 * single frame and exits. --window can be combined with --screenshot to
 * save the first frame and keep the window open afterwards.
 *
 * --fullscreen takes over the primary monitor (implies --window): for
 * sessions where another maximized app covers everything and the window
 * would otherwise render unseen behind it.
 *
 * --inside switches from the exterior orbit camera (a maquette view of
 * the whole room bounding box) to an interior fly camera placed INSIDE
 * the room itself: W/S fly forward/back, A/D strafe, arrows turn
 * (Left/Right) and pitch (Up/Down), E/Q up/down, ESC exits. Implies
 * --window unless --screenshot is given (then frame 0 is saved
 * headless for verification, same as the exterior batch mode).
 * --eye/--look/--up override the default interior viewpoint
 * (which is derived from the room's real bounding box, see renderRoom).
 *
 * Infinite background (see drawInfiniteBackground): the room's exterior
 * shell is drawn in its own pass with its own camera (see above) —
 * static authored placement, never translated to follow the live
 * camera position.
 */
public final class WorldViewer {
   private static final Map<String, RwxModel> modelCache = new HashMap<>();
   // Display list por modelo unico (clave = instancia de modelCache).
   // Optimizacion de rendimiento period-correct (listas de OpenGL 1.x,
   // la tecnica de la epoca de RenderWare 2): captura la MISMA secuencia
   // glMaterial/glNormal/glVertex que el modo inmediato, pixel-identica,
   // compilada una vez y re-ejecutada por instancia. Valida solo dentro
   // del contexto GL actual — se limpia al crear/destruir cada ventana
   // (modo ALL crea un contexto por sala).
   private static final Map<RwxModel, Integer> displayListCache = new HashMap<>();
    private static File baseDir;
    private static int loadedCount = 0;
    private static int missingCount = 0;
    private static int avatarSkipCount = 0; // refs "avatar:" sin .bod resoluble (no deberia pasar: hay fallback a aura)
    private static int avatarDrawnCount = 0; // refs "avatar:" dibujadas este frame (incluye fallback)
    private static int avatarFallbackCount = 0; // de ellas, cuantas usan aura.bod por defecto
    private static int rectCount = 0; // Rect surfaces placed (drawn as textured quads, see drawRect)
    private static int rectPatchCount = 0; // RectPatch heightfields placed (see drawRectPatch)

   // --- Texturing (real, per-material, see class javadoc) ---
   // GL texture ids are only valid within the GL context that created them
   // (a new context per room in ALL mode - same reason displayListCache is
   // cleared there), so this cache is cleared alongside it.
   private static final Map<String, Integer> glTextureCache = new HashMap<>();
   // Extracted once per baseDir (content.zip's real tex/*.cmp files, see
   // resolveTextureArchive) - NOT committed to git, a runtime-only cache.
   private static File textureArchiveDir;
   private static boolean textureArchiveChecked = false;
   // Real per-material texture-reference accounting across the whole run
   // (persists across rooms in ALL mode) - the honest coverage evidence
   // the session asked for, never rounded up.
    private static final Set<String> texturesResolved = new TreeSet<>();
    private static final Map<String, String> texturesUnresolved = new TreeMap<>(); // name -> reason
    private static int materialTextureRefs = 0; // total non-null Texture directives seen (incl. repeats)
    // Same accounting, separately, for Rect surface materials (absolute
    // dtex/*.cmp URLs + relative tex/* URLs, .mov por celdas: MaterialTiles).
    private static final Set<String> rectTexturesResolved = new TreeSet<>();
    private static final Map<String, String> rectTexturesUnresolved = new TreeMap<>();
    private static int rectTextureRefs = 0;

    // --- Avatares .bod (bind pose, ver javadoc de clase) ---
    // Escala mundo real: Drone.java avatarHeightChangedTo(189.0F) = altura
    // default de avatar en unidades mundo; los .bod decodifican a ~0.17
    // (jing.bod: bbox y [-1.68,-1.51] medida con el propio BodViewer) asi
    // que x1000 los deja en ~170-200, proporcion humana en salas de ~250
    // de alto. HEURISTICA DOCUMENTADA (mismo nivel que el ambient 0.15
    // de GlLighting): proporciones/colores/colocacion reales, escala
    // absoluta normalizada.
    private static final float BOD_WORLD_SCALE = 1000f;
    /** Un triangulo ya ensamblado en coords locales .bod (Y-up). */
    private static final class BodTri {
       float ax, ay, az, bx, by, bz, cx, cy, cz;
       float r, g, b;
    }
    /** Avatar ensamblado una vez por archivo .bod (bind pose). */
    private static final class BodAvatar {
       final List<BodTri> tris = new ArrayList<>();
       // bbox local (Y-up, sin rebasear): para rebasear pies a origen.
       float minX = Float.MAX_VALUE, minY = Float.MAX_VALUE, minZ = Float.MAX_VALUE;
       float maxX = -Float.MAX_VALUE, maxY = -Float.MAX_VALUE, maxZ = -Float.MAX_VALUE;
       boolean usedFallback; // este slot usa aura.bod por defecto
       String sourceName; // archivo .bod realmente usado (para el reporte)
    }
    private static final Map<String, BodAvatar> bodCache = new HashMap<>();
    private static File avatarDir;
    private static boolean avatarDirChecked = false;

    // --- Portales (--play): conectividad real y transformacion entre
    // salas, ver javadoc de crossPortal(). worldRoot + los dos mapas se
    // llenan una sola vez en main() (collectPortalMatrices), antes de
    // entrar a renderRoom - son estaticos para que el cruce de un
    // portal (dentro del loop de renderRoom) pueda resolver la sala
    // destino y la matriz-mundo real del portal lejano sin re-parsear
    // ni re-recorrer el arbol por sala cada vez.
    private static WNode worldRoot;
    /** Portal WNode -> su matriz local-a-sala acumulada (NO local-a-mundo:
     * cada Room es su propio espacio de coordenadas, como ya hace
     * collectPlayfield/preload por sala - ver Portal.getPosition()
     * devolviendo coords de la propia sala, no de un "mundo" global). */
    private static final Map<WNode, float[]> portalRoomMatrix = new IdentityHashMap<>();
    /** Portal WNode -> nombre de la sala que lo contiene (clave de
     * world.roomsByName), para resolver a que WNode de sala saltar tras
     * cruzar un portal conectado por referencia de objeto. */
    private static final Map<WNode, String> portalOwnerRoom = new IdentityHashMap<>();

    /** Texturas animadas por acciones (StartupSensor -> AnimateAction...),
     * ver TextureActions; se crea en main() tras parsear el mundo. */
    private static TextureActions textureActions;

      public static void main(String[] args) throws Exception {
         if (args.length < 2) {
            System.err.println("Usage: WorldViewer <file.world> <roomName|ALL|--list-rooms|--list-portals> [--screenshot out.png] [--screenshot-dir outdir] [--window] [--fullscreen] [--inside] [--play] [--eye x,y,z] [--look x,y,z] [--up x,y,z]");
            System.exit(2);
         }
         File worldFile = new File(args[0]);
         String roomArg = args[1];
         String screenshotPath = null;
         String screenshotDir = null;
         boolean windowed = false;
         boolean inside = false;
         boolean play = false;
         boolean fullscreen = false;
       float[] eyeArg = null, lookArg = null, upArg = null;
       // --spawn/--walk-to/--screenshot-before/--screenshot-after: solo
       // para el arnes headless de verificacion de portales (ver
       // PortalCrossHarness) - anaden un modo no-interactivo a --play sin
       // tocar el camino interactivo existente (WASD real, ver el loop).
       float[] spawnArg = null; // x,y,z,yawDeg
       float[] walkToArg = null; // x,y (autopiloto de paso fijo hacia el objetivo)
       String screenshotBeforePath = null;
       String screenshotAfterPath = null;
       for (int i = 2; i < args.length; i++) {
          if (args[i].equals("--screenshot") && i + 1 < args.length) {
             screenshotPath = args[++i];
          } else if (args[i].equals("--screenshot-dir") && i + 1 < args.length) {
             screenshotDir = args[++i];
           } else if (args[i].equals("--window")) {
              windowed = true;
           } else if (args[i].equals("--fullscreen")) {
              fullscreen = true;
              windowed = true; // fullscreen es una ventana visible interactiva
            } else if (args[i].equals("--inside")) {
               inside = true;
           } else if (args[i].equals("--play")) {
              // Modo juego (tercera persona): implica camara interior +
              // ventana, spawn en RestartAt, avatar del jugador, suelo y
              // colision. Ver javadoc de clase y renderRoom.
              play = true;
              inside = true;
           } else if (args[i].equals("--eye") && i + 1 < args.length) {
             eyeArg = parseVec(args[++i], "--eye");
          } else if (args[i].equals("--look") && i + 1 < args.length) {
             lookArg = parseVec(args[++i], "--look");
          } else if (args[i].equals("--up") && i + 1 < args.length) {
             upArg = parseVec(args[++i], "--up");
          } else if (args[i].equals("--spawn") && i + 1 < args.length) {
             spawnArg = parseVec4(args[++i], "--spawn");
          } else if (args[i].equals("--walk-to") && i + 1 < args.length) {
             walkToArg = parseVec2(args[++i], "--walk-to");
          } else if (args[i].equals("--screenshot-before") && i + 1 < args.length) {
             screenshotBeforePath = args[++i];
          } else if (args[i].equals("--screenshot-after") && i + 1 < args.length) {
             screenshotAfterPath = args[++i];
          }
       }
       if (inside && screenshotPath == null && walkToArg == null) {
          windowed = true; // interior interactivo necesita ventana visible (el autopiloto headless no)
       }

        baseDir = worldFile.getParentFile();
        byte[] data = Files.readAllBytes(worldFile.toPath());
        WNode world = WorldRestorer.parse(data);
        worldRoot = world;
        collectPortalMatrices(world);
        textureActions = new TextureActions(world);

        if (roomArg.equals("--list-portals") || java.util.Arrays.asList(args).contains("--list-portals")) {
           listPortals(world);
           return;
        }
        // --list-rooms vale en cualquier posición (no solo como sala):
        // evita abrir una ventana bloqueante por un orden de args distinto.
        if (roomArg.equals("--list-rooms") || java.util.Arrays.asList(args).contains("--list-rooms")) {
          java.util.List<String> names = new java.util.ArrayList<>(world.roomsByName.keySet());
          java.util.Collections.sort(names);
          for (String n : names) {
             System.out.println(n);
          }
          return;
       }

       java.util.List<String> rooms;
       if (roomArg.equals("ALL")) {
          rooms = new java.util.ArrayList<>(world.roomsByName.keySet());
          java.util.Collections.sort(rooms);
          if (screenshotDir != null) {
             new File(screenshotDir).mkdirs();
          }
       } else {
          rooms = java.util.Collections.singletonList(roomArg);
          if (screenshotDir != null) {
             System.err.println("--screenshot-dir only applies with ALL; ignoring");
             screenshotDir = null;
          }
       }

       boolean first = true;
       for (String roomName : rooms) {
          WNode room = world.roomsByName.get(roomName);
          if (room == null) {
             System.err.println("Room \"" + roomName + "\" not found. Available: " + world.roomsByName.keySet());
             if (!roomArg.equals("ALL")) {
                System.exit(1);
             }
             continue;
          }
          String out = screenshotPath;
          if (roomArg.equals("ALL") && screenshotDir != null) {
             out = new File(screenshotDir, "world_" + roomName + ".png").getPath();
          } else if (roomArg.equals("ALL")) {
             out = null; // sin capturas: solo estadisticas por sala
          }
          if (!first) {
             System.out.println("---");
          }
          first = false;
            renderRoom(room, roomName, out, windowed, inside, eyeArg, lookArg, upArg, fullscreen, play,
               spawnArg, walkToArg, screenshotBeforePath, screenshotAfterPath);
       }
       printTextureCoverage();
    }

    /** Parses "x,y,z" (floats, world units) for --eye/--look/--up. */
    private static float[] parseVec(String s, String flag) {
       String[] p = s.split(",");
       if (p.length != 3) {
          System.err.println(flag + " needs x,y,z (got \"" + s + "\")");
          System.exit(2);
       }
       try {
          return new float[]{Float.parseFloat(p[0]), Float.parseFloat(p[1]), Float.parseFloat(p[2])};
       } catch (NumberFormatException e) {
          System.err.println(flag + " needs numeric x,y,z (got \"" + s + "\")");
          System.exit(2);
          return null;
       }
    }

    /** Parses "x,y,z,yawDeg" for --spawn (arnes headless, ver crossPortal/PortalCrossHarness). */
    private static float[] parseVec4(String s, String flag) {
       String[] p = s.split(",");
       if (p.length != 4) {
          System.err.println(flag + " needs x,y,z,yawDeg (got \"" + s + "\")");
          System.exit(2);
       }
       try {
          return new float[]{Float.parseFloat(p[0]), Float.parseFloat(p[1]), Float.parseFloat(p[2]), Float.parseFloat(p[3])};
       } catch (NumberFormatException e) {
          System.err.println(flag + " needs numeric x,y,z,yawDeg (got \"" + s + "\")");
          System.exit(2);
          return null;
       }
    }

    /** Parses "x,y" for --walk-to (arnes headless). */
    private static float[] parseVec2(String s, String flag) {
       String[] p = s.split(",");
       if (p.length != 2) {
          System.err.println(flag + " needs x,y (got \"" + s + "\")");
          System.exit(2);
       }
       try {
          return new float[]{Float.parseFloat(p[0]), Float.parseFloat(p[1])};
       } catch (NumberFormatException e) {
          System.err.println(flag + " needs numeric x,y (got \"" + s + "\")");
          System.exit(2);
          return null;
       }
    }

    /** Real, honest coverage accounting across every room rendered this run
     * - never rounded up, see resolveTexture()'s javadoc for what counts as
     * "resolved" vs "unresolved" and why. */
    private static void printTextureCoverage() {
       int totalNames = texturesResolved.size() + texturesUnresolved.size();
       System.out.println("---");
       System.out.println("Texture coverage: " + texturesResolved.size() + "/" + totalNames
          + " unique texture names decoded (" + materialTextureRefs + " total material references seen)");
        if (!texturesUnresolved.isEmpty()) {
           System.out.println("Unresolved (real color fallback, no invented texture):");
           for (Map.Entry<String, String> e : texturesUnresolved.entrySet()) {
              System.out.println("  " + e.getKey() + ": " + e.getValue());
           }
        }
        int rectTotal = rectTexturesResolved.size() + rectTexturesUnresolved.size();
        System.out.println("Rect coverage: " + rectTexturesResolved.size() + "/" + rectTotal
           + " unique rect texture URLs decoded (" + rectTextureRefs + " total rect references seen)");
        if (!rectTexturesUnresolved.isEmpty()) {
           System.out.println("Unresolved rects (flat color fallback):");
           for (Map.Entry<String, String> e : rectTexturesUnresolved.entrySet()) {
              System.out.println("  " + e.getKey() + ": " + e.getValue());
           }
        }
    }

     private static void renderRoom(WNode room, String roomName, String screenshotPath, boolean visible,
            boolean inside, float[] eyeArg, float[] lookArg, float[] upArg, boolean fullscreen, boolean play,
            float[] spawnArg, float[] walkToArg, String screenshotBeforePath, String screenshotAfterPath) throws Exception {
       drawnTriangles = 0;
       drawnObjects = 0;
       avatarDrawnCount = 0;
       avatarFallbackCount = 0;

       // Pre-load all geometry referenced in this room so we can report
       // real counts before opening a window (and compute a scene bounding
       // box from REAL loaded vertex data, not a guess).
       // Estado del jugador (modo --play): pies en el mundo, yaw de facing.
       // Spawn real del cliente: worlds.ini RestartAt =
       // GroundZero.world#Reception<>@1872,1229,150,125,... El yaw 125 del
       // .ini admite dos signos (ver run-game.sh): aqui se mira al kiosko
       // (1290,865) igual que el default sin args, yaw=atan2(-364,-582).
       // --spawn (solo arnes headless) sobreescribe px/py/pz/yaw abajo,
       // tras fijar pitch=0 - ver el bloque "if (inside)" mas adelante.
       float px = 1872f, py = 1229f, pz = 150f;
       float[] bbox = {Float.MAX_VALUE, Float.MAX_VALUE, Float.MAX_VALUE, -Float.MAX_VALUE, -Float.MAX_VALUE, -Float.MAX_VALUE};
       int[] objectCount = {0};
       int loadedBefore = loadedCount;
       int missingBefore = missingCount;
       int avatarBefore = avatarSkipCount;
       int rectBefore = rectCount;
       int rectPatchBefore = rectPatchCount;
       preload(room, identity(), bbox, objectCount);
       // Room shell lives in environment (walls/floors/ceilings missed for
       // 6 sessions); avatars (.bod) now preload too (feet bbox included).
       if (room.environment != null) {
          preload(room.environment, identity(), bbox, objectCount);
       }
       // Bbox SOLO del fondo (para el frustum de su propia pasada; el
       // fondo nunca entra en el bbox de la sala ni en su camara).
       float[] bgBbox = null;
       if (room.infiniteBackground != null) {
          bgBbox = new float[]{Float.MAX_VALUE, Float.MAX_VALUE, Float.MAX_VALUE, -Float.MAX_VALUE, -Float.MAX_VALUE, -Float.MAX_VALUE};
          int[] bgCount = {0};
          preloadBg(room.infiniteBackground, identity(), bgBbox, bgCount);
          if (bgCount[0] == 0) {
             bgBbox = null; // fondo vacio (23/25 en GroundZero): sin pasada propia
          }
       }
       // Terreno jugable (modo --play): suelos = Rect/RectPatch visibles
       // (piso = Room.floorHeight del original: el mas alto <= z); muros =
       // Rects no-piso + bumpers invisibles (*Bump, flags bit0=0);
       // portales = nodos .Portal reales (con conectividad resuelta via
       // portalFarSidePortal - ver crossPortal). El fondo infinito es
       // backdrop, no pisable.
       List<float[][]> floorQuads = new ArrayList<>();
       List<float[]> blockerBoxes = new ArrayList<>();
       // Triangulos de props (.rwx/.rwg, coords mundo, 9 floats): el
       // mobiliario tambien es suelo y tambien estorba. Se recogen aqui
       // (modelos ya en cache por preload) en vez de re-leer disco.
       List<float[]> propTris = new ArrayList<>();
       List<WNode> portalNodes = new ArrayList<>();
       List<float[][]> portalQuads = new ArrayList<>();
       if (play) {
          collectPlayfield(room, identity(), floorQuads, blockerBoxes, propTris, portalNodes, portalQuads);
          if (room.environment != null) {
             collectPlayfield(room.environment, identity(), floorQuads, blockerBoxes, propTris, portalNodes, portalQuads);
          }
          pz = floorHeightAt(floorQuads, propTris, px, py, pz);
          System.out.println("Playfield: " + floorQuads.size() + " floor quads, "
             + propTris.size() + " prop tris, "
             + blockerBoxes.size() + " blockers, " + portalNodes.size() + " portals");
          if (hitsBlocker(blockerBoxes, px, py, pz)) {
             System.out.println("WARNING: el spawn (" + px + "," + py + "," + pz + ") nace dentro de un bloqueante");
          }
       }
       System.out.println("Room \"" + roomName + "\": " + objectCount[0] + " objects placed, "
          + (loadedCount - loadedBefore) + " real geometry files loaded, " + (missingCount - missingBefore) + " missing on disk, "
          + (avatarSkipCount - avatarBefore) + " avatar: refs unresolved (fallback covers the rest - see class javadoc), "
          + (rectCount - rectBefore) + " Rect surfaces (incl. environment), "
          + (rectPatchCount - rectPatchBefore) + " RectPatch heightfields"
          + (bgBbox != null ? ", infiniteBackground present" : ", infiniteBackground empty")); 
      float radius = Math.max(0.01f, distance(bbox));
      float cx = (bbox[0] + bbox[3]) / 2f;
      float cy = (bbox[1] + bbox[4]) / 2f;
      float cz = (bbox[2] + bbox[5]) / 2f;
      System.out.println("Scene bounding box (real, from loaded geometry): "
         + "[" + bbox[0] + "," + bbox[1] + "," + bbox[2] + "] to [" + bbox[3] + "," + bbox[4] + "," + bbox[5] + "]");

      GLFWErrorCallback.createPrint(System.err).set();
      GlUtil.forceX11OnLinux();
      if (!glfwInit()) {
         throw new IllegalStateException("GLFW init failed");
      }
      glfwDefaultWindowHints();
      glfwWindowHint(GLFW_VISIBLE, visible ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

      int width = 1024;
      int height = 768;
      long window = glfwCreateWindow(width, height, "FreeWorlds World Viewer - " + roomName, 0, 0);
      if (window == 0) {
         throw new IllegalStateException("Failed to create GLFW window");
      }
      glfwMakeContextCurrent(window);
      glfwSwapInterval(1);
      GL.createCapabilities();
       if (visible) {
          glfwShowWindow(window);
          if (fullscreen) {
             // Pantalla completa real en el monitor primario: para sesiones
             // donde otra app maximizada tapa todo (el usuario no ve la
             // ventana aunque renderice bien). Solo si hay monitor (en
             // Xvfb headless puede no haberlo: entonces se queda en ventana).
             long monitor = glfwGetPrimaryMonitor();
             if (monitor != 0) {
                org.lwjgl.glfw.GLFWVidMode mode = glfwGetVideoMode(monitor);
                glfwSetWindowMonitor(window, monitor, 0, 0, mode.width(), mode.height(), mode.refreshRate());
                width = mode.width();
                height = mode.height();
             }
          }
          // Traer al frente en el escritorio del usuario: sin esto, en
          // sesiones con varias áreas de trabajo la ventana puede abrirse
          // en otra (el usuario no la ve aunque esté renderizando bien).
          glfwFocusWindow(window);
          glfwRequestWindowAttention(window);
         // ESC or window close button exits the interactive viewer.
         glfwSetKeyCallback(window, (win, key, scancode, action, mods) -> {
            if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
               glfwSetWindowShouldClose(win, true);
            }
         });
      }
      displayListCache.clear(); // IDs del contexto anterior (modo ALL) no valen aqui
      glTextureCache.clear(); // GL texture ids: mismo motivo, otro contexto

      glEnable(GL_DEPTH_TEST);
      glClearColor(0.10f, 0.10f, 0.14f, 1f);
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      GlLighting.init();

      float angle = 30f;
      // Interior fly camera state (only used with --inside): eye/look
      // either explicit (--eye/--look) or derived from the room's real
      // bounding box (inside it, looking at its center). The client's own
      // convention is Z-up (Transform.raise = +Z, yaw spins about Z —
      // verified in editor/.../scape/Transform.java), so that is the
      // default; --up 0,1,0 keeps the legacy Y-up math.
       float[] eye = null, up = null;
       float yaw = 0f, pitch = 0f;
      boolean upZ = true;
      if (inside) {
         up = upArg != null ? upArg.clone() : new float[]{0, 0, 1};
         upZ = up[2] > 0.9f;
         if (play) {
            yaw = (float) Math.atan2(865f - 1229f, 1290f - 1872f);
            pitch = 0f;
            System.out.println("Play mode: spawn Reception (1872,1229,150) facing kiosk, yaw=" + yaw
               + " avatar=aura.bod (default real del cliente)");
            if (spawnArg != null) {
               // Solo arnes headless (PortalCrossHarness): posiciona al
               // jugador en una sala/posicion arbitraria para capturar
               // screenshots antes/despues de un cruce real, sin tocar el
               // spawn real (RestartAt) usado por defecto.
               px = spawnArg[0];
               py = spawnArg[1];
               pz = spawnArg[2];
               yaw = (float) Math.toRadians(spawnArg[3]);
               System.out.println("--spawn: override a (" + px + "," + py + "," + pz + ") yaw=" + spawnArg[3] + "deg");
            }
         } else {
         float[] look;
         if (eyeArg != null && lookArg != null) {
            eye = eyeArg.clone();
            look = lookArg.clone();
         } else if (upZ) {
            eye = new float[]{cx + radius * 0.3f, cy + radius * 0.3f, cz + radius * 0.12f};
            look = new float[]{cx, cy, cz};
         } else {
            eye = new float[]{cx + radius * 0.3f, cy + radius * 0.12f, cz + radius * 0.3f};
            look = new float[]{cx, cy, cz};
         }
         float[] d = norm(new float[]{look[0] - eye[0], look[1] - eye[1], look[2] - eye[2]});
         if (upZ) {
            pitch = (float) Math.asin(clamp(d[2], -1f, 1f));
            yaw = (float) Math.atan2(d[1], d[0]);
         } else {
            pitch = (float) Math.asin(clamp(d[1], -1f, 1f));
            yaw = (float) Math.atan2(d[0], -d[2]);
         }
          System.out.println("Interior camera: eye=(" + eye[0] + "," + eye[1] + "," + eye[2] + ") yaw=" + yaw
             + " pitch=" + pitch + " up=(" + up[0] + "," + up[1] + "," + up[2] + ")");
         }
          if (visible) {
             if (play) {
                System.out.println("Controls (play): W/S walk, A/D strafe, arrows turn/pitch camera, ESC exits");
             } else {
                System.out.println("Controls: W/S fly, A/D strafe, arrows turn/pitch, E/Q up/down, ESC exits");
             }
          }
      }
      // Hidden/offscreen mode: exactly 1 frame when a screenshot is asked
      // for (batch/ALL use), infinite only if a human is expected to look
      // at nothing (legacy behaviour, kept). Visible --window mode: run
      // interactively until ESC/close; if --screenshot is also given, save
      // frame 0 and keep the window open afterwards.
      int frames;
      if (visible || walkToArg != null) {
         // walkToArg (arnes headless): necesita muchos ticks para caminar
         // una sala real - el propio autopiloto corta el loop (ver
         // autopilotDone) al cruzar un portal o al agotar su presupuesto.
         frames = Integer.MAX_VALUE;
      } else {
         frames = screenshotPath != null ? 1 : Integer.MAX_VALUE;
      }
      boolean autopilotDone = false;
      int autopilotTicks = 0;
      double lastTime = glfwGetTime();
      // Frustum de la pasada de fondo (una vez por sala): cubre la
      // cascara vista desde el origen con margen x2.
      float bgNear = 1f, bgFar = 10000f;
      float bgCx = 0f, bgCy = 0f, bgCz = 0f;
      if (bgBbox != null) {
         bgCx = (bgBbox[0] + bgBbox[3]) / 2f;
         bgCy = (bgBbox[1] + bgBbox[4]) / 2f;
         bgCz = (bgBbox[2] + bgBbox[5]) / 2f;
         float bgR = distance(bgBbox) / 2f;
         float bgDist = (float) Math.sqrt(bgCx * bgCx + bgCy * bgCy + bgCz * bgCz);
         bgFar = (bgDist + bgR) * 2f + radius;
      }
      for (int frame = 0; frame < frames && !glfwWindowShouldClose(window); frame++) {
         double now = glfwGetTime();
         // Primer FrameEvent de la sala: StartupSensor (una vez); luego
         // cada frame las acciones vivas (RunningActionHandler.handle).
         if (frame == 0) {
            startRoomActions(room, roomName, (long) (now * 1000.0));
         }
         textureActions.tick((long) (now * 1000.0));
         float dt = (float) Math.min(0.1, Math.max(1e-3, now - lastTime));
         lastTime = now;
         // Contadores POR FRAME (antes acumulaban toda la sesion y el
         // resumen final mentia: "272 avatars" = 1 avatar x 272 frames).
         drawnTriangles = 0;
         drawnObjects = 0;
         avatarDrawnCount = 0;
         avatarFallbackCount = 0;
         boolean crossedThisFrame = false;
         // autopilot: solo PortalCrossHarness (arnes headless, --walk-to)
         // - paso fijo por tick (no atado a dt real, determinista incluso
         // sin vsync/ventana), gira a mirar hacia el objetivo, y usa el
         // MISMO camino de colision/suelo/cruce que el WASD real de abajo
         // (nada especial para el arnes: si el cruce funciona aqui,
         // funciona igual con teclado real). Se para solo tras el primer
         // cruce (autopilotDone) o al agotar su presupuesto de ticks.
         boolean autopilot = play && walkToArg != null;
         if (play && (visible || autopilot) && !(autopilot && autopilotDone)) {
            float dx = 0f, dy = 0f;
            if (!autopilot) {
               // Modo juego: arcade como SmoothDriver del original (fuerzas
               // con damping -> aqui velocidad constante honesta y simple):
               // flechas L/R giran, W/S caminan sobre el plano, A/D strafe,
               // sin volar (E/Q no hacen nada). Movimiento por ejes con slide
               // contra bloqueantes; pies pegados al suelo (Room.floorHeight:
               // el original tampoco tiene caida libre global).
               float turn = (float) Math.toRadians(60) * dt;
               if (isDown(window, GLFW_KEY_LEFT)) yaw -= turn;
               if (isDown(window, GLFW_KEY_RIGHT)) yaw += turn;
               if (isDown(window, GLFW_KEY_UP)) pitch = Math.min(1.55f, pitch + turn);
               if (isDown(window, GLFW_KEY_DOWN)) pitch = Math.max(-1.55f, pitch - turn);
               float fx = (float) Math.cos(yaw), fy = (float) Math.sin(yaw);
               float rx = -fy, ry = fx;
               float step = PLAY_WALK_SPEED * dt;
               if (isDown(window, GLFW_KEY_W)) { dx += fx * step; dy += fy * step; }
               if (isDown(window, GLFW_KEY_S)) { dx -= fx * step; dy -= fy * step; }
               if (isDown(window, GLFW_KEY_D)) { dx += rx * step; dy += ry * step; }
               if (isDown(window, GLFW_KEY_A)) { dx -= rx * step; dy -= ry * step; }
            } else {
               autopilotTicks++;
               float tdx = walkToArg[0] - px, tdy = walkToArg[1] - py;
               float dist = (float) Math.sqrt(tdx * tdx + tdy * tdy);
               if (dist > 1f) {
                  float aStep = Math.min(20f, dist); // paso fijo, no dt (ver comentario de arriba)
                  dx = tdx / dist * aStep;
                  dy = tdy / dist * aStep;
                  yaw = (float) Math.atan2(tdy, tdx); // caminar mirando al objetivo
               }
               if (autopilotTicks > 3000) {
                  System.out.println("PortalCrossHarness: autopiloto agoto su presupuesto (3000 ticks) "
                     + "sin cruzar ningun portal hacia (" + walkToArg[0] + "," + walkToArg[1] + ") - "
                     + "posicion final (" + px + "," + py + "," + pz + ")");
                  autopilotDone = true;
               }
            }
            if (dx != 0f || dy != 0f) {
               float p0x = px, p0y = py, p0z = pz;
               boolean movedX = false, movedY = false;
               float nx = px + dx;
               if (!hitsBlocker(blockerBoxes, nx, py, pz)) {
                  px = nx;
                  movedX = true;
               }
               float ny = py + dy;
               if (!hitsBlocker(blockerBoxes, px, ny, pz)) {
                  py = ny;
                  movedY = true;
               }
               // Sin snap si el muro te paro en seco: re-fijar el suelo
               // contra geometria que te rodea es lo que lanzaba al
               // jugador al cielo (empotrado + ratchet, 2026-09-14).
               if (movedX || movedY) {
                  pz = floorHeightAt(floorQuads, propTris, px, py, pz);
                  PortalCross cross = crossPortal(portalNodes, portalQuads, p0x, p0y, p0z, px - p0x, py - p0y, yaw);
                  if (cross != null) {
                     System.out.println("Cruzando portal \"" + cross.srcName + "\" (sala \"" + roomName
                        + "\", de " + p0x + "," + p0y + "," + p0z + " a " + px + "," + py + ") -> \"" + cross.farName
                        + "\" (sala \"" + cross.destRoomName + "\")");
                     room = cross.destRoom;
                     roomName = cross.destRoomName;
                     bbox = loadPlayRoom(room, floorQuads, blockerBoxes, propTris, portalNodes, portalQuads);
                     startRoomActions(room, roomName, (long) (glfwGetTime() * 1000.0));
                     radius = Math.max(0.01f, distance(bbox));
                     cx = (bbox[0] + bbox[3]) / 2f;
                     cy = (bbox[1] + bbox[4]) / 2f;
                     cz = (bbox[2] + bbox[5]) / 2f;
                     // Fondo infinito de la sala destino (misma logica que
                     // la carga inicial, ver arriba - una sala nueva puede
                     // no tener fondo, o uno distinto).
                     bgBbox = null;
                     if (room.infiniteBackground != null) {
                        float[] freshBg = {Float.MAX_VALUE, Float.MAX_VALUE, Float.MAX_VALUE, -Float.MAX_VALUE, -Float.MAX_VALUE, -Float.MAX_VALUE};
                        int[] bgCount = {0};
                        preloadBg(room.infiniteBackground, identity(), freshBg, bgCount);
                        if (bgCount[0] != 0) {
                           bgBbox = freshBg;
                        }
                     }
                     bgNear = 1f; bgFar = 10000f; bgCx = 0f; bgCy = 0f; bgCz = 0f;
                     if (bgBbox != null) {
                        bgCx = (bgBbox[0] + bgBbox[3]) / 2f;
                        bgCy = (bgBbox[1] + bgBbox[4]) / 2f;
                        bgCz = (bgBbox[2] + bgBbox[5]) / 2f;
                        float bgR = distance(bgBbox) / 2f;
                        float bgDist = (float) Math.sqrt(bgCx * bgCx + bgCy * bgCy + bgCz * bgCz);
                        bgFar = (bgDist + bgR) * 2f + radius;
                     }
                     px = cross.x;
                     py = cross.y;
                     pz = floorHeightAt(floorQuads, propTris, cross.x, cross.y, cross.z);
                     yaw = cross.yaw;
                     System.out.println("  -> sala \"" + roomName + "\" pos=(" + px + "," + py + "," + pz
                        + ") yaw=" + yaw + " (" + floorQuads.size() + " floor quads, " + blockerBoxes.size()
                        + " blockers, " + portalNodes.size() + " portals)");
                     if (autopilot) {
                        autopilotDone = true;
                        crossedThisFrame = true;
                     }
                  }
               }
            }
            if (!autopilot && frame % 300 == 0) {
               System.out.println("Player at (" + px + "," + py + "," + pz + ") yaw=" + yaw + " frame=" + frame);
            }
         } else if (inside && visible) {
            // Fly controls: 60 deg/s turn, radius*0.25/s fly speed (a
            // ~6200-unit room crosses in a few seconds, a small prop room
            // stays controllable - both scale from real scene data).
            float turn = (float) Math.toRadians(60) * dt;
            float speed = radius * 0.25f * dt;
            if (isDown(window, GLFW_KEY_LEFT)) yaw -= turn;
            if (isDown(window, GLFW_KEY_RIGHT)) yaw += turn;
            if (isDown(window, GLFW_KEY_UP)) pitch = Math.min(1.55f, pitch + turn);
            if (isDown(window, GLFW_KEY_DOWN)) pitch = Math.max(-1.55f, pitch - turn);
            float[] fwd = fwdFromYawPitch(yaw, pitch, upZ);
            float[] right = norm(new float[]{
               fwd[1] * up[2] - fwd[2] * up[1],
               fwd[2] * up[0] - fwd[0] * up[2],
               fwd[0] * up[1] - fwd[1] * up[0]});
            if (isDown(window, GLFW_KEY_W)) eye = add(eye, scale(fwd, speed));
            if (isDown(window, GLFW_KEY_S)) eye = add(eye, scale(fwd, -speed));
            if (isDown(window, GLFW_KEY_D)) eye = add(eye, scale(right, speed));
            if (isDown(window, GLFW_KEY_A)) eye = add(eye, scale(right, -speed));
            if (isDown(window, GLFW_KEY_E)) eye = add(eye, scale(up, speed));
            if (isDown(window, GLFW_KEY_Q)) eye = add(eye, scale(up, -speed));
         }
          glViewport(0, 0, width, height);

          // PASADA 1 — fondo infinito con SU propia camara (ver javadoc):
          // posicion fija en el origen local de la cascara, orientacion
          // de la camara viva. Asi el anillo rodea al espectador (nunca
          // en una esquina) sin tocar su colocacion de archivo. Sin
          // depth contra la sala: se limpia la profundidad antes de la
          // pasada 2 para que la sala siempre quede delante (el fondo
          // es backdrop por definicion, como en el cliente original).
          if (bgBbox != null) {
             glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
             glMatrixMode(GL_PROJECTION);
             glLoadIdentity();
             GlUtil.perspective(60f, (float) width / height, bgNear, bgFar);
             glMatrixMode(GL_MODELVIEW);
             glLoadIdentity();
          if (inside) {
                float[] fwdBg = fwdFromYawPitch(yaw, pitch, upZ);
                GlUtil.lookAt(0, 0, 0, fwdBg[0], fwdBg[1], fwdBg[2], up[0], up[1], up[2]);
             } else {
                double abg = Math.toRadians(angle);
                float ex = (float) (cx - radius * 1.6f * Math.sin(abg));
                float ey = (float) (cy + radius * 1.6f * Math.cos(abg));
                float ez = cz + radius * 0.7f;
                float[] dir = norm(new float[]{cx - ex, cy - ey, cz - ez});
                GlUtil.lookAt(0, 0, 0, dir[0], dir[1], dir[2], 0, 0, 1);
             }
             drawInfiniteBackground(room);
             glClear(GL_DEPTH_BUFFER_BIT);
          } else {
             glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
          }

          // PASADA 2 — sala con la camara viva (sin cambios).

         // Real .world scenes are much bigger than a single RWX prop
         // (this room spans ~6200 units), so a generic small-near/
         // big-far range wastes almost all of [near,far] on empty space
         // in front of the eye before the scene even starts - the real
         // scene content lands at view-space depth ~eyeDistance +-
         // radius, squeezed into a sliver right at the far plane in NDC
         // space, where depth-buffer precision collapses and every
         // fragment's depth rounds to exactly the 1.0 clear value -
         // GL_LESS then rejects everything (0 GL error, real triangles
         // submitted, nothing visible - confirmed by projecting a real
         // vertex by hand and finding ndc.z == 0.9999991). Fix: derive
         // near/far tightly around the actual eye-to-scene distance
         // instead of a generic multiple of radius alone.
          float eyeDistance = (float) Math.sqrt(Math.pow(radius * 0.7, 2) + Math.pow(radius * 1.6, 2));
          float near;
          float far;
          if (inside) {
             // Interior: the eye is among the geometry, so near must be
             // small (room-scale units, not scene-diameter scale) while
             // far still covers the whole room from any corner.
             near = Math.max(0.5f, radius * 0.0005f);
             far = radius * 3f;
          } else {
             near = Math.max(0.01f, eyeDistance - radius * 1.3f);
             far = eyeDistance + radius * 1.3f;
          }

          glMatrixMode(GL_PROJECTION);
          glLoadIdentity();
          GlUtil.perspective(60f, (float) width / height, near, far);

          glMatrixMode(GL_MODELVIEW);
          glLoadIdentity();
          if (play) {
             // Tercera persona como el original (HoloPilot BEHIND):
             // camara detras de la cabeza (pies+150 = eyeHeight real
             // de SmoothDriver/HoloPilot) mirando hacia adelante; las
             // flechas UP/DOWN (pitch) la suben/bajan.
             float[] fwd = fwdFromYawPitch(yaw, pitch, true);
             float hx = px, hy = py, hz = pz + PLAY_EYE_HEIGHT;
             GlUtil.lookAt(hx - fwd[0] * PLAY_CAM_DIST, hy - fwd[1] * PLAY_CAM_DIST,
                hz - fwd[2] * PLAY_CAM_DIST, hx + fwd[0] * 10f, hy + fwd[1] * 10f,
                hz + fwd[2] * 10f, 0, 0, 1);
          } else if (inside) {
             float[] fwd = fwdFromYawPitch(yaw, pitch, upZ);
             GlUtil.lookAt(eye[0], eye[1], eye[2], eye[0] + fwd[0], eye[1] + fwd[1], eye[2] + fwd[2], up[0], up[1], up[2]);
          } else {
             // Exterior orbit, Z-up like the client: eye starts out in +Y
             // and above (+Z), and sweeps around the Z axis.
             GlUtil.lookAt(cx, cy + radius * 1.6f, cz + radius * 0.7f, cx, cy, cz, 0, 0, 1);
             glTranslatef(cx, cy, cz);
             glRotatef(angle, 0, 0, 1);
             glTranslatef(-cx, -cy, -cz);
          }

           drawNode(room);
           if (room.environment != null) {
              drawNode(room.environment);
           }
           if (play) {
              // Avatar del jugador (aura.bod = default real del cliente,
              // PosableShape.defaultURL): pies en (px,py,pz), bind pose con
              // las 2 luces como cualquier otro avatar. Forward VERIFICADO:
              // cara y puntas de pies en +Z local del .bod (Y-up), coleta y
              // talones en -Z — medido en SPIN.RWX (cabeza z -0.006/+0.043,
              // pie -0.005/+0.059) y en bytes de aura.bod (coleta -Z, cara
              // +Z); RWXTOBOD.PL pasa ejes sin tocar (swap solo con flag).
              // El +Z bod mapea a +Y mundo (drawAvatar), y tras glRotate(t)
              // sobre Z el forward (0,1,0) va a (-sin t,cos t): igualar al
              // facing (cos yaw,sin yaw) da t = yaw-90 (algebra, no prueba).
              glPushMatrix();
              glTranslatef(px, py, pz);
              glRotatef((float) Math.toDegrees(yaw) - 90f, 0, 0, 1);
              if (drawAvatar(PLAY_AVATAR_URL)) {
                 drawnObjects++;
              }
              glPopMatrix();
           }

          if (!inside) {
             angle += 0.3f;
          }
          // Leer ANTES del swap: tras glfwSwapBuffers el contenido del
          // back buffer es indefinido — en Xvfb se conservaba por suerte
          // (capturas correctas) pero en el display real (:0/XWayland)
          // salía negro con GL error 0. Bug real, no del driver.
          if (screenshotPath != null && frame == 0) {
             GlUtil.saveScreenshot(width, height, screenshotPath);
             System.out.println("Screenshot written to " + screenshotPath
                + (visible ? " (window stays open, ESC to exit)" : ""));
          }
          // PortalCrossHarness (--walk-to): "before" se sobreescribe cada
          // tick MIENTRAS no se haya cruzado (queda con el ultimo frame
          // pre-cruce); "after" se guarda UNA vez, del mismo frame en que
          // crossPortal() ya cambio de sala/posicion mas arriba - por eso
          // ese mismo render ya muestra la sala destino real.
          if (autopilot) {
             if (!crossedThisFrame && screenshotBeforePath != null) {
                GlUtil.saveScreenshot(width, height, screenshotBeforePath);
             } else if (crossedThisFrame && screenshotAfterPath != null) {
                GlUtil.saveScreenshot(width, height, screenshotAfterPath);
                System.out.println("PortalCrossHarness: screenshots guardadas (" + screenshotBeforePath
                   + " / " + screenshotAfterPath + ")");
             }
          }
          glfwSwapBuffers(window);
          glfwPollEvents();
          if (visible && frame == 0) {
             System.out.println("Window presented frame 0 (interactive: ESC to exit)");
          }
          if (autopilot && autopilotDone) {
             break; // cruzado (o presupuesto agotado, ya logueado) - fin del arnes
          }
       }

       System.out.println("Drew " + drawnObjects + " objects (" + avatarDrawnCount + " avatars, "
          + avatarFallbackCount + " via aura.bod fallback), " + drawnTriangles + " triangles this frame. GL error: " + glGetError());
       if (play) {
          System.out.println("Player at (" + px + "," + py + "," + pz + ") yaw=" + yaw);
       }

      glfwDestroyWindow(window);
      glfwTerminate();
      displayListCache.clear();
      glTextureCache.clear();
    }

    /** Walk the room's real WObject tree once (no GL context needed) purely to resolve+load geometry and compute a real bounding box.
     * Invisible leaves (bumpers) are still resolved/counted (placement
     * stats) but excluded from the bounding box — the camera frames the
     * visible scene, not collision volumes. Avatar ("avatar:") leaves
     * resolve their real .bod and contribute their placed feet bbox. */
    private static void preload(WNode n, float[] parentToWorld, float[] bbox, int[] objectCount) {
       float[] here = n.matrix != null ? multiply(parentToWorld, n.matrix) : parentToWorld;
       if (n.geometryUrl != null) {
          objectCount[0]++;
          if (n.geometryUrl.startsWith("avatar:")) {
             BodAvatar av = resolveAvatar(n.geometryUrl);
             if (av == null) {
                avatarSkipCount++;
             } else if (n.isVisible()) {
                extendAvatarBbox(bbox, here, av);
             }
          } else {
             RwxModel model = loadModel(n.geometryUrl);
             if (model != null && n.isVisible()) {
                for (RwxVector3 v : model.vertices) {
                   extendBbox(bbox, transformPoint(here, v.x, v.y, v.z));
                }
             }
          }
       }
       if (isRect(n)) {
          if (n.isVisible()) {
          // Rect walls/floors/ceilings/signs: unit X/Z plane through the
          // live matrix (spin/scale already inside it - verified: wall
          // scales like (2149,2,400) sit in real Rect matrices).
          for (float[] c : RECT_CORNERS) {
             extendBbox(bbox, transformPoint(here, c[0], c[1], c[2]));
          }
          }
          rectCount++;
       }
       if (isRectPatch(n)) {
          if (n.isVisible()) {
          // Heightfield corners in local X/Y (see drawRectPatch).
          extendBbox(bbox, transformPoint(here, 0, 0, n.rpZ[0]));
          extendBbox(bbox, transformPoint(here, n.rpXDim, 0, n.rpZ[1]));
          extendBbox(bbox, transformPoint(here, n.rpXDim, n.rpYDim, n.rpZ[2]));
          extendBbox(bbox, transformPoint(here, 0, n.rpYDim, n.rpZ[3]));
          }
          rectPatchCount++;
       }
       for (WNode c : n.children) {
          preload(c, here, bbox, objectCount);
       }
    }

    private static void extendBbox(float[] bbox, float[] p) {
       bbox[0] = Math.min(bbox[0], p[0]);
       bbox[1] = Math.min(bbox[1], p[1]);
       bbox[2] = Math.min(bbox[2], p[2]);
       bbox[3] = Math.max(bbox[3], p[0]);
       bbox[4] = Math.max(bbox[4], p[1]);
       bbox[5] = Math.max(bbox[5], p[2]);
    }

    /** Bbox walk SOLO para el fondo infinito: Rect/RectPatch visibles con
     * su cadena de matrices, sin tocar contadores globales ni cargar
     * modelos (el fondo real es 100% Rects; si algun dia trae un Shape,
     * su bbox se ignora aqui pero IGUAL se dibuja en su pasada). */
    private static void preloadBg(WNode n, float[] parentToWorld, float[] bbox, int[] count) {
       float[] here = n.matrix != null ? multiply(parentToWorld, n.matrix) : parentToWorld;
       if (isRect(n)) {
          count[0]++;
          if (n.isVisible()) {
             for (float[] c : RECT_CORNERS) {
                extendBbox(bbox, transformPoint(here, c[0], c[1], c[2]));
             }
          }
       }
       if (isRectPatch(n)) {
          count[0]++;
          if (n.isVisible() && n.rpVersion != 0) {
             extendBbox(bbox, transformPoint(here, 0, 0, n.rpZ[0]));
             extendBbox(bbox, transformPoint(here, n.rpXDim, 0, n.rpZ[1]));
             extendBbox(bbox, transformPoint(here, n.rpXDim, n.rpYDim, n.rpZ[2]));
             extendBbox(bbox, transformPoint(here, 0, n.rpYDim, n.rpZ[3]));
          }
       }
       for (WNode c : n.children) {
          preloadBg(c, here, bbox, count);
       }
    }

    /** Extiende el bbox con las 8 esquinas del avatar ya colocado:
     * caja local con pies en origen (ver drawAvatar) x escala, pasada
     * por la matriz compuesta del nodo. */
    private static void extendAvatarBbox(float[] bbox, float[] here, BodAvatar av) {
       float w = (av.maxX - av.minX) * BOD_WORLD_SCALE;
       float h = (av.maxY - av.minY) * BOD_WORLD_SCALE;
       float d = (av.maxZ - av.minZ) * BOD_WORLD_SCALE;
       if (!(w > 0) || !(h > 0) || !(d > 0)) {
          return; // .bod degenerado: no ensancha el encuadre con basura
       }
       // Local (mundo-Z-up): x = bodX*s, y = bodZ*s, z = (bodY-minY)*s.
       float lx0 = av.minX * BOD_WORLD_SCALE, lx1 = av.maxX * BOD_WORLD_SCALE;
       float ly0 = av.minZ * BOD_WORLD_SCALE, ly1 = av.maxZ * BOD_WORLD_SCALE;
       float lz1 = h;
       float[] xs = {lx0, lx1};
       float[] ys = {ly0, ly1};
       float[] zs = {0f, lz1};
       for (float x : xs) {
          for (float y : ys) {
             for (float z : zs) {
                extendBbox(bbox, transformPoint(here, x, y, z));
             }
          }
       }
    }

    /** Resuelve "avatar:Nombre.rwg" al .bod base oficial del mismo nombre
     * (comparacion case-insensitive). Si no existe (Tre), usa aura.bod,
     * el default real del cliente (PosableShape.defaultURL). null solo si
     * ni siquiera hay fallback en disco. Conteo honesto via
     * avatarFallbackCount. */
    private static BodAvatar resolveAvatar(String url) {
       BodAvatar cached = bodCache.get(url);
       if (cached != null) {
          return cached;
       }
       File dir = resolveAvatarDir();
       BodAvatar av = null;
       if (dir != null) {
          String stem = url;
          int colon = stem.indexOf(':');
          if (colon >= 0) {
             stem = stem.substring(colon + 1);
          }
          int dot = stem.indexOf('.');
          if (dot >= 0) {
             stem = stem.substring(0, dot);
          }
          File f = findIgnoreCase(dir, stem + ".bod");
          if (f != null) {
             av = assembleAvatar(f, false);
          }
          if (av == null) {
             File aura = findIgnoreCase(dir, "aura.bod");
             if (aura != null) {
                av = assembleAvatar(aura, true);
                if (av != null) {
                   System.out.println("Avatar \"" + url + "\": no hay .bod propio, usando aura.bod (default real del cliente)");
                }
             }
          }
       }
       if (av != null) {
          bodCache.put(url, av);
       }
       return av;
    }

    /** Localiza el directorio de avatares base oficiales una vez por
     * ejecucion (ruta relativa a la instalacion, no al CWD). */
    private static File resolveAvatarDir() {
       if (avatarDirChecked) {
          return avatarDir;
       }
       avatarDirChecked = true;
       // baseDir = .../GroundZero ; los avatares viven en
       // <root>/assets/gammatutorial-samples/base-avatars/
       File[] candidates = {
          new File(baseDir, "../gammatutorial-samples/base-avatars"),
          new File(baseDir, "../../assets/gammatutorial-samples/base-avatars"),
          new File("assets/gammatutorial-samples/base-avatars"),
       };
       for (File c : candidates) {
          try {
             if (c.isDirectory() && findIgnoreCase(c, "aura.bod") != null) {
                avatarDir = c;
                break;
             }
          } catch (Exception e) {
             // probar el siguiente candidato
          }
       }
       return avatarDir;
    }

    /** Ensambla un .bod en bind pose (MISMA regla que BodViewer, ver su
     * javadoc: placeholders del padre + translacion propia; RAIZ incluida
     * — reproducir exacto lo verificado, sin "arreglos"). */
    private static BodAvatar assembleAvatar(File f, boolean fallback) {
       BodAvatar av = new BodAvatar();
       av.usedFallback = fallback;
       av.sourceName = f.getName();
       byte[] data;
       try {
          data = Files.readAllBytes(f.toPath());
       } catch (IOException e) {
          System.err.println("Avatar: no se pudo leer " + f + ": " + e);
          return null;
       }
       BodFile bod;
       try {
          bod = BodParser.parse(data);
       } catch (Exception e) {
          System.err.println("Avatar: no se pudo parsear " + f + ": " + e);
          return null;
       }
       Map<Integer, BodClump> partByTag = new HashMap<>();
       for (BodClump p : bod.parts) {
          partByTag.put(p.tag, p);
       }
       Set<Integer> referenced = new HashSet<>();
       for (BodClump p : bod.parts) {
          collectAvatarPlaceholders(p, referenced);
       }
       BodClump root = null;
       for (BodClump p : bod.parts) {
          if (!referenced.contains(p.tag)) {
             root = p;
             break;
          }
       }
       if (root == null) {
          root = partByTag.get(1); // pelvis(1) en todo el corpus real
       }
       if (root == null && !bod.parts.isEmpty()) {
          root = bod.parts.get(0);
       }
       if (root == null) {
          return null;
       }
       Set<Integer> visited = new HashSet<>();
       int[] bad = {0};
       collectAvatarClump(root, 0f, 0f, 0f, partByTag, visited, av, bad);
       if (av.tris.isEmpty()) {
          System.err.println("Avatar: " + f + " sin triangulos colocados");
          return null;
       }
       return av;
    }

    private static void collectAvatarPlaceholders(BodClump c, Set<Integer> out) {
       if (c.placeholder) {
          out.add(c.tag);
          return;
       }
       if (c.children != null) {
          for (BodClump child : c.children) {
             collectAvatarPlaceholders(child, out);
          }
       }
    }

    private static void collectAvatarClump(BodClump c, float ox, float oy, float oz,
          Map<Integer, BodClump> partByTag, Set<Integer> visited, BodAvatar av, int[] bad) {
       if (c.placeholder) {
          return;
       }
       visited.add(c.tag);
       float nx = ox + c.tx;
       float ny = oy + c.ty;
       float nz = oz + c.tz;
       if (c.vertices != null && !c.vertices.isEmpty() && c.triangles != null && !c.triangles.isEmpty()) {
          float r = (c.r & 0xFF) / 255f;
          float g = (c.g & 0xFF) / 255f;
          float b = (c.b & 0xFF) / 255f;
          List<BodVertex> v = c.vertices;
          for (int[] t : c.triangles) {
             if (t[0] < 0 || t[1] < 0 || t[2] < 0
                || t[0] >= v.size() || t[1] >= v.size() || t[2] >= v.size()) {
                bad[0]++;
                continue;
             }
             BodVertex a = v.get(t[0]);
             BodVertex bb = v.get(t[1]);
             BodVertex cc = v.get(t[2]);
             BodTri p = new BodTri();
             p.ax = a.x + nx; p.ay = a.y + ny; p.az = a.z + nz;
             p.bx = bb.x + nx; p.by = bb.y + ny; p.bz = bb.z + nz;
             p.cx = cc.x + nx; p.cy = cc.y + ny; p.cz = cc.z + nz;
             p.r = r; p.g = g; p.b = b;
             av.tris.add(p);
             float[] px = {p.ax, p.bx, p.cx};
             float[] py = {p.ay, p.by, p.cy};
             float[] pz = {p.az, p.bz, p.cz};
             for (int i = 0; i < 3; i++) {
                av.minX = Math.min(av.minX, px[i]);
                av.minY = Math.min(av.minY, py[i]);
                av.minZ = Math.min(av.minZ, pz[i]);
                av.maxX = Math.max(av.maxX, px[i]);
                av.maxY = Math.max(av.maxY, py[i]);
                av.maxZ = Math.max(av.maxZ, pz[i]);
             }
          }
       }
       if (c.children != null) {
          for (BodClump child : c.children) {
             if (child.placeholder) {
                BodClump target = partByTag.get(child.tag);
                if (target == null) {
                   bad[0]++;
                   continue;
                }
                collectAvatarClump(target, nx + child.tx, ny + child.ty, nz + child.tz,
                   partByTag, visited, av, bad);
             } else {
                collectAvatarClump(child, nx, ny, nz, partByTag, visited, av, bad);
             }
          }
       }
    }

    /** Dibuja un avatar .bod ya ensamblado bajo la matriz actual del nodo
     * (la posicion/orientacion del PosableShape ya esta aplicada por
     * drawNode): pies en el origen del nodo, +Y bod -> +Z mundo (el
     * cliente es Z-up), escala global documentada. Colores planos por
     * clump + 2 luces reales (el .bod no trae texturas ni normales:
     * normal de cara + GL_FLAT como RWX, ambas caras visibles como RWG
     * — winding sin verificar). Devuelve false si no habia nada que
     * dibujar. */
    private static boolean drawAvatar(String url) {
       BodAvatar av = resolveAvatar(url);
       if (av == null || av.tris.isEmpty()) {
          return false;
       }
       float h = (av.maxY - av.minY) * BOD_WORLD_SCALE;
       if (!(h > 0)) {
          return false;
       }
       RwxMaterial lastMat = null;
       boolean inBegin = false;
       glDisable(GL_CULL_FACE);
       for (BodTri t : av.tris) {
          // Mapeo bod(Y-up) -> mundo(Z-up) + rebase de pies + escala.
          float ax = t.ax * BOD_WORLD_SCALE;
          float ay = t.az * BOD_WORLD_SCALE;
          float az = (t.ay - av.minY) * BOD_WORLD_SCALE;
          float bx = t.bx * BOD_WORLD_SCALE;
          float by = t.bz * BOD_WORLD_SCALE;
          float bz = (t.by - av.minY) * BOD_WORLD_SCALE;
          float cx = t.cx * BOD_WORLD_SCALE;
          float cy = t.cz * BOD_WORLD_SCALE;
          float cz = (t.cy - av.minY) * BOD_WORLD_SCALE;
          if (lastMat == null || lastMat.colorR != t.r || lastMat.colorG != t.g || lastMat.colorB != t.b) {
             if (inBegin) {
                glEnd();
                inBegin = false;
             }
             lastMat = bodAvatarMaterial(t.r, t.g, t.b);
             GlLighting.applyMaterial(lastMat);
          }
          if (!inBegin) {
             glBegin(GL_TRIANGLES);
             inBegin = true;
          }
          float[] n = GlLighting.faceNormal(ax, ay, az, bx, by, bz, cx, cy, cz);
          glNormal3f(n[0], n[1], n[2]);
          glVertex3f(ax, ay, az);
          glVertex3f(bx, by, bz);
          glVertex3f(cx, cy, cz);
       }
       if (inBegin) {
          glEnd();
       }
       glEnable(GL_CULL_FACE);
       drawnTriangles += av.tris.size();
       avatarDrawnCount++;
       if (av.usedFallback) {
          avatarFallbackCount++;
       }
       return true;
    }

    /** Material plano por clump .bod (el formato no trae scalars: misma
     * convencion placeholder que RwgViewer/BodViewer — ambient 0.3,
     * diffuse 0.8, specular 0.1, opaco — marcada VERIFICAR igual que
     * alli). */
    private static RwxMaterial bodAvatarMaterial(float r, float g, float b) {
       RwxMaterial mat = new RwxMaterial();
       mat.colorR = r;
       mat.colorG = g;
       mat.colorB = b;
       mat.ambient = 0.3f;
       mat.diffuse = 0.8f;
       mat.specular = 0.1f;
       mat.opacity = 1f;
       return mat;
    }

    /** A Rect is a unit quad in its local X/Z plane (NOT X/Y: real
     * matrices squash local Y to ~zero — e.g. wall scale (2149,2,400) —
     * while (1,0,1) reproduces the decompiled far corner (f1,f2,f3)
     * exactly through spin(atan2(f2,f1)) about Z + scale(len,f3,f3)).
     * Verified corner-by-corner against groundzero.world Reception. */
    private static final float[][] RECT_CORNERS = {{0, 0, 0}, {1, 0, 0}, {1, 0, 1}, {0, 0, 1}};

    private static boolean isRect(WNode n) {
       return n.className.endsWith(".Rect"); // RectPatch ends with "Patch", excluded on purpose
    }

   static int drawnTriangles = 0;
   static int drawnObjects = 0;

    /** Draws the room's infinite background subtree AS-IS (authored
      * transforms only). The "infinite" effect comes from the caller's
      * dedicated background camera (position 0,0,0 + live orientation,
      * see the render loop), NOT from touching this geometry — so this
      * method deliberately takes no camera parameters and translates
      * nothing. Rooms whose background is empty (23/25 in GroundZero —
      * the author left them blank "to speed up rendering", Gamma_Overview)
      * draw nothing.
      */
    private static void drawInfiniteBackground(WNode room) {
       drawNode(room.infiniteBackground);
    }

    private static void drawNode(WNode n) {
       glPushMatrix();
       if (n.matrix != null) {
          try (MemoryStack stack = MemoryStack.stackPush()) {
             FloatBuffer buf = stack.mallocFloat(16);
             buf.put(n.matrix).flip();
             glMultMatrixf(buf);
          }
       }
       // Invisible nodes (WObject.flags bit0 clear — collision bumpers like
       // LizCave's Rect942CyanBump, verified teal #00FCF8 in-stream) are
       // parsed but never drawn. Leaf-only: grouping nodes always traverse
       // (visibility propagation is native-side, unverified — never hide a
       // whole subtree on a group's flag).
       boolean visibleLeaf = n.isVisible();
       if (n.geometryUrl != null) {
          if (n.geometryUrl.startsWith("avatar:")) {
             if (visibleLeaf) {
                if (drawAvatar(n.geometryUrl)) {
                   drawnObjects++;
                }
             }
          } else if (visibleLeaf) {
             RwxModel model = loadModel(n.geometryUrl);
             if (model != null) {
                drawModel(model);
                drawnTriangles += model.triangles.size();
                drawnObjects++;
             }
          }
       }
        if (isRect(n)) {
           if (visibleLeaf) {
              drawRect(n);
           }
        }
        if (isRectPatch(n)) {
           if (visibleLeaf) {
              drawRectPatch(n);
           }
        }
       for (WNode c : n.children) {
          drawNode(c);
       }
       glPopMatrix();
    }

    private static boolean isRectPatch(WNode n) {
       return n.className.endsWith(".RectPatch");
    }

    /** Draws one RectPatch heightfield quad (v1+ with material; v0 is
     * explicitly invisible in the client and skipped). Corners in local
     * X/Y with per-corner heights z[0..3] = (0,0),(xDim,0),(xDim,yDim),
     * (0,yDim) — the only order consistent with a non-twisted grid;
     * verified flat (all z equal) on the real corpus, where the order is
     * unobservable. Null material = client default (black). */
    private static void drawRectPatch(WNode n) {
       if (n.rpVersion == 0) {
          return; // explicitly invisible: setVisible(false) in restoreState
       }
       RwxMaterial mat = rectMaterial(n);
       GlLighting.applyMaterial(mat);
       glDisable(GL_CULL_FACE);
       int glTex = resolveRectTexture(n.material != null ? n.material.matTextureUrl : null);
       boolean texEnabled = false;
       if (glTex != 0) {
          glEnable(GL_TEXTURE_2D);
          glBindTexture(GL_TEXTURE_2D, glTex);
          texEnabled = true;
       }
       float u0 = n.rpXTileOff, v0 = n.rpYTileOff;
       float u1 = u0 + n.rpXTile, v1 = v0 + n.rpYTile;
       float[][] corners = {
          {0, 0, n.rpZ[0]}, {n.rpXDim, 0, n.rpZ[1]},
          {n.rpXDim, n.rpYDim, n.rpZ[2]}, {0, n.rpYDim, n.rpZ[3]}};
       float[][] uvs = {{u0, v0}, {u1, v0}, {u1, v1}, {u0, v1}};
       float[] ex = xformDir(n.rpXDim, 0, n.rpZ[1] - n.rpZ[0]);
       float[] ey = xformDir(0, n.rpYDim, n.rpZ[3] - n.rpZ[0]);
       float[] nn = GlLighting.faceNormal(0, 0, 0, ex[0], ex[1], ex[2], ey[0], ey[1], ey[2]);
       glBegin(GL_QUADS);
       glNormal3f(nn[0], nn[1], nn[2]);
       for (int i = 0; i < 4; i++) {
          glTexCoord2f(uvs[i][0], uvs[i][1]);
          glVertex3f(corners[i][0], corners[i][1], corners[i][2]);
       }
       glEnd();
       if (texEnabled) {
          glDisable(GL_TEXTURE_2D);
       }
       glEnable(GL_CULL_FACE);
       drawnTriangles += 2;
       drawnObjects++;
    }

    /** Dispara los StartupSensor de la sala (TextureActions) e informa de
     * las acciones que no mueven texturas y por tanto no se ejecutan. */
    private static void startRoomActions(WNode room, String roomName, long nowMs) {
       textureActions.startRoom(room, nowMs);
       if (!textureActions.skipped.isEmpty()) {
          System.out.println("Sala \"" + roomName + "\": acciones de StartupSensor no ejecutadas (no cambian texturas): "
             + textureActions.skipped);
          textureActions.skipped.clear();
       }
    }

    /** Draws one Rect surface node as a textured (or flat) quad. The node's
     * composed matrix (glMultMatrixf above) already places the unit quad;
     * UVs come from the real u/v/uOff/vOff (tiling like (2,8.4) relies on
     * GL_REPEAT, set at upload). Double-sided: Rect materials carry no
     * MaterialModes and winding through arbitrary spins is unverified —
     * from inside a closed room only inward faces are visible either way.
     * Lighting is two-sided (see GlLighting.init) so backs get correct N·L.
     *
     * Material: el del nodo, o el que haya puesto una AnimateAction
     * (textureActions.materialOverride, ver TextureActions). Con sufijo
     * "Nh*"/"Nv*" (Material.getHiRes) el Rect se parte en las celdas de
     * Surface.addSubPolys, cada una con su textura (MaterialTiles): asi se
     * ven los .mov de GroundZero, cuyos frames son esas celdas. */
    private static void drawRect(WNode n) {
       String override = textureActions == null ? null : textureActions.materialOverride.get(n);
       String url = override != null ? override : (n.material != null ? n.material.matTextureUrl : null);
       RwxMaterial mat = override != null ? urlMaterial(override) : rectMaterial(n);
       GlLighting.applyMaterial(mat);
       glDisable(GL_CULL_FACE);
       // World-space normal: read back the real composed modelview (parent
       // chain x node matrix, already current) and transform the two local
       // edges through its linear part - exact with no matrix threading.
       float[] ex = xformDir(1, 0, 0);
       float[] ez = xformDir(0, 0, 1);
       float[] nn = GlLighting.faceNormal(0, 0, 0, ex[0], ex[1], ex[2], ez[0], ez[1], ez[2]);
       MaterialTiles tiles = url == null ? null : MaterialTiles.of(url.trim());
       if (tiles != null && tiles.hiRes()) {
          int[] ids = resolveRectTextures(url);
          for (float[] c : MaterialTiles.rectCells(n.rectU, n.rectV, n.rectUOff, n.rectVOff, n.flags, tiles.hRes, tiles.vRes)) {
             int glTex = ids[(int) c[8]];
             if (glTex != 0) {
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, glTex);
             }
             // v de RW cuenta desde la fila de arriba; la textura se sube
             // volteada (uploadTexture), asi que t de GL = 1 - v.
             glBegin(GL_QUADS);
             glNormal3f(nn[0], nn[1], nn[2]);
             glTexCoord2f(c[4], 1f - c[6]);
             glVertex3f(c[0], 0f, c[2]);
             glTexCoord2f(c[5], 1f - c[6]);
             glVertex3f(c[1], 0f, c[2]);
             glTexCoord2f(c[5], 1f - c[7]);
             glVertex3f(c[1], 0f, c[3]);
             glTexCoord2f(c[4], 1f - c[7]);
             glVertex3f(c[0], 0f, c[3]);
             glEnd();
             if (glTex != 0) {
                glDisable(GL_TEXTURE_2D);
             }
             drawnTriangles += 2;
          }
          glEnable(GL_CULL_FACE);
          drawnObjects++;
          return;
       }
       int glTex = resolveRectTexture(url);
       boolean texEnabled = false;
       if (glTex != 0) {
          glEnable(GL_TEXTURE_2D);
          glBindTexture(GL_TEXTURE_2D, glTex);
          texEnabled = true;
       }
       float u0 = n.rectUOff, v0 = n.rectVOff;
       float u1 = u0 + n.rectU, v1 = v0 + n.rectV;
       float[][] uvs = {{u0, v0}, {u1, v0}, {u1, v1}, {u0, v1}};
       glBegin(GL_QUADS);
       glNormal3f(nn[0], nn[1], nn[2]);
       for (int i = 0; i < 4; i++) {
          glTexCoord2f(uvs[i][0], uvs[i][1]);
          glVertex3f(RECT_CORNERS[i][0], RECT_CORNERS[i][1], RECT_CORNERS[i][2]);
       }
       glEnd();
       if (texEnabled) {
          glDisable(GL_TEXTURE_2D);
       }
       // Restore the caller's culling expectation (shapes are single-sided).
       glEnable(GL_CULL_FACE);
       drawnTriangles += 2;
       drawnObjects++;
    }

    /** Transforms a local direction by the current modelview's linear part
     * (read back exactly as GL holds it - parent chain x node matrix). */
    private static float[] xformDir(float x, float y, float z) {
       try (MemoryStack stack = MemoryStack.stackPush()) {
          FloatBuffer mv = stack.mallocFloat(16);
          glGetFloatv(GL_MODELVIEW_MATRIX, mv);
          return new float[]{
             mv.get(0) * x + mv.get(4) * y + mv.get(8) * z,
             mv.get(1) * x + mv.get(5) * y + mv.get(9) * z,
             mv.get(2) * x + mv.get(6) * y + mv.get(10) * z};
       }
    }

   private static RwxModel loadModel(String url) {
      if (modelCache.containsKey(url)) {
         return modelCache.get(url);
      }
      RwxModel model = null;
      File f = resolveCaseInsensitive(baseDir, url);
      if (f != null) {
         try {
            String text = new String(Files.readAllBytes(f.toPath()), "ISO-8859-1");
            model = new RwxParser().parse(text);
            loadedCount++;
         } catch (Exception e) {
            System.err.println("Failed to parse " + f + ": " + e);
            missingCount++;
         }
      } else {
         missingCount++;
      }
      modelCache.put(url, model);
      return model;
   }

   /** Real filesystems here are case-sensitive but the .world file's URLs don't reliably match real file casing (e.g. "tex/frame.rwx" vs real "Frame.rwx") - resolve by case-insensitive match against real directory listings rather than guessing one casing. */
   private static File resolveCaseInsensitive(File base, String relPath) {
      String[] parts = relPath.split("/");
      File cur = base;
      for (String part : parts) {
         if (cur == null || !cur.isDirectory()) {
            return null;
         }
         File exact = new File(cur, part);
         if (exact.exists()) {
            cur = exact;
            continue;
         }
         File[] listing = cur.listFiles();
         File match = null;
         if (listing != null) {
            for (File f : listing) {
               if (f.getName().equalsIgnoreCase(part)) {
                  match = f;
                  break;
               }
            }
         }
         if (match == null) {
            return null;
         }
         cur = match;
      }
      return (cur != null && cur.isFile()) ? cur : null;
   }

    private static void drawModel(RwxModel model) {
       Integer list = displayListCache.get(model);
       if (list != null) {
          glCallList(list);
          return;
       }
       int id = glGenLists(1);
       glNewList(id, GL_COMPILE);
       emitModelImmediate(model);
       glEndList();
       displayListCache.put(model, id);
       glCallList(id);
    }

     /** Secuencia inmediata original (glMaterial/glNormal/glVertex/glTexCoord por triangulo) — unica fuente de verdad visual; la display list solo la captura. */
    private static void emitModelImmediate(RwxModel model) {
       RwxMaterial lastMat = null;
      boolean inBegin = false;
      boolean texEnabled = false;
      for (int i = 0; i < model.triangles.size(); i++) {
         RwxMaterial mat = model.triangleMaterials.get(i);
         if (mat != lastMat) {
            if (inBegin) {
               glEnd();
               inBegin = false;
            }
            GlLighting.applyMaterial(mat);
            GlLighting.applyCulling(mat.doubleSided);
            int glTex = resolveTexture(mat);
            if (glTex != 0) {
               if (!texEnabled) {
                  glEnable(GL_TEXTURE_2D);
                  texEnabled = true;
               }
               glBindTexture(GL_TEXTURE_2D, glTex);
            } else if (texEnabled) {
               glDisable(GL_TEXTURE_2D);
               texEnabled = false;
            }
            lastMat = mat;
         }
         if (!inBegin) {
            glBegin(GL_TRIANGLES);
            inBegin = true;
         }
         int[] t = model.triangles.get(i);
         RwxVector3 a = model.vertices.get(t[0]);
         RwxVector3 b = model.vertices.get(t[1]);
         RwxVector3 c = model.vertices.get(t[2]);
         float[] n = GlLighting.faceNormal(a.x, a.y, a.z, b.x, b.y, b.z, c.x, c.y, c.z);
         glNormal3f(n[0], n[1], n[2]);
         float[] uva = model.uvs.get(t[0]);
         float[] uvb = model.uvs.get(t[1]);
         float[] uvc = model.uvs.get(t[2]);
         glTexCoord2f(uva[0], uva[1]);
         glVertex3f(a.x, a.y, a.z);
         glTexCoord2f(uvb[0], uvb[1]);
         glVertex3f(b.x, b.y, b.z);
         glTexCoord2f(uvc[0], uvc[1]);
         glVertex3f(c.x, c.y, c.z);
      }
      if (inBegin) {
         glEnd();
      }
      if (texEnabled) {
         glDisable(GL_TEXTURE_2D);
      }
   }

    /**
     * Builds the GL material for one Rect surface from its real parsed
     * fields (see WorldRestorer.readMaterial): file color + ambient /
     * diffuse / specular / opacity scalars, texture URL when present.
     * Rect materials have no TextureModes/Lit concept, so the parsed
     * scalars apply directly (Lit-equivalent); textured ones get the
     * white base like RWX textured materials (see RwxMaterial).
     */
    private static RwxMaterial rectMaterial(WNode n) {
       RwxMaterial mat = new RwxMaterial();
       WNode m = n.material;
       if (m == null) {
          return mat; // no material in-stream: AW default surface, black base
       }
       mat.colorR = ((m.matColorRGB >> 16) & 0xFF) / 255f;
       mat.colorG = ((m.matColorRGB >> 8) & 0xFF) / 255f;
       mat.colorB = (m.matColorRGB & 0xFF) / 255f;
       mat.ambient = m.matAmbient;
       mat.diffuse = m.matDiffuse;
       mat.specular = m.matSpecular;
       mat.opacity = m.matOpacity;
       if (m.matTextureUrl != null) {
          mat.textureName = m.matTextureUrl.trim(); // non-null = textured (white base)
       }
       return mat;
    }

    /** new Material(URL) del original (Material.java: Material(URL) ->
     * Material(Color null, URL) -> Material(Color(128,128,128)) ->
     * ambient 0.75, diffuse 0, specular 0, opacidad 1), que es lo que
     * AnimateAction pone en su dueno por cada nombre de su lista. */
    private static RwxMaterial urlMaterial(String url) {
       RwxMaterial mat = new RwxMaterial();
       mat.colorR = mat.colorG = mat.colorB = 128 / 255f;
       mat.ambient = 0.75f;
       mat.diffuse = 0f;
       mat.specular = 0f;
       mat.opacity = 1f;
       mat.textureName = url.trim();
       return mat;
    }

    /** Textura 0 de un material de Rect/RectPatch (ver resolveRectTextures). */
    private static int resolveRectTexture(String url) {
       return url == null ? 0 : resolveRectTextures(url)[0];
    }

    /**
     * GL ids de las hRes*vRes texturas de un material (MaterialTiles: el
     * fichero y el frame de cada una, como Material.loadTextures y
     * syncBackgroundLoad), 0 donde no se puede (color plano). Cuenta la URL
     * como resuelta solo si salen todas. Busca cada fichero en el tex/
     * extraido de content.zip, y en dtex/ y tex/ junto al .world.
     */
    private static int[] resolveRectTextures(String url) {
       rectTextureRefs++;
       String key = url.trim();
       MaterialTiles tiles = MaterialTiles.of(key);
       int[] ids = new int[tiles.files.length];
       String problem = null;
       for (int k = 0; k < ids.length; k++) {
          String[] why = new String[1];
          ids[k] = rectTextureId(tiles.files[k], tiles.frames[k], tiles.framesNeeded(), tiles.movie(), why);
          if (ids[k] == 0 && problem == null) {
             problem = why[0];
          }
       }
       if (problem == null) {
          rectTexturesResolved.add(key);
       } else if (!rectTexturesUnresolved.containsKey(key)) {
          rectTexturesUnresolved.put(key, problem);
       }
       return ids;
    }

    /** Decoded .mov frames per file (lowercase base name), all frames at once. */
    private static final Map<String, CmpTexture[]> movFrameCache = new HashMap<>();

    private static int rectTextureId(String file, int frame, int framesNeeded, boolean movie, String[] why) {
       String key = "rect:" + file.toLowerCase() + "#" + frame;
       if (glTextureCache.containsKey(key)) {
          int cached = glTextureCache.get(key);
          if (cached == 0) {
             why[0] = "(cached failure: " + file + " frame " + frame + ")";
          }
          return cached;
       }
       int dot = file.lastIndexOf('.');
       String ext = dot >= 0 ? file.substring(dot + 1).toLowerCase() : "";
       if (!ext.equals("cmp") && !ext.equals("mov")) {
          why[0] = ext.isEmpty() ? "no extension" : "referenced as ." + ext + ", no loader for that container";
          glTextureCache.put(key, 0);
          return 0;
       }
       List<File> dirs = new ArrayList<>();
       File archive = resolveTextureArchive();
       if (archive != null) {
          dirs.add(archive);
       }
       dirs.add(new File(baseDir, "dtex"));
       dirs.add(new File(baseDir, "tex"));
       for (File dir : dirs) {
          File f = findIgnoreCase(dir, file);
          if (f == null) {
             continue;
          }
          int id = 0;
          try {
             if (movie) {
                CmpTexture[] all = movFrameCache.get(file.toLowerCase());
                if (all == null) {
                   all = CmpTexture.loadMovFrames(f);
                   movFrameCache.put(file.toLowerCase(), all);
                }
                // Material.syncBackgroundLoad: si la pelicula no tiene
                // hRes*vRes*(sPos+1) frames, error de carga (sin textura).
                if (all.length < framesNeeded) {
                   why[0] = file + ": " + all.length + " frames, el material pide " + framesNeeded;
                } else {
                   id = uploadTexture(all[frame]);
                }
             } else {
                id = uploadTexture(CmpTexture.loadRaw(f));
             }
          } catch (Exception e) {
             why[0] = file + ": " + e.getMessage();
          }
          glTextureCache.put(key, id);
          return id;
       }
       why[0] = file + " not found in tex/ archive, dtex/ or tex/ dirs";
       glTextureCache.put(key, 0);
       return 0;
    }

    /** Case-insensitive file lookup (real .world URLs don't reliably match
     * on-disk casing, same as geometry - see resolveCaseInsensitive). */
    private static File findIgnoreCase(File dir, String name) {
       File exact = new File(dir, name);
       if (exact.isFile()) {
          return exact;
       }
       File[] listing = dir.listFiles();
       if (listing != null) {
          for (File f : listing) {
             if (f.isFile() && f.getName().equalsIgnoreCase(name)) {
                return f;
             }
          }
       }
       return null;
    }

    /**
     * Resolves a material's real "Texture" reference to a real GL texture id,
     * decoded through net.freeworlds.cmp.CmpTexture - or 0 if it can't be
    * decoded (falls back to the material's own real flat color, applied
    * just above by GlLighting.applyMaterial - never an invented texture).
    * Cached per name so repeat materials (e.g. many objects sharing
    * "grnd1.cmp") don't re-decode. Every call is accounted for in
    * texturesResolved/texturesUnresolved for the session's coverage report,
    * whether or not this exact call hits the cache.
    */
   private static int resolveTexture(RwxMaterial mat) {
      if (mat.textureName == null) {
         return 0;
      }
      materialTextureRefs++;
      String base = mat.textureName.trim();
      int dot = base.lastIndexOf('.');
      String ext = dot >= 0 ? base.substring(dot + 1).toLowerCase() : "";
      String name = (dot >= 0 ? base.substring(0, dot) : base).toLowerCase();
      if (glTextureCache.containsKey(name)) {
         Integer cached = glTextureCache.get(name);
         if (cached != 0) {
            texturesResolved.add(name);
         } else if (!texturesUnresolved.containsKey(name)) {
            texturesUnresolved.put(name, "(cached failure, see first occurrence)");
         }
         return cached;
      }
       if (!ext.equals("cmp") && !ext.isEmpty()) {
          // Real corpus has a handful of .bmp-named references (e.g.
          // "cstgbs3.bmp", "pceil2.bmp"). No BMP loader exists in this
          // pipeline - but compimg's .cmp IS the compressed form of the
          // same artwork, and same-stem .cmp files ship in the same
          // archive (tex/cstgbs3.cmp verified present), so fall back to
          // the same-stem .cmp explicitly as such rather than guessing
          // pixels or silently dropping (pceil2 has no .cmp twin and
          // stays honestly unresolved).
          if (!ext.equals("bmp")) {
             texturesUnresolved.put(name, "referenced as ." + ext + ", no loader for that extension");
             glTextureCache.put(name, 0);
             return 0;
          }
       }
      File dir = resolveTextureArchive();
      if (dir == null) {
         texturesUnresolved.put(name, "no texture archive found next to this .world");
         glTextureCache.put(name, 0);
         return 0;
      }
      File cmpFile = new File(dir, name + ".cmp");
      try {
         // CmpTexture.loadRaw: the real Stage 1 Huffman/palette decoder
         // (net.freeworlds.cmp.CmpStage1), verified byte-exact against the
         // real cmpview.exe rendering for all 159 .cmp files in this same
         // GroundZero content.zip (docs/cmp-texture-format-reference.md,
         // "Estado final" section) - no pre-captured streams or hand-voted
         // palette needed, unlike the legacy CmpTexture.load used before.
         CmpTexture tex = CmpTexture.loadRaw(cmpFile);
         int id = uploadTexture(tex);
         glTextureCache.put(name, id);
         texturesResolved.add(name);
         return id;
      } catch (Exception e) {
         // No invented pixels: any failure (file missing from the real
         // archive, or a real decode error) falls back to the material's
         // real flat color, never a guessed texture.
         texturesUnresolved.put(name, String.valueOf(e.getMessage()));
         glTextureCache.put(name, 0);
         return 0;
      }
   }

   /**
    * The real client shipped its texture files in a per-world content
    * archive next to the .world file itself (confirmed: assets/WorldsPlayer/
    * GroundZero/content.zip, a genuine period zip with entries under
    * "tex/*.cmp" - same "tex/" convention as the already-extracted
    * tex/*.rwx geometry sitting alongside it on disk). Extracted once,
    * lazily, to a runtime temp dir (NOT committed - content.zip itself
    * already is, this just unpacks what's already real and tracked) so
    * CmpTexture.load's existing dir+basename file API can be reused as-is.
    */
   private static File resolveTextureArchive() {
      if (textureArchiveChecked) {
         return textureArchiveDir;
      }
      textureArchiveChecked = true;
      File zipFile = resolveCaseInsensitive(baseDir, "content.zip");
      if (zipFile == null) {
         return null;
      }
      File outDir = new File(System.getProperty("java.io.tmpdir"),
         "freeworlds-tex-cache/" + zipFile.getParentFile().getName());
      try (ZipFile zf = new ZipFile(zipFile)) {
         Enumeration<? extends ZipEntry> entries = zf.entries();
         while (entries.hasMoreElements()) {
            ZipEntry e = entries.nextElement();
             String n = e.getName();
             if (e.isDirectory() || (!n.toLowerCase().endsWith(".cmp") && !n.toLowerCase().endsWith(".mov"))) {
                continue;
             }
            String flatName = new File(n).getName(); // drop the "tex/" prefix
            File outFile = new File(outDir, flatName);
            if (outFile.exists() && outFile.length() == e.getSize()) {
               continue; // already extracted this run/session, real size match
            }
            outDir.mkdirs();
            try (InputStream in = zf.getInputStream(e);
                 FileOutputStream out = new FileOutputStream(outFile)) {
               byte[] buf = new byte[8192];
               int n2;
               while ((n2 = in.read(buf)) > 0) {
                  out.write(buf, 0, n2);
               }
            }
         }
      } catch (IOException e) {
         System.err.println("Failed to extract texture archive " + zipFile + ": " + e);
         return null;
      }
      textureArchiveDir = outDir;
      return outDir;
   }

   /** Uploads decoded .cmp pixels as a real GL texture. GL_NEAREST, no
    * mipmaps: RenderWare 2's real fixed-function pipeline is the target,
    * not a modern filtered look - this session's explicit scope rule is
    * to add nothing RW2 didn't have, and there is no real evidence here
    * (yet) that it applied bilinear filtering, so the conservative,
    * unfiltered choice is used rather than assuming smoothing. GL_REPEAT:
    * real RWX UVs in this corpus carry a slight &gt;1.0 overshoot (see
    * RwxViewer's texturing note) that would streak under GL_CLAMP. */
   private static int uploadTexture(CmpTexture texture) {
      int id = glGenTextures();
      glBindTexture(GL_TEXTURE_2D, id);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
      ByteBuffer buf = ByteBuffer.allocateDirect(texture.rgb.length);
      // GL expects the first row uploaded to be the BOTTOM row: flip the
      // top-down decode (see RwxViewer's texturing note re: v=0 orientation).
      int rowBytes = texture.width * 3;
      for (int y = texture.height - 1; y >= 0; y--) {
         buf.put(texture.rgb, y * rowBytes, rowBytes);
      }
      buf.flip();
      // Filas de 3*ancho bytes sin relleno: con el alineamiento por
      // defecto (4) una textura de ancho no multiplo de 4 (windr3.mov,
      // 154 de ancho desde CmpFrames) saldria cizallada.
      glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture.width, texture.height,
         0, GL_RGB, GL_UNSIGNED_BYTE, buf);
      return id;
   }

    private static float[] identity() {
       return new float[]{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    }

    // --- Modo juego (--play): constantes del cliente original ---
    // PLAY_EYE_HEIGHT=150: SmoothDriver.eyeHeight / HoloPilot.loadInit.
    // PLAY_CAM_DIST=220: HoloPilot WIDESHOT (modo 8) moveTo(0,-220,-40).
    // PLAY_WALK_SPEED=250: entre maxdvLR=166 y maxdvFB=300 de SmoothDriver.
    // PLAY_RADIUS=30: medio ancho del bound box real setLocalBoundBox(
    // -30,-30,-v / 30,50,20) de HoloPilot. PLAY_STEP=30: stepHeight real.
    private static final float PLAY_EYE_HEIGHT = 150f;
    private static final float PLAY_CAM_DIST = 220f;
    private static final float PLAY_WALK_SPEED = 250f;
    private static final float PLAY_RADIUS = 30f;
    private static final float PLAY_STEP = 30f;
    private static final String PLAY_AVATAR_URL = "avatar:Aura.rwg";
    private static final java.util.Set<String> announcedPortals = new java.util.HashSet<>();

    /** (Re)carga una sala completa para --play: preload real (geometria +
     * bbox, igual que la carga inicial de renderRoom) + collectPlayfield
     * (suelo/bloqueantes/props/portales), limpiando antes las listas de
     * salida. Usado al cruzar un portal (crossPortal) para la sala
     * destino - MISMO camino que la sala inicial, sin atajos: la sala a
     * la que se llega por un portal se trata exactamente igual que la
     * sala con la que arranca el visor. Devuelve el bbox real (para el
     * frustum "inside"/near-far, ver el punto de llamada). */
    private static float[] loadPlayRoom(WNode room, List<float[][]> floorQuads, List<float[]> blockerBoxes,
          List<float[]> propTris, List<WNode> portalNodes, List<float[][]> portalQuads) {
       floorQuads.clear();
       blockerBoxes.clear();
       propTris.clear();
       portalNodes.clear();
       portalQuads.clear();
       float[] bbox = {Float.MAX_VALUE, Float.MAX_VALUE, Float.MAX_VALUE, -Float.MAX_VALUE, -Float.MAX_VALUE, -Float.MAX_VALUE};
       int[] objectCount = {0};
       preload(room, identity(), bbox, objectCount);
       if (room.environment != null) {
          preload(room.environment, identity(), bbox, objectCount);
       }
       collectPlayfield(room, identity(), floorQuads, blockerBoxes, propTris, portalNodes, portalQuads);
       if (room.environment != null) {
          collectPlayfield(room.environment, identity(), floorQuads, blockerBoxes, propTris, portalNodes, portalQuads);
       }
       return bbox;
    }

    /** Recorre el arbol real y clasifica geometria jugable (ver llamada en
     * renderRoom): suelos = Rect/RectPatch visibles (quads en coords mundo)
     * + triangulos de props; bloqueantes = AABB mundo (b[6]=1 si es bumper
     * invisible: esos paran SIEMPRE) de Rects no-piso + invisibles + AABB
     * por prop; portales = nodos .Portal reales (WNode, para resolver su
     * conexion via portalFarSidePortal) + su quad mundo (4 esquinas, mismo
     * RECT_CORNERS que cualquier otro Rect - un Portal ES un Rect, ver
     * Portal.restoreState v8/9 en WorldRestorer.readPortal). El cruce real
     * de sala se decide en crossPortal(), llamado desde el loop de juego
     * con estas listas. El fondo infinito es backdrop, no pisable. */
    private static void collectPlayfield(WNode n, float[] parentToWorld,
          List<float[][]> floors, List<float[]> blockers, List<float[]> propTris,
          List<WNode> portalNodes, List<float[][]> portalQuads) {
       float[] here = n.matrix != null ? multiply(parentToWorld, n.matrix) : parentToWorld;
       if (n.className.endsWith("Portal")) {
          float[][] q = new float[4][];
          for (int i = 0; i < 4; i++) {
             q[i] = transformPoint(here, RECT_CORNERS[i][0], RECT_CORNERS[i][1], RECT_CORNERS[i][2]);
          }
          portalNodes.add(n);
          portalQuads.add(q);
       }
       if (n.geometryUrl != null && !n.geometryUrl.startsWith("avatar:")) {
          // Props (.rwx/.rwg): el mobiliario tambien es suelo y tambien
          // estorba. Sin esto se atraviesa el kiosko andando y el snap de
          // suelo encadena superficies hasta el cielo (bug real 2026-09-14:
          // Player at z=2250). Modelos ya en cache por preload.
          RwxModel model = loadModel(n.geometryUrl);
          if (model != null) {
             float[] box = {Float.MAX_VALUE, Float.MAX_VALUE, Float.MAX_VALUE,
                -Float.MAX_VALUE, -Float.MAX_VALUE, -Float.MAX_VALUE, 0f};
             for (int[] t : model.triangles) {
                float[] a = transformPoint(here, model.vertices.get(t[0]).x,
                   model.vertices.get(t[0]).y, model.vertices.get(t[0]).z);
                float[] b = transformPoint(here, model.vertices.get(t[1]).x,
                   model.vertices.get(t[1]).y, model.vertices.get(t[1]).z);
                float[] c = transformPoint(here, model.vertices.get(t[2]).x,
                   model.vertices.get(t[2]).y, model.vertices.get(t[2]).z);
                propTris.add(new float[]{a[0], a[1], a[2], b[0], b[1], b[2], c[0], c[1], c[2]});
                for (float[] v : new float[][]{a, b, c}) {
                   box[0] = Math.min(box[0], v[0]); box[1] = Math.min(box[1], v[1]); box[2] = Math.min(box[2], v[2]);
                   box[3] = Math.max(box[3], v[0]); box[4] = Math.max(box[4], v[1]); box[5] = Math.max(box[5], v[2]);
                }
             }
             if (box[0] <= box[3]) {
                blockers.add(box);
             }
          }
       }
       if (isRect(n)) {
          float[][] q = new float[4][];
          for (int i = 0; i < 4; i++) {
             q[i] = transformPoint(here, RECT_CORNERS[i][0], RECT_CORNERS[i][1], RECT_CORNERS[i][2]);
          }
          if (n.isVisible() && isFloorQuad(q)) {
             floors.add(q);
          } else {
             float[] b = quadAabb(q);
             if (!n.isVisible()) {
                b[6] = 1f; // bumper: pared invisible, nunca se pisa ni se salta
             }
             blockers.add(b);
          }
       }
       if (isRectPatch(n) && n.rpVersion != 0) {
          float[][] q = new float[][]{
             transformPoint(here, 0, 0, n.rpZ[0]),
             transformPoint(here, n.rpXDim, 0, n.rpZ[1]),
             transformPoint(here, n.rpXDim, n.rpYDim, n.rpZ[2]),
             transformPoint(here, 0, n.rpYDim, n.rpZ[3])};
          if (n.isVisible()) {
             floors.add(q);
          } else {
             float[] b = quadAabb(q);
             b[6] = 1f;
             blockers.add(b);
          }
       }
       for (WNode c : n.children) {
          collectPlayfield(c, here, floors, blockers, propTris, portalNodes, portalQuads);
       }
    }

    /** Un quad es piso si su normal apunta a +-Z (los muros de Reception
     * traen escala (2149,2,400): normal horizontal; los suelos son planos
     * X/Y en mundo). Umbral 0.7 honesto y documentado. */
    private static boolean isFloorQuad(float[][] q) {
       float[] ux = {q[1][0] - q[0][0], q[1][1] - q[0][1], q[1][2] - q[0][2]};
       float[] vx = {q[3][0] - q[0][0], q[3][1] - q[0][1], q[3][2] - q[0][2]};
       float nx = ux[1] * vx[2] - ux[2] * vx[1];
       float ny = ux[2] * vx[0] - ux[0] * vx[2];
       float nz = ux[0] * vx[1] - ux[1] * vx[0];
       float l = (float) Math.sqrt(nx * nx + ny * ny + nz * nz);
       return l > 0 && Math.abs(nz / l) > 0.7f;
    }

    private static float[] quadAabb(float[][] q) {
       // b[6]: 1 = bumper invisible (para SIEMPRE, aunque este a ras de
       // suelo), 0 = geometria normal (se puede pisar si es baja).
       float[] b = {Float.MAX_VALUE, Float.MAX_VALUE, Float.MAX_VALUE,
          -Float.MAX_VALUE, -Float.MAX_VALUE, -Float.MAX_VALUE, 0f};
       for (float[] c : q) {
          b[0] = Math.min(b[0], c[0]); b[1] = Math.min(b[1], c[1]); b[2] = Math.min(b[2], c[2]);
          b[3] = Math.max(b[3], c[0]); b[4] = Math.max(b[4], c[1]); b[5] = Math.max(b[5], c[2]);
       }
       return b;
    }

    /** Room.floorHeight del original: el piso mas alto que no este por
     * encima de los pies + escalon (stepHeight=30 real). Si no hay nada
     * debajo, devuelve LOS PIES (no el limite consultado: devolver z
     * con z=pies+STEP fue el bug que lanzaba al jugador al cielo a
     * +30/frame al andar sobre vacio — 2026-09-14, Player at z=2250 =
     * 180+69x30 exactos). Quads: techo = esquina mas alta (aproximacion
     * documentada); tris de props: z interpolada en el plano (exacta). */
    private static float floorHeightAt(List<float[][]> floors, List<float[]> tris,
          float x, float y, float feetZ) {
       float z = feetZ + PLAY_STEP;
       float best = Float.NEGATIVE_INFINITY;
       boolean found = false;
       for (float[][] q : floors) {
          float top = q[0][2];
          for (int i = 1; i < 4; i++) {
             top = Math.max(top, q[i][2]);
          }
          if (top > z) {
             continue;
          }
          if (pointInQuad2D(q, x, y) && (!found || top > best)) {
             best = top;
             found = true;
          }
       }
       for (float[] t : tris) {
          float tz = triHeightAt(t, x, y);
          if (Float.isNaN(tz) || tz > z) {
             continue;
          }
          if (!found || tz > best) {
             best = tz;
             found = true;
          }
       }
       return found ? best : feetZ;
    }

    /** z del plano del triangulo en (x,y), o NaN si (x,y) cae fuera o el
     * triangulo es vertical/degenerado en 2D. */
    private static float triHeightAt(float[] t, float x, float y) {
       float ax = t[0], ay = t[1], az = t[2];
       float bx = t[3], by = t[4], bz = t[5];
       float cx = t[6], cy = t[7], cz = t[8];
       float den = (by - cy) * (ax - cx) + (cx - bx) * (ay - cy);
       if (Math.abs(den) < 1e-9f) {
          return Float.NaN;
       }
       float wa = ((by - cy) * (x - cx) + (cx - bx) * (y - cy)) / den;
       float wb = ((cy - ay) * (x - cx) + (ax - cx) * (y - cy)) / den;
       float wc = 1f - wa - wb;
       if (wa < 0f || wb < 0f || wc < 0f) {
          return Float.NaN;
       }
       return wa * az + wb * bz + wc * cz;
    }

    private static boolean pointInQuad2D(float[][] q, float x, float y) {
       return pointInTri2D(q[0], q[1], q[2], x, y) || pointInTri2D(q[0], q[2], q[3], x, y);
    }

    private static boolean pointInTri2D(float[] a, float[] b, float[] c, float x, float y) {
       float d1 = sign2D(x, y, a, b);
       float d2 = sign2D(x, y, b, c);
       float d3 = sign2D(x, y, c, a);
       boolean neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
       boolean pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
       return !(neg && pos);
    }

    private static float sign2D(float x, float y, float[] a, float[] b) {
       return (x - b[0]) * (a[1] - b[1]) - (a[0] - b[0]) * (y - b[1]);
    }

    /** Colision como AABB expandido por PLAY_RADIUS (aproximacion
     * documentada: la geometria real son quads/tris finos, no cajas).
     * Regla por altura, fiel al stepHeight=30 real: lo que supera los
     * pies + escalon para (muro/mueble), lo bajo se pisa, lo que esta
     * por encima de la cabeza no existe. Los bumpers invisibles (b[6])
     * paran SIEMPRE: son paredes de colision, nunca escalones. */
    private static boolean hitsBlocker(List<float[]> blockers, float x, float y, float feetZ) {
       for (float[] b : blockers) {
          if (b.length > 6 && b[6] == 1f) {
             if (b[2] > feetZ + PLAY_EYE_HEIGHT) {
                continue; // por encima de la cabeza
             }
          } else {
             if (b[5] <= feetZ + PLAY_STEP) {
                continue; // bajo o a ras de pies: se pisa, no para
             }
             if (b[2] > feetZ + PLAY_EYE_HEIGHT) {
                continue; // por encima de la cabeza
             }
          }
          if (x > b[0] - PLAY_RADIUS && x < b[3] + PLAY_RADIUS
             && y > b[1] - PLAY_RADIUS && y < b[4] + PLAY_RADIUS) {
             return true;
          }
       }
       return false;
    }

    /** Resultado de cruzar un portal conectado este frame: sala destino
     * (WNode real de world.roomsByName) + posicion/orientacion calculadas
     * exactamente como el cliente original - ver crossPortal(). */
    private static final class PortalCross {
       final WNode destRoom;
       final String destRoomName;
       final String srcName, farName;
       final float x, y, z, yaw;
       PortalCross(WNode destRoom, String destRoomName, String srcName, String farName, float x, float y, float z, float yaw) {
          this.destRoom = destRoom; this.destRoomName = destRoomName;
          this.srcName = srcName; this.farName = farName;
          this.x = x; this.y = y; this.z = z; this.yaw = yaw;
       }
    }

    /** Conexion de un portal tras restaurar el mundo (ver link()). */
    private static final class PortalState {
       /** 2 = activo (Portal._state); cualquier otro valor no cruza. */
       final int state;
       final WNode farPortal;
       final String farRoom;
       /** farx, fary, farz, fartheta (recomputeFarPosition o del fichero). */
       final float[] far;
       final String reason;
       PortalState(int state, WNode farPortal, String farRoom, float[] far, String reason) {
          this.state = state; this.farPortal = farPortal; this.farRoom = farRoom;
          this.far = far; this.reason = reason;
       }
    }

    private static final Map<WNode, PortalState> portalStates = new IdentityHashMap<>();

    /**
     * Estado de un portal como lo deja Portal.postRestore: con referencia
     * al portal lejano, newFarSide() -> estado 2 (salvo flag 0x40000) y
     * recomputeFarPosition(); sin ella, reset(): sin farSideRoomName o con
     * 0x40000 -> -1; sin farSideWorld, busca la sala por nombre y, si es
     * portal-a-portal, el portal por nombre entre los de esa sala
     * (findFarSidePortal -> newFarSide); en modo posicion reset() no toca
     * el estado, que sigue en -1; con farSideWorld -> 0 y World.load del
     * otro mundo (loadedURLSelf lo pasa a 2 solo si ese .world carga).
     */
    private static PortalState link(WNode p) {
       PortalState st = portalStates.get(p);
       if (st != null) {
          return st;
       }
       boolean blocked = (p.flags & 0x40000) != 0;
       boolean mirror = (p.flags & 4) != 0;
       WNode far = p.portalFarSidePortal;
       if (far == null && !blocked && p.portalFarSideRoomName != null && p.portalFarSideWorld == null
             && p.portalFarSideIsPortal && p.portalFarSidePortalName != null) {
          WNode farRoom = worldRoot.roomsByName.get(p.portalFarSideRoomName);
          if (farRoom != null) {
             for (Map.Entry<WNode, String> e : portalOwnerRoom.entrySet()) {
                if (e.getValue().equals(p.portalFarSideRoomName) && p.portalFarSidePortalName.equals(e.getKey().name)) {
                   far = e.getKey();
                   break;
                }
             }
          }
       }
       if (far != null) {
          st = blocked
             ? new PortalState(-1, far, null, null, "flag 0x40000 (newFarSide no lo activa)")
             : new PortalState(2, far, portalOwnerRoom.get(far), PortalLink.recomputeFarPosition(far, mirror), null);
       } else if (p.portalFarSideRoomName == null || blocked) {
          st = new PortalState(-1, null, null, null, blocked ? "flag 0x40000"
             : "sin sala de destino (farSideRoomName nulo): Portal.reset() lo deja en -1");
       } else if (p.portalFarSideWorld != null) {
          st = new PortalState(0, null, p.portalFarSideRoomName, null, otherWorldReason(p));
       } else if (worldRoot.roomsByName.get(p.portalFarSideRoomName) == null) {
          st = new PortalState(-1, null, null, null, "la sala " + p.portalFarSideRoomName + " no existe (Room-doesnt)");
       } else if (p.portalFarSideIsPortal) {
          st = new PortalState(-1, null, null, null, "no hay portal " + p.portalFarSidePortalName
             + " en " + p.portalFarSideRoomName + " (Portal-doesnt)");
       } else {
          st = new PortalState(-1, null, p.portalFarSideRoomName,
             new float[]{p.portalFarX, p.portalFarY, p.portalFarZ, p.portalFarTheta},
             "modo posicion en el mismo mundo: reset() no cambia el estado -1");
       }
       portalStates.put(p, st);
       return st;
    }

    /**
     * Portal a otro .world: el original lo carga con World.load y, si no
     * lo tiene, avisa (Dont-have-world) y pide el paquete al servidor de
     * actualizaciones (NetUpdate.loadWorld). "home:" es el directorio de
     * instalacion (el que contiene GroundZero/); "rel:" solo marca la URL
     * como relativa. Aqui solo se comprueba si ese fichero esta en el
     * corpus: cargar otro .world en el visor no esta hecho.
     */
    private static String otherWorldReason(WNode p) {
       String url = p.portalFarSideWorld;
       String path = url.startsWith("rel:") ? url.substring(4) : url;
       String where;
       if (path.startsWith("home:")) {
          File home = baseDir.getParentFile();
          File f = new File(home, path.substring(5));
          where = f.getPath() + (f.isFile() ? " (existe; cargar otro .world no esta implementado)" : " (no esta en el corpus)");
       } else {
          where = "URL no local";
       }
       return "otro mundo " + url + "#" + p.portalFarSideRoomName + "#" + p.portalFarSidePortalName + " -> " + where;
    }

    /**
     * Cruce real de un portal durante el movimiento de este frame (de p0 a
     * p0 + m), como el cliente original (ver PortalLink): solo portales
     * bumpables (flags bit 1, WObject.detectBump), en estado 2, cuyo borde
     * inferior corta el camino del lado que cruza (PassthroughBumpCalc ->
     * BumpEventTemp.isCollision); gana el corte mas cercano. Altura:
     * aproximacion documentada, el piloto ocupa [z, z + PLAY_EYE_HEIGHT]
     * y debe solaparse con el rango z del portal (el original compara la
     * caja del clump del avatar). Solo se prueban portales: el resto de la
     * colision es la del visor (hitsBlocker), no la del original. Destino:
     * _p2pxform (Portal.setTransform, gamma.dll 0x0041b170) aplicado a la
     * posicion de corte + 0.2 y, como vector, al resto del camino y al
     * avance del piloto; el rumbo sale de ahi (antes se ponia a mano un
     * yaw deducido; ahora es el de getYaw traducido, 0x00425440).
     */
    private static PortalCross crossPortal(List<WNode> portalNodes, List<float[][]> portalQuads,
          float x0, float y0, float z0, float mx, float my, float yaw) {
       int best = -1;
       float bestF = 2f;
       for (int i = 0; i < portalNodes.size(); i++) {
          WNode src = portalNodes.get(i);
          if ((src.flags & 2) == 0) {
             continue; // no bumpable: WObject.detectBump ni lo mira
          }
          float[] q = quadAabb(portalQuads.get(i));
          if (z0 > q[5] || z0 + PLAY_EYE_HEIGHT < q[2]) {
             continue;
          }
          float[] m = portalRoomMatrix.get(src);
          float[] dir = PortalLink.transformVector(m, 1f, 0f, 1f);
          float f = PortalLink.isCollision(m[12], m[13], dir[0], dir[1], x0, y0, mx, my);
          if (f < 0f || f >= bestF) {
             continue;
          }
          PortalState st = link(src);
          if (st.state != 2) {
             if (announcedPortals.add("unresolved:" + src.name)) {
                System.out.println("Portal \"" + src.name + "\": no cruza (estado " + st.state + ": " + st.reason + ").");
             }
             continue;
          }
          best = i;
          bestF = f;
       }
       if (best < 0) {
          return null;
       }
       WNode src = portalNodes.get(best);
       PortalState st = link(src);
       WNode destRoom = worldRoot.roomsByName.get(st.farRoom);
       float[] p2p = PortalLink.p2pTransform(portalRoomMatrix.get(src), src.xScale, src.yScale, src.zScale,
          (src.flags & 4) != 0, st.far[0], st.far[1], st.far[2], st.far[3]);
       float[] r = PortalLink.cross(p2p, new float[]{x0, y0, z0}, mx, my, 0f, bestF,
          new float[]{(float) Math.cos(yaw), (float) Math.sin(yaw), 0f});
       return new PortalCross(destRoom, st.farRoom, src.name, st.farPortal.name, r[0], r[1], r[2], r[3]);
    }

    /**
     * --list-portals: estado de cada portal del mundo (ver link()) y, para
     * los que cruzan, un cruce de prueba por el centro de su borde en su
     * sentido de cruce, con la sala, posicion y rumbo de llegada; si el
     * portal lejano vuelve a este, tambien la vuelta (ida y vuelta debe
     * dejar la misma matriz: comprueba la cadena getYaw/recompute/p2p).
     */
    private static void listPortals(WNode world) {
       List<String> names = new ArrayList<>(world.roomsByName.keySet());
       java.util.Collections.sort(names);
       int total = 0, crossable = 0, oneWayOk = 0, roundTrips = 0, roundTripOk = 0;
       Map<String, Integer> causes = new TreeMap<>();
       for (String rn : names) {
          List<WNode> ps = new ArrayList<>();
          for (Map.Entry<WNode, String> e : portalOwnerRoom.entrySet()) {
             if (e.getValue().equals(rn)) {
                ps.add(e.getKey());
             }
          }
          ps.sort((a, b) -> String.valueOf(a.name).compareTo(String.valueOf(b.name)));
          for (WNode p : ps) {
             total++;
             PortalState st = link(p);
             boolean bump = (p.flags & 2) != 0;
             String head = rn + " / " + p.name + " flags=0x" + Integer.toHexString(p.flags);
             if (st.state != 2 || !bump) {
                String cause = st.state != 2 ? "estado " + st.state + ": " + st.reason
                   : "no bumpable (flags bit 1 = 0: WObject.detectBump no lo mira)"
                      + ((p.flags & 4) != 0 ? ", espejo hacia " + st.farPortal.name : "");
                String key = cause.replaceAll("otro mundo .*", "otro mundo fuera del corpus");
                causes.merge(key, 1, Integer::sum);
                System.out.println("NO   " + head + " -> " + cause);
                continue;
             }
             crossable++;
             float[] m = portalRoomMatrix.get(p);
             float[] dir = PortalLink.transformVector(m, 1f, 0f, 1f);
             float len = (float) Math.sqrt(dir[0] * dir[0] + dir[1] * dir[1]);
             float nx = -dir[1] / len, ny = dir[0] / len; // izquierda del borde = lado de cruce
             float mx0 = m[12] + dir[0] / 2f, my0 = m[13] + dir[1] / 2f;
             float[] p2p = PortalLink.p2pTransform(m, p.xScale, p.yScale, p.zScale, (p.flags & 4) != 0,
                st.far[0], st.far[1], st.far[2], st.far[3]);
             float x0 = mx0 - 5f * nx, y0 = my0 - 5f * ny;
             float f = PortalLink.isCollision(m[12], m[13], dir[0], dir[1], x0, y0, 10f * nx, 10f * ny);
             float yaw0 = (float) Math.atan2(ny, nx);
             float[] r = PortalLink.cross(p2p, new float[]{x0, y0, m[14]}, 10f * nx, 10f * ny, 0f, f,
                new float[]{nx, ny, 0f});
             if (f >= 0f) {
                oneWayOk++;
             }
             String back = "";
             PortalState bs = link(st.farPortal);
             if (bs.state == 2 && bs.farPortal == p) {
                roundTrips++;
                float[] fm = portalRoomMatrix.get(st.farPortal);
                float[] q = PortalLink.p2pTransform(fm, st.farPortal.xScale, st.farPortal.yScale, st.farPortal.zScale,
                   (st.farPortal.flags & 4) != 0, bs.far[0], bs.far[1], bs.far[2], bs.far[3]);
                float[] id = mulRw(p2p, q);
                float err = 0f;
                float[] ident = identity();
                for (int k = 0; k < 16; k++) {
                   err = Math.max(err, Math.abs(id[k] - ident[k]));
                }
                if (err < 0.01f) {
                   roundTripOk++;
                }
                back = String.format(java.util.Locale.ROOT, " | vuelta por %s: |p2p.p2p' - I| = %.4g", st.farPortal.name, err);
             }
             System.out.println(String.format(java.util.Locale.ROOT,
                "SI   %s borde (%.1f, %.1f, %.1f) -> %s/%s  f=%.2f  llegada (%.1f, %.1f, %.1f) rumbo %.1f grados (entrada %.1f), fartheta %.1f%s",
                head, mx0, my0, m[14], st.farRoom, st.farPortal.name, f, r[0], r[1], r[2], Math.toDegrees(r[3]), Math.toDegrees(yaw0),
                st.far[3], back));
          }
       }
       System.out.println("---");
       System.out.println("Portales: " + total + ", cruzables (estado 2 y bumpables): " + crossable
          + ", cruce de prueba con corte: " + oneWayOk + "/" + crossable
          + ", ida y vuelta = identidad: " + roundTripOk + "/" + roundTrips);
       for (Map.Entry<String, Integer> e : causes.entrySet()) {
          System.out.println("  " + e.getValue() + " x " + e.getKey());
       }
    }

    /** Producto de matrices RW (a.b, vector fila). */
    private static float[] mulRw(float[] a, float[] b) {
       float[] o = new float[16];
       for (int i = 0; i < 4; i++) {
          for (int j = 0; j < 4; j++) {
             float sum = 0f;
             for (int k = 0; k < 4; k++) {
                sum += a[i * 4 + k] * b[k * 4 + j];
             }
             o[i * 4 + j] = sum;
          }
       }
       return o;
    }

    /** Recorre TODAS las salas una vez (llamado desde main() tras parsear
     * el mundo, antes de renderRoom) y guarda, por cada nodo Portal real,
     * su matriz local-a-sala acumulada + el nombre de su sala dueña - ver
     * portalRoomMatrix/portalOwnerRoom. Barato (578 nodos, sin GL). */
    private static void collectPortalMatrices(WNode world) {
       for (Map.Entry<String, WNode> e : world.roomsByName.entrySet()) {
          walkPortalMatrices(e.getValue(), identity(), e.getKey());
          if (e.getValue().environment != null) {
             walkPortalMatrices(e.getValue().environment, identity(), e.getKey());
          }
       }
    }

    private static void walkPortalMatrices(WNode n, float[] parentToWorld, String roomName) {
       float[] here = n.matrix != null ? multiply(parentToWorld, n.matrix) : parentToWorld;
       if (n.className.endsWith("Portal")) {
          portalRoomMatrix.put(n, here);
          portalOwnerRoom.put(n, roomName);
       }
       for (WNode c : n.children) {
          walkPortalMatrices(c, here, roomName);
       }
    }

    /** Forward vector from yaw/pitch. Z-up (client convention): yaw spins
     * in the x/y plane from +X, pitch raises toward +Z. Y-up legacy keeps
     * the old formulas (only reachable via explicit --up 0,1,0). */
    private static float[] fwdFromYawPitch(float yaw, float pitch, boolean upZ) {
       if (upZ) {
          return new float[]{(float) (Math.cos(pitch) * Math.cos(yaw)), (float) (Math.cos(pitch) * Math.sin(yaw)), (float) Math.sin(pitch)};
       }
       return new float[]{(float) (Math.cos(pitch) * Math.sin(yaw)), (float) Math.sin(pitch), (float) (-Math.cos(pitch) * Math.cos(yaw))};
    }

    /** Interior-camera small vector helpers (yaw/pitch fly controls). */
    private static boolean isDown(long window, int key) {
       return glfwGetKey(window, key) == GLFW_PRESS;
    }

    private static float[] add(float[] a, float[] b) {
       return new float[]{a[0] + b[0], a[1] + b[1], a[2] + b[2]};
    }

    private static float[] scale(float[] a, float s) {
       return new float[]{a[0] * s, a[1] * s, a[2] * s};
    }

    private static float[] norm(float[] a) {
       float l = (float) Math.sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
       return l > 0 ? scale(a, 1f / l) : new float[]{0, 0, -1};
    }

    private static float clamp(float v, float lo, float hi) {
       return Math.max(lo, Math.min(hi, v));
    }

   /** Column-major 4x4 multiply (a*b), matching the OpenGL/three.js convention RwxMatrix4 already uses - real semantics not yet independently confirmed for WObject's "guts" matrix beyond "the scene renders coherently", see docs/world-format-reference.md. */
   private static float[] multiply(float[] a, float[] b) {
      float[] r = new float[16];
      for (int col = 0; col < 4; col++) {
         for (int row = 0; row < 4; row++) {
            float sum = 0;
            for (int k = 0; k < 4; k++) {
               sum += a[k * 4 + row] * b[col * 4 + k];
            }
            r[col * 4 + row] = sum;
         }
      }
      return r;
   }

   private static float[] transformPoint(float[] m, float x, float y, float z) {
      return new float[]{
         m[0] * x + m[4] * y + m[8] * z + m[12],
         m[1] * x + m[5] * y + m[9] * z + m[13],
         m[2] * x + m[6] * y + m[10] * z + m[14]
      };
   }

   /** Same convention as transformPoint but WITHOUT translation (column 3)
    * - rotation+scale only, matching Point3Temp.vectorTimes(Transform)'s
    * native "vector transform" semantics (see this class's own header doc
    * quoting Transform.worldVecToObjectVec, and crossPortal()'s javadoc). */
   private static float[] transformVector(float[] m, float x, float y, float z) {
      return new float[]{
         m[0] * x + m[4] * y + m[8] * z,
         m[1] * x + m[5] * y + m[9] * z,
         m[2] * x + m[6] * y + m[10] * z
      };
   }

    private static float distance(float[] bbox) {
       if (bbox[0] > bbox[3]) {
          return 1f; // no geometry loaded at all
       }
       float dx = bbox[3] - bbox[0];
       float dy = bbox[4] - bbox[1];
       float dz = bbox[5] - bbox[2];
       return (float) Math.sqrt(dx * dx + dy * dy + dz * dz);
    }
}
