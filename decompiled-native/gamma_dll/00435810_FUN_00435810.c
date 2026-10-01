// 00435810 FUN_00435810 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_00435810(void *this,void *param_1)

{
  undefined4 local_118 [66];
  undefined4 *local_10;
  
  local_10 = (undefined4 *)((int)this + 4);
  *local_10 = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  FUN_00435e30(local_10,*(undefined4 **)((int)param_1 + 0xc),
               *(undefined4 **)((int)param_1 + 0xc) + *(int *)((int)param_1 + 8) * 6);
  *(undefined ***)this = &PTR_LAB_00475b54;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined ***)((int)this + 0x14) = &PTR_LAB_00471ff8;
  *(undefined1 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x118) = *(undefined4 *)((int)param_1 + 0x118);
  FUN_004359d0(param_1,local_118);
  FUN_004359a0(this,(int)local_118);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)((int)param_1 + 0x10);
  return this;
}


