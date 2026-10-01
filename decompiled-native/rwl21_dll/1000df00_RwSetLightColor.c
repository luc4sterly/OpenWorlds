// 1000df00 RwSetLightColor [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int RwSetLightColor(int param_1,float param_2,float param_3,float param_4)

{
  int iVar1;
  
                    /* 0xdf00  406  RwSetLightColor */
  if (param_1 != 0) {
    if ((uint)param_2 < 0x80000001) {
      if (0x3f7fffff < (int)param_2) {
        param_2 = 1.0;
      }
    }
    else {
      param_2 = 0.0;
    }
    if ((uint)param_3 < 0x80000001) {
      *(float *)(param_1 + 0x78) = param_2 * _DAT_100520d4;
      if (0x3f7fffff < (int)param_3) {
        param_3 = 1.0;
      }
    }
    else {
      *(float *)(param_1 + 0x78) = param_2 * _DAT_100520d4;
      param_3 = 0.0;
    }
    if ((uint)param_4 < 0x80000001) {
      *(float *)(param_1 + 0x7c) = param_3 * _DAT_100520d4;
      if (0x3f7fffff < (int)param_4) {
        param_4 = 1.0;
      }
    }
    else {
      *(float *)(param_1 + 0x7c) = param_3 * _DAT_100520d4;
      param_4 = 0.0;
    }
    *(float *)(param_1 + 0x80) = param_4 * _DAT_100520d4;
    if (*(int *)(param_1 + 0x84) == 2) {
      iVar1 = RwGetLightOwner(param_1);
      FUN_1002c320(iVar1);
    }
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


