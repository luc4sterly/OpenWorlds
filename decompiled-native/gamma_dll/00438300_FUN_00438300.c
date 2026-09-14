// 00438300 FUN_00438300 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall FUN_00438300(void *this,undefined4 *param_1,short param_2,char param_3)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  float10 fVar4;
  undefined4 *puVar5;
  short sVar6;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined **local_130;
  float local_12c;
  float local_128;
  float local_124;
  undefined **local_120;
  float local_11c;
  float local_118;
  float local_114;
  undefined4 local_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  float local_fc;
  undefined4 local_f8 [5];
  undefined4 local_e4 [5];
  undefined4 local_d0 [5];
  undefined4 local_bc [5];
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined **local_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  undefined4 local_70 [5];
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 local_40 [5];
  int local_2c;
  undefined4 local_28;
  float local_24;
  
  local_148 = 0;
  local_150 = 0;
  local_14c = 0;
  FUN_00438a40(&local_150,*(int *)((int)this + 0xc) + 2);
  FUN_00428f10(&local_144);
  local_124 = 0.0;
  local_130 = &PTR_LAB_004732e8;
  local_128 = 0.0;
  local_12c = 0.0;
  iVar1 = FUN_00436230((int)this + 0x14);
  if (2 < iVar1) {
    local_120 = &PTR_LAB_004732e8;
    local_114 = 0.0;
    local_11c = 0.0;
    local_118 = 0.0;
    pvVar2 = (void *)FUN_00436240((void *)((int)this + 0x14),0);
    FUN_00435a10(pvVar2,local_f8,param_2);
    fVar4 = FUN_00429040((int)local_f8);
    local_11c = (float)fVar4;
    FUN_00428e50(local_f8);
    pvVar2 = (void *)FUN_00436240((void *)((int)this + 0x14),1);
    FUN_00435a10(pvVar2,local_e4,param_2);
    fVar4 = FUN_00429040((int)local_e4);
    local_118 = (float)fVar4;
    FUN_00428e50(local_e4);
    pvVar2 = (void *)FUN_00436240((void *)((int)this + 0x14),2);
    FUN_00435a10(pvVar2,local_d0,param_2);
    fVar4 = FUN_00429040((int)local_d0);
    local_114 = (float)fVar4;
    FUN_00428e50(local_d0);
    local_12c = local_12c + local_11c;
    local_128 = local_128 + local_118;
    local_124 = local_124 + local_114;
    iVar1 = FUN_00436230((int)this + 0x14);
    if (3 < iVar1) {
      puVar5 = local_bc;
      sVar6 = param_2;
      pvVar2 = (void *)FUN_00436240((void *)((int)this + 0x14),3);
      FUN_00435a10(pvVar2,puVar5,sVar6);
      FUN_00428e20(&local_144,(int)local_bc);
      FUN_00428e50(local_bc);
    }
    local_120 = &PTR_LAB_004732e8;
  }
  iVar1 = FUN_00436230((int)this + 0x14);
  if (0 < iVar1) {
    FUN_004290c0((int)&local_144);
    local_a4 = 1;
    local_a8 = 1;
    local_a0 = local_144;
    uStack_9c = uStack_140;
    uStack_98 = uStack_13c;
    uStack_94 = uStack_138;
    uStack_90 = uStack_134;
    FUN_004389d0(&local_150,&local_a8);
    if (param_3 == '\0') {
      local_124 = 0.0;
    }
    else {
      local_124 = _DAT_00475fec * local_124;
    }
    local_88 = 2;
    local_8c = 2;
    local_84 = local_130;
    fStack_80 = local_12c;
    fStack_7c = local_128;
    fStack_78 = local_124;
    FUN_004389d0(&local_150,&local_8c);
  }
  for (piVar3 = *(int **)((int)this + 0x10);
      piVar3 != (int *)(*(int *)((int)this + 0xc) * 8 + *(int *)((int)this + 0x10));
      piVar3 = piVar3 + 2) {
    pvVar2 = (void *)FUN_004361e0((void *)((int)this + 0x14),*piVar3);
    if (*(int *)((int)pvVar2 + 0x10) == 0x10) {
      FUN_00435a10(pvVar2,local_70,param_2);
      FUN_00428df0(&local_110,(int)local_70);
      FUN_00428e50(local_70);
      FUN_004290c0((int)&local_110);
      if (*(char *)((int)pvVar2 + 0x10) == '\x04') {
        local_58 = 3;
      }
      else if (*(char *)((int)pvVar2 + 0x10) == '\x10') {
        local_58 = 6;
      }
      else {
        local_58 = 0;
      }
      local_5c = piVar3[1];
      local_54 = local_110;
      uStack_50 = uStack_10c;
      uStack_4c = uStack_108;
      uStack_48 = uStack_104;
      uStack_44 = uStack_100;
      FUN_004389d0(&local_150,&local_5c);
      FUN_00428e50(&local_110);
    }
    else {
      FUN_00435a10(pvVar2,local_40,param_2);
      fVar4 = FUN_00429040((int)local_40);
      local_fc = (float)fVar4;
      FUN_00428e50(local_40);
      if (*(char *)((int)pvVar2 + 0x10) == '\x04') {
        local_28 = 3;
      }
      else if (*(char *)((int)pvVar2 + 0x10) == '\x10') {
        local_28 = 6;
      }
      else {
        local_28 = 0;
      }
      local_2c = piVar3[1];
      local_24 = local_fc;
      FUN_004389d0(&local_150,&local_2c);
    }
  }
  FUN_0043bc80(param_1,(int)&local_150);
  local_130 = &PTR_LAB_004732e8;
  FUN_00428e50(&local_144);
  FUN_00438c50((int)&local_150);
  return param_1;
}


