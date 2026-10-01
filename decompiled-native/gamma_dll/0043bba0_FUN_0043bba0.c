// 0043bba0 FUN_0043bba0 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_0043bba0(undefined4 *param_1,uint param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((param_2 & 2) == 0) {
      *param_1 = &PTR_FUN_0047700c;
      FUN_00437f50(param_1);
      if ((param_2 & 1) != 0) {
        FUN_0044e100(param_1);
      }
    }
    else {
      FUN_00451710((int)param_1,&LAB_0043b340);
    }
  }
  return param_1;
}


