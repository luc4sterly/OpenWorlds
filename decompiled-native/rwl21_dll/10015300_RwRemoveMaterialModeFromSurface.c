// 10015300 RwRemoveMaterialModeFromSurface [Global]
// program: RWL21.DLL

bool RwRemoveMaterialModeFromSurface(uint param_1)

{
  int iVar1;
  
                    /* 0x15300  340  RwRemoveMaterialModeFromSurface */
  FUN_1001ba80();
  iVar1 = RwCurrentMaterial();
  iVar1 = RwRemoveMaterialModeFromMaterial(iVar1,param_1);
  return (bool)('\x01' - (iVar1 == 0));
}


