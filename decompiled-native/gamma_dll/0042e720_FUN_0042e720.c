// 0042e720 FUN_0042e720 [Global]
// programa: gamma.dll

void __thiscall FUN_0042e720(void *this,int param_1)

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
    FUN_0042ea60(this,uVar2);
  }
  local_10 = auStack_24;
  puVar3 = (undefined4 *)(*(int *)((int)this + 4) * 0x104 + *(int *)((int)this + 8));
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = &PTR_LAB_00471ff8;
    FUN_0044d6d0((char *)(puVar3 + 1),(char *)(param_1 + 4),0xff);
    *(undefined1 *)((int)puVar3 + 0x103) = 0;
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
  return;
}


