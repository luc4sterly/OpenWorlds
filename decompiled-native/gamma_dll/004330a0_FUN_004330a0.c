// 004330a0 FUN_004330a0 [Global]
// programa: gamma.dll

undefined1 __thiscall FUN_004330a0(void *this,uint param_1,int param_2)

{
  uint uVar1;
  bool bVar2;
  uint *this_00;
  void *pvVar3;
  int iVar4;
  int iVar5;
  UINT UVar6;
  int iVar7;
  undefined3 extraout_var;
  void *pvVar8;
  int local_15c;
  int local_154;
  undefined1 local_150;
  undefined4 local_140;
  int local_13c;
  int local_138;
  undefined4 local_134;
  int local_130;
  int local_12c;
  undefined **local_128;
  char acStack_124 [255];
  undefined1 local_25;
  undefined4 *local_20;
  undefined4 *local_18;
  
  uVar1 = param_2 - 1;
  this_00 = FUN_0042c7f0();
  if (this_00 == (uint *)0x0) {
    return 0;
  }
  pvVar3 = (void *)FUN_0042ca00(this_00,param_1);
  if (pvVar3 == (void *)0x0) {
    return 0;
  }
  if (param_1 != *(uint *)((int)this + 0x30)) {
    *(uint *)((int)this + 0x30) = param_1;
    iVar4 = FUN_0042bd30((int)pvVar3);
    local_20 = &local_140;
    local_140 = 0;
    local_13c = 0;
    local_138 = 0;
    FUN_0042be90(local_20,*(int *)(iVar4 + 8),*(int *)(iVar4 + 4) * 0x104 + *(int *)(iVar4 + 8));
    if ((undefined4 *)((int)this + 0x24) != &local_140) {
      FUN_0042ebd0((void *)((int)this + 0x24),local_138,local_13c * 0x104 + local_138);
    }
    FUN_0042c410((int)&local_140);
    iVar4 = FUN_0042bd20((int)pvVar3);
    local_18 = &local_134;
    local_134 = 0;
    local_130 = 0;
    local_12c = 0;
    FUN_0042be90(local_18,*(int *)(iVar4 + 8),*(int *)(iVar4 + 4) * 0x104 + *(int *)(iVar4 + 8));
    if ((undefined4 *)((int)this + 0x18) != &local_134) {
      FUN_0042ebd0((void *)((int)this + 0x18),local_12c,local_130 * 0x104 + local_12c);
    }
    FUN_0042c410((int)&local_134);
  }
  iVar4 = FUN_0042bd50((int)pvVar3);
  iVar5 = FUN_0042bd40((int)pvVar3);
  if (((int)uVar1 < 0) || (*(uint *)(iVar4 + 4) <= uVar1)) {
    return 0;
  }
  UVar6 = GetPrivateProfileIntA
                    (s_Runtime_00475320,s_NoImpChange_00475314,0,s___override_ini_00475304);
  if (UVar6 == 1) {
    return 0;
  }
  iVar4 = FUN_0042bd60(pvVar3,uVar1 * 0x104 + *(int *)(iVar5 + 8));
  if (iVar4 == 0) {
    return 0;
  }
  iVar7 = FUN_0042be70(iVar4);
  local_15c = *(int *)(iVar7 + 8);
  iVar7 = FUN_0042be80(iVar4);
  local_154 = *(int *)(iVar7 + 8);
  local_150 = 0;
  iVar7 = FUN_0042be70(iVar4);
  if (local_15c != *(int *)(iVar7 + 4) * 0x104 + *(int *)(iVar7 + 8)) {
    do {
      local_128 = &PTR_LAB_00471ff8;
      FUN_0044d6d0(acStack_124,(char *)(local_15c + 4),0xff);
      local_25 = 0;
      pvVar3 = *(void **)((int)this + 0x20);
      pvVar8 = (void *)(*(int *)((int)this + 0x1c) * 0x104 + (int)pvVar3);
      for (; pvVar3 != pvVar8; pvVar3 = (void *)((int)pvVar3 + 0x104)) {
        bVar2 = FUN_00427480(pvVar3,(int)&local_128);
        if (CONCAT31(extraout_var,bVar2) != 0) break;
      }
      local_128 = &PTR_LAB_00471ff8;
      if (pvVar3 != (void *)(*(int *)(iVar5 + 4) * 0x104 + *(int *)(iVar5 + 8))) {
        iVar7 = (((int)pvVar3 - *(int *)((int)this + 0x20)) / 0x104) * 0x104 +
                *(int *)((int)this + 0x2c);
        FUN_0044d6d0((char *)(iVar7 + 4),(char *)(local_154 + 4),0xff);
        *(undefined1 *)(iVar7 + 0x103) = 0;
        local_150 = 1;
      }
      local_15c = local_15c + 0x104;
      local_154 = local_154 + 0x104;
      iVar7 = FUN_0042be70(iVar4);
    } while (local_15c != *(int *)(iVar7 + 4) * 0x104 + *(int *)(iVar7 + 8));
  }
  return local_150;
}


