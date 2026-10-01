// 10036fd0 FUN_10036fd0 [Global]
// program: RWL21.DLL

int FUN_10036fd0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  *param_1 = *piVar1;
  param_1[2] = param_1[2] + -1;
  if ((int *)param_1[1] == piVar1) {
    param_1[1] = 0;
  }
  return (int)piVar1;
}


