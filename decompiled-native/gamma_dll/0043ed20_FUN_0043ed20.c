// 0043ed20 FUN_0043ed20 [Global]
// program: gamma.dll

undefined4 FUN_0043ed20(int param_1,undefined4 *param_2)

{
  *param_2 = 0x14;
  if (*(int *)(param_1 + 0x28) == 0) {
    param_2[1] = 0;
  }
  else {
    param_2[1] = 0x28;
  }
  param_2[1] = param_2[1] | 4;
  param_2[2] = 0;
  return 0;
}


