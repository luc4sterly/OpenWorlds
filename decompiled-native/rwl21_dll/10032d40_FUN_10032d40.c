// 10032d40 FUN_10032d40 [Global]
// program: RWL21.DLL

int FUN_10032d40(uint param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  
  DAT_1005e064 = 0;
  piVar7 = *(int **)(param_2 + 0x98);
  DAT_1005e068 = param_4;
  DAT_1005e054 = param_4 + 0x10000;
  DAT_1005e05c = param_5;
  DAT_1005e060 = param_5 + 0x10000;
  iVar2 = FUN_10041c30();
  if (iVar2 == 0) {
    if ((*(uint *)(param_2 + 0x188) & 4) == 0) {
      uVar5 = (*(uint *)(param_2 + 0x188) & 2) >> 1;
    }
    else {
      uVar5 = 2;
    }
  }
  else {
    uVar5 = 2;
  }
  if (uVar5 == 1) {
    uVar5 = 2;
  }
  if (param_1 == 0) {
    pcVar3 = (code *)&LAB_100335c0;
  }
  else {
    FUN_100274c0(FUN_10032eb0);
    pcVar3 = FUN_10029210;
    if (*(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x218) != 1) {
      pcVar3 = (code *)&LAB_10027510;
    }
    pcVar3 = (code *)FUN_1002a7d0(pcVar3,param_1);
  }
  if (uVar5 == 0) {
    iVar2 = *piVar7;
    piVar7 = piVar7 + iVar2 + 2;
    while ((DAT_1005e064 == 0 && (iVar2 = iVar2 + -1, -1 < iVar2))) {
      piVar6 = piVar7 + -1;
      piVar7 = piVar7 + -1;
      (*pcVar3)(*piVar6);
    }
    return DAT_1005e064;
  }
  if (uVar5 == 2) {
    iVar2 = FUN_10041c30();
    if (iVar2 == 0) {
      *(undefined4 *)(PTR_DAT_1005b69c + 0x2e4) = 0;
    }
    iVar4 = 0;
    piVar6 = piVar7 + 2;
    iVar2 = *piVar7;
    while (iVar2 = iVar2 + -1, -1 < iVar2) {
      iVar1 = *piVar6;
      piVar6 = piVar6 + 1;
      (*pcVar3)(iVar1);
      if ((DAT_1005e064 != 0) && (*(int *)(PTR_DAT_1005b69c + 0x2e4) <= DAT_1005e058)) {
        *(int *)(PTR_DAT_1005b69c + 0x2e4) = DAT_1005e058;
        iVar4 = DAT_1005e064;
        DAT_1005e064 = 0;
      }
    }
    return iVar4;
  }
  return 0;
}


