// 100148e0 RwSetSurfaceLightSampling [Global]
// programa: RWL21.DLL

bool RwSetSurfaceLightSampling(int param_1)

{
  uint *puVar1;
  
                    /* 0x148e0  461  RwSetSurfaceLightSampling */
  FUN_1001ba80();
  puVar1 = (uint *)RwCurrentMaterial();
  puVar1 = RwSetMaterialLightSampling(puVar1,param_1);
  return (bool)('\x01' - (puVar1 == (uint *)0x0));
}


