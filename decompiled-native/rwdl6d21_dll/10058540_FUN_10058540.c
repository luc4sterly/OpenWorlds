// 10058540 FUN_10058540 [Global]
// program: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10058540(uint *param_1)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  short *psVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  longlong lVar15;
  longlong lVar16;
  int local_48;
  uint local_38;
  int local_34;
  int local_24;
  
  uVar8 = *param_1;
  uVar2 = param_1[0xc];
  uVar12 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar8 = uVar8 + uVar3;
    uVar12 = uVar12 + uVar4;
    uVar13 = *(uint *)(DAT_10079224 + ((uVar8 & 0x70000) >> 0x10) * 4);
    param_1[0x70] = (uint)((float)param_1[0x70] + (float)param_1[0x71]);
    param_1[0x74] = (uint)((float)param_1[0x74] + (float)param_1[0x75]);
    param_1[0x72] = (uint)((float)param_1[0x72] + (float)param_1[0x73]);
    param_1[0x76] = (uint)((float)param_1[0x76] + (float)param_1[0x77]);
    param_1[0x78] = (uint)((float)param_1[0x78] + (float)param_1[0x79]);
    param_1[0x7a] = (uint)((float)param_1[0x7a] + (float)param_1[0x7b]);
    uVar13 = uVar13 ^ (byte)param_1[9];
    local_48 = ((int)uVar8 >> 0x10) - ((int)uVar12 >> 0x10);
    if (local_48 < 0) {
      iVar6 = ((int)uVar12 >> 0x10) * 2 + param_1[5];
      if (local_48 < -0x10) {
        local_24 = -local_48 >> 4;
        lVar15 = __ftol();
        lVar16 = __ftol();
        psVar10 = (short *)(iVar6 + local_48 * 2);
        local_38 = (uint)lVar16;
        local_34 = (int)lVar15;
        do {
          lVar15 = __ftol();
          iVar7 = (int)lVar15;
          lVar15 = __ftol();
          uVar14 = (uint)lVar15;
          uVar9 = (local_38 & 0xfffc) >> 2 | local_34 << 0x10;
          local_48 = local_48 + 0x10;
          iVar11 = 0x10;
          do {
            if (((uVar13 & 0xff) < param_1[10]) &&
               (sVar1 = *(short *)((((uVar9 & 0x1e000000) >> 0x16 | uVar9 & 0x780) >> 2) + uVar2),
               sVar1 != 0)) {
              *psVar10 = sVar1;
            }
            psVar10 = psVar10 + 1;
            uVar9 = uVar9 + ((iVar7 - local_34 & 0xfffffff0U) << 0xc |
                            (uVar14 - local_38 & 0xfffc0) >> 6);
            uVar13 = uVar13 ^ uVar13 >> 6;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
          local_24 = local_24 + -1;
          local_38 = uVar14;
          local_34 = iVar7;
        } while (0 < local_24);
        if (local_48 < 0) {
          uVar9 = (uVar14 & 0xfffc) >> 2 | iVar7 << 0x10;
          lVar15 = __ftol();
          uVar14 = (int)(uVar14 - (int)lVar15) / local_48;
          lVar15 = __ftol();
          iVar7 = (iVar7 - (int)lVar15) / local_48;
          psVar10 = (short *)(iVar6 + local_48 * 2);
          do {
            if (((uVar13 & 0xff) < param_1[10]) &&
               (sVar1 = *(short *)((((uVar9 & 0x1e000000) >> 0x16 | uVar9 & 0x780) >> 2) + uVar2),
               sVar1 != 0)) {
              *psVar10 = sVar1;
            }
            uVar9 = uVar9 + ((uVar14 & 0xfffc) >> 2 | iVar7 << 0x10);
            psVar10 = psVar10 + 1;
            uVar13 = uVar13 ^ uVar13 >> 6;
            local_48 = local_48 + 1;
          } while (local_48 < 0);
        }
      }
      else {
        lVar15 = __ftol();
        lVar16 = __ftol();
        uVar14 = ((uint)lVar15 & 0x3fffc) >> 2 | (int)lVar16 << 0x10;
        lVar15 = __ftol();
        lVar16 = __ftol();
        psVar10 = (short *)(iVar6 + local_48 * 2);
        do {
          if (((uVar13 & 0xff) < param_1[10]) &&
             (sVar1 = *(short *)((((uVar14 & 0x1e000000) >> 0x16 | uVar14 & 0x780) >> 2) + uVar2),
             sVar1 != 0)) {
            *psVar10 = sVar1;
          }
          uVar14 = uVar14 + (((uint)lVar15 & 0x3fffc) >> 2 | (int)lVar16 << 0x10);
          psVar10 = psVar10 + 1;
          uVar13 = uVar13 ^ uVar13 >> 6;
          local_48 = local_48 + 1;
        } while (local_48 < 0);
      }
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar8;
  param_1[1] = uVar12;
  return;
}


