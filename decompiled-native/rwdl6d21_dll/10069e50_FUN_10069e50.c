// 10069e50 FUN_10069e50 [Global]
// program: RWDL6D21.DLL

void FUN_10069e50(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar2 = DAT_1007f2b0;
  do {
    DAT_1007f280 = DAT_1007f280 + DAT_1007f28c;
    DAT_1007f284 = DAT_1007f284 + DAT_1007f288;
    uVar3 = DAT_1007f284 >> 0x10;
    uVar5 = DAT_1007f2c0 + DAT_1007f2c4 & 0x7fff7fff;
    iVar4 = (DAT_1007f280 >> 0x10) - uVar3;
    DAT_1007f2c0 = uVar5;
    if (DAT_1007f280 >> 0x10 < uVar3) {
      iVar6 = uVar3 * 2 + DAT_1007f294;
      do {
        uVar3 = uVar5 >> 0x11 & 0x3f80;
        sVar1 = *(short *)(iVar2 + CONCAT31((int3)(uVar3 >> 8),(byte)uVar3 | (byte)(uVar5 >> 8)) * 2
                          );
        uVar5 = uVar5 + DAT_1007f2c8 & 0x7fff7fff;
        if (sVar1 != 0) {
          *(short *)(iVar6 + iVar4 * 2) = sVar1;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < 0);
    }
    DAT_1007f294 = DAT_1007f294 + DAT_1007f298;
    DAT_1007f290 = DAT_1007f290 + -1;
  } while (DAT_1007f290 != 0);
  return;
}


