// 0040abd0 FUN_0040abd0 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_0040abd0(undefined4 *param_1,uint param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((param_2 & 2) == 0) {
      *param_1 = &PTR_FUN_0046e3a4;
      if ((param_2 & 1) != 0) {
        FUN_0044e100(param_1);
      }
    }
    else {
      FUN_00451710((int)param_1,&LAB_0040ac10);
    }
  }
  return param_1;
}


