// 0042e990 FUN_0042e990 [Global]
// programa: gamma.dll

void __thiscall FUN_0042e990(void *this,undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  void *this_00;
  undefined1 auStack_20 [20];
  undefined1 *local_c;
  
  iVar1 = *(int *)this;
  if (*(int *)((int)this + 4) == iVar1) {
    if (iVar1 == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = iVar1 * 2;
    }
    FUN_0042ef00(this,uVar2);
  }
  local_c = auStack_20;
  this_00 = (void *)(*(int *)((int)this + 4) * 0x4c + *(int *)((int)this + 8));
  if (this_00 != (void *)0x0) {
    FUN_0042bb00(this_00,param_1);
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
  return;
}


