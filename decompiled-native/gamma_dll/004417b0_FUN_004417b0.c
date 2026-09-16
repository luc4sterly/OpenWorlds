// 004417b0 FUN_004417b0 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_004417b0(undefined4 *param_1,uint param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((param_2 & 2) == 0) {
      *param_1 = &PTR_FUN_00478af4;
      *param_1 = &PTR_LAB_00477d54;
      if ((param_2 & 1) != 0) {
        FUN_0044e100(param_1);
      }
    }
    else {
      FUN_00451710((int)param_1,&LAB_00441800);
    }
  }
  return param_1;
}


