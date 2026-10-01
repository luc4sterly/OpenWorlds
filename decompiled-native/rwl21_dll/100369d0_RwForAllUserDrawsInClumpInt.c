// 100369d0 RwForAllUserDrawsInClumpInt [Global]
// program: RWL21.DLL

int RwForAllUserDrawsInClumpInt(int param_1,undefined *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
                    /* 0x369d0  121  RwForAllUserDrawsInClumpInt */
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
  piVar4 = piVar1;
  for (iVar2 = *(int *)(param_1 + 0xe4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x38)) {
    *piVar4 = iVar2;
    piVar4 = piVar4 + 1;
  }
  iVar5 = 0;
  iVar2 = RwGetError();
  piVar4 = piVar1;
  if (0 < iVar6) {
    do {
      (*(code *)param_2)(*piVar4,param_3);
      iVar3 = FUN_1000cbd0();
      if (iVar3 != 0) {
        (**(code **)(PTR_DAT_1005b69c + 0x358))(piVar1);
        if (iVar2 != 0) {
          FUN_1000cb60(iVar2);
        }
        return 0;
      }
      iVar5 = iVar5 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar5 < iVar6);
  }
  (**(code **)(PTR_DAT_1005b69c + 0x358))(piVar1);
  FUN_1000cb60(iVar2);
  return param_1;
}


