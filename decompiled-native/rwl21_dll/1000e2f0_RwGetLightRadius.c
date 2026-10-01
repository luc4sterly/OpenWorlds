// 1000e2f0 RwGetLightRadius [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 RwGetLightRadius(int param_1)

{
                    /* 0xe2f0  192  RwGetLightRadius */
  if (param_1 != 0) {
    return (float10)*(float *)(param_1 + 100);
  }
  FUN_1000cba0(1);
  return (float10)_DAT_100520d8;
}


