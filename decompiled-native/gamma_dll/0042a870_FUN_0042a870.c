// 0042a870 FUN_0042a870 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_0042a870(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  *(undefined ***)this = &PTR_LAB_004744f4;
  *(undefined ***)this = &PTR_LAB_004744c4;
  *(undefined4 *)((int)this + 0x20) = param_1;
  *(undefined4 *)((int)this + 0x24) = param_2;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x38) = 1;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0xc) = 1;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 100) = 0;
  *(undefined4 *)((int)this + 0x68) = 0;
  *(undefined4 *)((int)this + 0x6c) = 0;
  *(undefined4 *)((int)this + 0x74) = 0;
  *(undefined4 *)((int)this + 0x70) = *(undefined4 *)((int)this + 0x74);
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)((int)this + 0x18);
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  uVar1 = FUN_00450b60(0x10008);
  *(undefined4 *)((int)this + 0x4c) = uVar1;
  return this;
}


