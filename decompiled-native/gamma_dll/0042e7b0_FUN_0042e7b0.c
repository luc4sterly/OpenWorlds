// 0042e7b0 FUN_0042e7b0 [Global]
// programa: gamma.dll

void __thiscall FUN_0042e7b0(void *this,int param_1)

{
  int iVar1;
  uint uVar2;
  void *this_00;
  undefined1 auStack_28 [20];
  undefined1 *local_14;
  
  iVar1 = *(int *)this;
  if (*(int *)((int)this + 4) == iVar1) {
    if (iVar1 == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = iVar1 * 2;
    }
    FUN_0042ee00(this,uVar2);
  }
  this_00 = (void *)FUN_00406440(0x11c,*(int *)((int)this + 4) * 0x11c + *(int *)((int)this + 8));
  local_14 = auStack_28;
  if (this_00 != (void *)0x0) {
    FUN_0042c070(this_00,param_1);
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
  return;
}


