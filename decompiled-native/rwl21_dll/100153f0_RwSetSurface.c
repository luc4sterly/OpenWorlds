// 100153f0 RwSetSurface [Global]
// programa: RWL21.DLL

undefined4 RwSetSurface(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  
                    /* 0x153f0  456  RwSetSurface */
  FUN_1001ba80();
  FUN_1001ba80();
  iVar1 = RwCurrentMaterial();
  iVar1 = RwSetMaterialAmbient(iVar1,param_1);
  if (iVar1 != 0) {
    FUN_1001ba80();
    iVar1 = RwCurrentMaterial();
    iVar1 = RwSetMaterialDiffuse(iVar1,param_2);
    if (iVar1 != 0) {
      FUN_1001ba80();
      iVar1 = RwCurrentMaterial();
      iVar1 = RwSetMaterialSpecular(iVar1,param_3);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  return 0;
}


