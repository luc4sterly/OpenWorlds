// 00439990 FUN_00439990 [Global]
// programa: gamma.dll

undefined4 * __fastcall FUN_00439990(undefined4 *param_1)

{
  undefined **local_10;
  undefined4 *local_c;
  
  FUN_0042f2c0(param_1);
  *param_1 = &PTR_LAB_00476e90;
  *param_1 = &PTR_LAB_00476e78;
  param_1[2] = &PTR_LAB_00474bac;
  param_1[2] = &PTR_LAB_00475fac;
  param_1[3] = 0;
  FUN_00437c60(&local_10);
  FUN_0043b240(param_1 + 2,(int)&local_10);
  local_10 = &PTR_LAB_00475fac;
  if (local_c != (undefined4 *)0x0) {
    FUN_0042f340(local_c);
  }
  FUN_0042f320(&local_10);
  return param_1;
}


