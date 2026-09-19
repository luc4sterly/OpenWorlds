// 1000b9c0 RwResetCamera [Global]
// programa: RWL21.DLL

int RwResetCamera(int param_1)

{
                    /* 0xb9c0  352  RwResetCamera */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  FUN_1001c940((float *)(param_1 + 4),-1.0,1.0,-1.0,1);
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else {
    *(undefined4 *)(param_1 + 0x90) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x94) = 0x3f800000;
    *(int *)(param_1 + 0x224) = *(int *)(param_1 + 0x224) + 1;
    *(undefined1 *)(param_1 + 0xfd) = 1;
  }
  *(undefined1 *)(param_1 + 0xfd) = 1;
  *(int *)(param_1 + 0x224) = *(int *)(param_1 + 0x224) + 1;
  return param_1;
}


