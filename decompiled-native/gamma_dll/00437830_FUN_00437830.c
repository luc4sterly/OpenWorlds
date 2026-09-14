// 00437830 FUN_00437830 [Global]
// programa: gamma.dll

void __thiscall FUN_00437830(void *this,undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined1 auStack_24 [20];
  undefined1 *local_10;
  
  iVar1 = *(int *)this;
  if (*(int *)((int)this + 4) == iVar1) {
    if (iVar1 == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = iVar1 * 2;
    }
    FUN_004378b0(this,uVar2);
  }
  local_10 = auStack_24;
  puVar3 = (undefined4 *)(*(int *)((int)this + 4) * 0x18 + *(int *)((int)this + 8));
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = *param_1;
    FUN_00428df0(puVar3 + 1,(int)(param_1 + 1));
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
  return;
}


