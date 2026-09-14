// 00409800 FUN_00409800 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_00409800(void *this,uint param_1)

{
  int *piVar1;
  
  if (this != (void *)0x0) {
    if ((param_1 & 2) == 0) {
      *(undefined ***)this = &PTR_FUN_0046db74;
      piVar1 = *(int **)((int)this + 8);
      if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
        FUN_00451780(*(undefined4 **)((int)this + 4));
        FUN_0044e100(*(undefined4 **)((int)this + 8));
      }
      *(undefined ***)this = &PTR_LAB_0046d50c;
      if ((param_1 & 1) != 0) {
        FUN_0044e100(this);
      }
    }
    else {
      FUN_00451710((int)this,&LAB_00408eb0);
    }
  }
  return this;
}


