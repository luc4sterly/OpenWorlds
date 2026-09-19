// 100178b0 RwGetTextureRaster [Global]
// programa: RWL21.DLL

undefined4 RwGetTextureRaster(int param_1)

{
                    /* 0x178b0  262  RwGetTextureRaster */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x18);
  }
  FUN_1000cba0(1);
  return 0;
}


