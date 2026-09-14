// 00454680 FUN_00454680 [Global]
// programa: gamma.dll

void __cdecl FUN_00454680(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[1];
  if (piVar1 == param_1) {
    piVar1 = (int *)0x0;
  }
  if (DAT_0049e768 == param_1) {
    DAT_0049e768 = piVar1;
  }
  if (piVar1 != (int *)0x0) {
    *piVar1 = *param_1;
    *(int **)(*piVar1 + 4) = piVar1;
  }
  param_1[1] = 0;
  *param_1 = 0;
  return;
}


