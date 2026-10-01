// 10025390 FUN_10025390 [Global]
// program: RWDL8D21.DLL

void FUN_10025390(uint *param_1)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  ushort uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint local_24;
  
  uVar3 = param_1[0xd];
  uVar10 = *param_1;
  uVar13 = param_1[1];
  uVar4 = param_1[0xc];
  uVar5 = param_1[3];
  uVar6 = param_1[2];
  uVar7 = param_1[4];
  while (uVar7 = uVar7 - 1, -1 < (int)uVar7) {
    uVar10 = uVar10 + uVar5;
    uVar13 = uVar13 + uVar6;
    uVar11 = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    uVar9 = param_1[0x1a] + param_1[0x19];
    param_1[0x10] = uVar11;
    param_1[0x19] = uVar9;
    iVar15 = (int)uVar13 >> 0x10;
    local_24 = *(uint *)(DAT_10075224 + ((uVar10 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
    iVar14 = ((int)uVar10 >> 0x10) - iVar15;
    if (iVar14 < 0) {
      uVar8 = param_1[5];
      iVar1 = param_1[7] + iVar15 * 2;
      do {
        uVar12 = (ushort)(uVar9 >> 0x10);
        if (*(ushort *)(iVar1 + iVar14 * 2) < uVar12) {
          bVar2 = *(byte *)(((((int)(short)(char)local_24 + uVar11 & 0x7f00) >> 7 |
                             (int)(short)((short)(char)local_24 ^ 0xaa) + ((int)uVar11 >> 0x10) &
                             0x7f00U) >> 1) + uVar4);
          if (bVar2 != 0) {
            *(ushort *)(iVar1 + iVar14 * 2) = uVar12;
            *(undefined1 *)(uVar8 + iVar15 + iVar14) = *(undefined1 *)(bVar2 + uVar3);
          }
        }
        local_24 = local_24 ^ local_24 >> 6;
        uVar9 = uVar9 + param_1[0x1b];
        uVar11 = param_1[0x12] + uVar11 & 0x7fff7fff;
        iVar14 = iVar14 + 1;
      } while (iVar14 < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
    param_1[7] = param_1[7] + param_1[8];
  }
  *param_1 = uVar10;
  param_1[1] = uVar13;
  return;
}


