// 10019340 RwGetTextureGammaCorrection [Global]
// program: RWL21.DLL

int RwGetTextureGammaCorrection(void)

{
                    /* 0x19340  258  RwGetTextureGammaCorrection */
  return 2 - (uint)((DAT_1005ac04 & 0x10) == 0);
}


