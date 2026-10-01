// 004093a0 FUN_004093a0 [Global]
// program: gamma.dll

int * __thiscall FUN_004093a0(void *this,int *param_1,uint param_2,uint param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint uVar1;
  undefined1 *puVar2;
  bool bVar3;
  int iVar4;
  uint *puVar5;
  char *pcVar6;
  undefined4 *puVar7;
  uint *puVar8;
  undefined1 auStack_68 [4];
  undefined ***local_64;
  undefined **local_5c;
  int local_58 [2];
  uint local_50;
  undefined ***local_4c;
  int *local_48;
  undefined1 *local_30;
  undefined1 *local_18;
  undefined4 local_14;
  
  if (*(uint *)*param_1 < param_2) {
    local_64 = &local_5c;
    local_4c = &local_5c;
    local_5c = &PTR_FUN_0046db74;
    local_48 = local_58;
    iVar4 = FUN_00450b60(0x26);
    local_30 = auStack_68;
    *local_48 = iVar4;
    local_48[1] = 0;
    puVar2 = auStack_68;
    if (*local_48 != 0) {
      puVar5 = FUN_0044e010(4);
      if (puVar5 != (uint *)0x0) {
        *puVar5 = 1;
      }
      local_48[1] = (int)puVar5;
      puVar2 = local_30;
    }
    local_30 = puVar2;
    pcVar6 = s_basic_string__append_pos_out_of_r_0046da3c;
    puVar7 = (undefined4 *)*local_48;
    for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      puVar7 = puVar7 + 1;
    }
    *(undefined2 *)puVar7 = *(undefined2 *)pcVar6;
    *local_64 = &PTR_LAB_0046db54;
    FUN_00451670();
  }
  local_50 = *(int *)*param_1 - param_2;
  if (*(int *)*param_1 - param_2 < param_3) {
    puVar5 = &local_50;
  }
  else {
    puVar5 = &param_3;
  }
  uVar1 = *puVar5;
  puVar5 = (uint *)*param_1;
  if ((uVar1 == *puVar5) && (puVar5[2] != 0)) {
    puVar8 = *(uint **)this;
    if (puVar8 == puVar5) {
      return this;
    }
    lpCriticalSection = (LPCRITICAL_SECTION)(puVar8 + 4);
    EnterCriticalSection(lpCriticalSection);
    if (puVar8[2] == 0) {
      puVar8[2] = 1;
    }
    puVar8[2] = puVar8[2] - 1;
    if (puVar8[2] != 0) {
      puVar8 = (uint *)0x0;
    }
    LeaveCriticalSection(lpCriticalSection);
    *(uint **)this = puVar8;
    iVar4 = *(int *)this;
    if (iVar4 != 0) {
      FUN_0044e100(*(undefined4 **)(iVar4 + 0xc));
      DeleteCriticalSection((LPCRITICAL_SECTION)(iVar4 + 0x10));
      FUN_0044e100(*(undefined4 **)this);
    }
    puVar5 = (uint *)*param_1;
    FUN_00406470(&local_14,puVar5 + 4);
    bVar3 = FUN_004065c0((int)puVar5);
    if (bVar3) {
      puVar5[2] = puVar5[2] + 1;
      FUN_00404f40(&local_14);
      puVar8 = puVar5;
    }
    else {
      puVar8 = (uint *)FUN_00406450(1);
      local_18 = auStack_68;
      FUN_00406530(puVar8,puVar5);
      FUN_00404f40(&local_14);
    }
    *(uint **)this = puVar8;
  }
  else if (this == param_1) {
    FUN_00408f50(this,0,param_2,0,0);
    FUN_00408b80(this,uVar1,'\x01');
  }
  else {
    FUN_00408b80(this,uVar1,'\0');
    FUN_0044df50(*(undefined4 **)(*(int *)this + 0xc),
                 (undefined4 *)(*(int *)(*param_1 + 0xc) + param_2),uVar1);
  }
  return this;
}


