// 0042ea60 FUN_0042ea60 [Global]
// program: gamma.dll

void __thiscall FUN_0042ea60(void *this,uint param_1)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *local_40;
  undefined **local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint *local_2c;
  undefined1 *local_14;
  
  if (*(uint *)this < param_1) {
    local_34 = 0;
    local_2c = (uint *)0x0;
    local_30 = 0;
    local_40 = this;
    puVar3 = FUN_0044e010(param_1 * 0x104);
    local_34 = param_1;
    uVar4 = local_40[2];
    local_38 = local_40[1] * 0x104 + uVar4;
    local_2c = puVar3;
    if (uVar4 < local_38) {
      local_3c = &PTR_LAB_00471ff8;
      do {
        if (puVar3 != (uint *)0x0) {
          *puVar3 = (uint)local_3c;
          local_14 = (undefined1 *)&local_40;
          FUN_0044d6d0((char *)(puVar3 + 1),(char *)(uVar4 + 4),0xff);
          *(undefined1 *)((int)puVar3 + 0x103) = 0;
        }
        uVar4 = uVar4 + 0x104;
        puVar3 = puVar3 + 0x41;
        local_30 = local_30 + 1;
      } while (uVar4 < local_38);
    }
    if (&local_34 != local_40) {
      uVar4 = *local_40;
      *local_40 = local_34;
      puVar3 = (uint *)local_40[2];
      local_40[2] = (uint)local_2c;
      uVar1 = local_40[1];
      local_40[1] = local_30;
      local_34 = uVar4;
      local_30 = uVar1;
      local_2c = puVar3;
    }
    puVar2 = local_2c;
    puVar3 = local_2c + local_30 * 0x41;
    while (puVar2 < puVar3) {
      puVar3 = puVar3 + -0x41;
      FUN_0042ebb0(puVar3);
    }
    local_30 = 0;
    if (local_2c != (uint *)0x0) {
      FUN_0044e100(local_2c);
    }
  }
  return;
}


