// 1000ba80 RwTransformCameraOrientation [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int RwTransformCameraOrientation(int param_1,float *param_2)

{
  float *pfVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_EDX;
  float10 extraout_ST0;
  undefined8 uVar2;
  float local_44 [12];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
                    /* 0xba80  508  RwTransformCameraOrientation */
  if ((param_1 == 0) || (param_2 == (float *)0x0)) {
    param_1 = 0;
  }
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  local_14 = *(undefined4 *)(param_1 + 0x34);
  local_10 = *(undefined4 *)(param_1 + 0x38);
  local_c = *(undefined4 *)(param_1 + 0x3c);
  local_8 = 0x3f800000;
  uVar2 = FUN_1001c300((float *)(param_1 + 4),param_2,local_44);
  pfVar1 = (float *)uVar2;
  if (pfVar1 != (float *)0x0) {
    pfVar1 = FUN_1001c150(extraout_ECX,(int)((ulonglong)uVar2 >> 0x20),pfVar1,pfVar1);
    if (pfVar1 != (float *)0x0) {
      uVar2 = FUN_1001c600(extraout_ECX_00,extraout_EDX,pfVar1);
      if ((float10)_DAT_100520c0 < extraout_ST0) {
        uVar2 = FUN_100510e0(extraout_ECX_01,(int)((ulonglong)uVar2 >> 0x20),pfVar1,
                             (float *)(param_1 + 4));
        if ((int)uVar2 != 0) goto LAB_1000bafd;
      }
    }
  }
  param_1 = 0;
LAB_1000bafd:
  if (param_1 != 0) {
    *(int *)(param_1 + 0x224) = *(int *)(param_1 + 0x224) + 1;
    *(undefined1 *)(param_1 + 0xfd) = 1;
    return param_1;
  }
  FUN_1000cba0(7);
  return 0;
}


