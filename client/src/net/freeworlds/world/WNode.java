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

   public WNode(String className) {
      this.className = className;
   }

   @Override
   public String toString() {
      return className + (name != null ? "[" + name + "]" : "");
   }
}
