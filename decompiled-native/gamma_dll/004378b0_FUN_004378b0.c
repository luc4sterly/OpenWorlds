// 004378b0 FUN_004378b0 [Global]
// program: gamma.dll

void __thiscall FUN_004378b0(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint *local_38;
  uint local_34;
  uint local_30;
  uint *local_2c;
  undefined1 *local_14;
  
  if (*(uint *)this < param_1) {
    local_34 = 0;
    local_2c = (uint *)0x0;
    local_30 = 0;
    local_38 = this;
    puVar3 = FUN_0044e010(param_1 * 0x18);
    puVar4 = (uint *)local_38[2];
    puVar5 = puVar4 + local_38[1] * 6;
    local_2c = puVar3;
    local_34 = param_1;
    for (; puVar4 < puVar5; puVar4 = puVar4 + 6) {
      if (puVar3 != (uint *)0x0) {
        *puVar3 = *puVar4;
        local_14 = (undefined1 *)&local_38;
        FUN_00428df0(puVar3 + 1,(int)(puVar4 + 1));
      }
      puVar3 = puVar3 + 6;
      local_30 = local_30 + 1;
    }
    if (&local_34 != local_38) {
      uVar1 = *local_38;
      *local_38 = local_34;
      puVar4 = (uint *)local_38[2];
      local_38[2] = (uint)local_2c;
      uVar2 = local_38[1];
      local_38[1] = local_30;
      local_34 = uVar1;
      local_30 = uVar2;
      local_2c = puVar4;
    }
    FUN_00436080((int)&local_34);
  }
  return;
}


