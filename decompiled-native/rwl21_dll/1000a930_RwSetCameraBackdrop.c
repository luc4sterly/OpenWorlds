// 1000a930 RwSetCameraBackdrop [Global]
// programa: RWL21.DLL

int RwSetCameraBackdrop(int param_1,undefined4 param_2)

{
                    /* 0xa930  368  RwSetCameraBackdrop */
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0xa0) = param_2;
    RwDamageCameraViewport
              (param_1,*(int *)(param_1 + 0xa4),*(int *)(param_1 + 0xa8),*(int *)(param_1 + 0xac),
               *(int *)(param_1 + 0xb0));
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


