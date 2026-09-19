// 100376a0 RwSetStereoCameraMode [Global]
// programa: RWL21.DLL

int RwSetStereoCameraMode(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int local_4;
  
                    /* 0x376a0  541  RwSetStereoCameraMode */
  if ((param_2 == 2) || (param_2 == 3)) {
    iVar1 = RwGetDeviceInfo(0xc,&local_4,4);
    if (iVar1 == 0) {
      return 0;
    }
    if ((*(uint *)(local_4 + 0x78) & 0x100) == 0) {
      FUN_1000cba0(0x5f);
      return 0;
    }
  }
  if ((param_1 != 0) && (iVar1 = 0, puVar2 = DAT_1005b748, 0 < DAT_1005b744)) {
    do {
      if (*(int *)*puVar2 == param_1) {
        piVar3 = (int *)DAT_1005b748[iVar1];
        goto LAB_10037713;
      }
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar1 < DAT_1005b744);
  }
  piVar3 = (int *)0x0;
LAB_10037713:
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  piVar3[0x11b] = param_2;
  RwInvalidateCameraViewport(*piVar3);
  return param_1;
}


