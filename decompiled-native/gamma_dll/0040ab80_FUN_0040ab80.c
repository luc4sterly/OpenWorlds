// 0040ab80 FUN_0040ab80 [Global]
// program: gamma.dll

undefined4 FUN_0040ab80(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return *(undefined4 *)(param_1 + 4);
}


