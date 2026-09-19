// 10020d30 FUN_10020d30 [Global]
// programa: RWL21.DLL

void FUN_10020d30(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = *param_1;
  piVar2 = param_1 + 2;
  while (iVar3 != 0) {
    piVar4 = piVar2 + 1;
    if (*piVar2 == param_2) {
      while (iVar3 = iVar3 + -1, iVar3 != 0) {
        iVar1 = *piVar4;
        piVar4 = piVar4 + 1;
        *piVar2 = iVar1;
        piVar2 = piVar2 + 1;
      }
      *param_1 = *param_1 + -1;
      piVar2 = piVar4;
    }
    else {
      iVar3 = iVar3 + -1;
      piVar2 = piVar4;
    }
  }
  return;
}


