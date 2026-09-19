// 10009410 RwFindClumpReal [Global]
// programa: RWL21.DLL

int RwFindClumpReal(int param_1,undefined *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x9410  89  RwFindClumpReal */
  if ((param_1 == 0) || (param_2 == (undefined *)0x0)) {
    FUN_1000cba0(1);
    iVar2 = 0;
  }
  else {
    iVar1 = RwGetError();
    iVar2 = (*(code *)param_2)(param_1,param_3);
    if (iVar2 != 0) {
      FUN_1000cb60(iVar1);
      return param_1;
    }
    iVar2 = FUN_1000cbd0();
    if (iVar2 != 0) {
      if (iVar1 != 0) {
        FUN_1000cb60(iVar1);
      }
      return 0;
    }
    FUN_1000cb60(iVar1);
    iVar1 = *(int *)(param_1 + 0x178);
    while( true ) {
      if (iVar1 == 0) {
        return 0;
      }
      iVar2 = RwFindClumpReal(iVar1,param_2,param_1);
      if (iVar2 != 0) break;
      iVar1 = *(int *)(iVar1 + 0x184);
    }
  }
  return iVar2;
}


