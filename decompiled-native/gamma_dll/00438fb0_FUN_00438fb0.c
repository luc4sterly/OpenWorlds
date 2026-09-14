// 00438fb0 FUN_00438fb0 [Global]
// programa: gamma.dll

undefined4 * __cdecl FUN_00438fb0(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  if (param_1 == param_2) {
    return param_1;
  }
  iVar2 = *(int *)(*(int *)(param_3 + 4) + 4);
  puVar7 = param_2 + -2;
  if (((int)param_1[1] <= iVar2) && ((int)param_2[-1] > iVar2)) {
    puVar6 = param_1 + 2;
    while( true ) {
      while( true ) {
        iVar2 = puVar6[1];
        iVar3 = *(int *)(*(int *)(param_3 + 4) + 4);
        if (iVar3 < iVar2) break;
        puVar6 = puVar6 + 2;
      }
      do {
        puVar8 = puVar7;
        puVar7 = puVar8 + -2;
      } while (iVar3 < (int)puVar8[-1]);
      if (puVar7 <= puVar6) break;
      uVar4 = *puVar6;
      *puVar6 = *puVar7;
      puVar6[1] = puVar8[-1];
      *puVar7 = uVar4;
      puVar6 = puVar6 + 2;
      puVar8[-1] = iVar2;
    }
    return puVar6;
  }
  if ((int)param_2[-1] <= iVar2) {
    puVar6 = param_1;
    if ((int)param_1[1] <= iVar2) {
      do {
        param_1 = puVar6 + 2;
        if (param_1 == param_2) break;
        piVar1 = puVar6 + 3;
        puVar6 = param_1;
      } while (*piVar1 <= iVar2);
      if (param_1 == param_2) {
        return param_1;
      }
      puVar7 = param_2 + -2;
    }
  }
  else {
    puVar6 = puVar7;
    if (param_1 == puVar7) {
      return param_1;
    }
    do {
      puVar7 = puVar6 + -2;
      if (param_1 == puVar7) break;
      piVar1 = puVar6 + -1;
      puVar6 = puVar7;
    } while (iVar2 < *piVar1);
    if (param_1 == puVar7) {
      return param_1;
    }
  }
  uVar4 = *param_1;
  uVar5 = param_1[1];
  *param_1 = *puVar7;
  param_1[1] = puVar7[1];
  puVar6 = param_1 + 2;
  *puVar7 = uVar4;
  puVar7[1] = uVar5;
  while( true ) {
    while( true ) {
      iVar2 = puVar6[1];
      iVar3 = *(int *)(*(int *)(param_3 + 4) + 4);
      if (iVar3 < iVar2) break;
      puVar6 = puVar6 + 2;
    }
    do {
      puVar8 = puVar7;
      puVar7 = puVar8 + -2;
    } while (iVar3 < (int)puVar8[-1]);
    if (puVar7 <= puVar6) break;
    uVar4 = *puVar6;
    *puVar6 = *puVar7;
    puVar6[1] = puVar8[-1];
    *puVar7 = uVar4;
    puVar6 = puVar6 + 2;
    puVar8[-1] = iVar2;
  }
  return puVar6;
}


