// 00430ad0 FUN_00430ad0 [Global]
// programa: gamma.dll

void __thiscall FUN_00430ad0(void *this,undefined4 *param_1,undefined4 *param_2,int param_3)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined1 auStack_110 [4];
  undefined **local_10c;
  undefined **local_108;
  undefined **local_104;
  undefined **local_100;
  undefined4 *local_fc;
  undefined **local_f8;
  undefined **local_f4;
  uint *local_f0;
  undefined4 *local_ec;
  undefined4 *local_e8;
  uint *local_e4;
  undefined4 *local_e0;
  uint local_dc;
  uint local_d8;
  uint *local_d4;
  undefined1 *local_bc;
  undefined1 *local_a4;
  undefined1 *local_8c;
  undefined1 *local_74;
  undefined1 *local_5c;
  undefined1 *local_44;
  undefined4 *local_40;
  undefined4 *local_3c;
  undefined4 *local_38;
  uint *local_34;
  uint *local_30;
  uint *local_2c;
  undefined4 *local_28;
  undefined4 *local_24;
  undefined4 *local_20;
  uint *local_1c;
  uint *local_18;
  uint *local_14;
  
  if (param_2 != (undefined4 *)0x0) {
    local_ec = *(undefined4 **)((int)this + 4);
    local_e4 = this;
    if (*(uint *)this < (uint)((int)local_ec + (int)param_2)) {
      local_dc = 0;
      local_d4 = (uint *)0x0;
      local_d8 = 0;
      uVar4 = *(uint *)this;
      if (uVar4 == 0) {
        uVar4 = 1;
      }
      for (; uVar4 < (uint)(*(int *)((int)this + 4) + (int)param_2); uVar4 = uVar4 * 2) {
      }
      local_f0 = FUN_0044e010(uVar4 * 0x110);
      puVar5 = (undefined4 *)local_e4[2];
      local_e0 = puVar5 + local_e4[1] * 0x44;
      local_dc = uVar4;
      local_d4 = local_f0;
      if (puVar5 < param_1) {
        local_108 = &PTR_LAB_00475040;
        do {
          if (local_f0 != (uint *)0x0) {
            local_34 = local_f0;
            *local_f0 = (uint)&PTR_LAB_00471ff8;
            local_74 = auStack_110;
            FUN_0044d6d0((char *)(local_f0 + 1),(char *)(puVar5 + 1),0xff);
            *(undefined1 *)((int)local_34 + 0x103) = 0;
            local_34[0x41] = puVar5[0x41];
            local_1c = local_34 + 0x42;
            *local_1c = (uint)&PTR_LAB_00474bac;
            *local_1c = (uint)local_108;
            local_34[0x43] = puVar5[0x43];
            if (local_34[0x43] != 0) {
              FUN_0042f330(local_34[0x43]);
            }
          }
          puVar5 = puVar5 + 0x44;
          local_f0 = local_f0 + 0x44;
          local_d8 = local_d8 + 1;
        } while (puVar5 < param_1);
      }
      if (param_2 != (undefined4 *)0x0) {
        local_104 = &PTR_LAB_00475040;
        do {
          if (local_f0 != (uint *)0x0) {
            local_30 = local_f0;
            *local_f0 = (uint)&PTR_LAB_00471ff8;
            local_5c = auStack_110;
            FUN_0044d6d0((char *)(local_f0 + 1),(char *)(param_3 + 4),0xff);
            *(undefined1 *)((int)local_30 + 0x103) = 0;
            local_30[0x41] = *(uint *)(param_3 + 0x104);
            local_18 = local_30 + 0x42;
            *local_18 = (uint)&PTR_LAB_00474bac;
            *local_18 = (uint)local_104;
            local_30[0x43] = *(uint *)(param_3 + 0x10c);
            if (local_30[0x43] != 0) {
              FUN_0042f330(local_30[0x43]);
            }
          }
          local_d8 = local_d8 + 1;
          local_f0 = local_f0 + 0x44;
          param_2 = (undefined4 *)((int)param_2 + -1);
        } while (param_2 != (undefined4 *)0x0);
      }
      if (puVar5 < local_e0) {
        local_100 = &PTR_LAB_00475040;
        do {
          if (local_f0 != (uint *)0x0) {
            local_2c = local_f0;
            *local_f0 = (uint)&PTR_LAB_00471ff8;
            local_44 = auStack_110;
            FUN_0044d6d0((char *)(local_f0 + 1),(char *)(puVar5 + 1),0xff);
            *(undefined1 *)((int)local_2c + 0x103) = 0;
            local_2c[0x41] = puVar5[0x41];
            local_14 = local_2c + 0x42;
            *local_14 = (uint)&PTR_LAB_00474bac;
            *local_14 = (uint)local_100;
            local_2c[0x43] = puVar5[0x43];
            if (local_2c[0x43] != 0) {
              FUN_0042f330(local_2c[0x43]);
            }
          }
          puVar5 = puVar5 + 0x44;
          local_f0 = local_f0 + 0x44;
          local_d8 = local_d8 + 1;
        } while (puVar5 < local_e0);
      }
      if (&local_dc != local_e4) {
        uVar4 = *local_e4;
        *local_e4 = local_dc;
        puVar2 = (uint *)local_e4[2];
        local_e4[2] = (uint)local_d4;
        uVar3 = local_e4[1];
        local_e4[1] = local_d8;
        local_dc = uVar4;
        local_d8 = uVar3;
        local_d4 = puVar2;
      }
      FUN_00431300((int)&local_dc);
      if (local_d4 != (uint *)0x0) {
        FUN_0044e100(local_d4);
      }
    }
    else {
      local_e8 = (undefined4 *)((int)local_ec - ((int)param_1 - *(int *)((int)this + 8)) / 0x110);
      puVar5 = (undefined4 *)((int)local_ec * 0x110 + *(int *)((int)this + 8));
      local_ec = puVar5;
      if (local_e8 < param_2) {
        local_fc = puVar5;
        if (local_e8 < param_2) {
          do {
            if (local_fc != (undefined4 *)0x0) {
              local_40 = local_fc;
              *local_fc = &PTR_LAB_00471ff8;
              local_bc = auStack_110;
              FUN_0044d6d0((char *)(local_fc + 1),(char *)(param_3 + 4),0xff);
              *(undefined1 *)((int)local_40 + 0x103) = 0;
              local_40[0x41] = *(undefined4 *)(param_3 + 0x104);
              local_28 = local_40 + 0x42;
              *local_28 = &PTR_LAB_00474bac;
              *local_28 = &PTR_LAB_00475040;
              local_40[0x43] = *(undefined4 *)(param_3 + 0x10c);
              if (local_40[0x43] != 0) {
                FUN_0042f330(local_40[0x43]);
              }
            }
            local_fc = local_fc + 0x44;
            param_2 = (undefined4 *)((int)param_2 - 1);
            *(int *)((int)local_e4 + 4) = *(int *)((int)local_e4 + 4) + 1;
          } while (local_e8 < param_2);
        }
        if (param_1 < local_ec) {
          local_f8 = &PTR_LAB_00475040;
          puVar5 = param_1;
          do {
            if (local_fc != (undefined4 *)0x0) {
              local_3c = local_fc;
              *local_fc = &PTR_LAB_00471ff8;
              local_a4 = auStack_110;
              FUN_0044d6d0((char *)(local_fc + 1),(char *)(puVar5 + 1),0xff);
              *(undefined1 *)((int)local_3c + 0x103) = 0;
              local_3c[0x41] = puVar5[0x41];
              local_24 = local_3c + 0x42;
              *local_24 = &PTR_LAB_00474bac;
              *local_24 = local_f8;
              local_3c[0x43] = puVar5[0x43];
              if (local_3c[0x43] != 0) {
                FUN_0042f330(local_3c[0x43]);
              }
            }
            puVar5 = puVar5 + 0x44;
            local_fc = local_fc + 0x44;
            *(int *)((int)local_e4 + 4) = *(int *)((int)local_e4 + 4) + 1;
          } while (puVar5 < local_ec);
        }
      }
      else {
        puVar6 = puVar5 + (int)param_2 * -0x44;
        if (puVar6 < puVar5) {
          local_f4 = &PTR_LAB_00475040;
          local_10c = &PTR_LAB_00474bac;
          do {
            if (puVar5 != (undefined4 *)0x0) {
              *puVar5 = &PTR_LAB_00471ff8;
              local_8c = auStack_110;
              local_38 = puVar5;
              FUN_0044d6d0((char *)(puVar5 + 1),(char *)(puVar6 + 1),0xff);
              *(undefined1 *)((int)local_38 + 0x103) = 0;
              local_38[0x41] = puVar6[0x41];
              local_20 = local_38 + 0x42;
              *local_20 = local_10c;
              *local_20 = local_f4;
              local_38[0x43] = puVar6[0x43];
              if (local_38[0x43] != 0) {
                FUN_0042f330(local_38[0x43]);
              }
            }
            puVar6 = puVar6 + 0x44;
            *(int *)((int)local_e4 + 4) = *(int *)((int)local_e4 + 4) + 1;
            puVar5 = puVar5 + 0x44;
          } while (puVar6 < local_ec);
        }
        local_e8 = param_1 + ((int)local_e8 - (int)param_2) * 0x44;
        puVar5 = local_e8;
        puVar6 = local_ec;
        while (local_ec = puVar6, param_1 < puVar5) {
          puVar7 = puVar5 + -0x44;
          local_ec = puVar6 + -0x44;
          FUN_0044d6d0((char *)(puVar6 + -0x43),(char *)(puVar5 + -0x43),0xff);
          *(undefined1 *)((int)puVar6 - 0xd) = 0;
          puVar6[-3] = puVar5[-3];
          if ((undefined4 *)puVar6[-1] != (undefined4 *)0x0) {
            FUN_0042f340((undefined4 *)puVar6[-1]);
          }
          puVar6[-1] = puVar5[-1];
          piVar1 = puVar6 + -1;
          puVar5 = puVar7;
          puVar6 = local_ec;
          if (*piVar1 != 0) {
            FUN_0042f330(*piVar1);
            puVar6 = local_ec;
          }
        }
      }
      for (; param_2 != (undefined4 *)0x0; param_2 = (undefined4 *)((int)param_2 + -1)) {
        FUN_0044d6d0((char *)(param_1 + 1),(char *)(param_3 + 4),0xff);
        *(undefined1 *)((int)param_1 + 0x103) = 0;
        param_1[0x41] = *(undefined4 *)(param_3 + 0x104);
        if ((undefined4 *)param_1[0x43] != (undefined4 *)0x0) {
          FUN_0042f340((undefined4 *)param_1[0x43]);
        }
        param_1[0x43] = *(undefined4 *)(param_3 + 0x10c);
        if (param_1[0x43] != 0) {
          FUN_0042f330(param_1[0x43]);
        }
        param_1 = param_1 + 0x44;
      }
    }
    return;
  }
  return;
}


