// 004109c0 FUN_004109c0 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_004109c0(undefined4 *param_1,uint param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((param_2 & 2) == 0) {
      *param_1 = &PTR_FUN_0046f370;
      FUN_00404dc0(param_1 + 7);
      if ((param_2 & 1) != 0) {
        FUN_0044e100(param_1);
      }
    }
    else {
      FUN_00451710((int)param_1,&LAB_00410a20);
    }
  }
  return param_1;
}


