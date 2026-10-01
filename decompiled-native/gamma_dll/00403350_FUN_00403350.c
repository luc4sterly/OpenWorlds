// 00403350 FUN_00403350 [Global]
// program: gamma.dll

int __cdecl FUN_00403350(int param_1,byte *param_2)

{
  byte bVar1;
  char *pcVar2;
  bool bVar3;
  int iVar4;
  byte *pbVar5;
  undefined1 local_80 [4];
  char local_7c;
  char local_7b;
  int local_7a;
  undefined1 *local_60;
  undefined1 *local_48;
  int local_44;
  int *local_40;
  undefined **local_3c;
  int local_38 [2];
  undefined ***local_30;
  int *local_2c;
  undefined1 *local_14;
  
  local_14 = local_80;
  local_7a = param_1;
  local_7c = '\0';
  local_7b = '\0';
  bVar3 = FUN_00403760(*(int *)(param_1 + 4));
  if (bVar3) {
    iVar4 = FUN_00403750(*(int *)(local_7a + 4));
    if (iVar4 != 0) {
      iVar4 = FUN_00403750(*(int *)(local_7a + 4));
      FUN_00403ac0(iVar4);
    }
    bVar3 = FUN_00403760(*(int *)(local_7a + 4));
    if (bVar3) {
      local_7c = '\x01';
    }
    else {
      FUN_004036b0(*(void **)(local_7a + 4),4);
    }
  }
  else {
    FUN_004036b0(*(void **)(local_7a + 4),4);
  }
  local_60 = local_80;
  if (local_7c != '\0') {
    iVar4 = -1;
    pbVar5 = param_2;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar1 = *pbVar5;
      pbVar5 = pbVar5 + 1;
    } while (bVar1 != 0);
    local_40 = *(int **)(*(int *)(param_1 + 4) + 0x24);
    local_60 = local_80;
    local_48 = local_80;
    FUN_00403820(&local_44,local_40,*(int *)(param_1 + 4),*(byte *)(*(int *)(param_1 + 4) + 0x38),
                 (byte *)0x0,0,param_2,-2 - iVar4);
    local_80[0] = local_44 == 0;
    if ((bool)local_80[0]) {
      iVar4 = *(int *)(param_1 + 4);
      *(byte *)(iVar4 + 0x32) = *(byte *)(iVar4 + 0x32) | 5;
      if (*(int *)(iVar4 + 0x24) == 0) {
        *(byte *)(iVar4 + 0x32) = *(byte *)(iVar4 + 0x32) | 1;
      }
      if ((*(byte *)(iVar4 + 0x33) & *(byte *)(iVar4 + 0x32)) != 0) {
        local_30 = &local_3c;
        local_3c = &PTR_LAB_0046d4fc;
        local_2c = local_38;
        iVar4 = FUN_00450b60(0x1a);
        FUN_00403d80(local_2c,iVar4);
        pcVar2 = (char *)*local_2c;
        *(undefined4 *)pcVar2 = s_ios_base_failure_in_clear_0046d45c._0_4_;
        *(undefined4 *)(pcVar2 + 4) = s_ios_base_failure_in_clear_0046d45c._4_4_;
        *(undefined4 *)(pcVar2 + 8) = s_ios_base_failure_in_clear_0046d45c._8_4_;
        *(undefined4 *)(pcVar2 + 0xc) = s_ios_base_failure_in_clear_0046d45c._12_4_;
        *(undefined4 *)(pcVar2 + 0x10) = s_ios_base_failure_in_clear_0046d45c._16_4_;
        *(undefined4 *)(pcVar2 + 0x14) = s_ios_base_failure_in_clear_0046d45c._20_4_;
        *(undefined2 *)(pcVar2 + 0x18) = s_ios_base_failure_in_clear_0046d45c._24_2_;
        FUN_00451670();
      }
    }
  }
  if ((((*(byte *)(*(int *)(local_7a + 4) + 0x32) & 5) == 0) &&
      ((*(ushort *)(*(int *)(local_7a + 4) + 0x30) & 0x2000) != 0)) && (local_7b == '\0')) {
    FUN_00403ac0(local_7a);
  }
  return param_1;
}


