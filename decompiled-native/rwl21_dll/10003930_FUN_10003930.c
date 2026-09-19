// 10003930 FUN_10003930 [Global]
// programa: RWL21.DLL

int * FUN_10003930(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  piVar2 = FUN_10020b70(*(int *)(param_1 + 0x94));
  if (piVar2 == (int *)0x0) {
    return (int *)0x0;
  }
  iVar3 = 0;
  if (0 < **(int **)(param_1 + 0x98)) {
    iVar4 = 0;
    piVar5 = piVar2;
    do {
      iVar6 = *(int *)(*(int *)(param_1 + 0x98) + 8 + iVar4);
      if ((iVar6 == *(int *)(iVar6 + 0x2c)) ||
         (piVar1 = (int *)(iVar6 + 0x30), piVar2 = piVar5, iVar6 = *(int *)(iVar6 + 0x2c),
         *piVar1 == 0)) {
        piVar2 = FUN_10020c20(piVar5,iVar6);
      }
      if (piVar2 == (int *)0x0) {
        FUN_10020be0(piVar5);
        return (int *)0x0;
      }
      iVar4 = iVar4 + 4;
      iVar3 = iVar3 + 1;
      piVar5 = piVar2;
    } while (iVar3 < **(int **)(param_1 + 0x98));
  }
  if (*piVar2 == *(int *)(param_1 + 0x94)) {
    return piVar2;
  }
  FUN_10020be0(piVar2);
  FUN_1000cba0(99);
  return (int *)0x0;
}


