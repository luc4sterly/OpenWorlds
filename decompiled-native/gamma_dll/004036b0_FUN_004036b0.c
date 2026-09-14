// 004036b0 FUN_004036b0 [Global]
// programa: gamma.dll

void __thiscall FUN_004036b0(void *this,byte param_1)

{
  char *pcVar1;
  int iVar2;
  undefined **local_20;
  int local_1c [2];
  undefined ***local_14;
  int *local_10;
  
  *(byte *)((int)this + 0x32) = *(byte *)((int)this + 0x32) | param_1;
  if (*(int *)((int)this + 0x24) == 0) {
    *(byte *)((int)this + 0x32) = *(byte *)((int)this + 0x32) | 1;
  }
  if ((*(byte *)((int)this + 0x33) & *(byte *)((int)this + 0x32)) != 0) {
    local_14 = &local_20;
    local_20 = &PTR_LAB_0046d4fc;
    local_10 = local_1c;
    iVar2 = FUN_00450b60(0x1a);
    FUN_00403d80(local_10,iVar2);
    pcVar1 = (char *)*local_10;
    *(undefined4 *)pcVar1 = s_ios_base_failure_in_clear_0046d45c._0_4_;
    *(undefined4 *)(pcVar1 + 4) = s_ios_base_failure_in_clear_0046d45c._4_4_;
    *(undefined4 *)(pcVar1 + 8) = s_ios_base_failure_in_clear_0046d45c._8_4_;
    *(undefined4 *)(pcVar1 + 0xc) = s_ios_base_failure_in_clear_0046d45c._12_4_;
    *(undefined4 *)(pcVar1 + 0x10) = s_ios_base_failure_in_clear_0046d45c._16_4_;
    *(undefined4 *)(pcVar1 + 0x14) = s_ios_base_failure_in_clear_0046d45c._20_4_;
    *(undefined2 *)(pcVar1 + 0x18) = s_ios_base_failure_in_clear_0046d45c._24_2_;
    FUN_00451670();
  }
  return;
}


