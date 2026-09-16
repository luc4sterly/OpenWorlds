// 00411ae0 FUN_00411ae0 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_00411ae0(undefined4 *param_1,uint param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((param_2 & 2) == 0) {
      FUN_00454d40(param_1);
      if ((param_2 & 1) != 0) {
        FUN_0044e100(param_1);
      }
    }
    else {
      FUN_00451710((int)param_1,FUN_00454d40);
    }
  }
  return param_1;
}


