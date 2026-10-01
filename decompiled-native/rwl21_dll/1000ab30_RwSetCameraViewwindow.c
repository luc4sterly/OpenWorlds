// 1000ab30 RwSetCameraViewwindow [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int RwSetCameraViewwindow(int param_1,float param_2,float param_3)

{
                    /* 0xab30  381  RwSetCameraViewwindow */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  if ((0 < (int)param_2) && (0 < (int)param_3)) {
    *(float *)(param_1 + 0x90) = _DAT_100520a0 / param_2;
    *(float *)(param_1 + 0x94) = _DAT_100520a0 / param_3;
    *(int *)(param_1 + 0x224) = *(int *)(param_1 + 0x224) + 1;
    *(undefined1 *)(param_1 + 0xfd) = 1;
    return param_1;
  }
  FUN_1000cba0(0xb);
  return 0;
}


