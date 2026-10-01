// 00403d50 FUN_00403d50 [Global]
// program: gamma.dll

undefined4 * __fastcall FUN_00403d50(undefined4 *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[1];
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
    FUN_00451780((undefined4 *)*param_1);
    FUN_0044e100((undefined4 *)param_1[1]);
  }
  return param_1;
}


