// 0042f460 FUN_0042f460 [Global]
// program: gamma.dll

int __thiscall FUN_0042f460(void *this,undefined1 *param_1,int param_2)

{
  int *piVar1;
  byte *pbVar2;
  char *pcVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  undefined1 auStack_60 [6];
  char local_5a;
  byte local_58;
  undefined1 *local_40;
  undefined **local_3c;
  int local_38 [2];
  undefined ***local_30;
  int *local_2c;
  undefined1 *local_14;
  
  local_14 = auStack_60;
  local_5a = '\0';
  *(undefined4 *)((int)this + 8) = 0;
  bVar4 = FUN_00403760(*(int *)((int)this + 4));
  if (bVar4) {
    iVar5 = FUN_00403750(*(int *)((int)this + 4));
    if (iVar5 != 0) {
      iVar5 = FUN_00403750(*(int *)((int)this + 4));
      FUN_00403ac0(iVar5);
    }
    bVar4 = FUN_00403760(*(int *)((int)this + 4));
    if (bVar4) {
      local_5a = '\x01';
    }
    else {
      FUN_004036b0(*(void **)((int)this + 4),4);
    }
  }
  else {
    FUN_004036b0(*(void **)((int)this + 4),4);
  }
  if (local_5a != '\0') {
    local_58 = 0;
    local_40 = auStack_60;
    for (; 0 < param_2; param_2 = param_2 + -1) {
      piVar1 = *(int **)(*(int *)((int)this + 4) + 0x24);
      if ((uint)piVar1[2] < (uint)piVar1[3]) {
        pbVar2 = (byte *)piVar1[2];
        piVar1[2] = piVar1[2] + 1;
        uVar6 = (uint)*pbVar2;
      }
      else {
        uVar6 = (**(code **)(*piVar1 + 0x24))();
      }
      if (uVar6 == 0xffffffff) {
        local_58 = local_58 | 6;
        break;
      }
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      *param_1 = (char)uVar6;
      param_1 = param_1 + 1;
    }
    iVar5 = *(int *)((int)this + 4);
    *(byte *)(iVar5 + 0x32) = *(byte *)(iVar5 + 0x32) | local_58;
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
      *(undefined4 *)pcVar3 = s_ios_base_failure_in_clear_00474bf0._0_4_;
      *(undefined4 *)(pcVar3 + 4) = s_ios_base_failure_in_clear_00474bf0._4_4_;
      *(undefined4 *)(pcVar3 + 8) = s_ios_base_failure_in_clear_00474bf0._8_4_;
      *(undefined4 *)(pcVar3 + 0xc) = s_ios_base_failure_in_clear_00474bf0._12_4_;
      *(undefined4 *)(pcVar3 + 0x10) = s_ios_base_failure_in_clear_00474bf0._16_4_;
      *(undefined4 *)(pcVar3 + 0x14) = s_ios_base_failure_in_clear_00474bf0._20_4_;
      *(undefined2 *)(pcVar3 + 0x18) = s_ios_base_failure_in_clear_00474bf0._24_2_;
      FUN_00451670();
    }
  }
  return (int)this;
}


