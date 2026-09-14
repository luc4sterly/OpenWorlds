// 0042ef00 FUN_0042ef00 [Global]
// programa: gamma.dll

void __thiscall FUN_0042ef00(void *this,uint param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  undefined4 *puVar5;
  undefined4 *local_38;
  uint local_34;
  int local_30;
  uint *local_2c;
  undefined1 *local_14;
  
  if (*(uint *)this < param_1) {
    local_34 = 0;
    local_2c = (uint *)0x0;
    local_30 = 0;
    puVar4 = FUN_0044e010(param_1 * 0x4c);
    local_34 = param_1;
    puVar5 = *(undefined4 **)((int)this + 8);
    local_38 = puVar5 + *(int *)((int)this + 4) * 0x13;
    local_2c = puVar4;
    if (puVar5 < local_38) {
      do {
        if (puVar4 != (uint *)0x0) {
          local_14 = (undefined1 *)&local_38;
          FUN_0042bb00(puVar4,puVar5);
        }
        puVar5 = puVar5 + 0x13;
        puVar4 = puVar4 + 0x13;
        local_30 = local_30 + 1;
      } while (puVar5 < local_38);
    }
    if (&local_34 != this) {
      uVar1 = *(uint *)this;
      *(uint *)this = local_34;
      puVar4 = *(uint **)((int)this + 8);
      *(uint **)((int)this + 8) = local_2c;
      iVar2 = *(int *)((int)this + 4);
      *(int *)((int)this + 4) = local_30;
      local_34 = uVar1;
      local_30 = iVar2;
      local_2c = puVar4;
    }
    puVar3 = local_2c;
    puVar4 = local_2c + local_30 * 0x13;
    while (puVar3 < puVar4) {
      puVar4 = puVar4 + -0x13;
      FUN_0042bc60((int)puVar4);
    }
    local_30 = 0;
    if (local_2c != (uint *)0x0) {
      FUN_0044e100(local_2c);
    }
  }
  return;
}


