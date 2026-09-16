// 0043b0d0 FUN_0043b0d0 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_0043b0d0(undefined4 *param_1,uint param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((param_2 & 2) == 0) {
      *param_1 = &PTR_FUN_00476e60;
      param_1[2] = &PTR_LAB_00475468;
      if ((undefined4 *)param_1[3] != (undefined4 *)0x0) {
        FUN_0042f340((undefined4 *)param_1[3]);
      }
      FUN_0042f320(param_1 + 2);
      *param_1 = &PTR_LAB_00476e90;
      FUN_0042f2d0(param_1);
      if ((param_2 & 1) != 0) {
        FUN_0044e100(param_1);
      }
    }
    else {
      FUN_00451710((int)param_1,FUN_00439c00);
    }
  }
  return param_1;
}


