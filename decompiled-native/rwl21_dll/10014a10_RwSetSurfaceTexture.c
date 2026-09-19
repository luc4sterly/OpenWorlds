// 10014a10 RwSetSurfaceTexture [Global]
// programa: RWL21.DLL

bool RwSetSurfaceTexture(char *param_1)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  
                    /* 0x14a10  465  RwSetSurfaceTexture */
  FUN_1001ba80();
  if (param_1 == (char *)0x0) {
    uVar3 = 0;
    puVar2 = (uint *)RwCurrentMaterial();
    puVar2 = RwSetMaterialTexture(puVar2,uVar3);
    return (bool)('\x01' - (puVar2 == (uint *)0x0));
  }
  piVar1 = RwGetNamedTexture(param_1);
  if (piVar1 != (int *)0x0) {
    puVar2 = (uint *)RwCurrentMaterial();
    puVar2 = RwSetMaterialTexture(puVar2,(uint)piVar1);
    return (bool)('\x01' - (puVar2 == (uint *)0x0));
  }
  return false;
}


