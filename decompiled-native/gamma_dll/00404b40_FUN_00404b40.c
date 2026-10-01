// 00404b40 FUN_00404b40 [Global]
// program: gamma.dll

int __thiscall FUN_00404b40(void *this,byte param_1)

{
  int *piVar1;
  byte *pbVar2;
  char *pcVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  undefined1 local_78 [4];
  char local_74;
  char local_73;
  void *local_72;
  undefined1 *local_58;
  undefined1 *local_40;
  undefined **local_3c;
  int local_38 [2];
  undefined ***local_30;
  int *local_2c;
  undefined1 *local_14;
  
  local_14 = local_78;
  local_74 = '\0';
  local_73 = '\0';
  local_72 = this;
  bVar4 = FUN_00403760(*(int *)((int)this + 4));
  if (bVar4) {
    iVar5 = FUN_00403750(*(int *)((int)local_72 + 4));
    if (iVar5 != 0) {
      iVar5 = FUN_00403750(*(int *)((int)local_72 + 4));
      FUN_00403ac0(iVar5);
    }
    bVar4 = FUN_00403760(*(int *)((int)local_72 + 4));
    if (bVar4) {
      local_74 = '\x01';
    }
    else {
      FUN_004036b0(*(void **)((int)local_72 + 4),4);
    }
  }
  else {
    FUN_004036b0(*(void **)((int)local_72 + 4),4);
  }
  local_58 = local_78;
  if (local_74 != '\0') {
    piVar1 = *(int **)(*(int *)((int)this + 4) + 0x24);
    if ((uint)piVar1[5] < (uint)piVar1[6]) {
      pbVar2 = (byte *)piVar1[5];
      piVar1[5] = piVar1[5] + 1;
      *pbVar2 = param_1;
      uVar6 = (uint)*pbVar2;
      local_58 = local_78;
      local_40 = local_78;
    }
    else {
      local_58 = local_78;
      local_40 = local_78;
      uVar6 = (**(code **)(*piVar1 + 0x30))(param_1);
    }
    local_78[0] = uVar6 == 0xffffffff;
    if ((bool)local_78[0]) {
      iVar5 = *(int *)((int)this + 4);
      *(byte *)(iVar5 + 0x32) = *(byte *)(iVar5 + 0x32) | 5;
      if (*(int *)(iVar5 + 0x24) == 0) {
        *(byte *)(iVar5 + 0x32) = *(byte *)(iVar5 + 0x32) | 1;
      }
      if ((*(byte *)(iVar5 + 0x33) & *(byte *)(iVar5 + 0x32)) != 0) {
        local_30 = &local_3c;
        local_3c = &PTR_LAB_0046d4fc;
        local_2c = local_38;
        iVar5 = FUN_00450b60(0x1a);
        FUN_00403d80(local_2c,iVar5);
        pcVar3 = (char *)*local_2c;
        *(undefined4 *)pcVar3 = s_ios_base_failure_in_clear_0046d658._0_4_;
        *(undefined4 *)(pcVar3 + 4) = s_ios_base_failure_in_clear_0046d658._4_4_;
        *(undefined4 *)(pcVar3 + 8) = s_ios_base_failure_in_clear_0046d658._8_4_;
        *(undefined4 *)(pcVar3 + 0xc) = s_ios_base_failure_in_clear_0046d658._12_4_;
        *(undefined4 *)(pcVar3 + 0x10) = s_ios_base_failure_in_clear_0046d658._16_4_;
        *(undefined4 *)(pcVar3 + 0x14) = s_ios_base_failure_in_clear_0046d658._20_4_;
        *(undefined2 *)(pcVar3 + 0x18) = s_ios_base_failure_in_clear_0046d658._24_2_;
        FUN_00451670();
      }
    }
  }
  if ((((*(byte *)(*(int *)((int)local_72 + 4) + 0x32) & 5) == 0) &&
      ((*(ushort *)(*(int *)((int)local_72 + 4) + 0x30) & 0x2000) != 0)) && (local_73 == '\0')) {
    FUN_00403ac0((int)local_72);
  }
  return (int)this;
}


