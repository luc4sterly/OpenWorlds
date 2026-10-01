// 1000e260 RwGetLightBrightness [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 RwGetLightBrightness(int param_1)

{
  longlong lVar1;
  
                    /* 0xe260  185  RwGetLightBrightness */
  if (param_1 != 0) {
    lVar1 = __ftol();
    return (float10)(int)lVar1 * (float10)_DAT_10052100;
  }
  FUN_1000cba0(1);
  return (float10)_DAT_100520d8;
}


