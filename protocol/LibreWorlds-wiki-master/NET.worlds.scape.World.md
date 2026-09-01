A World. Main object in .world files. Synonyms: "NET.worlds.network.World", "World"

`NET.worlds.scape.World` is a subtype of `NET.worlds.scape.SuperRoot`.

Note that as with all objects, there will first be an object ID, then a class ID, then if the class ID hasn't been seen before (usually the case with Worlds) the class name "NET.worlds.scape.World" (or a synonym).

| Version | Type | Name/Description |
| ---     | ---  | --- |
| All | Version for World | Version for World, 0-13 |
| 0 | String | World name |
| >= 1 | Implicit [[SuperRoot\|NET.worlds.scape.SuperRoot]] | World name |
| All | String | Default room name |
| <= 6 | String | Server URL, read in an "old" way, might need further description. "UNSHARED" equivalent to null |
| == 7 | String | Server URL. If null, assumed to a default value, otherwise, World considered to be multiuser |
| >= 8 | String | Server URL. |
| == 2 | String | Unknown, discarded |
| >= 5 | Int | Timeout Age. Note that in versions 8 and below, a Timeout Age of 60000 is converted to 15000 |
| 6 or 7 | Boolean | Unknown, discarded |
| >= 8 | Boolean | Multiuser |
| >= 10 | Boolean | Courtesy VIP |
| >= 11 | Boolean | Force Human |
| >= 12 | Boolean | Has Ad Banner |
| >= 12 | Integer | Banner Width |
| >= 12 | Integer | Banner Height |
| >= 12 | String | Banner URL |
| == 13 | Boolean | Has Clickable Ad Cube |
| == 13 | Boolean | Ad Cube Format Is Gif |
| == 13 | String | Ad Cube Base URL |
| == 13 | String | Default Ad Cube URL |
| All | Explicit [[Hashtable\|NET.worlds.core.Hashtable]] | Hashtable with room name as keys and [[Room\|NET.worlds.scape.Room]]s as values |
| == 4 | Integer | Timeout Age. 60000 and 900000 get read as 15000 |
