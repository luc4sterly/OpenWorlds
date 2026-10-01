// 1000c0c0 RwGetCameraRaster [Global]
// program: RWL21.DLL

undefined4 RwGetCameraRaster(int param_1)

{
                    /* 0xc0c0  140  RwGetCameraRaster */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x100);
  }
  FUN_1000cba0(1);
  return 0;
}


