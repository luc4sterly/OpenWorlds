// 1000b060 RwSetCameraZState [Global]
// program: RWL21.DLL

int RwSetCameraZState(int param_1,int param_2)

{
                    /* 0xb060  575  RwSetCameraZState */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  if ((param_2 != 2) && (param_2 != 1)) {
    FUN_1000cba0(0x2e);
    return 0;
  }
  *(int *)(param_1 + 0x8c) = param_2;
  *(int *)(param_1 + 0x224) = *(int *)(param_1 + 0x224) + 1;
  *(undefined1 *)(param_1 + 0xfd) = 1;
  return param_1;
}


