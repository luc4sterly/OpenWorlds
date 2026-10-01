// 10046160 FUN_10046160 [Global]
// program: RWDL6D21.DLL

void FUN_10046160(uint *param_1)

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
  
  uVar2 = param_1[0xc];
  uVar6 = *param_1;
  uVar9 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar6 = uVar6 + uVar3;
    uVar9 = uVar9 + uVar4;
    uVar10 = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    param_1[0x10] = uVar10;
    uVar7 = *(uint *)(DAT_10079224 + ((uVar6 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
    iVar11 = ((int)uVar6 >> 0x10) - ((int)uVar9 >> 0x10);
    if (iVar11 < 0) {
      psVar8 = (short *)(param_1[5] + ((int)uVar9 >> 0x10) * 2 + iVar11 * 2);
      do {
        sVar1 = *(short *)((((int)(short)((short)(char)uVar7 ^ 0xaa) + ((int)uVar10 >> 0x10) &
                             0xf00U | ((int)(short)(char)uVar7 + uVar10 & 0xf00) >> 4) >> 3) + uVar2
                          );
        if (sVar1 != 0) {
          *psVar8 = sVar1;
        }
        psVar8 = psVar8 + 1;
        uVar7 = uVar7 ^ uVar7 >> 6;
        uVar10 = param_1[0x12] + uVar10 & 0x7fff7fff;
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


