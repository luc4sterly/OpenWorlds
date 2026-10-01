// 1001dee0 FUN_1001dee0 [Global]
// program: RWDL6D21.DLL

void FUN_1001dee0(uint *param_1)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ushort uVar8;
  uint uVar9;
  int iVar10;
  short *psVar11;
  ushort *puVar12;
  int local_28;
  uint local_20;
  uint local_1c;
  
  uVar2 = param_1[0xc];
  uVar6 = *param_1;
  uVar9 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar6 = uVar6 + uVar3;
    uVar9 = uVar9 + uVar4;
    local_1c = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    iVar10 = (int)uVar9 >> 0x10;
    uVar7 = param_1[0x1a] + param_1[0x19];
    param_1[0x10] = local_1c;
    local_28 = ((int)uVar6 >> 0x10) - iVar10;
    param_1[0x19] = uVar7;
    if (local_28 < 0) {
      local_20 = *(uint *)(DAT_10079224 + ((uVar6 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
      psVar11 = (short *)(param_1[5] + iVar10 * 2 + local_28 * 2);
      puVar12 = (ushort *)(param_1[7] + iVar10 * 2 + local_28 * 2);
      do {
        uVar8 = (ushort)(uVar7 >> 0x10);
        if (*puVar12 < uVar8) {
          sVar1 = *(short *)(((int)(short)((short)(char)local_20 ^ 0xaa) + ((int)local_1c >> 0x10) &
                              0x7f00U | ((int)(short)(char)local_20 + local_1c & 0x7f00) >> 7) +
                            uVar2);
          if (sVar1 != 0) {
            *psVar11 = sVar1;
            *puVar12 = uVar8;
          }
        }
        local_20 = local_20 ^ local_20 >> 6;
        psVar11 = psVar11 + 1;
        puVar12 = puVar12 + 1;
        local_1c = param_1[0x12] + local_1c & 0x7fff7fff;
        uVar7 = uVar7 + param_1[0x1b];
        local_28 = local_28 + 1;
      } while (local_28 < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
    param_1[7] = param_1[7] + param_1[8];
  }
  *param_1 = uVar6;
  param_1[1] = uVar9;
  return;
}


