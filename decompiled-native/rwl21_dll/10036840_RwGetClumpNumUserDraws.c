// 10036840 RwGetClumpNumUserDraws [Global]
// program: RWL21.DLL

int RwGetClumpNumUserDraws(int param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x36840  160  RwGetClumpNumUserDraws */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    iVar1 = -1;
  }
  else {
    iVar1 = 0;
    iVar2 = *(int *)(param_1 + 0xe4);
    if (iVar2 != 0) {
      do {
        iVar1 = iVar1 + 1;
        iVar2 = *(int *)(iVar2 + 0x38);
      } while (iVar2 != 0);
      return iVar1;
    }
  }
  return iVar1;
}


