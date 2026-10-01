// 1003f430 FUN_1003f430 [Global]
// program: RWDL6D21.DLL

void FUN_1003f430(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  ushort *puVar10;
  ushort uVar11;
  int local_2c;
  uint local_24;
  uint local_20;
  ushort *local_18;
  
  uVar6 = *param_1;
  uVar8 = param_1[1];
  uVar1 = param_1[3];
  uVar2 = param_1[2];
  uVar3 = param_1[0xc];
  uVar4 = param_1[4];
  while (uVar4 = uVar4 - 1, -1 < (int)uVar4) {
    uVar6 = uVar6 + uVar1;
    uVar8 = uVar8 + uVar2;
    local_24 = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    uVar7 = param_1[0x19] + param_1[0x1a];
    param_1[0x10] = local_24;
    param_1[0x19] = uVar7;
    local_20 = *(uint *)(DAT_10079224 + ((uVar6 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
    iVar9 = (int)uVar8 >> 0x10;
    local_2c = ((int)uVar6 >> 0x10) - iVar9;
    if (local_2c < 0) {
      local_18 = (ushort *)(param_1[5] + iVar9 * 2 + local_2c * 2);
      puVar10 = (ushort *)(param_1[7] + iVar9 * 2 + local_2c * 2);
      do {
        if ((((local_20 & 0xff) < param_1[10]) &&
            (uVar11 = (ushort)(uVar7 >> 0x10), *puVar10 < uVar11)) &&
           (puVar5 = (ushort *)(uVar3 + ((local_24 & 0xf00) >> 7 | (local_24 & 0xf000000) >> 0x13)),
           *puVar5 != 0)) {
          *puVar10 = uVar11;
          uVar11 = *puVar5;
          *local_18 = (ushort)*(byte *)((uint)((uVar11 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                      (ushort)*(byte *)((uint)(uVar11 >> 0xb) + param_1[0xd]) << 0xb |
                      (ushort)*(byte *)(param_1[0xf] + (uVar11 & 0x1f));
        }
        local_24 = param_1[0x12] + local_24 & 0x7fff7fff;
        uVar7 = uVar7 + param_1[0x1b];
        puVar10 = puVar10 + 1;
        local_20 = local_20 ^ local_20 >> 6;
        local_18 = local_18 + 1;
        local_2c = local_2c + 1;
      } while (local_2c < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[7] = param_1[7] + param_1[8];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar6;
  param_1[1] = uVar8;
  return;
}


