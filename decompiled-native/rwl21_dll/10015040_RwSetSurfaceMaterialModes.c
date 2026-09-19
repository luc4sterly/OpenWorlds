// 10015040 RwSetSurfaceMaterialModes [Global]
// programa: RWL21.DLL

bool RwSetSurfaceMaterialModes(uint param_1)

{
  int iVar1;
  
                    /* 0x15040  462  RwSetSurfaceMaterialModes */
  FUN_1001ba80();
  if ((param_1 & 0xffffff3f) == 0) {
    iVar1 = RwCurrentMaterial();
    iVar1 = RwSetMaterialModes(iVar1,param_1);
    return (bool)('\x01' - (iVar1 == 0));
  }
  FUN_1000cba0(0x48);
  return false;
}


