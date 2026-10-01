// 00424260 FUN_00424260 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_00424260(void *this,undefined4 *param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  undefined **local_28;
  undefined4 local_24 [3];
  undefined ***local_18;
  undefined4 *local_14;
  
  *(undefined4 *)this = 0;
  if (param_2 == -1) {
    local_18 = &local_28;
    local_28 = &PTR_FUN_0046db74;
    local_14 = local_24;
    iVar1 = FUN_00450b60(0x21);
    FUN_00403d80(local_14,iVar1);
    pcVar2 = s_string_constructor__n_>_max_size_004716c4;
    pcVar3 = (char *)*local_14;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined4 *)pcVar3 = *(undefined4 *)pcVar2;
      pcVar2 = pcVar2 + 4;
      pcVar3 = pcVar3 + 4;
    }
    *pcVar3 = *pcVar2;
    local_28 = &PTR_LAB_0046db64;
    FUN_00451670();
  }
  FUN_00424350(this,param_1,(int)param_1 + param_2);
  return this;
}


