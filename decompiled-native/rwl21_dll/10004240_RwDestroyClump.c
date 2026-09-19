// 10004240 RwDestroyClump [Global]
// programa: RWL21.DLL

undefined4 RwDestroyClump(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  int iVar9;
  
                    /* 0x4240  58  RwDestroyClump */
  if (param_1 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
    return 0;
  }
  iVar9 = param_1[0x5d];
  if (iVar9 != 0) {
    if (param_1 == (undefined4 *)0x0) {
      FUN_1000cba0(1);
    }
    else if (iVar9 != 0) {
      puVar1 = *(undefined4 **)(iVar9 + 0x178);
      if (param_1 == puVar1) {
        if (*(undefined4 **)(iVar9 + 0x17c) == puVar1) {
          *(undefined4 *)(iVar9 + 0x178) = 0;
          *(undefined4 *)(iVar9 + 0x17c) = 0;
        }
        else {
          iVar5 = puVar1[0x61];
          *(int *)(iVar9 + 0x178) = iVar5;
          *(undefined4 *)(iVar5 + 0x180) = 0;
        }
        puVar1[0x60] = 0;
        puVar1[0x61] = 0;
      }
      else {
        puVar2 = *(undefined4 **)(iVar9 + 0x17c);
        if (param_1 == puVar2) {
          if (puVar2 == puVar1) {
            *(undefined4 *)(iVar9 + 0x178) = 0;
            *(undefined4 *)(iVar9 + 0x17c) = 0;
          }
          else {
            iVar5 = puVar2[0x60];
            *(int *)(iVar9 + 0x17c) = iVar5;
            *(undefined4 *)(iVar5 + 0x184) = 0;
          }
          puVar2[0x60] = 0;
          puVar2[0x61] = 0;
        }
        else {
          *(undefined4 *)(param_1[0x60] + 0x184) = param_1[0x61];
          *(undefined4 *)(param_1[0x61] + 0x180) = param_1[0x60];
          param_1[0x60] = 0;
          param_1[0x61] = 0;
        }
      }
      param_1[0x5d] = 0;
      *(undefined1 *)((int)param_1 + 0x12d) = 1;
    }
  }
  puVar1 = (undefined4 *)param_1[0x5e];
  while (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)puVar1[0x61];
    RwDestroyClump(puVar1);
    puVar1 = puVar2;
  }
  if ((uint *)param_1[0x2e] != (uint *)0x0) {
    FUN_1002ba80((uint *)param_1[0x2e]);
  }
  param_1[0x2e] = param_1;
  puVar1 = (undefined4 *)param_1[0x39];
  while (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)puVar1[0xe];
    puVar1[0xd] = 0;
    RwDestroyUserDraw(puVar1);
    puVar1 = puVar2;
  }
  FUN_10032910((int)param_1);
  if (param_1 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
  }
  else {
    piVar4 = FUN_10003930((int)param_1);
    if (piVar4 != (int *)0x0) {
      piVar8 = piVar4 + 2;
      iVar9 = *piVar4;
      iVar5 = RwGetError();
      do {
        if (iVar9 == 0) {
          FUN_10020be0(piVar4);
          FUN_1000cb60(iVar5);
          goto LAB_1000442f;
        }
        piVar3 = (int *)*piVar8;
        piVar8 = piVar8 + 1;
        RwDestroyPolygon(piVar3);
        iVar6 = FUN_1000cbd0();
        iVar9 = iVar9 + -1;
      } while (iVar6 == 0);
      FUN_10020be0(piVar4);
      if (iVar5 != 0) {
        FUN_1000cb60(iVar5);
      }
    }
  }
LAB_1000442f:
  uVar7 = FUN_10020be0((undefined4 *)param_1[0x26]);
  param_1[0x26] = uVar7;
  uVar7 = FUN_10020be0((undefined4 *)param_1[0x27]);
  param_1[0x27] = uVar7;
  *(undefined4 *)param_1[0x22] = 0;
  FUN_10041d80((int *)param_1[0x22]);
  FUN_10037010(DAT_10058054,param_1);
  return 1;
}


