// 00444a60 FUN_00444a60 [Global]
// program: gamma.dll

undefined4 FUN_00444a60(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 4) = 0;
  uVar1 = (**(code **)(**(int **)(param_1 + 8) + 0xc4))();
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  return 0;
}


