// 10014d00 RwSetSurfaceTextureModes [Global]
// program: RWL21.DLL

bool RwSetSurfaceTextureModes(uint param_1)

{
  int iVar1;
  
                    /* 0x14d00  467  RwSetSurfaceTextureModes */
  FUN_1001ba80();
  if ((param_1 & 0xffffffe8) == 0) {
    iVar1 = RwCurrentMaterial();
    iVar1 = RwSetMaterialTextureModes(iVar1,param_1);
    return (bool)('\x01' - (iVar1 == 0));
  }
  FUN_1000cba0(0x39);
  return false;
}


