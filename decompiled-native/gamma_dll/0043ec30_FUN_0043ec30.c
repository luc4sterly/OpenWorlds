// 0043ec30 FUN_0043ec30 [Global]
// programa: gamma.dll

undefined4 FUN_0043ec30(int param_1)

{
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  return *(undefined4 *)(param_1 + 8);
}


