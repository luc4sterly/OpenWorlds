// 0043eaa0 FUN_0043eaa0 [Global]
// program: gamma.dll

undefined4 FUN_0043eaa0(int param_1)

{
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  return *(undefined4 *)(param_1 + 0x10);
}


