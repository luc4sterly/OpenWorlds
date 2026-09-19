// 10019c20 RwGetMaterialSpecular [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 RwGetMaterialSpecular(int param_1)

{
                    /* 0x19c20  204  RwGetMaterialSpecular */
  if (param_1 != 0) {
    return ((float10)*(float *)(param_1 + 0x24) + (float10)*(float *)(param_1 + 0x28) +
           (float10)*(float *)(param_1 + 0x2c)) * (float10)_DAT_10052160;
  }
  FUN_1000cba0(1);
  return (float10)_DAT_10052164;
}


