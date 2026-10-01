// 0044b0d0 FUN_0044b0d0 [Global]
// program: gamma.dll

undefined4 * __fastcall FUN_0044b0d0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  FUN_0044b100(param_1);
  puVar2 = (undefined4 *)param_1[5];
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)puVar2[1];
    FUN_0044e100(puVar2);
    puVar2 = puVar1;
  }
  return param_1;
}


