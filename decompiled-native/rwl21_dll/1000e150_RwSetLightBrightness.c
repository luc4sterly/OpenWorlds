// 1000e150 RwSetLightBrightness [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int RwSetLightBrightness(int param_1,float param_2)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* 0xe150  405  RwSetLightBrightness */
  if (param_1 != 0) {
    local_4 = param_2;
    local_8 = param_2;
    local_c = param_2;
    if ((uint)param_2 < 0x80000001) {
      if (0x3f7fffff < (int)param_2) {
        local_c = 1.0;
      }
    }
    else {
      local_c = 0.0;
    }
    if ((uint)param_2 < 0x80000001) {
      *(float *)(param_1 + 0x78) = local_c * _DAT_100520d4;
      if (0x3f7fffff < (int)param_2) {
        local_8 = 1.0;
      }
    }
    else {
      *(float *)(param_1 + 0x78) = local_c * _DAT_100520d4;
      local_8 = 0.0;
    }
    if ((uint)param_2 < 0x80000001) {
      *(float *)(param_1 + 0x7c) = local_8 * _DAT_100520d4;
      if (0x3f7fffff < (int)param_2) {
        local_4 = 1.0;
      }
    }
    else {
      *(float *)(param_1 + 0x7c) = local_8 * _DAT_100520d4;
      local_4 = 0.0;
    }
    *(float *)(param_1 + 0x80) = local_4 * _DAT_100520d4;
    if (*(int *)(param_1 + 0x84) == 2) {
      iVar1 = RwGetLightOwner(param_1);
      FUN_1002c320(iVar1);
      if (*(int *)(param_1 + 0x84) == 2) {
        iVar1 = RwGetLightOwner(param_1);
        FUN_1002c320(iVar1);
      }
    }
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


