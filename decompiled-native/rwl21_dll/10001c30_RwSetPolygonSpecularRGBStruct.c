// 10001c30 RwSetPolygonSpecularRGBStruct [Global]
// programa: RWL21.DLL

int * RwSetPolygonSpecularRGBStruct(int *param_1,uint *param_2)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  
                    /* 0x1c30  561  RwSetPolygonSpecularRGBStruct */
  if ((param_1 == (int *)0x0) || (param_2 == (uint *)0x0)) {
    FUN_1000cba0(1);
    return param_1;
  }
  if (param_1 == (int *)0x0) {
    FUN_1000cba0(1);
    puVar1 = (uint *)0x0;
  }
  else {
    puVar1 = (uint *)*param_1;
  }
  piVar2 = param_1;
  if (puVar1[0x10] != 1) {
    puVar1 = RwDuplicateMaterial(puVar1);
    if (puVar1 == (uint *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      puVar1[0x10] = puVar1[0x10] - 1;
      piVar2 = RwSetPolygonMaterial(param_1,(int *)puVar1);
    }
  }
  if (piVar2 != (int *)0x0) {
    if (param_1 == (int *)0x0) {
      FUN_1000cba0(1);
      iVar3 = 0;
    }
    else {
      iVar3 = *param_1;
    }
    RwSetMaterialSpecularRGBStruct(iVar3,param_2);
    return param_1;
  }
  return (int *)0x0;
}


