// 1000f3c0 FUN_1000f3c0 [Global]
// program: RWDL6D21.DLL

void FUN_1000f3c0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  ushort *puVar10;
  ushort uVar11;
  int local_28;
  uint local_24;
  ushort *local_18;
  
  iVar6 = *param_1;
  iVar8 = param_1[1];
  iVar1 = param_1[3];
  iVar2 = param_1[2];
  iVar3 = param_1[0xc];
  iVar4 = param_1[4];
  while (iVar4 = iVar4 + -1, -1 < iVar4) {
    iVar6 = iVar6 + iVar1;
    iVar8 = iVar8 + iVar2;
    local_24 = param_1[0x11] + param_1[0x10] & 0x7fff7fff;
    iVar7 = param_1[0x1a] + param_1[0x19];
    iVar9 = iVar8 >> 0x10;
    param_1[0x10] = local_24;
    local_28 = (iVar6 >> 0x10) - iVar9;
    param_1[0x19] = iVar7;
    if (local_28 < 0) {
      local_18 = (ushort *)(param_1[5] + iVar9 * 2 + local_28 * 2);
      puVar10 = (ushort *)(param_1[7] + iVar9 * 2 + local_28 * 2);
      do {
        uVar11 = (ushort)((uint)iVar7 >> 0x10);
        if ((*puVar10 < uVar11) &&
           (puVar5 = (ushort *)
                     (iVar3 + ((local_24 & 0x7f00) >> 7 | (local_24 & 0x7f000000) >> 0x10)),
           *puVar5 != 0)) {
          *puVar10 = uVar11;
          uVar11 = *puVar5;
          *local_18 = (ushort)*(byte *)((uint)((uVar11 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                      (ushort)*(byte *)((uint)(uVar11 >> 0xb) + param_1[0xd]) << 0xb |
                      (ushort)*(byte *)(param_1[0xf] + (uVar11 & 0x1f));
        }
        local_24 = param_1[0x12] + local_24 & 0x7fff7fff;
        iVar7 = iVar7 + param_1[0x1b];
        puVar10 = puVar10 + 1;
        local_18 = local_18 + 1;
        local_28 = local_28 + 1;
      } while (local_28 < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[7] = param_1[7] + param_1[8];
  }
  *param_1 = iVar6;
  param_1[1] = iVar8;
  return;
}


