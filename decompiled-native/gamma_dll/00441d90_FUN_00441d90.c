// 00441d90 FUN_00441d90 [Global]
// programa: gamma.dll

int FUN_00441d90(int *param_1)

{
  param_1[1] = param_1[1] + -1;
  if (param_1[1] != 0) {
    return param_1[1];
  }
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x1c))(1);
  }
  return 0;
}


