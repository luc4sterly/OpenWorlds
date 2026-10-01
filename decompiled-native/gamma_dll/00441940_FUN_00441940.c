// 00441940 FUN_00441940 [Global]
// program: gamma.dll

undefined4 FUN_00441940(int param_1,short *param_2)

{
  int *piVar1;
  
  if (param_2 == (short *)0x0) {
    return 0x80004003;
  }
  if (*(short **)(param_1 + 0x2c) == (short *)0x0) {
    *param_2 = 0;
  }
  else {
    FUN_0044b2c0(param_2,*(short **)(param_1 + 0x2c),0x80);
  }
  *(undefined4 *)(param_2 + 0x80) = *(undefined4 *)(param_1 + 0x30);
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return 0;
}


