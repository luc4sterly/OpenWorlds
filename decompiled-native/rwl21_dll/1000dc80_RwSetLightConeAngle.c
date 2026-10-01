// 1000dc80 RwSetLightConeAngle [Global]
// program: RWL21.DLL

int RwSetLightConeAngle(int param_1,float param_2)

{
  int iVar1;
  undefined1 auVar2 [10];
  
                    /* 0xdc80  408  RwSetLightConeAngle */
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else if (*(int *)(param_1 + 4) == 3) {
    auVar2 = FUN_10041760(param_2);
    *(float *)(param_1 + 0x74) = (float)(float10)auVar2;
    iVar1 = RwGetLightOwner(param_1);
    FUN_1002c320(iVar1);
    return param_1;
  }
  return 0;
}


