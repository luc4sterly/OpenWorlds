// 10038080 RwShowStereoCameraImage [Global]
// programa: RWL21.DLL

undefined4 RwShowStereoCameraImage(int param_1,undefined *param_2)

{
  undefined4 *puVar1;
  undefined4 extraout_EAX;
  int iVar2;
  
                    /* 0x38080  491  RwShowStereoCameraImage */
  if (param_1 != 0) {
    iVar2 = 0;
    puVar1 = DAT_1005b748;
    if (0 < DAT_1005b744) {
      do {
        if (*(int *)*puVar1 == param_1) {
          iVar2 = DAT_1005b748[iVar2];
          goto LAB_100380ae;
        }
        iVar2 = iVar2 + 1;
        puVar1 = puVar1 + 1;
      } while (iVar2 < DAT_1005b744);
    }
    iVar2 = 0;
LAB_100380ae:
    if (iVar2 != 0) {
      if (*(int *)(iVar2 + 0x46c) != 1) {
        RwInvalidateCameraViewport(param_1);
      }
      RwShowCameraImage(param_1,param_2);
      return extraout_EAX;
    }
  }
  return 0;
}


