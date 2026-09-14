// 00438dd0 FUN_00438dd0 [Global]
// programa: gamma.dll

undefined4 * __cdecl FUN_00438dd0(undefined4 *param_1,undefined4 *param_2,int param_3)

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
  puVar8 = param_2 + -2;
  if (((int)param_1[1] < iVar2) && (iVar2 <= (int)param_2[-1])) {
    puVar6 = param_1 + 2;
    while( true ) {
      while( true ) {
        iVar2 = puVar6[1];
        iVar3 = *(int *)(*(int *)(param_3 + 4) + 4);
        if (iVar3 <= iVar2) break;
        puVar6 = puVar6 + 2;
      }
      do {
        puVar7 = puVar8;
        puVar8 = puVar7 + -2;
      } while (iVar3 <= (int)puVar7[-1]);
      if (puVar8 <= puVar6) break;
      uVar4 = *puVar6;
      *puVar6 = *puVar8;
      puVar6[1] = puVar7[-1];
      puVar6 = puVar6 + 2;
      *puVar8 = uVar4;
      puVar7[-1] = iVar2;
    }
    return puVar6;
  }
  puVar6 = param_1;
  if (iVar2 <= (int)param_2[-1]) {
    puVar7 = puVar8;
    if (param_1 == puVar8) {
      return param_1;
    }
    do {
      puVar8 = puVar7 + -2;
      if (param_1 == puVar8) break;
      piVar1 = puVar7 + -1;
      puVar7 = puVar8;
    } while (iVar2 <= *piVar1);
    if (param_1 == puVar8) {
      return param_1;
    }
  }
  else if ((int)param_1[1] < iVar2) {
    do {
      puVar6 = param_1 + 2;
      if (puVar6 == param_2) break;
      piVar1 = param_1 + 3;
      param_1 = puVar6;
    } while (*piVar1 < iVar2);
    if (puVar6 == param_2) {
      return puVar6;
    }
    puVar8 = param_2 + -2;
  }
  uVar4 = *puVar6;
  uVar5 = puVar6[1];
  *puVar6 = *puVar8;
  puVar6[1] = puVar8[1];
  puVar6 = puVar6 + 2;
  *puVar8 = uVar4;
  puVar8[1] = uVar5;
  while( true ) {
    while( true ) {
      iVar2 = puVar6[1];
      iVar3 = *(int *)(*(int *)(param_3 + 4) + 4);
      if (iVar3 <= iVar2) break;
      puVar6 = puVar6 + 2;
    }
    do {
      puVar7 = puVar8;
      puVar8 = puVar7 + -2;
    } while (iVar3 <= (int)puVar7[-1]);
    if (puVar8 <= puVar6) break;
    uVar4 = *puVar6;
    *puVar6 = *puVar8;
    puVar6[1] = puVar7[-1];
    puVar6 = puVar6 + 2;
    *puVar8 = uVar4;
    puVar7[-1] = iVar2;
  }
  return puVar6;
}


