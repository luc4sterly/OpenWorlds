// 10037a00 RwGetLeftStereoCamera [Global]
// program: RWL21.DLL

undefined4 RwGetLeftStereoCamera(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x37a00  184  RwGetLeftStereoCamera */
  if ((param_1 != 0) && (iVar2 = 0, puVar1 = DAT_1005b748, 0 < DAT_1005b744)) {
    do {
      if (*(int *)*puVar1 == param_1) {
        iVar2 = DAT_1005b748[iVar2];
        goto LAB_10037a30;
      }
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar2 < DAT_1005b744);
  }
  iVar2 = 0;
LAB_10037a30:
  if (iVar2 == 0) {
    return 0;
  }
  return *(undefined4 *)(iVar2 + 0xc);
}


