// 00449ba0 FUN_00449ba0 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_00449ba0(void *this,int param_1,undefined4 param_2,undefined4 *param_3)

{
  FUN_004456a0(this,0,param_1,param_1 + 0x74,param_2,param_3);
  *(undefined ***)this = &PTR_LAB_0047b778;
  *(undefined ***)((int)this + 0xc) = &PTR_LAB_0047b790;
  *(undefined ***)((int)this + 0x10) = &PTR_LAB_0047b7e0;
  *(undefined ***)((int)this + 0x94) = &PTR_LAB_0047b86c;
  *(int *)((int)this + 0xd0) = param_1;
  return this;
}


