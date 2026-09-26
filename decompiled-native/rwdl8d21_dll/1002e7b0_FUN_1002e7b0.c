// 1002e7b0 FUN_1002e7b0 [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1002e7b0(uint *param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  longlong lVar15;
  longlong lVar16;
  uint local_40;
  int local_3c;
  uint local_30;
  int local_2c;
  
  uVar8 = *param_1;
  uVar2 = param_1[0xc];
  uVar12 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar8 = uVar8 + uVar3;
    uVar12 = uVar12 + uVar4;
    uVar13 = *(uint *)(DAT_10075224 + ((uVar8 & 0x70000) >> 0x10) * 4);
    param_1[0x70] = (uint)((float)param_1[0x70] + (float)param_1[0x71]);
    param_1[0x74] = (uint)((float)param_1[0x74] + (float)param_1[0x75]);
    param_1[0x72] = (uint)((float)param_1[0x72] + (float)param_1[0x73]);
    param_1[0x76] = (uint)((float)param_1[0x76] + (float)param_1[0x77]);
    param_1[0x78] = (uint)((float)param_1[0x78] + (float)param_1[0x79]);
    param_1[0x7a] = (uint)((float)param_1[0x7a] + (float)param_1[0x7b]);
    uVar13 = uVar13 ^ (byte)param_1[9];
    iVar14 = ((int)uVar8 >> 0x10) - ((int)uVar12 >> 0x10);
    if (iVar14 < 0) {
      iVar10 = param_1[5] + ((int)uVar12 >> 0x10);
      if (iVar14 < -0x10) {
        lVar15 = __ftol();
        lVar16 = __ftol();
        local_3c = -iVar14 >> 4;
        local_30 = (uint)lVar16;
        local_2c = (int)lVar15;
        do {
          lVar15 = __ftol();
          iVar7 = (int)lVar15;
          lVar15 = __ftol();
          uVar6 = (uint)lVar15;
          uVar9 = (local_30 & 0xfffc) >> 2 | local_2c << 0x10;
          iVar11 = 0x10;
          do {
            if (((uVar13 & 0xff) < param_1[10]) &&
               (cVar1 = *(char *)((uVar9 >> 0x19 | uVar9 & 0x3f80) + uVar2), cVar1 != '\0')) {
              *(char *)(iVar10 + iVar14) = cVar1;
            }
            iVar14 = iVar14 + 1;
            uVar9 = uVar9 + ((uVar6 - local_30 & 0xfffc0) >> 6 |
                            (iVar7 - local_2c & 0xfffffff0U) << 0xc);
            uVar13 = uVar13 ^ uVar13 >> 6;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
          local_3c = local_3c + -1;
          local_30 = uVar6;
          local_2c = iVar7;
        } while (0 < local_3c);
        if (iVar14 < 0) {
          local_40 = (uVar6 & 0xfffc) >> 2 | iVar7 << 0x10;
          lVar15 = __ftol();
          uVar6 = (int)(uVar6 - (int)lVar15) / iVar14;
          lVar15 = __ftol();
          iVar7 = (iVar7 - (int)lVar15) / iVar14;
          do {
            if (((uVar13 & 0xff) < param_1[10]) &&
               (cVar1 = *(char *)((local_40 >> 0x19 | local_40 & 0x3f80) + uVar2), cVar1 != '\0')) {
              *(char *)(iVar10 + iVar14) = cVar1;
            }
            local_40 = local_40 + ((uVar6 & 0xfffc) >> 2 | iVar7 << 0x10);
            uVar13 = uVar13 ^ uVar13 >> 6;
            iVar14 = iVar14 + 1;
          } while (iVar14 < 0);
        }
      }
      else {
        lVar15 = __ftol();
        lVar16 = __ftol();
        local_40 = ((uint)lVar15 & 0x3fffc) >> 2 | (int)lVar16 << 0x10;
        lVar15 = __ftol();
        lVar16 = __ftol();
        do {
          if (((uVar13 & 0xff) < param_1[10]) &&
             (cVar1 = *(char *)((local_40 >> 0x19 | local_40 & 0x3f80) + uVar2), cVar1 != '\0')) {
            *(char *)(iVar10 + iVar14) = cVar1;
          }
          local_40 = local_40 + (((uint)lVar15 & 0x3fffc) >> 2 | (int)lVar16 << 0x10);
          uVar13 = uVar13 ^ uVar13 >> 6;
          iVar14 = iVar14 + 1;
        } while (iVar14 < 0);
      }
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar8;
  param_1[1] = uVar12;
  return;
}


