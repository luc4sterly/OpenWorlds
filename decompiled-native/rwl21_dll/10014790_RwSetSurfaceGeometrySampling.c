// 10014790 RwSetSurfaceGeometrySampling [Global]
// program: RWL21.DLL

bool RwSetSurfaceGeometrySampling(undefined4 param_1)

{
  uint *puVar1;
  
                    /* 0x14790  460  RwSetSurfaceGeometrySampling */
  FUN_1001ba80();
  puVar1 = (uint *)RwCurrentMaterial();
  puVar1 = RwSetMaterialGeometrySampling(puVar1,param_1);
  return (bool)('\x01' - (puVar1 == (uint *)0x0));
}


