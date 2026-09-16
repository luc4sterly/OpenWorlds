// 00444520 FUN_00444520 [Global]
// programa: gamma.dll

undefined4 FUN_00444520(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0xb0))();
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0xb4))();
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 4) = 0;
  FUN_0044b100((undefined4 *)(param_1 + 0x18));
  return 0;
}


