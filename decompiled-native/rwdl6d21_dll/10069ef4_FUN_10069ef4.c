// 10069ef4 FUN_10069ef4 [Global]
// program: RWDL6D21.DLL

void FUN_10069ef4(void)

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
  
  iVar3 = DAT_1007f2b0;
  do {
    DAT_1007f280 = DAT_1007f280 + DAT_1007f28c;
    DAT_1007f284 = DAT_1007f284 + DAT_1007f288;
    iVar4 = DAT_1007f284 >> 0x10;
    iVar9 = DAT_1007f2e4 + DAT_1007f2e8;
    uVar7 = DAT_1007f2c0 + DAT_1007f2c4 & 0x7fff7fff;
    iVar6 = (DAT_1007f280 >> 0x10) - iVar4;
    DAT_1007f2c0 = uVar7;
    DAT_1007f2e4 = iVar9;
    if (DAT_1007f280 >> 0x10 < iVar4) {
      iVar1 = DAT_1007f29c + iVar4 * 2;
      iVar4 = DAT_1007f294 + iVar4 * 2;
      do {
        uVar8 = (ushort)((uint)iVar9 >> 0x10);
        if ((*(ushort *)(iVar1 + iVar6 * 2) <= uVar8) &&
           (uVar5 = uVar7 >> 0x11 & 0x3f80,
           sVar2 = *(short *)(iVar3 + CONCAT31((int3)(uVar5 >> 8),(byte)uVar5 | (byte)(uVar7 >> 8))
                                      * 2), sVar2 != 0)) {
          *(ushort *)(iVar1 + iVar6 * 2) = uVar8;
          *(short *)(iVar4 + iVar6 * 2) = sVar2;
        }
        iVar9 = iVar9 + DAT_1007f2ec;
        uVar7 = uVar7 + DAT_1007f2c8 & 0x7fff7fff;
        iVar6 = iVar6 + 1;
      } while (iVar6 < 0);
    }
    DAT_1007f294 = DAT_1007f294 + DAT_1007f298;
    DAT_1007f29c = DAT_1007f29c + DAT_1007f2a0;
    DAT_1007f290 = DAT_1007f290 + -1;
  } while (DAT_1007f290 != 0);
  return;
}


