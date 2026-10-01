// 1000f250 FUN_1000f250 [Global]
// program: rwdlmd21.dll

void FUN_1000f250(int *param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ushort uVar8;
  int iVar9;
  short *psVar10;
  int iVar11;
  ushort *puVar12;
  int local_20;
  uint local_1c;
  
  iVar6 = *param_1;
  iVar9 = param_1[1];
  iVar2 = param_1[3];
  iVar3 = param_1[2];
  iVar4 = param_1[0xc];
  iVar5 = param_1[4];
  while (iVar5 = iVar5 + -1, -1 < iVar5) {
    iVar6 = iVar6 + iVar2;
    iVar9 = iVar9 + iVar3;
    local_1c = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    iVar7 = param_1[0x1a] + param_1[0x19];
    iVar11 = iVar9 >> 0x10;
    param_1[0x10] = local_1c;
    local_20 = (iVar6 >> 0x10) - iVar11;
    param_1[0x19] = iVar7;
    if (local_20 < 0) {
      psVar10 = (short *)(param_1[5] + iVar11 * 2 + local_20 * 2);
      puVar12 = (ushort *)(param_1[7] + iVar11 * 2 + local_20 * 2);
      do {
        uVar8 = (ushort)((uint)iVar7 >> 0x10);
        if ((*puVar12 < uVar8) &&
           (sVar1 = *(short *)(((local_1c & 0x7f000000) >> 0x10 | (local_1c & 0x7f00) >> 7) + iVar4)
           , sVar1 != 0)) {
          *psVar10 = sVar1;
          *puVar12 = uVar8;
        }
        local_1c = param_1[0x12] + local_1c & 0x7fff7fff;
        iVar7 = iVar7 + param_1[0x1b];
        psVar10 = psVar10 + 1;
        puVar12 = puVar12 + 1;
        local_20 = local_20 + 1;
      } while (local_20 < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[7] = param_1[7] + param_1[8];
  }
  *param_1 = iVar6;
  param_1[1] = iVar9;
  return;
}


