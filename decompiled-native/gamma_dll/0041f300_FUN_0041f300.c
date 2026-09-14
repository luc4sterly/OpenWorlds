// 0041f300 FUN_0041f300 [Global]
// programa: gamma.dll

int __thiscall FUN_0041f300(void *this,char *param_1,int param_2,char param_3)

{
  char *pcVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  undefined1 auStack_78 [4];
  char local_74;
  char local_6e;
  byte local_6c;
  undefined1 *local_54;
  undefined **local_50;
  int local_4c [2];
  undefined **local_44;
  int local_40 [2];
  undefined ***local_38;
  undefined ***local_34;
  int *local_30;
  int *local_2c;
  undefined1 *local_14;
  
  local_14 = auStack_78;
  local_6e = '\0';
  *(undefined4 *)((int)this + 8) = 0;
  bVar3 = FUN_00403760(*(int *)((int)this + 4));
  if (bVar3) {
    iVar4 = FUN_00403750(*(int *)((int)this + 4));
    if (iVar4 != 0) {
      iVar4 = FUN_00403750(*(int *)((int)this + 4));
      FUN_00403ac0(iVar4);
    }
    bVar3 = FUN_00403760(*(int *)((int)this + 4));
    if (bVar3) {
      local_6e = '\x01';
    }
    else {
      FUN_004036b0(*(void **)((int)this + 4),4);
    }
  }
  else {
    FUN_004036b0(*(void **)((int)this + 4),4);
  }
  if ((param_1 == (char *)0x0) || (param_2 < 1)) {
    iVar4 = *(int *)((int)this + 4);
    *(byte *)(iVar4 + 0x32) = *(byte *)(iVar4 + 0x32) | 4;
    if (*(int *)(iVar4 + 0x24) == 0) {
      *(byte *)(iVar4 + 0x32) = *(byte *)(iVar4 + 0x32) | 1;
    }
    if ((*(byte *)(iVar4 + 0x33) & *(byte *)(iVar4 + 0x32)) != 0) {
      local_38 = &local_50;
      local_50 = &PTR_LAB_0046d4fc;
      local_30 = local_4c;
      iVar4 = FUN_00450b60(0x1a);
      FUN_00403d80(local_30,iVar4);
      pcVar1 = (char *)*local_30;
      *(undefined4 *)pcVar1 = s_ios_base_failure_in_clear_00470cd8._0_4_;
      *(undefined4 *)(pcVar1 + 4) = s_ios_base_failure_in_clear_00470cd8._4_4_;
      *(undefined4 *)(pcVar1 + 8) = s_ios_base_failure_in_clear_00470cd8._8_4_;
      *(undefined4 *)(pcVar1 + 0xc) = s_ios_base_failure_in_clear_00470cd8._12_4_;
      *(undefined4 *)(pcVar1 + 0x10) = s_ios_base_failure_in_clear_00470cd8._16_4_;
      *(undefined4 *)(pcVar1 + 0x14) = s_ios_base_failure_in_clear_00470cd8._20_4_;
      *(undefined2 *)(pcVar1 + 0x18) = s_ios_base_failure_in_clear_00470cd8._24_2_;
      FUN_00451670();
    }
    return (int)this;
  }
  if (local_6e != '\0') {
    local_6c = 0;
    local_54 = auStack_78;
    while( true ) {
      piVar2 = *(int **)(*(int *)((int)this + 4) + 0x24);
      if ((byte *)piVar2[2] < (byte *)piVar2[3]) {
        uVar5 = (uint)*(byte *)piVar2[2];
      }
      else {
        uVar5 = (**(code **)(*piVar2 + 0x20))();
      }
      if (uVar5 == 0xffffffff) {
        local_6c = local_6c | 2;
        goto LAB_0041f530;
      }
      local_74 = (char)uVar5;
      if (local_74 == param_3) {
        piVar2 = *(int **)(*(int *)((int)this + 4) + 0x24);
        if ((uint)piVar2[2] < (uint)piVar2[3]) {
          piVar2[2] = piVar2[2] + 1;
        }
        else {
          (**(code **)(*piVar2 + 0x24))();
        }
        *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
        goto LAB_0041f530;
      }
      if (param_2 == 1) break;
      piVar2 = *(int **)(*(int *)((int)this + 4) + 0x24);
      if ((uint)piVar2[2] < (uint)piVar2[3]) {
        piVar2[2] = piVar2[2] + 1;
      }
      else {
        (**(code **)(*piVar2 + 0x24))();
      }
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      *param_1 = local_74;
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    }
    local_6c = local_6c | 4;
LAB_0041f530:
    if (*(int *)((int)this + 8) == 0) {
      local_6c = local_6c | 4;
    }
    *param_1 = '\0';
    iVar4 = *(int *)((int)this + 4);
    *(byte *)(iVar4 + 0x32) = *(byte *)(iVar4 + 0x32) | local_6c;
    if (*(int *)(iVar4 + 0x24) == 0) {
      *(byte *)(iVar4 + 0x32) = *(byte *)(iVar4 + 0x32) | 1;
    }
    if ((*(byte *)(iVar4 + 0x33) & *(byte *)(iVar4 + 0x32)) != 0) {
      local_34 = &local_44;
      local_44 = &PTR_LAB_0046d4fc;
      local_2c = local_40;
      iVar4 = FUN_00450b60(0x1a);
      FUN_00403d80(local_2c,iVar4);
      pcVar1 = (char *)*local_2c;
      *(undefined4 *)pcVar1 = s_ios_base_failure_in_clear_00470cd8._0_4_;
      *(undefined4 *)(pcVar1 + 4) = s_ios_base_failure_in_clear_00470cd8._4_4_;
      *(undefined4 *)(pcVar1 + 8) = s_ios_base_failure_in_clear_00470cd8._8_4_;
      *(undefined4 *)(pcVar1 + 0xc) = s_ios_base_failure_in_clear_00470cd8._12_4_;
      *(undefined4 *)(pcVar1 + 0x10) = s_ios_base_failure_in_clear_00470cd8._16_4_;
      *(undefined4 *)(pcVar1 + 0x14) = s_ios_base_failure_in_clear_00470cd8._20_4_;
      *(undefined2 *)(pcVar1 + 0x18) = s_ios_base_failure_in_clear_00470cd8._24_2_;
      FUN_00451670();
    }
  }
  return (int)this;
}


