// 00438b30 FUN_00438b30 [Global]
// programa: gamma.dll

void __thiscall FUN_00438b30(void *this,undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)this;
  if (*(int *)((int)this + 4) == iVar1) {
    if (iVar1 == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = iVar1 * 2;
    }
    FUN_00438b90(this,uVar2);
  }
  puVar3 = (undefined4 *)(*(int *)((int)this + 4) * 8 + *(int *)((int)this + 8));
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = *param_1;
    puVar3[1] = param_1[1];
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
  return;
}


