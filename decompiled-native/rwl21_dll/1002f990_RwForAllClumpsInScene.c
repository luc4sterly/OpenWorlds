// 1002f990 RwForAllClumpsInScene [Global]
// programa: RWL21.DLL

int RwForAllClumpsInScene(int param_1,undefined *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  
                    /* 0x2f990  100  RwForAllClumpsInScene */
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
      iVar6 = 0;
      if (0 < *(int *)(param_1 + 0x1c)) {
        iVar5 = 0;
        do {
          iVar1 = *(int *)(*(int *)(param_1 + 0xc) + iVar5);
          if ((*(int *)(iVar1 + 0x44) == 1) &&
             (iVar1 = *(int *)(iVar1 + 0x48), *(int *)(iVar1 + 0x174) == 0)) {
            iVar4 = FUN_10008f30(iVar1,iVar4,(int)puVar3);
          }
          iVar5 = iVar5 + 4;
          iVar6 = iVar6 + 1;
        } while (iVar6 < *(int *)(param_1 + 0x1c));
      }
      for (iVar6 = *(int *)(param_1 + 8); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x10)) {
        if ((*(int *)(iVar6 + 0x44) == 1) && (*(int *)(*(int *)(iVar6 + 0x48) + 0x174) == 0)) {
          iVar4 = FUN_10008f30(*(int *)(iVar6 + 0x48),iVar4,(int)puVar3);
        }
      }
      iVar6 = RwGetError();
      iVar5 = 0;
      puVar7 = puVar3;
      do {
        if (iVar4 == 0) break;
        uVar2 = *puVar7;
        puVar7 = puVar7 + 1;
        (*(code *)param_2)(uVar2);
        iVar5 = FUN_1000cbd0();
        iVar4 = iVar4 + -1;
      } while (iVar5 == 0);
      if (iVar5 != 0) {
        param_1 = 0;
      }
      if ((iVar6 != 0) || (iVar6 = iVar5, iVar5 != 0)) {
        FUN_1000cb60(iVar6);
      }
      (**(code **)(PTR_DAT_1005b69c + 0x358))(puVar3);
      return param_1;
    }
    FUN_1000cba0(3);
  }
  return 0;
}


