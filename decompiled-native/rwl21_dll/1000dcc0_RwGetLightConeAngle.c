// 1000dcc0 RwGetLightConeAngle [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 RwGetLightConeAngle(int param_1)

{
  float10 fVar1;
  
                    /* 0xdcc0  187  RwGetLightConeAngle */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return (float10)0.0;
  }
  if (*(int *)(param_1 + 4) != 2) {
    if (*(int *)(param_1 + 4) != 3) {
      return (float10)0.0;
    }
    fVar1 = (float10)FUN_10044a6c();
    return (float10)(float)(fVar1 * (float10)_DAT_100520f8);
  }
  return (float10)180.0;
}


