// 0043bd70 FUN_0043bd70 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_0043bd70(void *this,int param_1)

{
  FUN_0042f2c0(this);
  *(undefined ***)this = &PTR_LAB_00477238;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  FUN_0043c430((undefined4 *)((int)this + 8),*(undefined4 **)(param_1 + 8),
               *(undefined4 **)(param_1 + 8) + *(int *)(param_1 + 4) * 7);
  return this;
}


