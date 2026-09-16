// 00440ba0 FUN_00440ba0 [Global]
// programa: gamma.dll

void __thiscall FUN_00440ba0(int param_1,undefined4 param_2)

{
  bool bVar1;
  
  if (*(int *)(param_1 + 0x34) != 0) {
    bVar1 = true;
    if ((*(int *)(param_1 + 8) != 1) && (*(int *)(param_1 + 8) != 2)) {
      bVar1 = false;
    }
    if ((bVar1) && (*(int *)(param_1 + 0x38) != 0)) {
      (**(code **)(**(int **)(param_1 + 0x24) + 0x1c))(*(int **)(param_1 + 0x24),1);
      *(undefined4 *)(param_1 + 8) = 3;
      *(undefined4 *)(param_1 + 4) = param_2;
    }
  }
  return;
}


