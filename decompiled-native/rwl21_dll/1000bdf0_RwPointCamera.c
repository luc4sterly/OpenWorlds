// 1000bdf0 RwPointCamera [Global]
// program: RWL21.DLL

int RwPointCamera(int param_1,float param_2,float param_3,float param_4)

{
  float *pfVar1;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
                    /* 0xbdf0  304  RwPointCamera */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  local_18 = param_2;
  local_14 = param_3;
  local_10 = param_4;
  RwSubtractVector(&local_18,(float *)(param_1 + 0x34),&local_18);
  *(int *)(param_1 + 0x224) = *(int *)(param_1 + 0x224) + 1;
  local_c = local_10;
  local_8 = local_14;
  local_4 = local_18;
  if (param_1 != 0) {
    pfVar1 = FUN_1001cd90((float *)(param_1 + 4),local_18,local_14,local_10);
    if (pfVar1 != (float *)0x0) {
      *(int *)(param_1 + 0x224) = *(int *)(param_1 + 0x224) + 1;
      *(undefined1 *)(param_1 + 0xfd) = 1;
      if (param_1 != 0) {
        return param_1;
      }
    }
    return 0;
  }
  FUN_1000cba0(1);
  return 0;
}


