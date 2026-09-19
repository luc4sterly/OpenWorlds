// 1000af90 RwGetCameraNearClipping [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 RwGetCameraNearClipping(int param_1)

{
                    /* 0xaf90  137  RwGetCameraNearClipping */
  if (param_1 != 0) {
    return (float10)*(float *)(param_1 + 0x74);
  }
  FUN_1000cba0(1);
  return (float10)_DAT_100520bc;
}


