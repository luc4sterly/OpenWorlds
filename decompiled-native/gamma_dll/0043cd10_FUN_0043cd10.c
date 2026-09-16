// 0043cd10 FUN_0043cd10 [Global]
// programa: gamma.dll

undefined4 FUN_0043cd10(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return *(undefined4 *)(param_1 + 4);
}


