// 100272a0 RwGetRasterInfo [Global]
// programa: RWL21.DLL

undefined4 * RwGetRasterInfo(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
                    /* 0x272a0  543  RwGetRasterInfo */
  if ((param_1 != (undefined4 *)0x0) && (param_2 != (undefined4 *)0x0)) {
    puVar2 = param_1;
    for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_2 = *puVar2;
      puVar2 = puVar2 + 1;
      param_2 = param_2 + 1;
    }
    return param_1;
  }
  FUN_1000cba0(1);
  return (undefined4 *)0x0;
}


