// 1000a650 RwSetCameraProjection [Global]
// programa: RWL21.DLL

int RwSetCameraProjection(int param_1,int param_2)

{
                    /* 0xa650  378  RwSetCameraProjection */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  if ((param_2 != 1) && (param_2 != 2)) {
    FUN_1000cba0(0x2d);
    return 0;
  }
  *(int *)(param_1 + 0x218) = param_2;
  *(int *)(param_1 + 0x224) = *(int *)(param_1 + 0x224) + 1;
  *(undefined1 *)(param_1 + 0xfd) = 1;
  FUN_10041b80(param_1,(float *)(param_1 + 0x74));
  *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_1 + 0x88);
  return param_1;
}


