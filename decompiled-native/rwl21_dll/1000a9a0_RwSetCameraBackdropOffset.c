// 1000a9a0 RwSetCameraBackdropOffset [Global]
// program: RWL21.DLL

int RwSetCameraBackdropOffset(int param_1,undefined4 param_2,undefined4 param_3)

{
                    /* 0xa9a0  369  RwSetCameraBackdropOffset */
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0xb4) = param_2;
    *(undefined4 *)(param_1 + 0xb8) = param_3;
    if (*(int *)(param_1 + 0xa0) != 0) {
      RwDamageCameraViewport
                (param_1,*(int *)(param_1 + 0xa4),*(int *)(param_1 + 0xa8),*(int *)(param_1 + 0xac),
                 *(int *)(param_1 + 0xb0));
    }
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


