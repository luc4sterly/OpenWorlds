// 10019230 _RwSetTextureOwnPalette@4 [Global]
// program: RWL21.DLL

/* WARNING: Removing unreachable block (ram,0x10019289) */
/* WARNING: Removing unreachable block (ram,0x1001928e) */
/* WARNING: Removing unreachable block (ram,0x100192a7) */

undefined4 _RwSetTextureOwnPalette_4(int param_1)

{
                    /* 0x19230  240  _RwSetTextureOwnPalette@4 */
  if ((DAT_1005ac04 & 0x20) == 0) {
    if (param_1 == 1) {
      return 1;
    }
  }
  else if (param_1 == 2) {
    return 1;
  }
  if (param_1 != 1) {
    if (param_1 == 2) {
      if ((DAT_1005ac04 & 8) != 8) {
        DAT_1005ac04 = 8;
      }
      DAT_1005ac04 = DAT_1005ac04 | 0x20;
      return 1;
    }
    FUN_1000cba0(0x2e);
    return 0;
  }
  DAT_1005ac04 = DAT_1005ac04 & 0xffffffdf;
  return 1;
}


