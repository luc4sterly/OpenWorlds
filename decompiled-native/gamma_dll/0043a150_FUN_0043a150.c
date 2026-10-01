// 0043a150 FUN_0043a150 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_0043a150(void *this,int param_1,int param_2)

{
  FUN_0042f2c0(this);
  *(undefined ***)this = &PTR_LAB_00476e90;
  *(undefined ***)this = &PTR_LAB_00476e30;
  *(undefined4 *)((int)this + 8) = &PTR_LAB_00474bac;
  *(undefined4 *)((int)this + 8) = &PTR_LAB_00475468;
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 4);
  if (*(int *)((int)this + 0xc) != 0) {
    FUN_0042f330(*(int *)((int)this + 0xc));
  }
  *(undefined4 *)((int)this + 0x10) = &PTR_LAB_00474bac;
  *(undefined4 *)((int)this + 0x10) = &PTR_LAB_00475468;
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)(param_2 + 4);
  if (*(int *)((int)this + 0x14) != 0) {
    FUN_0042f330(*(int *)((int)this + 0x14));
  }
  return this;
}


