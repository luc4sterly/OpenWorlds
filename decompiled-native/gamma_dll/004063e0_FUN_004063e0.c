// 004063e0 FUN_004063e0 [Global]
// program: gamma.dll

int __thiscall FUN_004063e0(void *this,undefined4 param_1,uint param_2)

{
  uint *puVar1;
  
  *(uint *)((int)this + 4) = (param_2 + 3) - (param_2 & 3);
  *(undefined4 *)((int)this + 8) = 1;
  puVar1 = FUN_0044e010(*(int *)((int)this + 4) + 1);
  *(uint **)((int)this + 0xc) = puVar1;
  InitializeCriticalSection((LPCRITICAL_SECTION)((int)this + 0x10));
  return (int)this;
}


