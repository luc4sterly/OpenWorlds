// 10014660 RwSetSurfaceSpecular [Global]
// program: RWL21.DLL

bool RwSetSurfaceSpecular(uint param_1)

{
  int iVar1;
  
                    /* 0x14660  464  RwSetSurfaceSpecular */
  FUN_1001ba80();
  iVar1 = RwCurrentMaterial();
  iVar1 = RwSetMaterialSpecular(iVar1,param_1);
  return (bool)('\x01' - (iVar1 == 0));
}


