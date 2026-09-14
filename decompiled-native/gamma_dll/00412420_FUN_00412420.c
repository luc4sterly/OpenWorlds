// 00412420 FUN_00412420 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_00412420(void *this,undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  int local_44 [8];
  undefined1 local_21;
  
  *(undefined ***)this = &PTR_LAB_0046f370;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  FUN_00412510((int *)((int)this + 0x1c));
  *(undefined ***)this = &PTR_LAB_0046f3ac;
  *(undefined4 *)((int)this + 0x24) = param_1;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined1 *)((int)this + 0x40) = 0;
  *(undefined1 *)((int)this + 0x42) = 1;
  FUN_00410f00(this,local_44);
  local_21 = DAT_00489370;
  iVar2 = FUN_00411e00(local_44);
  *(int *)((int)this + 0x2c) = iVar2;
  FUN_00404dc0(local_44);
  uVar1 = (**(code **)(**(int **)((int)this + 0x2c) + 0x14))();
  *(undefined1 *)((int)this + 0x41) = uVar1;
  return this;
}


