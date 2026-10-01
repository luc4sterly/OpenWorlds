// 10019350 FUN_10019350 [Global]
// program: RWDL8D21.DLL

void FUN_10019350(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  ushort uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint local_30;
  uint local_28;
  uint local_24;
  
  iVar6 = DAT_10075220;
  uVar1 = param_1[0xc];
  uVar8 = *param_1;
  uVar13 = param_1[1];
  uVar2 = param_1[3];
  uVar3 = param_1[2];
  uVar4 = param_1[4];
  while (uVar4 = uVar4 - 1, -1 < (int)uVar4) {
    uVar8 = uVar8 + uVar2;
    uVar13 = uVar13 + uVar3;
    local_24 = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    uVar14 = param_1[0x13] + param_1[0x14];
    iVar10 = (int)uVar13 >> 0x10;
    param_1[0x10] = local_24;
    param_1[0x13] = uVar14;
    uVar7 = param_1[0x1a] + param_1[0x19];
    iVar15 = ((int)uVar8 >> 0x10) - iVar10;
    param_1[0x19] = uVar7;
    if (iVar15 < 0) {
      local_28 = *(uint *)(DAT_10075224 + ((uVar8 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
      uVar5 = param_1[5];
      iVar9 = iVar10 * 2 + param_1[7];
      do {
        uVar12 = (ushort)(uVar7 >> 0x10);
        if ((*(ushort *)(iVar9 + iVar15 * 2) < uVar12) &&
           (pbVar11 = (byte *)(((local_24 & 0x7f000000) >> 0x11 | (local_24 & 0x7f00) >> 8) + uVar1)
           , *pbVar11 != 0)) {
          *(ushort *)(iVar9 + iVar15 * 2) = uVar12;
          local_30 = (uint)*pbVar11;
          *(undefined1 *)(uVar5 + iVar10 + iVar15) =
               *(undefined1 *)(((local_28 & 0xff) + uVar14 & 0xff00) + local_30 + iVar6);
        }
        local_28 = local_28 ^ local_28 >> 6;
        local_24 = param_1[0x12] + local_24 & 0x7fff7fff;
        uVar14 = uVar14 + param_1[0x15];
        uVar7 = uVar7 + param_1[0x1b];
        iVar15 = iVar15 + 1;
      } while (iVar15 < 0);
    }
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
    param_1[7] = param_1[7] + param_1[8];
    param_1[5] = param_1[5] + param_1[6];
  }
  *param_1 = uVar8;
  param_1[1] = uVar13;
  return;
}


