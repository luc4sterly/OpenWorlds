// 100021d0 RwGetPolygonGeometrySampling [Global]
// program: RWL21.DLL

void RwGetPolygonGeometrySampling(undefined4 *param_1)

{
                    /* 0x21d0  218  RwGetPolygonGeometrySampling */
  if (param_1 != (undefined4 *)0x0) {
    RwGetMaterialGeometrySampling((uint *)*param_1);
    return;
  }
  FUN_1000cba0(1);
  RwGetMaterialGeometrySampling((uint *)0x0);
  return;
}


