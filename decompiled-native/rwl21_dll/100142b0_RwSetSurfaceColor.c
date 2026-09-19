// 100142b0 RwSetSurfaceColor [Global]
// programa: RWL21.DLL

bool RwSetSurfaceColor(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  
                    /* 0x142b0  458  RwSetSurfaceColor */
  FUN_1001ba80();
  iVar1 = RwCurrentMaterial();
  iVar1 = RwSetMaterialColor(iVar1,param_1,param_2,param_3);
  return (bool)('\x01' - (iVar1 == 0));
}


