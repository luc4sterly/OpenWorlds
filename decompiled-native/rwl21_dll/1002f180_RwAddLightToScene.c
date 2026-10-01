// 1002f180 RwAddLightToScene [Global]
// program: RWL21.DLL

int RwAddLightToScene(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  int *piVar8;
  int *piVar9;
  
                    /* 0x2f180  6  RwAddLightToScene */
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    param_1 = 0;
  }
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  iVar1 = param_2[0x23];
  if (iVar1 == 0) goto LAB_1002f237;
  if (param_2[0x21] == 1) {
    puVar2 = *(undefined4 **)(iVar1 + 0x10);
    puVar7 = puVar2;
    puVar4 = puVar2;
    while ((puVar3 = puVar7, puVar3 != (undefined4 *)0x0 && (param_2 != puVar3))) {
      puVar4 = puVar3;
      puVar7 = (undefined4 *)*puVar3;
    }
    if (puVar3 != (undefined4 *)0x0) {
      if (puVar3 == puVar2) {
        *(undefined4 *)(iVar1 + 0x10) = *puVar2;
        goto LAB_1002f22d;
      }
      *puVar4 = *puVar3;
    }
    *(undefined4 **)(iVar1 + 0x10) = puVar2;
  }
  else if (param_2[0x21] == 2) {
    piVar9 = *(int **)(iVar1 + 0x14);
    piVar8 = piVar9;
    piVar6 = piVar9;
    while ((piVar5 = piVar8, piVar5 != (int *)0x0 && (param_2 != piVar5))) {
      piVar6 = piVar5;
      piVar8 = (int *)*piVar5;
    }
    if (piVar5 != (int *)0x0) {
      if (piVar9 == piVar5) {
        piVar9 = (int *)*piVar9;
      }
      else {
        *piVar6 = *piVar5;
      }
    }
    *(int **)(iVar1 + 0x14) = piVar9;
    if (iVar1 == 0) {
      FUN_1000cba0(1);
    }
    else {
      *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
    }
  }
LAB_1002f22d:
  param_2[0x23] = 0;
LAB_1002f237:
  param_2[0x23] = param_1;
  if (param_2[0x21] == 1) {
    *param_2 = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 **)(param_1 + 0x10) = param_2;
    return param_1;
  }
  if (param_2[0x21] != 2) {
    return param_1;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 **)(param_1 + 0x14) = param_2;
  if (param_1 != 0) {
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


