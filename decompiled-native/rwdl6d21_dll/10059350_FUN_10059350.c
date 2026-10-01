// 10059350 FUN_10059350 [Global]
// program: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10059350(uint *param_1)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  ushort *puVar10;
  uint uVar11;
  uint uVar12;
  longlong lVar13;
  longlong lVar14;
  int local_50;
  uint local_4c;
  uint local_3c;
  int local_38;
  int local_28;
  int local_14;
  
  uVar8 = *param_1;
  uVar2 = param_1[0xc];
  uVar11 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar8 = uVar8 + uVar3;
    uVar11 = uVar11 + uVar4;
    local_4c = *(uint *)(DAT_10079224 + ((uVar8 & 0x70000) >> 0x10) * 4);
    param_1[0x70] = (uint)((float)param_1[0x70] + (float)param_1[0x71]);
    param_1[0x72] = (uint)((float)param_1[0x72] + (float)param_1[0x73]);
    param_1[0x74] = (uint)((float)param_1[0x74] + (float)param_1[0x75]);
    param_1[0x76] = (uint)((float)param_1[0x76] + (float)param_1[0x77]);
    param_1[0x78] = (uint)((float)param_1[0x78] + (float)param_1[0x79]);
    param_1[0x7a] = (uint)((float)param_1[0x7a] + (float)param_1[0x7b]);
    local_4c = local_4c ^ (byte)param_1[9];
    local_50 = ((int)uVar8 >> 0x10) - ((int)uVar11 >> 0x10);
    if (local_50 < 0) {
      iVar6 = ((int)uVar11 >> 0x10) * 2 + param_1[5];
      if (local_50 < -0x10) {
        local_28 = -local_50 >> 4;
        lVar13 = __ftol();
        lVar14 = __ftol();
        puVar10 = (ushort *)(iVar6 + local_50 * 2);
        local_3c = (uint)lVar14;
        local_38 = (int)lVar13;
        do {
          lVar13 = __ftol();
          iVar7 = (int)lVar13;
          lVar13 = __ftol();
          uVar12 = (uint)lVar13;
          uVar9 = (local_3c & 0xfffc) >> 2 | local_38 << 0x10;
          local_14 = 0x10;
          local_50 = local_50 + 0x10;
          do {
            if ((local_4c & 0xff) < param_1[10]) {
              uVar1 = *(ushort *)((((uVar9 & 0x1e000000) >> 0x16 | uVar9 & 0x780) >> 2) + uVar2);
              if (uVar1 != 0) {
                *puVar10 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                           (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                           (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
              }
            }
            uVar9 = uVar9 + ((uVar12 - local_3c & 0xfffc0) >> 6 |
                            (iVar7 - local_38 & 0xfffffff0U) << 0xc);
            puVar10 = puVar10 + 1;
            local_4c = local_4c ^ local_4c >> 6;
            local_14 = local_14 + -1;
          } while (local_14 != 0);
          local_28 = local_28 + -1;
          local_3c = uVar12;
          local_38 = iVar7;
        } while (0 < local_28);
        if (local_50 < 0) {
          uVar9 = (uVar12 & 0xfffc) >> 2 | iVar7 << 0x10;
          lVar13 = __ftol();
          uVar12 = (int)(uVar12 - (int)lVar13) / local_50;
          lVar13 = __ftol();
          iVar7 = (iVar7 - (int)lVar13) / local_50;
          puVar10 = (ushort *)(iVar6 + local_50 * 2);
          do {
            if ((local_4c & 0xff) < param_1[10]) {
              uVar1 = *(ushort *)((((uVar9 & 0x1e000000) >> 0x16 | uVar9 & 0x780) >> 2) + uVar2);
              if (uVar1 != 0) {
                *puVar10 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                           (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                           (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
              }
            }
            uVar9 = uVar9 + ((uVar12 & 0xfffc) >> 2 | iVar7 << 0x10);
            puVar10 = puVar10 + 1;
            local_4c = local_4c ^ local_4c >> 6;
            local_50 = local_50 + 1;
          } while (local_50 < 0);
        }
      }
      else {
        lVar13 = __ftol();
        lVar14 = __ftol();
        uVar12 = ((uint)lVar13 & 0x3fffc) >> 2 | (int)lVar14 << 0x10;
        lVar13 = __ftol();
        lVar14 = __ftol();
        puVar10 = (ushort *)(iVar6 + local_50 * 2);
        do {
          if ((local_4c & 0xff) < param_1[10]) {
            uVar1 = *(ushort *)((((uVar12 & 0x1e000000) >> 0x16 | uVar12 & 0x780) >> 2) + uVar2);
            if (uVar1 != 0) {
              *puVar10 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                         (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                         (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
            }
          }
          uVar12 = uVar12 + (((uint)lVar13 & 0x3fffc) >> 2 | (int)lVar14 << 0x10);
          puVar10 = puVar10 + 1;
          local_4c = local_4c ^ local_4c >> 6;
          local_50 = local_50 + 1;
        } while (local_50 < 0);
      }
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar8;
  param_1[1] = uVar11;
  return;
}


