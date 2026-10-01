// 00449f30 FUN_00449f30 [Global]
// program: gamma.dll

int * __thiscall FUN_00449f30(void *this,undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  FUN_00448520(this,param_1,param_2,param_3);
  *(undefined **)((int)this + 0xbc) = &DAT_00477514;
  *(undefined **)((int)this + 0xbc) = &DAT_0047b74c;
  *(undefined **)((int)this + 0xc0) = &DAT_00477514;
  *(undefined **)((int)this + 0xc0) = &DAT_00479dd0;
  *(undefined ***)this = &PTR_LAB_0047b574;
  *(undefined ***)((int)this + 0xc) = &PTR_LAB_0047b58c;
  *(undefined ***)((int)this + 0x10) = &PTR_LAB_0047b5d0;
  *(undefined ***)((int)this + 0xbc) = &PTR_LAB_0047b6d4;
  *(undefined ***)((int)this + 0xc0) = &PTR_LAB_0047b700;
  *(undefined4 *)((int)this + 200) = 0;
  *(undefined4 *)((int)this + 0xf8) = 0;
  *(undefined4 *)((int)this + 0xfc) = 0;
  (**(code **)(*(int *)this + 0x1b0))();
  return this;
}


