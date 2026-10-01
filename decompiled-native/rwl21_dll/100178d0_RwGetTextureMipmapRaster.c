// 100178d0 RwGetTextureMipmapRaster [Global]
// program: RWL21.DLL

undefined4 RwGetTextureMipmapRaster(int param_1)

{
                    /* 0x178d0  578  RwGetTextureMipmapRaster */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x1c);
  }
  FUN_1000cba0(1);
  return 0;
}


