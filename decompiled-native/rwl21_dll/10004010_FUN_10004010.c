// 10004010 FUN_10004010 [Global]
// programa: RWL21.DLL

void FUN_10004010(undefined4 *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  int iVar9;
  
  if ((uint *)param_1[0x2e] != (uint *)0x0) {
    FUN_1002ba80((uint *)param_1[0x2e]);
  }
  param_1[0x2e] = param_1;
  puVar3 = (undefined4 *)param_1[0x39];
  while (puVar3 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)puVar3[0xe];
    puVar3[0xd] = 0;
    RwDestroyUserDraw(puVar3);
    puVar3 = puVar1;
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
          goto LAB_100040cb;
        }
        piVar2 = (int *)*piVar8;
        piVar8 = piVar8 + 1;
        RwDestroyPolygon(piVar2);
        iVar6 = FUN_1000cbd0();
        iVar9 = iVar9 + -1;
      } while (iVar6 == 0);
      FUN_10020be0(piVar4);
      if (iVar5 != 0) {
        FUN_1000cb60(iVar5);
      }
    }
  }
LAB_100040cb:
  uVar7 = FUN_10020be0((undefined4 *)param_1[0x26]);
  param_1[0x26] = uVar7;
  uVar7 = FUN_10020be0((undefined4 *)param_1[0x27]);
  param_1[0x27] = uVar7;
  *(undefined4 *)param_1[0x22] = 0;
  FUN_10041d80((int *)param_1[0x22]);
  FUN_10037010(DAT_10058054,param_1);
  return;
}


