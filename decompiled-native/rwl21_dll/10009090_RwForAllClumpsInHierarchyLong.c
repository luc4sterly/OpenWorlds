// 10009090 RwForAllClumpsInHierarchyLong [Global]
// programa: RWL21.DLL

int RwForAllClumpsInHierarchyLong(int param_1,undefined *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x9090  97  RwForAllClumpsInHierarchyLong */
  if ((param_1 == 0) || (param_2 == (undefined *)0x0)) {
    FUN_1000cba0(1);
    return 0;
  }
  iVar2 = *(int *)(param_1 + 0x178);
  while (iVar2 != 0) {
    iVar3 = *(int *)(iVar2 + 0x184);
    iVar1 = RwForAllClumpsInHierarchyLong(iVar2,param_2,param_3);
    iVar2 = iVar3;
    if (iVar1 == 0) {
      return 0;
    }
  }
  iVar2 = RwGetError();
  (*(code *)param_2)(param_1,param_3);
  iVar3 = FUN_1000cbd0();
  if (iVar3 == 0) {
    FUN_1000cb60(iVar2);
    return param_1;
  }
  if (iVar2 != 0) {
    FUN_1000cb60(iVar2);
  }
  return 0;
}


