// 004437d0 FUN_004437d0 [Global]
// program: gamma.dll

undefined4 * __thiscall
FUN_004437d0(void *this,undefined4 param_1,undefined4 *param_2,undefined4 param_3,
            undefined4 *param_4)

{
  FUN_004463e0(this,param_1,param_2);
  *(undefined **)((int)this + 0xc) = &DAT_00477514;
  *(undefined **)((int)this + 0xc) = &DAT_0047a04c;
  *(undefined **)((int)this + 0xc) = &DAT_0047a01c;
  *(undefined **)((int)this + 0xc) = &DAT_00479fc0;
  *(undefined **)((int)this + 0x10) = &DAT_00477514;
  *(undefined **)((int)this + 0x10) = &DAT_00479fa4;
  *(undefined ***)this = &PTR_FUN_00479ed4;
  *(undefined ***)((int)this + 0xc) = &PTR_LAB_00479eec;
  *(undefined ***)((int)this + 0x10) = &PTR_LAB_00479f30;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = *param_4;
  *(undefined4 *)((int)this + 0x28) = param_4[1];
  *(undefined4 *)((int)this + 0x2c) = param_4[2];
  *(undefined4 *)((int)this + 0x30) = param_4[3];
  *(undefined4 *)((int)this + 0x34) = param_3;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x44) = 1;
  return this;
}


