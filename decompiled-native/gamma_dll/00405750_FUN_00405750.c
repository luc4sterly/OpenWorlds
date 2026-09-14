// 00405750 FUN_00405750 [Global]
// programa: gamma.dll

int __thiscall FUN_00405750(void *this,undefined4 param_1)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  undefined1 auStack_a8 [4];
  undefined1 local_a4;
  char local_a0;
  char local_9f;
  void *local_9e;
  undefined1 *local_84;
  undefined1 *local_6c;
  undefined4 *local_68;
  int *local_64;
  int local_60;
  undefined4 local_5c;
  undefined1 local_55;
  undefined **local_3c;
  int local_38 [2];
  undefined ***local_30;
  int *local_2c;
  undefined1 *local_14;
  
  local_14 = auStack_a8;
  local_a0 = '\0';
  local_9f = '\0';
  local_9e = this;
  bVar2 = FUN_00403760(*(int *)((int)this + 4));
  if (bVar2) {
    iVar3 = FUN_00403750(*(int *)((int)local_9e + 4));
    if (iVar3 != 0) {
      iVar3 = FUN_00403750(*(int *)((int)local_9e + 4));
      FUN_00403ac0(iVar3);
    }
    bVar2 = FUN_00403760(*(int *)((int)local_9e + 4));
    if (bVar2) {
      local_a0 = '\x01';
    }
    else {
      FUN_004036b0(*(void **)((int)local_9e + 4),4);
    }
  }
  else {
    FUN_004036b0(*(void **)((int)local_9e + 4),4);
  }
  local_84 = auStack_a8;
  if (local_a0 != '\0') {
    local_84 = auStack_a8;
    local_6c = auStack_a8;
    FUN_004049b0(*(void **)((int)this + 4),&local_68);
    local_55 = DAT_004890b5;
    piVar4 = (int *)FUN_00405d40((int *)&local_68);
    if ((local_64 != (int *)0x0) && (*local_64 = *local_64 + -1, *local_64 == 0)) {
      if (local_68 != (undefined4 *)0x0) {
        FUN_00404e60((int)local_68);
        FUN_0044e100(local_68);
      }
      FUN_0044e100(local_64);
    }
    iVar3 = *(int *)((int)this + 4);
    local_5c = *(undefined4 *)(iVar3 + 0x24);
    (**(code **)(*piVar4 + 0xc))(&local_60,local_5c,iVar3,*(undefined1 *)(iVar3 + 0x38),param_1);
    local_a4 = local_60 == 0;
    if ((bool)local_a4) {
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
        *(undefined4 *)pcVar1 = s_ios_base_failure_in_clear_0046d7f4._0_4_;
        *(undefined4 *)(pcVar1 + 4) = s_ios_base_failure_in_clear_0046d7f4._4_4_;
        *(undefined4 *)(pcVar1 + 8) = s_ios_base_failure_in_clear_0046d7f4._8_4_;
        *(undefined4 *)(pcVar1 + 0xc) = s_ios_base_failure_in_clear_0046d7f4._12_4_;
        *(undefined4 *)(pcVar1 + 0x10) = s_ios_base_failure_in_clear_0046d7f4._16_4_;
        *(undefined4 *)(pcVar1 + 0x14) = s_ios_base_failure_in_clear_0046d7f4._20_4_;
        *(undefined2 *)(pcVar1 + 0x18) = s_ios_base_failure_in_clear_0046d7f4._24_2_;
        FUN_00451670();
      }
    }
  }
  if ((((*(byte *)(*(int *)((int)local_9e + 4) + 0x32) & 5) == 0) &&
      ((*(ushort *)(*(int *)((int)local_9e + 4) + 0x30) & 0x2000) != 0)) && (local_9f == '\0')) {
    FUN_00403ac0((int)local_9e);
  }
  return (int)this;
}


