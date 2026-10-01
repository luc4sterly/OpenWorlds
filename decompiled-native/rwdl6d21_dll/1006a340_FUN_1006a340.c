// 1006a340 FUN_1006a340 [Global]
// program: RWDL6D21.DLL

void FUN_1006a340(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  do {
    DAT_1007f280 = DAT_1007f280 + DAT_1007f28c;
    uVar4 = DAT_1007f280 >> 0x10;
    DAT_1007f284 = DAT_1007f284 + DAT_1007f288;
    uVar3 = DAT_1007f284 >> 0x10;
    DAT_1007f2c0 = DAT_1007f2c0 + DAT_1007f2c4;
    iVar6 = DAT_1007f2cc + DAT_1007f2d0;
    iVar5 = uVar4 - uVar3;
    DAT_1007f2cc = iVar6;
    DAT_1007fc68 = DAT_1007f2c0;
    if (uVar4 < uVar3) {
      uVar2 = *(undefined4 *)(DAT_1007f590 + (uVar4 & 7) * 4);
      iVar1 = DAT_1007f294 + uVar3 * 2;
      uVar3 = CONCAT31((int3)((uint)uVar2 >> 8),(byte)uVar2 ^ (byte)DAT_1007f2a4);
      do {
        iVar7 = (DAT_1007fc68 >> 0x18) << 5;
        iVar7 = CONCAT31((int3)((uint)iVar7 >> 8),
                         (char)iVar7 + (char)(DAT_1007fc68 >> 8) +
                         CARRY1((byte)DAT_1007fc68,(byte)uVar3)) << 6;
        uVar4 = (uint)iVar6 >> 8;
        iVar6 = iVar6 + DAT_1007f2d4;
        DAT_1007fc68 = DAT_1007f2c8 + DAT_1007fc68;
        *(short *)(iVar1 + iVar5 * 2) =
             (short)CONCAT31((int3)((uint)iVar7 >> 8),(byte)iVar7 | (byte)uVar4);
        uVar3 = uVar3 ^ uVar3 >> 6;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 0);
    }
    DAT_1007f294 = DAT_1007f294 + DAT_1007f298;
    DAT_1007f2a4 = DAT_1007f2a4 ^ DAT_1007f2a4 >> 6;
    DAT_1007f290 = DAT_1007f290 + -1;
  } while (DAT_1007f290 != 0);
  return;
}


