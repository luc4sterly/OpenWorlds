// 10008e70 RwGetClumpNumChildren [Global]
// programa: RWL21.DLL

int RwGetClumpNumChildren(int param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x8e70  158  RwGetClumpNumChildren */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    iVar1 = -1;
  }
  else {
    iVar1 = 0;
    iVar2 = *(int *)(param_1 + 0x178);
    if (iVar2 != 0) {
      do {
        iVar1 = iVar1 + 1;
        iVar2 = *(int *)(iVar2 + 0x184);
      } while (iVar2 != 0);
      return iVar1;
    }
  }
  return iVar1;
}


