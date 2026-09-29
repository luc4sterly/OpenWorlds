package net.openworlds.solar;

import java.io.IOException;
import java.io.UTFDataFormatException;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

/**
 * The two property-list encodings of the protocol (netConst, OldPropertyList,
 * PropertyList, net2Property): the old one, {@code [id][string]} repeated,
 * used by SESSINIT and SESSEXIT; and the new one, {@code [id][flags][access]}
 * then a string or (with the binary flag) {@code [length][bytes]}, used by
 * PROPSET and PROPUPD.
 */
final class Props {
   private Props() {
   }

   static final int APPNAME = 1;
   static final int USERNAME = 2;
   static final int PROTOCOL = 3;
   static final int ERROR = 4;
   /** VAR_CHANNEL in SESSINIT, VAR_BITMAP (the avatar URL) on a user. */
   static final int CHANNEL = 5;
   static final int BITMAP = 5;
   static final int PASSWORD = 6;
   static final int AVATARS = 7;
   static final int UPDATETIME = 8;
   static final int CLIENT = 9;
   static final int SERIAL = 10;
   static final int LOGONOFF = 12;
   static final int GUEST = 14;
   static final int SERVERTYPE = 15;
   static final int NEW_PASSWD = 20;
   static final int PRIV = 22;
   static final int ASLEEP = 23;
   static final int SCRIPT_SERVER = 25;
   static final int SMTP_SERVER = 26;
   static final int MAIL_DOMAIN = 27;
   static final int NEW_USERNAME = 28;

   static final int FLAG_BINARY = 16;
   static final int FLAG_AUTOUPDATE = 64;
   static final int ACCESS_POSSESS = 1;

   // VAR_PRIV bits (netConst PRIV_*), as sessionInitCmd reads them
   static final int PRIV_BROADCAST = 2;
   static final int PRIV_VIP = 8;
   static final int PRIV_VIP2 = 16;

   // VAR_ERROR values (netConst NAK_*); the client shows its own text for each
   static final int ACK = 0;
   static final int NAK_BAD_USER = 1;
   static final int NAK_MAX_ORDINARY = 2;
   static final int NAK_FATAL = 5;
   static final int NAK_BAD_PROTOCOL = 6;
   static final int NAK_TAKEN_USER = 11;
   static final int NAK_NO_SUCH_USER = 12;
   static final int NAK_BAD_PASSWORD = 13;
   static final int NAK_BAD_ACCOUNT = 14;
   static final int NAK_SHUTDOWN = 100;

   /** Old-style list as id -> value (a repeated id keeps the last value). */
   static Map<Integer, String> readOld(Packet p) throws IOException {
      Map<Integer, String> m = new LinkedHashMap<>();
      while (p.more()) {
         int id = p.u8();
         m.put(id, p.utf());
      }
      return m;
   }

   static Packet.Out old(Packet.Out o, int id, String value) {
      return o.u8(id).utf(value);
   }

   /** One new-style property, kept as it travels so relaying it changes nothing. */
   static final class Prop {
      final int id;
      final int flags;
      final int access;
      /** The value's wire form: a length byte and the modified UTF-8 or binary bytes. */
      final byte[] wire;

      Prop(int id, int flags, int access, byte[] wire) {
         this.id = id;
         this.flags = flags;
         this.access = access;
         this.wire = wire;
      }

      static Prop text(int id, int flags, int access, String value) {
         return new Prop(id, flags, access, new Packet.Out().utf(value).raw());
      }

      /** The value as text (binary values as ISO-8859-1, like net2Property.value()). */
      String text() {
         int len = wire[0] & 0xff;
         if ((flags & FLAG_BINARY) != 0) {
            return new String(wire, 1, len, java.nio.charset.StandardCharsets.ISO_8859_1);
         }
         try {
            return Packet.decodeUtf(wire, 1, len);
         } catch (UTFDataFormatException e) {
            return "";
         }
      }

      int size() {
         return 3 + wire.length;
      }
   }

   static List<Prop> readNew(Packet p) throws IOException {
      List<Prop> list = new ArrayList<>();
      while (p.more()) {
         int id = p.u8();
         int flags = p.u8();
         int access = p.u8();
         int len = p.u8();
         byte[] value = p.bytes(len);
         byte[] wire = new byte[len + 1];
         wire[0] = (byte) len;
         System.arraycopy(value, 0, wire, 1, len);
         list.add(new Prop(id, flags, access, wire));
      }
      return list;
   }

   static Packet.Out write(Packet.Out o, Prop p) {
      return o.u8(p.id).u8(p.flags).u8(p.access).bytes(p.wire);
   }
}
