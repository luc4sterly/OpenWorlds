// 0044ed50 FUN_0044ed50 [Global]
// program: gamma.dll

int __thiscall FUN_0044ed50(int *param_1,short *param_2,int param_3)

{
  short *psVar1;
  short sVar2;
  int *piVar3;
  int iStack_18;
  int iStack_14;
  
  iStack_14 = (int)(((param_1[3] - param_1[2]) + 1U) -
                   (uint)((uint)(param_1[3] - param_1[2]) < 0x80000000)) >> 1;
  if (iStack_14 < param_3) {
    piVar3 = &iStack_14;
  }
  else {
    piVar3 = &param_3;
  }
  iStack_18 = *piVar3;
  if (0 < iStack_18) {
    FUN_00458960((undefined4 *)param_2,(undefined4 *)param_1[2],iStack_18);
    param_1[2] = param_1[2] + iStack_18 * 2;
    param_3 = param_3 - iStack_18;
    param_2 = param_2 + iStack_18;
  }
  while( true ) {
    if (param_3 < 1) {
      return iStack_18;
    }
    if ((uint)param_1[2] < (uint)param_1[3]) {
      psVar1 = (short *)param_1[2];
      param_1[2] = param_1[2] + 2;
      sVar2 = *psVar1;
    }
    else {
      sVar2 = (**(code **)(*param_1 + 0x24))();
    }
    if (sVar2 == -1) break;
    *param_2 = sVar2;
    param_3 = param_3 + -1;
    iStack_18 = iStack_18 + 1;
    param_2 = param_2 + 1;
  }
  return iStack_18;
}


