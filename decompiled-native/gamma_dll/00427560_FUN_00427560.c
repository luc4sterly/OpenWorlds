// 00427560 FUN_00427560 [Global]
// program: gamma.dll

uint __fastcall FUN_00427560(int param_1)

{
  int *piVar1;
  byte *pbVar2;
  char *pcVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  undefined1 auStack_60 [4];
  byte local_5c;
  char local_56;
  undefined1 *local_40;
  undefined **local_3c;
  int local_38 [2];
  undefined ***local_30;
  int *local_2c;
  undefined1 *local_14;
  
  local_14 = auStack_60;
  uVar6 = 0xffffffff;
  local_56 = '\0';
  *(undefined4 *)(param_1 + 8) = 0;
  bVar4 = FUN_00403760(*(int *)(param_1 + 4));
  if (bVar4) {
    iVar5 = FUN_00403750(*(int *)(param_1 + 4));
    if (iVar5 != 0) {
      iVar5 = FUN_00403750(*(int *)(param_1 + 4));
      FUN_00403ac0(iVar5);
    }
    bVar4 = FUN_00403760(*(int *)(param_1 + 4));
    if (bVar4) {
      local_56 = '\x01';
    }
    else {
      FUN_004036b0(*(void **)(param_1 + 4),4);
    }
  }
  else {
    FUN_004036b0(*(void **)(param_1 + 4),4);
  }
  if (local_56 != '\0') {
    local_5c = 0;
    piVar1 = *(int **)(*(int *)(param_1 + 4) + 0x24);
    if ((uint)piVar1[2] < (uint)piVar1[3]) {
      pbVar2 = (byte *)piVar1[2];
      piVar1[2] = piVar1[2] + 1;
      uVar6 = (uint)*pbVar2;
      local_40 = auStack_60;
    }
    else {
      local_40 = auStack_60;
      uVar6 = (**(code **)(*piVar1 + 0x24))();
    }
    if (uVar6 == 0xffffffff) {
      local_5c = 6;
    }
    else {
      *(undefined4 *)(param_1 + 8) = 1;
    }
    iVar5 = *(int *)(param_1 + 4);
    *(byte *)(iVar5 + 0x32) = *(byte *)(iVar5 + 0x32) | local_5c;
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
      *(undefined4 *)pcVar3 = s_ios_base_failure_in_clear_00471f38._0_4_;
      *(undefined4 *)(pcVar3 + 4) = s_ios_base_failure_in_clear_00471f38._4_4_;
      *(undefined4 *)(pcVar3 + 8) = s_ios_base_failure_in_clear_00471f38._8_4_;
      *(undefined4 *)(pcVar3 + 0xc) = s_ios_base_failure_in_clear_00471f38._12_4_;
      *(undefined4 *)(pcVar3 + 0x10) = s_ios_base_failure_in_clear_00471f38._16_4_;
      *(undefined4 *)(pcVar3 + 0x14) = s_ios_base_failure_in_clear_00471f38._20_4_;
      *(undefined2 *)(pcVar3 + 0x18) = s_ios_base_failure_in_clear_00471f38._24_2_;
      FUN_00451670();
    }
  }
  return uVar6;
}


