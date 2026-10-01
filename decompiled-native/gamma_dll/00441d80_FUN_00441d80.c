// 00441d80 FUN_00441d80 [Global]
// program: gamma.dll

undefined4 FUN_00441d80(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return *(undefined4 *)(param_1 + 4);
}


