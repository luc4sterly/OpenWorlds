// 00403ac0 FUN_00403ac0 [Global]
// programa: gamma.dll

int __fastcall FUN_00403ac0(int param_1)

{
  int *piVar1;
  char *pcVar2;
  bool bVar3;
  int iVar4;
  uint *puVar5;
  char local_78 [4];
  undefined1 local_74;
  char local_73;
  int local_72;
  undefined1 *local_58;
  undefined **local_54;
  int local_50 [2];
  undefined ***local_48;
  int *local_44;
  undefined1 *local_2c;
  undefined1 *local_14;
  
  local_14 = local_78;
  local_74 = 0;
  local_73 = 0;
  local_72 = param_1;
  bVar3 = FUN_00403760(*(int *)(param_1 + 4));
  if (bVar3) {
    iVar4 = FUN_00403750(*(int *)(local_72 + 4));
    if (iVar4 != 0) {
      iVar4 = FUN_00403750(*(int *)(local_72 + 4));
      FUN_00403ac0(iVar4);
    }
    bVar3 = FUN_00403760(*(int *)(local_72 + 4));
    if (bVar3) {
      local_74 = 1;
    }
    else {
      FUN_004036b0(*(void **)(local_72 + 4),4);
    }
  }
  else {
    FUN_004036b0(*(void **)(local_72 + 4),4);
  }
  local_73 = '\x01';
  piVar1 = *(int **)(*(int *)(param_1 + 4) + 0x24);
  if (piVar1 != (int *)0x0) {
    local_78[0] = '\0';
    local_58 = local_78;
    iVar4 = (**(code **)(*piVar1 + 0x14))();
    if (iVar4 == -1) {
      local_78[0] = '\x01';
    }
    if (local_78[0] != '\0') {
      iVar4 = *(int *)(param_1 + 4);
      *(byte *)(iVar4 + 0x32) = *(byte *)(iVar4 + 0x32) | 1;
      if (*(int *)(iVar4 + 0x24) == 0) {
        *(byte *)(iVar4 + 0x32) = *(byte *)(iVar4 + 0x32) | 1;
      }
      if ((*(byte *)(iVar4 + 0x33) & *(byte *)(iVar4 + 0x32)) != 0) {
        local_48 = &local_54;
        local_54 = &PTR_LAB_0046d4fc;
        local_44 = local_50;
        iVar4 = FUN_00450b60(0x1a);
        *local_44 = iVar4;
        local_44[1] = 0;
        local_2c = local_78;
        if (*local_44 != 0) {
          local_2c = local_78;
          puVar5 = FUN_0044e010(4);
          if (puVar5 != (uint *)0x0) {
            *puVar5 = 1;
          }
          local_44[1] = (int)puVar5;
        }
        pcVar2 = (char *)*local_44;
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
  if ((((*(byte *)(*(int *)(local_72 + 4) + 0x32) & 5) == 0) &&
      ((*(ushort *)(*(int *)(local_72 + 4) + 0x30) & 0x2000) != 0)) && (local_73 == '\0')) {
    FUN_00403ac0(local_72);
  }
  return param_1;
}


