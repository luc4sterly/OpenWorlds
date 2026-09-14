// 00454d40 FUN_00454d40 [Global]
// programa: gamma.dll

undefined4 * __fastcall FUN_00454d40(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  *param_1 = &PTR_LAB_0046f410;
  iVar2 = param_1[2];
  while (iVar2 != 0) {
    iVar2 = iVar2 + -1;
    puVar1 = (undefined4 *)(iVar2 * 8 + param_1[1]);
    (*(code *)*puVar1)(0,param_1,puVar1[1]);
  }
  puVar1 = (undefined4 *)param_1[8];
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00404dc0(puVar1);
    FUN_0044e100(puVar1);
  }
  FUN_00454a60((undefined4 *)param_1[6]);
  FUN_00454a60((undefined4 *)param_1[4]);
  FUN_00454a60((undefined4 *)param_1[1]);
  return param_1;
}


