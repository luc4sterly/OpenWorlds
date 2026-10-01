// 100073b0 FUN_100073b0 [Global]
// program: RWDLDD21.DLL

undefined4 FUN_100073b0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  
  puVar2 = (undefined4 *)param_1[0xb];
  if (*param_1 == 3) {
    if (puVar2 == (undefined4 *)0x0) {
      return 0;
    }
    if (puVar2[0xd] == 0) {
      return 0;
    }
    piVar6 = *(int **)(puVar2[0xd] + 0x10);
    if (piVar6 == (int *)0x0) {
      return 0;
    }
    iVar1 = (**(code **)(*piVar6 + 0x80))(piVar6,0);
    if (iVar1 == -0x7789fe3e) {
      puVar2 = (undefined4 *)&stack0xffffff8c;
      for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
      }
      (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,&stack0xffffff8c,0,&LAB_10001b40);
      if (DAT_10036038 != (int *)0x0) {
        (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
      }
      if (DAT_1003603c != DAT_10036038) {
        (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
      }
      iVar1 = (**(code **)(*piVar6 + 0x80))(piVar6,0);
    }
    if (iVar1 != 0) {
      return 0;
    }
    param_1[6] = 0;
    param_1[0x10] = param_1[0x10] | 1;
    return 1;
  }
  if (puVar2 == (undefined4 *)0x0) {
    iVar5 = -1;
    FUN_100033a0(param_1);
    iVar1 = DAT_10036180;
    iVar3 = 0;
    if (0 < DAT_10036180) {
      do {
        if (param_1 == (int *)DAT_1003617c[iVar3]) goto LAB_100075ad;
        if ((iVar5 == -1) && ((int *)DAT_1003617c[iVar3] == (int *)0x0)) {
          iVar5 = iVar3;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < DAT_10036180);
    }
    if (iVar5 == -1) {
      iVar5 = iVar1;
      if ((DAT_1003617c == (undefined4 *)0x0) || (DAT_10036180 == 0)) {
        puVar2 = (undefined4 *)(**(code **)(DAT_100394fc + 0x34c))(0x200);
        if (puVar2 != (undefined4 *)0x0) {
          puVar4 = puVar2;
          for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar4 = 0;
            puVar4 = puVar4 + 1;
          }
          DAT_10036180 = 0x80;
          DAT_1003617c = puVar2;
        }
      }
      else {
        puVar2 = (undefined4 *)(**(code **)(DAT_100394fc + 0x354))(DAT_1003617c,DAT_10036180 * 8);
        if (puVar2 != (undefined4 *)0x0) {
          if (DAT_10036180 != 0 && SBORROW4(DAT_10036180 * 2,DAT_10036180) == DAT_10036180 < 0) {
            puVar4 = puVar2 + DAT_10036180;
            iVar1 = DAT_10036180;
            do {
              *puVar4 = 0;
              puVar4 = puVar4 + 1;
              iVar1 = iVar1 + 1;
            } while (iVar1 < DAT_10036180 * 2);
          }
          DAT_10036180 = DAT_10036180 * 2;
          DAT_1003617c = puVar2;
        }
      }
    }
    DAT_1003617c[iVar5] = param_1;
LAB_100075ad:
    puVar2 = (undefined4 *)param_1[0xb];
    if (puVar2 == (undefined4 *)0x0) {
      piVar6 = (int *)0x0;
      goto LAB_100075ba;
    }
  }
  piVar6 = (int *)*puVar2;
LAB_100075ba:
  if (piVar6 == (int *)0x0) {
    return 0;
  }
  iVar1 = (**(code **)(*piVar6 + 0x80))(piVar6,0);
  if (iVar1 == -0x7789fe3e) {
    puVar2 = (undefined4 *)&stack0xffffff8c;
    for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,&stack0xffffff8c,0,&LAB_10001b40);
    if (DAT_10036038 != (int *)0x0) {
      (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
    }
    if (DAT_1003603c != DAT_10036038) {
      (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
    }
    iVar1 = (**(code **)(*piVar6 + 0x80))(piVar6,0);
  }
  if (iVar1 != 0) {
    return 0;
  }
  param_1[6] = 0;
  return 1;
}


