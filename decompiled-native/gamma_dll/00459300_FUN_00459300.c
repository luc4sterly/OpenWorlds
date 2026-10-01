// 00459300 FUN_00459300 [Global]
// program: gamma.dll

void __cdecl FUN_00459300(int param_1)

{
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x24);
  *(int *)(param_1 + 0x2c) =
       *(int *)(param_1 + 0x2c) - (*(uint *)(param_1 + 0x1c) & *(uint *)(param_1 + 0x30));
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x1c);
  return;
}


