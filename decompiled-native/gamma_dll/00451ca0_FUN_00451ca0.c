// 00451ca0 FUN_00451ca0 [Global]
// program: gamma.dll

undefined4 * __fastcall FUN_00451ca0(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_00482348;
  if (*(char *)(param_1 + 3) != '\0') {
    FUN_00451780((undefined4 *)param_1[2]);
  }
  *param_1 = &PTR_LAB_0046d714;
  return param_1;
}


