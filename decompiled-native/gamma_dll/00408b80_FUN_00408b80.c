// 00408b80 FUN_00408b80 [Global]
// program: gamma.dll

void __thiscall FUN_00408b80(void *this,uint param_1,char param_2)

{
  undefined ****ppppuVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  char *pcVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined ***local_a0;
  void *local_9c;
  undefined4 *local_98;
  undefined4 *local_94;
  uint *local_90;
  undefined **local_8c;
  int local_88 [7];
  undefined1 *local_6c;
  undefined ***local_68;
  int *local_64;
  undefined1 *local_4c;
  undefined1 *local_34;
  undefined1 *local_1c;
  undefined4 local_18;
  uint local_14;
  
  if (param_1 == 0xffffffff) {
    local_a0 = &local_8c;
    local_68 = &local_8c;
    local_8c = &PTR_FUN_0046db74;
    local_64 = local_88;
    iVar2 = FUN_00450b60(0x33);
    local_4c = (undefined1 *)&local_a0;
    *local_64 = iVar2;
    local_64[1] = 0;
    ppppuVar1 = &local_a0;
    if (*local_64 != 0) {
      puVar3 = FUN_0044e010(4);
      if (puVar3 != (uint *)0x0) {
        *puVar3 = 1;
      }
      local_64[1] = (int)puVar3;
      ppppuVar1 = (undefined ****)local_4c;
    }
    local_4c = (undefined1 *)ppppuVar1;
    pcVar6 = s_basic_string__length_error__Resi_0046d94c;
    puVar7 = (undefined4 *)*local_64;
    for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar7 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      puVar7 = puVar7 + 1;
    }
    *(undefined2 *)puVar7 = *(undefined2 *)pcVar6;
    *(char *)((int)puVar7 + 2) = pcVar6[2];
    *local_a0 = &PTR_LAB_0046db64;
    FUN_00451670();
  }
  if (1 < *(uint *)(*(int *)this + 8)) {
    local_14 = param_1;
    puVar3 = *(uint **)this;
    FUN_00406470(&local_18,puVar3 + 4);
    if (puVar3[2] < 2) {
      FUN_00404f40(&local_18);
      puVar5 = puVar3;
    }
    else {
      puVar5 = (uint *)FUN_00406450(1);
      local_1c = (undefined1 *)&local_a0;
      local_90 = puVar5;
      local_9c = (void *)FUN_00406440(0x28,puVar5);
      if (local_9c != (void *)0x0) {
        local_34 = (undefined1 *)&local_a0;
        FUN_004063e0(local_9c,puVar3 + 1,local_14);
      }
      puVar3[2] = puVar3[2] - 1;
      if (param_2 != '\0') {
        puVar4 = FUN_004063b0(&local_14,puVar3);
        FUN_00406390((undefined4 *)puVar5[3],(undefined4 *)puVar3[3],*puVar4 + 1);
        *puVar5 = *puVar3;
      }
      FUN_00404f40(&local_18);
    }
    *(uint **)this = puVar5;
  }
  puVar3 = *(uint **)this;
  uVar8 = puVar3[1];
  if (uVar8 < param_1) {
    for (; uVar8 < param_1; uVar8 = uVar8 * 2) {
    }
    if (uVar8 < *puVar3) {
      uVar8 = *puVar3;
    }
    uVar8 = (uVar8 + 3) - (uVar8 & 3);
    if (uVar8 < puVar3[1]) {
      local_94 = (undefined4 *)puVar3[3];
      local_6c = (undefined1 *)&local_a0;
      puVar5 = FUN_0044e010(uVar8 + 1);
      puVar3[3] = (uint)puVar5;
      FUN_0044df50((undefined4 *)puVar3[3],local_94,*puVar3 + 1);
      puVar7 = local_94;
    }
    else {
      if (uVar8 <= puVar3[1]) goto LAB_00408e24;
      local_98 = (undefined4 *)puVar3[3];
      puVar5 = FUN_0044e010(uVar8 + 1);
      puVar3[3] = (uint)puVar5;
      FUN_0044df50((undefined4 *)puVar3[3],local_98,*puVar3 + 1);
      puVar7 = local_98;
    }
    FUN_0044e100(puVar7);
    puVar3[1] = uVar8;
  }
LAB_00408e24:
  *(undefined1 *)(*(int *)(*(int *)this + 0xc) + param_1) = DAT_0046d948;
  **(uint **)this = param_1;
  iVar2 = *(int *)(*(int *)this + 8);
  if (iVar2 == 0) {
    iVar2 = 1;
  }
  *(int *)(*(int *)this + 8) = iVar2;
  return;
}


