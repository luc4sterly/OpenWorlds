// 00448700 FUN_00448700 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_00448700(undefined4 *param_1,uint param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((param_2 & 2) == 0) {
      *param_1 = &PTR_FUN_0047b778;
      param_1[3] = &PTR_FUN_0047b790;
      param_1[4] = &PTR_FUN_0047b7e0;
      param_1[0x25] = &PTR_FUN_0047b86c;
      FUN_00445750(param_1);
      if ((param_2 & 1) != 0) {
        FUN_0044e100(param_1);
      }
    }
    else {
      FUN_00451710((int)param_1,&LAB_00448770);
    }
  }
  return param_1;
}


