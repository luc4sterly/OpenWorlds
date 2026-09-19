// 10041700 FUN_10041700 [Global]
// programa: RWL21.DLL

undefined4 FUN_10041700(void)

{
  DAT_1005b794 = FUN_100371c0(s_binaryobjectslist_1005b7ac,0x18);
  if (DAT_1005b794 != (undefined4 *)0x0) {
    DAT_1005b790 = FUN_100371c0(s_objectlistlist_1005b79c,0xc);
  }
  if ((DAT_1005b794 != (undefined4 *)0x0) && (DAT_1005b790 != (undefined4 *)0x0)) {
    return 1;
  }
  return 0;
}


