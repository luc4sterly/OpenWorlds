// 1000e2b0 RwSetLightRadius [Global]
// program: RWL21.DLL

int RwSetLightRadius(int param_1,undefined4 param_2)

{
  int iVar1;
  
                    /* 0xe2b0  411  RwSetLightRadius */
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 100) = param_2;
    if (*(int *)(param_1 + 0x84) == 2) {
      iVar1 = RwGetLightOwner(param_1);
      FUN_1002c320(iVar1);
    }
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


