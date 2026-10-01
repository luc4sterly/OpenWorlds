// 00441dd0 FUN_00441dd0 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_00441dd0(undefined4 *param_1,uint param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((param_2 & 2) == 0) {
      *param_1 = &PTR_FUN_00478d28;
      FUN_0040aac0();
      if ((param_2 & 1) != 0) {
        FUN_0044e100(param_1);
      }
    }
    else {
      FUN_00451710((int)param_1,&LAB_00441e20);
    }
  }
  return param_1;
}


