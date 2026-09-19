// 1002f840 RwGetSceneNumClumps [Global]
// programa: RWL21.DLL

int RwGetSceneNumClumps(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
                    /* 0x2f840  242  RwGetSceneNumClumps */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    iVar1 = -1;
  }
  else {
    iVar1 = 0;
    if (*(int *)(param_1 + 0x20) != 0) {
      if (*(uint **)(param_1 + 4) != (uint *)0x0) {
        iVar1 = FUN_1002f8c0(0,0,*(uint **)(param_1 + 4));
      }
      iVar2 = *(int *)(param_1 + 0x1c);
      if (0 < iVar2) {
        piVar3 = *(int **)(param_1 + 0xc);
        do {
          if (*(int *)(*piVar3 + 0x44) == 1) {
            iVar1 = iVar1 + 1;
          }
          piVar3 = piVar3 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      iVar2 = *(int *)(param_1 + 8);
      if (iVar2 != 0) {
        do {
          if (*(int *)(iVar2 + 0x44) == 1) {
            iVar1 = iVar1 + 1;
          }
          iVar2 = *(int *)(iVar2 + 0x10);
        } while (iVar2 != 0);
        return iVar1;
      }
    }
  }
  return iVar1;
}


