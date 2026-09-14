// 00438b90 FUN_00438b90 [Global]
// programa: gamma.dll

void __thiscall FUN_00438b90(void *this,uint param_1)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  undefined1 auStack_38 [4];
  uint local_34;
  int local_30;
  uint *local_2c;
  undefined1 *local_14;
  
  if (*(uint *)this < param_1) {
    local_2c = (uint *)0x0;
    local_34 = 0;
    local_30 = 0;
    puVar2 = FUN_0044e010(param_1 * 8);
    local_34 = param_1;
    puVar4 = *(uint **)((int)this + 8);
    puVar5 = puVar4 + *(int *)((int)this + 4) * 2;
    puVar3 = puVar2;
    iVar1 = local_30;
    for (; puVar4 < puVar5; puVar4 = puVar4 + 2) {
      if (puVar3 != (uint *)0x0) {
        *puVar3 = *puVar4;
        puVar3[1] = puVar4[1];
        local_14 = auStack_38;
      }
      puVar3 = puVar3 + 2;
      iVar1 = iVar1 + 1;
    }
    local_30 = iVar1;
    local_2c = puVar2;
    if (&local_34 != this) {
      local_34 = *(uint *)this;
      *(uint *)this = param_1;
      local_2c = *(uint **)((int)this + 8);
      *(uint **)((int)this + 8) = puVar2;
      local_30 = *(int *)((int)this + 4);
      *(int *)((int)this + 4) = iVar1;
    }
    FUN_004392b0((int)&local_34);
    if (local_2c != (uint *)0x0) {
      FUN_0044e100(local_2c);
    }
  }
  return;
}


