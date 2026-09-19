// 10001000 RwGetPolygonMaterial [Global]
// programa: RWL21.DLL

undefined4 RwGetPolygonMaterial(undefined4 *param_1)

{
                    /* 0x1000  220  RwGetPolygonMaterial */
  if (param_1 != (undefined4 *)0x0) {
    return *param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


