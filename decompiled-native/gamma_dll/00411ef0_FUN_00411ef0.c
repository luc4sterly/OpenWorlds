// 00411ef0 FUN_00411ef0 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_00411ef0(void *this,uint param_1,int param_2)

{
  void *this_00;
  undefined1 uVar1;
  
  if ((param_1 & 1) != 0) {
    *(int *)((int)this + 4) = (int)this + 0xc;
    *(undefined4 *)((int)this + 0xc) = &PTR_LAB_0046f410;
    *(undefined4 *)((int)this + 0xc) = &PTR_LAB_0046f34c;
  }
  *(undefined ***)this = &PTR_LAB_0046f358;
  **(undefined4 **)((int)this + 4) = &PTR_LAB_0046f364;
  *(int *)(*(int *)((int)this + 4) + 0x3c) = (int)this + (0xc - *(int *)((int)this + 4));
  *(undefined4 *)((int)this + 8) = 0;
  this_00 = *(void **)((int)this + 4);
  FUN_00454dd0(this_00,param_2);
  *(undefined4 *)((int)this_00 + 0x34) = 0;
  uVar1 = FUN_00411f80(this_00,0x20);
  *(undefined1 *)((int)this_00 + 0x38) = uVar1;
  return this;
}


