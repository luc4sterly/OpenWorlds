// 1000dd00 FUN_1000dd00 [Global]
// program: RWDL8D21.DLL

void FUN_1000dd00(uint *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  ushort uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  
  uVar9 = *param_1;
  uVar11 = param_1[1];
  uVar2 = param_1[3];
  uVar3 = param_1[2];
  uVar6 = param_1[0xb];
  uVar4 = param_1[4];
  while (uVar4 = uVar4 - 1, -1 < (int)uVar4) {
    uVar9 = uVar9 + uVar2;
    uVar11 = uVar11 + uVar3;
    uVar13 = param_1[0x1a] + param_1[0x19];
    param_1[0x19] = uVar13;
    iVar12 = (int)uVar11 >> 0x10;
    iVar7 = ((int)uVar9 >> 0x10) - iVar12;
    if (iVar7 < 0) {
      iVar1 = param_1[7] + iVar12 * 2;
      uVar5 = param_1[5];
      uVar10 = *(uint *)(DAT_10075224 + ((uVar9 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
      do {
        if (((uVar10 & 0xff) < param_1[10]) &&
           (uVar8 = (ushort)(uVar13 >> 0x10), *(ushort *)(iVar1 + iVar7 * 2) < uVar8)) {
          *(ushort *)(iVar1 + iVar7 * 2) = uVar8;
          *(char *)(iVar12 + uVar5 + iVar7) = (char)uVar6;
        }
        uVar10 = uVar10 ^ uVar10 >> 6;
        uVar13 = uVar13 + param_1[0x1b];
        iVar7 = iVar7 + 1;
      } while (iVar7 < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[7] = param_1[7] + param_1[8];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar9;
  param_1[1] = uVar11;
  return;
}


