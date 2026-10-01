// 10009550 RwFindTaggedClump [Global]
// program: RWL21.DLL

int RwFindTaggedClump(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  int iVar3;
  
                    /* 0x9550  93  RwFindTaggedClump */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    iVar2 = 0;
  }
  else {
    iVar2 = RwGetError();
    bVar1 = FUN_100095f0(param_1,param_2);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      FUN_1000cb60(iVar2);
      return param_1;
    }
    iVar3 = FUN_1000cbd0();
    if (iVar3 != 0) {
      if (iVar2 != 0) {
        FUN_1000cb60(iVar2);
      }
      return 0;
    }
    FUN_1000cb60(iVar2);
    iVar3 = *(int *)(param_1 + 0x178);
    while( true ) {
      if (iVar3 == 0) {
        return 0;
      }
      iVar2 = RwFindClumpInt(iVar3,FUN_100095f0,param_2);
      if (iVar2 != 0) break;
      iVar3 = *(int *)(iVar3 + 0x184);
    }
  }
  return iVar2;
}


