// 0042ac80 FUN_0042ac80 [Global]
// programa: gamma.dll

void __fastcall FUN_0042ac80(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  
  iVar2 = *(int *)(param_1 + 0x3c);
  *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x4c);
  piVar1 = *(int **)(param_1 + 0x50);
  *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 4;
  *piVar1 = iVar2;
  for (pbVar4 = *(byte **)(param_1 + 4); pbVar4 < *(byte **)(param_1 + 0x34); pbVar4 = pbVar4 + 1) {
    if (*pbVar4 == 0) {
      uVar3 = 1;
    }
    else {
      uVar3 = *(uint *)(u_________________0123456789_<_>___004739ba + (uint)*pbVar4 * 2 + 0x3b);
    }
    while (iVar2 != *(short *)(&DAT_004740b4 +
                              ((uVar3 & 0xff) + (int)*(short *)(&DAT_00473e98 + iVar2 * 2)) * 2)) {
      iVar2 = (int)*(short *)(&DAT_00473f30 + iVar2 * 2);
      if (0x48 < iVar2) {
        uVar3 = (uint)(byte)(&DAT_00473e30)[(uVar3 & 0xff) * 4];
      }
    }
    piVar1 = *(int **)(param_1 + 0x50);
    iVar2 = (int)*(short *)(&DAT_00473fc8 +
                           ((uVar3 & 0xff) + (int)*(short *)(&DAT_00473e98 + iVar2 * 2)) * 2);
    *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 4;
    *piVar1 = iVar2;
  }
  return;
}


