// 00441960 FUN_00441960 [Global]
// programa: gamma.dll

undefined4 FUN_00441960(int param_1,int *param_2)

{
  uint *this;
  undefined4 uVar1;
  
  if (param_2 == (int *)0x0) {
    return 0x80004003;
  }
  this = FUN_0044e010(0x30);
  if (this != (uint *)0x0) {
    FUN_00444020(this,param_1 + -0xc,0);
  }
  *param_2 = (int)this;
  if (*param_2 == 0) {
    uVar1 = 0x8007000e;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


