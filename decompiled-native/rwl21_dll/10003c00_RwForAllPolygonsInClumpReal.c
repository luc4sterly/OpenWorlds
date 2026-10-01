// 10003c00 RwForAllPolygonsInClumpReal [Global]
// program: RWL21.DLL

int RwForAllPolygonsInClumpReal(int param_1,undefined *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
                    /* 0x3c00  119  RwForAllPolygonsInClumpReal */
  if ((param_1 != 0) && (param_2 != (undefined *)0x0)) {
    piVar1 = FUN_10003930(param_1);
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    iVar4 = *piVar1;
    iVar2 = RwGetError();
    piVar5 = piVar1 + 2;
    do {
      if (iVar4 == 0) {
        FUN_10020be0(piVar1);
        FUN_1000cb60(iVar2);
        return param_1;
      }
      (*(code *)param_2)(*piVar5,param_3);
      iVar3 = FUN_1000cbd0();
      iVar4 = iVar4 + -1;
      piVar5 = piVar5 + 1;
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


