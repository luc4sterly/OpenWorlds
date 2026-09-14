// 00411980 FUN_00411980 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_00411980(void *this,uint param_1,LPCSTR param_2,byte param_3)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  undefined **local_20;
  int local_1c [2];
  undefined ***local_14;
  int *local_10;
  
  if ((param_1 & 1) != 0) {
    *(int *)((int)this + 4) = (int)this + 0x50;
    *(undefined4 *)((int)this + 0x50) = &PTR_LAB_0046f410;
    *(undefined4 *)((int)this + 0x50) = &PTR_LAB_0046f34c;
  }
  FUN_00411ef0(this,0,(int)this + 0xc);
  *(undefined ***)this = &PTR_FUN_0046f3e8;
  **(undefined4 **)((int)this + 4) = &PTR_LAB_0046f3f4;
  *(int *)(*(int *)((int)this + 4) + 0x3c) = (int)this + (0x50 - *(int *)((int)this + 4));
  FUN_00412420((void *)((int)this + 0xc),0);
  piVar2 = FUN_00411bf0((void *)((int)this + 0xc),param_2,param_3 | 8);
  if (piVar2 == (int *)0x0) {
    iVar3 = *(int *)((int)this + 4);
    *(byte *)(iVar3 + 0x32) = *(byte *)(iVar3 + 0x32) | 4;
    if (*(int *)(iVar3 + 0x24) == 0) {
      *(byte *)(iVar3 + 0x32) = *(byte *)(iVar3 + 0x32) | 1;
    }
    if ((*(byte *)(iVar3 + 0x33) & *(byte *)(iVar3 + 0x32)) != 0) {
      local_14 = &local_20;
      local_20 = &PTR_LAB_0046d4fc;
      local_10 = local_1c;
      iVar3 = FUN_00450b60(0x1a);
      FUN_00403d80(local_10,iVar3);
      pcVar1 = (char *)*local_10;
      *(undefined4 *)pcVar1 = s_ios_base_failure_in_clear_0046f264._0_4_;
      *(undefined4 *)(pcVar1 + 4) = s_ios_base_failure_in_clear_0046f264._4_4_;
      *(undefined4 *)(pcVar1 + 8) = s_ios_base_failure_in_clear_0046f264._8_4_;
      *(undefined4 *)(pcVar1 + 0xc) = s_ios_base_failure_in_clear_0046f264._12_4_;
      *(undefined4 *)(pcVar1 + 0x10) = s_ios_base_failure_in_clear_0046f264._16_4_;
      *(undefined4 *)(pcVar1 + 0x14) = s_ios_base_failure_in_clear_0046f264._20_4_;
      *(undefined2 *)(pcVar1 + 0x18) = s_ios_base_failure_in_clear_0046f264._24_2_;
      FUN_00451670();
    }
  }
  return this;
}


