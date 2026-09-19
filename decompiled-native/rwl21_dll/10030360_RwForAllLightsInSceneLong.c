// 10030360 RwForAllLightsInSceneLong [Global]
// programa: RWL21.DLL

int RwForAllLightsInSceneLong(int param_1,undefined *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int iStack_8;
  
                    /* 0x30360  107  RwForAllLightsInSceneLong */
  if ((param_1 == 0) || (param_2 == (undefined *)0x0)) {
    FUN_1000cba0(1);
  }
  else {
    iVar5 = 0;
    for (puVar3 = *(undefined4 **)(param_1 + 0x10); puVar3 != (undefined4 *)0x0;
        puVar3 = (undefined4 *)*puVar3) {
      iVar5 = iVar5 + 1;
    }
    iVar2 = 0;
    for (puVar3 = *(undefined4 **)(param_1 + 0x14); puVar3 != (undefined4 *)0x0;
        puVar3 = (undefined4 *)*puVar3) {
      iVar2 = iVar2 + 1;
    }
    iVar2 = iVar2 + iVar5;
    if (iVar2 == 0) {
      return param_1;
    }
    puVar3 = (undefined4 *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(iVar2 * 4);
    if (puVar3 != (undefined4 *)0x0) {
      puVar4 = puVar3;
      for (puVar6 = *(undefined4 **)(param_1 + 0x10); puVar6 != (undefined4 *)0x0;
          puVar6 = (undefined4 *)*puVar6) {
        *puVar4 = puVar6;
        puVar4 = puVar4 + 1;
      }
      for (puVar6 = *(undefined4 **)(param_1 + 0x14); puVar6 != (undefined4 *)0x0;
          puVar6 = (undefined4 *)*puVar6) {
        *puVar4 = puVar6;
        puVar4 = puVar4 + 1;
      }
      iStack_8 = RwGetError();
      iVar5 = 0;
      puVar6 = puVar3;
      do {
        if (iVar2 == 0) break;
        uVar1 = *puVar6;
        puVar6 = puVar6 + 1;
        (*(code *)param_2)(uVar1,param_3);
        iVar5 = FUN_1000cbd0();
        iVar2 = iVar2 + -1;
      } while (iVar5 == 0);
      if (iVar5 != 0) {
        param_1 = 0;
      }
      if (iStack_8 == 0) {
        iStack_8 = iVar5;
      }
      if (iStack_8 != 0) {
        FUN_1000cb60(iStack_8);
      }
      (**(code **)(PTR_DAT_1005b69c + 0x358))(puVar3);
      return param_1;
    }
    FUN_1000cba0(3);
  }
  return 0;
}


