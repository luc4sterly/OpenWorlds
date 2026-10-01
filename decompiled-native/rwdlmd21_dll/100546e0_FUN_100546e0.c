// 100546e0 FUN_100546e0 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100546e0(int *param_1)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  ushort uVar11;
  int iVar12;
  ushort *puVar13;
  longlong lVar14;
  longlong lVar15;
  int local_5c;
  ushort *local_58;
  uint local_54;
  int local_50;
  uint local_4c;
  ushort *local_48;
  uint local_3c;
  int local_38;
  ushort *local_28;
  int local_24;
  int local_c;
  
  iVar9 = *param_1;
  iVar3 = param_1[0xc];
  iVar12 = param_1[1];
  iVar4 = param_1[3];
  iVar5 = param_1[2];
  iVar6 = param_1[4];
  while (iVar6 = iVar6 + -1, -1 < iVar6) {
    iVar9 = iVar9 + iVar4;
    iVar12 = iVar12 + iVar5;
    param_1[0x70] = (int)((float)param_1[0x70] + (float)param_1[0x71]);
    param_1[0x72] = (int)((float)param_1[0x72] + (float)param_1[0x73]);
    param_1[0x74] = (int)((float)param_1[0x75] + (float)param_1[0x74]);
    param_1[0x76] = (int)((float)param_1[0x76] + (float)param_1[0x77]);
    param_1[0x78] = (int)((float)param_1[0x78] + (float)param_1[0x79]);
    local_50 = param_1[0x1a] + param_1[0x19];
    iVar10 = iVar12 >> 0x10;
    param_1[0x7a] = (int)((float)param_1[0x7a] + (float)param_1[0x7b]);
    param_1[0x19] = local_50;
    local_5c = (iVar9 >> 0x10) - iVar10;
    if (local_5c < 0) {
      iVar1 = param_1[5] + iVar10 * 2;
      iVar10 = param_1[7] + iVar10 * 2;
      if (local_5c < -0x10) {
        local_24 = -local_5c >> 4;
        lVar14 = __ftol();
        lVar15 = __ftol();
        puVar13 = (ushort *)(iVar10 + local_5c * 2);
        local_28 = (ushort *)(local_5c * 2 + iVar1);
        local_3c = (uint)lVar15;
        local_38 = (int)lVar14;
        do {
          lVar14 = __ftol();
          iVar8 = (int)lVar14;
          lVar14 = __ftol();
          uVar7 = (uint)lVar14;
          local_54 = (local_3c & 0xfffc) >> 2 | local_38 << 0x10;
          local_c = 0x10;
          local_5c = local_5c + 0x10;
          do {
            uVar11 = (ushort)((uint)local_50 >> 0x10);
            if (*puVar13 < uVar11) {
              uVar2 = *(ushort *)
                       ((((local_54 & 0x1e000000) >> 0x16 | local_54 & 0x780) >> 2) + iVar3);
              if (uVar2 != 0) {
                *local_28 = (ushort)*(byte *)((uint)((uVar2 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                            (ushort)*(byte *)((uint)(uVar2 >> 0xb) + param_1[0xd]) << 0xb |
                            (ushort)*(byte *)(param_1[0xf] + (uVar2 & 0x1f));
                *puVar13 = uVar11;
              }
            }
            local_54 = local_54 +
                       ((uVar7 - local_3c & 0xfffc0) >> 6 | (iVar8 - local_38 & 0xfffffff0U) << 0xc)
            ;
            local_50 = local_50 + param_1[0x1b];
            local_28 = local_28 + 1;
            puVar13 = puVar13 + 1;
            local_c = local_c + -1;
          } while (local_c != 0);
          local_24 = local_24 + -1;
          local_3c = uVar7;
          local_38 = iVar8;
        } while (0 < local_24);
        if (local_5c < 0) {
          local_54 = (uVar7 & 0xfffc) >> 2 | iVar8 << 0x10;
          lVar14 = __ftol();
          uVar7 = (int)(uVar7 - (int)lVar14) / local_5c;
          lVar14 = __ftol();
          iVar8 = (iVar8 - (int)lVar14) / local_5c;
          local_58 = (ushort *)(iVar1 + local_5c * 2);
          puVar13 = (ushort *)(iVar10 + local_5c * 2);
          do {
            uVar11 = (ushort)((uint)local_50 >> 0x10);
            if (*puVar13 < uVar11) {
              uVar2 = *(ushort *)
                       ((((local_54 & 0x1e000000) >> 0x16 | local_54 & 0x780) >> 2) + iVar3);
              if (uVar2 != 0) {
                *local_58 = (ushort)*(byte *)((uint)((uVar2 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                            (ushort)*(byte *)((uint)(uVar2 >> 0xb) + param_1[0xd]) << 0xb |
                            (ushort)*(byte *)(param_1[0xf] + (uVar2 & 0x1f));
                *puVar13 = uVar11;
              }
            }
            local_54 = local_54 + ((uVar7 & 0xfffc) >> 2 | iVar8 << 0x10);
            local_50 = local_50 + param_1[0x1b];
            local_58 = local_58 + 1;
            puVar13 = puVar13 + 1;
            local_5c = local_5c + 1;
          } while (local_5c < 0);
        }
      }
      else {
        lVar14 = __ftol();
        lVar15 = __ftol();
        local_4c = ((uint)lVar14 & 0x3fffc) >> 2 | (int)lVar15 << 0x10;
        lVar14 = __ftol();
        lVar15 = __ftol();
        local_48 = (ushort *)(iVar1 + local_5c * 2);
        puVar13 = (ushort *)(iVar10 + local_5c * 2);
        do {
          uVar11 = (ushort)((uint)local_50 >> 0x10);
          if (*puVar13 < uVar11) {
            uVar2 = *(ushort *)((((local_4c & 0x1e000000) >> 0x16 | local_4c & 0x780) >> 2) + iVar3)
            ;
            if (uVar2 != 0) {
              *local_48 = (ushort)*(byte *)((uint)((uVar2 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                          (ushort)*(byte *)((uint)(uVar2 >> 0xb) + param_1[0xd]) << 0xb |
                          (ushort)*(byte *)(param_1[0xf] + (uVar2 & 0x1f));
              *puVar13 = uVar11;
            }
          }
          local_4c = local_4c + (((uint)lVar14 & 0x3fffc) >> 2 | (int)lVar15 << 0x10);
          local_50 = local_50 + param_1[0x1b];
          local_48 = local_48 + 1;
          puVar13 = puVar13 + 1;
          local_5c = local_5c + 1;
        } while (local_5c < 0);
      }
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[7] = param_1[7] + param_1[8];
  }
  *param_1 = iVar9;
  param_1[1] = iVar12;
  return;
}


