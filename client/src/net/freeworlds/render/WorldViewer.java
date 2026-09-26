package net.freeworlds.render;

import net.freeworlds.avatar.AnimAnimator;
import net.freeworlds.avatar.AnimPose;
import net.freeworlds.avatar.AnimRegistry;
import net.freeworlds.avatar.AnimSequence;
import net.freeworlds.avatar.AvatarFigure;
import net.freeworlds.avatar.AvatarLooks;
import net.freeworlds.avatar.AvatarNameDecoder;
import net.freeworlds.avatar.AvatarRig;
import net.freeworlds.avatar.ServerTables;
import net.freeworlds.cmp.CmpTexture;
import net.freeworlds.bod.BodFile;
import net.freeworlds.bod.BodParser;
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
import org.lwjgl.opengl.GL14;
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
 * Avatares: las referencias "avatar:Nombre.rwg" (6 en GroundZero, en las
 * galerias IconViewRoom1a/b/c/e/f/g) y el avatar del jugador de --play se
 * resuelven al .bod oficial del mismo nombre en
 * assets/gammatutorial-samples/base-avatars/ (jing/julie/paul/roxanne/
 * simon; Tre no existe y usa aura.bod, el default real del cliente,
 * PosableShape.defaultURL). Desde 2026-09-25 se dibujan como el original
 * (net.freeworlds.avatar, portado del puente, ver drawAvatar):
 * - prepFigure (FUN_00434f00): escala 1000 y giro de 180 grados sobre
 *   (0,1,1), que lleva el +Y del .bod a +Z y deja los pies en z = 0. (Antes
 *   era una heuristica x1000 con (x,y,z) -&gt; (x,z,y), que es un espejo.)
 * - aspecto por nombre de avatar (AvatarLooks, como BodViewer --avatar:
 *   texturas .cmp/.mov con su subimagen y colores);
 * - animacion con la regla de gamma.dll (DroneAnimator): quieto 10 s -&gt;
 *   wait, 30 s -&gt; endwait, 10 s -&gt; wait; andar -&gt; walk sincronizado
 *   con la distancia; pararse -&gt; wait; mezclas de 250 ms. Tipos y
 *   secuencias del Avatars.dat de base-avatars.
 * Los avatares de las galerias no se mueven en este visor (sus MoveAction
 * no se ejecutan): pasan de reposo a wait a los 10 s.
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
   // Display lists por modelo y por luz local (DriverLight.objectKey): los
   // colores de cada poligono dependen de las luces de la sala llevadas al
   // espacio del objeto, asi que un mismo modelo girado distinto necesita
   // otra lista. Optimizacion de rendimiento period-correct (listas de
   // OpenGL 1.x): captura la MISMA secuencia que el modo inmediato,
   // compilada una vez. Valida solo dentro del contexto GL actual — se
   // limpia al crear/destruir cada ventana (modo ALL crea un contexto por
   // sala).
   private static final Map<RwxModel, Map<Long, Integer>> displayListCache = new IdentityHashMap<>();
   /** Normales de RW por modelo (ver modelNormals): no dependen del contexto GL. */
   private static final Map<RwxModel, float[][]> modelNormalCache = new IdentityHashMap<>();
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

    // --- Avatares .bod animados (ver drawAvatar y net.freeworlds.avatar) ---
    /** Un .bod ya leido por URL "avatar:..." (compartido entre figuras). */
    private static final class AvatarModel {
       BodFile bod;
       File bodFile;
       boolean usedFallback; // este slot usa aura.bod por defecto
       Map<Integer, AvatarLooks.Look> looks;
       /** false si el nombre trae SZZZ (PosableShape.runPrepFigure). */
       boolean runPrepFigure = true;
       /** DroneAnimator.getnameindex del tipo, o -1 (sin animador ni prepFigure). */
       int figureType = -1;
       /** Caja en el sistema del PosableShape, pose de reposo (encuadre y bbox de sala). */
       float[] bounds;
    }
    /** Una figura en escena (PosableShape): su arbol, su animador y su closestView. */
    private static final class AvatarInstance {
       final AvatarModel model;
       final AvatarRig rig;
       AnimAnimator animator;
       float closestView = 10000.0F;
       int farViewCount;
       int lastImplicit = 1;
       List<AvatarRig.Tri> tris;

       AvatarInstance(AvatarModel model, AvatarRig rig) {
          this.model = model;
          this.rig = rig;
       }
    }
    private static final Map<String, AvatarModel> avatarModels = new HashMap<>();
    /** Por WNode (avatares del mundo) o PLAYER_AVATAR_KEY. */
    private static final Map<Object, AvatarInstance> avatarInstances = new IdentityHashMap<>();
    private static final Object PLAYER_AVATAR_KEY = new Object();
    private static final Map<CmpTexture, Integer> avatarTextureIds = new IdentityHashMap<>();
    private static File avatarDir;
    private static boolean avatarDirChecked = false;
    private static ServerTables avatarTablesCache;
    private static boolean avatarTablesChecked = false;
    private static AnimRegistry animRegistryCache;
    private static AnimSequence.Library animLibrary;
    private static boolean animRegistryChecked = false;
    /** Std.getRealTime del frame (ms): reloj real, o 1000/30 ms por tick del autopiloto (determinista). */
    private static int animClockMs = 1000;
    /** -Dfreeworlds.animLog=true: cambios de implicito de todos los avatares, no solo del jugador. */
    private static final boolean ANIM_LOG = Boolean.getBoolean("freeworlds.animLog");
    /** Matriz objeto-a-mundo del nodo que drawNode esta dibujando (vector fila / GL por columnas). */
    private static float[] drawWorld = new float[]{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    /** --shot-at TICK:PNG (solo con --walk-to): capturas en ticks concretos del autopiloto. */
    private static final java.util.TreeMap<Integer, String> shotAt = new java.util.TreeMap<>();

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
         // Java2D solo dibuja el atlas del HUD (HudText) en una imagen: sin
         // ventana AWT, que en macOS competiria con GLFW por el hilo principal.
         if (System.getProperty("java.awt.headless") == null) {
            System.setProperty("java.awt.headless", "true");
         }
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
          } else if (args[i].equals("--shot-at") && i + 1 < args.length) {
             // --shot-at TICK:PNG (repetible, con --walk-to): captura en ese
             // tick del autopiloto y termina tras la ultima.
             String v = args[++i];
             int c = v.indexOf(':');
             shotAt.put(Integer.parseInt(v.substring(0, c)), v.substring(c + 1));
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
       float px = RESTART_AT[0], py = RESTART_AT[1], pz = RESTART_AT[2];
       float spawnYaw = 0f;
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
       {
          float[] sp = spawnFor(room, roomName, bbox);
          px = sp[0];
          py = sp[1];
          pz = sp[2];
          spawnYaw = sp[3];
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

      // -Dfreeworlds.windowSize=AxB: otro tamano (p. ej. el aspecto de la
      // vista del original, 468x272, para comparar capturas con el puente).
      int width = 1024;
      int height = 768;
      String size = System.getProperty("freeworlds.windowSize");
      if (size != null && size.matches("\\d+x\\d+")) {
         width = Integer.parseInt(size.substring(0, size.indexOf('x')));
         height = Integer.parseInt(size.substring(size.indexOf('x') + 1));
      }
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
         // ESC or window close button exits the interactive viewer; in
         // play mode ESC opens the pause menu instead (menuKey).
         final boolean pauseMenu = play;
         glfwSetKeyCallback(window, (win, key, scancode, action, mods) -> {
            if (pauseMenu) {
               if (action == GLFW_PRESS || action == GLFW_REPEAT) {
                  menuKey(win, key);
               }
            } else if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
               glfwSetWindowShouldClose(win, true);
            }
         });
      }
      displayListCache.clear(); // IDs del contexto anterior (modo ALL) no valen aqui
      glTextureCache.clear(); // GL texture ids: mismo motivo, otro contexto
      avatarTextureIds.clear();

      glEnable(GL_DEPTH_TEST);
      glClearColor(0.10f, 0.10f, 0.14f, 1f);
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      initDriverLighting();

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
            yaw = spawnYaw;
            pitch = 0f;
            System.out.println("Play mode: spawn " + roomName + " (" + px + "," + py + "," + pz + ") yaw="
               + Math.round(Math.toDegrees(yaw)) + " grados, avatar=aura.bod (default real del cliente)");
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
      double animStart = lastTime;
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
         // Std.getRealTime del frame para los avatares (ver animClockMs).
         // El autopiloto es de paso fijo por tick: su reloj tambien.
         if (play && walkToArg != null) {
            animClockMs = 1000 + autopilotTicks * 1000 / 30;
         } else {
            animClockMs = 1000 + (int) ((now - animStart) * 1000.0);
         }
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
            PortalCross cross = null;
            if (pendingRoom != null && !autopilot) {
               // "Ir a otra sala" del menu de pausa: TeleportAction con la
               // sala sin posicion (su defaultPosition), ver spawnFor.
               cross = teleportCross(pendingRoom);
               pendingRoom = null;
               if (cross != null) {
                  System.out.println("Menu: ir a la sala \"" + cross.destRoomName + "\"");
               }
            }
            if (cross == null && (dx != 0f || dy != 0f)) {
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
                  cross = crossPortal(portalNodes, portalQuads, p0x, p0y, p0z, px - p0x, py - p0y, yaw);
                  if (cross != null) {
                     System.out.println("Cruzando portal \"" + cross.srcName + "\" (sala \"" + roomName
                        + "\", de " + p0x + "," + p0y + "," + p0z + " a " + px + "," + py + ") -> \"" + cross.farName
                        + "\" (sala \"" + cross.destRoomName + "\")");
                  }
               }
            }
            if (cross != null) {
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
             roomLights(room);
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
             // Tercera persona como el original al arrancar (HoloPilot
             // CAM_MODE_BEHIND, medido en el puente): la camara mira al
             // punto de ojo (pies + 150, eyeHeight de SmoothDriver) desde
             // 140 unidades por detras, inclinada 10 grados hacia abajo, y
             // se acerca si hay un muro por medio (la camara del original
             // es bumpable). Las flechas UP/DOWN suman a esa inclinacion.
             float[] view = fwdFromYawPitch(yaw, pitch + PLAY_CAM_PITCH, true);
             float hx = px, hy = py, hz = pz + PLAY_EYE_HEIGHT;
             float dist = cameraDistance(blockerBoxes, hx, hy, hz, view);
             float[] camEye = {hx - view[0] * dist, hy - view[1] * dist, hz - view[2] * dist};
             float[] camCenter = {hx, hy, hz};
             float[] camUp = {0f, 0f, 1f};
             if (PORTALS) {
                // Salas vistas a traves de los portales, antes que la propia
                // (Room.prerender del original, ver drawPortals).
                float aspect = (float) width / height;
                drawPortals(room, camEye, camCenter, camUp, aspect, near, far, width, height,
                   new int[]{0, 0, width, height}, 0, false);
                glMatrixMode(GL_PROJECTION);
                glLoadIdentity();
                GlUtil.perspective(60f, aspect, near, far);
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                glClear(GL_DEPTH_BUFFER_BIT);
             }
             GlUtil.lookAt(camEye[0], camEye[1], camEye[2], camCenter[0], camCenter[1], camCenter[2], camUp[0], camUp[1], camUp[2]);
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

           roomLights(room); // drawPortals las cambio por las de cada sala lejana
           drawNode(room);
           if (room.environment != null) {
              drawNode(room.environment);
           }
           if (play) {
              // Avatar del jugador (aura.bod = default real del cliente,
              // PosableShape.defaultURL), animado como cualquier PosableShape
              // (drawAvatar). Forward VERIFICADO: cara y puntas de pies en
              // +Z local del .bod (Y-up) — medido en SPIN.RWX y en bytes de
              // aura.bod; prepFigure (AvatarRig) lleva ese +Z al +Y del
              // objeto. Girar el objeto t sobre Z lleva (0,1,0) a (-sin t,
              // cos t): igualar al facing (cos yaw, sin yaw) da t = yaw - 90.
              float t = yaw - (float) (Math.PI / 2);
              float ct = (float) Math.cos(t), st = (float) Math.sin(t);
              float[] playerToWorld = {ct, st, 0, 0, -st, ct, 0, 0, 0, 0, 1, 0, px, py, pz, 1};
              glPushMatrix();
              try (MemoryStack stack = MemoryStack.stackPush()) {
                 FloatBuffer pb = stack.mallocFloat(16);
                 pb.put(playerToWorld).flip();
                 glMultMatrixf(pb);
              }
              if (drawAvatar(PLAYER_AVATAR_KEY, PLAY_AVATAR_URL, playerToWorld, 1.0F)) {
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
          if (autopilot && shotAt.containsKey(autopilotTicks)) {
             GlUtil.saveScreenshot(width, height, shotAt.get(autopilotTicks));
             AvatarInstance pl = avatarInstances.get(PLAYER_AVATAR_KEY);
             System.out.println("--shot-at: tick " + autopilotTicks + " (t=" + animClockMs + " ms) jugador en ("
                + px + "," + py + "," + pz + ")" + (pl != null && pl.animator != null
                   ? " implicito " + pl.animator.implicitIndex() + " (" + pl.animator.implicitName() + ")" : "")
                + " -> " + shotAt.get(autopilotTicks));
             if (autopilotTicks >= shotAt.lastKey()) {
                autopilotDone = true;
             }
          }
          if (autopilot) {
             if (!crossedThisFrame && screenshotBeforePath != null) {
                GlUtil.saveScreenshot(width, height, screenshotBeforePath);
             } else if (crossedThisFrame && screenshotAfterPath != null) {
                GlUtil.saveScreenshot(width, height, screenshotAfterPath);
                System.out.println("PortalCrossHarness: screenshots guardadas (" + screenshotBeforePath
                   + " / " + screenshotAfterPath + ")");
             }
          }
          if (play && visible) {
             drawHud(width, height, roomName, now);
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
      avatarTextureIds.clear();
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
             AvatarModel av = resolveAvatar(n.geometryUrl);
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

    /** Extiende el bbox con las 8 esquinas de la caja del avatar en el
     * sistema del PosableShape (tras prepFigure, pose de reposo), pasadas
     * por la matriz compuesta del nodo. */
    private static void extendAvatarBbox(float[] bbox, float[] here, AvatarModel av) {
       float[] b = av.bounds;
       if (b == null || !(b[3] > b[0]) || !(b[5] > b[2])) {
          return; // .bod degenerado: no ensancha el encuadre con basura
       }
       for (int i = 0; i < 8; i++) {
          extendBbox(bbox, transformPoint(here, b[(i & 1) == 0 ? 0 : 3], b[(i & 2) == 0 ? 1 : 4], b[(i & 4) == 0 ? 2 : 5]));
       }
    }

    /** Resuelve "avatar:Nombre.rwg" al .bod base oficial del mismo nombre
     * (comparacion case-insensitive). Si no existe, usa aura.bod, el
     * default real del cliente (PosableShape.defaultURL). null solo si ni
     * siquiera hay fallback en disco. Ademas: el aspecto del nombre
     * (AvatarLooks), el tipo de figura de Avatars.dat y la caja tras
     * prepFigure. */
    private static AvatarModel resolveAvatar(String url) {
       if (avatarModels.containsKey(url)) {
          return avatarModels.get(url);
       }
       File dir = resolveAvatarDir();
       AvatarModel av = null;
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
             av = loadAvatarModel(url, f, false);
          }
          if (av == null) {
             File aura = findIgnoreCase(dir, "aura.bod");
             if (aura != null) {
                av = loadAvatarModel(url, aura, true);
                if (av != null) {
                   System.out.println("Avatar \"" + url + "\": no hay .bod propio, usando aura.bod (default real del cliente)");
                }
             }
          }
       }
       avatarModels.put(url, av);
       return av;
    }

    private static AvatarModel loadAvatarModel(String url, File f, boolean fallback) {
       AvatarModel av = new AvatarModel();
       av.usedFallback = fallback;
       av.bodFile = f;
       try {
          av.bod = BodParser.parse(Files.readAllBytes(f.toPath()));
       } catch (Exception e) {
          System.err.println("Avatar: no se pudo leer " + f + ": " + e);
          return null;
       }
       // Aspecto por el nombre (PosableShape.createSubparts): igual que BodViewer --avatar.
       ServerTables tables = avatarTables();
       AvatarFigure fig = null;
       if (tables != null) {
          try {
             fig = AvatarNameDecoder.decode(url, tables.permittedHash());
             AvatarLooks.Result res = AvatarLooks.resolve(fig, f, f.getParentFile());
             av.looks = res.byTag;
             System.out.println(AvatarLooks.report(url, fig, res));
          } catch (Exception e) {
             System.out.println("Avatar \"" + url + "\": sin aspecto por nombre (" + e.getMessage() + ")");
          }
       }
       av.runPrepFigure = fig == null || fig.prepFigure;
       // PosableShape.getFigureType -> getBodyType (PosableShape.java:874)
       // -> DroneAnimator.getnameindex (FUN_0042c8a0).
       String body = bodyType(url, tables);
       AnimRegistry reg = animRegistry();
       av.figureType = body == null || reg == null ? -1 : reg.nameIndex(body);
       AvatarRig probe = new AvatarRig(av.bod, av.looks);
       if (av.figureType != -1 && av.runPrepFigure) {
          probe.prepFigure();
       }
       av.bounds = probe.bounds();
       System.out.println("Avatar \"" + url + "\": " + f.getName() + ", tipo de figura " + av.figureType
          + (body != null ? " (\"" + body + "\")" : "") + (av.figureType == -1 ? " sin animador" : "")
          + ", alto " + (av.bounds[5] - av.bounds[2]));
       return av;
    }

    /**
     * PosableShape.getBodyType(URL) (PosableShape.java:874): "avatar:X.rwg"
     * -> X en minusculas hasta el primer punto; si tras el punto no viene
     * '0' (nombre corto), getBodyType(String) (PosableShape.java:960) lo
     * traduce por permittedHash y se queda con lo que hay antes del punto.
     * (convertLODToParent no se porta: el visor no usa LOD.)
     */
    static String bodyType(String url, ServerTables tables) {
       if (url == null || !url.startsWith("avatar:") || !(url.endsWith(".rwg") || url.endsWith(".RWG"))
             || url.length() < 8 || url.charAt(7) == '.') {
          return null;
       }
       int dot = url.indexOf('.', 7);
       String body = url.substring(7, dot).toLowerCase();
       if (url.charAt(dot + 1) != '0' && tables != null) {
          String full = tables.permittedHash().get(body);
          if (full != null) {
             body = full.substring(0, full.indexOf('.'));
          }
       }
       return body;
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

    /** tables.dat de la instalacion (permittedList para los nombres cortos), o null. */
    private static ServerTables avatarTables() {
       if (!avatarTablesChecked) {
          avatarTablesChecked = true;
          File t = new File(baseDir, "../tables/tables.dat");
          try {
             if (t.isFile()) {
                avatarTablesCache = ServerTables.load(t.toPath());
             }
          } catch (Exception e) {
             System.err.println("Avatar: no se pudo leer " + t + ": " + e);
          }
       }
       return avatarTablesCache;
    }

    /**
     * El registro de animacion: DroneAnimator.loadconfig (FUN_00434b70) de
     * PendingCacheDrone.getAvatarDatPath. En este repo, el Avatars.dat de
     * base-avatars (junto a sus .seq con nombre); para los 7 avatares de
     * GroundZero (aura, jing, julie, paul, roxanne, simon, tre) sus
     * implicitos son los mismos que en el 45.dat de cachedir (walk =
     * common_walk, wait = common_a_wait, endwait = common_a_endwait).
     * Archive.readTextFile quita los CR (FUN_00403eb0).
     */
    private static AnimRegistry animRegistry() {
       if (!animRegistryChecked) {
          animRegistryChecked = true;
          File dir = resolveAvatarDir();
          File dat = dir == null ? null : findIgnoreCase(dir, "Avatars.dat");
          if (dat != null) {
             try {
                byte[] raw = Files.readAllBytes(dat.toPath());
                java.io.ByteArrayOutputStream o = new java.io.ByteArrayOutputStream();
                for (byte b : raw) {
                   if (b != 13) {
                      o.write(b);
                   }
                }
                AnimRegistry reg = AnimRegistry.get();
                reg.clear();
                reg.load(o.toByteArray(), dat.getPath());
                animRegistryCache = reg;
                animLibrary = new AnimSequence.Library(dir);
                System.out.println("Animacion: " + reg.size() + " tipos de avatar en " + dat);
             } catch (Exception e) {
                System.err.println("Animacion: " + dat + ": " + e);
             }
          }
       }
       return animRegistryCache;
    }

    /**
     * La figura de un PosableShape (un nodo del mundo o el jugador): como
     * PosableShape.recursiveAddRwChildren (PosableShape.java:125), si hay
     * tipo de figura se hace prepFigure (si el nombre no lo prohibe) y se
     * crea el animador (DroneAnimator.CreateRep); sin tipo, ni una cosa ni
     * la otra (la figura queda a la escala del .bod, como en el original).
     */
    private static AvatarInstance avatarInstance(Object key, AvatarModel av) {
       AvatarInstance ai = avatarInstances.get(key);
       if (ai == null || ai.model != av) {
          ai = new AvatarInstance(av, new AvatarRig(av.bod, av.looks));
          AnimRegistry reg = animRegistry();
          if (av.figureType != -1 && reg != null) {
             if (av.runPrepFigure) {
                ai.rig.prepFigure();
             }
             ai.animator = new AnimAnimator(reg, animLibrary, animClockMs);
          }
          avatarInstances.put(key, ai);
       }
       return ai;
    }

    /**
     * Dibuja un avatar bajo la matriz GL actual (la del nodo, o la del
     * jugador), animado con la regla de gamma.dll. Por frame, lo que hace
     * el PosableShape original:
     * <ol>
     * <li>handle(FrameEvent) (PosableShape.java:1219): si hay animador y
     *     closestView (del frame anterior) no pasa de 900, moveto(tipo,
     *     (short) x/y/z del objeto en el mundo, (short) -getYaw(), t - 1) y
     *     update(null, figura, t, getScaleX()); luego closestView = 10000.
     *     La pose resultante se aplica a la figura (FUN_00434470).</li>
     * <li>prerender (PosableShape.java:1122): posicion del objeto en el
     *     espacio de la camara; si z &gt; 1 y |x| &lt; z, closestView =
     *     min(closestView, z), y si z &gt; 700 durante mas de 10 frames se
     *     fuerza closestView &lt;= 400 (un update de vez en cuando aunque
     *     este lejos).</li>
     * </ol>
     * ⚠️ No se porta setLOD (doLOD): el visor no tiene niveles de detalle.
     *
     * @param objToWorld matriz del objeto en el mundo (getObjectToWorldMatrix:
     *                   modelado x LTM del padre, sin el joint de la figura)
     * @param scaleX     getScaleX del Transform del objeto
     */
    private static boolean drawAvatar(Object key, String url, float[] objToWorld, float scaleX) {
       AvatarModel av = resolveAvatar(url);
       if (av == null) {
          return false;
       }
       AvatarInstance ai = avatarInstance(key, av);
       float view = ai.closestView;
       ai.closestView = 10000.0F;
       if (ai.animator != null && !(view > 900.0F)) {
          int t = animClockMs;
          short yaw = (short) (-AvatarRig.transformYaw(objToWorld));
          ai.animator.moveto(av.figureType, (short) objToWorld[12], (short) objToWorld[13], (short) objToWorld[14], yaw, t - 1);
          AnimPose pose = ai.animator.update(t, AnimAnimator.updateScale(scaleX, ai.rig.pelvisM00()));
          ai.rig.applyPose(pose);
          ai.tris = null;
          if (ai.animator.implicitIndex() != ai.lastImplicit) {
             if (key == PLAYER_AVATAR_KEY || ANIM_LOG) {
                System.out.println("[anim] " + (key == PLAYER_AVATAR_KEY ? "jugador" : url) + " t=" + t + " ms: implicito "
                   + ai.lastImplicit + " -> " + ai.animator.implicitIndex() + " (" + ai.animator.implicitName() + ")");
             }
             ai.lastImplicit = ai.animator.implicitIndex();
          }
       }
       // prerender: origen del objeto en el espacio de la camara (GL mira
       // hacia -z; RenderWare hacia +z).
       try (MemoryStack stack = MemoryStack.stackPush()) {
          FloatBuffer mv = stack.mallocFloat(16);
          glGetFloatv(GL_MODELVIEW_MATRIX, mv);
          float cx = mv.get(12);
          float cz = -mv.get(14);
          if (cz > 1.0F && cx < cz && -cx < cz) {
             if (ai.closestView > cz) {
                ai.closestView = cz;
             }
             if (cz > 700.0F && ++ai.farViewCount > 10) {
                if (ai.closestView > 400.0F) {
                   ai.closestView = 400.0F;
                }
                ai.farViewCount = 0;
             }
          }
       }
       if (ai.tris == null) {
          ai.tris = ai.rig.triangles();
       }
       if (ai.tris.isEmpty()) {
          return false;
       }
       DriverLight.object(objToWorld);
       drawAvatarTris(ai.tris);
       drawnTriangles += ai.tris.size();
       avatarDrawnCount++;
       if (av.usedFallback) {
          avatarFallbackCount++;
       }
       return true;
    }

    /** Triangulos del avatar: color plano por clump o textura del nombre,
     * iluminados por DriverLight, ambas caras (bobinado sin verificar). Los
     * dos materiales son lisos (gamma.dll FUN_0041d950 y PosableShape:
     * superficie 0.32/0.55/0 y FUN_00417a10), asi que los triangulos sin
     * textura van con luz por vertice: la normal de cada vertice es la suma
     * sin pesos de las de los triangulos de su parte (clump) que lo
     * comparten, como RwCalculateClumpVertexNormal (RWL21 0x10041df0; el
     * .bod no trae normales); los texturizados, por cara. */
    private static void drawAvatarTris(List<AvatarRig.Tri> tris) {
       // normales de cara (espacio del objeto) y de vertice por (parte, indice)
       int nt = tris.size();
       float[][] faceN = new float[nt][];
       Map<Long, float[]> vSum = new HashMap<>();
       Map<Long, float[]> vFirst = new HashMap<>();
       for (int k = 0; k < nt; k++) {
          AvatarRig.Tri t = tris.get(k);
          float[] p = t.p;
          faceN[k] = DriverLight.polygonNormal(new float[][]{{p[0], p[1], p[2]}, {p[3], p[4], p[5]}, {p[6], p[7], p[8]}});
          for (int j = 0; j < 3; j++) {
             long key = ((long) t.limb << 32) | (t.vi[j] & 0xFFFFFFFFL);
             float[] s = vSum.computeIfAbsent(key, x -> new float[3]);
             s[0] += faceN[k][0];
             s[1] += faceN[k][1];
             s[2] += faceN[k][2];
             vFirst.putIfAbsent(key, faceN[k]);
          }
       }
       for (Map.Entry<Long, float[]> e : vSum.entrySet()) {
          float[] s = e.getValue();
          float len = (float) Math.sqrt(s[0] * s[0] + s[1] * s[1] + s[2] * s[2]);
          if (len > 0f) {
             s[0] /= len;
             s[1] /= len;
             s[2] /= len;
          } else {
             System.arraycopy(vFirst.get(e.getKey()), 0, s, 0, 3);
          }
       }
       boolean first = true;
       boolean inBegin = false;
       float lr = 0f, lg = 0f, lb = 0f;
       CmpTexture lastTex = null;
       boolean lastAvatarMat = false;
       RwxMaterial mat = null;
       glDisable(GL_CULL_FACE);
       for (int k = 0; k < nt; k++) {
          AvatarRig.Tri t = tris.get(k);
          if (first || t.r != lr || t.g != lg || t.b != lb || t.texture != lastTex || t.avatarMaterial != lastAvatarMat) {
             if (inBegin) {
                glEnd();
                inBegin = false;
             }
             if (t.texture != null) {
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, avatarTextureId(t.texture));
             } else {
                glDisable(GL_TEXTURE_2D);
             }
             mat = t.avatarMaterial ? avatarNameMaterial(t.r, t.g, t.b) : bodAvatarMaterial(t.r, t.g, t.b);
             lr = t.r;
             lg = t.g;
             lb = t.b;
             lastTex = t.texture;
             lastAvatarMat = t.avatarMaterial;
             first = false;
          }
          if (!inBegin) {
             glBegin(GL_TRIANGLES);
             inBegin = true;
          }
          float[] p = t.p;
          float[] n = faceN[k];
          boolean textured = t.texture != null;
          if (textured) {
             driverColour(mat.rwAmbient(), mat.diffuse, mat.specular, true, true, mat.colorR, mat.colorG, mat.colorB,
                mat.opacity, n[0], n[1], n[2]);
          }
          for (int j = 0; j < 3; j++) {
             if (!textured) {
                float[] vn = vSum.get(((long) t.limb << 32) | (t.vi[j] & 0xFFFFFFFFL));
                driverColour(mat.rwAmbient(), mat.diffuse, mat.specular, false, true, mat.colorR, mat.colorG, mat.colorB,
                   mat.opacity, vn[0], vn[1], vn[2]);
             }
             if (t.texture != null) {
                glTexCoord2f(t.uv[j * 2], t.uv[j * 2 + 1]);
             }
             glVertex3f(p[j * 3], p[j * 3 + 1], p[j * 3 + 2]);
          }
       }
       if (inBegin) {
          glEnd();
       }
       glDisable(GL_TEXTURE_2D);
       glEnable(GL_CULL_FACE);
    }

    /** Id GL de una textura de avatar (una subida por contexto; uploadTexture ya fija GL_UNPACK_ALIGNMENT 1). */
    private static int avatarTextureId(CmpTexture tex) {
       Integer id = avatarTextureIds.get(tex);
       if (id == null) {
          id = uploadTexture(tex);
          avatarTextureIds.put(tex, id);
       }
       return id;
    }

    /** Material de una limb con textura o color del nombre de avatar:
     * new Material(0.32f, 0.55f, 0.0f, ...) de PosableShape.scanTexture /
     * readColor (PosableShape.java:255, 303), como BodViewer. ⚠️ VERIFICAR:
     * con textura el color del cliente es colorTable[3]; si RenderWare 2
     * tine la textura con el no esta verificado (se dibuja sin tintar). */
    private static RwxMaterial avatarNameMaterial(float r, float g, float b) {
       RwxMaterial mat = new RwxMaterial();
       mat.colorR = r;
       mat.colorG = g;
       mat.colorB = b;
       mat.ambient = 0.32f;
       mat.ambientSet = true;
       mat.diffuse = 0.55f;
       mat.specular = 0.0f;
       mat.opacity = 1f;
       mat.lightSampling = 2; // PosableShape: smooth = true
       return mat;
    }

    /** Material de una parte .bod sin textura de nombre: el de gamma.dll
     * FUN_0041d950, RwSetMaterialSurface(0.32, 0.55, 0.0) (DAT_00470ac4,
     * DAT_00470ac0, DAT_00470abc) y liso (FUN_00417a10), con el color de la
     * parte. Antes, un placeholder 0.3/0.8/0.1. */
    private static RwxMaterial bodAvatarMaterial(float r, float g, float b) {
       RwxMaterial mat = new RwxMaterial();
       mat.colorR = r;
       mat.colorG = g;
       mat.colorB = b;
       mat.ambient = 0.32f;
       mat.ambientSet = true;
       mat.diffuse = 0.55f;
       mat.specular = 0.0f;
       mat.opacity = 1f;
       mat.lightSampling = 2;
       return mat;
    }

    /** A Rect is a unit quad in its local X/Z plane (NOT X/Y: real
     * matrices squash local Y to ~zero — e.g. wall scale (2149,2,400) —
     * while (1,0,1) reproduces the decompiled far corner (f1,f2,f3)
     * exactly through spin(atan2(f2,f1)) about Z + scale(len,f3,f3)).
     * Verified corner-by-corner against groundzero.world Reception. */
    private static final float[][] RECT_CORNERS = {{0, 0, 0}, {1, 0, 0}, {1, 0, 1}, {0, 0, 1}};
    /** See drawRect: the original culls the back of every Rect. */
    private static final boolean RECT_DOUBLE_SIDED = Boolean.getBoolean("freeworlds.rectDoubleSided");

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

    /** Las dos luces de una sala (Room.addRwChildren; el entorno y el fondo
     * infinito, RoomEnvironment.addLight, llevan las mismas). */
    private static void roomLights(WNode room) {
       DriverLight.room(room.lightPosition, room.lightColorRGB == null ? DriverLight.DEFAULT_COLOR : room.lightColorRGB);
    }

    private static void drawNode(WNode n) {
       glPushMatrix();
       float[] parentWorld = drawWorld;
       if (n.matrix != null) {
          drawWorld = multiply(drawWorld, n.matrix);
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
       if (visibleLeaf && (n.geometryUrl != null || isRect(n) || isRectPatch(n))) {
          DriverLight.object(drawWorld); // luces de la sala en el espacio de este objeto (el LTM de RW)
       }
       if (n.geometryUrl != null) {
          if (n.geometryUrl.startsWith("avatar:")) {
             if (visibleLeaf) {
                if (drawAvatar(n, n.geometryUrl, drawWorld, n.xScale)) {
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
       drawWorld = parentWorld;
       glPopMatrix();
    }

    private static boolean isRectPatch(WNode n) {
       return n.className.endsWith(".RectPatch");
    }

    /** Draws one RectPatch (v1+ with material; v0 is explicitly invisible
     * in the client and skipped) as RectPatch.createAppearance builds it:
     * four triangles from each edge to the centre (xDim/2, yDim/2, mean of
     * the four heights), corners (0,0) z[0], (0,yDim) z[1], (xDim,yDim)
     * z[2], (xDim,0) z[3], with its tile clamps (1..31) and offset rule.
     * Before this it was one quad with z[1] and z[3] swapped — invisible on
     * GroundZero, where every patch is flat. Lit per triangle by
     * DriverLight and one-sided like every world polygon (see drawRect). */
    private static void drawRectPatch(WNode n) {
       if (n.rpVersion == 0) {
          return; // explicitly invisible: setVisible(false) in restoreState
       }
       if (!(n.rpXDim > 0f) || !(n.rpYDim > 0f)) {
          return; // createAppearance draws nothing
       }
       WorldSurface sf = worldSurface(n.material);
       GlLighting.applyCulling(RECT_DOUBLE_SIDED);
       int glTex = resolveRectTexture(n.material != null ? n.material.matTextureUrl : null);
       boolean texEnabled = false;
       if (glTex != 0) {
          glEnable(GL_TEXTURE_2D);
          glBindTexture(GL_TEXTURE_2D, glTex);
          texEnabled = true;
       }
       float xt = n.rpXTile <= 0f ? 1f : Math.min(n.rpXTile, 31f);
       float yt = n.rpYTile <= 0f ? 1f : Math.min(n.rpYTile, 31f);
       float xo = n.rpXTileOff < 0f ? 1f - (float) Math.floor(n.rpXTileOff) + n.rpXTileOff : n.rpXTileOff;
       float yo = n.rpYTileOff < 0f ? 1f - (float) Math.floor(n.rpYTileOff) + n.rpYTileOff : n.rpYTileOff;
       float[] z = n.rpZ;
       float[][] corner = {
          {0f, 0f, z[0], xo, yo},
          {0f, n.rpYDim, z[1], xo, yo + yt},
          {n.rpXDim, n.rpYDim, z[2], xo + xt, yo + yt},
          {n.rpXDim, 0f, z[3], xo + xt, yo}};
       float[] centre = {n.rpXDim / 2f, n.rpYDim / 2f, (z[0] + z[1] + z[2] + z[3]) / 4f, xo + xt / 2f, yo + yt / 2f};
       glBegin(GL_TRIANGLES);
       for (int k = 0; k < 4; k++) {
          float[][] tri = {corner[k], centre, corner[(k + 1) % 4]};
          float[] nn = DriverLight.polygonNormal(tri);
          surfaceColour(sf, texEnabled, nn);
          for (float[] c : tri) {
             // v de RW cuenta desde arriba; la textura se sube volteada
             glTexCoord2f(c[3], 1f - c[4]);
             glVertex3f(c[0], c[1], c[2]);
          }
       }
       glEnd();
       if (texEnabled) {
          glDisable(GL_TEXTURE_2D);
       }
       glEnable(GL_CULL_FACE);
       drawnTriangles += 4;
       drawnObjects++;
    }

    /** Lo que DriverLight necesita de un Material del mundo. */
    private static final class WorldSurface {
       float amb, dif, spec, r, g, b, opacity = 1f;
       boolean litTexture;
    }

    /**
     * Un Material del mundo como lo monta el puente (natives.patch,
     * Material.makeMaterial): color / 256, ambiente, difusa y especular tal
     * cual, y la textura iluminada salvo en un material plano
     * "auto-iluminado" (gamma.dll FUN_00417950: ambiente ~0.75 sin difusa
     * ni especular, el de new Material(URL)/Material(Color)); uno liso
     * (smoothShading, FUN_00417a10) siempre la ilumina. Sin material: el
     * de new Material() (todo a cero).
     */
    private static WorldSurface worldSurface(WNode m) {
       WorldSurface s = new WorldSurface();
       if (m == null) {
          s.litTexture = true;
          return s;
       }
       s.amb = m.matAmbient;
       s.dif = m.matDiffuse;
       s.spec = m.matSpecular;
       s.opacity = m.matOpacity;
       s.r = ((m.matColorRGB >> 16) & 0xFF) * 0.00390625f;
       s.g = ((m.matColorRGB >> 8) & 0xFF) * 0.00390625f;
       s.b = (m.matColorRGB & 0xFF) * 0.00390625f;
       s.litTexture = m.matSmooth || !DriverLight.selfLit(s.amb, s.dif, s.spec);
       return s;
    }

    /** new Material(URL) (el de AnimateAction): ambiente 0.75, gris 128, plano -> textura sin iluminar. */
    private static final WorldSurface URL_SURFACE = urlSurface();

    private static WorldSurface urlSurface() {
       WorldSurface s = new WorldSurface();
       s.amb = 0.75f;
       s.r = s.g = s.b = 128 * 0.00390625f;
       s.litTexture = !DriverLight.selfLit(s.amb, s.dif, s.spec);
       return s;
    }

    private static void surfaceColour(WorldSurface s, boolean textured, float[] n) {
       driverColour(s.amb, s.dif, s.spec, textured, s.litTexture, s.r, s.g, s.b, s.opacity, n[0], n[1], n[2]);
    }

    /** Una celda de Surface.addSubPolys (MaterialTiles.rectCells) con su textura y el color de DriverLight. */
    private static void drawRectCell(float[] c, int glTex, WorldSurface sf) {
       if (glTex != 0) {
          glEnable(GL_TEXTURE_2D);
          glBindTexture(GL_TEXTURE_2D, glTex);
       }
       surfaceColour(sf, glTex != 0, RECT_NORMAL);
       // v de RW cuenta desde la fila de arriba; la textura se sube
       // volteada (uploadTexture), asi que t de GL = 1 - v.
       glBegin(GL_QUADS);
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

    /** El Billboard de un Rect (su Sharer lleva los atributos), o null. */
    private static WNode billboardOf(WNode n) {
       if (n.sharer == null || n.sharer.attributes == null) {
          return null;
       }
       for (WNode a : n.sharer.attributes) {
          if (a != null && a.className.endsWith(".Billboard")) {
             return a;
          }
       }
       return null;
    }

    /** Billboard._defTextureURL: IniFile.override() "defaultAd", por defecto adworlds.cmp (en home:). */
    private static final String DEFAULT_AD = System.getProperty("freeworlds.defaultAd", "adworlds.cmp");

    /**
     * Rect con Billboard (un anuncio): Billboard.assignMaterial le pone
     * new Material(URL(defaultAd), max(1, xSurface/128), max(1, ySurface/128))
     * y parte el Rect en esas celdas (Surface.addSubPolys). Cada subtextura
     * es el fichero ENTERO (Material.syncBackgroundLoad ->
     * TextureDecoder.decode(subURL, fichero base)); el control de IE que la
     * sustituiria por el anuncio de la red no existe, asi que cada celda
     * lleva el logo completo, como en el original bajo el puente. El
     * material es el de Material(URL, h, v): ambiente 0.75 sin difusa ->
     * textura sin iluminar. El material guardado en el .world (una
     * ScapePicTexture de c:/internalgdk/ del autor) no se usa.
     */
    private static void drawBillboard(WNode n, WNode bb) {
       int hRes = Math.max(1, bb.billboardX / 128), vRes = Math.max(1, bb.billboardY / 128);
       String[] why = new String[1];
       int glTex = rectTextureId(DEFAULT_AD, 0, 1, false, why);
       GlLighting.applyCulling(RECT_DOUBLE_SIDED);
       for (float[] c : MaterialTiles.rectCells(n.rectU, n.rectV, n.rectUOff, n.rectVOff, n.flags, hRes, vRes)) {
          drawRectCell(c, glTex, URL_SURFACE);
       }
       glEnable(GL_CULL_FACE);
       drawnObjects++;
    }

    /** Normal de poligono de un Rect en su espacio: (0,-1,0) para (0,0,0) (1,0,0) (1,0,1) (0,0,1). */
    private static final float[] RECT_NORMAL = DriverLight.polygonNormal(new float[][]{
       {0, 0, 0}, {1, 0, 0}, {1, 0, 1}, {0, 0, 1}});

    /**
     * Surface.uvOutOfRange como lo traduce el puente: con "Flip Alternate
     * U/V" (flags 0x80000 / 0x100000) o con alguna UV de Rect.addRwChildren
     * fuera de [0, 32], el original parte el Rect en celdas
     * (Surface.addSubPolys) en vez de dibujar un solo poligono.
     */
    private static boolean rectUvOutOfRange(WNode n, float[][] uv) {
       if ((n.flags & 0x100000) != 0 || (n.flags & 0x80000) != 0) {
          return true;
       }
       for (float[] t : uv) {
          if (t[0] < 0f || !(t[0] <= 32f) || t[1] < 0f || !(t[1] <= 32f)) {
             return true;
          }
       }
       return false;
    }

    /** UVs de RW de las esquinas de un Rect (Rect.addRwChildren): uOff*u y vOff*v modulo 2, v contada desde arriba. */
    private static float[][] rectUvs(WNode n) {
       float u = n.rectU, v = n.rectV;
       float uo = n.rectUOff;
       if (uo != 0f) {
          uo *= u;
          uo = (float) (uo - 2.0 * Math.floor(uo / 2.0F));
       }
       float vo = n.rectVOff;
       if (vo != 0f) {
          vo *= v;
          vo = (float) (vo - 2.0 * Math.floor(vo / 2.0F));
       }
       return new float[][]{{uo, v + vo}, {u + uo, v + vo}, {u + uo, vo}, {uo, vo}};
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
     * GL_REPEAT, set at upload). One-sided, as the original: the driver
     * pass drops every back polygon whose material lacks MaterialModes
     * double (bridge NativeCamera.drawClump, `!front && (materialModes &
     * 0x80) == 0`), and a world Material never sets it (only a .rwx
     * "MaterialModes Double" does). RW's front, area &lt; 0 with its
     * mirrored screen x and downward y, is counter-clockwise as seen on
     * screen, GL's default front face; the vertices go in Rect.java's
     * order (0,0,0) (1,0,0) (1,0,1) (0,0,1). Drawn double-sided before,
     * walls seen from behind covered the views through portals (the
     * building of ReceptionView1 hid the landscape) and showed mirrored
     * signs. -Dfreeworlds.rectDoubleSided=true brings that back.
     *
     * Material: el del nodo, o el que haya puesto una AnimateAction
     * (textureActions.materialOverride, ver TextureActions). Con sufijo
     * "Nh*"/"Nv*" (Material.getHiRes) el Rect se parte en las celdas de
     * Surface.addSubPolys, cada una con su textura (MaterialTiles): asi se
     * ven los .mov de GroundZero, cuyos frames son esas celdas. */
    private static void drawRect(WNode n) {
       WNode billboard = billboardOf(n);
       if (billboard != null) {
          drawBillboard(n, billboard);
          return;
       }
       String override = textureActions == null ? null : textureActions.materialOverride.get(n);
       String url = override != null ? override : (n.material != null ? n.material.matTextureUrl : null);
       WorldSurface sf = override != null ? URL_SURFACE : worldSurface(n.material);
       GlLighting.applyCulling(RECT_DOUBLE_SIDED);
       if (url == null && override == null && n.material != null && n.material.matPicUrl != null) {
          // Textura como objeto ScapePicTexture (no como URL de Material):
          // un solo fichero, sin reparto h/v.
          url = n.material.matPicUrl;
       }
       MaterialTiles tiles = url == null ? null : MaterialTiles.of(url.trim());
       float[][] uv = rectUvs(n);
       boolean hiRes = tiles != null && tiles.hiRes();
       if (hiRes || (url != null && rectUvOutOfRange(n, uv))) {
          // Surface.addSubPolys: una celda por repeticion de la textura (y
          // por subtextura en un material hi-res), con el espejado alterno.
          int[] ids = resolveRectTextures(url);
          int hRes = hiRes ? tiles.hRes : 1, vRes = hiRes ? tiles.vRes : 1;
          for (float[] c : MaterialTiles.rectCells(n.rectU, n.rectV, n.rectUOff, n.rectVOff, n.flags, hRes, vRes)) {
             int cell = (int) c[8];
             drawRectCell(c, cell < ids.length ? ids[cell] : 0, sf);
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
       // Un solo poligono con las UV de Rect.addRwChildren (el driver repite
       // la textura dentro de [0, 32], como GL_REPEAT); t de GL = 1 - v.
       surfaceColour(sf, texEnabled, RECT_NORMAL);
       glBegin(GL_QUADS);
       for (int i = 0; i < 4; i++) {
          glTexCoord2f(uv[i][0], 1f - uv[i][1]);
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
       Map<Long, Integer> lists = displayListCache.computeIfAbsent(model, k -> new HashMap<>());
       long key = DriverLight.objectKey();
       Integer list = lists.get(key);
       if (list == null) {
          if (lists.size() >= 32) {
             // un objeto que no para de girar: se empieza de nuevo en vez de crecer
             for (int id : lists.values()) {
                glDeleteLists(id, 1);
             }
             lists.clear();
          }
          list = glGenLists(1);
          glNewList(list, GL_COMPILE);
          emitModelImmediate(model);
          glEndList();
          lists.put(key, list);
       }
       glCallList(list);
    }

    /** GL para DriverLight: sin luces de GL; el color de cada poligono o
     * vertice como color primario y el termino hacia el blanco de la
     * rampa como color secundario, sumado despues de la textura
     * (GL_COLOR_SUM, GL 1.4); mezcla alfa para Opacity como antes. */
    private static void initDriverLighting() {
       glDisable(GL_LIGHTING);
       glShadeModel(GL_SMOOTH);
       glEnable(GL14.GL_COLOR_SUM);
       glEnable(GL_BLEND);
       glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
       glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    }

    private static final float[] litI = new float[3];
    private static final float[] litP = new float[3];
    private static final float[] litS = new float[3];
    private static final float[] litC = new float[3];

    /**
     * Color de un poligono (o de un vertice, con su normal) segun el driver
     * del original (DriverLight). Con textura: sin iluminar la textura tal
     * cual; iluminada, texel * P + S de la rampa. Sin textura: el color
     * exacto de la rampa. La normal va en el espacio del objeto (el de
     * DriverLight.object).
     */
    private static void driverColour(float amb, float dif, float spec, boolean textured, boolean litTexture,
          float r, float g, float b, float opacity, float nx, float ny, float nz) {
       if (textured && !litTexture) {
          glColor4f(1f, 1f, 1f, opacity);
          GL14.glSecondaryColor3f(0f, 0f, 0f);
          return;
       }
       DriverLight.intensity(amb, dif, spec, nx, ny, nz, litI);
       if (textured) {
          DriverLight.rampFactors(litI, litP, litS);
          glColor4f(litP[0], litP[1], litP[2], opacity);
          GL14.glSecondaryColor3f(litS[0], litS[1], litS[2]);
       } else {
          DriverLight.rampColor(r, g, b, litI, litC);
          glColor4f(litC[0], litC[1], litC[2], opacity);
          GL14.glSecondaryColor3f(0f, 0f, 0f);
       }
    }

    /**
     * Normales de RenderWare de un modelo: [0] la del poligono de cada
     * triangulo (RWL21 0x10001100: suma de los productos vectoriales del
     * abanico, igual a la suma de los triangulos de cualquier
     * triangulacion, normalizada) y [1] la de cada vertice para LightSampling
     * Vertex (0x10041df0: suma SIN pesos de las normales de los poligonos
     * que comparten el vertice del script, normalizada; si se anula, la del
     * primero; la Normal del script manda).
     */
    private static float[][] modelNormals(RwxModel model) {
       float[][] cached = modelNormalCache.get(model);
       if (cached != null) {
          return cached;
       }
       int nt = model.triangles.size();
       Map<Integer, float[]> polySum = new HashMap<>();
       for (int i = 0; i < nt; i++) {
          int[] t = model.triangles.get(i);
          RwxVector3 a = model.vertices.get(t[0]), b = model.vertices.get(t[1]), c = model.vertices.get(t[2]);
          float ax = b.x - a.x, ay = b.y - a.y, az = b.z - a.z;
          float bx = c.x - a.x, by = c.y - a.y, bz = c.z - a.z;
          float[] s = polySum.computeIfAbsent(model.trianglePolygons.get(i), k -> new float[3]);
          s[0] += ay * bz - az * by;
          s[1] += az * bx - ax * bz;
          s[2] += ax * by - ay * bx;
       }
       for (float[] s : polySum.values()) {
          float len = (float) Math.sqrt(s[0] * s[0] + s[1] * s[1] + s[2] * s[2]);
          if (len > 0f) {
             s[0] /= len;
             s[1] /= len;
             s[2] /= len;
          }
       }
       float[] tri = new float[nt * 3];
       Map<Integer, float[]> vSum = new HashMap<>();
       Map<Integer, float[]> vFirst = new HashMap<>();
       java.util.Set<Long> counted = new java.util.HashSet<>();
       for (int i = 0; i < nt; i++) {
          int poly = model.trianglePolygons.get(i);
          float[] pn = polySum.get(poly);
          tri[i * 3] = pn[0];
          tri[i * 3 + 1] = pn[1];
          tri[i * 3 + 2] = pn[2];
          for (int vi : model.triangles.get(i)) {
             int key = model.vertexKeys.get(vi);
             if (key >= 0 && counted.add(((long) key << 32) | (poly & 0xFFFFFFFFL))) {
                float[] s = vSum.computeIfAbsent(key, k -> new float[3]);
                s[0] += pn[0];
                s[1] += pn[1];
                s[2] += pn[2];
                vFirst.putIfAbsent(key, pn);
             }
          }
       }
       int nv = model.vertices.size();
       float[] vert = new float[nv * 3];
       for (int i = 0; i < nt; i++) {
          float[] pn = polySum.get(model.trianglePolygons.get(i));
          for (int vi : model.triangles.get(i)) {
             float[] set = model.vertexNormals.get(vi);
             float[] n = set;
             if (n == null) {
                int key = model.vertexKeys.get(vi);
                float[] s = key >= 0 ? vSum.get(key) : null;
                if (s == null) {
                   n = pn;
                } else {
                   float len = (float) Math.sqrt(s[0] * s[0] + s[1] * s[1] + s[2] * s[2]);
                   n = len > 0f ? new float[]{s[0] / len, s[1] / len, s[2] / len} : vFirst.get(key);
                }
             }
             vert[vi * 3] = n[0];
             vert[vi * 3 + 1] = n[1];
             vert[vi * 3 + 2] = n[2];
          }
       }
       float[][] out = {tri, vert};
       modelNormalCache.put(model, out);
       return out;
    }

     /** Secuencia inmediata (color de DriverLight/glTexCoord/glVertex por triangulo) — unica fuente de verdad visual; la display list solo la captura. Los colores son los del driver con las luces de DriverLight.object en ese momento. */
    private static void emitModelImmediate(RwxModel model) {
       RwxMaterial lastMat = null;
      boolean inBegin = false;
      boolean texEnabled = false;
      boolean textured = false;
      float[][] normals = modelNormals(model);
      float[] triN = normals[0], vertN = normals[1];
      for (int i = 0; i < model.triangles.size(); i++) {
         RwxMaterial mat = model.triangleMaterials.get(i);
         if (mat != lastMat) {
            if (inBegin) {
               glEnd();
               inBegin = false;
            }
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
            textured = glTex != 0;
            lastMat = mat;
         }
         if (!inBegin) {
            glBegin(GL_TRIANGLES);
            inBegin = true;
         }
         int[] t = model.triangles.get(i);
         // El driver ilumina por vertice solo un poligono sin textura de un
         // material LightSampling Vertex (bridge NativeCamera.drawClump).
         boolean vertexLit = mat.lightSampling == 2 && mat.textureName == null;
         float amb = mat.rwAmbient();
         if (!vertexLit) {
            driverColour(amb, mat.diffuse, mat.specular, textured, mat.rwLit(), mat.colorR, mat.colorG, mat.colorB,
               mat.opacity, triN[i * 3], triN[i * 3 + 1], triN[i * 3 + 2]);
         }
         for (int j = 0; j < 3; j++) {
            int vi = t[j];
            if (vertexLit) {
               driverColour(amb, mat.diffuse, mat.specular, false, true, mat.colorR, mat.colorG, mat.colorB,
                  mat.opacity, vertN[vi * 3], vertN[vi * 3 + 1], vertN[vi * 3 + 2]);
            }
            RwxVector3 v = model.vertices.get(vi);
            float[] uv = model.uvs.get(vi);
            glTexCoord2f(uv[0], uv[1]);
            glVertex3f(v.x, v.y, v.z);
         }
      }
      if (inBegin) {
         glEnd();
      }
      if (texEnabled) {
         glDisable(GL_TEXTURE_2D);
      }
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
       if (baseDir.getParentFile() != null) {
          dirs.add(baseDir.getParentFile()); // home: (la instalacion), p. ej. adworlds.cmp de los Billboard
       }
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
    * just above by driverColour - never an invented texture).
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
    // PLAY_CAM_DIST=140, PLAY_CAM_PITCH=-10: HoloPilot BEHIND (modo 7)
    // moveTo(0,-140,0).postspin(1,0,0,-10), el modo con que arranca el
    // original (en el puente, camara a 137.9 en horizontal y +24.3 del ojo:
    // 140*cos 10 y 140*sin 10). Antes era WIDESHOT (modo 8, 220), que en
    // salas pequenas dejaba la camara al otro lado de la pared.
    // PLAY_WALK_SPEED=250: entre maxdvLR=166 y maxdvFB=300 de SmoothDriver.
    // PLAY_RADIUS=30: medio ancho del bound box real setLocalBoundBox(
    // -30,-30,-v / 30,50,20) de HoloPilot. PLAY_STEP=30: stepHeight real.
    /**
     * worlds.ini RestartAt of the 2004 install:
     * home:GroundZero/GroundZero.world#Reception<>@1872.0,1229.0,150.0,125.0,0.0,0.0,-1.0
     * (x, y, z, rot, axis: TeleportAction.setFromURL).
     */
    private static final float[] RESTART_AT = {1872f, 1229f, 150f, 125f, 0f, 0f, -1f};

    /**
     * Where the pilot starts in a room and where it looks, as TeleportAction
     * does it: moveTo(pos).spin(axis, rot) on an identity pilot, whose
     * forward is +Y. Measured on the bridge (camera behind the pilot): the
     * default room AvatarEnter (261 degrees about (0,0,-1)) faces
     * (-0.97,-0.15) and Reception at its RestartAt (125 about (0,0,-1))
     * faces (0.81,-0.56); both are +Y turned to the heading 90 + s*rot
     * degrees for a spin about (0,0,s). (The viewer used to face Reception
     * towards the kiosk, -148 degrees, chosen by hand; the original faces
     * -35.) Reception uses the install's RestartAt, as the original on
     * startup; any other room its defaultPosition/defaultOrientation, or the
     * centre of its box when that point is outside it (the 500,500,120 of
     * rooms that were never given one). Returns {x, y, z, yaw radians}.
     */
    static float[] spawnFor(WNode room, String roomName, float[] bbox) {
       float x, y, z, rot, az;
       if ("Reception".equals(roomName) || room.defaultPosition == null) {
          x = RESTART_AT[0];
          y = RESTART_AT[1];
          z = RESTART_AT[2];
          rot = RESTART_AT[3];
          az = RESTART_AT[6];
       } else {
          x = room.defaultPosition[0];
          y = room.defaultPosition[1];
          z = room.defaultPosition[2];
          rot = room.defaultOrientation;
          az = room.defaultOrientationAxis == null ? -1f : room.defaultOrientationAxis[2];
       }
       if (bbox[0] <= bbox[3] && (x < bbox[0] || x > bbox[3] || y < bbox[1] || y > bbox[4])) {
          x = (bbox[0] + bbox[3]) / 2f;
          y = (bbox[1] + bbox[4]) / 2f;
          z = Math.max(bbox[2], Math.min(bbox[5], z));
       }
       float heading = 90f + Math.signum(az == 0f ? -1f : az) * rot;
       return new float[]{x, y, z, (float) Math.toRadians(heading)};
    }

    // --- Menu de pausa y HUD (--play con ventana) ---
    private static final String[] MENU = {"Continuar", "Ir a otra sala", "Mostrar FPS", "Ayuda de controles", "Salir"};
    private static volatile boolean menuOpen;
    private static int menuSel;
    private static boolean menuRooms;
    private static int roomSel;
    /** Sala pedida desde el menu; la aplica el bucle de juego (como un cruce de portal). */
    private static volatile String pendingRoom;
    private static boolean showFps = Boolean.getBoolean("freeworlds.fps");
    private static boolean showHelp = true;
    private static double helpUntil = -1.0;
    private static HudText hud;
    private static HudText hudBig;
    private static List<String> menuRoomNames;
    private static int fpsFrames;
    private static double fpsMark;
    private static int fpsShown;

    private static List<String> roomNames() {
       if (menuRoomNames == null) {
          menuRoomNames = new ArrayList<>(worldRoot.roomsByName.keySet());
          java.util.Collections.sort(menuRoomNames, String.CASE_INSENSITIVE_ORDER);
       }
       return menuRoomNames;
    }

    /** Teclas en modo juego: ESC abre/cierra el menu; con el menu abierto, flechas + Intro. */
    private static void menuKey(long win, int key) {
       if (!menuOpen) {
          if (key == GLFW_KEY_ESCAPE) {
             menuOpen = true;
             menuSel = 0;
             menuRooms = false;
          } else if (key == GLFW_KEY_F3) {
             showFps = !showFps;
          } else if (key == GLFW_KEY_F1) {
             showHelp = !showHelp;
             helpUntil = -1.0;
          }
          return;
       }
       boolean up = key == GLFW_KEY_UP || key == GLFW_KEY_W;
       boolean down = key == GLFW_KEY_DOWN || key == GLFW_KEY_S;
       boolean ok = key == GLFW_KEY_ENTER || key == GLFW_KEY_KP_ENTER || key == GLFW_KEY_SPACE;
       if (menuRooms) {
          List<String> names = roomNames();
          if (key == GLFW_KEY_ESCAPE || key == GLFW_KEY_BACKSPACE) {
             menuRooms = false;
          } else if (up) {
             roomSel = (roomSel + names.size() - 1) % names.size();
          } else if (down) {
             roomSel = (roomSel + 1) % names.size();
          } else if (key == GLFW_KEY_PAGE_UP) {
             roomSel = Math.max(0, roomSel - 10);
          } else if (key == GLFW_KEY_PAGE_DOWN) {
             roomSel = Math.min(names.size() - 1, roomSel + 10);
          } else if (ok) {
             pendingRoom = names.get(roomSel);
             menuRooms = false;
             menuOpen = false;
          }
          return;
       }
       if (key == GLFW_KEY_ESCAPE) {
          menuOpen = false;
       } else if (up) {
          menuSel = (menuSel + MENU.length - 1) % MENU.length;
       } else if (down) {
          menuSel = (menuSel + 1) % MENU.length;
       } else if (ok) {
          switch (menuSel) {
             case 0:
                menuOpen = false;
                break;
             case 1:
                menuRooms = true;
                break;
             case 2:
                showFps = !showFps;
                break;
             case 3:
                showHelp = !showHelp;
                helpUntil = -1.0;
                break;
             default:
                glfwSetWindowShouldClose(win, true);
          }
       }
    }

    /** El cruce de "Ir a otra sala": la sala por nombre, en su punto de entrada (spawnFor). */
    private static PortalCross teleportCross(String name) {
       WNode dest = worldRoot.roomsByName.get(name);
       if (dest == null) {
          return null;
       }
       float[] bb = {Float.MAX_VALUE, Float.MAX_VALUE, Float.MAX_VALUE, -Float.MAX_VALUE, -Float.MAX_VALUE, -Float.MAX_VALUE};
       int[] count = {0};
       preload(dest, identity(), bb, count);
       if (dest.environment != null) {
          preload(dest.environment, identity(), bb, count);
       }
       float[] sp = spawnFor(dest, name, bb);
       return new PortalCross(dest, name, "(menu)", "(menu)", sp[0], sp[1], sp[2], sp[3]);
    }

    /** Sala, FPS, ayuda y el menu de pausa, sobre el frame ya dibujado. */
    private static void drawHud(int w, int h, String roomName, double now) {
       if (hud == null) {
          hud = new HudText(16);
          hudBig = new HudText(24);
          fpsMark = now;
       }
       if (helpUntil < 0.0 && showHelp) {
          helpUntil = now + 12.0;
       }
       fpsFrames++;
       if (now - fpsMark >= 1.0) {
          fpsShown = (int) Math.round(fpsFrames / (now - fpsMark));
          fpsFrames = 0;
          fpsMark = now;
       }
       HudText.begin(w, h);
       hud.drawShadowed(12, 10, roomName, 1f, 1f, 1f);
       if (showFps) {
          String f = fpsShown + " fps";
          hud.drawShadowed(w - 12 - hud.width(f), 10, f, 1f, 0.9f, 0.4f);
       }
       if (!menuOpen && showHelp && now < helpUntil) {
          String[] lines = {"W/S andar   A/D de lado   flechas: girar y mirar", "ESC menu   F3 fps   F1 esta ayuda"};
          float y = h - 16 - lines.length * hud.lineHeight;
          for (String l : lines) {
             hud.drawShadowed(12, y, l, 0.85f, 0.9f, 1f);
             y += hud.lineHeight;
          }
       }
       if (menuOpen) {
          HudText.rect(0, 0, w, h, 0f, 0f, 0.05f, 0.55f);
          if (!menuRooms) {
             float bw = 360, bh = 60 + MENU.length * (hud.lineHeight + 14);
             float bx = (w - bw) / 2f, by = (h - bh) / 2f;
             HudText.rect(bx, by, bw, bh, 0.08f, 0.10f, 0.20f, 0.92f);
             hudBig.drawShadowed(bx + 20, by + 12, "FreeWorlds", 1f, 1f, 1f);
             float y = by + 56;
             for (int i = 0; i < MENU.length; i++) {
                String label = MENU[i];
                if (i == 2) {
                   label += showFps ? ": si" : ": no";
                } else if (i == 3) {
                   label += showHelp ? ": si" : ": no";
                }
                if (i == menuSel) {
                   HudText.rect(bx + 12, y - 4, bw - 24, hud.lineHeight + 8, 0.22f, 0.36f, 1f, 0.9f);
                }
                hud.draw(bx + 24, y, label, 1f, 1f, 1f, 1f);
                y += hud.lineHeight + 14;
             }
          } else {
             List<String> names = roomNames();
             int visibleRows = Math.max(5, (int) ((h - 160) / (hud.lineHeight + 6)));
             int first = Math.max(0, Math.min(roomSel - visibleRows / 2, names.size() - visibleRows));
             int last = Math.min(names.size(), first + visibleRows);
             float bw = 420, bh = 70 + (last - first) * (hud.lineHeight + 6);
             float bx = (w - bw) / 2f, by = (h - bh) / 2f;
             HudText.rect(bx, by, bw, bh, 0.08f, 0.10f, 0.20f, 0.92f);
             hudBig.drawShadowed(bx + 20, by + 12, "Ir a otra sala", 1f, 1f, 1f);
             float y = by + 52;
             for (int i = first; i < last; i++) {
                if (i == roomSel) {
                   HudText.rect(bx + 12, y - 3, bw - 24, hud.lineHeight + 6, 0.22f, 0.36f, 1f, 0.9f);
                }
                boolean here = names.get(i).equals(roomName);
                hud.draw(bx + 24, y, names.get(i) + (here ? "   (aqui)" : ""), 1f, 1f, here ? 0.6f : 1f, 1f);
                y += hud.lineHeight + 6;
             }
             hud.drawShadowed(bx + 20, by + bh - 22, "Intro: ir   ESC: volver", 0.7f, 0.75f, 0.9f);
          }
       }
       HudText.end();
    }

    // --- Portales vistos a traves (Portal.prerender del original) ---
    /** -Dfreeworlds.portals=false los apaga (huecos del color de fondo, como antes). */
    private static final boolean PORTALS = !"false".equals(System.getProperty("freeworlds.portals"));
    /** Niveles de portal como el original: Portal.rwPrerender (gamma.dll
     * 0x0041ba30) sigue mientras DAT_00489624 (rwDepth) <= 10, o sea 11
     * niveles. Con 3 no se veia Reception al fondo de AvatarEnter (esta 4
     * portales mas alla: IconViewRoom1d, IconViewRoom1, IconViewRoom1Enter).
     * -Dfreeworlds.portalDepth=N para medir. */
    private static final int PORTAL_MAX_DEPTH = Integer.getInteger("freeworlds.portalDepth", 11);
    private static final Map<WNode, List<Object[]>> roomPortals = new IdentityHashMap<>();
    /** -Dfreeworlds.portalTrace=true: una linea por portal dibujado (camara transformada, rectangulo). */
    private static final boolean PORTAL_TRACE = Boolean.getBoolean("freeworlds.portalTrace");
    private static final Set<WNode> tracedPortals = java.util.Collections.newSetFromMap(new IdentityHashMap<>());

    /** Portales de una sala (y su entorno) con sus 4 esquinas en coordenadas de sala. */
    private static List<Object[]> portalsOf(WNode room) {
       List<Object[]> out = roomPortals.get(room);
       if (out == null) {
          out = new ArrayList<>();
          collectPortals(room, identity(), out);
          if (room.environment != null) {
             collectPortals(room.environment, identity(), out);
          }
          roomPortals.put(room, out);
       }
       return out;
    }

    private static void collectPortals(WNode n, float[] parentToWorld, List<Object[]> out) {
       float[] here = n.matrix != null ? multiply(parentToWorld, n.matrix) : parentToWorld;
       if (n.className.endsWith("Portal")) {
          float[][] q = new float[4][];
          for (int i = 0; i < 4; i++) {
             q[i] = transformPoint(here, RECT_CORNERS[i][0], RECT_CORNERS[i][1], RECT_CORNERS[i][2]);
          }
          out.add(new Object[]{n, q});
       }
       for (WNode c : n.children) {
          collectPortals(c, here, out);
       }
    }

    /**
     * gamma.dll 0x0041b3b0 (NativeCamera.portalFacesCamera en el puente): el
     * portal se ve cuando ((cam - v1) x e1) . e2 &gt; 0, con e1 = v2 - v1 y
     * e2 = v4 - v1 normalizados (los vertices del Rect son las esquinas
     * (0,0,0), (1,0,0), (1,0,1), (0,0,1), como RECT_CORNERS); degenerado =
     * no se ve.
     */
    private static boolean portalFacesCamera(float[][] q, float[] cam) {
       float[] v1 = q[0], v2 = q[1], v4 = q[3];
       float e1x = v2[0] - v1[0], e1y = v2[1] - v1[1], e1z = v2[2] - v1[2];
       float e2x = v4[0] - v1[0], e2y = v4[1] - v1[1], e2z = v4[2] - v1[2];
       float l1 = (float) Math.sqrt(e1x * e1x + e1y * e1y + e1z * e1z);
       float l2 = (float) Math.sqrt(e2x * e2x + e2y * e2y + e2z * e2z);
       if (!(l1 > 0.0078125F) || !(l2 > 0.0078125F)) {
          return false;
       }
       float s1 = 1.0F / l1, s2 = 1.0F / l2;
       float dx = cam[0] - v1[0], dy = cam[1] - v1[1], dz = cam[2] - v1[2];
       float v = (dx * e1y * s1 - dy * e1x * s1) * e2z * s2
          + (dy * e1z * s1 - dz * e1y * s1) * e2x * s2
          + (dz * e1x * s1 - dx * e1z * s1) * e2y * s2;
       return v > 0.0F;
    }

    /**
     * Rectangulo de ventana (x, y, ancho, alto; origen abajo a la izquierda,
     * como glScissor) que cubre el portal visto con esta camara, recortado
     * por el plano cercano; null si no se ve. Mismas matrices que
     * GlUtil.lookAt / GlUtil.perspective(60, aspect, near, far).
     */
    private static int[] portalScreenRect(float[][] q, float[] eye, float[] center, float[] up, float aspect,
          float near, int w, int h) {
       float[] f = GlUtil.normalize(center[0] - eye[0], center[1] - eye[1], center[2] - eye[2]);
       float[] u = GlUtil.normalize(up[0], up[1], up[2]);
       float[] sv = GlUtil.normalize(f[1] * u[2] - f[2] * u[1], f[2] * u[0] - f[0] * u[2], f[0] * u[1] - f[1] * u[0]);
       float[] u2 = {sv[1] * f[2] - sv[2] * f[1], sv[2] * f[0] - sv[0] * f[2], sv[0] * f[1] - sv[1] * f[0]};
       float[][] ec = new float[4][];
       for (int i = 0; i < 4; i++) {
          float dx = q[i][0] - eye[0], dy = q[i][1] - eye[1], dz = q[i][2] - eye[2];
          ec[i] = new float[]{sv[0] * dx + sv[1] * dy + sv[2] * dz, u2[0] * dx + u2[1] * dy + u2[2] * dz,
             -(f[0] * dx + f[1] * dy + f[2] * dz)};
       }
       List<float[]> poly = new ArrayList<>();
       float zc = -near;
       for (int i = 0; i < 4; i++) {
          float[] a = ec[i], b = ec[(i + 1) % 4];
          boolean ina = a[2] <= zc, inb = b[2] <= zc;
          if (ina) {
             poly.add(a);
          }
          if (ina != inb) {
             float t = (zc - a[2]) / (b[2] - a[2]);
             poly.add(new float[]{a[0] + (b[0] - a[0]) * t, a[1] + (b[1] - a[1]) * t, zc});
          }
       }
       if (poly.isEmpty()) {
          return null;
       }
       float tanH = (float) Math.tan(Math.toRadians(30.0));
       float minX = Float.MAX_VALUE, minY = Float.MAX_VALUE, maxX = -Float.MAX_VALUE, maxY = -Float.MAX_VALUE;
       for (float[] v : poly) {
          float nx = v[0] / -v[2] / (tanH * aspect);
          float ny = v[1] / -v[2] / tanH;
          minX = Math.min(minX, nx);
          maxX = Math.max(maxX, nx);
          minY = Math.min(minY, ny);
          maxY = Math.max(maxY, ny);
       }
       minX = Math.max(-1f, minX);
       minY = Math.max(-1f, minY);
       maxX = Math.min(1f, maxX);
       maxY = Math.min(1f, maxY);
       if (minX >= maxX || minY >= maxY) {
          return null;
       }
       int x0 = (int) Math.floor((minX + 1f) * 0.5f * w), x1 = (int) Math.ceil((maxX + 1f) * 0.5f * w);
       int y0 = (int) Math.floor((minY + 1f) * 0.5f * h), y1 = (int) Math.ceil((maxY + 1f) * 0.5f * h);
       return new int[]{x0, y0, x1 - x0, y1 - y0};
    }

    private static int[] intersectRect(int[] a, int[] b) {
       int x0 = Math.max(a[0], b[0]), y0 = Math.max(a[1], b[1]);
       int x1 = Math.min(a[0] + a[2], b[0] + b[2]), y1 = Math.min(a[1] + a[3], b[1] + b[3]);
       return x1 > x0 && y1 > y0 ? new int[]{x0, y0, x1 - x0, y1 - y0} : null;
    }

    /**
     * Las salas vistas a traves de los portales de una sala, como el
     * original (Portal.prerender -&gt; el pase de portal de gamma.dll,
     * traducido en el puente como Portal.rwPrerender): cada portal en
     * estado 2, visible (flags bit 0) y de cara a la camara dibuja su sala
     * lejana con la camara movida por _p2pxform, recortada al rectangulo del
     * portal en pantalla (el original cambia el viewport; aqui glScissor
     * con la misma proyeccion), antes que la sala propia, que luego se
     * dibuja encima con el z-buffer limpio. Primero van los portales de la
     * sala lejana (recursion).
     *
     * Espejos (flags bit 2; en GroundZero los dos del fondo de
     * AuditoriumHall y EastPortalReflection de ReceptionView1, enlazados
     * consigo mismos): _p2pxform con la columna x negada (PortalLink), y el
     * original niega el view offset y luego da la vuelta a los pixeles del
     * rectangulo (Portal.rwPrerender + mirrorViewport), que es lo mismo que
     * dibujar con la x de la proyeccion negada: glScalef(-1, 1, 1) en la
     * proyeccion y glFrontFace(GL_CW), y los rectangulos de los portales de
     * dentro reflejados. "mirrored" es el estado del pase en curso.
     */
    private static void drawPortals(WNode room, float[] eye, float[] center, float[] up, float aspect,
          float near, float far, int w, int h, int[] clip, int depth, boolean mirrored) {
       for (Object[] pq : portalsOf(room)) {
          WNode p = (WNode) pq[0];
          float[][] q = (float[][]) pq[1];
          if ((p.flags & 1) == 0) {
             continue;
          }
          PortalState st = link(p);
          if (st.state != 2 || !portalFacesCamera(q, eye)) {
             continue;
          }
          boolean mirror = (p.flags & 4) != 0;
          boolean inner = mirrored ^ mirror;
          int[] r = portalScreenRect(q, eye, center, up, aspect, near, w, h);
          if (r != null && mirrored) {
             r = new int[]{w - r[0] - r[2], r[1], r[2], r[3]};
          }
          r = r == null ? null : intersectRect(r, clip);
          WNode farRoom = r == null ? null : worldRoot.roomsByName.get(st.farRoom);
          float[] m = portalRoomMatrix.get(p);
          if (farRoom == null || m == null) {
             continue;
          }
          float[] p2p = PortalLink.p2pTransform(m, p.xScale, p.yScale, p.zScale, mirror,
             st.far[0], st.far[1], st.far[2], st.far[3]);
          float[] e2 = PortalLink.transformPoint(p2p, eye[0], eye[1], eye[2]);
          float[] c2 = PortalLink.transformPoint(p2p, center[0], center[1], center[2]);
          float[] u2 = PortalLink.transformVector(p2p, up[0], up[1], up[2]);
          if (PORTAL_TRACE && tracedPortals.add(p)) {
             System.out.println("[portal] " + p.name + " (prof. " + depth + ") -> sala " + st.farRoom + " rect="
                + java.util.Arrays.toString(r) + " ojo " + java.util.Arrays.toString(eye) + " -> "
                + java.util.Arrays.toString(e2) + " mira " + java.util.Arrays.toString(GlUtil.normalize(
                   c2[0] - e2[0], c2[1] - e2[1], c2[2] - e2[2])));
          }
          glEnable(GL_SCISSOR_TEST);
          glScissor(r[0], r[1], r[2], r[3]);
          // Solo el z: Camera.rwRenderRoom no borra el color de una sala
          // vista por un portal (sin piloto) salvo que tenga colores de
          // cielo/suelo, y ninguna sala de GroundZero los tiene; asi el
          // portal anidado ReceptionView1 -> ReceptionView2 deja ver el
          // panorama que ya dibujo la primera.
          glClear(GL_DEPTH_BUFFER_BIT);
          float farPlane = Math.max(far * 3f, 20000f);
          if (farRoom.infiniteBackground != null && !farRoom.infiniteBackground.children.isEmpty()) {
             // su fondo infinito, desde el origen con la orientacion de la camara (pasada 1)
             glMatrixMode(GL_PROJECTION);
             glLoadIdentity();
             if (inner) {
                glScalef(-1f, 1f, 1f);
             }
             GlUtil.perspective(60f, aspect, 1f, 200000f);
             glMatrixMode(GL_MODELVIEW);
             glLoadIdentity();
             GlUtil.lookAt(0, 0, 0, c2[0] - e2[0], c2[1] - e2[1], c2[2] - e2[2], u2[0], u2[1], u2[2]);
             glFrontFace(inner ? GL_CW : GL_CCW);
             roomLights(farRoom);
             drawInfiniteBackground(farRoom);
             glClear(GL_DEPTH_BUFFER_BIT);
          }
          if (depth + 1 < PORTAL_MAX_DEPTH) {
             drawPortals(farRoom, e2, c2, u2, aspect, near, farPlane, w, h, r, depth + 1, inner);
             glScissor(r[0], r[1], r[2], r[3]);
             glClear(GL_DEPTH_BUFFER_BIT);
          }
          glMatrixMode(GL_PROJECTION);
          glLoadIdentity();
          if (inner) {
             glScalef(-1f, 1f, 1f);
          }
          GlUtil.perspective(60f, aspect, near, farPlane);
          glMatrixMode(GL_MODELVIEW);
          glLoadIdentity();
          GlUtil.lookAt(e2[0], e2[1], e2[2], c2[0], c2[1], c2[2], u2[0], u2[1], u2[2]);
          glFrontFace(inner ? GL_CW : GL_CCW);
          roomLights(farRoom);
          drawNode(farRoom);
          if (farRoom.environment != null) {
             drawNode(farRoom.environment);
          }
       }
       glFrontFace(mirrored ? GL_CW : GL_CCW);
       if (depth == 0) {
          glDisable(GL_SCISSOR_TEST);
       } else {
          glScissor(clip[0], clip[1], clip[2], clip[3]);
       }
    }

    private static final float PLAY_EYE_HEIGHT = 150f;
    private static final float PLAY_CAM_DIST = 140f;
    private static final float PLAY_CAM_PITCH = (float) Math.toRadians(-10.0);

    /**
     * How far behind the eye point the camera can be: PLAY_CAM_DIST unless a
     * wall or bumper (the boxes the pilot collides with) is closer along the
     * way back; then just in front of it. The original camera is bumpable
     * (HoloPilot.setOutsideCameraMode: cam.setBumpable(true)), which is why
     * the bridge shows it at 116 instead of 138 in the small AvatarEnter.
     */
    private static float cameraDistance(List<float[]> blockers, float hx, float hy, float hz, float[] view) {
       final float margin = 8f;
       for (float d = 4f; d <= PLAY_CAM_DIST; d += 4f) {
          float x = hx - view[0] * d, y = hy - view[1] * d, z = hz - view[2] * d;
          for (float[] b : blockers) {
             if (x > b[0] - margin && x < b[3] + margin && y > b[1] - margin && y < b[4] + margin
                   && z > b[2] - margin && z < b[5] + margin) {
                return Math.max(20f, d - 4f);
             }
          }
       }
       return PLAY_CAM_DIST;
    }
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
       return !menuOpen && glfwGetKey(window, key) == GLFW_PRESS;
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
