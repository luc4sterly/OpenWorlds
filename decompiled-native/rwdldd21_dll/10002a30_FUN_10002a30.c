// 10002a30 FUN_10002a30 [Global]
// program: RWDLDD21.DLL

undefined4 * FUN_10002a30(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *unaff_EBP;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 uStack_11c;
  int *piStack_118;
  undefined1 auStack_114 [4];
  int *piStack_110;
  int *piStack_10c;
  int *piStack_108;
  int *piStack_104;
  undefined1 *puStack_100;
  undefined4 uStack_fc;
  undefined1 local_e8 [8];
  undefined4 local_e0;
  undefined4 local_dc;
  int local_d8 [6];
  undefined4 local_c0;
  undefined4 auStack_94 [9];
  undefined4 local_70;
  undefined4 uStack_2c;
  undefined4 uStack_20;
  
  puVar2 = (undefined4 *)0x0;
  local_e0 = 0;
  local_dc = 0;
  if (param_1[0xc] == 0) {
    piVar5 = local_d8;
    for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar5 = 0;
      piVar5 = piVar5 + 1;
    }
    local_d8[0] = 0x6c;
    local_d8[1] = 0x1007;
    local_70 = 0x5000;
    if (param_1[0xb] != 0) {
      local_d8[1] = 0x21007;
      local_70 = 0x405008;
      local_c0 = param_1[10];
    }
    local_d8[2] = *param_1;
    puVar2 = auStack_94;
    uStack_fc = 0;
    piStack_104 = local_d8;
    puVar4 = &DAT_10038b08;
    for (iVar3 = 8; puVar2 = puVar2 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar2 = *puVar4;
      puVar4 = puVar4 + 1;
    }
    puStack_100 = local_e8;
    piStack_108 = DAT_10036030;
    piStack_10c = (int *)0x10002ad0;
    local_d8[3] = local_d8[2];
    iVar3 = (**(code **)(*DAT_10036030 + 0x18))();
    if (iVar3 == 0) {
      piStack_10c = (int *)&stack0xffffff0c;
      piStack_110 = (int *)&DAT_10034190;
      piStack_118 = (int *)0x10002af5;
      iVar3 = (**(code **)*unaff_EBP)();
      if (iVar3 == -0x7789fe3e) {
        piStack_118 = (int *)&LAB_10001b40;
        puVar2 = auStack_94 + 3;
        for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar2 = 0;
          puVar2 = puVar2 + 1;
        }
        auStack_94[3] = 0x6c;
        uStack_11c = 0;
        auStack_94[4] = 1;
        uStack_20 = 0x4000;
        (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,auStack_94 + 3);
        if (DAT_10036038 != (int *)0x0) {
          (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
        }
        if (DAT_1003603c != DAT_10036038) {
          (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
        }
        iVar3 = (**(code **)*piStack_118)(piStack_118,&DAT_10034190,auStack_114);
      }
      if (iVar3 == 0) {
        piStack_118 = &uStack_fc;
        uStack_11c = 8;
        iVar3 = (**(code **)(*piStack_104 + 0x74))(piStack_104);
        if (iVar3 == -0x7789fe3e) {
          piVar5 = (int *)&LAB_10001b40;
          puVar2 = auStack_94;
          for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar2 = 0;
            puVar2 = puVar2 + 1;
          }
          auStack_94[0] = 0x6c;
          auStack_94[1] = 1;
          uStack_2c = 0x4000;
          (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,auStack_94,0);
          if (DAT_10036038 != (int *)0x0) {
            (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
          }
          if (DAT_1003603c != DAT_10036038) {
            (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
          }
          iVar3 = (**(code **)(*piVar5 + 0x74))(piVar5,8,&uStack_11c);
        }
        if (iVar3 == 0) {
          iVar3 = (**(code **)(DAT_100394fc + 0x354))(param_1[3],(param_1[1] * 3 + 3) * 8);
          if (iVar3 == 0) {
            param_1[0xc] = 1;
            if (piStack_10c != (int *)0x0) {
              (**(code **)(*piStack_10c + 8))(piStack_10c);
              piStack_10c = (int *)0x0;
            }
            if (piStack_110 != (int *)0x0) {
              (**(code **)(*piStack_110 + 8))(piStack_110);
            }
            puVar2 = (undefined4 *)0x0;
          }
          else {
            param_1[3] = iVar3;
            iVar1 = param_1[1];
            param_1[1] = iVar1 + 1;
            puVar2 = (undefined4 *)(iVar3 + -0x18 + (iVar1 + 1) * 0x18);
            *puVar2 = 0;
            puVar2[1] = 0;
            puVar2[2] = 0;
            puVar2[4] = piStack_110;
            puVar2[5] = piStack_10c;
            puVar2[3] = 0;
          }
        }
        else {
          param_1[0xc] = 1;
          if (piStack_10c != (int *)0x0) {
            (**(code **)(*piStack_10c + 8))(piStack_10c);
            piStack_10c = (int *)0x0;
          }
          if (piStack_110 != (int *)0x0) {
            (**(code **)(*piStack_110 + 8))(piStack_110);
          }
          puVar2 = (undefined4 *)0x0;
        }
      }
      else {
        param_1[0xc] = 1;
        if (piStack_104 != (int *)0x0) {
          piStack_118 = piStack_104;
          uStack_11c = 0x10002b9e;
          (**(code **)(*piStack_104 + 8))();
        }
        puVar2 = (undefined4 *)0x0;
      }
    }
    else {
      param_1[0xc] = 1;
      puVar2 = (undefined4 *)0x0;
    }
  }
  return puVar2;
}


