// 10004420 FUN_10004420 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10004420(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  _DAT_1008d5a8 = DAT_1008723c;
  DAT_1008d59c = DAT_10087248;
  if (DAT_10087064 == 0x10) {
    DAT_10089b54 = (**(code **)(DAT_10089de0 + 0x34c))(0x2100);
    if (DAT_10089b54 == 0) {
      return 0;
    }
    iVar5 = 0x20;
    iVar1 = (DAT_10089b54 & 0xffffff00) + 0x100;
    iVar4 = DAT_10087248;
    _DAT_1008d598 = iVar1;
    do {
      iVar2 = 0;
      do {
        iVar3 = iVar2 + 1;
        *(char *)(iVar2 + iVar1) = *(char *)(iVar2 + iVar4) << 3;
        *(char *)(iVar2 + 0x20 + iVar1) = *(char *)(iVar2 + iVar4) << 3;
        *(char *)(iVar2 + 0x40 + iVar1) = *(char *)(iVar2 + iVar4) << 3;
        *(char *)(iVar2 + 0x60 + iVar1) = *(char *)(iVar2 + iVar4) << 3;
        *(char *)(iVar2 + 0x80 + iVar1) = *(char *)(iVar2 + iVar4) << 3;
        *(char *)(iVar2 + 0xa0 + iVar1) = *(char *)(iVar2 + iVar4) << 3;
        *(char *)(iVar2 + 0xc0 + iVar1) = *(char *)(iVar2 + iVar4) << 3;
        *(char *)(iVar2 + 0xe0 + iVar1) = *(char *)(iVar2 + iVar4) << 3;
        iVar2 = iVar3;
      } while (iVar3 < 0x20);
      iVar1 = iVar1 + 0x100;
      iVar4 = iVar4 + 0x20;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return 1;
}


