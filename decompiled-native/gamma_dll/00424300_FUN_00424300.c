// 00424300 FUN_00424300 [Global]
// program: gamma.dll

void __thiscall FUN_00424300(void *this,undefined4 *param_1,int param_2)

{
  uint *puVar1;
  
  *(int *)this = param_2 - (int)param_1;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)this;
  if (*(uint *)((int)this + 4) != 0) {
    puVar1 = FUN_0044e010(*(uint *)((int)this + 4));
    *(uint **)((int)this + 8) = puVar1;
    FUN_0044df50(*(undefined4 **)((int)this + 8),param_1,param_2 - (int)param_1);
  }
  return;
}


