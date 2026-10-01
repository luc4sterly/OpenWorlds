// 004358f0 FUN_004358f0 [Global]
// program: gamma.dll

void * __thiscall FUN_004358f0(void *this,void *param_1)

{
  undefined4 local_114 [66];
  
  if ((int)this + 4 != (int)param_1 + 4) {
    FUN_00435ec0((void *)((int)this + 4),*(undefined4 **)((int)param_1 + 0xc),
                 *(undefined4 **)((int)param_1 + 0xc) + *(int *)((int)param_1 + 8) * 6);
  }
  *(undefined4 *)((int)this + 0x118) = *(undefined4 *)((int)param_1 + 0x118);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)((int)param_1 + 0x10);
  FUN_004359d0(param_1,local_114);
  FUN_004359a0(this,(int)local_114);
  return this;
}


