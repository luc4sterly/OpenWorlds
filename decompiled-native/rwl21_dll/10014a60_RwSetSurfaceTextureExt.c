// 10014a60 RwSetSurfaceTextureExt [Global]
// program: RWL21.DLL

bool RwSetSurfaceTextureExt(char *param_1,char *param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  uint *puVar4;
  
                    /* 0x14a60  466  RwSetSurfaceTextureExt */
  FUN_1001ba80();
  if (param_1 == (char *)0x0) {
    uVar3 = 0;
    puVar4 = (uint *)RwCurrentMaterial();
    puVar4 = RwSetMaterialTexture(puVar4,uVar3);
    return (bool)('\x01' - (puVar4 == (uint *)0x0));
  }
  if (param_2 == (char *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = RwReadMaskRaster(param_2);
    if (piVar1 == (int *)0x0) {
      return false;
    }
  }
  piVar2 = RwGetNamedTexture(param_1);
  if (piVar2 != (int *)0x0) {
    if (piVar1 != (int *)0x0) {
      uVar3 = RwMaskTexture((uint)piVar2,piVar1);
      if (uVar3 == 0) {
        RwDestroyRaster(piVar1);
        return false;
      }
      RwDestroyRaster(piVar1);
    }
    puVar4 = (uint *)RwCurrentMaterial();
    puVar4 = RwSetMaterialTexture(puVar4,(uint)piVar2);
    return (bool)('\x01' - (puVar4 == (uint *)0x0));
  }
  if (piVar1 != (int *)0x0) {
    RwDestroyRaster(piVar1);
  }
  return false;
}


