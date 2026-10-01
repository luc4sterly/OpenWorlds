// 1000afc0 RwSetCameraFarClipping [Global]
// program: RWL21.DLL

int RwSetCameraFarClipping(int param_1,float param_2)

{
                    /* 0xafc0  373  RwSetCameraFarClipping */
  if (param_1 == 0) {
    param_1 = 0;
    FUN_1000cba0(1);
  }
  else if ((0x3c75c28e < (int)param_2) && (*(float *)(param_1 + 0x74) <= param_2)) {
    *(float *)(param_1 + 0x78) = param_2;
    *(int *)(param_1 + 0x224) = *(int *)(param_1 + 0x224) + 1;
    *(undefined1 *)(param_1 + 0xfd) = 1;
    FUN_10041b80(param_1,(float *)(param_1 + 0x74));
    *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_1 + 0x88);
    return param_1;
  }
  return param_1;
}


