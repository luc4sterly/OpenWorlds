// 10019c90 RwGetMaterialDiffuse [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 RwGetMaterialDiffuse(int param_1)

{
                    /* 0x19c90  199  RwGetMaterialDiffuse */
  if (param_1 != 0) {
    return ((float10)*(float *)(param_1 + 0x18) + (float10)*(float *)(param_1 + 0x1c) +
           (float10)*(float *)(param_1 + 0x20)) * (float10)_DAT_10052160;
  }
  FUN_1000cba0(1);
  return (float10)_DAT_10052164;
}


