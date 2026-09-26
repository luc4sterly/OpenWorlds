// 10001b60 FUN_10001b60 [Global]
// programa: RWDLDD21.DLL

undefined4 FUN_10001b60(undefined4 *param_1,undefined4 *param_2,int *param_3)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int unaff_EDI;
  undefined4 *puVar7;
  int *unaff_retaddr;
  int local_10c;
  int local_108;
  int local_104;
  int local_100;
  int local_fc;
  int local_f8 [3];
  int local_ec;
  int *local_e8;
  undefined4 uStack_e0;
  undefined1 auStack_dc [4];
  undefined4 auStack_d8 [26];
  undefined4 uStack_70;
  undefined4 auStack_6c [23];
  undefined4 *puStack_10;
  undefined4 uStack_4;
  
  local_10c = 0;
  if (0 < (int)param_1[9]) {
    local_e8 = (int *)0x0;
    do {
      piVar6 = (int *)((int *)((int)local_e8 + param_1[0xb]))[2];
      local_100 = *param_3;
      local_108 = 0;
      local_104 = *(int *)((int)local_e8 + param_1[0xb]);
      local_fc = local_104 + local_100;
      local_f8[1] = 0;
      local_f8[0] = 0;
      local_f8[2] = local_100;
      local_ec = local_100;
      iVar3 = (**(code **)(*piVar6 + 0x14))(piVar6,local_f8,*param_1,&local_108,0x1000000,0);
      if (iVar3 == -0x7789fe3e) {
        puVar7 = auStack_d8;
        for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar7 = 0;
          puVar7 = puVar7 + 1;
        }
        auStack_d8[0] = 0x6c;
        auStack_d8[1] = 1;
        uStack_70 = 0x4000;
        (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,auStack_d8,0,&LAB_10001b40);
        if (DAT_10036038 != (int *)0x0) {
          (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
        }
        if (DAT_1003603c != DAT_10036038) {
          (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
        }
        iVar3 = (**(code **)(*piVar6 + 0x14))
                          (piVar6,&local_10c,*puStack_10,&stack0xfffffee4,0x1000000,0);
      }
      if (iVar3 != 0) {
        iVar4 = FUN_10001ef0(piVar6,(int *)*param_1);
        if (iVar4 != 0) {
          iVar3 = 0;
        }
        if (iVar3 != 0) {
          return 0;
        }
      }
      if (param_2 != (undefined4 *)0x0) {
        iVar3 = 1;
        uStack_e0 = 0x401000;
        if (1 < param_3[10]) {
          do {
            iVar4 = (**(code **)(*piVar6 + 0x30))(piVar6,&uStack_e0,auStack_dc);
            piVar6 = local_e8;
            if (iVar4 != 0) {
              return 0;
            }
            local_f8[2] = *unaff_retaddr;
            iVar4 = local_f8[2] / 2;
            bVar1 = (byte)iVar3;
            if ((iVar3 < 1) || (iVar4 >> (bVar1 - 1 & 0x1f) == 0)) {
              bVar2 = false;
            }
            else if (iVar3 == 1) {
              local_108 = iVar4 + ((iVar4 >> 1) + iVar4) * unaff_EDI;
              bVar2 = true;
              local_10c = iVar4;
            }
            else {
              local_108 = iVar4 >> (bVar1 - 1 & 0x1f);
              local_10c = local_108 +
                          (((1 << (bVar1 - 2 & 0x1f)) + -1) * iVar4 >> (bVar1 - 2 & 0x1f));
              local_108 = local_108 + ((iVar4 >> 1) + iVar4) * unaff_EDI + iVar4;
              bVar2 = true;
            }
            if (!bVar2) {
              return 0;
            }
            local_fc = local_f8[2] >> (bVar1 & 0x1f);
            local_100 = 0;
            local_104 = 0;
            local_f8[0] = local_fc;
            iVar4 = (**(code **)(*local_e8 + 0x14))
                              (local_e8,&local_104,*param_2,&stack0xfffffeec,0x1000000,0);
            if (iVar4 == -0x7789fe3e) {
              puVar7 = auStack_6c;
              for (iVar4 = 0x1b; iVar4 != 0; iVar4 = iVar4 + -1) {
                *puVar7 = 0;
                puVar7 = puVar7 + 1;
              }
              auStack_6c[0] = 0x6c;
              auStack_6c[1] = 1;
              uStack_4 = 0x4000;
              (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,auStack_6c,0,&LAB_10001b40);
              if (DAT_10036038 != (int *)0x0) {
                (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
              }
              if (DAT_1003603c != DAT_10036038) {
                (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
              }
              iVar4 = (**(code **)(*piVar6 + 0x14))
                                (piVar6,&local_10c,*param_2,&stack0xfffffee4,0x1000000,0);
            }
            if (iVar4 != 0) {
              iVar5 = FUN_10001ef0(piVar6,(int *)*param_2);
              if (iVar5 != 0) {
                iVar4 = 0;
              }
              if (iVar4 != 0) {
                return 0;
              }
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < param_3[10]);
        }
      }
      local_e8 = local_e8 + 4;
      local_10c = local_10c + 1;
    } while (local_10c < (int)param_1[9]);
  }
  return 1;
}


