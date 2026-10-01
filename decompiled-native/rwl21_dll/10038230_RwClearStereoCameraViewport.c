// 10038230 RwClearStereoCameraViewport [Global]
// program: RWL21.DLL

int RwClearStereoCameraViewport(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x38230  26  RwClearStereoCameraViewport */
  if ((param_1 != 0) && (iVar2 = 0, puVar1 = DAT_1005b748, 0 < DAT_1005b744)) {
    do {
      if (*(int *)*puVar1 == param_1) {
        iVar2 = DAT_1005b748[iVar2];
        goto LAB_10038262;
      }
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar2 < DAT_1005b744);
  }
  iVar2 = 0;
LAB_10038262:
  if ((DAT_1005b73c == 0) || (iVar2 == 0)) {
    return 0;
  }
  iVar2 = *(int *)(DAT_1005b73c + 0x46c);
  if (iVar2 == 1) {
    RwClearCameraViewport(param_1);
    return param_1;
  }
  if ((1 < iVar2) && (iVar2 < 4)) {
    RwBeginCameraUpdate(param_1,DAT_1005b740);
    RwClearCameraViewport(param_1);
    RwEndCameraUpdate(param_1);
    return param_1;
  }
  RwBeginCameraUpdate(*(int *)(DAT_1005b73c + 0xc),DAT_1005b740);
  RwClearCameraViewport(*(int *)(DAT_1005b73c + 0xc));
  RwEndCameraUpdate(*(int *)(DAT_1005b73c + 0xc));
  RwBeginCameraUpdate(*(int *)(DAT_1005b73c + 0x23c),DAT_1005b740);
  RwClearCameraViewport(*(int *)(DAT_1005b73c + 0x23c));
  RwEndCameraUpdate(*(int *)(DAT_1005b73c + 0x23c));
  return param_1;
}


