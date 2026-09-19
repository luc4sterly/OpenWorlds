// 100191b0 _RwSetTextureColorMatching@4 [Global]
// programa: RWL21.DLL

undefined4 _RwSetTextureColorMatching_4(int param_1)

{
                    /* 0x191b0  178  _RwSetTextureColorMatching@4 */
  if ((DAT_1005ac04 & 8) == 0) {
    if (param_1 == 2) {
      return 1;
    }
  }
  else if (param_1 == 1) {
    return 1;
  }
  if (param_1 != 1) {
    if (param_1 == 2) {
      DAT_1005ac04 = 0x15;
      return 1;
    }
    FUN_1000cba0(0x2e);
    return 0;
  }
  DAT_1005ac04 = 8;
  return 1;
}


