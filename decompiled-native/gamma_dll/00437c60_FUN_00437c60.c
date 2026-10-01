// 00437c60 FUN_00437c60 [Global]
// program: gamma.dll

undefined4 * __cdecl FUN_00437c60(undefined4 *param_1)

{
  undefined **local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  
  FUN_0043b2c0(&local_14);
  local_c = param_1;
  *param_1 = &PTR_LAB_00474bac;
  *param_1 = &PTR_LAB_00475fac;
  param_1[1] = local_10;
  if (param_1[1] != 0) {
    FUN_0042f330(param_1[1]);
  }
  local_14 = &PTR_LAB_00475fac;
  if (local_10 != (undefined4 *)0x0) {
    FUN_0042f340(local_10);
  }
  FUN_0042f320(&local_14);
  return param_1;
}


