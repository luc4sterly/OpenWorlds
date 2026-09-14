// 0040f5a0 FUN_0040f5a0 [Global]
// programa: gamma.dll

int __thiscall FUN_0040f5a0(void *this,undefined4 param_1)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined1 auStack_d0 [4];
  int *local_cc;
  undefined1 local_c8;
  char local_c4;
  char local_c3;
  void *local_c2;
  undefined1 *local_a8;
  undefined1 *local_90;
  int local_8c [2];
  int local_84 [2];
  int local_7c;
  undefined4 local_78;
  undefined1 local_71;
  undefined1 local_55;
  undefined **local_3c;
  int local_38 [2];
  undefined ***local_30;
  int *local_2c;
  undefined1 *local_14;
  
  local_14 = auStack_d0;
  local_c4 = '\0';
  local_c3 = '\0';
  local_c2 = this;
  bVar2 = FUN_00403760(*(int *)((int)this + 4));
  if (bVar2) {
    iVar3 = FUN_00403750(*(int *)((int)local_c2 + 4));
    if (iVar3 != 0) {
      iVar3 = FUN_00403750(*(int *)((int)local_c2 + 4));
      FUN_00403ac0(iVar3);
    }
    bVar2 = FUN_00403760(*(int *)((int)local_c2 + 4));
    if (bVar2) {
      local_c4 = '\x01';
    }
    else {
      FUN_004036b0(*(void **)((int)local_c2 + 4),4);
    }
  }
  else {
    FUN_004036b0(*(void **)((int)local_c2 + 4),4);
  }
  local_a8 = auStack_d0;
  if (local_c4 != '\0') {
    local_a8 = auStack_d0;
    local_90 = auStack_d0;
    FUN_004049b0(*(void **)((int)this + 4),local_8c);
    local_71 = DAT_004892de;
    local_cc = (int *)FUN_00405d40(local_8c);
    FUN_00404dc0(local_8c);
    FUN_004049b0(*(void **)((int)this + 4),local_84);
    local_55 = DAT_004892dd;
    piVar4 = (int *)FUN_00404a00(local_84);
    FUN_00404dc0(local_84);
    uVar5 = (**(code **)(*piVar4 + 0x14))(0x30);
    local_78 = *(undefined4 *)(*(int *)((int)this + 4) + 0x24);
    (**(code **)(*local_cc + 0x20))(&local_7c,local_78,*(int *)((int)this + 4),uVar5,param_1);
    local_c8 = local_7c == 0;
    if ((bool)local_c8) {
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
  if ((((*(byte *)(*(int *)((int)local_c2 + 4) + 0x32) & 5) == 0) &&
      ((*(ushort *)(*(int *)((int)local_c2 + 4) + 0x30) & 0x2000) != 0)) && (local_c3 == '\0')) {
    FUN_00403ac0((int)local_c2);
  }
  return (int)this;
}


