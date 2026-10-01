// 10037ff0 RwEndStereoCameraUpdate [Global]
// program: RWL21.DLL

int RwEndStereoCameraUpdate(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x37ff0  82  RwEndStereoCameraUpdate */
  if ((param_1 != 0) && (iVar2 = 0, puVar1 = DAT_1005b748, 0 < DAT_1005b744)) {
    do {
      if (*(int *)*puVar1 == param_1) {
        iVar2 = DAT_1005b748[iVar2];
        goto LAB_1003801e;
      }
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar2 < DAT_1005b744);
  }
  iVar2 = 0;
LAB_1003801e:
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x46c) == 1)) {
    RwEndCameraUpdate(param_1);
    DAT_1005b73c = 0;
    DAT_1005b740 = 0;
    return param_1;
  }
  RwBeginCameraUpdate(param_1,DAT_1005b740);
  RwEndCameraUpdate(param_1);
  DAT_1005b73c = 0;
  DAT_1005b740 = 0;
  return param_1;
}


