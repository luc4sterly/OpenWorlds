// 10001efe FUN_10001efe [Global]
// programa: RWDLDD21.DLL

undefined4 __thiscall FUN_10001efe(void *this)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  undefined4 in_EAX;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  int *piVar7;
  uint **ppuVar8;
  undefined4 uStack00000038;
  int in_stack_0000005c;
  int in_stack_00000070;
  undefined4 uStack00000074;
  int in_stack_000000a0;
  int in_stack_000000c8;
  undefined4 uStack000000cc;
  int in_stack_000000dc;
  int *in_stack_00000108;
  int *in_stack_0000010c;
  int *in_stack_00000110;
  int *in_stack_00000114;
  int *in_stack_00000124;
  int *in_stack_00000128;
  int *in_stack_0000012c;
  int *in_stack_00000130;
  int *in_stack_00000134;
  int *in_stack_0000013c;
  int *in_stack_00000154;
  uint *apuStack_30 [4];
  int iStack_20;
  undefined1 *puStack_1c;
  undefined4 uStack_18;
  
  puVar6 = &stack0x00000074;
  for (; this != (void *)0x0; this = (void *)((int)this + -1)) {
    *puVar6 = in_EAX;
    puVar6 = puVar6 + 1;
  }
  uStack_18 = 0x11;
  puStack_1c = (undefined1 *)&stack0x00000074;
  uStack00000074 = 0x6c;
  iStack_20 = 0;
  apuStack_30[3] = (uint *)in_stack_00000154;
  apuStack_30[2] = (uint *)0x10001f31;
  iVar4 = (**(code **)(*in_stack_00000154 + 100))();
  if (iVar4 == -0x7789fe3e) {
    apuStack_30[2] = (uint *)&LAB_10001b40;
    puVar6 = (undefined4 *)&stack0xfffffff4;
    for (iVar4 = 0x1b; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    apuStack_30[1] = (uint *)0x0;
    apuStack_30[0] = (uint *)&stack0xfffffff4;
    in_stack_0000005c = 0x4000;
    (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10);
    if (DAT_10036038 != (int *)0x0) {
      (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
    }
    if (DAT_1003603c != DAT_10036038) {
      (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
    }
    iVar4 = (**(code **)(*in_stack_0000012c + 100))(in_stack_0000012c,0,&stack0x0000004c,0x11,0);
  }
  if (iVar4 != 0) {
    return 0;
  }
  apuStack_30[2] = (uint *)0x0;
  puVar6 = &stack0x000000cc;
  for (iVar4 = 0x1b; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  apuStack_30[1] = (uint *)0x21;
  apuStack_30[0] = &stack0x000000cc;
  uStack000000cc = 0x6c;
  iVar4 = (**(code **)(*in_stack_0000013c + 100))(in_stack_0000013c,0);
  if (iVar4 == -0x7789fe3e) {
    piVar7 = &iStack_20;
    for (iVar4 = 0x1b; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar7 = 0;
      piVar7 = piVar7 + 1;
    }
    iStack_20 = 0x6c;
    puStack_1c = (undefined1 *)0x1;
    (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,&iStack_20,0,&LAB_10001b40);
    if (DAT_10036038 != (int *)0x0) {
      (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
    }
    if (DAT_1003603c != DAT_10036038) {
      (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
    }
    iVar4 = (**(code **)(*in_stack_00000114 + 100))(in_stack_00000114,0,&stack0x000000a4,0x21,0);
  }
  if (iVar4 != 0) {
    iVar4 = (**(code **)(*in_stack_0000012c + 0x80))(in_stack_0000012c,0);
    if (iVar4 == -0x7789fe3e) {
      ppuVar8 = apuStack_30 + 2;
      for (iVar4 = 0x1b; iVar4 != 0; iVar4 = iVar4 + -1) {
        *ppuVar8 = (uint *)0x0;
        ppuVar8 = ppuVar8 + 1;
      }
      apuStack_30[2] = (uint *)0x6c;
      apuStack_30[3] = (uint *)0x1;
      (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,apuStack_30 + 2,0,&LAB_10001b40);
      if (DAT_10036038 != (int *)0x0) {
        (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
      }
      if (DAT_1003603c != DAT_10036038) {
        (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
      }
      (**(code **)(*in_stack_00000110 + 0x80))(in_stack_00000110,0);
    }
    return 0;
  }
  apuStack_30[2] =
       (uint *)(in_stack_0000005c * in_stack_00000134[1] + *in_stack_00000134 * 2 +
               in_stack_00000070);
  apuStack_30[3] =
       (uint *)(in_stack_00000130[1] * in_stack_000000c8 + *in_stack_00000130 * 2 +
               in_stack_000000dc);
  iStack_20 = in_stack_00000134[2] - *in_stack_00000134;
  iVar4 = in_stack_00000134[3] - in_stack_00000134[1];
  FUN_10002490((int)&stack0x00000094,(int)&stack0x00000100);
  if (in_stack_000000a0 == 0x10) {
    if (in_stack_0000010c == (int *)0x10) {
      for (; puVar1 = apuStack_30[2], puVar2 = apuStack_30[3], iVar3 = iStack_20, iVar4 != 0;
          iVar4 = iVar4 + -1) {
        for (; iVar3 != 0; iVar3 = iVar3 + -1) {
          uVar5 = FUN_100027c0((uint)(ushort)*puVar1);
          *(short *)puVar2 = (short)uVar5;
          puVar1 = (uint *)((int)puVar1 + 2);
          puVar2 = (uint *)((int)puVar2 + 2);
        }
        apuStack_30[2] = (uint *)((int)apuStack_30[2] + in_stack_0000005c);
        apuStack_30[3] = (uint *)((int)apuStack_30[3] + in_stack_000000c8);
      }
      goto LAB_10002350;
    }
    if (in_stack_0000010c == (int *)0x20) {
      for (; puVar1 = apuStack_30[2], puVar2 = apuStack_30[3], iVar3 = iStack_20, iVar4 != 0;
          iVar4 = iVar4 + -1) {
        for (; iVar3 != 0; iVar3 = iVar3 + -1) {
          uVar5 = FUN_100027c0((uint)(ushort)*puVar1);
          *puVar2 = uVar5;
          puVar1 = (uint *)((int)puVar1 + 2);
          puVar2 = puVar2 + 1;
        }
        apuStack_30[2] = (uint *)((int)apuStack_30[2] + in_stack_0000005c);
        apuStack_30[3] = (uint *)((int)apuStack_30[3] + in_stack_000000c8);
      }
      goto LAB_10002350;
    }
  }
  if (in_stack_000000a0 == 0x20) {
    if (in_stack_0000010c == (int *)0x10) {
      for (; puVar1 = apuStack_30[2], puVar2 = apuStack_30[3], iVar3 = iStack_20, iVar4 != 0;
          iVar4 = iVar4 + -1) {
        for (; iVar3 != 0; iVar3 = iVar3 + -1) {
          uVar5 = FUN_100027c0(*puVar1);
          *(short *)puVar2 = (short)uVar5;
          puVar1 = puVar1 + 1;
          puVar2 = (uint *)((int)puVar2 + 2);
        }
        apuStack_30[2] = (uint *)((int)apuStack_30[2] + in_stack_0000005c);
        apuStack_30[3] = (uint *)((int)apuStack_30[3] + in_stack_000000c8);
      }
    }
    else if (in_stack_0000010c == (int *)0x20) {
      for (; puVar1 = apuStack_30[2], puVar2 = apuStack_30[3], iVar3 = iStack_20, iVar4 != 0;
          iVar4 = iVar4 + -1) {
        for (; iVar3 != 0; iVar3 = iVar3 + -1) {
          uVar5 = FUN_100027c0(*puVar1);
          *puVar2 = uVar5;
          puVar1 = puVar1 + 1;
          puVar2 = puVar2 + 1;
        }
        apuStack_30[2] = (uint *)((int)apuStack_30[2] + in_stack_0000005c);
        apuStack_30[3] = (uint *)((int)apuStack_30[3] + in_stack_000000c8);
      }
    }
  }
LAB_10002350:
  iVar4 = (**(code **)(*in_stack_00000128 + 0x80))(in_stack_00000128,0);
  if (iVar4 == -0x7789fe3e) {
    ppuVar8 = apuStack_30 + 2;
    for (iVar4 = 0x1b; iVar4 != 0; iVar4 = iVar4 + -1) {
      *ppuVar8 = (uint *)0x0;
      ppuVar8 = ppuVar8 + 1;
    }
    apuStack_30[2] = (uint *)0x6c;
    apuStack_30[3] = (uint *)0x1;
    (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,apuStack_30 + 2,0,&LAB_10001b40);
    if (DAT_10036038 != (int *)0x0) {
      (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
    }
    if (DAT_1003603c != DAT_10036038) {
      (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
    }
    (**(code **)(*in_stack_0000010c + 0x80))(in_stack_0000010c,0);
  }
  iVar4 = (**(code **)(*in_stack_00000124 + 0x80))(in_stack_00000124,0);
  if (iVar4 == -0x7789fe3e) {
    ppuVar8 = apuStack_30;
    for (iVar4 = 0x1b; iVar4 != 0; iVar4 = iVar4 + -1) {
      *ppuVar8 = (uint *)0x0;
      ppuVar8 = ppuVar8 + 1;
    }
    apuStack_30[0] = (uint *)0x6c;
    apuStack_30[1] = (uint *)0x1;
    uStack00000038 = 0x4000;
    (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,apuStack_30,0,&LAB_10001b40);
    if (DAT_10036038 != (int *)0x0) {
      (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
    }
    if (DAT_1003603c != DAT_10036038) {
      (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
    }
    (**(code **)(*in_stack_00000108 + 0x80))(in_stack_00000108,0);
  }
  return 1;
}


