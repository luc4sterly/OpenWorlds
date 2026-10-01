// 100170b0 FUN_100170b0 [Global]
// program: RWDL8D21.DLL

void FUN_100170b0(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  byte *pbVar10;
  ushort uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint local_28;
  uint local_20;
  
  uVar1 = param_1[0xc];
  uVar2 = param_1[0xd];
  uVar8 = *param_1;
  uVar12 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar8 = uVar8 + uVar3;
    uVar12 = uVar12 + uVar4;
    local_28 = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    uVar13 = param_1[0x1a] + param_1[0x19];
    param_1[0x10] = local_28;
    param_1[0x19] = uVar13;
    local_20 = *(uint *)(DAT_10075224 + ((uVar8 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
    iVar7 = (int)uVar12 >> 0x10;
    iVar9 = ((int)uVar8 >> 0x10) - iVar7;
    if (iVar9 < 0) {
      uVar6 = param_1[5];
      iVar14 = iVar7 * 2 + param_1[7];
      do {
        if ((((local_20 & 0xff) < param_1[10]) &&
            (uVar11 = (ushort)(uVar13 >> 0x10), *(ushort *)(iVar14 + iVar9 * 2) < uVar11)) &&
           (pbVar10 = (byte *)(((local_28 & 0x7f00) >> 8 | (local_28 & 0x7f000000) >> 0x11) + uVar1)
           , *pbVar10 != 0)) {
          *(ushort *)(iVar14 + iVar9 * 2) = uVar11;
          *(undefined1 *)(uVar6 + iVar7 + iVar9) = *(undefined1 *)(*pbVar10 + uVar2);
        }
        local_20 = local_20 ^ local_20 >> 6;
        local_28 = param_1[0x12] + local_28 & 0x7fff7fff;
        uVar13 = uVar13 + param_1[0x1b];
        iVar9 = iVar9 + 1;
      } while (iVar9 < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
    param_1[7] = param_1[7] + param_1[8];
  }
  *param_1 = uVar8;
  param_1[1] = uVar12;
  return;
}


