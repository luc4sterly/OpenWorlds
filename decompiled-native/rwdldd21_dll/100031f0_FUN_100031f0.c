// 100031f0 FUN_100031f0 [Global]
// programa: RWDLDD21.DLL

undefined4 FUN_100031f0(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = DAT_10038aa4;
  if (0 < DAT_10038a9c) {
    do {
      *(undefined4 *)(iVar1 + 0xc) = 0;
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x18;
    } while (iVar2 < DAT_10038a9c);
  }
  iVar2 = 0;
  iVar1 = DAT_10038a2c;
  if (0 < DAT_10038a24) {
    do {
      *(undefined4 *)(iVar1 + 0xc) = 0;
      iVar1 = iVar1 + 0x18;
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_10038a24);
  }
  return 1;
}


