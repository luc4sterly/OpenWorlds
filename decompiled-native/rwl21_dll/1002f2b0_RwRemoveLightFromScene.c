// 1002f2b0 RwRemoveLightFromScene [Global]
// programa: RWL21.DLL

undefined4 * RwRemoveLightFromScene(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  
                    /* 0x2f2b0  337  RwRemoveLightFromScene */
  if (param_1 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
    return (undefined4 *)0x0;
  }
  if (param_1[0x23] == DAT_1005adb0) {
    param_1 = (undefined4 *)0x0;
  }
  if (param_1 == (undefined4 *)0x0) {
    FUN_1000cba0(0x1a);
    return (undefined4 *)0x0;
  }
  iVar6 = param_1[0x23];
  if (iVar6 != 0) {
    if (param_1[0x21] == 1) {
      puVar5 = *(undefined4 **)(iVar6 + 0x10);
      puVar4 = puVar5;
      puVar3 = puVar5;
      while ((puVar2 = puVar4, puVar2 != (undefined4 *)0x0 && (param_1 != puVar2))) {
        puVar3 = puVar2;
        puVar4 = (undefined4 *)*puVar2;
      }
      if (puVar2 != (undefined4 *)0x0) {
        if (puVar5 == puVar2) {
          *(undefined4 *)(iVar6 + 0x10) = *puVar5;
          goto LAB_1002f368;
        }
        *puVar3 = *puVar2;
      }
      *(undefined4 **)(iVar6 + 0x10) = puVar5;
    }
    else if (param_1[0x21] == 2) {
      puVar5 = *(undefined4 **)(iVar6 + 0x14);
      puVar4 = puVar5;
      puVar3 = puVar5;
      while ((puVar2 = puVar4, puVar2 != (undefined4 *)0x0 && (puVar2 != param_1))) {
        puVar3 = puVar2;
        puVar4 = (undefined4 *)*puVar2;
      }
      if (puVar2 != (undefined4 *)0x0) {
        if (puVar2 == puVar5) {
          puVar5 = (undefined4 *)*puVar5;
        }
        else {
          *puVar3 = *puVar2;
        }
      }
      *(undefined4 **)(iVar6 + 0x14) = puVar5;
      if (iVar6 == 0) {
        FUN_1000cba0(1);
      }
      else {
        *(int *)(iVar6 + 0x18) = *(int *)(iVar6 + 0x18) + 1;
      }
    }
LAB_1002f368:
    param_1[0x23] = 0;
  }
  if ((DAT_1005adb0 == 0) || (iVar6 = DAT_1005adb0, param_1 == (undefined4 *)0x0)) {
    iVar6 = 0;
  }
  if (iVar6 == 0) {
    FUN_1000cba0(1);
    return param_1;
  }
  iVar1 = param_1[0x23];
  if (iVar1 == 0) goto LAB_1002f424;
  if (param_1[0x21] == 1) {
    puVar5 = *(undefined4 **)(iVar1 + 0x10);
    puVar4 = puVar5;
    puVar3 = puVar5;
    while ((puVar2 = puVar4, puVar2 != (undefined4 *)0x0 && (puVar2 != param_1))) {
      puVar3 = puVar2;
      puVar4 = (undefined4 *)*puVar2;
    }
    if (puVar2 != (undefined4 *)0x0) {
      if (puVar2 == puVar5) {
        *(undefined4 *)(iVar1 + 0x10) = *puVar5;
        goto LAB_1002f41a;
      }
      *puVar3 = *puVar2;
    }
    *(undefined4 **)(iVar1 + 0x10) = puVar5;
  }
  else if (param_1[0x21] == 2) {
    puVar5 = *(undefined4 **)(iVar1 + 0x14);
    puVar4 = puVar5;
    puVar3 = puVar5;
    while ((puVar2 = puVar4, puVar2 != (undefined4 *)0x0 && (param_1 != puVar2))) {
      puVar3 = puVar2;
      puVar4 = (undefined4 *)*puVar2;
    }
    if (puVar2 != (undefined4 *)0x0) {
      if (puVar2 == puVar5) {
        puVar5 = (undefined4 *)*puVar5;
      }
      else {
        *puVar3 = *puVar2;
      }
    }
    *(undefined4 **)(iVar1 + 0x14) = puVar5;
    if (iVar1 == 0) {
      FUN_1000cba0(1);
    }
    else {
      *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
    }
  }
LAB_1002f41a:
  param_1[0x23] = 0;
LAB_1002f424:
  param_1[0x23] = iVar6;
  if (param_1[0x21] == 1) {
    *param_1 = *(undefined4 *)(iVar6 + 0x10);
    *(undefined4 **)(iVar6 + 0x10) = param_1;
    return param_1;
  }
  if (param_1[0x21] != 2) {
    return param_1;
  }
  *param_1 = *(undefined4 *)(iVar6 + 0x14);
  *(undefined4 **)(iVar6 + 0x14) = param_1;
  if (iVar6 != 0) {
    *(int *)(iVar6 + 0x18) = *(int *)(iVar6 + 0x18) + 1;
    return param_1;
  }
  FUN_1000cba0(1);
  return param_1;
}


