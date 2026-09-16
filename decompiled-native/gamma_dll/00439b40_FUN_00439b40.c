// 00439b40 FUN_00439b40 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_00439b40(int param_1,undefined4 *param_2)

{
  if (*(int **)(param_1 + 0xc) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xc) + 8))(param_2);
    return param_2;
  }
  *param_2 = &PTR_LAB_00474bac;
  *param_2 = &PTR_LAB_00475438;
  param_2[1] = 0;
  if (param_2[1] != 0) {
    FUN_0042f330(param_2[1]);
  }
  return param_2;
}


