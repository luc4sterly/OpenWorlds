// 00444020 FUN_00444020 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_00444020(void *this,undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  *(undefined **)this = &DAT_00477514;
  *(undefined **)this = &DAT_00479eb0;
  *(undefined ***)this = &PTR_LAB_00479e88;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = param_1;
  *(undefined4 *)((int)this + 0x14) = 1;
  FUN_0044b0a0((undefined4 *)((int)this + 0x18));
  (**(code **)(**(int **)((int)this + 0xc) + 0x74))(*(int **)((int)this + 0xc));
  if (param_2 == 0) {
    uVar1 = (**(code **)(**(int **)((int)this + 0xc) + 0xb0))();
    *(undefined4 *)((int)this + 0x10) = uVar1;
    uVar1 = (**(code **)(**(int **)((int)this + 0xc) + 0xb4))();
    *(undefined4 *)((int)this + 8) = uVar1;
  }
  else {
    *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_2 + 4);
    *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_2 + 8);
    *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_2 + 0x10);
    FUN_0044b1f0((void *)((int)this + 0x18),(int *)(param_2 + 0x18));
  }
  return this;
}


