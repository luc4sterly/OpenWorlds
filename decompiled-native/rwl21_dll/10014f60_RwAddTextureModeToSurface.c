// 10014f60 RwAddTextureModeToSurface [Global]
// program: RWL21.DLL

bool RwAddTextureModeToSurface(uint param_1)

{
  int iVar1;
  
                    /* 0x14f60  14  RwAddTextureModeToSurface */
  FUN_1001ba80();
  iVar1 = RwCurrentMaterial();
  iVar1 = RwAddTextureModeToMaterial(iVar1,param_1);
  return (bool)('\x01' - (iVar1 == 0));
}


