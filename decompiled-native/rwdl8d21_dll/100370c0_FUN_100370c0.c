// 100370c0 FUN_100370c0 [Global]
// programa: RWDL8D21.DLL

void FUN_100370c0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  ushort uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint local_20;
  
  iVar2 = param_1[0xc];
  iVar8 = *param_1;
  iVar11 = param_1[1];
  iVar3 = param_1[3];
  iVar4 = param_1[2];
  iVar5 = param_1[4];
  while (iVar5 = iVar5 + -1, -1 < iVar5) {
    iVar8 = iVar8 + iVar3;
    iVar11 = iVar11 + iVar4;
    local_20 = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    iVar12 = param_1[0x1a] + param_1[0x19];
    param_1[0x10] = local_20;
    param_1[0x19] = iVar12;
    iVar13 = iVar11 >> 0x10;
    iVar9 = (iVar8 >> 0x10) - iVar13;
    if (iVar9 < 0) {
      iVar6 = param_1[5];
      iVar1 = param_1[7] + iVar13 * 2;
      do {
        uVar10 = (ushort)((uint)iVar12 >> 0x10);
        if ((*(ushort *)(iVar1 + iVar9 * 2) < uVar10) &&
           (pcVar7 = (char *)(iVar2 + ((local_20 & 0xf00) >> 8 | (local_20 & 0xf000000) >> 0x14)),
           *pcVar7 != '\0')) {
          *(ushort *)(iVar1 + iVar9 * 2) = uVar10;
          *(char *)(iVar6 + iVar13 + iVar9) = *pcVar7;
        }
        local_20 = param_1[0x12] + local_20 & 0x7fff7fff;
        iVar12 = iVar12 + param_1[0x1b];
        iVar9 = iVar9 + 1;
      } while (iVar9 < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[7] = param_1[7] + param_1[8];
  }
  *param_1 = iVar8;
  param_1[1] = iVar11;
  return;
}


