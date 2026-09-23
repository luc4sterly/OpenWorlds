package net.freeworlds.world;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

/**
 * Generic parsed node from a .world file's object graph (every Persister
 * instance becomes one of these - not just spatial WObjects). Deliberately
 * one flat class instead of a class hierarchy mirroring the real Java
 * client's ~30 classes: the goal of this session is position + geometry
 * reference extraction, not full interactivity (actions/sensors/portals
 * are parsed correctly to keep the byte stream in sync, but their fields
 * beyond that aren't specially modeled - see docs/world-format-reference.md).
 */
public final class WNode {
   public final String className;
   /** From SuperRoot.name - may be null. */
   public String name;
   /** WObject.flags as saved (bit 0 = visible, bit 1 = bumpable — verified
    * against the decompiled client: WObject.getVisible() = (flags & 1),
    * default flags = 3). Invisible nodes (collision bumpers like
    * Rect942CyanBump in LizCave) are parsed to keep the byte stream in
    * sync but never drawn. */
   public int flags = 3;
   /** WObject.getVisible() replica: bit 0. */
   public boolean isVisible() {
      return (flags & 1) != 0;
   }
   /** 16-float column-major transform matrix from Transform.getGuts()/setGuts() - null for non-Transform classes (Action, Sensor, Point3, Material...). */
   public float[] matrix;
   public float xScale = 1f, yScale = 1f, zScale = 1f;
   /** WObject.contents - child WObjects in the scene tree (Room -> RoomEnvironment/Shape/... ). */
   public final List<WNode> children = new ArrayList<>();
   /** Shape/PosableShape.url - the .rwx/.rwg this node should render, relative to the .world file's own URL. */
   public String geometryUrl;
   /** Point3's own x/y/z - only meaningful when className is "NET.worlds.scape.Point3". */
   public float x, y, z;
   /** Room-specific fields (only meaningful when className is "NET.worlds.scape.Room" or a subclass like WrStaircase). */
   public float[] lightPosition; // 3 floats, from Room.lightPosition (a Point3 sub-object)
   public Integer lightColorRGB;
   public Integer skyColorRGB;
   public Integer groundColorRGB;
    /** World-specific: room name -> Room node, from World.roomHash. */
    public final Map<String, WNode> roomsByName = new LinkedHashMap<>();
    public String defaultRoomName;
    /** Room.environment + Room.infiniteBackground subtrees (parsed but
     * historically discarded; the sky Rects live here). Null when the
     * stream had none. */
    public WNode environment;
    public WNode infiniteBackground;
    /** Surface.material — the node's own Material child (Surface/Rect/...),
     * null when the stream had none. Material nodes themselves carry the
     * fields below (see readMaterial). */
    public WNode material;
    /** Material fields (only meaningful on Material nodes): scalars as saved
     * (ambient/diffuse/specular/opacity), packed 0xRRGGBB color, and the raw
     * texture URL string when the stream carried one (Material v2+; v0/v1
     * reference a Texture object with no name in-stream, so stays null). */
    public float matAmbient, matDiffuse, matSpecular, matOpacity = 1f;
    public int matColorRGB = 0xFFFFFF;
    public int matVersion = -1;
    public String matTextureUrl;
    /** Rect UV extent/offset (u/v/uOff/vOff from Rect.restoreState; defaults
     * match the decompiled field initializers u=v=1). The live spin/scale is
     * already inside matrix — only UVs need storing. */
    public float rectU = 1f, rectV = 1f, rectUOff, rectVOff;
    /** RectPatch dims (xDim/yDim + 4 corner heights + tile UVs; defaults
     * match the decompiled initializers). v0 patches are explicitly
     * invisible in the client (setVisible(false)) and carry no material. */
    public int rpVersion = -1;
    public float rpXDim, rpYDim;
    public final float[] rpZ = new float[4];
    public float rpXTile = 1f, rpXTileOff, rpYTile = 1f, rpYTileOff;

    /** Portal.restoreState fields (v8/v9 - see NET/worlds/scape/Portal.java:670-696).
     * Only meaningful when className ends in ".Portal". farSidePortal is a
     * DIRECT object-graph reference (restoreMaybeNull resolves to the same
     * WNode instance the far room's own tree holds - no name lookup needed
     * when non-null): this is what Portal.connected()/farSide() actually
     * use at runtime (Portal.java:281-283, :265-267), not the persisted
     * name/position floats, which the real client only falls back to when
     * portalFarSideIsPortal is false (position/orientation mode,
     * Portal.java:107-118) or when the reference didn't resolve. */
    public boolean portalFarSideIsPortal = true;
    public String portalFarSidePortalName;
    public WNode portalFarSidePortal;
    public String portalFarSideWorld;
    public String portalFarSideRoomName;
    public float portalFarX, portalFarY, portalFarZ, portalFarTheta;

    /** WObject.eventHandlers (sensores, SwitchableBehavior...) y
     * WObject.actions tal como se guardan (WObject.restoreWObjectState:
     * contents, handlers, actions). En un Sensor, actions = Sensor.actions
     * (las acciones que dispara, Sensor.restoreStateVers). Null si el
     * stream no las traia. */
    public List<WNode> handlers;
    public List<WNode> actions;
    /** AnimateAction (AnimateAction.restoreState v0-v3): periodo del ciclo
     * en ms, numero de ciclos, bucle infinito y lista de materiales
     * (URLs separadas por espacios, AnimatingDoor.namesToMaterialArray). */
    public int animCycleTime = 1000;
    public int animCycles;
    public boolean animInfiniteLoop;
    public String animFrameList;
    /** SequenceAction.loopCount / loopInfinite (componentes en actions). */
    public int seqLoopCount = 1;
    public boolean seqLoopInfinite;
    /** WaitAction.duration en segundos. */
    public float waitDuration = 1f;

   public WNode(String className) {
      this.className = className;
   }

   @Override
   public String toString() {
      return className + (name != null ? "[" + name + "]" : "");
   }
}
