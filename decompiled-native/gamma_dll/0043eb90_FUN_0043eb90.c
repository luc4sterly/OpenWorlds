// 0043eb90 FUN_0043eb90 [Global]
// programa: gamma.dll

undefined4 FUN_0043eb90(int param_1)

{
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  return *(undefined4 *)(param_1 + 0xc);
}


