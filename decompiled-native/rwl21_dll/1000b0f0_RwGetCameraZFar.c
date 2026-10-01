// 1000b0f0 RwGetCameraZFar [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 RwGetCameraZFar(int param_1)

{
                    /* 0xb0f0  581  RwGetCameraZFar */
  if (param_1 != 0) {
    return (float10)*(float *)(param_1 + 0x84);
  }
  FUN_1000cba0(1);
  return (float10)_DAT_100520bc;
}


