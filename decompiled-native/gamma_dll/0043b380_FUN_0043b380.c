// 0043b380 FUN_0043b380 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_0043b380(undefined4 param_1,undefined4 *param_2)

{
  *param_2 = &PTR_LAB_00474bac;
  *param_2 = &PTR_LAB_00475fac;
  param_2[1] = param_1;
  if (param_2[1] != 0) {
    FUN_0042f330(param_2[1]);
  }
  return param_2;
}


