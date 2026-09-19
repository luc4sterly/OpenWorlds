// 1000dc20 RwTransformLight [Global]
// programa: RWL21.DLL

int __fastcall
RwTransformLight(undefined4 param_1,undefined4 param_2,int param_3,float *param_4,undefined4 param_5
                )

{
  int iVar1;
  
                    /* 0xdc20  513  RwTransformLight */
  if ((param_3 == 0) || (param_4 == (float *)0x0)) {
    param_3 = 0;
  }
  if (param_3 != 0) {
    iVar1 = FUN_1001d040(param_5,param_2,(float *)(param_3 + 8),param_4,param_5);
    if (iVar1 != 0) {
      iVar1 = RwGetLightOwner(param_3);
      FUN_1002c320(iVar1);
      if (param_3 != 0) {
        return param_3;
      }
    }
    return 0;
  }
  FUN_1000cba0(1);
  return 0;
}


