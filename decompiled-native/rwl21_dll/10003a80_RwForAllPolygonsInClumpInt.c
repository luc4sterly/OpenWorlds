// 10003a80 RwForAllPolygonsInClumpInt [Global]
// program: RWL21.DLL

int RwForAllPolygonsInClumpInt(int param_1,undefined *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
                    /* 0x3a80  116  RwForAllPolygonsInClumpInt */
  if ((param_1 != 0) && (param_2 != (undefined *)0x0)) {
    piVar1 = FUN_10003930(param_1);
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    piVar4 = piVar1 + 2;
    iVar5 = *piVar1;
    iVar2 = RwGetError();
    do {
      if (iVar5 == 0) {
        FUN_10020be0(piVar1);
        FUN_1000cb60(iVar2);
        return param_1;
      }
      iVar3 = *piVar4;
      piVar4 = piVar4 + 1;
      (*(code *)param_2)(iVar3,param_3);
      iVar3 = FUN_1000cbd0();
      iVar5 = iVar5 + -1;
    } while (iVar3 == 0);
    FUN_10020be0(piVar1);
    if (iVar2 != 0) {
      FUN_1000cb60(iVar2);
    }
    return 0;
  }
  FUN_1000cba0(1);
  return 0;
}


