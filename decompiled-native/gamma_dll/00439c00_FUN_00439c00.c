// 00439c00 FUN_00439c00 [Global]
// program: gamma.dll

undefined4 * __fastcall FUN_00439c00(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_00476e60;
  param_1[2] = &PTR_LAB_00475468;
  if ((undefined4 *)param_1[3] != (undefined4 *)0x0) {
    FUN_0042f340((undefined4 *)param_1[3]);
  }
  FUN_0042f320(param_1 + 2);
  *param_1 = &PTR_LAB_00476e90;
  FUN_0042f2d0(param_1);
  return param_1;
}


