// 10003da0 FUN_10003da0 [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10003da0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  _DAT_1007b5a8 = DAT_10075214;
  DAT_1007b59c = DAT_10075220;
  if (DAT_10075064 == 0x10) {
    DAT_10077b24 = (**(code **)(DAT_10077da8 + 0x34c))(0x2100);
    if (DAT_10077b24 == 0) {
      return 0;
    }
    iVar5 = 0x20;
    iVar1 = (DAT_10077b24 & 0xffffff00) + 0x100;
    iVar4 = DAT_10075220;
    _DAT_1007b598 = iVar1;
    do {
      iVar2 = 0;
      do {
        iVar3 = iVar2 + 1;
        *(char *)(iVar1 + -1 + iVar3) = *(char *)(iVar2 + iVar4) << 3;
        *(char *)(iVar1 + 0x1f + iVar3) = *(char *)(iVar2 + iVar4) << 3;
        *(char *)(iVar1 + 0x3f + iVar3) = *(char *)(iVar2 + iVar4) << 3;
        *(char *)(iVar1 + 0x5f + iVar3) = *(char *)(iVar2 + iVar4) << 3;
        *(char *)(iVar1 + 0x7f + iVar3) = *(char *)(iVar2 + iVar4) << 3;
        *(char *)(iVar1 + 0x9f + iVar3) = *(char *)(iVar2 + iVar4) << 3;
        *(char *)(iVar1 + 0xbf + iVar3) = *(char *)(iVar2 + iVar4) << 3;
        *(char *)(iVar1 + 0xdf + iVar3) = *(char *)(iVar2 + iVar4) << 3;
        iVar2 = iVar3;
      } while (iVar3 < 0x20);
      iVar1 = iVar1 + 0x100;
      iVar4 = iVar4 + 0x20;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return 1;
}


