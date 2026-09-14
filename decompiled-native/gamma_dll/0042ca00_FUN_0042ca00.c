// 0042ca00 FUN_0042ca00 [Global]
// programa: gamma.dll

int __thiscall FUN_0042ca00(void *this,uint param_1)

{
  if (param_1 == 0xfb) {
    return (int)this + 0xc;
  }
  if (param_1 == 0xfc) {
    return (int)this + 0x58;
  }
  if (param_1 == 0xfd) {
    return (int)this + 0xa4;
  }
  if ((-1 < (int)param_1) && (param_1 < *(uint *)((int)this + 4))) {
    return param_1 * 0x4c + *(int *)((int)this + 8);
  }
  return 0;
}


