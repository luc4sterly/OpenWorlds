// 10001e30 RwSetPolygonSurface [Global]
// programa: RWL21.DLL

int * RwSetPolygonSurface(int *param_1,uint param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  
                    /* 0x1e30  441  RwSetPolygonSurface */
  if (param_1 == (int *)0x0) {
    FUN_1000cba0(1);
    return (int *)0x0;
  }
  piVar2 = param_1;
  if (((uint *)*param_1)[0x10] != 1) {
    puVar1 = RwDuplicateMaterial((uint *)*param_1);
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
    RwSetMaterialSurface(iVar3,param_2,param_3,param_4);
    return param_1;
  }
  return (int *)0x0;
}


