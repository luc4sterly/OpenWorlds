// 004329c0 FUN_004329c0 [Global]
// program: gamma.dll

undefined4 * __fastcall FUN_004329c0(undefined4 *param_1)

{
  FUN_0044e100((undefined4 *)*param_1);
  FUN_0042c410((int)(param_1 + 9));
  FUN_0042c410((int)(param_1 + 6));
  param_1[4] = &PTR_LAB_00475468;
  if ((undefined4 *)param_1[5] != (undefined4 *)0x0) {
    FUN_0042f340((undefined4 *)param_1[5]);
  }
  FUN_0042f320(param_1 + 4);
  param_1[2] = &PTR_LAB_00475468;
  if ((undefined4 *)param_1[3] != (undefined4 *)0x0) {
    FUN_0042f340((undefined4 *)param_1[3]);
  }
  FUN_0042f320(param_1 + 2);
  FUN_00434430(param_1 + 1);
  return param_1;
}


