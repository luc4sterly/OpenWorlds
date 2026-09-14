// 00438a40 FUN_00438a40 [Global]
// programa: gamma.dll

void __thiscall FUN_00438a40(void *this,uint param_1)

{
  uint uVar1;
  uint *puVar2;
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
    puVar2 = FUN_0044e010(param_1 * 0x1c);
    local_34 = param_1;
    puVar5 = (uint *)local_38[2];
    puVar3 = puVar5 + local_38[1] * 7;
    puVar4 = puVar2;
    uVar1 = local_30;
    for (; puVar5 < puVar3; puVar5 = puVar5 + 7) {
      if (puVar4 != (uint *)0x0) {
        *puVar4 = *puVar5;
        puVar4[1] = puVar5[1];
        puVar4[2] = puVar5[2];
        puVar4[3] = puVar5[3];
        puVar4[4] = puVar5[4];
        puVar4[5] = puVar5[5];
        puVar4[6] = puVar5[6];
        local_14 = (undefined1 *)&local_38;
      }
      puVar4 = puVar4 + 7;
      uVar1 = uVar1 + 1;
    }
    local_30 = uVar1;
    local_2c = puVar2;
    if (&local_34 != local_38) {
      local_34 = *local_38;
      *local_38 = param_1;
      local_2c = (uint *)local_38[2];
      local_38[2] = (uint)puVar2;
      local_30 = local_38[1];
      local_38[1] = uVar1;
    }
    FUN_00439280((int)&local_34);
    if (local_2c != (uint *)0x0) {
      FUN_0044e100(local_2c);
    }
  }
  return;
}


