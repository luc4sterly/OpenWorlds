// 00428120 FUN_00428120 [Global]
// programa: gamma.dll

int __thiscall FUN_00428120(void *this,float param_1)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  uint *puVar5;
  undefined1 auStack_c0 [4];
  undefined1 local_bc;
  char local_b8;
  char local_b7;
  void *local_b6;
  undefined1 *local_9c;
  undefined1 *local_84;
  int local_80 [2];
  int local_78;
  undefined4 local_74;
  undefined1 local_6d;
  undefined **local_54;
  int local_50 [2];
  undefined ***local_48;
  int *local_44;
  undefined1 *local_2c;
  undefined1 *local_14;
  
  local_14 = auStack_c0;
  local_b8 = '\0';
  local_b7 = '\0';
  local_b6 = this;
  bVar2 = FUN_00403760(*(int *)((int)this + 4));
  if (bVar2) {
    iVar3 = FUN_00403750(*(int *)((int)local_b6 + 4));
    if (iVar3 != 0) {
      iVar3 = FUN_00403750(*(int *)((int)local_b6 + 4));
      FUN_00403ac0(iVar3);
    }
    bVar2 = FUN_00403760(*(int *)((int)local_b6 + 4));
    if (bVar2) {
      local_b8 = '\x01';
    }
    else {
      FUN_004036b0(*(void **)((int)local_b6 + 4),4);
    }
  }
  else {
    FUN_004036b0(*(void **)((int)local_b6 + 4),4);
  }
  local_9c = auStack_c0;
  if (local_b8 != '\0') {
    local_9c = auStack_c0;
    local_84 = auStack_c0;
    FUN_004049b0(*(void **)((int)this + 4),local_80);
    local_6d = DAT_0049db4e;
    piVar4 = (int *)FUN_00405d40(local_80);
    FUN_00404dc0(local_80);
    iVar3 = *(int *)((int)this + 4);
    local_74 = *(undefined4 *)(iVar3 + 0x24);
    (**(code **)(*piVar4 + 0x18))
              (&local_78,local_74,iVar3,*(undefined1 *)(iVar3 + 0x38),(double)param_1);
    local_bc = local_78 == 0;
    if ((bool)local_bc) {
      iVar3 = *(int *)((int)this + 4);
      *(byte *)(iVar3 + 0x32) = *(byte *)(iVar3 + 0x32) | 5;
      if (*(int *)(iVar3 + 0x24) == 0) {
        *(byte *)(iVar3 + 0x32) = *(byte *)(iVar3 + 0x32) | 1;
      }
      if ((*(byte *)(iVar3 + 0x33) & *(byte *)(iVar3 + 0x32)) != 0) {
        local_48 = &local_54;
        local_54 = &PTR_LAB_0046d4fc;
        local_44 = local_50;
        iVar3 = FUN_00450b60(0x1a);
        *local_44 = iVar3;
        local_44[1] = 0;
        local_2c = auStack_c0;
        if (*local_44 != 0) {
          local_2c = auStack_c0;
          puVar5 = FUN_0044e010(4);
          if (puVar5 != (uint *)0x0) {
            *puVar5 = 1;
          }
          local_44[1] = (int)puVar5;
        }
        pcVar1 = (char *)*local_44;
        *(undefined4 *)pcVar1 = s_ios_base_failure_in_clear_00472f2c._0_4_;
        *(undefined4 *)(pcVar1 + 4) = s_ios_base_failure_in_clear_00472f2c._4_4_;
        *(undefined4 *)(pcVar1 + 8) = s_ios_base_failure_in_clear_00472f2c._8_4_;
        *(undefined4 *)(pcVar1 + 0xc) = s_ios_base_failure_in_clear_00472f2c._12_4_;
        *(undefined4 *)(pcVar1 + 0x10) = s_ios_base_failure_in_clear_00472f2c._16_4_;
        *(undefined4 *)(pcVar1 + 0x14) = s_ios_base_failure_in_clear_00472f2c._20_4_;
        *(undefined2 *)(pcVar1 + 0x18) = s_ios_base_failure_in_clear_00472f2c._24_2_;
        FUN_00451670();
      }
    }
  }
  if ((((*(byte *)(*(int *)((int)local_b6 + 4) + 0x32) & 5) == 0) &&
      ((*(ushort *)(*(int *)((int)local_b6 + 4) + 0x30) & 0x2000) != 0)) && (local_b7 == '\0')) {
    FUN_00403ac0((int)local_b6);
  }
  return (int)this;
}


