// 10014860 FUN_10014860 [Global]
// programa: RWDL8D21.DLL

void FUN_10014860(uint *param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  
  uVar2 = param_1[0xc];
  uVar7 = *param_1;
  uVar9 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar7 = uVar7 + uVar3;
    uVar9 = uVar9 + uVar4;
    uVar10 = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    param_1[0x10] = uVar10;
    uVar8 = *(uint *)(DAT_10075224 + ((uVar7 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
    iVar11 = ((int)uVar7 >> 0x10) - ((int)uVar9 >> 0x10);
    if (iVar11 < 0) {
      uVar6 = param_1[5];
      do {
        if (((uVar8 & 0xff) < param_1[10]) &&
           (cVar1 = *(char *)(((uVar10 & 0x7f000000) >> 0x11 | (uVar10 & 0x7f00) >> 8) + uVar2),
           cVar1 != '\0')) {
          *(char *)(uVar6 + ((int)uVar9 >> 0x10) + iVar11) = cVar1;
        }
        uVar8 = uVar8 ^ uVar8 >> 6;
        uVar10 = param_1[0x12] + uVar10 & 0x7fff7fff;
        iVar11 = iVar11 + 1;
      } while (iVar11 < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar7;
  param_1[1] = uVar9;
  return;
}


