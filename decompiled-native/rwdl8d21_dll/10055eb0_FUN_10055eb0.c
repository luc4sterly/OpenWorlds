// 10055eb0 FUN_10055eb0 [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10055eb0(uint *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  longlong lVar15;
  longlong lVar16;
  uint local_48;
  int local_3c;
  uint local_30;
  int local_2c;
  int local_1c;
  
  uVar2 = param_1[0xd];
  uVar3 = param_1[0xc];
  uVar9 = *param_1;
  uVar11 = param_1[1];
  uVar4 = param_1[3];
  uVar5 = param_1[2];
  uVar6 = param_1[4];
  while (uVar6 = uVar6 - 1, -1 < (int)uVar6) {
    uVar9 = uVar9 + uVar4;
    uVar11 = uVar11 + uVar5;
    uVar12 = *(uint *)(DAT_10075224 + ((uVar9 & 0x70000) >> 0x10) * 4);
    param_1[0x70] = (uint)((float)param_1[0x70] + (float)param_1[0x71]);
    param_1[0x74] = (uint)((float)param_1[0x74] + (float)param_1[0x75]);
    param_1[0x72] = (uint)((float)param_1[0x72] + (float)param_1[0x73]);
    param_1[0x76] = (uint)((float)param_1[0x76] + (float)param_1[0x77]);
    param_1[0x78] = (uint)((float)param_1[0x78] + (float)param_1[0x79]);
    param_1[0x7a] = (uint)((float)param_1[0x7a] + (float)param_1[0x7b]);
    uVar12 = uVar12 ^ (byte)param_1[9];
    iVar14 = ((int)uVar9 >> 0x10) - ((int)uVar11 >> 0x10);
    if (iVar14 < 0) {
      iVar13 = param_1[5] + ((int)uVar11 >> 0x10);
      if (iVar14 < -0x10) {
        lVar15 = __ftol();
        lVar16 = __ftol();
        local_1c = -iVar14 >> 4;
        local_30 = (uint)lVar16;
        local_2c = (int)lVar15;
        do {
          lVar15 = __ftol();
          iVar8 = (int)lVar15;
          lVar15 = __ftol();
          uVar7 = (uint)lVar15;
          uVar10 = (local_30 & 0xfffc) >> 2 | local_2c << 0x10;
          local_3c = 0x10;
          do {
            if (((uVar12 & 0xff) < param_1[10]) &&
               (bVar1 = *(byte *)((((uVar10 & 0x1e000000) >> 0x16 | uVar10 & 0x780) >> 3) + uVar3),
               bVar1 != 0)) {
              *(undefined1 *)(iVar13 + iVar14) = *(undefined1 *)(bVar1 + uVar2);
            }
            iVar14 = iVar14 + 1;
            uVar10 = uVar10 + ((uVar7 - local_30 & 0xfffc0) >> 6 |
                              (iVar8 - local_2c & 0xfffffff0U) << 0xc);
            uVar12 = uVar12 ^ uVar12 >> 6;
            local_3c = local_3c + -1;
          } while (local_3c != 0);
          local_1c = local_1c + -1;
          local_30 = uVar7;
          local_2c = iVar8;
        } while (0 < local_1c);
        if (iVar14 < 0) {
          local_48 = (uVar7 & 0xfffc) >> 2 | iVar8 << 0x10;
          lVar15 = __ftol();
          uVar7 = (int)(uVar7 - (int)lVar15) / iVar14;
          lVar15 = __ftol();
          iVar8 = (iVar8 - (int)lVar15) / iVar14;
          do {
            if (((uVar12 & 0xff) < param_1[10]) &&
               (bVar1 = *(byte *)((((local_48 & 0x1e000000) >> 0x16 | local_48 & 0x780) >> 3) +
                                 uVar3), bVar1 != 0)) {
              *(undefined1 *)(iVar13 + iVar14) = *(undefined1 *)(bVar1 + uVar2);
            }
            local_48 = local_48 + ((uVar7 & 0xfffc) >> 2 | iVar8 << 0x10);
            uVar12 = uVar12 ^ uVar12 >> 6;
            iVar14 = iVar14 + 1;
          } while (iVar14 < 0);
        }
      }
      else {
        lVar15 = __ftol();
        lVar16 = __ftol();
        local_48 = ((uint)lVar15 & 0x3fffc) >> 2 | (int)lVar16 << 0x10;
        lVar15 = __ftol();
        lVar16 = __ftol();
        do {
          if (((uVar12 & 0xff) < param_1[10]) &&
             (bVar1 = *(byte *)((((local_48 & 0x1e000000) >> 0x16 | local_48 & 0x780) >> 3) + uVar3)
             , bVar1 != 0)) {
            *(undefined1 *)(iVar13 + iVar14) = *(undefined1 *)(bVar1 + uVar2);
          }
          local_48 = local_48 + (((uint)lVar15 & 0x3fffc) >> 2 | (int)lVar16 << 0x10);
          uVar12 = uVar12 ^ uVar12 >> 6;
          iVar14 = iVar14 + 1;
        } while (iVar14 < 0);
      }
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar9;
  param_1[1] = uVar11;
  return;
}


