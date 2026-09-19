// 1000b030 RwGetCameraFarClipping [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 RwGetCameraFarClipping(int param_1)

{
                    /* 0xb030  131  RwGetCameraFarClipping */
  if (param_1 != 0) {
    return (float10)*(float *)(param_1 + 0x78);
  }
  FUN_1000cba0(1);
  return (float10)_DAT_100520bc;
}


