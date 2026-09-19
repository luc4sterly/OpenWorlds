// 1002fd10 RwForAllClumpsInSceneLong [Global]
// programa: RWL21.DLL

int RwForAllClumpsInSceneLong(int param_1,undefined *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iStack_4;
  
                    /* 0x2fd10  102  RwForAllClumpsInSceneLong */
  if ((param_1 == 0) || (param_2 == (undefined *)0x0)) {
    FUN_1000cba0(1);
  }
  else {
    if (*(int *)(param_1 + 0x20) == 0) {
      return param_1;
    }
    puVar3 = (undefined4 *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(*(int *)(param_1 + 0x20) * 4);
    if (puVar3 != (undefined4 *)0x0) {
      iVar4 = 0;
      if (*(uint **)(param_1 + 4) != (uint *)0x0) {
        iVar4 = FUN_1002fae0((int)puVar3,0,*(uint **)(param_1 + 4));
      }
      iVar7 = 0;
      if (0 < *(int *)(param_1 + 0x1c)) {
        iVar5 = 0;
        do {
          iVar1 = *(int *)(*(int *)(param_1 + 0xc) + iVar5);
          if ((*(int *)(iVar1 + 0x44) == 1) &&
             (iVar1 = *(int *)(iVar1 + 0x48), *(int *)(iVar1 + 0x174) == 0)) {
            iVar4 = FUN_10008f30(iVar1,iVar4,(int)puVar3);
          }
          iVar5 = iVar5 + 4;
          iVar7 = iVar7 + 1;
        } while (iVar7 < *(int *)(param_1 + 0x1c));
      }
      for (iVar7 = *(int *)(param_1 + 8); iVar7 != 0; iVar7 = *(int *)(iVar7 + 0x10)) {
        if ((*(int *)(iVar7 + 0x44) == 1) && (*(int *)(*(int *)(iVar7 + 0x48) + 0x174) == 0)) {
          iVar4 = FUN_10008f30(*(int *)(iVar7 + 0x48),iVar4,(int)puVar3);
        }
      }
      iStack_4 = RwGetError();
      iVar7 = 0;
      puVar6 = puVar3;
      do {
        if (iVar4 == 0) break;
        uVar2 = *puVar6;
        puVar6 = puVar6 + 1;
        (*(code *)param_2)(uVar2,param_3);
        iVar7 = FUN_1000cbd0();
        iVar4 = iVar4 + -1;
      } while (iVar7 == 0);
      if (iVar7 != 0) {
        param_1 = 0;
      }
      if (iStack_4 == 0) {
        iStack_4 = iVar7;
      }
      if (iStack_4 != 0) {
        FUN_1000cb60(iStack_4);
      }
      (**(code **)(PTR_DAT_1005b69c + 0x358))(puVar3);
      return param_1;
    }
    FUN_1000cba0(3);
  }
  return 0;
}


