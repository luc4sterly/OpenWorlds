// 0042b5f0 FUN_0042b5f0 [Global]
// programa: gamma.dll

uint * __thiscall
FUN_0042b5f0(void *this,undefined4 *param_1,char param_2,char param_3,uint *param_4)

{
  char *pcVar1;
  int iVar2;
  uint *puVar3;
  undefined1 auStack_58 [4];
  undefined **local_54;
  int local_50 [7];
  undefined1 *local_34;
  undefined1 *local_1c;
  undefined ***local_18;
  int *local_14;
  
  if (*(int *)this == -1) {
    local_18 = &local_54;
    local_54 = &PTR_FUN_0046db74;
    local_14 = local_50;
    iVar2 = FUN_00450b60(0x1a);
    FUN_00403d80(local_14,iVar2);
    pcVar1 = (char *)*local_14;
    *(undefined4 *)pcVar1 = s_tree__insert_length_error_00474748._0_4_;
    *(undefined4 *)(pcVar1 + 4) = s_tree__insert_length_error_00474748._4_4_;
    *(undefined4 *)(pcVar1 + 8) = s_tree__insert_length_error_00474748._8_4_;
    *(undefined4 *)(pcVar1 + 0xc) = s_tree__insert_length_error_00474748._12_4_;
    *(undefined4 *)(pcVar1 + 0x10) = s_tree__insert_length_error_00474748._16_4_;
    *(undefined4 *)(pcVar1 + 0x14) = s_tree__insert_length_error_00474748._20_4_;
    *(undefined2 *)(pcVar1 + 0x18) = s_tree__insert_length_error_00474748._24_2_;
    local_54 = &PTR_LAB_0046db64;
    FUN_00451670();
  }
  puVar3 = FUN_0044e010(0x14);
  if (puVar3 + 3 != (uint *)0x0) {
    puVar3[3] = *param_4;
    puVar3[4] = param_4[1];
    local_1c = auStack_58;
  }
  puVar3[1] = 0;
  *puVar3 = puVar3[1];
  puVar3[2] = puVar3[2] & 1 | (uint)param_1;
  if (param_2 == '\0') {
    param_1[1] = puVar3;
  }
  else {
    *param_1 = puVar3;
  }
  *(int *)this = *(int *)this + 1;
  local_34 = auStack_58;
  FUN_0042b780(puVar3,*(uint **)((int)this + 4));
  if (param_3 != '\0') {
    *(uint **)((int)this + 0xc) = puVar3;
  }
  return puVar3;
}


