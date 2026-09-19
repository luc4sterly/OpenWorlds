// 10035e40 FUN_10035e40 [Global]
// programa: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10035e40(uint *param_1)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  ushort uVar10;
  uint uVar11;
  int iVar12;
  ushort *puVar13;
  longlong lVar14;
  longlong lVar15;
  int local_60;
  ushort *local_5c;
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
  
  uVar9 = *param_1;
  uVar3 = param_1[0xc];
  uVar11 = param_1[1];
  uVar4 = param_1[3];
  uVar5 = param_1[2];
  uVar6 = param_1[4];
  while (uVar6 = uVar6 - 1, -1 < (int)uVar6) {
    uVar9 = uVar9 + uVar4;
    uVar11 = uVar11 + uVar5;
    local_50 = param_1[0x1a] + param_1[0x19];
    param_1[0x19] = local_50;
    local_58 = *(uint *)(DAT_10079224 + ((uVar9 & 0x70000) >> 0x10) * 4);
    param_1[0x70] = (uint)((float)param_1[0x70] + (float)param_1[0x71]);
    param_1[0x72] = (uint)((float)param_1[0x73] + (float)param_1[0x72]);
    param_1[0x74] = (uint)((float)param_1[0x74] + (float)param_1[0x75]);
    param_1[0x76] = (uint)((float)param_1[0x76] + (float)param_1[0x77]);
    param_1[0x78] = (uint)((float)param_1[0x78] + (float)param_1[0x79]);
    param_1[0x7a] = (uint)((float)param_1[0x7a] + (float)param_1[0x7b]);
    iVar12 = (int)uVar11 >> 0x10;
    local_58 = local_58 ^ (byte)param_1[9];
    local_60 = ((int)uVar9 >> 0x10) - iVar12;
    if (local_60 < 0) {
      iVar1 = param_1[5] + iVar12 * 2;
      iVar12 = param_1[7] + iVar12 * 2;
      if (local_60 < -0x10) {
        local_24 = -local_60 >> 4;
        lVar14 = __ftol();
        lVar15 = __ftol();
        puVar13 = (ushort *)(iVar12 + local_60 * 2);
        local_28 = (ushort *)(local_60 * 2 + iVar1);
        local_3c = (uint)lVar15;
        local_38 = (int)lVar14;
        do {
          lVar14 = __ftol();
          iVar8 = (int)lVar14;
          lVar14 = __ftol();
          uVar7 = (uint)lVar14;
          local_54 = (local_3c & 0xfffc) >> 2 | local_38 << 0x10;
          local_60 = local_60 + 0x10;
          local_c = 0x10;
          do {
            if (((local_58 & 0xff) < param_1[10]) &&
               (uVar10 = (ushort)(local_50 >> 0x10), *puVar13 < uVar10)) {
              uVar2 = *(ushort *)
                       (((local_54 & 0x3f80) * 2 | (local_54 & 0xfeffffff) >> 0x18) + uVar3);
              if (uVar2 != 0) {
                *local_28 = (ushort)*(byte *)((uint)((uVar2 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                            (ushort)*(byte *)((uint)(uVar2 >> 0xb) + param_1[0xd]) << 0xb |
                            (ushort)*(byte *)(param_1[0xf] + (uVar2 & 0x1f));
                *puVar13 = uVar10;
              }
            }
            local_54 = local_54 +
                       ((uVar7 - local_3c & 0xfffc0) >> 6 | (iVar8 - local_38 & 0xfffffff0U) << 0xc)
            ;
            local_50 = local_50 + param_1[0x1b];
            puVar13 = puVar13 + 1;
            local_58 = local_58 ^ local_58 >> 6;
            local_28 = local_28 + 1;
            local_c = local_c + -1;
          } while (local_c != 0);
          local_24 = local_24 + -1;
          local_3c = uVar7;
          local_38 = iVar8;
        } while (0 < local_24);
        if (local_60 < 0) {
          local_54 = (uVar7 & 0xfffc) >> 2 | iVar8 << 0x10;
          lVar14 = __ftol();
          uVar7 = (int)(uVar7 - (int)lVar14) / local_60;
          lVar14 = __ftol();
          iVar8 = (iVar8 - (int)lVar14) / local_60;
          local_5c = (ushort *)(iVar1 + local_60 * 2);
          puVar13 = (ushort *)(iVar12 + local_60 * 2);
          do {
            if (((local_58 & 0xff) < param_1[10]) &&
               (uVar10 = (ushort)(local_50 >> 0x10), *puVar13 < uVar10)) {
              uVar2 = *(ushort *)
                       (((local_54 & 0x3f80) * 2 | (local_54 & 0xfeffffff) >> 0x18) + uVar3);
              if (uVar2 != 0) {
                *local_5c = (ushort)*(byte *)((uint)((uVar2 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                            (ushort)*(byte *)((uint)(uVar2 >> 0xb) + param_1[0xd]) << 0xb |
                            (ushort)*(byte *)(param_1[0xf] + (uVar2 & 0x1f));
                *puVar13 = uVar10;
              }
            }
            local_54 = local_54 + ((uVar7 & 0xfffc) >> 2 | iVar8 << 0x10);
            local_50 = local_50 + param_1[0x1b];
            puVar13 = puVar13 + 1;
            local_58 = local_58 ^ local_58 >> 6;
            local_5c = local_5c + 1;
            local_60 = local_60 + 1;
          } while (local_60 < 0);
        }
      }
      else {
        lVar14 = __ftol();
        lVar15 = __ftol();
        local_4c = ((uint)lVar14 & 0x3fffc) >> 2 | (int)lVar15 << 0x10;
        lVar14 = __ftol();
        lVar15 = __ftol();
        local_48 = (ushort *)(iVar1 + local_60 * 2);
        puVar13 = (ushort *)(iVar12 + local_60 * 2);
        do {
          if (((local_58 & 0xff) < param_1[10]) &&
             (uVar10 = (ushort)(local_50 >> 0x10), *puVar13 < uVar10)) {
            uVar2 = *(ushort *)(((local_4c & 0xfeffffff) >> 0x18 | (local_4c & 0x3f80) * 2) + uVar3)
            ;
            if (uVar2 != 0) {
              *local_48 = (ushort)*(byte *)((uint)((uVar2 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                          (ushort)*(byte *)((uint)(uVar2 >> 0xb) + param_1[0xd]) << 0xb |
                          (ushort)*(byte *)(param_1[0xf] + (uVar2 & 0x1f));
              *puVar13 = uVar10;
            }
          }
          local_4c = local_4c + (((uint)lVar14 & 0x3fffc) >> 2 | (int)lVar15 << 0x10);
          local_50 = local_50 + param_1[0x1b];
          puVar13 = puVar13 + 1;
          local_58 = local_58 ^ local_58 >> 6;
          local_48 = local_48 + 1;
          local_60 = local_60 + 1;
        } while (local_60 < 0);
      }
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[7] = param_1[7] + param_1[8];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar9;
  param_1[1] = uVar11;
  return;
}


