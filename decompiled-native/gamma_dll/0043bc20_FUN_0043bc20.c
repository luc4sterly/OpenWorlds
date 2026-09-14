// 0043bc20 FUN_0043bc20 [Global]
// programa: gamma.dll

undefined4 * __cdecl FUN_0043bc20(undefined4 *param_1)

{
  uint *puVar1;
  
  puVar1 = FUN_0044e010(0x14);
  if (puVar1 != (uint *)0x0) {
    FUN_0043bd40(puVar1);
  }
  *param_1 = &PTR_LAB_00474bac;
  *param_1 = &PTR_LAB_00475438;
  param_1[1] = puVar1;
  if (param_1[1] != 0) {
    FUN_0042f330(param_1[1]);
  }
  return param_1;
}


