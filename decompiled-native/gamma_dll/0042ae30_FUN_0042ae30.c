// 0042ae30 FUN_0042ae30 [Global]
// program: gamma.dll

void __fastcall FUN_0042ae30(int param_1)

{
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(*(int *)(param_1 + 0x28) + 0x10);
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(*(int *)(param_1 + 0x28) + 8);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(param_1 + 0x20) = **(undefined4 **)(param_1 + 0x28);
  *(undefined1 *)(param_1 + 0x2c) = **(undefined1 **)(param_1 + 0x34);
  return;
}


