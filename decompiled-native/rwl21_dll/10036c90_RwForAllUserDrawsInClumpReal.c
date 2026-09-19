// 10036c90 RwForAllUserDrawsInClumpReal [Global]
// programa: RWL21.DLL

int RwForAllUserDrawsInClumpReal(int param_1,undefined *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
                    /* 0x36c90  124  RwForAllUserDrawsInClumpReal */
  if ((param_1 == 0) || (param_2 == (undefined *)0x0)) {
    FUN_1000cba0(1);
    return 0;
  }
  if (param_1 == 0) {
    iVar6 = -1;
    FUN_1000cba0(1);
  }
  else {
    iVar6 = 0;
    for (iVar2 = *(int *)(param_1 + 0xe4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x38)) {
      iVar6 = iVar6 + 1;
    }
  }
  if (iVar6 == 0) {
    return param_1;
  }
  piVar1 = (int *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(iVar6 * 4);
  if (piVar1 == (int *)0x0) {
    FUN_1000cba0(3);
    return 0;
  }
  piVar5 = piVar1;
  for (iVar2 = *(int *)(param_1 + 0xe4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x38)) {
    *piVar5 = iVar2;
    piVar5 = piVar5 + 1;
  }
  iVar4 = 0;
  iVar2 = RwGetError();
  piVar5 = piVar1;
  if (0 < iVar6) {
    do {
      (*(code *)param_2)(*piVar5,param_3);
      iVar3 = FUN_1000cbd0();
      if (iVar3 != 0) {
        (**(code **)(PTR_DAT_1005b69c + 0x358))(piVar1);
        if (iVar2 != 0) {
          FUN_1000cb60(iVar2);
        }
        return 0;
      }
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar4 < iVar6);
  }
  (**(code **)(PTR_DAT_1005b69c + 0x358))(piVar1);
  FUN_1000cb60(iVar2);
  return param_1;
}


