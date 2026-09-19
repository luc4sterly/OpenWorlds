// 1000a0d0 RwGetCameraLookRight [Global]
// programa: RWL21.DLL

float * RwGetCameraLookRight(int param_1,undefined4 *param_2)

{
  float *pfVar1;
  
                    /* 0xa0d0  135  RwGetCameraLookRight */
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    pfVar1 = (float *)FUN_1001d000((undefined4 *)(param_1 + 4),param_2);
    *pfVar1 = -*pfVar1;
    pfVar1[1] = -pfVar1[1];
    pfVar1[2] = -pfVar1[2];
    return pfVar1;
  }
  FUN_1000cba0(1);
  return (float *)0x0;
}


