// 0042c070 FUN_0042c070 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_0042c070(void *this,int param_1)

{
  *(undefined ***)this = &PTR_LAB_00471ff8;
  FUN_0044d6d0((char *)((int)this + 4),(char *)(param_1 + 4),0xff);
  *(undefined1 *)((int)this + 0x103) = 0;
  FUN_0042c0e0((void *)((int)this + 0x104),param_1 + 0x104);
  FUN_0042c0e0((void *)((int)this + 0x110),param_1 + 0x110);
  return this;
}


