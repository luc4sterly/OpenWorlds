// 10032c70 FUN_10032c70 [Global]
// program: RWL21.DLL

void FUN_10032c70(undefined *param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  iVar2 = FUN_10041c30();
  if (iVar2 == 0) {
    if ((*(uint *)(param_2 + 0x188) & 4) == 0) {
      uVar3 = (*(uint *)(param_2 + 0x188) & 2) >> 1;
    }
    else {
      uVar3 = 2;
    }
  }
  else {
    uVar3 = 2;
  }
  if (uVar3 == 0) {
    piVar1 = *(int **)(param_2 + 0x98);
    iVar2 = piVar1[2];
    piVar5 = piVar1 + 3;
    iVar4 = *piVar1 + -1;
    if (-1 < iVar4) {
      do {
        (*(code *)param_1)(iVar2);
        iVar2 = *piVar5;
        iVar4 = iVar4 + -1;
        piVar5 = piVar5 + 1;
      } while (-1 < iVar4);
      return;
    }
  }
  else {
    if (uVar3 == 1) {
      if ((*(int *)(param_2 + 0xa4) != 0) || (*(int *)(*(int *)(param_2 + 0xa8) + 4) != 0)) {
        (**(code **)(PTR_DAT_1005b69c + 0x40))(param_3);
      }
      FUN_10033f70(param_1,param_2);
      return;
    }
    if (uVar3 != 2) {
      return;
    }
    piVar1 = *(int **)(param_2 + 0x98);
    iVar2 = piVar1[2];
    iVar4 = *piVar1;
    piVar1 = piVar1 + 3;
    while (iVar4 = iVar4 + -1, -1 < iVar4) {
      (*(code *)param_1)(iVar2);
      iVar2 = *piVar1;
      piVar1 = piVar1 + 1;
    }
  }
  return;
}


