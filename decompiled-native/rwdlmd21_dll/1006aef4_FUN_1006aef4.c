// 1006aef4 FUN_1006aef4 [Global]
// programa: rwdlmd21.dll

void FUN_1006aef4(void)

{
  int iVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  ushort uVar8;
  int iVar9;
  
  iVar3 = DAT_1008d2b0;
  do {
    DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
    DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
    iVar4 = DAT_1008d284 >> 0x10;
    iVar9 = DAT_1008d2e4 + DAT_1008d2e8;
    uVar7 = DAT_1008d2c0 + DAT_1008d2c4 & 0x7fff7fff;
    iVar6 = (DAT_1008d280 >> 0x10) - iVar4;
    DAT_1008d2c0 = uVar7;
    DAT_1008d2e4 = iVar9;
    if (DAT_1008d280 >> 0x10 < iVar4) {
      iVar1 = DAT_1008d29c + iVar4 * 2;
      iVar4 = DAT_1008d294 + iVar4 * 2;
      do {
        uVar8 = (ushort)((uint)iVar9 >> 0x10);
        if ((*(ushort *)(iVar1 + iVar6 * 2) <= uVar8) &&
           (uVar5 = uVar7 >> 0x11 & 0x3f80,
           sVar2 = *(short *)(iVar3 + CONCAT31((int3)(uVar5 >> 8),(byte)uVar5 | (byte)(uVar7 >> 8))
                                      * 2), sVar2 != 0)) {
          *(ushort *)(iVar1 + iVar6 * 2) = uVar8;
          *(short *)(iVar4 + iVar6 * 2) = sVar2;
        }
        iVar9 = iVar9 + DAT_1008d2ec;
        uVar7 = uVar7 + DAT_1008d2c8 & 0x7fff7fff;
        iVar6 = iVar6 + 1;
      } while (iVar6 < 0);
    }
    DAT_1008d294 = DAT_1008d294 + DAT_1008d298;
    DAT_1008d29c = DAT_1008d29c + DAT_1008d2a0;
    DAT_1008d290 = DAT_1008d290 + -1;
  } while (DAT_1008d290 != 0);
  return;
}


