// 0043cd20 FUN_0043cd20 [Global]
// program: gamma.dll

undefined4 FUN_0043cd20(undefined4 *param_1)

{
  param_1[1] = param_1[1] + -1;
  if (param_1[1] != 0) {
    return param_1[1];
  }
  FUN_0044e100(param_1);
  return 0;
}


