// 10015b30 FUN_10015b30 [Global]
// program: RWDL6D21.DLL

void FUN_10015b30(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  uint uVar7;
  int iVar8;
  ushort uVar9;
  uint uVar10;
  ushort *puVar11;
  undefined2 local_32;
  int local_30;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_18;
  ushort *local_14;
  
  uVar10 = param_1[1];
  uVar7 = *param_1;
  uVar1 = param_1[3];
  uVar2 = param_1[2];
  uVar3 = param_1[0xc];
  uVar4 = param_1[4];
  while (uVar4 = uVar4 - 1, -1 < (int)uVar4) {
    uVar7 = uVar7 + uVar1;
    uVar10 = uVar10 + uVar2;
    local_24 = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    param_1[0x10] = local_24;
    local_20 = param_1[0x13] + param_1[0x14];
    uVar5 = param_1[0x16];
    param_1[0x13] = local_20;
    local_18 = param_1[0x1a] + param_1[0x19];
    iVar8 = (int)uVar10 >> 0x10;
    param_1[0x16] = uVar5 + param_1[0x17];
    local_30 = ((int)uVar7 >> 0x10) - iVar8;
    param_1[0x19] = local_18;
    if (local_30 < 0) {
      local_32 = (short)(uVar5 + param_1[0x17]);
      local_28 = *(uint *)(DAT_10079224 + ((uVar7 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
      puVar11 = (ushort *)(param_1[7] + iVar8 * 2 + local_30 * 2);
      local_14 = (ushort *)(param_1[5] + iVar8 * 2 + local_30 * 2);
      do {
        uVar9 = (ushort)(local_18 >> 0x10);
        if ((*puVar11 < uVar9) &&
           (puVar6 = (ushort *)
                     (uVar3 + ((local_24 & 0x7f000000) >> 0x10 | (local_24 & 0x7f00) >> 7)),
           *puVar6 != 0)) {
          *puVar11 = uVar9;
          uVar9 = *puVar6;
          *local_14 = (ushort)*(byte *)(((local_28 & 0xff) + local_20 >> 8 & 0xff) * 0x20 +
                                        (uint)((uVar9 & 0x7c0) >> 6) + 0x400 + DAT_10079220) << 6 |
                      (ushort)*(byte *)((uint)local_32._1_1_ * 0x20 + (uVar9 & 0x1f) + 0x800 +
                                       DAT_10079220) |
                      (ushort)*(byte *)((((uint)(uVar9 >> 0xb) ^ (int)local_20 >> 0x13) & 0x1f ^
                                        (int)local_20 >> 0x13) + DAT_10079220) << 0xb;
        }
        local_28 = local_28 ^ local_28 >> 6;
        puVar11 = puVar11 + 1;
        local_24 = param_1[0x12] + local_24 & 0x7fff7fff;
        local_20 = local_20 + param_1[0x15];
        local_32 = local_32 + (short)param_1[0x18];
        local_18 = local_18 + param_1[0x1b];
        local_14 = local_14 + 1;
        local_30 = local_30 + 1;
      } while (local_30 < 0);
    }
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
    param_1[5] = param_1[5] + param_1[6];
    param_1[7] = param_1[7] + param_1[8];
  }
  *param_1 = uVar7;
  param_1[1] = uVar10;
  return;
}


