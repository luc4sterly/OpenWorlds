* Packet size: 1-2 bytes. 2 byte mode looks defective on Worlds 1920, and non-existent on 1904 and below.
* ObjID: Either 1 byte, or if byte is 0, then after that a thing I will call a WorldsString. 254 is a special destination called "CO"
* Packet type: 1 byte
* Packet data

If the initial ObjID is "CO" (254), Packet data consists of ObjIDs followed by packet data for the packet type.

WorldsString: 1 byte for remaining length in bytes, then the string in [Modified UTF-8 encoding](https://docs.oracle.com/javase/6/docs/api/java/io/DataInput.html#modified-utf-8)