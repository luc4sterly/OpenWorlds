// 1003e8a0 FUN_1003e8a0 [Global]
// program: RWDL8D21.DLL

void FUN_1003e8a0(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  byte *pbVar11;
  uint uVar12;
  int iVar13;
  ushort uVar14;
  uint local_30;
  uint local_24;
  uint local_20;
  uint local_18;
  
  iVar6 = DAT_10075220;
  uVar1 = param_1[0xc];
  uVar8 = *param_1;
  uVar12 = param_1[1];
  uVar2 = param_1[3];
  uVar3 = param_1[2];
  uVar4 = param_1[4];
  while (uVar4 = uVar4 - 1, -1 < (int)uVar4) {
    uVar8 = uVar8 + uVar2;
    uVar12 = uVar12 + uVar3;
    local_20 = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    uVar9 = param_1[0x13] + param_1[0x14];
    param_1[0x10] = local_20;
    local_18 = param_1[0x1a] + param_1[0x19];
    iVar10 = (int)uVar12 >> 0x10;
    param_1[0x13] = uVar9;
    iVar13 = ((int)uVar8 >> 0x10) - iVar10;
    param_1[0x19] = local_18;
    if (iVar13 < 0) {
      local_30 = (uint)(byte)param_1[9];
      local_24 = *(uint *)(DAT_10075224 + ((uVar8 & 0x70000) >> 0x10) * 4) ^ local_30;
      uVar5 = param_1[5];
      iVar7 = iVar10 * 2 + param_1[7];
      do {
        if ((((local_24 & 0xff) < param_1[10]) &&
            (uVar14 = (ushort)(local_18 >> 0x10), *(ushort *)(iVar7 + iVar13 * 2) < uVar14)) &&
           (pbVar11 = (byte *)(uVar1 + ((local_20 & 0xf00) >> 8 | (local_20 & 0xf000000) >> 0x14)),
           *pbVar11 != 0)) {
          *(ushort *)(iVar7 + iVar13 * 2) = uVar14;
          *(undefined1 *)(uVar5 + iVar10 + iVar13) =
               *(undefined1 *)(((local_24 & 0xff) + uVar9 & 0xff00) + (uint)*pbVar11 + iVar6);
        }
        local_24 = local_24 ^ local_24 >> 6;
        uVar9 = uVar9 + param_1[0x15];
        local_20 = param_1[0x12] + local_20 & 0x7fff7fff;
        local_18 = local_18 + param_1[0x1b];
        iVar13 = iVar13 + 1;
      } while (iVar13 < 0);
    }
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
    param_1[5] = param_1[5] + param_1[6];
    param_1[7] = param_1[7] + param_1[8];
  }
  *param_1 = uVar8;
  param_1[1] = uVar12;
  return;
}


