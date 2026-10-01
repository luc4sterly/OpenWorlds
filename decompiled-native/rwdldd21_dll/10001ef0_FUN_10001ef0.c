// 10001ef0 FUN_10001ef0 [Global]
// program: RWDLDD21.DLL

undefined4 FUN_10001ef0(undefined4 param_1,int *param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint *puVar6;
  int *piVar7;
  uint **ppuVar8;
  uint *apuStack_17c [4];
  int iStack_16c;
  undefined4 *puStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined1 auStack_100 [16];
  int iStack_f0;
  int iStack_dc;
  undefined4 auStack_d8 [8];
  undefined1 auStack_b8 [12];
  int iStack_ac;
  undefined1 auStack_a8 [36];
  int iStack_84;
  uint auStack_80 [4];
  int iStack_70;
  undefined1 auStack_4c [8];
  int *piStack_44;
  int *piStack_40;
  int *piStack_3c;
  int *piStack_38;
  int *piStack_28;
  int *piStack_24;
  int *piStack_20;
  int *piStack_1c;
  int *piStack_18;
  int *piStack_10;
  
  uStack_160 = 0;
  puVar5 = auStack_d8;
  for (iVar4 = 0x1b; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  uStack_164 = 0x11;
  puStack_168 = auStack_d8;
  auStack_d8[0] = 0x6c;
  iStack_16c = 0;
  apuStack_17c[3] = (uint *)param_2;
  apuStack_17c[2] = (uint *)0x10001f31;
  iVar4 = (**(code **)(*param_2 + 100))();
  if (iVar4 == -0x7789fe3e) {
    apuStack_17c[2] = (uint *)&LAB_10001b40;
    puVar5 = (undefined4 *)&stack0xfffffea8;
    for (iVar4 = 0x1b; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    apuStack_17c[1] = (uint *)0x0;
    apuStack_17c[0] = (uint *)&stack0xfffffea8;
    iStack_f0 = 0x4000;
    (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10);
    if (DAT_10036038 != (int *)0x0) {
      (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
    }
    if (DAT_1003603c != DAT_10036038) {
      (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
    }
    iVar4 = (**(code **)(*piStack_20 + 100))(piStack_20,0,auStack_100,0x11,0);
  }
  if (iVar4 != 0) {
    return 0;
  }
  apuStack_17c[2] = (uint *)0x0;
  puVar6 = auStack_80;
  for (iVar4 = 0x1b; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  apuStack_17c[1] = (uint *)0x21;
  apuStack_17c[0] = auStack_80;
  auStack_80[0] = 0x6c;
  iVar4 = (**(code **)(*piStack_10 + 100))(piStack_10,0);
  if (iVar4 == -0x7789fe3e) {
    piVar7 = &iStack_16c;
    for (iVar4 = 0x1b; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar7 = 0;
      piVar7 = piVar7 + 1;
    }
    iStack_16c = 0x6c;
    puStack_168 = (undefined4 *)0x1;
    (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,&iStack_16c,0,&LAB_10001b40);
    if (DAT_10036038 != (int *)0x0) {
      (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
    }
    if (DAT_1003603c != DAT_10036038) {
      (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
    }
    iVar4 = (**(code **)(*piStack_38 + 100))(piStack_38,0,auStack_a8,0x21,0);
  }
  if (iVar4 != 0) {
    iVar4 = (**(code **)(*piStack_20 + 0x80))(piStack_20,0);
    if (iVar4 == -0x7789fe3e) {
      ppuVar8 = apuStack_17c + 2;
      for (iVar4 = 0x1b; iVar4 != 0; iVar4 = iVar4 + -1) {
        *ppuVar8 = (uint *)0x0;
        ppuVar8 = ppuVar8 + 1;
      }
      apuStack_17c[2] = (uint *)0x6c;
      apuStack_17c[3] = (uint *)0x1;
      (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,apuStack_17c + 2,0,&LAB_10001b40);
      if (DAT_10036038 != (int *)0x0) {
        (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
      }
      if (DAT_1003603c != DAT_10036038) {
        (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
      }
      (**(code **)(*piStack_3c + 0x80))(piStack_3c,0);
    }
    return 0;
  }
  apuStack_17c[2] = (uint *)(iStack_f0 * piStack_18[1] + *piStack_18 * 2 + iStack_dc);
  apuStack_17c[3] = (uint *)(piStack_1c[1] * iStack_84 + *piStack_1c * 2 + iStack_70);
  iStack_16c = piStack_18[2] - *piStack_18;
  iVar4 = piStack_18[3] - piStack_18[1];
  FUN_10002490((int)auStack_b8,(int)auStack_4c);
  if (iStack_ac == 0x10) {
    if (piStack_40 == (int *)0x10) {
      for (; puVar6 = apuStack_17c[2], puVar1 = apuStack_17c[3], iVar2 = iStack_16c, iVar4 != 0;
          iVar4 = iVar4 + -1) {
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          uVar3 = FUN_100027c0((uint)(ushort)*puVar6);
          *(short *)puVar1 = (short)uVar3;
          puVar6 = (uint *)((int)puVar6 + 2);
          puVar1 = (uint *)((int)puVar1 + 2);
        }
        apuStack_17c[2] = (uint *)((int)apuStack_17c[2] + iStack_f0);
        apuStack_17c[3] = (uint *)((int)apuStack_17c[3] + iStack_84);
      }
      goto LAB_10002350;
    }
    if (piStack_40 == (int *)0x20) {
      for (; puVar6 = apuStack_17c[2], puVar1 = apuStack_17c[3], iVar2 = iStack_16c, iVar4 != 0;
          iVar4 = iVar4 + -1) {
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          uVar3 = FUN_100027c0((uint)(ushort)*puVar6);
          *puVar1 = uVar3;
          puVar6 = (uint *)((int)puVar6 + 2);
          puVar1 = puVar1 + 1;
        }
        apuStack_17c[2] = (uint *)((int)apuStack_17c[2] + iStack_f0);
        apuStack_17c[3] = (uint *)((int)apuStack_17c[3] + iStack_84);
      }
      goto LAB_10002350;
    }
  }
  if (iStack_ac == 0x20) {
    if (piStack_40 == (int *)0x10) {
      for (; puVar6 = apuStack_17c[2], puVar1 = apuStack_17c[3], iVar2 = iStack_16c, iVar4 != 0;
          iVar4 = iVar4 + -1) {
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          uVar3 = FUN_100027c0(*puVar6);
          *(short *)puVar1 = (short)uVar3;
          puVar6 = puVar6 + 1;
          puVar1 = (uint *)((int)puVar1 + 2);
        }
        apuStack_17c[2] = (uint *)((int)apuStack_17c[2] + iStack_f0);
        apuStack_17c[3] = (uint *)((int)apuStack_17c[3] + iStack_84);
      }
    }
    else if (piStack_40 == (int *)0x20) {
      for (; puVar6 = apuStack_17c[2], puVar1 = apuStack_17c[3], iVar2 = iStack_16c, iVar4 != 0;
          iVar4 = iVar4 + -1) {
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          uVar3 = FUN_100027c0(*puVar6);
          *puVar1 = uVar3;
          puVar6 = puVar6 + 1;
          puVar1 = puVar1 + 1;
        }
        apuStack_17c[2] = (uint *)((int)apuStack_17c[2] + iStack_f0);
        apuStack_17c[3] = (uint *)((int)apuStack_17c[3] + iStack_84);
      }
    }
  }
LAB_10002350:
  iVar4 = (**(code **)(*piStack_24 + 0x80))(piStack_24,0);
  if (iVar4 == -0x7789fe3e) {
    ppuVar8 = apuStack_17c + 2;
    for (iVar4 = 0x1b; iVar4 != 0; iVar4 = iVar4 + -1) {
      *ppuVar8 = (uint *)0x0;
      ppuVar8 = ppuVar8 + 1;
    }
    apuStack_17c[2] = (uint *)0x6c;
    apuStack_17c[3] = (uint *)0x1;
    (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,apuStack_17c + 2,0,&LAB_10001b40);
    if (DAT_10036038 != (int *)0x0) {
      (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
    }
    if (DAT_1003603c != DAT_10036038) {
      (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
    }
    (**(code **)(*piStack_40 + 0x80))(piStack_40,0);
  }
  iVar4 = (**(code **)(*piStack_28 + 0x80))(piStack_28,0);
  if (iVar4 == -0x7789fe3e) {
    ppuVar8 = apuStack_17c;
    for (iVar4 = 0x1b; iVar4 != 0; iVar4 = iVar4 + -1) {
      *ppuVar8 = (uint *)0x0;
      ppuVar8 = ppuVar8 + 1;
    }
    apuStack_17c[0] = (uint *)0x6c;
    apuStack_17c[1] = (uint *)0x1;
    (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,apuStack_17c,0,&LAB_10001b40);
    if (DAT_10036038 != (int *)0x0) {
      (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
    }
    if (DAT_1003603c != DAT_10036038) {
      (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
    }
    (**(code **)(*piStack_44 + 0x80))(piStack_44,0);
  }
  return 1;
}


