// 10034990 FUN_10034990 [Global]
// programa: RWDL8D21.DLL

void FUN_10034990(int *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar2 = param_1[0xd];
  iVar3 = param_1[0xc];
  iVar9 = *param_1;
  iVar11 = param_1[1];
  iVar4 = param_1[3];
  iVar5 = param_1[2];
  iVar6 = param_1[4];
  while (iVar6 = iVar6 + -1, -1 < iVar6) {
    iVar9 = iVar9 + iVar4;
    iVar11 = iVar11 + iVar5;
    uVar8 = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    param_1[0x10] = uVar8;
    iVar10 = (iVar9 >> 0x10) - (iVar11 >> 0x10);
    if (iVar10 < 0) {
      iVar7 = param_1[5];
      do {
        bVar1 = *(byte *)(((uVar8 & 0xf00) >> 8 | (uVar8 & 0xf000000) >> 0x14) + iVar3);
        if (bVar1 != 0) {
          *(undefined1 *)(iVar7 + (iVar11 >> 0x10) + iVar10) = *(undefined1 *)((uint)bVar1 + iVar2);
        }
        uVar8 = param_1[0x12] + uVar8 & 0x7fff7fff;
        iVar10 = iVar10 + 1;
      } while (iVar10 < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
  }
  *param_1 = iVar9;
  param_1[1] = iVar11;
  return;
}


