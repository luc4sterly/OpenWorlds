// 1000b120 RwGetCameraZState [Global]
// program: RWL21.DLL

undefined4 RwGetCameraZState(int param_1)

{
                    /* 0xb120  574  RwGetCameraZState */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x8c);
  }
  FUN_1000cba0(1);
  return 0;
}


