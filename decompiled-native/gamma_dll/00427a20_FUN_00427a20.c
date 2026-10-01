// 00427a20 FUN_00427a20 [Global]
// program: gamma.dll

uint * __thiscall FUN_00427a20(void *this,uint param_1)

{
  *(uint *)this = param_1 / 1000;
  *(uint *)((int)this + 4) = param_1 % 1000;
  return this;
}


