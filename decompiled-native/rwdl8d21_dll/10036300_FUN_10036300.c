// 10036300 FUN_10036300 [Global]
// program: RWDL8D21.DLL

void FUN_10036300(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  
  iVar2 = param_1[0xc];
  iVar7 = *param_1;
  iVar8 = param_1[1];
  iVar3 = param_1[3];
  iVar4 = param_1[2];
  iVar5 = param_1[4];
  while (iVar5 = iVar5 + -1, -1 < iVar5) {
    iVar7 = iVar7 + iVar3;
    iVar8 = iVar8 + iVar4;
    uVar9 = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    param_1[0x10] = uVar9;
    iVar10 = (iVar7 >> 0x10) - (iVar8 >> 0x10);
    if (iVar10 < 0) {
      iVar6 = param_1[5];
      do {
        cVar1 = *(char *)(((uVar9 & 0xf000000) >> 0x14 | (uVar9 & 0xf00) >> 8) + iVar2);
        if (cVar1 != '\0') {
          *(char *)(iVar6 + (iVar8 >> 0x10) + iVar10) = cVar1;
        }
        uVar9 = param_1[0x12] + uVar9 & 0x7fff7fff;
        iVar10 = iVar10 + 1;
      } while (iVar10 < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
  }
  *param_1 = iVar7;
  param_1[1] = iVar8;
  return;
}


