// 004446f0 FUN_004446f0 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_004446f0(void *this,uint param_1)

{
  if (this != (void *)0x0) {
    if ((param_1 & 2) == 0) {
      *(undefined ***)this = &PTR_LAB_00479e3c;
      (**(code **)(**(int **)((int)this + 8) + 0x84))(*(int **)((int)this + 8));
      if ((param_1 & 1) != 0) {
        FUN_0044e100(this);
      }
    }
    else {
      FUN_00451710((int)this,&LAB_004445a0);
    }
  }
  return this;
}


