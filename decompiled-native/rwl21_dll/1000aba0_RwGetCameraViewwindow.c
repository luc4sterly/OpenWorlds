// 1000aba0 RwGetCameraViewwindow [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int RwGetCameraViewwindow(int param_1,float *param_2,float *param_3)

{
                    /* 0xaba0  144  RwGetCameraViewwindow */
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else {
    if (param_2 != (float *)0x0) {
      *param_2 = _DAT_100520a0 / *(float *)(param_1 + 0x90);
    }
    if (param_3 != (float *)0x0) {
      *param_3 = _DAT_100520a0 / *(float *)(param_1 + 0x94);
      return param_1;
    }
  }
  return param_1;
}


