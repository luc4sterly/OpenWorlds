// 1006ae50 FUN_1006ae50 [Global]
// program: rwdlmd21.dll

void FUN_1006ae50(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar2 = DAT_1008d2b0;
  do {
    DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
    DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
    uVar3 = DAT_1008d284 >> 0x10;
    uVar5 = DAT_1008d2c0 + DAT_1008d2c4 & 0x7fff7fff;
    iVar4 = (DAT_1008d280 >> 0x10) - uVar3;
    DAT_1008d2c0 = uVar5;
    if (DAT_1008d280 >> 0x10 < uVar3) {
      iVar6 = uVar3 * 2 + DAT_1008d294;
      do {
        uVar3 = uVar5 >> 0x11 & 0x3f80;
        sVar1 = *(short *)(iVar2 + CONCAT31((int3)(uVar3 >> 8),(byte)uVar3 | (byte)(uVar5 >> 8)) * 2
                          );
        uVar5 = uVar5 + DAT_1008d2c8 & 0x7fff7fff;
        if (sVar1 != 0) {
          *(short *)(iVar6 + iVar4 * 2) = sVar1;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < 0);
    }
    DAT_1008d294 = DAT_1008d294 + DAT_1008d298;
    DAT_1008d290 = DAT_1008d290 + -1;
  } while (DAT_1008d290 != 0);
  return;
}


