Most things are subclasses of WObject. WObject is a subclass of [[NET.worlds.scape.Transform]] which is a subclass of [[NET.worlds.scape.SuperRoot]].

| Version | Type | Name/Description |
| --- | --- | --- |
| All | Version for WObject | 0-10 |
| All | Implicit [[Transform\|NET.worlds.scape.Transform]] | Transform (includes name) |
| All | Integer | [[WObject Flags]] |
| 0-1 | MaybeNull | Unknown, discarded |
| All | MaybeNullVector of Explicit WObjects | Contents (unshared only) |
| All | MaybeNullVector of Explicit [[SuperRoots\|NET.worlds.scape.SuperRoot]] | Handlers |
| 1-10 | MaybeNullVector of Explicit [[Actions\|NET.worlds.scape.Action]] | Actions |
| 3-4 | Explicit Object | Unknown, discarded |
| 5-10 | MaybeNull Explicit [[BumpCalc\|NET.worlds.scape.BumpCalc]] | BumpCalc. Seemingly usually null, with BumpCalc determined by the class of this WObject |
| 4-10 | MaybeNull Explicit [[Sharer\|NET.worlds.scape.Sharer]] | Sharer for shared things. |
| 6 | String | Unknown, discarded |
| 9-10 | String | Tool Tip Text. WorldsPlayer 1920 discards this for reasons unknown. |
| 10 | Boolean | Mouse Over |

