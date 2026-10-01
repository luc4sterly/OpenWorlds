// 00423be0 FUN_00423be0 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_00423be0(void *this,uint param_1)

{
  if (this != (void *)0x0) {
    if ((param_1 & 2) == 0) {
      *(int *)(*(int *)((int)this + 4) + 0x3c) = (int)this + (0x40 - *(int *)((int)this + 4));
      *(int *)(*(int *)((int)this + 4) + 0x3c) = (int)this + (0x40 - *(int *)((int)this + 4));
      FUN_004231d0(this);
      FUN_004108d0((undefined4 *)((int)this + 0x40));
      if ((param_1 & 1) != 0) {
        FUN_0044e100(this);
      }
    }
    else {
      FUN_00451710((int)this,&LAB_00423250);
    }
  }
  return this;
}


