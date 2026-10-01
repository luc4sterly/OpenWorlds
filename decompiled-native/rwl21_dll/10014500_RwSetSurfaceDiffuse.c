// 10014500 RwSetSurfaceDiffuse [Global]
// program: RWL21.DLL

bool RwSetSurfaceDiffuse(uint param_1)

{
  int iVar1;
  
                    /* 0x14500  459  RwSetSurfaceDiffuse */
  FUN_1001ba80();
  iVar1 = RwCurrentMaterial();
  iVar1 = RwSetMaterialDiffuse(iVar1,param_1);
  return (bool)('\x01' - (iVar1 == 0));
}


