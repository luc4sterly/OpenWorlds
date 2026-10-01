// 100377a0 RwGetStereoCameraEyeSeparation [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 RwGetStereoCameraEyeSeparation(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x377a0  248  RwGetStereoCameraEyeSeparation */
  if ((param_1 != 0) && (iVar2 = 0, puVar1 = DAT_1005b748, 0 < DAT_1005b744)) {
    do {
      if (*(int *)*puVar1 == param_1) {
        iVar2 = DAT_1005b748[iVar2];
        goto LAB_100377d0;
      }
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar2 < DAT_1005b744);
  }
  iVar2 = 0;
LAB_100377d0:
  if (iVar2 == 0) {
    return (float10)_DAT_10052280;
  }
  return (float10)*(float *)(iVar2 + 4);
}


