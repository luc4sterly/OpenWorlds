// 10010d20 FUN_10010d20 [Global]
// program: RWDL8D21.DLL

void FUN_10010d20(uint *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  ushort uVar10;
  uint uVar11;
  uint uVar12;
  uint local_20;
  uint local_14;
  
  uVar7 = *param_1;
  uVar11 = param_1[1];
  uVar2 = param_1[3];
  uVar3 = param_1[2];
  uVar4 = param_1[4];
  while (uVar4 = uVar4 - 1, -1 < (int)uVar4) {
    uVar7 = uVar7 + uVar2;
    uVar11 = uVar11 + uVar3;
    uVar12 = param_1[0x1a] + param_1[0x19];
    param_1[0x19] = uVar12;
    uVar6 = param_1[0x10] + param_1[0x11];
    iVar8 = (int)uVar11 >> 0x10;
    param_1[0x10] = uVar6;
    iVar9 = ((int)uVar7 >> 0x10) - iVar8;
    if (iVar9 < 0) {
      iVar1 = param_1[7] + iVar8 * 2;
      local_20 = (uint)(byte)param_1[9];
      local_14 = *(uint *)(DAT_10075224 + ((uVar7 & 0x70000) >> 0x10) * 4) ^ local_20;
      uVar5 = param_1[5];
      do {
        if (((local_14 & 0xff) < param_1[10]) &&
           (uVar10 = (ushort)(uVar12 >> 0x10), *(ushort *)(iVar1 + iVar9 * 2) < uVar10)) {
          *(ushort *)(iVar1 + iVar9 * 2) = uVar10;
          *(undefined1 *)(iVar9 + uVar5 + iVar8) =
               *(undefined1 *)(((local_14 & 0xff) + uVar6 >> 8 & 0xff) + param_1[0xd]);
        }
        local_14 = local_14 ^ local_14 >> 6;
        uVar6 = uVar6 + param_1[0x12];
        uVar12 = uVar12 + param_1[0x1b];
        iVar9 = iVar9 + 1;
      } while (iVar9 < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[7] = param_1[7] + param_1[8];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar7;
  param_1[1] = uVar11;
  return;
}


