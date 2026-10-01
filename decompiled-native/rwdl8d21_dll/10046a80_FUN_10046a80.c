// 10046a80 FUN_10046a80 [Global]
// program: RWDL8D21.DLL

void FUN_10046a80(uint *param_1)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  ushort uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint local_28;
  uint local_24;
  
  uVar3 = param_1[0xc];
  uVar4 = param_1[0xd];
  uVar10 = *param_1;
  uVar12 = param_1[1];
  uVar5 = param_1[3];
  uVar6 = param_1[2];
  uVar7 = param_1[4];
  while (uVar7 = uVar7 - 1, -1 < (int)uVar7) {
    uVar10 = uVar10 + uVar5;
    uVar12 = uVar12 + uVar6;
    local_24 = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    uVar13 = param_1[0x1a] + param_1[0x19];
    param_1[0x10] = local_24;
    param_1[0x19] = uVar13;
    iVar14 = (int)uVar12 >> 0x10;
    local_28 = *(uint *)(DAT_10075224 + ((uVar10 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
    iVar9 = ((int)uVar10 >> 0x10) - iVar14;
    if (iVar9 < 0) {
      uVar8 = param_1[5];
      iVar1 = param_1[7] + iVar14 * 2;
      do {
        uVar11 = (ushort)(uVar13 >> 0x10);
        if (*(ushort *)(iVar1 + iVar9 * 2) < uVar11) {
          bVar2 = *(byte *)((((int)(short)((short)(char)local_28 ^ 0xaa) + ((int)local_24 >> 0x10) &
                              0xf00U | ((int)(short)(char)local_28 + local_24 & 0xf00) >> 4) >> 4) +
                           uVar3);
          if (bVar2 != 0) {
            *(ushort *)(iVar1 + iVar9 * 2) = uVar11;
            *(undefined1 *)(uVar8 + iVar14 + iVar9) = *(undefined1 *)(bVar2 + uVar4);
          }
        }
        local_28 = local_28 ^ local_28 >> 6;
        local_24 = param_1[0x12] + local_24 & 0x7fff7fff;
        uVar13 = uVar13 + param_1[0x1b];
        iVar9 = iVar9 + 1;
      } while (iVar9 < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
    param_1[7] = param_1[7] + param_1[8];
  }
  *param_1 = uVar10;
  param_1[1] = uVar12;
  return;
}


