// 00440c00 FUN_00440c00 [Global]
// programa: gamma.dll

void __fastcall FUN_00440c00(int param_1)

{
  bool bVar1;
  
  if (*(int *)(param_1 + 0x34) != 0) {
    bVar1 = true;
    if ((*(int *)(param_1 + 8) != 3) && (*(int *)(param_1 + 8) != 1)) {
      bVar1 = false;
    }
    if ((bVar1) && (*(int *)(param_1 + 0x38) != 0)) {
      (**(code **)(**(int **)(param_1 + 0x24) + 0x1c))(*(int **)(param_1 + 0x24),0);
      *(undefined4 *)(param_1 + 8) = 2;
    }
  }
  return;
}


