// 00445ff0 FUN_00445ff0 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_00445ff0(undefined4 *param_1,uint param_2)

{
  int *piVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    if ((param_2 & 2) == 0) {
      *param_1 = &PTR_FUN_00479b6c;
      param_1[3] = &PTR_FUN_00479b84;
      param_1[4] = &PTR_FUN_00479bd4;
      param_1[0x25] = &PTR_FUN_00479c60;
      piVar1 = (int *)param_1[0x26];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        param_1[0x26] = 0;
      }
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
      FUN_00451710((int)param_1,FUN_00445750);
    }
  }
  return param_1;
}


