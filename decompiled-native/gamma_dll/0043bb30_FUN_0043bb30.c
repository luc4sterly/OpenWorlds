// 0043bb30 FUN_0043bb30 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_0043bb30(undefined4 *param_1,uint param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((param_2 & 2) == 0) {
      *param_1 = &PTR_FUN_00476ff4;
      param_1[2] = &PTR_LAB_00475040;
      if ((undefined4 *)param_1[3] != (undefined4 *)0x0) {
        FUN_0042f340((undefined4 *)param_1[3]);
      }
      FUN_0042f320(param_1 + 2);
      FUN_00437f50(param_1);
      if ((param_2 & 1) != 0) {
        FUN_0044e100(param_1);
      }
    }
    else {
      FUN_00451710((int)param_1,&LAB_0043b550);
    }
  }
  return param_1;
}


