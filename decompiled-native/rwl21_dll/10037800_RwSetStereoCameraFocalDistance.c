// 10037800 RwSetStereoCameraFocalDistance [Global]
// programa: RWL21.DLL

int RwSetStereoCameraFocalDistance(int param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x37800  454  RwSetStereoCameraFocalDistance */
  if ((param_1 != 0) && (iVar2 = 0, puVar1 = DAT_1005b748, 0 < DAT_1005b744)) {
    do {
      if (*(int *)*puVar1 == param_1) {
        iVar2 = DAT_1005b748[iVar2];
        goto LAB_10037830;
      }
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar2 < DAT_1005b744);
  }
  iVar2 = 0;
LAB_10037830:
  if ((iVar2 != 0) && ((param_2 & 0x7fffffff) != 0)) {
    *(uint *)(iVar2 + 8) = param_2;
    return param_1;
  }
  return 0;
}


