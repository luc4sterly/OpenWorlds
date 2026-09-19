// 10030480 RwForAllLightsInSceneReal [Global]
// programa: RWL21.DLL

int RwForAllLightsInSceneReal(int param_1,undefined *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  
                    /* 0x30480  109  RwForAllLightsInSceneReal */
  if ((param_1 == 0) || (param_2 == (undefined *)0x0)) {
    FUN_1000cba0(1);
  }
  else {
    iVar6 = 0;
    for (puVar3 = *(undefined4 **)(param_1 + 0x10); puVar3 != (undefined4 *)0x0;
        puVar3 = (undefined4 *)*puVar3) {
      iVar6 = iVar6 + 1;
    }
    iVar2 = 0;
    for (puVar3 = *(undefined4 **)(param_1 + 0x14); puVar3 != (undefined4 *)0x0;
        puVar3 = (undefined4 *)*puVar3) {
      iVar2 = iVar2 + 1;
    }
    iVar6 = iVar6 + iVar2;
    if (iVar6 == 0) {
      return param_1;
    }
    puVar3 = (undefined4 *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(iVar6 * 4);
    if (puVar3 != (undefined4 *)0x0) {
      puVar5 = puVar3;
      for (puVar7 = *(undefined4 **)(param_1 + 0x10); puVar7 != (undefined4 *)0x0;
          puVar7 = (undefined4 *)*puVar7) {
        *puVar5 = puVar7;
        puVar5 = puVar5 + 1;
      }
      for (puVar7 = *(undefined4 **)(param_1 + 0x14); puVar7 != (undefined4 *)0x0;
          puVar7 = (undefined4 *)*puVar7) {
        *puVar5 = puVar7;
        puVar5 = puVar5 + 1;
      }
      iVar2 = RwGetError();
      iVar4 = 0;
      puVar7 = puVar3;
      do {
        if (iVar6 == 0) break;
        uVar1 = *puVar7;
        puVar7 = puVar7 + 1;
        (*(code *)param_2)(uVar1,param_3);
        iVar4 = FUN_1000cbd0();
        iVar6 = iVar6 + -1;
      } while (iVar4 == 0);
      if (iVar4 != 0) {
        param_1 = 0;
      }
      if ((iVar2 != 0) || (iVar2 = iVar4, iVar4 != 0)) {
        FUN_1000cb60(iVar2);
      }
      (**(code **)(PTR_DAT_1005b69c + 0x358))(puVar3);
      return param_1;
    }
    FUN_1000cba0(3);
  }
  return 0;
}


