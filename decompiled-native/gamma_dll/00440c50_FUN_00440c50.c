// 00440c50 FUN_00440c50 [Global]
// programa: gamma.dll

void __fastcall FUN_00440c50(int param_1)

{
  if ((*(int *)(param_1 + 0x34) != 0) && (*(int *)(param_1 + 0x38) != 0)) {
    (**(code **)(**(int **)(param_1 + 0x24) + 0x1c))(*(int **)(param_1 + 0x24),0);
    *(undefined4 *)(param_1 + 8) = 1;
  }
  return;
}


