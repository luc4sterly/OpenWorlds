// 00444280 FUN_00444280 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_00444280(void *this,uint param_1)

{
  if (this != (void *)0x0) {
    if ((param_1 & 2) == 0) {
      *(undefined ***)this = &PTR_LAB_00479e88;
      (**(code **)(**(int **)((int)this + 0xc) + 0x78))(*(int **)((int)this + 0xc));
      FUN_0044b0d0((undefined4 *)((int)this + 0x18));
      if ((param_1 & 1) != 0) {
        FUN_0044e100(this);
      }
    }
    else {
      FUN_00451710((int)this,&LAB_00444130);
    }
  }
  return this;
}


