// 00408f50 FUN_00408f50 [Global]
// program: gamma.dll

int * __thiscall FUN_00408f50(void *this,uint param_1,uint param_2,int param_3,undefined1 param_4)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  int **ppiVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  char *pcVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined1 *puVar9;
  int *local_a8 [2];
  uint local_a0;
  undefined **local_9c;
  int local_98 [2];
  undefined **local_90;
  int local_8c [7];
  undefined1 *local_70;
  uint local_6c [6];
  undefined1 *local_54;
  undefined ***local_50;
  undefined ***local_4c;
  int *local_48;
  int *local_44;
  undefined1 *local_2c;
  undefined1 *local_14;
  
  local_a8[0] = this;
  if (**(uint **)this < param_1) {
    local_50 = &local_9c;
    local_9c = &PTR_FUN_0046db74;
    local_48 = local_98;
    iVar3 = FUN_00450b60(0x27);
    local_2c = (undefined1 *)local_a8;
    *local_48 = iVar3;
    local_48[1] = 0;
    ppiVar2 = local_a8;
    if (*local_48 != 0) {
      puVar4 = FUN_0044e010(4);
      if (puVar4 != (uint *)0x0) {
        *puVar4 = 1;
      }
      local_48[1] = (int)puVar4;
      ppiVar2 = (int **)local_2c;
    }
    local_2c = (undefined1 *)ppiVar2;
    pcVar6 = s_basic_string__replace_pos_out_of_0046d9b8;
    puVar8 = (undefined4 *)*local_48;
    for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar8 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      puVar8 = puVar8 + 1;
    }
    *(undefined2 *)puVar8 = *(undefined2 *)pcVar6;
    *(char *)((int)puVar8 + 2) = pcVar6[2];
    local_9c = &PTR_LAB_0046db54;
    FUN_00451670();
  }
  local_6c[0] = *(int *)*local_a8[0] - param_1;
  if (*(int *)*local_a8[0] - param_1 < param_2) {
    puVar4 = local_6c;
  }
  else {
    puVar4 = &param_2;
  }
  local_a0 = *puVar4;
  if ((param_3 == -1) || (-param_3 - 2U < *(int *)*local_a8[0] - local_a0)) {
    local_4c = &local_90;
    local_90 = &PTR_FUN_0046db74;
    local_44 = local_8c;
    iVar3 = FUN_00450b60(0x23);
    local_14 = (undefined1 *)local_a8;
    *local_44 = iVar3;
    local_44[1] = 0;
    ppiVar2 = local_a8;
    if (*local_44 != 0) {
      puVar4 = FUN_0044e010(4);
      if (puVar4 != (uint *)0x0) {
        *puVar4 = 1;
      }
      local_44[1] = (int)puVar4;
      ppiVar2 = (int **)local_14;
    }
    local_14 = (undefined1 *)ppiVar2;
    pcVar6 = s_basic_string__replace_length_err_0046da18;
    puVar8 = (undefined4 *)*local_44;
    for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar8 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      puVar8 = puVar8 + 1;
    }
    *(undefined2 *)puVar8 = *(undefined2 *)pcVar6;
    *(char *)((int)puVar8 + 2) = pcVar6[2];
    local_90 = &PTR_LAB_0046db64;
    FUN_00451670();
  }
  piVar1 = (int *)*local_a8[0];
  uVar7 = (*piVar1 - local_a0) + param_3;
  if (((uint)piVar1[2] < 2) && (uVar7 <= (uint)piVar1[1])) {
    FUN_0044ded0((undefined4 *)(piVar1[3] + param_1 + param_3),
                 (undefined4 *)(piVar1[3] + param_1 + local_a0),*piVar1 - (param_1 + local_a0));
    if (param_3 != 0) {
      puVar9 = (undefined1 *)(*(int *)(*local_a8[0] + 0xc) + param_1);
      for (; param_3 != 0; param_3 = param_3 + -1) {
        *puVar9 = param_4;
        puVar9 = puVar9 + 1;
      }
    }
    *(undefined1 *)(*(int *)(*local_a8[0] + 0xc) + uVar7) = DAT_0046d944;
    *(uint *)*local_a8[0] = uVar7;
  }
  else {
    puVar4 = FUN_0044e010(0x28);
    local_70 = (undefined1 *)local_a8;
    ppiVar2 = local_a8;
    if (puVar4 != (uint *)0x0) {
      puVar4[1] = (uVar7 + 3) - (uVar7 & 3);
      puVar4[2] = 1;
      local_54 = (undefined1 *)local_a8;
      puVar5 = FUN_0044e010(puVar4[1] + 1);
      puVar4[3] = (uint)puVar5;
      InitializeCriticalSection((LPCRITICAL_SECTION)(puVar4 + 4));
      ppiVar2 = (int **)local_70;
    }
    local_70 = (undefined1 *)ppiVar2;
    FUN_0044df50((undefined4 *)puVar4[3],*(undefined4 **)(*local_a8[0] + 0xc),param_1);
    if (param_3 != 0) {
      puVar9 = (undefined1 *)(puVar4[3] + param_1);
      for (iVar3 = param_3; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar9 = param_4;
        puVar9 = puVar9 + 1;
      }
    }
    FUN_0044df50((undefined4 *)(puVar4[3] + param_1 + param_3),
                 (undefined4 *)(((int *)*local_a8[0])[3] + param_1 + local_a0),
                 *(int *)*local_a8[0] - (param_1 + local_a0));
    *(undefined1 *)(puVar4[3] + uVar7) = DAT_0046d940;
    *puVar4 = uVar7;
    iVar3 = *local_a8[0];
    lpCriticalSection = (LPCRITICAL_SECTION)(iVar3 + 0x10);
    EnterCriticalSection(lpCriticalSection);
    if (*(int *)(iVar3 + 8) == 0) {
      *(undefined4 *)(iVar3 + 8) = 1;
    }
    *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + -1;
    if (*(int *)(iVar3 + 8) != 0) {
      iVar3 = 0;
    }
    LeaveCriticalSection(lpCriticalSection);
    *local_a8[0] = iVar3;
    iVar3 = *local_a8[0];
    if (iVar3 != 0) {
      FUN_0044e100(*(undefined4 **)(iVar3 + 0xc));
      DeleteCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x10));
      FUN_0044e100((undefined4 *)*local_a8[0]);
    }
    *local_a8[0] = (int)puVar4;
  }
  return local_a8[0];
}


