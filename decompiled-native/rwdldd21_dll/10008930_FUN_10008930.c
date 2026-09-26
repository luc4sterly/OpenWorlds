// 10008930 FUN_10008930 [Global]
// programa: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10008930(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int **ppiVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puStack_110;
  int *piStack_10c;
  int *piStack_108;
  int **ppiStack_104;
  int *piStack_100;
  int *apiStack_fc [6];
  undefined4 auStack_d8 [5];
  undefined4 uStack_c4;
  undefined4 auStack_b4 [8];
  undefined4 uStack_94;
  int aiStack_90 [8];
  undefined4 uStack_70;
  undefined4 uStack_28;
  undefined4 uStack_20;
  
  if ((param_1 & 0x10) == 0) {
    puVar2 = auStack_d8;
    for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    auStack_d8[0] = 0x6c;
    apiStack_fc[5] = (int *)0x0;
    apiStack_fc[3] = auStack_d8;
    apiStack_fc[4] = (int *)&DAT_10036038;
    auStack_d8[1] = 1;
    uStack_70 = 0x200;
    apiStack_fc[2] = DAT_10036030;
    apiStack_fc[1] = (int *)0x10008c08;
    iVar1 = (**(code **)(*DAT_10036030 + 0x18))();
    if (iVar1 != 0) {
      return 0;
    }
    apiStack_fc[1] = (undefined4 *)0x0;
    apiStack_fc[0] = (int *)&DAT_10036044;
    piStack_100 = (int *)0x0;
    DAT_1003603c = DAT_10036038;
    ppiStack_104 = (int **)DAT_10036030;
    piStack_108 = (int *)0x10008c32;
    iVar1 = (**(code **)(*DAT_10036030 + 0x10))();
    if (iVar1 != 0) {
      if (DAT_10036038 != (int *)0x0) {
        piStack_108 = DAT_10036038;
        piStack_10c = (int *)0x10008c45;
        (**(code **)(*DAT_10036038 + 8))();
        DAT_10036038 = (int *)0x0;
      }
      return 0;
    }
    piStack_108 = DAT_10036044;
    piStack_10c = DAT_1003603c;
    puStack_110 = (undefined4 *)0x10008c68;
    iVar1 = (**(code **)(*DAT_1003603c + 0x70))();
    if (iVar1 != 0) {
      if (DAT_10036044 != (int *)0x0) {
        ppiStack_104 = (int **)DAT_10036044;
        piStack_108 = (int *)0x10008c7b;
        (**(code **)(*DAT_10036044 + 8))();
        DAT_10036044 = (int *)0x0;
      }
      if (DAT_10036038 != (int *)0x0) {
        ppiStack_104 = (int **)DAT_10036038;
        piStack_108 = (int *)0x10008c94;
        (**(code **)(*DAT_10036038 + 8))();
        DAT_10036038 = (int *)0x0;
      }
      return 0;
    }
    DAT_10036040 = 0;
    DAT_10036048 = 0;
  }
  else {
    puVar2 = auStack_d8;
    for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    auStack_d8[0] = 0x6c;
    auStack_d8[1] = 0x21;
    apiStack_fc[5] = (int *)0x0;
    apiStack_fc[3] = auStack_d8;
    apiStack_fc[4] = (int *)&DAT_10036038;
    uStack_70 = 0x2218;
    uStack_c4 = 1;
    apiStack_fc[2] = DAT_10036030;
    apiStack_fc[1] = (int *)0x1000898a;
    iVar1 = (**(code **)(*DAT_10036030 + 0x18))();
    if (iVar1 != 0) {
      return 0;
    }
    apiStack_fc[1] = (int *)&DAT_1003603c;
    ppiVar3 = apiStack_fc + 5;
    for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppiVar3 = (int *)0x0;
      ppiVar3 = ppiVar3 + 1;
    }
    apiStack_fc[0] = aiStack_90 + 4;
    apiStack_fc[5] = (int *)0x6c;
    piStack_100 = DAT_10036038;
    aiStack_90[4] = 4;
    ppiStack_104 = (int **)0x100089cc;
    (**(code **)(*DAT_10036038 + 0x30))();
    if (DAT_10036058 == 0) {
      DAT_10036040 = 0;
    }
    else {
      ppiVar3 = apiStack_fc + 2;
      for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
        *ppiVar3 = (int *)0x0;
        ppiVar3 = ppiVar3 + 1;
      }
      ppiStack_104 = apiStack_fc + 2;
      apiStack_fc[2] = (int *)0x6c;
      piStack_108 = DAT_10036038;
      piStack_10c = (int *)0x100089fc;
      iVar1 = (**(code **)(*DAT_10036038 + 0x58))();
      if (iVar1 == -0x7789fe3e) {
        piStack_10c = (int *)&LAB_10001b40;
        piVar4 = aiStack_90;
        for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
          *piVar4 = 0;
          piVar4 = piVar4 + 1;
        }
        aiStack_90[0] = 0x6c;
        puStack_110 = (undefined4 *)0x0;
        aiStack_90[1] = 1;
        uStack_28 = 0x4000;
        (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,aiStack_90);
        if (DAT_10036038 != (int *)0x0) {
          (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
        }
        if (DAT_1003603c != DAT_10036038) {
          (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
        }
        (**(code **)(*DAT_10036038 + 0x58))(DAT_10036038,&puStack_110);
      }
      ppiVar3 = apiStack_fc;
      for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
        *ppiVar3 = (int *)0x0;
        ppiVar3 = ppiVar3 + 1;
      }
      apiStack_fc[0] = (int *)0x6c;
      apiStack_fc[1] = (undefined4 *)0x47;
      piStack_10c = (int *)0x0;
      puStack_110 = &DAT_10036040;
      uStack_94 = 0x26000;
      iVar1 = (**(code **)(*DAT_10036030 + 0x18))(DAT_10036030,apiStack_fc);
      if (iVar1 != 0) {
        if (DAT_10036038 != (int *)0x0) {
          (**(code **)(*DAT_10036038 + 8))(DAT_10036038);
          DAT_10036038 = (int *)0x0;
        }
        return 0;
      }
      iVar1 = (**(code **)(*DAT_1003603c + 0xc))(DAT_1003603c,DAT_10036040);
      if (iVar1 == -0x7789fe3e) {
        ppiStack_104 = (int **)&LAB_10001b40;
        piVar4 = aiStack_90 + 2;
        for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
          *piVar4 = 0;
          piVar4 = piVar4 + 1;
        }
        aiStack_90[2] = 0x6c;
        piStack_108 = (int *)0x0;
        aiStack_90[3] = 1;
        uStack_20 = 0x4000;
        piStack_10c = aiStack_90 + 2;
        puStack_110 = (undefined4 *)0x10;
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
          ppiStack_104 = (int **)DAT_10036038;
          piStack_108 = (int *)0x10008b9c;
          (**(code **)(*DAT_10036038 + 8))();
          DAT_10036038 = (int *)0x0;
        }
        return 0;
      }
    }
    DAT_10036044 = (int *)0x0;
    DAT_10036048 = 1;
  }
  ppiVar3 = apiStack_fc + 2;
  for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppiVar3 = (int *)0x0;
    ppiVar3 = ppiVar3 + 1;
  }
  ppiStack_104 = apiStack_fc + 2;
  apiStack_fc[2] = (int *)0x6c;
  piStack_108 = DAT_10036038;
  piStack_10c = (int *)0x10008cd8;
  iVar1 = (**(code **)(*DAT_10036038 + 0x58))();
  if (iVar1 == -0x7789fe3e) {
    piStack_10c = (int *)&LAB_10001b40;
    piVar4 = aiStack_90;
    for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar4 = 0;
      piVar4 = piVar4 + 1;
    }
    aiStack_90[0] = 0x6c;
    puStack_110 = (undefined4 *)0x0;
    aiStack_90[1] = 1;
    uStack_28 = 0x4000;
    (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,aiStack_90);
    if (DAT_10036038 != (int *)0x0) {
      (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
    }
    if (DAT_1003603c != DAT_10036038) {
      (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
    }
    iVar1 = (**(code **)(*DAT_10036038 + 0x58))(DAT_10036038,&puStack_110);
  }
  if (iVar1 == 0) {
    puVar2 = auStack_b4;
    puVar5 = &DAT_10038b38;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar5 = puVar5 + 1;
    }
    DAT_10038b00 = apiStack_fc[3];
    DAT_10038a80 = apiStack_fc[2];
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
  puVar5 = &DAT_10038b08;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar5 = puVar5 + 1;
  }
  return 1;
}


