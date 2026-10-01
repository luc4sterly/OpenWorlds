// 0042a190 FUN_0042a190 [Global]
// program: gamma.dll

void __thiscall FUN_0042a190(void *this,uint param_1)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
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
    puVar2 = FUN_0044e010(param_1 * 0x108);
    local_34 = param_1;
    uVar3 = local_40[2];
    local_38 = local_40[1] * 0x108 + uVar3;
    local_2c = puVar2;
    if (uVar3 < local_38) {
      local_3c = &PTR_LAB_00471ff8;
      do {
        if (puVar2 != (uint *)0x0) {
          *puVar2 = (uint)local_3c;
          local_14 = (undefined1 *)&local_40;
          FUN_0044d6d0((char *)(puVar2 + 1),(char *)(uVar3 + 4),0xff);
          *(undefined1 *)((int)puVar2 + 0x103) = 0;
          puVar2[0x41] = *(uint *)(uVar3 + 0x104);
        }
        uVar3 = uVar3 + 0x108;
        puVar2 = puVar2 + 0x42;
        local_30 = local_30 + 1;
      } while (uVar3 < local_38);
    }
    if (&local_34 != local_40) {
      uVar3 = *local_40;
      *local_40 = local_34;
      puVar2 = (uint *)local_40[2];
      local_40[2] = (uint)local_2c;
      uVar1 = local_40[1];
      local_40[1] = local_30;
      local_34 = uVar3;
      local_30 = uVar1;
      local_2c = puVar2;
    }
    FUN_0042a310((int)&local_34);
    if (local_2c != (uint *)0x0) {
      FUN_0042a2c0(local_2c);
    }
  }
  return;
}


