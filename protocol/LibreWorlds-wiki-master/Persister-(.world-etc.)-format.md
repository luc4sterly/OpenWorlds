Data in Persister format does not mark itself to indicate their types, the types are assumed by the deserialization code. That is, a Portal being read in knows when to expect a boolean, a string, and an integer, for example. Without knowing what a Portal wants to read, it is not possible to determine where the next item begins.

During reading or writing, WorldsPlayer maintains 3 tables: Object table, Class table, Cookie table (for versions). These serve as a caching mechanism, so that objects can be reused and class names do not need to be repeated.

# Primitive data types

Worlds generally uses the format described by [Java's DataInput](https://docs.oracle.com/javase/7/docs/api/java/io/DataInput.html).

* String: Starts with a byte, where 0x01 means the string is null (and the next byte is for the next item) and 0x00 means non-null. If non-null, next 2 bytes are the length in number of bytes (big-endian). Following is the actual string data, in modified UTF-8. (The bytes after the non-null indicator are merely read by DataInput).
* Boolean: 1 byte, 0x00 for false 0x01 for true.
* Byte, Double, Long, Int, Float, Short: Self-explanatory
* MaybeNull: 1 byte as a null indicator (0x01 for null, 0x00 for non-null), followed by an object (as described below) for non-null
* Class: A Class ID, then if the Class ID has not been encountered before in this file, a String for the class name. If the Class ID has been encountered before, the class name is omitted and the prior name assumed.
* Vector: Integer representing number of objects, followed by that number of objects.
* MaybeNullVector: 1 byte as a null indicator (0x00 for null, 0x01 for non-null, opposite of MaybeNull), followed by a Vector for not-null
* Array: If Persister version >= 5, starts with a class (as described above) with a name beginning with "[L" and ending with ";". Between these are the name of another class. Following that, in all Persister versions, is an integer for number of items, followed by that many MaybeNulls.
* "Version for X" (not applicable to Persister version): For the first instance for a given X within this file, this is an integer. Otherwise it is omitted and the prior value assumed. Note that X is usually, but not always, a class. Note that for Persister version 1, "versions" are always 0 and never read from the file.

# Header and footer

* Persister files begin with the String "PERSISTER Worlds, Inc." (remember the 3 bytes at beginning), followed by an integer representing persister format version (7 seems to be latest), followed by an object.

* Persister files end with the String "END PERSISTER"

# Objects

Assuming empty class and object table, an object consists of an object ID (integer), a class (a class ID (integer) then class name (String)), and then data as determined by the specific class.

If the Object ID has been seen before within this file, reuse the associated object, instead of proceeding to read class and data. In this way, the same object can be contained by multiple other objects, and the Persister format does NOT form a tree.

## Explicit vs Implicit

Objects often contain other objects. Even if object A (e.g. World) is expected to only contain B (e.g. a Hashtable), B will still have the class ID and potentially class name. This will be noted in these docs as "Explicit" as a reminder. There are exceptions where there is no object ID and class id/name (usually because of an is-a relationship). These will be noted as "Implicit".

## Subtyping

Some classes are subtypes of others. For example, [[WrStaircase|NET.worlds.scape.WrStaircase]] is a subtype of [[Room|NET.worlds.scape.Room]]. This means that WrStaircase can be used when an Explicit (not Implicit) Room is expected.

## Example from GroundZero

| "PERSISTER Worlds, Inc." | Persister version | Object ID | Class ID | Class name |
| ------------------------ | ----------------- | --------- | -------- | ---------- |
| 0x00 0x00 0x16 "PERSISTER Worlds, Inc." | 0x00 0x00 0x00 0x07 | 0x00 0x00 0x03 0x67 | 0x00 0x00 0x02 0xE6 | 0x00 0x00 0x16 "NET.worlds.scape.World" |