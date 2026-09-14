// 0042ee00 FUN_0042ee00 [Global]
// programa: gamma.dll

void __thiscall FUN_0042ee00(void *this,uint param_1)

{
  uint *puVar1;
  uint uVar2;
  void *this_00;
  uint uVar3;
  uint *local_40;
  uint *local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint *local_2c;
  undefined1 *local_14;
  
  if (*(uint *)this < param_1) {
    local_34 = 0;
    local_2c = (uint *)0x0;
    local_30 = 0;
    local_3c = this;
    local_40 = FUN_0044e010(param_1 * 0x11c);
    local_34 = param_1;
    uVar3 = local_3c[2];
    local_38 = local_3c[1] * 0x11c + uVar3;
    local_2c = local_40;
    if (uVar3 < local_38) {
      do {
        this_00 = (void *)FUN_00406440(0x11c,local_40);
        if (this_00 != (void *)0x0) {
          local_14 = (undefined1 *)&local_40;
          FUN_0042c070(this_00,uVar3);
        }
        uVar3 = uVar3 + 0x11c;
        local_40 = local_40 + 0x47;
        local_30 = local_30 + 1;
      } while (uVar3 < local_38);
    }
    if (&local_34 != local_3c) {
      uVar3 = *local_3c;
      *local_3c = local_34;
      puVar1 = (uint *)local_3c[2];
      local_3c[2] = (uint)local_2c;
      uVar2 = local_3c[1];
      local_3c[1] = local_30;
      local_34 = uVar3;
      local_30 = uVar2;
      local_2c = puVar1;
    }
    FUN_0042c440((int)&local_34);
  }
  return;
}


