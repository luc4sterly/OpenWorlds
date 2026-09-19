// 100193f0 RwSetTextureDithering [Global]
// programa: RWL21.DLL

/* WARNING: Removing unreachable block (ram,0x100194af) */
/* WARNING: Removing unreachable block (ram,0x10019430) */
/* WARNING: Removing unreachable block (ram,0x1001949d) */
/* WARNING: Removing unreachable block (ram,0x10019442) */

undefined4 RwSetTextureDithering(int param_1)

{
                    /* 0x193f0  472  RwSetTextureDithering */
  if (param_1 == 1) {
    if ((DAT_1005ac04 & 8) == 8) {
      DAT_1005ac04 = 0x15;
    }
    DAT_1005ac04 = DAT_1005ac04 & 0xfffffffe | 2;
    return 1;
  }
  if (param_1 == 2) {
    DAT_1005ac04 = DAT_1005ac04 & 0xfffffffc;
    return 1;
  }
  if (param_1 == 3) {
    if ((DAT_1005ac04 & 8) == 8) {
      DAT_1005ac04 = 0x15;
    }
    DAT_1005ac04 = DAT_1005ac04 & 0xfffffffd | 1;
    return 1;
  }
  FUN_1000cba0(0x3e);
  return 0;
}


