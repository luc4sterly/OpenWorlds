// 10020cf0 FUN_10020cf0 [Global]
// program: RWL21.DLL

int * FUN_10020cf0(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar2 = *param_1;
  piVar1 = param_1 + 2;
  do {
    piVar4 = piVar1;
    iVar3 = iVar2 + -1;
    if (iVar2 == 0) {
      return (int *)0x0;
    }
    iVar2 = iVar3;
    piVar1 = piVar4 + 1;
  } while (*piVar4 != param_2);
  piVar1 = piVar4;
  if (iVar3 != 0) {
    piVar1 = (int *)param_1[*param_1 + 1];
    *piVar4 = (int)piVar1;
  }
  *param_1 = *param_1 + -1;
  return piVar1;
}


