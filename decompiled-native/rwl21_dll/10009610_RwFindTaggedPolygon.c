// 10009610 RwFindTaggedPolygon [Global]
// program: RWL21.DLL

undefined4 RwFindTaggedPolygon(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
                    /* 0x9610  94  RwFindTaggedPolygon */
  DAT_1005ddb8 = 0;
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else {
    piVar1 = FUN_10003930(param_1);
    if (piVar1 != (int *)0x0) {
      piVar4 = piVar1 + 2;
      iVar5 = *piVar1;
      iVar2 = RwGetError();
      do {
        if (iVar5 == 0) {
          FUN_10020be0(piVar1);
          FUN_1000cb60(iVar2);
          return DAT_1005ddb8;
        }
        iVar3 = *piVar4;
        piVar4 = piVar4 + 1;
        FUN_100096b0(iVar3,param_2);
        iVar3 = FUN_1000cbd0();
        iVar5 = iVar5 + -1;
      } while (iVar3 == 0);
      FUN_10020be0(piVar1);
      if (iVar2 != 0) {
        FUN_1000cb60(iVar2);
      }
    }
  }
  return DAT_1005ddb8;
}


