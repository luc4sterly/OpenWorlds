// 0042e930 FUN_0042e930 [Global]
// program: gamma.dll

void * __thiscall FUN_0042e930(void *this,void *param_1)

{
  if (this != param_1) {
    FUN_0042ebd0(this,*(int *)((int)param_1 + 8),
                 *(int *)((int)param_1 + 4) * 0x104 + *(int *)((int)param_1 + 8));
  }
  return this;
}


