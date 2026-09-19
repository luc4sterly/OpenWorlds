// 1000bbb0 RwSetCameraViewOffset [Global]
// programa: RWL21.DLL

int RwSetCameraViewOffset(int param_1,undefined4 param_2,undefined4 param_3)

{
                    /* 0xbbb0  379  RwSetCameraViewOffset */
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x48) = param_2;
    *(undefined4 *)(param_1 + 0x4c) = param_3;
    *(int *)(param_1 + 0x224) = *(int *)(param_1 + 0x224) + 1;
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined1 *)(param_1 + 0xfd) = 1;
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


