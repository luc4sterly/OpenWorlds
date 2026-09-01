| ID | Source | Short Name | Description |
| --- | --- | --- | --- |
| 0x01 (1) | Server?/Client |  LONGLOC  |  Used for long movement and z-coordinate movement. |
| 0x02 (2) | Server?/Client? |  STATE | *Unknown* |
| 0x03 (3) | Server/Client |  PROP  |  Old-style property list. |
| 0x04 (4) | Server  |  SHORTLOC  |  Movement deltas, not along z-axis. |
| 0x05 (5) | Server?/Client? |  ROOMCHNG  |  Indication of user changing rooms, includes new location within room |
| 0x06 (6) | Server/Client |  SESSINIT  |  Used by client to log in to a server, and server to acknowledge and provider more information. Uses old-style property list |
| 0x07 (7) | Server/Client |  SESSEXIT  |  Used by client to log off of a server, and server to acknowledge. Uses old-style property list. |
| 0x08 (8) | Server  |  APPINIT  |  Usage unknown, does not seem to be sent by client. Modifies a state machine upon being received by client. Uses new-style property list. |
| [[0x0A (10)\|PROPREQ]]  | Client |  [[PROPREQ]]  |  Sent on connection to request properties (e.g. server type and protocol). May include a list of properties to request, but that functionality seems to be unused. |
| 0x0B (11) | Server  |  DISAPPR  |  Indicate a Drone should disappear. |
| 0x0C (12) | Server  |  APPRACTR  |  Indicate a Drone should appear at a room (indicated with a u16), at x, y, z, dir. |
| 0x0D (13) | Server  |  REGOBJID  |  Associate a long Object ID with a short Object ID, to save bandwidth. These associations seem to be per connection. The object ID in the packet frame is not used for this, and is 0xFF (target connection). |
| 0x0E (14) | Server/Client |  TEXT  |  Used for chat. Includes an ObjID in the data itself, the ObjID in the packet frame is ignored. |
| 0x0F (15) | Server/Client |  PROPSET  |  Usually sent from client to server, although there is support for it to be sent server to client as a NOOP. This packet indicates a property change (e.g. avatar or sleep). It also can be sent for shared state, which can affect the objid it gets sent with. The packet format includes a string marked as "fromUser" but usually empty. |
| 0x10 (16) | Server  |  PROPUPD  |  Update properties on the given ObjID (with a new-style property list). |
| 0x11 (17) | Server/Client |  WHISPER  |  Whispering. Includes a sender ID, and uses frame's ObjID for destination. |
| 0x12 (18) | Server/Client |  TELEPORT  |  Sent to server for teleporting, sent from server for drones teleporting (includes entering and leaving). |
| 0x14 (20) | Client |  ROOMIDRQ  |  Request numeric room ID for room name (e.g. "GroundZero#ChatElevator\<dimension-1\>"). |
| 0x15 (21) | Server  |  ROOMID  |  Associate room name with numeric room ID. |
| 0x16 (22) | Client |  SUBSCRIB |  Subscribe to a room (with numeric room ID) at a location and a distance. |
| 0x17 (23) | Client |  UNSUBSCR  |  Unsubscribe from a room. |
| 0x18 (24) | Client |  SUB-DIST  |  Subscribe to a room at a distance? Mostly after having moved, but I'm unclear on this. It is in use, as is SUBSCRIB. |
| 0x19 (25) | Server?/Client? |  REDIRECT  |  No-op. |
| 0x1A (26) | Server |  REDIRID  |  Reassign room ID<->room name mapping and point to a different RoomServer? |
| 0x1B (27) | Server?/Client? |  FINGREQ  |  Unused. |
| 0x1C (28) | Server?/Client? |  FINGREP  |  Unused. |
| 0x1D (29) | Client |  BUDDYLISTUPDATE  | Add or remove a buddy from buddy list. |
| 0x1E (30) | Server?/Client? |  BUDDYLISTNOTIFY  |  Buddy came online or offline. |
| 0x1F (31) | Client |  CHANNEL  |  Change channels (dimensions?). |