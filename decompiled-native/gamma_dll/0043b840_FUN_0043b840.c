// 0043b840 FUN_0043b840 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_0043b840(void *this,int param_1,undefined4 param_2)

{
  FUN_0042f2c0(this);
  *(undefined ***)this = &PTR_LAB_00475f94;
  *(undefined ***)this = &PTR_LAB_00476fdc;
  *(undefined4 *)((int)this + 8) = &PTR_LAB_00474bac;
  *(undefined4 *)((int)this + 8) = &PTR_LAB_00475040;
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 4);
  if (*(int *)((int)this + 0xc) != 0) {
    FUN_0042f330(*(int *)((int)this + 0xc));
  }
  *(undefined4 *)((int)this + 0x10) = param_2;
  *(undefined2 *)((int)this + 0x14) = 0;
  *(undefined2 *)((int)this + 0x16) = 0xffff;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  return this;
}


