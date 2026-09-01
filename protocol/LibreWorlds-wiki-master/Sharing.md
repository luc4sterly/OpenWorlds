Sharing occurs with "Attributes" attached to a [[NET.worlds.scape.Sharer]] on an object. Such an attachment causes a ForwardAttribute to be attached to the Room (technically the nearest container with even Sharing Mode). Forwarder attrID
 on the Attribute corresponds to Attribute ID of the associated ForwardAttribute. The user of Attribute ID on the original Attribute is currently unknown.

Sharing works via [[PROPSET]]/[[PROPUPD]] directed (usually) to the room. ObjID #253 in the client's PROPSET corresponds to the current room. The property ID used is the one for the "Forwarder attrID"/ForwardAttribute's Attribute ID.

If the ForwardAttribute does not exist, a DynamicForwardAttribute is created. Its data should begin with 0x55E6, then 2 bytes for string length then a URL in modified UTF-8 encoding, representing a .wob. Unknown as of writing if the .wob URL must be local or can be remote. If this header isn't present, the DynamicForwardAttribute is removed.