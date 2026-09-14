// 00427760 FUN_00427760 [Global]
// programa: gamma.dll

int __thiscall FUN_00427760(void *this,undefined4 param_1,int param_2)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  undefined1 auStack_78 [4];
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
  
  local_14 = auStack_78;
  local_74 = '\0';
  local_73 = '\0';
  local_72 = this;
  bVar2 = FUN_00403760(*(int *)((int)this + 4));
  if (bVar2) {
    iVar3 = FUN_00403750(*(int *)((int)local_72 + 4));
    if (iVar3 != 0) {
      iVar3 = FUN_00403750(*(int *)((int)local_72 + 4));
      FUN_00403ac0(iVar3);
    }
    bVar2 = FUN_00403760(*(int *)((int)local_72 + 4));
    if (bVar2) {
      local_74 = '\x01';
    }
    else {
      FUN_004036b0(*(void **)((int)local_72 + 4),4);
    }
  }
  else {
    FUN_004036b0(*(void **)((int)local_72 + 4),4);
  }
  local_58 = auStack_78;
  if (local_74 != '\0') {
    local_58 = auStack_78;
    local_40 = auStack_78;
    iVar3 = (**(code **)(**(int **)(*(int *)((int)this + 4) + 0x24) + 0x2c))(param_1,param_2);
    if (param_2 != iVar3) {
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
        *(undefined4 *)pcVar1 = s_ios_base_failure_in_clear_00471f38._0_4_;
        *(undefined4 *)(pcVar1 + 4) = s_ios_base_failure_in_clear_00471f38._4_4_;
        *(undefined4 *)(pcVar1 + 8) = s_ios_base_failure_in_clear_00471f38._8_4_;
        *(undefined4 *)(pcVar1 + 0xc) = s_ios_base_failure_in_clear_00471f38._12_4_;
        *(undefined4 *)(pcVar1 + 0x10) = s_ios_base_failure_in_clear_00471f38._16_4_;
        *(undefined4 *)(pcVar1 + 0x14) = s_ios_base_failure_in_clear_00471f38._20_4_;
        *(undefined2 *)(pcVar1 + 0x18) = s_ios_base_failure_in_clear_00471f38._24_2_;
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


