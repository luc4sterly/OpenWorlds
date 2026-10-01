// 1001e7e0 FUN_1001e7e0 [Global]
// program: RWL21.DLL

undefined4 FUN_1001e7e0(void)

{
  DAT_1005ac38 = FUN_100371c0(s_matrixlist_1005ac58,0x44);
  if (DAT_1005ac38 != (undefined4 *)0x0) {
    DAT_1005ac3c = FUN_100371c0(s_matrixstacklist_1005ac48,0xc);
    if (DAT_1005ac3c != (undefined4 *)0x0) {
      DAT_1005ac40 = FUN_1001d3a0(0x10);
      if (DAT_1005ac40 == (int *)0x0) {
        return 0;
      }
      DAT_1005ac44 = FUN_1001d3a0(0x10);
      if (DAT_1005ac44 == (int *)0x0) {
        return 0;
      }
    }
  }
  if ((DAT_1005ac38 != (undefined4 *)0x0) && (DAT_1005ac3c != (undefined4 *)0x0)) {
    return 1;
  }
  return 0;
}


