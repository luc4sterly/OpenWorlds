// 100020a0 RwGetPolygonOpacity [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 RwGetPolygonOpacity(int *param_1)

{
  float10 fVar1;
  
                    /* 0x20a0  224  RwGetPolygonOpacity */
  if (param_1 != (int *)0x0) {
    fVar1 = RwGetMaterialOpacity(*param_1);
    return fVar1;
  }
  FUN_1000cba0(1);
  return (float10)_DAT_10052008;
}


