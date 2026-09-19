// 1005e100 FUN_1005e100 [Global]
// programa: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1005e100(uint *param_1)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  ushort uVar11;
  int iVar12;
  ushort *puVar13;
  longlong lVar14;
  longlong lVar15;
  undefined2 local_66;
  int local_64;
  ushort *local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  ushort *local_48;
  uint local_3c;
  int local_38;
  ushort *local_28;
  int local_24;
  int local_c;
  
  uVar3 = param_1[0xc];
  uVar7 = *param_1;
  uVar10 = param_1[1];
  uVar4 = param_1[3];
  uVar5 = param_1[2];
  uVar6 = param_1[4];
  while (uVar6 = uVar6 - 1, -1 < (int)uVar6) {
    uVar7 = uVar7 + uVar4;
    uVar10 = uVar10 + uVar5;
    local_50 = param_1[0x1a] + param_1[0x19];
    uVar8 = param_1[0x16];
    local_58 = param_1[0x13] + param_1[0x14];
    param_1[0x70] = (uint)((float)param_1[0x70] + (float)param_1[0x71]);
    param_1[0x72] = (uint)((float)param_1[0x72] + (float)param_1[0x73]);
    param_1[0x74] = (uint)((float)param_1[0x74] + (float)param_1[0x75]);
    param_1[0x76] = (uint)((float)param_1[0x76] + (float)param_1[0x77]);
    param_1[0x78] = (uint)((float)param_1[0x78] + (float)param_1[0x79]);
    param_1[0x7a] = (uint)((float)param_1[0x7a] + (float)param_1[0x7b]);
    param_1[0x19] = local_50;
    param_1[0x13] = local_58;
    iVar12 = (int)uVar10 >> 0x10;
    param_1[0x16] = uVar8 + param_1[0x17];
    local_64 = ((int)uVar7 >> 0x10) - iVar12;
    if (local_64 < 0) {
      iVar1 = param_1[5] + iVar12 * 2;
      local_66 = (short)(uVar8 + param_1[0x17]);
      iVar12 = param_1[7] + iVar12 * 2;
      local_5c = *(uint *)(DAT_10079224 + ((uVar7 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
      if (local_64 < -0x10) {
        local_24 = -local_64 >> 4;
        lVar14 = __ftol();
        lVar15 = __ftol();
        puVar13 = (ushort *)(iVar12 + local_64 * 2);
        local_28 = (ushort *)(local_64 * 2 + iVar1);
        local_3c = (uint)lVar15;
        local_38 = (int)lVar14;
        do {
          lVar14 = __ftol();
          iVar9 = (int)lVar14;
          lVar14 = __ftol();
          uVar8 = (uint)lVar14;
          local_54 = (local_3c & 0xfffc) >> 2 | local_38 << 0x10;
          local_c = 0x10;
          local_64 = local_64 + 0x10;
          do {
            if ((((local_5c & 0xff) < param_1[10]) &&
                (uVar11 = (ushort)(local_50 >> 0x10), *puVar13 < uVar11)) &&
               (uVar2 = *(ushort *)
                         ((((local_54 & 0x1e000000) >> 0x16 | local_54 & 0x780) >> 2) + uVar3),
               uVar2 != 0)) {
              *local_28 = (ushort)*(byte *)(((local_5c & 0xff) + local_58 >> 8 & 0xff) * 0x20 +
                                            (uint)((uVar2 & 0x7c0) >> 6) + 0x400 + DAT_10079220) <<
                          6 | (ushort)*(byte *)((uint)local_66._1_1_ * 0x20 + (uVar2 & 0x1f) + 0x800
                                               + DAT_10079220) |
                          (ushort)*(byte *)((((uint)(uVar2 >> 0xb) ^ (int)local_58 >> 0x13) & 0x1f ^
                                            (int)local_58 >> 0x13) + DAT_10079220) << 0xb;
              *puVar13 = uVar11;
            }
            local_54 = local_54 +
                       ((iVar9 - local_38 & 0xfffffff0U) << 0xc | (uVar8 - local_3c & 0xfffc0) >> 6)
            ;
            local_28 = local_28 + 1;
            puVar13 = puVar13 + 1;
            local_50 = local_50 + param_1[0x1b];
            local_5c = local_5c ^ local_5c >> 6;
            local_58 = local_58 + param_1[0x15];
            local_66 = local_66 + (short)param_1[0x18];
            local_c = local_c + -1;
          } while (local_c != 0);
          local_24 = local_24 + -1;
          local_3c = uVar8;
          local_38 = iVar9;
        } while (0 < local_24);
        if (local_64 < 0) {
          local_54 = (uVar8 & 0xfffc) >> 2 | iVar9 << 0x10;
          lVar14 = __ftol();
          uVar8 = (int)(uVar8 - (int)lVar14) / local_64;
          lVar14 = __ftol();
          iVar9 = (iVar9 - (int)lVar14) / local_64;
          puVar13 = (ushort *)(iVar12 + local_64 * 2);
          local_60 = (ushort *)(iVar1 + local_64 * 2);
          do {
            if ((((local_5c & 0xff) < param_1[10]) &&
                (uVar11 = (ushort)(local_50 >> 0x10), *puVar13 < uVar11)) &&
               (uVar2 = *(ushort *)
                         ((((local_54 & 0x1e000000) >> 0x16 | local_54 & 0x780) >> 2) + uVar3),
               uVar2 != 0)) {
              *local_60 = (ushort)*(byte *)(((local_5c & 0xff) + local_58 >> 8 & 0xff) * 0x20 +
                                            (uint)((uVar2 & 0x7c0) >> 6) + 0x400 + DAT_10079220) <<
                          6 | (ushort)*(byte *)((uint)local_66._1_1_ * 0x20 + (uVar2 & 0x1f) + 0x800
                                               + DAT_10079220) |
                          (ushort)*(byte *)((((uint)(uVar2 >> 0xb) ^ (int)local_58 >> 0x13) & 0x1f ^
                                            (int)local_58 >> 0x13) + DAT_10079220) << 0xb;
              *puVar13 = uVar11;
            }
            local_54 = local_54 + ((uVar8 & 0xfffc) >> 2 | iVar9 << 0x10);
            local_60 = local_60 + 1;
            puVar13 = puVar13 + 1;
            local_50 = local_50 + param_1[0x1b];
            local_5c = local_5c ^ local_5c >> 6;
            local_58 = local_58 + param_1[0x15];
            local_66 = local_66 + (short)param_1[0x18];
            local_64 = local_64 + 1;
          } while (local_64 < 0);
        }
      }
      else {
        lVar14 = __ftol();
        lVar15 = __ftol();
        local_4c = ((uint)lVar14 & 0x3fffc) >> 2 | (int)lVar15 << 0x10;
        lVar14 = __ftol();
        lVar15 = __ftol();
        puVar13 = (ushort *)(iVar12 + local_64 * 2);
        local_48 = (ushort *)(iVar1 + local_64 * 2);
        do {
          if ((((local_5c & 0xff) < param_1[10]) &&
              (uVar11 = (ushort)(local_50 >> 0x10), *puVar13 < uVar11)) &&
             (uVar2 = *(ushort *)
                       ((((local_4c & 0x1e000000) >> 0x16 | local_4c & 0x780) >> 2) + uVar3),
             uVar2 != 0)) {
            *local_48 = (ushort)*(byte *)(((local_5c & 0xff) + local_58 >> 8 & 0xff) * 0x20 +
                                          (uint)((uVar2 & 0x7c0) >> 6) + 0x400 + DAT_10079220) << 6
                        | (ushort)*(byte *)((uint)local_66._1_1_ * 0x20 + (uVar2 & 0x1f) + 0x800 +
                                           DAT_10079220) |
                        (ushort)*(byte *)((((uint)(uVar2 >> 0xb) ^ (int)local_58 >> 0x13) & 0x1f ^
                                          (int)local_58 >> 0x13) + DAT_10079220) << 0xb;
            *puVar13 = uVar11;
          }
          local_4c = local_4c + (((uint)lVar14 & 0x3fffc) >> 2 | (int)lVar15 << 0x10);
          local_48 = local_48 + 1;
          puVar13 = puVar13 + 1;
          local_50 = local_50 + param_1[0x1b];
          local_5c = local_5c ^ local_5c >> 6;
          local_58 = local_58 + param_1[0x15];
          local_66 = local_66 + (short)param_1[0x18];
          local_64 = local_64 + 1;
        } while (local_64 < 0);
      }
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[7] = param_1[7] + param_1[8];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar7;
  param_1[1] = uVar10;
  return;
}


