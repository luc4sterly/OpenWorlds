// 100454a0 FUN_100454a0 [Global]
// programa: RWDL6D21.DLL

void FUN_100454a0(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  ushort *puVar11;
  undefined2 local_32;
  int local_30;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_18;
  ushort *local_14;
  
  uVar9 = param_1[1];
  uVar8 = *param_1;
  uVar1 = param_1[3];
  uVar2 = param_1[2];
  uVar3 = param_1[0xc];
  uVar4 = param_1[4];
  while (uVar4 = uVar4 - 1, -1 < (int)uVar4) {
    uVar8 = uVar8 + uVar1;
    uVar9 = uVar9 + uVar2;
    local_20 = param_1[0x13] + param_1[0x14];
    param_1[0x13] = local_20;
    local_24 = param_1[0x11] + param_1[0x10] & 0x7fff7fff;
    uVar5 = param_1[0x16];
    iVar10 = (int)uVar9 >> 0x10;
    local_18 = param_1[0x1a] + param_1[0x19];
    param_1[0x10] = local_24;
    param_1[0x16] = uVar5 + param_1[0x17];
    local_30 = ((int)uVar8 >> 0x10) - iVar10;
    param_1[0x19] = local_18;
    if (local_30 < 0) {
      local_32 = (short)(uVar5 + param_1[0x17]);
      local_28 = *(uint *)(DAT_10079224 + ((uVar8 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
      puVar11 = (ushort *)(param_1[7] + iVar10 * 2 + local_30 * 2);
      local_14 = (ushort *)(param_1[5] + iVar10 * 2 + local_30 * 2);
      do {
        if ((((local_28 & 0xff) < param_1[10]) &&
            (uVar7 = (ushort)(local_18 >> 0x10), *puVar11 < uVar7)) &&
           (puVar6 = (ushort *)(uVar3 + ((local_24 & 0xf00) >> 7 | (local_24 & 0xf000000) >> 0x13)),
           *puVar6 != 0)) {
          *puVar11 = uVar7;
          uVar7 = *puVar6;
          *local_14 = (ushort)*(byte *)(((local_28 & 0xff) + local_20 >> 8 & 0xff) * 0x20 +
                                        (uint)((uVar7 & 0x7c0) >> 6) + 0x400 + DAT_10079220) << 6 |
                      (ushort)*(byte *)((uint)local_32._1_1_ * 0x20 + (uVar7 & 0x1f) + 0x800 +
                                       DAT_10079220) |
                      (ushort)*(byte *)((((uint)(uVar7 >> 0xb) ^ (int)local_20 >> 0x13) & 0x1f ^
                                        (int)local_20 >> 0x13) + DAT_10079220) << 0xb;
        }
        local_28 = local_28 ^ local_28 >> 6;
        local_18 = local_18 + param_1[0x1b];
        local_32 = local_32 + (short)param_1[0x18];
        local_24 = param_1[0x12] + local_24 & 0x7fff7fff;
        puVar11 = puVar11 + 1;
        local_20 = local_20 + param_1[0x15];
        local_14 = local_14 + 1;
        local_30 = local_30 + 1;
      } while (local_30 < 0);
    }
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
    param_1[7] = param_1[7] + param_1[8];
    param_1[5] = param_1[5] + param_1[6];
  }
  *param_1 = uVar8;
  param_1[1] = uVar9;
  return;
}


