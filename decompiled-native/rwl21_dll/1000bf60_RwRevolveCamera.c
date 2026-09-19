// 1000bf60 RwRevolveCamera [Global]
// programa: RWL21.DLL

int RwRevolveCamera(int param_1,float param_2)

{
  float *pfVar1;
  
                    /* 0xbf60  354  RwRevolveCamera */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  pfVar1 = FUN_1001d240((float *)(param_1 + 4),param_2);
  if (pfVar1 != (float *)0x0) {
    *(int *)(param_1 + 0x224) = *(int *)(param_1 + 0x224) + 1;
    *(undefined1 *)(param_1 + 0xfd) = 1;
    if (param_1 != 0) {
      return param_1;
    }
  }
  return 0;
}


