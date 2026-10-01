// 00437ad0 FUN_00437ad0 [Global]
// program: gamma.dll

void __thiscall FUN_00437ad0(void *this,uint param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  void *pvVar4;
  void *local_38;
  uint local_34;
  int local_30;
  uint *local_2c;
  undefined1 *local_14;
  
  if (*(uint *)this < param_1) {
    local_34 = 0;
    local_2c = (uint *)0x0;
    local_30 = 0;
    puVar3 = FUN_0044e010(param_1 * 0x11c);
    local_34 = param_1;
    pvVar4 = *(void **)((int)this + 8);
    local_38 = (void *)(*(int *)((int)this + 4) * 0x11c + (int)pvVar4);
    local_2c = puVar3;
    if (pvVar4 < local_38) {
      do {
        if (puVar3 != (uint *)0x0) {
          local_14 = (undefined1 *)&local_38;
          FUN_00435810(puVar3,pvVar4);
        }
        pvVar4 = (void *)((int)pvVar4 + 0x11c);
        puVar3 = puVar3 + 0x47;
        local_30 = local_30 + 1;
      } while (pvVar4 < local_38);
    }
    if (&local_34 != this) {
      uVar1 = *(uint *)this;
      *(uint *)this = local_34;
      puVar3 = *(uint **)((int)this + 8);
      *(uint **)((int)this + 8) = local_2c;
      iVar2 = *(int *)((int)this + 4);
      *(int *)((int)this + 4) = local_30;
      local_34 = uVar1;
      local_30 = iVar2;
      local_2c = puVar3;
    }
    FUN_00437be0((int)&local_34);
    if (local_2c != (uint *)0x0) {
      FUN_0044e100(local_2c);
    }
  }
  return;
}


