// 0043ed50 FUN_0043ed50 [Global]
// programa: gamma.dll

undefined4 FUN_0043ed50(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return *(undefined4 *)(param_1 + 4);
}


