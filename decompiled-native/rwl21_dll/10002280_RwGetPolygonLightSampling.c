// 10002280 RwGetPolygonLightSampling [Global]
// programa: RWL21.DLL

void RwGetPolygonLightSampling(undefined4 *param_1)

{
                    /* 0x2280  219  RwGetPolygonLightSampling */
  if (param_1 != (undefined4 *)0x0) {
    RwGetMaterialLightSampling((uint *)*param_1);
    return;
  }
  FUN_1000cba0(1);
  RwGetMaterialLightSampling((uint *)0x0);
  return;
}


