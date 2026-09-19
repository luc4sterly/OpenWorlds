// 10015370 RwSetSurfaceOpacity [Global]
// programa: RWL21.DLL

bool RwSetSurfaceOpacity(uint param_1)

{
  uint *puVar1;
  
                    /* 0x15370  463  RwSetSurfaceOpacity */
  FUN_1001ba80();
  puVar1 = (uint *)RwCurrentMaterial();
  puVar1 = RwSetMaterialOpacity(puVar1,param_1);
  return (bool)('\x01' - (puVar1 == (uint *)0x0));
}


