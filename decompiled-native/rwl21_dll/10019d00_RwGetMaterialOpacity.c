// 10019d00 RwGetMaterialOpacity [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 RwGetMaterialOpacity(int param_1)

{
                    /* 0x19d00  203  RwGetMaterialOpacity */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return (float10)_DAT_10052164;
  }
  if (*(byte *)(param_1 + 4) != 0xff) {
    return (float10)((uint)*(byte *)(param_1 + 4) << 8) * (float10)_DAT_10052168;
  }
  return (float10)_DAT_10052170;
}


