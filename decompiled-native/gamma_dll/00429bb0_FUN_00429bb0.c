// 00429bb0 FUN_00429bb0 [Global]
// program: gamma.dll

void __thiscall FUN_00429bb0(void *this,undefined4 *param_1,undefined4 *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined **local_c8;
  undefined **local_c4;
  uint *local_c0;
  uint *local_bc;
  undefined4 *local_b8;
  undefined4 *local_b4;
  undefined4 *local_b0;
  uint local_ac;
  uint local_a8;
  uint *local_a4;
  undefined1 *local_8c;
  undefined1 *local_74;
  undefined1 *local_5c;
  undefined1 *local_44;
  undefined1 *local_2c;
  undefined1 *local_14;
  
  if (param_2 == (undefined4 *)0x0) {
    return;
  }
  local_b8 = *(undefined4 **)((int)this + 4);
  local_bc = this;
  if (*(uint *)this < (uint)((int)local_b8 + (int)param_2)) {
    local_ac = 0;
    local_a4 = (uint *)0x0;
    local_a8 = 0;
    uVar2 = *(uint *)this;
    if (uVar2 == 0) {
      uVar2 = 1;
    }
    for (; uVar2 < (uint)(*(int *)((int)this + 4) + (int)param_2); uVar2 = uVar2 * 2) {
    }
    puVar3 = FUN_0044e010(uVar2 * 0x108);
    puVar4 = (undefined4 *)local_bc[2];
    local_b0 = puVar4 + local_bc[1] * 0x42;
    local_a4 = puVar3;
    local_ac = uVar2;
    for (; puVar4 < param_1; puVar4 = puVar4 + 0x42) {
      local_c0 = puVar3;
      if (puVar3 != (uint *)0x0) {
        *puVar3 = (uint)&PTR_LAB_00471ff8;
        local_44 = (undefined1 *)&local_c8;
        FUN_0044d6d0((char *)(puVar3 + 1),(char *)(puVar4 + 1),0xff);
        *(undefined1 *)((int)puVar3 + 0x103) = 0;
        puVar3[0x41] = puVar4[0x41];
      }
      puVar3 = local_c0 + 0x42;
      local_a8 = local_a8 + 1;
    }
    for (; local_c0 = puVar3, param_2 != (undefined4 *)0x0;
        param_2 = (undefined4 *)((int)param_2 + -1)) {
      if (puVar3 != (uint *)0x0) {
        *puVar3 = (uint)&PTR_LAB_00471ff8;
        local_2c = (undefined1 *)&local_c8;
        FUN_0044d6d0((char *)(puVar3 + 1),(char *)(param_3 + 4),0xff);
        *(undefined1 *)((int)puVar3 + 0x103) = 0;
        puVar3[0x41] = *(uint *)(param_3 + 0x104);
      }
      local_a8 = local_a8 + 1;
      puVar3 = local_c0 + 0x42;
    }
    if (puVar4 < local_b0) {
      do {
        puVar3 = local_c0;
        if (local_c0 != (uint *)0x0) {
          *local_c0 = (uint)&PTR_LAB_00471ff8;
          local_14 = (undefined1 *)&local_c8;
          FUN_0044d6d0((char *)(local_c0 + 1),(char *)(puVar4 + 1),0xff);
          *(undefined1 *)((int)puVar3 + 0x103) = 0;
          puVar3[0x41] = puVar4[0x41];
        }
        puVar4 = puVar4 + 0x42;
        local_c0 = local_c0 + 0x42;
        local_a8 = local_a8 + 1;
      } while (puVar4 < local_b0);
    }
    if (&local_ac != local_bc) {
      uVar2 = *local_bc;
      *local_bc = local_ac;
      puVar3 = (uint *)local_bc[2];
      local_bc[2] = (uint)local_a4;
      uVar1 = local_bc[1];
      local_bc[1] = local_a8;
      local_ac = uVar2;
      local_a8 = uVar1;
      local_a4 = puVar3;
    }
    FUN_0042a2e0((int)&local_ac);
  }
  else {
    local_b4 = (undefined4 *)((int)local_b8 - ((int)param_1 - *(int *)((int)this + 8)) / 0x108);
    puVar4 = (undefined4 *)((int)local_b8 * 0x108 + *(int *)((int)this + 8));
    local_b8 = puVar4;
    if (local_b4 < param_2) {
      if (local_b4 < param_2) {
        do {
          if (puVar4 != (undefined4 *)0x0) {
            *puVar4 = &PTR_LAB_00471ff8;
            local_8c = (undefined1 *)&local_c8;
            FUN_0044d6d0((char *)(puVar4 + 1),(char *)(param_3 + 4),0xff);
            *(undefined1 *)((int)puVar4 + 0x103) = 0;
            puVar4[0x41] = *(undefined4 *)(param_3 + 0x104);
          }
          param_2 = (undefined4 *)((int)param_2 - 1);
          *(int *)((int)local_bc + 4) = *(int *)((int)local_bc + 4) + 1;
          puVar4 = puVar4 + 0x42;
        } while (local_b4 < param_2);
      }
      if (param_1 < local_b8) {
        local_c8 = &PTR_LAB_00471ff8;
        puVar5 = param_1;
        do {
          if (puVar4 != (undefined4 *)0x0) {
            *puVar4 = local_c8;
            local_74 = (undefined1 *)&local_c8;
            FUN_0044d6d0((char *)(puVar4 + 1),(char *)(puVar5 + 1),0xff);
            *(undefined1 *)((int)puVar4 + 0x103) = 0;
            puVar4[0x41] = puVar5[0x41];
          }
          puVar5 = puVar5 + 0x42;
          *(int *)((int)local_bc + 4) = *(int *)((int)local_bc + 4) + 1;
          puVar4 = puVar4 + 0x42;
        } while (puVar5 < local_b8);
      }
    }
    else {
      puVar5 = puVar4 + (int)param_2 * -0x42;
      if (puVar5 < puVar4) {
        local_c4 = &PTR_LAB_00471ff8;
        do {
          if (puVar4 != (undefined4 *)0x0) {
            *puVar4 = local_c4;
            local_5c = (undefined1 *)&local_c8;
            FUN_0044d6d0((char *)(puVar4 + 1),(char *)(puVar5 + 1),0xff);
            *(undefined1 *)((int)puVar4 + 0x103) = 0;
            puVar4[0x41] = puVar5[0x41];
          }
          puVar5 = puVar5 + 0x42;
          *(int *)((int)local_bc + 4) = *(int *)((int)local_bc + 4) + 1;
          puVar4 = puVar4 + 0x42;
        } while (puVar5 < local_b8);
      }
      puVar4 = param_1 + ((int)local_b4 - (int)param_2) * 0x42;
      local_b4 = puVar4;
      puVar5 = local_b8;
      for (; local_b8 = puVar5, param_1 < puVar4; puVar4 = puVar4 + -0x42) {
        local_b8 = puVar5 + -0x42;
        FUN_0044d6d0((char *)(puVar5 + -0x41),(char *)(puVar4 + -0x41),0xff);
        *(undefined1 *)((int)puVar5 - 5) = 0;
        puVar5[-1] = puVar4[-1];
        puVar5 = local_b8;
      }
    }
    for (; param_2 != (undefined4 *)0x0; param_2 = (undefined4 *)((int)param_2 + -1)) {
      FUN_0044d6d0((char *)(param_1 + 1),(char *)(param_3 + 4),0xff);
      *(undefined1 *)((int)param_1 + 0x103) = 0;
      param_1[0x41] = *(undefined4 *)(param_3 + 0x104);
      param_1 = param_1 + 0x42;
    }
  }
  return;
}


