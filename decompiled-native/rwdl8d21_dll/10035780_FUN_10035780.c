// 10035780 FUN_10035780 [Global]
// program: RWDL8D21.DLL

void FUN_10035780(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  ushort uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint local_24;
  
  iVar2 = param_1[0xc];
  iVar3 = param_1[0xd];
  iVar8 = *param_1;
  iVar12 = param_1[1];
  iVar4 = param_1[3];
  iVar5 = param_1[2];
  iVar6 = param_1[4];
  while (iVar6 = iVar6 + -1, -1 < iVar6) {
    iVar8 = iVar8 + iVar4;
    iVar12 = iVar12 + iVar5;
    local_24 = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    iVar9 = param_1[0x1a] + param_1[0x19];
    iVar14 = iVar12 >> 0x10;
    param_1[0x10] = local_24;
    iVar13 = (iVar8 >> 0x10) - iVar14;
    param_1[0x19] = iVar9;
    if (iVar13 < 0) {
      iVar7 = param_1[5];
      iVar1 = param_1[7] + iVar14 * 2;
      do {
        uVar11 = (ushort)((uint)iVar9 >> 0x10);
        if ((*(ushort *)(iVar1 + iVar13 * 2) < uVar11) &&
           (pbVar10 = (byte *)(((local_24 & 0xf00) >> 8 | (local_24 & 0xf000000) >> 0x14) + iVar2),
           *pbVar10 != 0)) {
          *(ushort *)(iVar1 + iVar13 * 2) = uVar11;
          *(undefined1 *)(iVar7 + iVar14 + iVar13) = *(undefined1 *)((uint)*pbVar10 + iVar3);
        }
        local_24 = param_1[0x12] + local_24 & 0x7fff7fff;
        iVar9 = iVar9 + param_1[0x1b];
        iVar13 = iVar13 + 1;
      } while (iVar13 < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[7] = param_1[7] + param_1[8];
  }
  *param_1 = iVar8;
  param_1[1] = iVar12;
  return;
}


