// 004533f0 FUN_004533f0 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_004533f0(undefined4 *param_1,uint param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((param_2 & 2) == 0) {
      *param_1 = &PTR_FUN_004822e0;
      *param_1 = &PTR_LAB_004822b8;
      *param_1 = &PTR_LAB_0046d714;
      if ((param_2 & 1) != 0) {
        FUN_0044e100(param_1);
      }
    }
    else {
      FUN_00451710((int)param_1,&LAB_00453440);
    }
  }
  return param_1;
}


