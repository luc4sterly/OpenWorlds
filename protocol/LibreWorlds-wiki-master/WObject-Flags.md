ubclasses of WObject may have their own flags not used elsewhere; Certain flags might always be set or unset on serialization or deserialization.

| Flag | Description |
| --- | --- |
| `1<<0` | Visible |
| `1<<1` | Bumpable |
| `1<<2` | (Holograms only) Rough Cut |
| `1<<2` | (Portals only) Mirrored |
| `1<<7` | Hilight. Always saved as 0, but NOT ignored on deserialization if WObject version >= 8 |
| `1<<14` | Ignored; internal use |
| `1<<18` | (Rooms only) Is VIP Only |
| `1<<19` | (Rooms only) Is VIP View Only |
| `1<<19` | (Surface only) U Flipped |
| `1<<20` | (Surface only) V Flipped |