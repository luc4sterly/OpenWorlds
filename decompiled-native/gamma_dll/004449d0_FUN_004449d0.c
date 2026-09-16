// 004449d0 FUN_004449d0 [Global]
// programa: gamma.dll

uint FUN_004449d0(int param_1,int param_2)

{
  int iVar1;
  undefined4 auStack_58 [18];
  
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0xc4))();
  if (*(int *)(param_1 + 0xc) == iVar1) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + param_2;
    FUN_00448100(auStack_58);
    iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0xe8))(*(int *)(param_1 + 4) + -1,auStack_58);
    FUN_004480e0((int)auStack_58);
    return (uint)(iVar1 != 0);
  }
  return 0x80040203;
}


