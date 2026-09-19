// 100143a0 RwSetSurfaceAmbient [Global]
// programa: RWL21.DLL

bool RwSetSurfaceAmbient(uint param_1)

{
  int iVar1;
  
                    /* 0x143a0  457  RwSetSurfaceAmbient */
  FUN_1001ba80();
  iVar1 = RwCurrentMaterial();
  iVar1 = RwSetMaterialAmbient(iVar1,param_1);
  return (bool)('\x01' - (iVar1 == 0));
}


