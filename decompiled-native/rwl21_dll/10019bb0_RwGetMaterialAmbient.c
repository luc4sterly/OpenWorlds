// 10019bb0 RwGetMaterialAmbient [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 RwGetMaterialAmbient(int param_1)

{
                    /* 0x19bb0  196  RwGetMaterialAmbient */
  if (param_1 != 0) {
    return ((float10)*(float *)(param_1 + 0x14) + (float10)*(float *)(param_1 + 0xc) +
           (float10)*(float *)(param_1 + 0x10)) * (float10)_DAT_10052160;
  }
  FUN_1000cba0(1);
  return (float10)_DAT_10052164;
}


