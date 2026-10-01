// 10015290 RwAddMaterialModeToSurface [Global]
// program: RWL21.DLL

bool RwAddMaterialModeToSurface(uint param_1)

{
  int iVar1;
  
                    /* 0x15290  9  RwAddMaterialModeToSurface */
  FUN_1001ba80();
  iVar1 = RwCurrentMaterial();
  iVar1 = RwAddMaterialModeToMaterial(iVar1,param_1);
  return (bool)('\x01' - (iVar1 == 0));
}


