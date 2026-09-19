// 10019360 RwSetTextureMipmapState [Global]
// programa: RWL21.DLL

undefined4 RwSetTextureMipmapState(int param_1)

{
                    /* 0x19360  577  RwSetTextureMipmapState */
  if (param_1 != 2) {
    if (param_1 == 1) {
      DAT_1005ac04 = DAT_1005ac04 & 0xffffffbf;
      return 1;
    }
    FUN_1000cba0(0x2e);
    return 0;
  }
  if ((*(uint *)(*(int *)(PTR_DAT_1005b69c + 0x2c4) + 0x78) & 0x400) != 0) {
    DAT_1005ac04 = DAT_1005ac04 | 0x40;
    return 1;
  }
  FUN_1000cba0(0x5f);
  return 0;
}


