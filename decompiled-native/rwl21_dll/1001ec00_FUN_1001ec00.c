// 1001ec00 FUN_1001ec00 [Global]
// program: RWL21.DLL

undefined4 FUN_1001ec00(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  while (param_1 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*param_1;
    FUN_10037010(DAT_1005ac74,param_1);
    param_1 = puVar1;
  }
  return 0;
}


