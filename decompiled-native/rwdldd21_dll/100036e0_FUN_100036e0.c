// 100036e0 FUN_100036e0 [Global]
// programa: RWDLDD21.DLL

undefined4 FUN_100036e0(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int unaff_EBX;
  int iVar5;
  int *piVar6;
  int unaff_ESI;
  int unaff_EDI;
  undefined1 *puStack_100;
  int *piStack_fc;
  undefined4 uStack_f8;
  undefined4 *puStack_f4;
  undefined4 *puStack_f0;
  undefined4 local_d8 [4];
  int iStack_c8;
  int iStack_98;
  undefined4 auStack_80 [26];
  undefined4 uStack_18;
  
  puVar1 = (undefined4 *)param_1[0xb];
  if (*param_1 == 3) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    if (puVar1[0xd] == 0) {
      return 0;
    }
    piVar6 = *(int **)(puVar1[0xd] + 0x10);
    if (piVar6 == (int *)0x0) {
      return 0;
    }
    puVar1 = local_d8;
    for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar1 = 0;
      puVar1 = puVar1 + 1;
    }
    puStack_f4 = local_d8;
    puStack_f0 = (undefined4 *)0x1;
    local_d8[0] = 0x6c;
    uStack_f8 = 0;
    puStack_100 = (undefined1 *)0x1000374b;
    piStack_fc = piVar6;
    iVar2 = (**(code **)(*piVar6 + 100))();
    if (iVar2 == -0x7789fe3e) {
      puStack_100 = &LAB_10001b40;
      puVar1 = auStack_80;
      for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
      }
      auStack_80[0] = 0x6c;
      auStack_80[1] = 1;
      uStack_18 = 0x4000;
      (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,auStack_80,0);
      if (DAT_10036038 != (int *)0x0) {
        (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
      }
      if (DAT_1003603c != DAT_10036038) {
        (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
      }
      iVar2 = (**(code **)(*piVar6 + 100))(piVar6,0,&puStack_100,1,0);
    }
    if (iVar2 != 0) {
      return 0;
    }
    param_1[6] = iStack_c8;
    param_1[7] = unaff_ESI;
    param_1[8] = unaff_EDI;
    param_1[10] = unaff_EBX;
    goto LAB_100039f2;
  }
  if (puVar1 == (undefined4 *)0x0) {
    iVar5 = -1;
    puStack_f0 = (undefined4 *)0x10003815;
    FUN_100033a0(param_1);
    iVar2 = DAT_10036180;
    iVar3 = 0;
    if (0 < DAT_10036180) {
      do {
        if (param_1 == (int *)DAT_1003617c[iVar3]) goto LAB_100038fe;
        if ((iVar5 == -1) && ((int *)DAT_1003617c[iVar3] == (int *)0x0)) {
          iVar5 = iVar3;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < DAT_10036180);
    }
    if (iVar5 == -1) {
      iVar5 = iVar2;
      if ((DAT_1003617c == (undefined4 *)0x0) || (DAT_10036180 == 0)) {
        puStack_f0 = (undefined4 *)0x100038d2;
        puVar1 = (undefined4 *)(**(code **)(DAT_100394fc + 0x34c))();
        if (puVar1 != (undefined4 *)0x0) {
          puVar4 = puVar1;
          for (iVar2 = 0x80; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar4 = 0;
            puVar4 = puVar4 + 1;
          }
          DAT_10036180 = 0x80;
          DAT_1003617c = puVar1;
        }
      }
      else {
        puStack_f0 = DAT_1003617c;
        puStack_f4 = (undefined4 *)0x1000387c;
        puVar1 = (undefined4 *)(**(code **)(DAT_100394fc + 0x354))();
        if (puVar1 != (undefined4 *)0x0) {
          if (DAT_10036180 != 0 && SBORROW4(DAT_10036180 * 2,DAT_10036180) == DAT_10036180 < 0) {
            puVar4 = puVar1 + DAT_10036180;
            iVar2 = DAT_10036180;
            do {
              *puVar4 = 0;
              puVar4 = puVar4 + 1;
              iVar2 = iVar2 + 1;
            } while (iVar2 < DAT_10036180 * 2);
          }
          DAT_10036180 = DAT_10036180 * 2;
          DAT_1003617c = puVar1;
        }
      }
    }
    DAT_1003617c[iVar5] = param_1;
LAB_100038fe:
    puVar1 = (undefined4 *)param_1[0xb];
    if (puVar1 != (undefined4 *)0x0) goto LAB_10003905;
    piVar6 = (int *)0x0;
  }
  else {
LAB_10003905:
    piVar6 = (int *)*puVar1;
  }
  if (piVar6 == (int *)0x0) {
    return 0;
  }
  puVar1 = local_d8;
  for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  puStack_f4 = local_d8;
  puStack_f0 = (undefined4 *)0x1;
  local_d8[0] = 0x6c;
  uStack_f8 = 0;
  puStack_100 = (undefined1 *)0x1000393b;
  piStack_fc = piVar6;
  iVar2 = (**(code **)(*piVar6 + 100))();
  if (iVar2 == -0x7789fe3e) {
    puStack_100 = &LAB_10001b40;
    puVar1 = auStack_80;
    for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar1 = 0;
      puVar1 = puVar1 + 1;
    }
    auStack_80[0] = 0x6c;
    auStack_80[1] = 1;
    uStack_18 = 0x4000;
    (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,auStack_80,0);
    if (DAT_10036038 != (int *)0x0) {
      (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
    }
    if (DAT_1003603c != DAT_10036038) {
      (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
    }
    iVar2 = (**(code **)(*piVar6 + 100))(piVar6,0,&puStack_100,1,0);
  }
  if (iVar2 != 0) {
    return 0;
  }
  param_1[6] = iStack_c8;
  param_1[7] = unaff_ESI;
  param_1[8] = unaff_EDI;
  param_1[9] = iStack_98;
  param_1[10] = unaff_EBX;
LAB_100039f2:
  param_1[0x10] = param_1[0x10] | 1;
  return 1;
}


