// 00445300 FUN_00445300 [Global]
// program: gamma.dll

int FUN_00445300(int *param_1)

{
  int iVar1;
  
  if (param_1[6] == 0) {
    return 1;
  }
  iVar1 = (**(code **)(*param_1 + 0xe0))();
  if (iVar1 < 0) {
    return iVar1;
  }
  (**(code **)(*(int *)param_1[6] + 8))((int *)param_1[6]);
  param_1[6] = 0;
  return 0;
}


