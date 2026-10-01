// 00451840 FUN_00451840 [Global]
// program: gamma.dll

void * __cdecl FUN_00451840(void *param_1)

{
  uint *this;
  uint uVar1;
  int local_10 [2];
  
  this = FUN_0044e010(0x10);
  if (this != (uint *)0x0) {
    FUN_00453a10(this,0);
  }
  FUN_004536d0(local_10,(int)this);
  uVar1 = FUN_0044d690(&DAT_00481374);
  FUN_004537b0((void *)(local_10[0] + 0xc),(undefined4 *)&DAT_00481374,uVar1);
  FUN_004049e0(param_1,local_10);
  FUN_00404dc0(local_10);
  return param_1;
}


