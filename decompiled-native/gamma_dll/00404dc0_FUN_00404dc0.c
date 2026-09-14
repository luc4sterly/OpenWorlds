// 00404dc0 FUN_00404dc0 [Global]
// programa: gamma.dll

undefined4 * __fastcall FUN_00404dc0(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  
  piVar1 = (int *)param_1[1];
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
    puVar2 = (undefined4 *)*param_1;
    if (puVar2 != (undefined4 *)0x0) {
      FUN_00404e60((int)puVar2);
      FUN_0044e100(puVar2);
    }
    FUN_0044e100((undefined4 *)param_1[1]);
  }
  return param_1;
}


