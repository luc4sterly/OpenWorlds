// 1000bb50 RwTransformCamera [Global]
// programa: RWL21.DLL

int __fastcall
RwTransformCamera(undefined4 param_1,undefined4 param_2,int param_3,float *param_4,
                 undefined4 param_5)

{
  int iVar1;
  
                    /* 0xbb50  507  RwTransformCamera */
  if ((param_3 == 0) || (param_4 == (float *)0x0)) {
    param_3 = 0;
  }
  if (param_3 != 0) {
    iVar1 = FUN_1001d040(param_5,param_2,(float *)(param_3 + 4),param_4,param_5);
    if (iVar1 != 0) {
      *(int *)(param_3 + 0x224) = *(int *)(param_3 + 0x224) + 1;
      *(undefined1 *)(param_3 + 0xfd) = 1;
      if (param_3 != 0) {
        return param_3;
      }
    }
    return 0;
  }
  FUN_1000cba0(1);
  return 0;
}


