// 10039630 FUN_10039630 [Global]
// program: RWDL8D21.DLL

void FUN_10039630(uint *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  ushort uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint local_24;
  uint local_1c;
  
  uVar2 = param_1[0xc];
  uVar8 = *param_1;
  uVar11 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar8 = uVar8 + uVar3;
    uVar11 = uVar11 + uVar4;
    local_24 = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    uVar12 = param_1[0x1a] + param_1[0x19];
    iVar13 = (int)uVar11 >> 0x10;
    param_1[0x10] = local_24;
    iVar9 = ((int)uVar8 >> 0x10) - iVar13;
    param_1[0x19] = uVar12;
    if (iVar9 < 0) {
      uVar6 = param_1[5];
      local_1c = *(uint *)(DAT_10075224 + ((uVar8 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
      iVar1 = param_1[7] + iVar13 * 2;
      do {
        if ((((local_1c & 0xff) < param_1[10]) &&
            (uVar10 = (ushort)(uVar12 >> 0x10), *(ushort *)(iVar1 + iVar9 * 2) < uVar10)) &&
           (pcVar7 = (char *)(uVar2 + ((local_24 & 0xf00) >> 8 | (local_24 & 0xf000000) >> 0x14)),
           *pcVar7 != '\0')) {
          *(ushort *)(iVar1 + iVar9 * 2) = uVar10;
          *(char *)(uVar6 + iVar13 + iVar9) = *pcVar7;
        }
        local_1c = local_1c ^ local_1c >> 6;
        local_24 = param_1[0x12] + local_24 & 0x7fff7fff;
        uVar12 = uVar12 + param_1[0x1b];
        iVar9 = iVar9 + 1;
      } while (iVar9 < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
    param_1[7] = param_1[7] + param_1[8];
  }
  *param_1 = uVar8;
  param_1[1] = uVar11;
  return;
}


