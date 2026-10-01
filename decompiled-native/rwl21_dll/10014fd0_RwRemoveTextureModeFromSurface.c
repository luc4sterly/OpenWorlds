// 10014fd0 RwRemoveTextureModeFromSurface [Global]
// program: RWL21.DLL

bool RwRemoveTextureModeFromSurface(uint param_1)

{
  int iVar1;
  
                    /* 0x14fd0  343  RwRemoveTextureModeFromSurface */
  FUN_1001ba80();
  iVar1 = RwCurrentMaterial();
  iVar1 = RwRemoveTextureModeFromMaterial(iVar1,param_1);
  return (bool)('\x01' - (iVar1 == 0));
}


