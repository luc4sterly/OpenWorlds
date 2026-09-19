// 1000de40 RwSetLightPosition [Global]
// programa: RWL21.DLL

int RwSetLightPosition(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
                    /* 0xde40  410  RwSetLightPosition */
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else {
    if (*(int *)(param_1 + 4) == 1) {
      FUN_1000cba0(8);
      return 0;
    }
    iVar1 = FUN_1001cd30(param_1 + 8,param_2,param_3,param_4);
    if (iVar1 == 0) {
      param_1 = 0;
    }
    if (param_1 != 0) {
      iVar1 = RwGetLightOwner(param_1);
      FUN_1002c320(iVar1);
      return param_1;
    }
  }
  return 0;
}


