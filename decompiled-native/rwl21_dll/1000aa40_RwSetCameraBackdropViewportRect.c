// 1000aa40 RwSetCameraBackdropViewportRect [Global]
// program: RWL21.DLL

int RwSetCameraBackdropViewportRect(int param_1,int param_2,int param_3,int param_4,int param_5)

{
                    /* 0xaa40  371  RwSetCameraBackdropViewportRect */
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0xa0) != 0) {
      RwDamageCameraViewport
                (param_1,*(int *)(param_1 + 0xa4),*(int *)(param_1 + 0xa8),*(int *)(param_1 + 0xac),
                 *(int *)(param_1 + 0xb0));
    }
    *(int *)(param_1 + 0xa4) = param_2;
    *(int *)(param_1 + 0xa8) = param_3;
    *(int *)(param_1 + 0xac) = param_4;
    *(int *)(param_1 + 0xb0) = param_5;
    if (*(int *)(param_1 + 0xa0) != 0) {
      RwDamageCameraViewport(param_1,param_2,param_3,param_4,param_5);
    }
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


