// 10003e10 FUN_10003e10 [Global]
// programa: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10003e10(void)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  _DAT_1007f5a8 = DAT_10079214;
  _DAT_1007f59c = DAT_10079220;
  if (DAT_10079064 == 0x10) {
    DAT_1007bb24 = (**(code **)(DAT_1007bda8 + 0x34c))(0x2100);
    if (DAT_1007bb24 == 0) {
      return 0;
    }
    iVar5 = 0x20;
    iVar2 = (DAT_1007bb24 & 0xffffff00) + 0x100;
    iVar3 = DAT_10079220;
    DAT_1007f598 = iVar2;
    do {
      iVar4 = 0;
      do {
        pcVar1 = (char *)(iVar3 + iVar4);
        iVar4 = iVar4 + 1;
        *(char *)(iVar2 + -1 + iVar4) = *pcVar1 << 3;
        *(char *)(iVar2 + 0x1f + iVar4) = *(char *)(iVar3 + -1 + iVar4) << 3;
        *(char *)(iVar2 + 0x3f + iVar4) = *(char *)(iVar3 + -1 + iVar4) << 3;
        *(char *)(iVar2 + 0x5f + iVar4) = *(char *)(iVar3 + -1 + iVar4) << 3;
        *(char *)(iVar2 + 0x7f + iVar4) = *(char *)(iVar3 + -1 + iVar4) << 3;
        *(char *)(iVar2 + 0x9f + iVar4) = *(char *)(iVar3 + -1 + iVar4) << 3;
        *(char *)(iVar2 + 0xbf + iVar4) = *(char *)(iVar3 + -1 + iVar4) << 3;
        *(char *)(iVar2 + 0xdf + iVar4) = *(char *)(iVar3 + -1 + iVar4) << 3;
      } while (iVar4 < 0x20);
      iVar2 = iVar2 + 0x100;
      iVar3 = iVar3 + 0x20;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return 1;
}


