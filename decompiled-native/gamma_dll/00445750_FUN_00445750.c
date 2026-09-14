// 00445750 FUN_00445750 [Global]
// programa: gamma.dll

undefined4 * __fastcall FUN_00445750(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_LAB_00479b6c;
  param_1[3] = &PTR_LAB_00479b84;
  param_1[4] = &PTR_LAB_00479bd4;
  param_1[0x25] = &PTR_LAB_00479c60;
  piVar1 = (int *)param_1[0x26];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    param_1[0x26] = 0;
  }
  *param_1 = &PTR_LAB_00479cdc;
  param_1[3] = &PTR_LAB_00479cf4;
  param_1[4] = &PTR_LAB_00479d44;
  FUN_00451780((undefined4 *)param_1[5]);
  FUN_004480e0((int)(param_1 + 0xd));
  *param_1 = &PTR_FUN_0047a004;
  FUN_00446370(param_1 + 1);
  return param_1;
}


