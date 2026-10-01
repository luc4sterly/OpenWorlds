// 0042eff0 FUN_0042eff0 [Global]
// program: gamma.dll

uint * __thiscall FUN_0042eff0(void *this,undefined4 *param_1,char param_2,char param_3,int param_4)

{
  char *pcVar1;
  undefined1 *puVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  undefined1 auStack_78 [4];
  undefined ***local_74;
  undefined **local_70;
  int local_6c [7];
  undefined1 *local_50;
  undefined1 *local_38;
  undefined ***local_34;
  uint *local_30;
  int *local_2c;
  undefined1 *local_14;
  
  if (*(int *)this == -1) {
    local_74 = &local_70;
    local_34 = &local_70;
    local_70 = &PTR_FUN_0046db74;
    local_2c = local_6c;
    iVar3 = FUN_00450b60(0x1a);
    local_14 = auStack_78;
    *local_2c = iVar3;
    local_2c[1] = 0;
    puVar2 = auStack_78;
    if (*local_2c != 0) {
      puVar4 = FUN_0044e010(4);
      if (puVar4 != (uint *)0x0) {
        *puVar4 = 1;
      }
      local_2c[1] = (int)puVar4;
      puVar2 = local_14;
    }
    local_14 = puVar2;
    pcVar1 = (char *)*local_2c;
    *(undefined4 *)pcVar1 = s_tree__insert_length_error_00474acc._0_4_;
    *(undefined4 *)(pcVar1 + 4) = s_tree__insert_length_error_00474acc._4_4_;
    *(undefined4 *)(pcVar1 + 8) = s_tree__insert_length_error_00474acc._8_4_;
    *(undefined4 *)(pcVar1 + 0xc) = s_tree__insert_length_error_00474acc._12_4_;
    *(undefined4 *)(pcVar1 + 0x10) = s_tree__insert_length_error_00474acc._16_4_;
    *(undefined4 *)(pcVar1 + 0x14) = s_tree__insert_length_error_00474acc._20_4_;
    *(undefined2 *)(pcVar1 + 0x18) = s_tree__insert_length_error_00474acc._24_2_;
    *local_74 = &PTR_LAB_0046db64;
    FUN_00451670();
  }
  puVar5 = FUN_0044e010(0x214);
  puVar4 = puVar5 + 3;
  local_50 = auStack_78;
  if (puVar4 != (uint *)0x0) {
    *puVar4 = (uint)&PTR_LAB_00471ff8;
    local_50 = auStack_78;
    local_38 = auStack_78;
    local_30 = puVar4;
    FUN_0044d6d0((char *)(puVar5 + 4),(char *)(param_4 + 4),0xff);
    *(undefined1 *)((int)local_30 + 0x103) = 0;
    local_30[0x41] = (uint)&PTR_LAB_00471ff8;
    FUN_0044d6d0((char *)(local_30 + 0x42),(char *)(param_4 + 0x108),0xff);
    *(undefined1 *)((int)local_30 + 0x207) = 0;
  }
  puVar5[1] = 0;
  *puVar5 = puVar5[1];
  puVar5[2] = puVar5[2] & 1 | (uint)param_1;
  if (param_2 == '\0') {
    param_1[1] = puVar5;
  }
  else {
    *param_1 = puVar5;
  }
  *(int *)this = *(int *)this + 1;
  FUN_0042b780(puVar5,*(uint **)((int)this + 4));
  if (param_3 != '\0') {
    *(uint **)((int)this + 0xc) = puVar5;
  }
  return puVar5;
}


