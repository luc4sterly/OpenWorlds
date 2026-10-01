// 00443880 FUN_00443880 [Global]
// program: gamma.dll

undefined4 * __fastcall FUN_00443880(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_00479ed4;
  param_1[3] = &PTR_LAB_00479eec;
  param_1[4] = &PTR_LAB_00479f30;
  FUN_00451780((undefined4 *)param_1[0xe]);
  piVar1 = (int *)param_1[6];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    param_1[6] = 0;
  }
  *param_1 = &PTR_FUN_0047a004;
  FUN_00446370(param_1 + 1);
  return param_1;
}


