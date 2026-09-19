// 1002c410 FUN_1002c410 [Global]
// programa: RWL21.DLL

undefined4 * FUN_1002c410(undefined4 *param_1)

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
  
  iVar1 = param_1[0x23];
  if (iVar1 == 0) {
    return param_1;
  }
  if (param_1[0x21] == 1) {
    puVar2 = *(undefined4 **)(iVar1 + 0x10);
    puVar7 = puVar2;
    puVar4 = puVar2;
    while ((puVar3 = puVar7, puVar3 != (undefined4 *)0x0 && (param_1 != puVar3))) {
      puVar4 = puVar3;
      puVar7 = (undefined4 *)*puVar3;
    }
    if (puVar3 != (undefined4 *)0x0) {
      if (puVar2 == puVar3) {
        *(undefined4 *)(iVar1 + 0x10) = *puVar2;
        goto LAB_1002c4a6;
      }
      *puVar4 = *puVar3;
    }
    *(undefined4 **)(iVar1 + 0x10) = puVar2;
  }
  else if (param_1[0x21] == 2) {
    piVar9 = *(int **)(iVar1 + 0x14);
    piVar8 = piVar9;
    piVar6 = piVar9;
    while ((piVar5 = piVar8, piVar5 != (int *)0x0 && (piVar5 != param_1))) {
      piVar6 = piVar5;
      piVar8 = (int *)*piVar5;
    }
    if (piVar5 != (int *)0x0) {
      if (piVar5 == piVar9) {
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
LAB_1002c4a6:
  param_1[0x23] = 0;
  return param_1;
}


