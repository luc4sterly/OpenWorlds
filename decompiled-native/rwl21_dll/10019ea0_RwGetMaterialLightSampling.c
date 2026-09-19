// 10019ea0 RwGetMaterialLightSampling [Global]
// programa: RWL21.DLL

int RwGetMaterialLightSampling(uint *param_1)

{
                    /* 0x19ea0  201  RwGetMaterialLightSampling */
  if (param_1 != (uint *)0x0) {
    return 2 - (uint)((*param_1 & 1) == 0);
  }
  FUN_1000cba0(1);
  return 0;
}


