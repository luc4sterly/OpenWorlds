// 1002c340 FUN_1002c340 [Global]
// program: RWL21.DLL

void FUN_1002c340(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  iVar1 = param_1[0x23];
  if (param_1[0x21] == 1) {
    piVar5 = *(int **)(iVar1 + 0x14);
    piVar4 = piVar5;
    piVar3 = piVar5;
    while ((piVar2 = piVar4, piVar2 != (int *)0x0 && (param_1 != piVar2))) {
      piVar3 = piVar2;
      piVar4 = (int *)*piVar2;
    }
    if (piVar2 != (int *)0x0) {
      if (piVar2 == piVar5) {
        piVar5 = (int *)*piVar5;
      }
      else {
        *piVar3 = *piVar2;
      }
    }
    *(int **)(iVar1 + 0x14) = piVar5;
    *param_1 = *(int *)(iVar1 + 0x10);
    *(int **)(iVar1 + 0x10) = param_1;
    if (iVar1 == 0) {
      FUN_1000cba0(1);
      return;
    }
    *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
    return;
  }
  if (param_1[0x21] != 2) {
    return;
  }
  piVar5 = *(int **)(iVar1 + 0x10);
  piVar4 = piVar5;
  piVar3 = piVar5;
  while ((piVar2 = piVar4, piVar2 != (int *)0x0 && (param_1 != piVar2))) {
    piVar3 = piVar2;
    piVar4 = (int *)*piVar2;
  }
  if (piVar2 != (int *)0x0) {
    if (piVar5 == piVar2) {
      piVar5 = (int *)*piVar5;
    }
    else {
      *piVar3 = *piVar2;
    }
  }
  *(int **)(iVar1 + 0x10) = piVar5;
  *param_1 = *(int *)(iVar1 + 0x14);
  *(int **)(iVar1 + 0x14) = param_1;
  if (iVar1 == 0) {
    FUN_1000cba0(1);
    return;
  }
  *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
  return;
}


