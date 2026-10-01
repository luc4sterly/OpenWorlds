// 10056d40 FUN_10056d40 [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10056d40(uint *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  int iVar9;
  uint uVar10;
  ushort uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  longlong lVar17;
  longlong lVar18;
  uint local_54;
  uint local_50;
  uint local_44;
  int local_40;
  int local_2c;
  int local_14;
  
  uVar2 = param_1[0xc];
  uVar3 = param_1[0xd];
  uVar10 = *param_1;
  uVar12 = param_1[1];
  uVar4 = param_1[3];
  uVar5 = param_1[2];
  uVar6 = param_1[4];
  while (uVar6 = uVar6 - 1, -1 < (int)uVar6) {
    uVar10 = uVar10 + uVar4;
    uVar12 = uVar12 + uVar5;
    local_50 = param_1[0x1a] + param_1[0x19];
    param_1[0x19] = local_50;
    local_54 = *(uint *)(DAT_10075224 + ((uVar10 & 0x70000) >> 0x10) * 4);
    param_1[0x70] = (uint)((float)param_1[0x70] + (float)param_1[0x71]);
    param_1[0x72] = (uint)((float)param_1[0x72] + (float)param_1[0x73]);
    param_1[0x74] = (uint)((float)param_1[0x74] + (float)param_1[0x75]);
    param_1[0x76] = (uint)((float)param_1[0x76] + (float)param_1[0x77]);
    param_1[0x78] = (uint)((float)param_1[0x78] + (float)param_1[0x79]);
    param_1[0x7a] = (uint)((float)param_1[0x7a] + (float)param_1[0x7b]);
    iVar13 = (int)uVar12 >> 0x10;
    local_54 = local_54 ^ (byte)param_1[9];
    iVar15 = ((int)uVar10 >> 0x10) - iVar13;
    if (iVar15 < 0) {
      iVar7 = param_1[5] + iVar13;
      iVar13 = param_1[7] + iVar13 * 2;
      if (iVar15 < -0x10) {
        local_2c = -iVar15 >> 4;
        lVar17 = __ftol();
        lVar18 = __ftol();
        local_44 = (uint)lVar18;
        local_40 = (int)lVar17;
        do {
          lVar17 = __ftol();
          iVar9 = (int)lVar17;
          lVar17 = __ftol();
          uVar14 = (uint)lVar17;
          uVar16 = (local_44 & 0xfffc) >> 2 | local_40 << 0x10;
          puVar8 = (ushort *)(iVar13 + iVar15 * 2);
          local_14 = 0x10;
          do {
            if ((((local_54 & 0xff) < param_1[10]) &&
                (uVar11 = (ushort)(local_50 >> 0x10), *puVar8 < uVar11)) &&
               (bVar1 = *(byte *)((((uVar16 & 0x1e000000) >> 0x16 | uVar16 & 0x780) >> 3) + uVar2),
               bVar1 != 0)) {
              *(undefined1 *)(iVar7 + iVar15) = *(undefined1 *)(bVar1 + uVar3);
              *puVar8 = uVar11;
            }
            uVar16 = uVar16 + ((iVar9 - local_40 & 0xfffffff0U) << 0xc |
                              (uVar14 - local_44 & 0xfffc0) >> 6);
            local_50 = local_50 + param_1[0x1b];
            local_54 = local_54 ^ local_54 >> 6;
            puVar8 = puVar8 + 1;
            iVar15 = iVar15 + 1;
            local_14 = local_14 + -1;
          } while (local_14 != 0);
          local_2c = local_2c + -1;
          local_44 = uVar14;
          local_40 = iVar9;
        } while (0 < local_2c);
        if (iVar15 < 0) {
          uVar16 = (uVar14 & 0xfffc) >> 2 | iVar9 << 0x10;
          lVar17 = __ftol();
          uVar14 = (int)(uVar14 - (int)lVar17) / iVar15;
          lVar17 = __ftol();
          iVar9 = (iVar9 - (int)lVar17) / iVar15;
          do {
            if ((((local_54 & 0xff) < param_1[10]) &&
                (uVar11 = (ushort)(local_50 >> 0x10), *(ushort *)(iVar13 + iVar15 * 2) < uVar11)) &&
               (bVar1 = *(byte *)((((uVar16 & 0x1e000000) >> 0x16 | uVar16 & 0x780) >> 3) + uVar2),
               bVar1 != 0)) {
              *(undefined1 *)(iVar7 + iVar15) = *(undefined1 *)(bVar1 + uVar3);
              *(ushort *)(iVar13 + iVar15 * 2) = uVar11;
            }
            uVar16 = uVar16 + ((uVar14 & 0xfffc) >> 2 | iVar9 << 0x10);
            local_50 = local_50 + param_1[0x1b];
            local_54 = local_54 ^ local_54 >> 6;
            iVar15 = iVar15 + 1;
          } while (iVar15 < 0);
        }
      }
      else {
        lVar17 = __ftol();
        lVar18 = __ftol();
        uVar14 = ((uint)lVar17 & 0x3fffc) >> 2 | (int)lVar18 << 0x10;
        lVar17 = __ftol();
        lVar18 = __ftol();
        do {
          if ((((local_54 & 0xff) < param_1[10]) &&
              (uVar11 = (ushort)(local_50 >> 0x10), *(ushort *)(iVar13 + iVar15 * 2) < uVar11)) &&
             (bVar1 = *(byte *)((((uVar14 & 0x1e000000) >> 0x16 | uVar14 & 0x780) >> 3) + uVar2),
             bVar1 != 0)) {
            *(undefined1 *)(iVar7 + iVar15) = *(undefined1 *)(bVar1 + uVar3);
            *(ushort *)(iVar13 + iVar15 * 2) = uVar11;
          }
          uVar14 = uVar14 + (((uint)lVar17 & 0x3fffc) >> 2 | (int)lVar18 << 0x10);
          local_50 = local_50 + param_1[0x1b];
          local_54 = local_54 ^ local_54 >> 6;
          iVar15 = iVar15 + 1;
        } while (iVar15 < 0);
      }
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[7] = param_1[7] + param_1[8];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar10;
  param_1[1] = uVar12;
  return;
}


