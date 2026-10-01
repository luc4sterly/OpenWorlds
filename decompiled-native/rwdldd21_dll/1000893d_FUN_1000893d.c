// 1000893d FUN_1000893d [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1000893d(void)

{
  int iVar1;
  undefined4 *puVar2;
  int **ppiVar3;
  undefined4 *puVar4;
  bool in_ZF;
  undefined4 uStack00000004;
  undefined4 in_stack_00000044;
  undefined4 in_stack_00000048;
  undefined4 in_stack_0000004c;
  undefined4 in_stack_00000050;
  undefined4 in_stack_00000054;
  undefined4 in_stack_00000058;
  undefined4 uStack00000068;
  undefined4 in_stack_000000b0;
  undefined4 in_stack_000000b8;
  undefined4 *puStack_38;
  int *piStack_34;
  int *piStack_30;
  int **ppiStack_2c;
  int *piStack_28;
  int *apiStack_24 [3];
  undefined4 *puStack_14;
  undefined4 uStack_10;
  
  if (in_ZF) {
    puVar2 = (undefined4 *)register0x00000010;
    for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    uStack_10 = 0;
    puStack_14 = &DAT_10036038;
    uStack00000004 = 1;
    uStack00000068 = 0x200;
    apiStack_24[2] = DAT_10036030;
    apiStack_24[1] = (int *)0x10008c08;
    iVar1 = (**(code **)(*DAT_10036030 + 0x18))();
    if (iVar1 != 0) {
      return 0;
    }
    apiStack_24[1] = (undefined4 *)0x0;
    apiStack_24[0] = (int *)&DAT_10036044;
    piStack_28 = (int *)0x0;
    DAT_1003603c = DAT_10036038;
    ppiStack_2c = (int **)DAT_10036030;
    piStack_30 = (int *)0x10008c32;
    iVar1 = (**(code **)(*DAT_10036030 + 0x10))();
    if (iVar1 != 0) {
      if (DAT_10036038 != (int *)0x0) {
        piStack_30 = DAT_10036038;
        piStack_34 = (int *)0x10008c45;
        (**(code **)(*DAT_10036038 + 8))();
        DAT_10036038 = (int *)0x0;
      }
      return 0;
    }
    piStack_30 = DAT_10036044;
    piStack_34 = DAT_1003603c;
    puStack_38 = (undefined4 *)0x10008c68;
    iVar1 = (**(code **)(*DAT_1003603c + 0x70))();
    if (iVar1 != 0) {
      if (DAT_10036044 != (int *)0x0) {
        ppiStack_2c = (int **)DAT_10036044;
        piStack_30 = (int *)0x10008c7b;
        (**(code **)(*DAT_10036044 + 8))();
        DAT_10036044 = (int *)0x0;
      }
      if (DAT_10036038 != (int *)0x0) {
        ppiStack_2c = (int **)DAT_10036038;
        piStack_30 = (int *)0x10008c94;
        (**(code **)(*DAT_10036038 + 8))();
        DAT_10036038 = (int *)0x0;
      }
      return 0;
    }
    DAT_10036040 = 0;
    DAT_10036048 = 0;
  }
  else {
    puVar2 = (undefined4 *)register0x00000010;
    for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    uStack00000004 = 0x21;
    uStack_10 = 0;
    puStack_14 = &DAT_10036038;
    uStack00000068 = 0x2218;
    apiStack_24[2] = DAT_10036030;
    apiStack_24[1] = (int *)0x1000898a;
    iVar1 = (**(code **)(*DAT_10036030 + 0x18))();
    if (iVar1 != 0) {
      return 0;
    }
    apiStack_24[1] = (int *)&DAT_1003603c;
    puVar2 = &stack0xfffffff0;
    for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    apiStack_24[0] = &stack0x00000058;
    uStack_10 = 0x6c;
    piStack_28 = DAT_10036038;
    in_stack_00000058 = 4;
    ppiStack_2c = (int **)0x100089cc;
    (**(code **)(*DAT_10036038 + 0x30))();
    if (DAT_10036058 == 0) {
      DAT_10036040 = 0;
    }
    else {
      ppiVar3 = apiStack_24 + 2;
      for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
        *ppiVar3 = (int *)0x0;
        ppiVar3 = ppiVar3 + 1;
      }
      ppiStack_2c = apiStack_24 + 2;
      apiStack_24[2] = (int *)0x6c;
      piStack_30 = DAT_10036038;
      piStack_34 = (int *)0x100089fc;
      iVar1 = (**(code **)(*DAT_10036038 + 0x58))();
      if (iVar1 == -0x7789fe3e) {
        piStack_34 = (int *)&LAB_10001b40;
        puVar2 = &stack0x00000048;
        for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar2 = 0;
          puVar2 = puVar2 + 1;
        }
        in_stack_00000048 = 0x6c;
        puStack_38 = (undefined4 *)0x0;
        in_stack_0000004c = 1;
        in_stack_000000b0 = 0x4000;
        (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,&stack0x00000048);
        if (DAT_10036038 != (int *)0x0) {
          (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
        }
        if (DAT_1003603c != DAT_10036038) {
          (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
        }
        (**(code **)(*DAT_10036038 + 0x58))(DAT_10036038,&puStack_38);
      }
      ppiVar3 = apiStack_24;
      for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
        *ppiVar3 = (int *)0x0;
        ppiVar3 = ppiVar3 + 1;
      }
      apiStack_24[0] = (int *)0x6c;
      apiStack_24[1] = (undefined4 *)0x47;
      piStack_34 = (undefined4 *)0x0;
      puStack_38 = &DAT_10036040;
      in_stack_00000044 = 0x26000;
      iVar1 = (**(code **)(*DAT_10036030 + 0x18))(DAT_10036030,apiStack_24);
      if (iVar1 != 0) {
        if (DAT_10036038 != (int *)0x0) {
          (**(code **)(*DAT_10036038 + 8))(DAT_10036038);
          DAT_10036038 = (int *)0x0;
        }
        return 0;
      }
      iVar1 = (**(code **)(*DAT_1003603c + 0xc))(DAT_1003603c,DAT_10036040);
      if (iVar1 == -0x7789fe3e) {
        ppiStack_2c = (int **)&LAB_10001b40;
        puVar2 = &stack0x00000050;
        for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar2 = 0;
          puVar2 = puVar2 + 1;
        }
        in_stack_00000050 = 0x6c;
        piStack_30 = (int *)0x0;
        in_stack_00000054 = 1;
        in_stack_000000b8 = 0x4000;
        piStack_34 = &stack0x00000050;
        puStack_38 = (undefined4 *)0x10;
        (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030);
        if (DAT_10036038 != (int *)0x0) {
          (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
        }
        if (DAT_1003603c != DAT_10036038) {
          (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
        }
        iVar1 = (**(code **)(*DAT_1003603c + 0xc))(DAT_1003603c,DAT_10036040);
      }
      if (iVar1 != 0) {
        if (DAT_10036038 != (int *)0x0) {
          ppiStack_2c = (int **)DAT_10036038;
          piStack_30 = (int *)0x10008b9c;
          (**(code **)(*DAT_10036038 + 8))();
          DAT_10036038 = (int *)0x0;
        }
        return 0;
      }
    }
    DAT_10036044 = (int *)0x0;
    DAT_10036048 = 1;
  }
  ppiVar3 = apiStack_24 + 2;
  for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppiVar3 = (int *)0x0;
    ppiVar3 = ppiVar3 + 1;
  }
  ppiStack_2c = apiStack_24 + 2;
  apiStack_24[2] = (int *)0x6c;
  piStack_30 = DAT_10036038;
  piStack_34 = (int *)0x10008cd8;
  iVar1 = (**(code **)(*DAT_10036038 + 0x58))();
  if (iVar1 == -0x7789fe3e) {
    piStack_34 = (int *)&LAB_10001b40;
    puVar2 = &stack0x00000048;
    for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    in_stack_00000048 = 0x6c;
    puStack_38 = (undefined4 *)0x0;
    in_stack_0000004c = 1;
    in_stack_000000b0 = 0x4000;
    (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,&stack0x00000048);
    if (DAT_10036038 != (int *)0x0) {
      (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
    }
    if (DAT_1003603c != DAT_10036038) {
      (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
    }
    iVar1 = (**(code **)(*DAT_10036038 + 0x58))(DAT_10036038,&puStack_38);
  }
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)&stack0x00000024;
    puVar4 = &DAT_10038b38;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar4 = puVar4 + 1;
    }
    DAT_10038a80 = apiStack_24[2];
    DAT_10038b00 = (undefined1 *)register0x00000010;
  }
  else {
    DAT_10038b48 = 0xf800;
    DAT_10038b4c = 0x7e0;
    DAT_10038b50 = 0x1f;
  }
  _DAT_10038adc = 0x40;
  _DAT_10038ae4 = 0x10;
  _DAT_10038af0 = 0x1f;
  DAT_10038a64 = 0x40;
  DAT_10038a6c = 0x10;
  _DAT_10038ae8 = 0x7c00;
  _DAT_10038aec = 0x3e0;
  DAT_10038a78 = 0x1f;
  _DAT_10038af4 = 0x8000;
  DAT_10038a70 = 0xf800;
  DAT_10038a74 = 0x7e0;
  puVar2 = &DAT_10038a60;
  puVar4 = &DAT_10038b08;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  return 1;
}


