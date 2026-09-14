// 00427d00 FUN_00427d00 [Global]
// programa: gamma.dll

int __cdecl FUN_00427d00(int param_1)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
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
  bVar2 = FUN_00403760(*(int *)(param_1 + 4));
  if (bVar2) {
    iVar3 = FUN_00403750(*(int *)(local_7a + 4));
    if (iVar3 != 0) {
      iVar3 = FUN_00403750(*(int *)(local_7a + 4));
      FUN_00403ac0(iVar3);
    }
    bVar2 = FUN_00403760(*(int *)(local_7a + 4));
    if (bVar2) {
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
    iVar3 = *(int *)(param_1 + 4);
    local_40 = *(int **)(iVar3 + 0x24);
    local_60 = local_80;
    local_48 = local_80;
    FUN_00403820(&local_44,local_40,iVar3,*(byte *)(iVar3 + 0x38),(byte *)0x0,0,&stack0x00000008,1);
    local_80[0] = local_44 == 0;
    if ((bool)local_80[0]) {
      iVar3 = *(int *)(param_1 + 4);
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
        *(undefined4 *)pcVar1 = s__ios_base_failure_in_clear_0047202f._1_4_;
        *(undefined4 *)(pcVar1 + 4) = s__ios_base_failure_in_clear_0047202f._5_4_;
        *(undefined4 *)(pcVar1 + 8) = s__ios_base_failure_in_clear_0047202f._9_4_;
        *(undefined4 *)(pcVar1 + 0xc) = s__ios_base_failure_in_clear_0047202f._13_4_;
        *(undefined4 *)(pcVar1 + 0x10) = s__ios_base_failure_in_clear_0047202f._17_4_;
        *(undefined4 *)(pcVar1 + 0x14) = s__ios_base_failure_in_clear_0047202f._21_4_;
        *(undefined2 *)(pcVar1 + 0x18) = s__ios_base_failure_in_clear_0047202f._25_2_;
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


