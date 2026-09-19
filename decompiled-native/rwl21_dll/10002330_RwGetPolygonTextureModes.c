// 10002330 RwGetPolygonTextureModes [Global]
// programa: RWL21.DLL

void RwGetPolygonTextureModes(int *param_1)

{
                    /* 0x2330  229  RwGetPolygonTextureModes */
  if (param_1 != (int *)0x0) {
    RwGetMaterialTextureModes(*param_1);
    return;
  }
  FUN_1000cba0(1);
  RwGetMaterialTextureModes(0);
  return;
}


