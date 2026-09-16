// 004460c0 FUN_004460c0 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_004460c0(undefined4 *param_1,uint param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((param_2 & 2) == 0) {
      *param_1 = &PTR_FUN_00479cdc;
      param_1[3] = &PTR_FUN_00479cf4;
      param_1[4] = &PTR_FUN_00479d44;
      FUN_00451780((undefined4 *)param_1[5]);
      FUN_004480e0((int)(param_1 + 0xd));
      *param_1 = &PTR_FUN_0047a004;
      FUN_00446370(param_1 + 1);
      if ((param_2 & 1) != 0) {
        FUN_0044e100(param_1);
      }
    }
    else {
      FUN_00451710((int)param_1,&LAB_00444bd0);
    }
  }
  return param_1;
}


