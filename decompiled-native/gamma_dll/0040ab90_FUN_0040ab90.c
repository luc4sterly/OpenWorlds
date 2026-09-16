// 0040ab90 FUN_0040ab90 [Global]
// programa: gamma.dll

int FUN_0040ab90(int *param_1)

{
  param_1[1] = param_1[1] + -1;
  if (param_1[1] != 0) {
    return param_1[1];
  }
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x18))(1);
  }
  return 0;
}


