// 1000dd30 RwSetLightVector [Global]
// programa: RWL21.DLL

int RwSetLightVector(int param_1,float param_2,float param_3,float param_4)

{
  float *pfVar1;
  int iVar2;
  
                    /* 0xdd30  413  RwSetLightVector */
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else {
    if (((ABS(param_2) == 0.0) && (ABS(param_3) == 0.0)) && (ABS(param_4) == 0.0)) {
      FUN_1000cba0(0x20);
      return 0;
    }
    if (*(int *)(param_1 + 4) == 2) {
      FUN_1000cba0(8);
      return 0;
    }
    pfVar1 = FUN_1001cd90((float *)(param_1 + 8),param_2,param_3,param_4);
    if (pfVar1 == (float *)0x0) {
      param_1 = 0;
    }
    if (param_1 != 0) {
      iVar2 = RwGetLightOwner(param_1);
      FUN_1002c320(iVar2);
      return param_1;
    }
  }
  return 0;
}


