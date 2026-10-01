// 1005bd00 FUN_1005bd00 [Global]
// program: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1005bd00(uint *param_1)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  ushort uVar11;
  uint uVar12;
  ushort *puVar13;
  uint uVar14;
  short *psVar15;
  longlong lVar16;
  longlong lVar17;
  int local_58;
  uint local_54;
  uint local_4c;
  uint local_40;
  int local_3c;
  int local_2c;
  int local_14;
  
  uVar8 = *param_1;
  uVar3 = param_1[0xc];
  uVar12 = param_1[1];
  uVar4 = param_1[3];
  uVar5 = param_1[2];
  uVar6 = param_1[4];
  while (uVar6 = uVar6 - 1, -1 < (int)uVar6) {
    uVar8 = uVar8 + uVar4;
    uVar12 = uVar12 + uVar5;
    local_4c = param_1[0x1a] + param_1[0x19];
    param_1[0x19] = local_4c;
    local_54 = *(uint *)(DAT_10079224 + ((uVar8 & 0x70000) >> 0x10) * 4);
    param_1[0x70] = (uint)((float)param_1[0x70] + (float)param_1[0x71]);
    param_1[0x72] = (uint)((float)param_1[0x72] + (float)param_1[0x73]);
    param_1[0x74] = (uint)((float)param_1[0x74] + (float)param_1[0x75]);
    param_1[0x76] = (uint)((float)param_1[0x76] + (float)param_1[0x77]);
    param_1[0x78] = (uint)((float)param_1[0x78] + (float)param_1[0x79]);
    param_1[0x7a] = (uint)((float)param_1[0x7a] + (float)param_1[0x7b]);
    local_54 = local_54 ^ (byte)param_1[9];
    iVar9 = (int)uVar12 >> 0x10;
    local_58 = ((int)uVar8 >> 0x10) - iVar9;
    if (local_58 < 0) {
      iVar1 = param_1[5] + iVar9 * 2;
      iVar9 = param_1[7] + iVar9 * 2;
      if (local_58 < -0x10) {
        local_2c = -local_58 >> 4;
        lVar16 = __ftol();
        lVar17 = __ftol();
        puVar13 = (ushort *)(iVar9 + local_58 * 2);
        psVar15 = (short *)(iVar1 + local_58 * 2);
        local_40 = (uint)lVar17;
        local_3c = (int)lVar16;
        do {
          lVar16 = __ftol();
          iVar7 = (int)lVar16;
          lVar16 = __ftol();
          uVar14 = (uint)lVar16;
          uVar10 = (local_40 & 0xfffc) >> 2 | local_3c << 0x10;
          local_58 = local_58 + 0x10;
          local_14 = 0x10;
          do {
            if ((((local_54 & 0xff) < param_1[10]) &&
                (uVar11 = (ushort)(local_4c >> 0x10), *puVar13 < uVar11)) &&
               (sVar2 = *(short *)((((uVar10 & 0x1e000000) >> 0x16 | uVar10 & 0x780) >> 2) + uVar3),
               sVar2 != 0)) {
              *psVar15 = sVar2;
              *puVar13 = uVar11;
            }
            uVar10 = uVar10 + ((uVar14 - local_40 & 0xfffc0) >> 6 |
                              (iVar7 - local_3c & 0xfffffff0U) << 0xc);
            local_4c = local_4c + param_1[0x1b];
            local_54 = local_54 ^ local_54 >> 6;
            psVar15 = psVar15 + 1;
            puVar13 = puVar13 + 1;
            local_14 = local_14 + -1;
          } while (local_14 != 0);
          local_2c = local_2c + -1;
          local_40 = uVar14;
          local_3c = iVar7;
        } while (0 < local_2c);
        if (local_58 < 0) {
          uVar10 = (uVar14 & 0xfffc) >> 2 | iVar7 << 0x10;
          lVar16 = __ftol();
          uVar14 = (int)(uVar14 - (int)lVar16) / local_58;
          lVar16 = __ftol();
          iVar7 = (iVar7 - (int)lVar16) / local_58;
          psVar15 = (short *)(iVar1 + local_58 * 2);
          puVar13 = (ushort *)(iVar9 + local_58 * 2);
          do {
            if ((((local_54 & 0xff) < param_1[10]) &&
                (uVar11 = (ushort)(local_4c >> 0x10), *puVar13 < uVar11)) &&
               (sVar2 = *(short *)((((uVar10 & 0x1e000000) >> 0x16 | uVar10 & 0x780) >> 2) + uVar3),
               sVar2 != 0)) {
              *psVar15 = sVar2;
              *puVar13 = uVar11;
            }
            uVar10 = uVar10 + ((uVar14 & 0xfffc) >> 2 | iVar7 << 0x10);
            local_4c = local_4c + param_1[0x1b];
            local_54 = local_54 ^ local_54 >> 6;
            psVar15 = psVar15 + 1;
            puVar13 = puVar13 + 1;
            local_58 = local_58 + 1;
          } while (local_58 < 0);
        }
      }
      else {
        lVar16 = __ftol();
        lVar17 = __ftol();
        uVar14 = ((uint)lVar16 & 0x3fffc) >> 2 | (int)lVar17 << 0x10;
        lVar16 = __ftol();
        lVar17 = __ftol();
        psVar15 = (short *)(iVar1 + local_58 * 2);
        puVar13 = (ushort *)(iVar9 + local_58 * 2);
        do {
          if ((((local_54 & 0xff) < param_1[10]) &&
              (uVar11 = (ushort)(local_4c >> 0x10), *puVar13 < uVar11)) &&
             (sVar2 = *(short *)((((uVar14 & 0x1e000000) >> 0x16 | uVar14 & 0x780) >> 2) + uVar3),
             sVar2 != 0)) {
            *psVar15 = sVar2;
            *puVar13 = uVar11;
          }
          uVar14 = uVar14 + ((int)lVar16 << 0x10 | ((uint)lVar17 & 0x3fffc) >> 2);
          local_4c = local_4c + param_1[0x1b];
          local_54 = local_54 ^ local_54 >> 6;
          psVar15 = psVar15 + 1;
          puVar13 = puVar13 + 1;
          local_58 = local_58 + 1;
        } while (local_58 < 0);
      }
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[7] = param_1[7] + param_1[8];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar8;
  param_1[1] = uVar12;
  return;
}


