// 10054b80 FUN_10054b80 [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10054b80(uint *param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  ushort uVar9;
  int iVar10;
  ushort *puVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  longlong lVar17;
  longlong lVar18;
  uint local_4c;
  uint local_40;
  int local_3c;
  uint local_2c;
  int local_24;
  int local_10;
  
  uVar2 = param_1[0xc];
  uVar8 = *param_1;
  uVar12 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar8 = uVar8 + uVar3;
    uVar12 = uVar12 + uVar4;
    uVar16 = param_1[0x1a] + param_1[0x19];
    param_1[0x19] = uVar16;
    local_4c = *(uint *)(DAT_10075224 + ((uVar8 & 0x70000) >> 0x10) * 4);
    param_1[0x70] = (uint)((float)param_1[0x70] + (float)param_1[0x71]);
    param_1[0x72] = (uint)((float)param_1[0x72] + (float)param_1[0x73]);
    param_1[0x74] = (uint)((float)param_1[0x74] + (float)param_1[0x75]);
    param_1[0x76] = (uint)((float)param_1[0x77] + (float)param_1[0x76]);
    param_1[0x78] = (uint)((float)param_1[0x78] + (float)param_1[0x79]);
    param_1[0x7a] = (uint)((float)param_1[0x7a] + (float)param_1[0x7b]);
    iVar10 = (int)uVar12 >> 0x10;
    local_4c = local_4c ^ (byte)param_1[9];
    iVar13 = ((int)uVar8 >> 0x10) - iVar10;
    if (iVar13 < 0) {
      iVar6 = param_1[5] + iVar10;
      iVar10 = param_1[7] + iVar10 * 2;
      if (iVar13 < -0x10) {
        local_24 = -iVar13 >> 4;
        lVar17 = __ftol();
        lVar18 = __ftol();
        local_40 = (uint)lVar18;
        local_3c = (int)lVar17;
        do {
          lVar17 = __ftol();
          iVar7 = (int)lVar17;
          lVar17 = __ftol();
          uVar14 = (uint)lVar17;
          local_10 = 0x10;
          local_2c = (local_40 & 0xfffc) >> 2 | local_3c << 0x10;
          puVar11 = (ushort *)(iVar10 + iVar13 * 2);
          do {
            if ((((local_4c & 0xff) < param_1[10]) &&
                (uVar9 = (ushort)(uVar16 >> 0x10), *puVar11 < uVar9)) &&
               (cVar1 = *(char *)((((local_2c & 0x1e000000) >> 0x16 | local_2c & 0x780) >> 3) +
                                 uVar2), cVar1 != '\0')) {
              *(char *)(iVar6 + iVar13) = cVar1;
              *puVar11 = uVar9;
            }
            local_2c = local_2c +
                       ((iVar7 - local_3c & 0xfffffff0U) << 0xc | (uVar14 - local_40 & 0xfffc0) >> 6
                       );
            uVar16 = uVar16 + param_1[0x1b];
            puVar11 = puVar11 + 1;
            iVar13 = iVar13 + 1;
            local_4c = local_4c ^ local_4c >> 6;
            local_10 = local_10 + -1;
          } while (local_10 != 0);
          local_24 = local_24 + -1;
          local_40 = uVar14;
          local_3c = iVar7;
        } while (0 < local_24);
        if (iVar13 < 0) {
          uVar15 = (uVar14 & 0xfffc) >> 2 | iVar7 << 0x10;
          lVar17 = __ftol();
          uVar14 = (int)(uVar14 - (int)lVar17) / iVar13;
          lVar17 = __ftol();
          iVar7 = (iVar7 - (int)lVar17) / iVar13;
          do {
            if ((((local_4c & 0xff) < param_1[10]) &&
                (uVar9 = (ushort)(uVar16 >> 0x10), *(ushort *)(iVar10 + iVar13 * 2) < uVar9)) &&
               (cVar1 = *(char *)((((uVar15 & 0x1e000000) >> 0x16 | uVar15 & 0x780) >> 3) + uVar2),
               cVar1 != '\0')) {
              *(char *)(iVar6 + iVar13) = cVar1;
              *(ushort *)(iVar10 + iVar13 * 2) = uVar9;
            }
            uVar15 = uVar15 + ((uVar14 & 0xfffc) >> 2 | iVar7 << 0x10);
            uVar16 = uVar16 + param_1[0x1b];
            local_4c = local_4c ^ local_4c >> 6;
            iVar13 = iVar13 + 1;
          } while (iVar13 < 0);
        }
      }
      else {
        lVar17 = __ftol();
        lVar18 = __ftol();
        uVar14 = ((uint)lVar17 & 0x3fffc) >> 2 | (int)lVar18 << 0x10;
        lVar17 = __ftol();
        lVar18 = __ftol();
        do {
          if ((((local_4c & 0xff) < param_1[10]) &&
              (uVar9 = (ushort)(uVar16 >> 0x10), *(ushort *)(iVar10 + iVar13 * 2) < uVar9)) &&
             (cVar1 = *(char *)((((uVar14 & 0x1e000000) >> 0x16 | uVar14 & 0x780) >> 3) + uVar2),
             cVar1 != '\0')) {
            *(char *)(iVar6 + iVar13) = cVar1;
            *(ushort *)(iVar10 + iVar13 * 2) = uVar9;
          }
          uVar14 = uVar14 + (((uint)lVar17 & 0x3fffc) >> 2 | (int)lVar18 << 0x10);
          uVar16 = uVar16 + param_1[0x1b];
          local_4c = local_4c ^ local_4c >> 6;
          iVar13 = iVar13 + 1;
        } while (iVar13 < 0);
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


