// 100050f0 RwGetClumpLightSampleRate [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 RwGetClumpLightSampleRate(int param_1)

{
                    /* 0x50f0  155  RwGetClumpLightSampleRate */
  if (*(ushort *)(param_1 + 0x198) == 0x3fff) {
    return (float10)_DAT_10052070;
  }
  return (float10)_DAT_10052088 / (float10)(*(ushort *)(param_1 + 0x198) + 1);
}


