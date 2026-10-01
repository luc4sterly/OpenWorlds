// 1000a600 RwSetCameraData [Global]
// program: RWL21.DLL

int RwSetCameraData(int param_1,undefined4 param_2)

{
                    /* 0xa600  372  RwSetCameraData */
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x21c) = param_2;
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


