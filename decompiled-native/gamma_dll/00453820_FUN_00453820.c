// 00453820 FUN_00453820 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_00453820(void *this,char *param_1)

{
  int iVar1;
  int iVar2;
  undefined **local_28;
  undefined4 local_24 [3];
  undefined ***local_18;
  undefined4 *local_14;
  
  *(undefined4 *)this = 0;
  iVar1 = FUN_0044d690(param_1);
  if (iVar1 == -1) {
    local_18 = &local_28;
    local_28 = &PTR_FUN_0046db74;
    local_14 = local_24;
    iVar2 = FUN_0044d690(s_string_constructor__n_>_max_size_00482054);
    iVar2 = FUN_00450b60(iVar2 + 1);
    FUN_00403d80(local_14,iVar2);
    FUN_0044d6b0((char *)*local_14,s_string_constructor__n_>_max_size_00482054);
    local_28 = &PTR_LAB_0046db64;
    FUN_00451670();
  }
  FUN_00424350(this,(undefined4 *)param_1,(int)(param_1 + iVar1));
  return this;
}


