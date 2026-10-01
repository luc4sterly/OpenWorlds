// 0043e0c0 FUN_0043e0c0 [Global]
// program: gamma.dll

undefined4 FUN_0043e0c0(int param_1)

{
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  return *(undefined4 *)(param_1 + 0x18);
}


