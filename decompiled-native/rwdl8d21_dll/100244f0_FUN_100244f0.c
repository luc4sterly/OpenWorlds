// 100244f0 FUN_100244f0 [Global]
// program: RWDL8D21.DLL

void FUN_100244f0(uint *param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  ushort uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint local_24;
  
  uVar8 = *param_1;
  uVar11 = param_1[1];
  uVar2 = param_1[0xc];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar8 = uVar8 + uVar3;
    uVar11 = uVar11 + uVar4;
    uVar7 = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    iVar12 = (int)uVar11 >> 0x10;
    uVar14 = param_1[0x1a] + param_1[0x19];
    param_1[0x10] = uVar7;
    param_1[0x19] = uVar14;
    iVar9 = ((int)uVar8 >> 0x10) - iVar12;
    if (iVar9 < 0) {
      local_24 = *(uint *)(DAT_10075224 + ((uVar8 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
      uVar6 = param_1[5];
      iVar13 = iVar12 * 2 + param_1[7];
      do {
        uVar10 = (ushort)(uVar14 >> 0x10);
        if (*(ushort *)(iVar13 + iVar9 * 2) < uVar10) {
          cVar1 = *(char *)((((int)(short)((short)(char)local_24 ^ 0xaa) + ((int)uVar7 >> 0x10) &
                              0x7f00U | ((int)(short)(char)local_24 + uVar7 & 0x7f00) >> 7) >> 1) +
                           uVar2);
          if (cVar1 != '\0') {
            *(ushort *)(iVar13 + iVar9 * 2) = uVar10;
            *(char *)(uVar6 + iVar12 + iVar9) = cVar1;
          }
        }
        local_24 = local_24 ^ local_24 >> 6;
        uVar14 = uVar14 + param_1[0x1b];
        uVar7 = param_1[0x12] + uVar7 & 0x7fff7fff;
        iVar9 = iVar9 + 1;
      } while (iVar9 < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
    param_1[7] = param_1[7] + param_1[8];
  }
  *param_1 = uVar8;
  param_1[1] = uVar11;
  return;
}


