// 100144d0 RwSetSurfaceDiffuseRGB [Global]
// program: RWL21.DLL

bool RwSetSurfaceDiffuseRGB(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  
                    /* 0x144d0  563  RwSetSurfaceDiffuseRGB */
  FUN_1001ba80();
  iVar1 = RwCurrentMaterial();
  iVar1 = RwSetMaterialDiffuseRGB(iVar1,param_1,param_2,param_3);
  return (bool)('\x01' - (iVar1 == 0));
}


