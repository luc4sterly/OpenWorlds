// 100192c0 RwSetTextureGammaCorrection [Global]
// programa: RWL21.DLL

/* WARNING: Removing unreachable block (ram,0x100192f7) */
/* WARNING: Removing unreachable block (ram,0x100192e6) */

undefined4 RwSetTextureGammaCorrection(int param_1)

{
                    /* 0x192c0  475  RwSetTextureGammaCorrection */
  if (param_1 == 2) {
    if ((DAT_1005ac04 & 8) == 8) {
      DAT_1005ac04 = 0x15;
    }
    DAT_1005ac04 = DAT_1005ac04 | 0x10;
    return 1;
  }
  if (param_1 == 1) {
    DAT_1005ac04 = DAT_1005ac04 & 0xffffffef;
    return 1;
  }
  FUN_1000cba0(0x2e);
  return 0;
}


