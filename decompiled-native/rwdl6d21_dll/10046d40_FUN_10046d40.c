// 10046d40 FUN_10046d40 [Global]
// program: RWDL6D21.DLL

void FUN_10046d40(uint *param_1)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ushort *puVar9;
  uint local_1c;
  int local_18;
  
  uVar2 = param_1[0xc];
  uVar6 = *param_1;
  uVar8 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar6 = uVar6 + uVar3;
    uVar8 = uVar8 + uVar4;
    uVar7 = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    param_1[0x10] = uVar7;
    local_1c = *(uint *)(DAT_10079224 + ((uVar6 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
    local_18 = ((int)uVar6 >> 0x10) - ((int)uVar8 >> 0x10);
    if (local_18 < 0) {
      puVar9 = (ushort *)(param_1[5] + ((int)uVar8 >> 0x10) * 2 + local_18 * 2);
      do {
        uVar1 = *(ushort *)
                 ((((int)(short)((short)(char)local_1c ^ 0xaa) + ((int)uVar7 >> 0x10) & 0xf00U |
                   ((int)(short)(char)local_1c + uVar7 & 0xf00) >> 4) >> 3) + uVar2);
        if (uVar1 != 0) {
          *puVar9 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                    (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                    (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
        }
        puVar9 = puVar9 + 1;
        local_1c = local_1c ^ local_1c >> 6;
        uVar7 = param_1[0x12] + uVar7 & 0x7fff7fff;
        local_18 = local_18 + 1;
      } while (local_18 < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar6;
  param_1[1] = uVar8;
  return;
}


