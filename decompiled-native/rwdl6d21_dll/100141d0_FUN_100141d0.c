// 100141d0 FUN_100141d0 [Global]
// programa: RWDL6D21.DLL

void FUN_100141d0(uint *param_1)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined2 local_2a;
  uint local_24;
  uint local_20;
  int local_1c;
  ushort *local_14;
  
  uVar8 = param_1[1];
  uVar7 = *param_1;
  uVar2 = param_1[3];
  uVar3 = param_1[2];
  uVar4 = param_1[0xc];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar7 = uVar7 + uVar2;
    uVar8 = uVar8 + uVar3;
    local_20 = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    uVar9 = param_1[0x13] + param_1[0x14];
    uVar6 = param_1[0x16];
    param_1[0x10] = local_20;
    param_1[0x13] = uVar9;
    param_1[0x16] = uVar6 + param_1[0x17];
    local_1c = ((int)uVar7 >> 0x10) - ((int)uVar8 >> 0x10);
    if (local_1c < 0) {
      local_2a = (short)(uVar6 + param_1[0x17]);
      local_24 = *(uint *)(DAT_10079224 + ((uVar7 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
      local_14 = (ushort *)(((int)uVar8 >> 0x10) * 2 + param_1[5] + local_1c * 2);
      do {
        uVar1 = *(ushort *)(((local_20 & 0x7f00) >> 7 | (local_20 & 0x7f000000) >> 0x10) + uVar4);
        if (uVar1 != 0) {
          *local_14 = (ushort)*(byte *)(((local_24 & 0xff) + uVar9 >> 8 & 0xff) * 0x20 +
                                        (uint)((uVar1 & 0x7c0) >> 6) + 0x400 + DAT_10079220) << 6 |
                      (ushort)*(byte *)((uint)local_2a._1_1_ * 0x20 + (uVar1 & 0x1f) + 0x800 +
                                       DAT_10079220) |
                      (ushort)*(byte *)((((uint)(uVar1 >> 0xb) ^ (int)uVar9 >> 0x13) & 0x1f ^
                                        (int)uVar9 >> 0x13) + DAT_10079220) << 0xb;
        }
        local_24 = local_24 ^ local_24 >> 6;
        uVar9 = uVar9 + param_1[0x15];
        local_20 = param_1[0x12] + local_20 & 0x7fff7fff;
        local_14 = local_14 + 1;
        local_2a = local_2a + (short)param_1[0x18];
        local_1c = local_1c + 1;
      } while (local_1c < 0);
    }
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
    param_1[5] = param_1[5] + param_1[6];
  }
  *param_1 = uVar7;
  param_1[1] = uVar8;
  return;
}


