// 10006450 FUN_10006450 [Global]
// program: RWDLDD21.DLL

/* WARNING: Type propagation algorithm not settling */

int * FUN_10006450(int *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint *puVar7;
  uint **ppuVar8;
  uint *puVar9;
  uint ***pppuVar10;
  int **ppiVar11;
  int *piVar12;
  undefined4 *puStack_1a4;
  int *piStack_1a0;
  int *piStack_19c;
  int *piStack_198;
  uint **ppuStack_194;
  uint **appuStack_190 [2];
  uint *apuStack_188 [8];
  undefined1 local_150 [8];
  undefined4 local_148;
  undefined4 uStack_130;
  undefined4 uStack_128;
  undefined4 uStack_120;
  uint uStack_114;
  uint uStack_110;
  int aiStack_10c [4];
  undefined4 uStack_fc;
  uint *puStack_f8;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 auStack_e4 [4];
  undefined1 auStack_d4 [12];
  int iStack_c8;
  undefined1 auStack_c4 [36];
  int iStack_a0;
  undefined4 auStack_9c [4];
  uint *apuStack_8c [9];
  undefined1 auStack_68 [4];
  int *piStack_64;
  int *piStack_5c;
  int *piStack_48;
  int *apiStack_44 [5];
  int *piStack_30;
  int *piStack_2c;
  undefined4 uStack_24;
  undefined4 *puStack_18;
  uint *puStack_8;
  
  apuStack_188[7] = (uint *)local_150;
  local_148 = 1;
  apuStack_188[6] = (uint *)0x8;
  apuStack_188[5] = (uint *)param_1;
  apuStack_188[4] = (uint *)0x10006476;
  (**(code **)(*param_1 + 0x40))();
  apuStack_188[4] = (uint *)0x0;
  puVar6 = auStack_e4;
  for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  apuStack_188[3] = (uint *)0x11;
  apuStack_188[2] = auStack_e4;
  auStack_e4[0] = 0x6c;
  apuStack_188[1] = (uint *)0x0;
  apuStack_188[0] = puStack_8;
  appuStack_190[1] = (uint **)0x100064b8;
  iVar3 = (**(code **)(*puStack_8 + 100))();
  if (iVar3 == -0x7789fe3e) {
    appuStack_190[1] = (uint **)&LAB_10001b40;
    puVar6 = (undefined4 *)&stack0xfffffe9c;
    for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    appuStack_190[0] = (uint **)0x0;
    ppuStack_194 = (uint **)&stack0xfffffe9c;
    uStack_fc = 0x4000;
    piStack_198 = (int *)0x10;
    piStack_19c = DAT_10036030;
    piStack_1a0 = (int *)0x100064fb;
    (**(code **)(*DAT_10036030 + 0x24))();
    if (DAT_10036038 != (int *)0x0) {
      piStack_1a0 = DAT_10036038;
      puStack_1a4 = (undefined4 *)0x1000650a;
      (**(code **)(*DAT_10036038 + 0x6c))();
    }
    if (DAT_1003603c != DAT_10036038) {
      piStack_1a0 = DAT_1003603c;
      puStack_1a4 = (undefined4 *)0x1000651f;
      (**(code **)(*DAT_1003603c + 0x6c))();
    }
    piStack_1a0 = (int *)0x0;
    puStack_1a4 = (undefined4 *)0x11;
    iVar3 = (**(code **)(*piStack_30 + 100))(piStack_30,0,aiStack_10c);
  }
  if (iVar3 != 0) {
    return (int *)0x0;
  }
  ppuVar8 = apuStack_8c;
  for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppuVar8 = (uint *)0x0;
    ppuVar8 = ppuVar8 + 1;
  }
  apuStack_8c[1] = (uint *)0x1007;
  apuStack_8c[0] = (uint *)0x6c;
  uStack_24 = 0x840;
  apuStack_8c[3] = (uint *)uStack_ec;
  appuStack_190[1] = (uint **)0x0;
  appuStack_190[0] = apuStack_188 + 5;
  apuStack_8c[2] = (uint *)uStack_f0;
  puVar6 = puStack_18;
  ppiVar11 = apiStack_44;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppiVar11 = (int *)*puVar6;
    puVar6 = puVar6 + 1;
    ppiVar11 = ppiVar11 + 1;
  }
  ppuStack_194 = apuStack_8c;
  piStack_198 = DAT_10036030;
  piStack_19c = (int *)0x100065c3;
  iVar3 = (**(code **)(*DAT_10036030 + 0x18))();
  puVar7 = apuStack_188[1];
  if (iVar3 != 0) {
    piStack_19c = (int *)0x0;
    piStack_1a0 = piStack_2c;
    puStack_1a4 = (undefined4 *)0x100065dd;
    iVar3 = (**(code **)(*piStack_2c + 0x80))();
    if (iVar3 == -0x7789fe3e) {
      puStack_1a4 = (undefined4 *)&LAB_10001b40;
      ppuVar8 = apuStack_188 + 3;
      for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
        *ppuVar8 = (uint *)0x0;
        ppuVar8 = ppuVar8 + 1;
      }
      apuStack_188[3] = (uint *)0x6c;
      apuStack_188[4] = (uint *)0x1;
      uStack_114 = 0x4000;
      (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,apuStack_188 + 3,0);
      if (DAT_10036038 != (int *)0x0) {
        (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
      }
      if (DAT_1003603c != DAT_10036038) {
        (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
      }
      (**(code **)(*piStack_48 + 0x80))(piStack_48,0);
    }
    return (int *)0x0;
  }
  puVar6 = auStack_9c;
  for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  piStack_19c = (int *)0x0;
  puStack_1a4 = auStack_9c;
  piStack_1a0 = (int *)0x21;
  auStack_9c[0] = 0x6c;
  piVar12 = (int *)0x0;
  iVar3 = (**(code **)(*apuStack_188[1] + 100))(apuStack_188[1]);
  if (iVar3 == -0x7789fe3e) {
    ppuVar8 = apuStack_188;
    for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
      *ppuVar8 = (uint *)0x0;
      ppuVar8 = ppuVar8 + 1;
    }
    apuStack_188[0] = (uint *)0x6c;
    apuStack_188[1] = (uint *)0x1;
    uStack_120 = 0x4000;
    (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,apuStack_188,0,&LAB_10001b40);
    if (DAT_10036038 != (int *)0x0) {
      (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
    }
    if (DAT_1003603c != DAT_10036038) {
      (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
    }
    iVar3 = (**(code **)(*puVar7 + 100))(puVar7,0,auStack_c4,0x21,0);
  }
  if (iVar3 != 0) {
    if (piStack_198 != (int *)0x0) {
      (**(code **)(*piStack_198 + 8))(piStack_198);
      piStack_198 = (int *)0x0;
    }
    iVar3 = (**(code **)(*apiStack_44[1] + 0x80))(apiStack_44[1],0);
    if (iVar3 == -0x7789fe3e) {
      pppuVar10 = appuStack_190;
      for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
        *pppuVar10 = (uint **)0x0;
        pppuVar10 = pppuVar10 + 1;
      }
      appuStack_190[0] = (uint **)0x6c;
      appuStack_190[1] = (uint **)0x1;
      uStack_128 = 0x4000;
      (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,appuStack_190,0,&LAB_10001b40);
      if (DAT_10036038 != (int *)0x0) {
        (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
      }
      if (DAT_1003603c != DAT_10036038) {
        (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
      }
      (**(code **)(*piStack_5c + 0x80))(piStack_5c,0);
    }
    return (int *)0x0;
  }
  apuStack_188[0] = apuStack_8c[0];
  FUN_10002490((int)auStack_d4,(int)auStack_68);
  if (iStack_c8 == 0x10) {
    if (piStack_5c == (int *)0x10) {
      piStack_19c = (int *)0x0;
      puVar7 = puStack_f8;
      if (uStack_114 != 0) {
        do {
          uVar5 = 0;
          puVar4 = apuStack_188[0];
          puVar9 = puVar7;
          if (uStack_110 != 0) {
            do {
              uVar2 = *puVar9;
              puVar9 = (uint *)((int)puVar9 + 2);
              uVar5 = uVar5 + 1;
              uVar2 = FUN_100027c0((uint)(ushort)uVar2);
              *(short *)puVar4 = (short)uVar2;
              puVar4 = (uint *)((int)puVar4 + 2);
            } while (uVar5 < uStack_110);
          }
          puVar7 = (uint *)((int)puVar7 + aiStack_10c[0]);
          apuStack_188[0] = (uint *)((int)apuStack_188[0] + iStack_a0);
          piStack_19c = (int *)((int)piStack_19c + 1);
        } while (piStack_19c < uStack_114);
      }
      goto LAB_10006a3b;
    }
    if (piStack_5c == (int *)0x20) {
      piStack_19c = (int *)0x0;
      puVar7 = puStack_f8;
      if (uStack_114 != 0) {
        do {
          uVar5 = 0;
          puVar4 = apuStack_188[0];
          puVar9 = puVar7;
          if (uStack_110 != 0) {
            do {
              uVar2 = *puVar9;
              puVar9 = (uint *)((int)puVar9 + 2);
              uVar5 = uVar5 + 1;
              uVar2 = FUN_100027c0((uint)(ushort)uVar2);
              *puVar4 = uVar2;
              puVar4 = puVar4 + 1;
            } while (uVar5 < uStack_110);
          }
          puVar7 = (uint *)((int)puVar7 + aiStack_10c[0]);
          apuStack_188[0] = (uint *)((int)apuStack_188[0] + iStack_a0);
          piStack_19c = (int *)((int)piStack_19c + 1);
        } while (piStack_19c < uStack_114);
      }
      goto LAB_10006a3b;
    }
  }
  if (iStack_c8 == 0x20) {
    if (piStack_5c == (int *)0x10) {
      piStack_19c = (int *)0x0;
      puVar7 = puStack_f8;
      if (uStack_114 != 0) {
        do {
          uVar5 = 0;
          puVar4 = puVar7;
          puVar9 = apuStack_188[0];
          if (uStack_110 != 0) {
            do {
              uVar2 = *puVar4;
              puVar4 = puVar4 + 1;
              uVar2 = FUN_100027c0(uVar2);
              *(short *)puVar9 = (short)uVar2;
              uVar5 = uVar5 + 1;
              puVar9 = (uint *)((int)puVar9 + 2);
            } while (uVar5 < uStack_110);
          }
          puVar7 = (uint *)((int)puVar7 + aiStack_10c[0]);
          apuStack_188[0] = (uint *)((int)apuStack_188[0] + iStack_a0);
          piStack_19c = (int *)((int)piStack_19c + 1);
        } while (piStack_19c < uStack_114);
      }
    }
    else if ((piStack_5c == (int *)0x20) &&
            (piStack_19c = (int *)0x0, puVar7 = puStack_f8, uStack_114 != 0)) {
      do {
        uVar5 = 0;
        puVar4 = apuStack_188[0];
        puVar9 = puVar7;
        if (uStack_110 != 0) {
          do {
            uVar2 = *puVar9;
            puVar9 = puVar9 + 1;
            uVar2 = FUN_100027c0(uVar2);
            uVar5 = uVar5 + 1;
            *puVar4 = uVar2;
            puVar4 = puVar4 + 1;
          } while (uVar5 < uStack_110);
        }
        puVar7 = (uint *)((int)puVar7 + aiStack_10c[0]);
        apuStack_188[0] = (uint *)((int)apuStack_188[0] + iStack_a0);
        piStack_19c = (int *)((int)piStack_19c + 1);
      } while (piStack_19c < uStack_114);
    }
  }
LAB_10006a3b:
  piVar1 = piStack_198;
  iVar3 = (**(code **)(*piStack_198 + 0x80))(piStack_198,0);
  if (iVar3 == -0x7789fe3e) {
    pppuVar10 = appuStack_190;
    for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pppuVar10 = (uint **)0x0;
      pppuVar10 = pppuVar10 + 1;
    }
    appuStack_190[0] = (uint **)0x6c;
    appuStack_190[1] = (uint **)0x1;
    uStack_128 = 0x4000;
    (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,appuStack_190,0,&LAB_10001b40);
    if (DAT_10036038 != (int *)0x0) {
      (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
    }
    if (DAT_1003603c != DAT_10036038) {
      (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
    }
    (**(code **)(*piVar1 + 0x80))(piVar1,0);
  }
  iVar3 = (**(code **)(*piStack_48 + 0x80))(piStack_48,0);
  if (iVar3 == -0x7789fe3e) {
    ppiVar11 = &piStack_198;
    for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
      *ppiVar11 = (int *)0x0;
      ppiVar11 = ppiVar11 + 1;
    }
    piStack_198 = (int *)0x6c;
    ppuStack_194 = (uint **)0x1;
    uStack_130 = 0x4000;
    (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,&piStack_198,0,&LAB_10001b40);
    if (DAT_10036038 != (int *)0x0) {
      (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
    }
    if (DAT_1003603c != DAT_10036038) {
      (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
    }
    (**(code **)(*piStack_64 + 0x80))(piStack_64,0);
  }
  if (piStack_19c != (int *)0x0) {
    puStack_1a4 = (undefined4 *)FUN_100027c0((uint)puStack_1a4);
    puStack_1a4 = (undefined4 *)FUN_100027c0((uint)puStack_1a4);
    (**(code **)(*piVar12 + 0x74))(piVar12,8,&puStack_1a4);
  }
  return piVar12;
}


