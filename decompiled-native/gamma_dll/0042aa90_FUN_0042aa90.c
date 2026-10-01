// 0042aa90 FUN_0042aa90 [Global]
// program: gamma.dll

undefined4 __fastcall FUN_0042aa90(int *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined4 uVar9;
  
  puVar6 = *(undefined1 **)(param_1[10] + 4);
  puVar7 = (undefined1 *)param_1[1];
  if (puVar6 + param_1[0xc] + 1 < (undefined1 *)param_1[0xd]) {
    (**(code **)(*param_1 + 0x24))(s_fatal_flex_scanner_internal_erro_00474290);
  }
  if (*(int *)(param_1[10] + 0x20) == 0) {
    if (param_1[0xd] - param_1[1] == 1) {
      return 1;
    }
    return 2;
  }
  iVar5 = 0;
  iVar8 = param_1[0xd];
  iVar4 = param_1[1];
  iVar2 = (iVar8 - iVar4) + -1;
  if (0 < iVar2) {
    if (8 < iVar2) {
      do {
        iVar5 = iVar5 + 8;
        *puVar6 = *puVar7;
        puVar6[1] = puVar7[1];
        puVar6[2] = puVar7[2];
        puVar6[3] = puVar7[3];
        puVar6[4] = puVar7[4];
        puVar6[5] = puVar7[5];
        puVar6[6] = puVar7[6];
        puVar1 = puVar7 + 7;
        puVar7 = puVar7 + 8;
        puVar6[7] = *puVar1;
        puVar6 = puVar6 + 8;
      } while (iVar5 < (iVar8 - iVar4) + -9);
    }
    for (; iVar5 < iVar2; iVar5 = iVar5 + 1) {
      uVar3 = *puVar7;
      puVar7 = puVar7 + 1;
      *puVar6 = uVar3;
      puVar6 = puVar6 + 1;
    }
  }
  if (*(int *)(param_1[10] + 0x24) == 2) {
    param_1[0xc] = 0;
  }
  else {
    iVar8 = (*(int *)(param_1[10] + 0xc) - iVar2) + -1;
    while (iVar8 < 1) {
      (**(code **)(*param_1 + 0x24))(s_input_buffer_overflow__can_t_enl_004742c8);
    }
    if (0x2000 < iVar8) {
      iVar8 = 0x2000;
    }
    iVar8 = (**(code **)(*param_1 + 0x1c))(*(int *)(param_1[10] + 4) + iVar2,iVar8);
    param_1[0xc] = iVar8;
    if (param_1[0xc] < 0) {
      (**(code **)(*param_1 + 0x24))(s_input_in_flex_scanner_failed_00474310);
    }
  }
  *(int *)(param_1[10] + 0x10) = param_1[0xc];
  if (param_1[0xc] == 0) {
    if (iVar2 == 0) {
      uVar9 = 1;
      (**(code **)(*param_1 + 0x10))(param_1[8]);
    }
    else {
      uVar9 = 2;
      *(undefined4 *)(param_1[10] + 0x24) = 2;
    }
  }
  else {
    uVar9 = 0;
  }
  param_1[0xc] = param_1[0xc] + iVar2;
  *(undefined1 *)(*(int *)(param_1[10] + 4) + param_1[0xc]) = 0;
  *(undefined1 *)(*(int *)(param_1[10] + 4) + 1 + param_1[0xc]) = 0;
  param_1[1] = *(int *)(param_1[10] + 4);
  return uVar9;
}


