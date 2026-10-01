// 0042ada0 FUN_0042ada0 [Global]
// program: gamma.dll

void __thiscall FUN_0042ada0(void *this,undefined4 param_1)

{
  undefined4 uVar1;
  
  if (*(int *)((int)this + 0x28) == 0) {
    uVar1 = (**(code **)(*(int *)this + 8))(*(undefined4 *)((int)this + 0x20),0x4000);
    *(undefined4 *)((int)this + 0x28) = uVar1;
  }
  FUN_0042af10(this,*(undefined4 **)((int)this + 0x28),param_1);
  FUN_0042ae30((int)this);
  return;
}


