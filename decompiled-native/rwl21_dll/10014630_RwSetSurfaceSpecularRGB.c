// 10014630 RwSetSurfaceSpecularRGB [Global]
// program: RWL21.DLL

bool RwSetSurfaceSpecularRGB(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  
                    /* 0x14630  564  RwSetSurfaceSpecularRGB */
  FUN_1001ba80();
  iVar1 = RwCurrentMaterial();
  iVar1 = RwSetMaterialSpecularRGB(iVar1,param_1,param_2,param_3);
  return (bool)('\x01' - (iVar1 == 0));
}


