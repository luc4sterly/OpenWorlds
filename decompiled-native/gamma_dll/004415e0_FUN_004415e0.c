// 004415e0 FUN_004415e0 [Global]
// program: gamma.dll

void __fastcall FUN_004415e0(int param_1)

{
  bool bVar1;
  
  bVar1 = true;
  if ((*(int *)(param_1 + 8) != 3) && (*(int *)(param_1 + 8) != 2)) {
    bVar1 = false;
  }
  if ((bVar1) && (*(int *)(param_1 + 0x10) != 0)) {
    (**(code **)(**(int **)(param_1 + 0x14) + 0x20))
              (*(int **)(param_1 + 0x14),DAT_00478090,DAT_00478094);
    (**(code **)(**(int **)(param_1 + 0x10) + 0x24))(*(int **)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 8) = 1;
  }
  return;
}


