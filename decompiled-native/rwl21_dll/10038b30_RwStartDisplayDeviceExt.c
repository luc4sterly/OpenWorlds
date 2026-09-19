// 10038b30 RwStartDisplayDeviceExt [Global]
// programa: RWL21.DLL

uint RwStartDisplayDeviceExt(int param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  uint local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
                    /* 0x38b30  498  RwStartDisplayDeviceExt */
  for (local_10 = 0; local_10 < param_3; local_10 = local_10 + 1) {
    if ((*(byte *)((int)param_4 + local_10 * 8 + 3) & 0x80) != 0) {
      return 0;
    }
  }
  if (*(int *)(PTR_DAT_1005b69c + 0x288) == 0) {
    FUN_1000cba0(0x4e);
    local_14 = 0;
  }
  else {
    if (param_3 == 0) {
      param_3 = 1;
      local_c = 1;
      local_8 = 0;
      param_4 = &local_c;
    }
    if (param_1 == 0) {
      FUN_1000cba0(1);
      local_14 = 0;
    }
    else {
      local_14 = (**(code **)(PTR_DAT_1005b69c + 0x288))
                           (PTR_DAT_1005b69c + 0x14,param_2,param_3,param_4);
      if (local_14 == 0) {
        for (local_10 = 0; local_10 < param_3; local_10 = local_10 + 1) {
          param_4[local_10 * 2] = param_4[local_10 * 2] & 0x7fffffff;
        }
        FUN_1000cba0(0x4f);
        local_14 = 0;
      }
      else {
        for (local_10 = 0; local_10 < param_3; local_10 = local_10 + 1) {
          local_14 = param_4[local_10 * 2] & 0x80000000;
          param_4[local_10 * 2] = param_4[local_10 * 2] & 0x7fffffff;
          if (local_14 == 0) break;
        }
        if (local_14 == 0) {
          FUN_1000cba0(0x42);
          (**(code **)(PTR_DAT_1005b69c + 0x290))(PTR_DAT_1005b69c + 0x14);
          local_14 = 0;
        }
        else if (local_14 != 0) {
          RwTextureDictBegin();
        }
      }
    }
  }
  return local_14;
}


