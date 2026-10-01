// 004431d0 FUN_004431d0 [Global]
// program: gamma.dll

int __thiscall FUN_004431d0(void *this,undefined4 param_1,undefined4 param_2)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  undefined1 auStack_68 [4];
  byte local_64;
  undefined1 local_5e;
  undefined1 *local_48;
  int local_44 [2];
  undefined **local_3c;
  int local_38 [2];
  undefined ***local_30;
  int *local_2c;
  undefined1 *local_14;
  
  local_14 = auStack_68;
  local_5e = 0;
  *(undefined4 *)((int)this + 8) = 0;
  bVar2 = FUN_00403760(*(int *)((int)this + 4));
  if (bVar2) {
    iVar3 = FUN_00403750(*(int *)((int)this + 4));
    if (iVar3 != 0) {
      iVar3 = FUN_00403750(*(int *)((int)this + 4));
      FUN_00403ac0(iVar3);
    }
    bVar2 = FUN_00403760(*(int *)((int)this + 4));
    if (bVar2) {
      local_5e = 1;
    }
    else {
      FUN_004036b0(*(void **)((int)this + 4),4);
    }
  }
  else {
    FUN_004036b0(*(void **)((int)this + 4),4);
  }
  if ((*(byte *)(*(int *)((int)this + 4) + 0x32) & 5) == 0) {
    local_64 = 0;
    local_48 = auStack_68;
    (**(code **)(**(int **)(*(int *)((int)this + 4) + 0x24) + 0x10))(local_44,param_1,param_2,8);
    if (local_44[0] == -1) {
      local_64 = 4;
    }
    if (local_64 != 0) {
      iVar3 = *(int *)((int)this + 4);
      *(byte *)(iVar3 + 0x32) = *(byte *)(iVar3 + 0x32) | local_64;
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
        *(undefined4 *)pcVar1 = s_ios_base_failure_in_clear_0047932c._0_4_;
        *(undefined4 *)(pcVar1 + 4) = s_ios_base_failure_in_clear_0047932c._4_4_;
        *(undefined4 *)(pcVar1 + 8) = s_ios_base_failure_in_clear_0047932c._8_4_;
        *(undefined4 *)(pcVar1 + 0xc) = s_ios_base_failure_in_clear_0047932c._12_4_;
        *(undefined4 *)(pcVar1 + 0x10) = s_ios_base_failure_in_clear_0047932c._16_4_;
        *(undefined4 *)(pcVar1 + 0x14) = s_ios_base_failure_in_clear_0047932c._20_4_;
        *(undefined2 *)(pcVar1 + 0x18) = s_ios_base_failure_in_clear_0047932c._24_2_;
        FUN_00451670();
      }
    }
  }
  return (int)this;
}


