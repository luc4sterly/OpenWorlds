// 00426ca0 FUN_00426ca0 [Global]
// program: gamma.dll

void __thiscall FUN_00426ca0(void *this,int param_1)

{
  if (*(int *)this + *(int *)((int)this + 4) != DAT_0049d280) {
    FUN_00402800(s_memscrat_00471cc0,0x3d);
  }
  DAT_0049d284 = DAT_0049d284 + *(int *)((int)this + 4);
  DAT_0049d280 = *(int *)this;
  if (DAT_0049d284 < param_1) {
    FUN_00402800(s_memscrat_00471cc0,0x2c);
  }
  *(int *)this = DAT_0049d280;
  *(int *)((int)this + 4) = param_1;
  DAT_0049d280 = DAT_0049d280 + param_1;
  DAT_0049d284 = DAT_0049d284 - param_1;
  return;
}


