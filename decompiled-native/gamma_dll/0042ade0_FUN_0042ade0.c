// 0042ade0 FUN_0042ade0 [Global]
// programa: gamma.dll

void __thiscall FUN_0042ade0(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x28) == param_2) {
    return;
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    **(undefined1 **)(param_1 + 0x34) = *(undefined1 *)(param_1 + 0x2c);
    *(undefined4 *)(*(int *)(param_1 + 0x28) + 8) = *(undefined4 *)(param_1 + 0x34);
    *(undefined4 *)(*(int *)(param_1 + 0x28) + 0x10) = *(undefined4 *)(param_1 + 0x30);
  }
  *(int *)(param_1 + 0x28) = param_2;
  FUN_0042ae30(param_1);
  *(undefined4 *)(param_1 + 0x40) = 1;
  return;
}


