// 1005ae30 FUN_1005ae30 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1005ae30(uint *param_1)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  ushort *puVar11;
  longlong lVar12;
  longlong lVar13;
  undefined2 local_5a;
  int local_58;
  uint local_54;
  uint local_50;
  uint local_48;
  uint local_44;
  uint local_38;
  int local_34;
  int local_24;
  int local_10;
  
  uVar2 = param_1[0xc];
  uVar9 = *param_1;
  uVar10 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar9 = uVar9 + uVar3;
    uVar10 = uVar10 + uVar4;
    local_50 = param_1[0x13] + param_1[0x14];
    param_1[0x70] = (uint)((float)param_1[0x71] + (float)param_1[0x70]);
    param_1[0x72] = (uint)((float)param_1[0x72] + (float)param_1[0x73]);
    param_1[0x74] = (uint)((float)param_1[0x74] + (float)param_1[0x75]);
    param_1[0x76] = (uint)((float)param_1[0x76] + (float)param_1[0x77]);
    param_1[0x78] = (uint)((float)param_1[0x78] + (float)param_1[0x79]);
    uVar7 = param_1[0x16];
    param_1[0x13] = local_50;
    param_1[0x7a] = (uint)((float)param_1[0x7a] + (float)param_1[0x7b]);
    param_1[0x16] = uVar7 + param_1[0x17];
    local_58 = ((int)uVar9 >> 0x10) - ((int)uVar10 >> 0x10);
    if (local_58 < 0) {
      local_5a = (short)(uVar7 + param_1[0x17]);
      iVar6 = ((int)uVar10 >> 0x10) * 2 + param_1[5];
      local_54 = *(uint *)(DAT_1008724c + ((uVar9 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
      if (local_58 < -0x10) {
        local_24 = -local_58 >> 4;
        lVar12 = __ftol();
        lVar13 = __ftol();
        puVar11 = (ushort *)(iVar6 + local_58 * 2);
        local_38 = (uint)lVar13;
        local_34 = (int)lVar12;
        do {
          lVar12 = __ftol();
          iVar8 = (int)lVar12;
          lVar12 = __ftol();
          uVar7 = (uint)lVar12;
          local_48 = (local_38 & 0xfffc) >> 2 | local_34 << 0x10;
          local_10 = 0x10;
          local_58 = local_58 + 0x10;
          do {
            if (((local_54 & 0xff) < param_1[10]) &&
               (uVar1 = *(ushort *)
                         ((((local_48 & 0x1e000000) >> 0x16 | local_48 & 0x780) >> 2) + uVar2),
               uVar1 != 0)) {
              *puVar11 = (ushort)*(byte *)(((local_54 & 0xff) + local_50 >> 8 & 0xff) * 0x20 +
                                           (uint)((uVar1 & 0x7c0) >> 6) + 0x400 + DAT_10087248) << 6
                         | (ushort)*(byte *)((uint)local_5a._1_1_ * 0x20 + (uVar1 & 0x1f) + 0x800 +
                                            DAT_10087248) |
                         (ushort)*(byte *)((((uint)(uVar1 >> 0xb) ^ (int)local_50 >> 0x13) & 0x1f ^
                                           (int)local_50 >> 0x13) + DAT_10087248) << 0xb;
            }
            local_48 = local_48 +
                       ((uVar7 - local_38 & 0xfffc0) >> 6 | (iVar8 - local_34 & 0xfffffff0U) << 0xc)
            ;
            puVar11 = puVar11 + 1;
            local_54 = local_54 ^ local_54 >> 6;
            local_5a = local_5a + (short)param_1[0x18];
            local_50 = local_50 + param_1[0x15];
            local_10 = local_10 + -1;
          } while (local_10 != 0);
          local_24 = local_24 + -1;
          local_38 = uVar7;
          local_34 = iVar8;
        } while (0 < local_24);
        if (local_58 < 0) {
          local_48 = (uVar7 & 0xfffc) >> 2 | iVar8 << 0x10;
          lVar12 = __ftol();
          uVar7 = (int)(uVar7 - (int)lVar12) / local_58;
          lVar12 = __ftol();
          iVar8 = (iVar8 - (int)lVar12) / local_58;
          puVar11 = (ushort *)(iVar6 + local_58 * 2);
          do {
            if (((local_54 & 0xff) < param_1[10]) &&
               (uVar1 = *(ushort *)
                         ((((local_48 & 0x1e000000) >> 0x16 | local_48 & 0x780) >> 2) + uVar2),
               uVar1 != 0)) {
              *puVar11 = (ushort)*(byte *)(((local_54 & 0xff) + local_50 >> 8 & 0xff) * 0x20 +
                                           (uint)((uVar1 & 0x7c0) >> 6) + 0x400 + DAT_10087248) << 6
                         | (ushort)*(byte *)((uint)local_5a._1_1_ * 0x20 + (uVar1 & 0x1f) + 0x800 +
                                            DAT_10087248) |
                         (ushort)*(byte *)((((uint)(uVar1 >> 0xb) ^ (int)local_50 >> 0x13) & 0x1f ^
                                           (int)local_50 >> 0x13) + DAT_10087248) << 0xb;
            }
            local_48 = local_48 + ((uVar7 & 0xfffc) >> 2 | iVar8 << 0x10);
            puVar11 = puVar11 + 1;
            local_54 = local_54 ^ local_54 >> 6;
            local_5a = local_5a + (short)param_1[0x18];
            local_50 = local_50 + param_1[0x15];
            local_58 = local_58 + 1;
          } while (local_58 < 0);
        }
      }
      else {
        lVar12 = __ftol();
        lVar13 = __ftol();
        local_44 = ((uint)lVar12 & 0x3fffc) >> 2 | (int)lVar13 << 0x10;
        lVar12 = __ftol();
        lVar13 = __ftol();
        puVar11 = (ushort *)(iVar6 + local_58 * 2);
        do {
          if (((local_54 & 0xff) < param_1[10]) &&
             (uVar1 = *(ushort *)
                       ((((local_44 & 0x1e000000) >> 0x16 | local_44 & 0x780) >> 2) + uVar2),
             uVar1 != 0)) {
            *puVar11 = (ushort)*(byte *)(((local_54 & 0xff) + local_50 >> 8 & 0xff) * 0x20 +
                                         (uint)((uVar1 & 0x7c0) >> 6) + 0x400 + DAT_10087248) << 6 |
                       (ushort)*(byte *)((uint)local_5a._1_1_ * 0x20 + (uVar1 & 0x1f) + 0x800 +
                                        DAT_10087248) |
                       (ushort)*(byte *)((((uint)(uVar1 >> 0xb) ^ (int)local_50 >> 0x13) & 0x1f ^
                                         (int)local_50 >> 0x13) + DAT_10087248) << 0xb;
          }
          local_44 = local_44 + (((uint)lVar12 & 0x3fffc) >> 2 | (int)lVar13 << 0x10);
          puVar11 = puVar11 + 1;
          local_54 = local_54 ^ local_54 >> 6;
          local_5a = local_5a + (short)param_1[0x18];
          local_50 = local_50 + param_1[0x15];
          local_58 = local_58 + 1;
        } while (local_58 < 0);
      }
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar9;
  param_1[1] = uVar10;
  return;
}


