// 00439db0 FUN_00439db0 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_00439db0(void *this,int param_1)

{
  FUN_0042f2c0(this);
  *(undefined ***)this = &PTR_LAB_00476e90;
  *(undefined ***)this = &PTR_LAB_00476e60;
  *(undefined4 *)((int)this + 8) = &PTR_LAB_00474bac;
  *(undefined4 *)((int)this + 8) = &PTR_LAB_00475468;
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 4);
  if (*(int *)((int)this + 0xc) != 0) {
    FUN_0042f330(*(int *)((int)this + 0xc));
  }
  return this;
}


