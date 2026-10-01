// 004537e0 FUN_004537e0 [Global]
// program: gamma.dll

void __thiscall FUN_004537e0(void *this,uint param_1,byte param_2)

{
  uint uVar1;
  
  uVar1 = **(uint **)this;
  FUN_00408b80(this,param_1,'\x01');
  if (uVar1 < param_1) {
    FUN_0044df90((uint *)(*(int *)(*(int *)this + 0xc) + uVar1),(uint)param_2,param_1 - uVar1);
  }
  return;
}


