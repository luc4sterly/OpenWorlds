// 0044b100 FUN_0044b100 [Global]
// program: gamma.dll

void __fastcall FUN_0044b100(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)*param_1;
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)puVar2[1];
    FUN_0044e100(puVar2);
    puVar2 = puVar1;
  }
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = param_1[1];
  return;
}


