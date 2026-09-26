// 10008370 FUN_10008370 [Global]
// programa: RWDLDD21.DLL

void FUN_10008370(int *param_1)

{
  undefined2 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined2 *unaff_EBP;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *local_e8;
  int iStack_e4;
  undefined2 uStack_e0;
  undefined2 uStack_dc;
  undefined4 auStack_d8 [17];
  undefined1 auStack_94 [8];
  undefined4 uStack_8c;
  undefined4 uStack_84;
  uint uStack_78;
  uint uStack_74;
  int iStack_70;
  undefined4 auStack_6c [4];
  undefined2 *puStack_5c;
  undefined4 auStack_24 [9];
  
  local_e8 = (undefined4 *)param_1[0xb];
  if (local_e8 == (undefined4 *)0x0) {
    iVar7 = -1;
    FUN_100033a0(param_1);
    iVar6 = DAT_10036180;
    local_e8 = (undefined4 *)param_1[0xb];
    iVar5 = 0;
    if (0 < DAT_10036180) {
      do {
        if (param_1 == (int *)DAT_1003617c[iVar5]) goto LAB_1000848c;
        if ((iVar7 == -1) && ((int *)DAT_1003617c[iVar5] == (int *)0x0)) {
          iVar7 = iVar5;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < DAT_10036180);
    }
    if (iVar7 == -1) {
      iVar7 = iVar6;
      if ((DAT_1003617c == (undefined4 *)0x0) || (DAT_10036180 == 0)) {
        puVar3 = (undefined4 *)(**(code **)(DAT_100394fc + 0x34c))();
        if (puVar3 != (undefined4 *)0x0) {
          puVar10 = puVar3;
          for (iVar6 = 0x80; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar10 = 0;
            puVar10 = puVar10 + 1;
          }
          DAT_10036180 = 0x80;
          DAT_1003617c = puVar3;
        }
      }
      else {
        puVar3 = (undefined4 *)(**(code **)(DAT_100394fc + 0x354))(DAT_1003617c);
        if (puVar3 != (undefined4 *)0x0) {
          if (DAT_10036180 != 0 && SBORROW4(DAT_10036180 * 2,DAT_10036180) == DAT_10036180 < 0) {
            puVar10 = puVar3 + DAT_10036180;
            iVar6 = DAT_10036180;
            do {
              *puVar10 = 0;
              puVar10 = puVar10 + 1;
              iVar6 = iVar6 + 1;
            } while (iVar6 < DAT_10036180 * 2);
          }
          DAT_10036180 = DAT_10036180 * 2;
          DAT_1003617c = puVar3;
        }
      }
    }
    DAT_1003617c[iVar7] = param_1;
  }
LAB_1000848c:
  iStack_e4 = (**(code **)(DAT_100394fc + 0x34c))();
  if (iStack_e4 != 0) {
    piVar2 = (int *)*local_e8;
    puVar3 = auStack_6c;
    for (iVar6 = 0x1b; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    auStack_6c[0] = 0x6c;
    puVar10 = (undefined4 *)0x0;
    puVar3 = auStack_6c;
    iVar6 = (**(code **)(*piVar2 + 100))(piVar2,0,puVar3,0x11);
    if (iVar6 == -0x7789fe3e) {
      puVar9 = (undefined4 *)&stack0xffffff14;
      for (iVar6 = 0x1b; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      }
      uStack_84 = 0x4000;
      (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,&stack0xffffff14,0,&LAB_10001b40);
      if (DAT_10036038 != (int *)0x0) {
        (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
      }
      if (DAT_1003603c != DAT_10036038) {
        (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
      }
      iVar6 = (**(code **)(*piVar2 + 100))(piVar2,0,auStack_94,0x11,0);
    }
    if (iVar6 == 0) {
      uVar8 = 0;
      if (uStack_78 != 0) {
        do {
          uVar4 = 0;
          if (uStack_74 != 0) {
            do {
              uVar1 = *puStack_5c;
              puStack_5c = puStack_5c + 1;
              *unaff_EBP = uVar1;
              unaff_EBP = unaff_EBP + 1;
              uVar4 = uVar4 + 1;
            } while (uVar4 < uStack_74);
          }
          uVar8 = uVar8 + 1;
          puStack_5c = puStack_5c + (iStack_70 / 2 - uStack_74);
        } while (uVar8 < uStack_78);
      }
      piVar2 = (int *)*puVar10;
      iVar6 = (**(code **)(*piVar2 + 0x80))(piVar2,0);
      if (iVar6 == -0x7789fe3e) {
        puVar10 = (undefined4 *)&stack0xffffff0c;
        for (iVar6 = 0x1b; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar10 = 0;
          puVar10 = puVar10 + 1;
        }
        uStack_8c = 0x4000;
        (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,&stack0xffffff0c,0,&LAB_10001b40);
        if (DAT_10036038 != (int *)0x0) {
          (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
        }
        if (DAT_1003603c != DAT_10036038) {
          (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
        }
        (**(code **)(*piVar2 + 0x80))(piVar2,0);
      }
      iVar6 = (**(code **)(*(int *)*puVar3 + 0x40))((int *)*puVar3,8,&stack0xffffff04);
      if (iVar6 == -0x7789fe3e) {
        puVar3 = auStack_d8;
        for (iVar7 = 0x1b; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
        }
        auStack_d8[0] = 0x6c;
        auStack_d8[1] = 1;
        iStack_70 = 0x4000;
        (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,auStack_d8,0);
        if (DAT_10036038 != (int *)0x0) {
          (**(code **)(*DAT_10036038 + 0x6c))();
        }
        if (DAT_1003603c != DAT_10036038) {
          (**(code **)(*DAT_1003603c + 0x6c))();
        }
      }
      if (iVar6 == 0) {
        *unaff_EBP = uStack_e0;
        puVar3 = (undefined4 *)(unaff_EBP + 2);
        unaff_EBP[1] = uStack_dc;
      }
      else {
        *unaff_EBP = 0;
        puVar3 = (undefined4 *)(unaff_EBP + 1);
        *(undefined2 *)puVar3 = 0xffff;
      }
      puVar10 = auStack_24;
      for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar3 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    else {
      (**(code **)(DAT_100394fc + 0x358))(unaff_EBP);
      iStack_e4 = 0;
    }
  }
  param_1[6] = iStack_e4;
  param_1[10] = param_1[7] * 2;
  FUN_10006dc0(param_1);
  return;
}


