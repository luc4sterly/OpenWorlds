// 100580b0 FUN_100580b0 [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100580b0(uint *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  longlong lVar15;
  longlong lVar16;
  uint local_48;
  uint local_3c;
  int local_38;
  int local_28;
  int local_10;
  
  iVar6 = DAT_10075220;
  uVar2 = param_1[0xc];
  uVar8 = *param_1;
  uVar11 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar8 = uVar8 + uVar3;
    uVar11 = uVar11 + uVar4;
    param_1[0x70] = (uint)((float)param_1[0x70] + (float)param_1[0x71]);
    param_1[0x72] = (uint)((float)param_1[0x72] + (float)param_1[0x73]);
    param_1[0x74] = (uint)((float)param_1[0x74] + (float)param_1[0x75]);
    param_1[0x76] = (uint)((float)param_1[0x76] + (float)param_1[0x77]);
    param_1[0x78] = (uint)((float)param_1[0x78] + (float)param_1[0x79]);
    param_1[0x7a] = (uint)((float)param_1[0x7a] + (float)param_1[0x7b]);
    uVar14 = param_1[0x13] + param_1[0x14];
    param_1[0x13] = uVar14;
    iVar12 = ((int)uVar8 >> 0x10) - ((int)uVar11 >> 0x10);
    if (iVar12 < 0) {
      iVar9 = param_1[5] + ((int)uVar11 >> 0x10);
      local_48 = *(uint *)(DAT_10075224 + ((uVar8 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
      if (iVar12 < -0x10) {
        local_28 = -iVar12 >> 4;
        lVar15 = __ftol();
        lVar16 = __ftol();
        local_3c = (uint)lVar16;
        local_38 = (int)lVar15;
        do {
          lVar15 = __ftol();
          iVar7 = (int)lVar15;
          lVar15 = __ftol();
          uVar13 = (uint)lVar15;
          local_10 = 0x10;
          uVar10 = (local_3c & 0xfffc) >> 2 | local_38 << 0x10;
          do {
            if (((local_48 & 0xff) < param_1[10]) &&
               (bVar1 = *(byte *)((((uVar10 & 0x1e000000) >> 0x16 | uVar10 & 0x780) >> 3) + uVar2),
               bVar1 != 0)) {
              *(undefined1 *)(iVar9 + iVar12) =
                   *(undefined1 *)(((local_48 & 0xff) + uVar14 & 0xff00) + (uint)bVar1 + iVar6);
            }
            uVar10 = uVar10 + ((iVar7 - local_38 & 0xfffffff0U) << 0xc |
                              (uVar13 - local_3c & 0xfffc0) >> 6);
            uVar14 = uVar14 + param_1[0x15];
            iVar12 = iVar12 + 1;
            local_48 = local_48 ^ local_48 >> 6;
            local_10 = local_10 + -1;
          } while (local_10 != 0);
          local_28 = local_28 + -1;
          local_3c = uVar13;
          local_38 = iVar7;
        } while (0 < local_28);
        if (iVar12 < 0) {
          uVar10 = (uVar13 & 0xfffc) >> 2 | iVar7 << 0x10;
          lVar15 = __ftol();
          uVar13 = (int)(uVar13 - (int)lVar15) / iVar12;
          lVar15 = __ftol();
          iVar7 = (iVar7 - (int)lVar15) / iVar12;
          do {
            if (((local_48 & 0xff) < param_1[10]) &&
               (bVar1 = *(byte *)((((uVar10 & 0x1e000000) >> 0x16 | uVar10 & 0x780) >> 3) + uVar2),
               bVar1 != 0)) {
              *(undefined1 *)(iVar9 + iVar12) =
                   *(undefined1 *)(((local_48 & 0xff) + uVar14 & 0xff00) + (uint)bVar1 + iVar6);
            }
            uVar10 = uVar10 + ((uVar13 & 0xfffc) >> 2 | iVar7 << 0x10);
            uVar14 = uVar14 + param_1[0x15];
            local_48 = local_48 ^ local_48 >> 6;
            iVar12 = iVar12 + 1;
          } while (iVar12 < 0);
        }
      }
      else {
        lVar15 = __ftol();
        lVar16 = __ftol();
        uVar13 = ((uint)lVar15 & 0x3fffc) >> 2 | (int)lVar16 << 0x10;
        lVar15 = __ftol();
        lVar16 = __ftol();
        do {
          if (((local_48 & 0xff) < param_1[10]) &&
             (bVar1 = *(byte *)((((uVar13 & 0x1e000000) >> 0x16 | uVar13 & 0x780) >> 3) + uVar2),
             bVar1 != 0)) {
            *(undefined1 *)(iVar9 + iVar12) =
                 *(undefined1 *)(((local_48 & 0xff) + uVar14 & 0xff00) + (uint)bVar1 + iVar6);
          }
          uVar13 = uVar13 + (((uint)lVar15 & 0x3fffc) >> 2 | (int)lVar16 << 0x10);
          uVar14 = uVar14 + param_1[0x15];
          local_48 = local_48 ^ local_48 >> 6;
          iVar12 = iVar12 + 1;
        } while (iVar12 < 0);
      }
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar8;
  param_1[1] = uVar11;
  return;
}


