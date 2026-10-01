// 10053800 FUN_10053800 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10053800(int *param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  ushort *puVar10;
  int iVar11;
  uint uVar12;
  longlong lVar13;
  longlong lVar14;
  int local_4c;
  uint local_3c;
  int local_38;
  int local_28;
  int local_14;
  
  iVar8 = *param_1;
  iVar2 = param_1[0xc];
  iVar11 = param_1[1];
  iVar3 = param_1[3];
  iVar4 = param_1[2];
  iVar5 = param_1[4];
  while (iVar5 = iVar5 + -1, -1 < iVar5) {
    iVar8 = iVar8 + iVar3;
    param_1[0x70] = (int)((float)param_1[0x70] + (float)param_1[0x71]);
    param_1[0x72] = (int)((float)param_1[0x72] + (float)param_1[0x73]);
    param_1[0x74] = (int)((float)param_1[0x74] + (float)param_1[0x75]);
    param_1[0x76] = (int)((float)param_1[0x76] + (float)param_1[0x77]);
    param_1[0x78] = (int)((float)param_1[0x78] + (float)param_1[0x79]);
    iVar11 = iVar11 + iVar4;
    param_1[0x7a] = (int)((float)param_1[0x7a] + (float)param_1[0x7b]);
    local_4c = (iVar8 >> 0x10) - (iVar11 >> 0x10);
    if (local_4c < 0) {
      iVar6 = (iVar11 >> 0x10) * 2 + param_1[5];
      if (local_4c < -0x10) {
        local_28 = -local_4c >> 4;
        lVar13 = __ftol();
        lVar14 = __ftol();
        puVar10 = (ushort *)(iVar6 + local_4c * 2);
        local_3c = (uint)lVar14;
        local_38 = (int)lVar13;
        do {
          lVar13 = __ftol();
          iVar7 = (int)lVar13;
          lVar13 = __ftol();
          uVar12 = (uint)lVar13;
          uVar9 = (local_3c & 0xfffc) >> 2 | local_38 << 0x10;
          local_14 = 0x10;
          local_4c = local_4c + 0x10;
          do {
            uVar1 = *(ushort *)((((uVar9 & 0x1e000000) >> 0x16 | uVar9 & 0x780) >> 2) + iVar2);
            if (uVar1 != 0) {
              *puVar10 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                         (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                         (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
            }
            puVar10 = puVar10 + 1;
            uVar9 = uVar9 + ((uVar12 - local_3c & 0xfffc0) >> 6 |
                            (iVar7 - local_38 & 0xfffffff0U) << 0xc);
            local_14 = local_14 + -1;
          } while (local_14 != 0);
          local_28 = local_28 + -1;
          local_3c = uVar12;
          local_38 = iVar7;
        } while (0 < local_28);
        if (local_4c < 0) {
          uVar9 = (uVar12 & 0xfffc) >> 2 | iVar7 << 0x10;
          lVar13 = __ftol();
          uVar12 = (int)(uVar12 - (int)lVar13) / local_4c;
          lVar13 = __ftol();
          iVar7 = (iVar7 - (int)lVar13) / local_4c;
          puVar10 = (ushort *)(iVar6 + local_4c * 2);
          do {
            uVar1 = *(ushort *)((((uVar9 & 0x1e000000) >> 0x16 | uVar9 & 0x780) >> 2) + iVar2);
            if (uVar1 != 0) {
              *puVar10 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                         (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                         (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
            }
            puVar10 = puVar10 + 1;
            uVar9 = uVar9 + ((uVar12 & 0xfffc) >> 2 | iVar7 << 0x10);
            local_4c = local_4c + 1;
          } while (local_4c < 0);
        }
      }
      else {
        lVar13 = __ftol();
        lVar14 = __ftol();
        uVar12 = ((uint)lVar13 & 0x3fffc) >> 2 | (int)lVar14 << 0x10;
        lVar13 = __ftol();
        lVar14 = __ftol();
        puVar10 = (ushort *)(iVar6 + local_4c * 2);
        do {
          uVar1 = *(ushort *)((((uVar12 & 0x1e000000) >> 0x16 | uVar12 & 0x780) >> 2) + iVar2);
          if (uVar1 != 0) {
            *puVar10 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                       (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                       (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
          }
          puVar10 = puVar10 + 1;
          uVar12 = uVar12 + (((uint)lVar13 & 0x3fffc) >> 2 | (int)lVar14 << 0x10);
          local_4c = local_4c + 1;
        } while (local_4c < 0);
      }
    }
    param_1[5] = param_1[5] + param_1[6];
  }
  *param_1 = iVar8;
  param_1[1] = iVar11;
  return;
}


