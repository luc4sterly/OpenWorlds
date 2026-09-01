An object used in a lot of places to store key-value associates.

| Type | Name/Description |
| --- | --- |
| Version for Hashtable | Always 0 as of WorldsPlayer 1920 |
| Integer | Number of entries |

Followed by the below for each entry:

| Type | Name/Description |
| --- | --- |
| Boolean | Indicator: True = Key is a String, False = Key is an Object |
| String or Object | Key |
| Object | Value |