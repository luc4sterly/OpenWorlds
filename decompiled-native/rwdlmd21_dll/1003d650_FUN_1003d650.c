// 1003d650 FUN_1003d650 [Global]
// program: rwdlmd21.dll

void FUN_1003d650(uint *param_1)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  short *psVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  
  uVar6 = *param_1;
  uVar9 = param_1[1];
  uVar2 = param_1[3];
  uVar3 = param_1[2];
  uVar4 = param_1[0xc];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar6 = uVar6 + uVar2;
    uVar9 = uVar9 + uVar3;
    uVar10 = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    param_1[0x10] = uVar10;
    uVar7 = *(uint *)(DAT_1008724c + ((uVar6 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
    iVar11 = ((int)uVar6 >> 0x10) - ((int)uVar9 >> 0x10);
    if (iVar11 < 0) {
      psVar8 = (short *)(param_1[5] + ((int)uVar9 >> 0x10) * 2 + iVar11 * 2);
      do {
        if (((uVar7 & 0xff) < param_1[10]) &&
           (sVar1 = *(short *)(((uVar10 & 0xf00) >> 7 | (uVar10 & 0xf000000) >> 0x13) + uVar4),
           sVar1 != 0)) {
          *psVar8 = sVar1;
        }
        psVar8 = psVar8 + 1;
        uVar10 = param_1[0x12] + uVar10 & 0x7fff7fff;
        uVar7 = uVar7 ^ uVar7 >> 6;
        iVar11 = iVar11 + 1;
      } while (iVar11 < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar6;
  param_1[1] = uVar9;
  return;
}


