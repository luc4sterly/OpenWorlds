// 00435160 FUN_00435160 [Global]
// programa: gamma.dll

undefined4 * __fastcall FUN_00435160(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_004329c0(puVar1);
    FUN_0044e100(puVar1);
  }
  puVar1 = (undefined4 *)param_1[1];
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00428e50(puVar1 + 4);
    *puVar1 = &PTR_LAB_00473390;
    FUN_0044e100(puVar1);
  }
  return param_1;
}


