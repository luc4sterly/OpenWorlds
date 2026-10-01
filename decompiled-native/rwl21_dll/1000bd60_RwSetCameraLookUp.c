// 1000bd60 RwSetCameraLookUp [Global]
// program: RWL21.DLL

int RwSetCameraLookUp(int param_1,float param_2,float param_3,float param_4)

{
  float *pfVar1;
  
                    /* 0xbd60  375  RwSetCameraLookUp */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  pfVar1 = FUN_1001cec0((float *)(param_1 + 4),param_2,param_3,param_4);
  if (pfVar1 != (float *)0x0) {
    *(int *)(param_1 + 0x224) = *(int *)(param_1 + 0x224) + 1;
    *(undefined1 *)(param_1 + 0xfd) = 1;
    if (param_1 != 0) {
      return param_1;
    }
  }
  return 0;
}


