// 10014370 RwSetSurfaceAmbientRGB [Global]
// programa: RWL21.DLL

bool RwSetSurfaceAmbientRGB(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  
                    /* 0x14370  562  RwSetSurfaceAmbientRGB */
  FUN_1001ba80();
  iVar1 = RwCurrentMaterial();
  iVar1 = RwSetMaterialAmbientRGB(iVar1,param_1,param_2,param_3);
  return (bool)('\x01' - (iVar1 == 0));
}


