// 1000c070 RwGetCameraZRaster [Global]
// programa: RWL21.DLL

int RwGetCameraZRaster(int param_1)

{
  int iVar1;
  
                    /* 0xc070  580  RwGetCameraZRaster */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x104);
    if (iVar1 == 0) {
      FUN_1000cba0(0x60);
      return 0;
    }
  }
  return iVar1;
}


