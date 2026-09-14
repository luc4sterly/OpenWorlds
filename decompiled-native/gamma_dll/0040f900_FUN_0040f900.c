// 0040f900 FUN_0040f900 [Global]
// programa: gamma.dll

int __thiscall FUN_0040f900(void *this,undefined4 param_1)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  ushort uVar4;
  bool local_b0 [4];
  int *local_ac;
  char local_a8;
  char local_a7;
  void *local_a6;
  undefined1 *local_8c;
  undefined1 *local_74;
  int local_70 [2];
  int local_68;
  undefined4 local_64;
  int local_60;
  undefined4 local_5c;
  undefined1 local_55;
  undefined **local_3c;
  int local_38 [2];
  undefined ***local_30;
  int *local_2c;
  undefined1 *local_14;
  
  local_14 = local_b0;
  local_a8 = '\0';
  local_a7 = '\0';
  local_a6 = this;
  bVar2 = FUN_00403760(*(int *)((int)this + 4));
  if (bVar2) {
    iVar3 = FUN_00403750(*(int *)((int)local_a6 + 4));
    if (iVar3 != 0) {
      iVar3 = FUN_00403750(*(int *)((int)local_a6 + 4));
      FUN_00403ac0(iVar3);
    }
    bVar2 = FUN_00403760(*(int *)((int)local_a6 + 4));
    if (bVar2) {
      local_a8 = '\x01';
    }
    else {
      FUN_004036b0(*(void **)((int)local_a6 + 4),4);
    }
  }
  else {
    FUN_004036b0(*(void **)((int)local_a6 + 4),4);
  }
  local_8c = local_b0;
  if (local_a8 != '\0') {
    local_8c = local_b0;
    local_74 = local_b0;
    FUN_004049b0(*(void **)((int)this + 4),local_70);
    local_55 = DAT_004892de;
    local_ac = (int *)FUN_00405d40(local_70);
    FUN_00404dc0(local_70);
    iVar3 = *(int *)((int)this + 4);
    uVar4 = *(ushort *)(iVar3 + 0x30) & 0x4a;
    if ((uVar4 == 0x40) || (uVar4 == 8)) {
      local_64 = *(undefined4 *)(iVar3 + 0x24);
      (**(code **)(*local_ac + 0xc))(&local_68,local_64,iVar3,*(undefined1 *)(iVar3 + 0x38),param_1)
      ;
    }
    else {
      local_5c = *(undefined4 *)(iVar3 + 0x24);
      (**(code **)(*local_ac + 8))(&local_60,local_5c,iVar3,*(undefined1 *)(iVar3 + 0x38),param_1);
      local_68 = local_60;
    }
    local_b0[0] = local_68 == 0;
    if (local_b0[0]) {
      iVar3 = *(int *)((int)this + 4);
      *(byte *)(iVar3 + 0x32) = *(byte *)(iVar3 + 0x32) | 5;
      if (*(int *)(iVar3 + 0x24) == 0) {
        *(byte *)(iVar3 + 0x32) = *(byte *)(iVar3 + 0x32) | 1;
      }
      if ((*(byte *)(iVar3 + 0x33) & *(byte *)(iVar3 + 0x32)) != 0) {
        local_30 = &local_3c;
        local_3c = &PTR_LAB_0046d4fc;
        local_2c = local_38;
        iVar3 = FUN_00450b60(0x1a);
        FUN_00403d80(local_2c,iVar3);
        pcVar1 = (char *)*local_2c;
        *(undefined4 *)pcVar1 = s_ios_base_failure_in_clear_0046ebc0._0_4_;
        *(undefined4 *)(pcVar1 + 4) = s_ios_base_failure_in_clear_0046ebc0._4_4_;
        *(undefined4 *)(pcVar1 + 8) = s_ios_base_failure_in_clear_0046ebc0._8_4_;
        *(undefined4 *)(pcVar1 + 0xc) = s_ios_base_failure_in_clear_0046ebc0._12_4_;
        *(undefined4 *)(pcVar1 + 0x10) = s_ios_base_failure_in_clear_0046ebc0._16_4_;
        *(undefined4 *)(pcVar1 + 0x14) = s_ios_base_failure_in_clear_0046ebc0._20_4_;
        *(undefined2 *)(pcVar1 + 0x18) = s_ios_base_failure_in_clear_0046ebc0._24_2_;
        FUN_00451670();
      }
    }
  }
  if ((((*(byte *)(*(int *)((int)local_a6 + 4) + 0x32) & 5) == 0) &&
      ((*(ushort *)(*(int *)((int)local_a6 + 4) + 0x30) & 0x2000) != 0)) && (local_a7 == '\0')) {
    FUN_00403ac0((int)local_a6);
  }
  return (int)this;
}


