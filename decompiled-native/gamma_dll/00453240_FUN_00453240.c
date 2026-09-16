// 00453240 FUN_00453240 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_00453240(undefined4 *param_1,uint param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((param_2 & 2) == 0) {
      *param_1 = &PTR_FUN_00482290;
      *param_1 = &PTR_LAB_00482268;
      *param_1 = &PTR_LAB_0046d714;
      if ((param_2 & 1) != 0) {
        FUN_0044e100(param_1);
      }
    }
    else {
      FUN_00451710((int)param_1,&LAB_00453290);
    }
  }
  return param_1;
}


