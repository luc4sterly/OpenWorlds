// 10001ff0 RwGetPolygonTexture [Global]
// programa: RWL21.DLL

undefined4 RwGetPolygonTexture(int *param_1)

{
  undefined4 uVar1;
  
                    /* 0x1ff0  228  RwGetPolygonTexture */
  if (param_1 != (int *)0x0) {
    uVar1 = RwGetMaterialTexture(*param_1);
    return uVar1;
  }
  FUN_1000cba0(1);
  return 0;
}


