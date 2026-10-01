// 00446130 FUN_00446130 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_00446130(void *this,uint param_1)

{
  int *piVar1;
  
  if (this != (void *)0x0) {
    if ((param_1 & 2) == 0) {
      *(undefined ***)this = &PTR_FUN_00479ed4;
      *(undefined ***)((int)this + 0xc) = &PTR_LAB_00479eec;
      *(undefined ***)((int)this + 0x10) = &PTR_LAB_00479f30;
      FUN_00451780(*(undefined4 **)((int)this + 0x38));
      piVar1 = *(int **)((int)this + 0x18);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        *(undefined4 *)((int)this + 0x18) = 0;
      }
      *(undefined ***)this = &PTR_FUN_0047a004;
      FUN_00446370((int)this + 4);
      if ((param_1 & 1) != 0) {
        FUN_0044e100(this);
      }
    }
    else {
      FUN_00451710((int)this,FUN_00443880);
    }
  }
  return this;
}


