// 10001bc0 RwGetPolygonDiffuseRGB [Global]
// programa: RWL21.DLL

undefined4 * RwGetPolygonDiffuseRGB(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
                    /* 0x1bc0  554  RwGetPolygonDiffuseRGB */
  if ((param_1 != (int *)0x0) && (param_2 != (undefined4 *)0x0)) {
    if (param_1 == (int *)0x0) {
      FUN_1000cba0(1);
      iVar1 = 0;
    }
    else {
      iVar1 = *param_1;
    }
    puVar2 = RwGetMaterialDiffuseRGB(iVar1,param_2);
    return puVar2;
  }
  FUN_1000cba0(1);
  return (undefined4 *)0x0;
}


