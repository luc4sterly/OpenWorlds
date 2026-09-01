Portal is a subtype of [[Rect|NET.worlds.scape.Rect]].

| Version | Type | Name/Description |
| --- | --- | --- |
| All | Version for Portal | 0-9 |
| 0-7 | Implicit [[WObject\|NET.worlds.scape.WObject]] | WObject |
| 8-9 | Implicit [[Rect\|NET.worlds.scape.Rect]] | Rect |
| 8-9 | Boolean | Far Side Is Portal |
| 9 | Boolean | Allow Download |
| 0 | Integer | Unknown; discarded |
| 0-5 | Float | X scale |
| 0-5 | Float | "Y" scale (but actually discarded) |
| 0-5 | Float | Z scale |
| 0-7 | Boolean | If true, [[WObject flag\|WObject Flags]] `1<<2` (mirrored) loaded as 1 |
| 4-9 | String | Far side portal name |
| 0-9 | MaybeNull Explicit Portal | Far side Portal |
| 1 | String | Name (if not empty string) |
| 3-9 | String | URL for far side World. If version 3-6, may potentially assume ".world" at end if needed (no "." after "/") |
| 3-9 | String | Far side room name |
| 3-9 | Float | Far X |
| 3-9 | Float | Far Y |
| 3-9 | Float | Far Z |
| 3-9 | Float | Far Theta |
| 3-7 | MaybeNull Explicit [[Material\|NET.worlds.scape.Material]] | Initial Cover |
| 3-7 | MaybeNull Explicit [[Material\|NET.worlds.scape.Material]] | Download Cover |
| 5-7 | Boolean | Far Side Is Portal |
 
