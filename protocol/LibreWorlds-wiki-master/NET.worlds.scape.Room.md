`NET.worlds.scape.Room` is a subtype of [[NET.worlds.scape.WObject]] which is a subtype of [[NET.worlds.scape.Transform]] which is a subtype of [[NET.worlds.scape.SuperRoot]].

| Version | Type | Name/Description |
| --- | --- | --- |
| All | Version for Room | 0-7 |
| All | Implicit [[WObject\|NET.worlds.scape.WObject]] | Includes room contents, actions, event handlers, and room name for non-0 version |
| 0 | String | Room name |
| 0-1 | Explicit Object | Unknown, discarded |
| All | Boolean | Null indicator: False = Skip next entry |
| All | Integer | Sky Color |
| All | Boolean | Null indicator: False = Skip next entry |
| All | Integer | Ground Color |
| 0-3 | MaybeNull | Unknown, discarded |
| All | Explicit [[Point3\|NET.worlds.scape.Point3]] | Default Position |
| All | Explicit [[Point3\|NET.worlds.scape.Point3]] | Default Orientation Axis |
| All | Float | Default Orientation |
| 0 | Vector | Unknown, discarded |
| 5-7 | Explicit [[Point3\|NET.worlds.scape.Point3]] | Light Position |
| 5-7 | Float | Light Color |
| All | Explicit [[RoomEnvironment\|NET.worlds.scape.RoomEnvironment]] | Environment |
| 3-7 | Explicit [[RoomEnvironment\|NET.worlds.scape.RoomEnvironment]] | Infinite Background |
| 6-7 | String | Teleport Chain |
| 6-7 | Integer | Teleport Interval |
| 7 | Boolean | Allow Teleport |