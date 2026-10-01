// 10002150 RwSetPolygonGeometrySampling [Global]
// program: RWL21.DLL

undefined4 * RwSetPolygonGeometrySampling(undefined4 *param_1,undefined4 param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  
                    /* 0x2150  435  RwSetPolygonGeometrySampling */
  if (param_1 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
    return (undefined4 *)0x0;
  }
  puVar2 = param_1;
  if (((uint *)*param_1)[0x10] != 1) {
    puVar1 = RwDuplicateMaterial((uint *)*param_1);
    if (puVar1 == (uint *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar1[0x10] = puVar1[0x10] - 1;
      puVar2 = RwSetPolygonMaterial(param_1,(int *)puVar1);
    }
  }
  if (puVar2 != (undefined4 *)0x0) {
    if (param_1 == (undefined4 *)0x0) {
      FUN_1000cba0(1);
      puVar1 = (uint *)0x0;
    }
    else {
      puVar1 = (uint *)*param_1;
    }
    RwSetMaterialGeometrySampling(puVar1,param_2);
    return param_1;
  }
  return (undefined4 *)0x0;
}


