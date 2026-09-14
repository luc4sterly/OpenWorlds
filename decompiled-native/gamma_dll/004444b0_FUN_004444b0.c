// 004444b0 FUN_004444b0 [Global]
// programa: gamma.dll

undefined4 FUN_004444b0(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0xb0))();
  if (*(int *)(param_1 + 0x10) != iVar1) {
    return 0x80040203;
  }
  if (param_2 <= (uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4))) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + param_2;
    return 0;
  }
  return 1;
}


