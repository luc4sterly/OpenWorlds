// 1000d8c0 FUN_1000d8c0 [Global]
// program: rwdlmd21.dll

void FUN_1000d8c0(int *param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short *psVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  
  iVar6 = *param_1;
  iVar8 = param_1[1];
  iVar2 = param_1[3];
  iVar3 = param_1[2];
  iVar4 = param_1[0xc];
  iVar5 = param_1[4];
  while (iVar5 = iVar5 + -1, -1 < iVar5) {
    iVar6 = iVar6 + iVar2;
    iVar8 = iVar8 + iVar3;
    uVar9 = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    param_1[0x10] = uVar9;
    iVar10 = (iVar6 >> 0x10) - (iVar8 >> 0x10);
    if (iVar10 < 0) {
      psVar7 = (short *)(param_1[5] + (iVar8 >> 0x10) * 2 + iVar10 * 2);
      do {
        sVar1 = *(short *)(((uVar9 & 0x7f000000) >> 0x10 | (uVar9 & 0x7f00) >> 7) + iVar4);
        if (sVar1 != 0) {
          *psVar7 = sVar1;
        }
        psVar7 = psVar7 + 1;
        uVar9 = param_1[0x12] + uVar9 & 0x7fff7fff;
        iVar10 = iVar10 + 1;
      } while (iVar10 < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
  }
  *param_1 = iVar6;
  param_1[1] = iVar8;
  return;
}


