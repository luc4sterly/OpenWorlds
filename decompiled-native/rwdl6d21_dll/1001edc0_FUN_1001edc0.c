// 1001edc0 FUN_1001edc0 [Global]
// programa: RWDL6D21.DLL

void FUN_1001edc0(uint *param_1)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  uint uVar8;
  ushort uVar9;
  int iVar10;
  int local_30;
  uint local_28;
  uint local_24;
  uint local_1c;
  ushort *local_18;
  
  uVar2 = param_1[0xc];
  uVar6 = *param_1;
  uVar8 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar6 = uVar6 + uVar3;
    uVar8 = uVar8 + uVar4;
    local_24 = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    local_1c = param_1[0x1a] + param_1[0x19];
    param_1[0x10] = local_24;
    param_1[0x19] = local_1c;
    local_28 = *(uint *)(DAT_10079224 + ((uVar6 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
    iVar10 = (int)uVar8 >> 0x10;
    local_30 = ((int)uVar6 >> 0x10) - iVar10;
    if (local_30 < 0) {
      local_18 = (ushort *)(param_1[5] + iVar10 * 2 + local_30 * 2);
      puVar7 = (ushort *)(param_1[7] + iVar10 * 2 + local_30 * 2);
      do {
        uVar9 = (ushort)(local_1c >> 0x10);
        if (*puVar7 < uVar9) {
          uVar1 = *(ushort *)
                   ((((int)(short)(char)local_28 + local_24 & 0x7f00) >> 7 |
                    (int)(short)((short)(char)local_28 ^ 0xaa) + ((int)local_24 >> 0x10) & 0x7f00U)
                   + uVar2);
          if (uVar1 != 0) {
            *local_18 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                        (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                        (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
            *puVar7 = uVar9;
          }
        }
        local_28 = local_28 ^ local_28 >> 6;
        local_18 = local_18 + 1;
        local_24 = param_1[0x12] + local_24 & 0x7fff7fff;
        puVar7 = puVar7 + 1;
        local_1c = local_1c + param_1[0x1b];
        local_30 = local_30 + 1;
      } while (local_30 < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
    param_1[7] = param_1[7] + param_1[8];
  }
  *param_1 = uVar6;
  param_1[1] = uVar8;
  return;
}


