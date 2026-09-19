// 100175c0 RwSetTextureMipmapRaster [Global]
// programa: RWL21.DLL

int RwSetTextureMipmapRaster(int param_1,int param_2)

{
                    /* 0x175c0  579  RwSetTextureMipmapRaster */
  if ((*(uint *)(*(int *)(PTR_DAT_1005b69c + 0x2c4) + 0x78) & 0x400) == 0) {
    FUN_1000cba0(0x5f);
    return 0;
  }
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  if (param_2 == 0) {
LAB_10017683:
    if (param_2 == 0) goto LAB_100176d5;
    if (*(int *)(param_2 + 0x20) / ((*(int *)(param_2 + 0x1c) >> 1) + *(int *)(param_2 + 0x1c)) !=
        *(int *)(param_1 + 0xc)) {
      FUN_1000cba0(0x17);
      return 0;
    }
  }
  else {
    if (*(int *)(param_2 + 0x3c) != 0) {
      if (*(int *)(param_2 + 0x3c) == param_1) {
        return param_1;
      }
      FUN_1000cba0(0x43);
      return 0;
    }
    if (param_2 != 0) {
      if (((*(int *)(param_1 + 0x18) != 0) &&
          (*(int *)(*(int *)(param_1 + 0x18) + 0x1c) >> 1 != *(int *)(param_2 + 0x1c))) ||
         ((*(int *)(PTR_DAT_1005b69c + 0x20) >> 1 != *(int *)(param_2 + 0x1c) &&
          (*(int *)(PTR_DAT_1005b69c + 700) >> 1 != *(int *)(param_2 + 0x1c))))) {
        FUN_1000cba0(0x16);
        return 0;
      }
      goto LAB_10017683;
    }
  }
  if ((param_2 != 0) && (*(int *)(PTR_DAT_1005b69c + 0x14) != *(int *)(param_2 + 0x24))) {
    FUN_1000cba0(0x18);
    return 0;
  }
LAB_100176d5:
  if (*(int *)(param_1 + 0x1c) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x3c) = 0;
    RwDestroyRaster(*(undefined4 **)(param_1 + 0x1c));
  }
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 8) = 0;
  }
  else {
    *(int *)(param_2 + 0x3c) = param_1;
    *(uint *)(param_2 + 0x40) = *(uint *)(param_2 + 0x40) | 1;
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 0x18);
  }
  *(int *)(param_1 + 0x1c) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0;
  if (*(int *)(param_1 + 0x18) != 0) {
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x18);
    return param_1;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return param_1;
}


