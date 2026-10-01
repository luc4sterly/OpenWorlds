// 00442fd0 FUN_00442fd0 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_00442fd0(void *this,int param_1)

{
  uint *this_00;
  
  this_00 = FUN_0044e010(0x15c);
  if (this_00 != (uint *)0x0) {
    FUN_004425f0(this_00,param_1);
  }
  *(uint **)this = this_00;
  return this;
}


