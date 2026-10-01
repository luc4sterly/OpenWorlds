// 1000b0c0 RwGetCameraZNear [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 RwGetCameraZNear(int param_1)

{
                    /* 0xb0c0  582  RwGetCameraZNear */
  if (param_1 != 0) {
    return (float10)*(float *)(param_1 + 0x80);
  }
  FUN_1000cba0(1);
  return (float10)_DAT_100520bc;
}


