// 100024e0 RwGetPolygonMaterialModes [Global]
// programa: RWL21.DLL

void RwGetPolygonMaterialModes(int *param_1)

{
                    /* 0x24e0  221  RwGetPolygonMaterialModes */
  if (param_1 != (int *)0x0) {
    RwGetMaterialModes(*param_1);
    return;
  }
  FUN_1000cba0(1);
  RwGetMaterialModes(0);
  return;
}


