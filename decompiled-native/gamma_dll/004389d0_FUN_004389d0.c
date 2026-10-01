// 004389d0 FUN_004389d0 [Global]
// program: gamma.dll

void __thiscall FUN_004389d0(void *this,undefined4 *param_1)

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
    FUN_00438a40(this,uVar2);
  }
  puVar3 = (undefined4 *)(*(int *)((int)this + 4) * 0x1c + *(int *)((int)this + 8));
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = *param_1;
    puVar3[1] = param_1[1];
    puVar3[2] = param_1[2];
    puVar3[3] = param_1[3];
    puVar3[4] = param_1[4];
    puVar3[5] = param_1[5];
    puVar3[6] = param_1[6];
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
  return;
}


