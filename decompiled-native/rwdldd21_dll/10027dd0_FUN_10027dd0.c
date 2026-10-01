// 10027dd0 FUN_10027dd0 [Global]
// program: RWDLDD21.DLL

int FUN_10027dd0(int param_1,int param_2)

{
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  piVar2 = DAT_10036410;
  if (DAT_10036410 != (int *)0x0) {
    if (*DAT_10036410 == 0) {
      if (DAT_10036410 == (int *)0x0) goto LAB_10027e3d;
      iVar6 = 8;
      piVar5 = DAT_10036410;
      do {
        piVar5 = piVar5 + 1;
        iVar3 = FUN_10027ed0((int *)*piVar5);
        iVar6 = iVar6 + -1;
        *piVar5 = iVar3;
      } while (iVar6 != 0);
    }
    else {
      if (DAT_10036410 == (int *)0x0) goto LAB_10027e3d;
      piVar5 = DAT_10036410 + 1;
      if (DAT_10036410[1] != 0) {
        (**(code **)(DAT_100394fc + 0x358))(DAT_10036410[1]);
      }
      *piVar5 = 0;
      *piVar2 = 0;
    }
    (**(code **)(DAT_100394fc + 0x358))(piVar2);
  }
LAB_10027e3d:
  DAT_10036410 = (int *)0x0;
  if ((param_1 < 1) || (param_2 == 0)) {
    iVar6 = 1;
  }
  else {
    iVar6 = 0;
  }
  piVar2 = DAT_10036410;
  if ((iVar6 == 0) && (piVar2 = (int *)(**(code **)(DAT_100394fc + 0x34c))(8), piVar2 != (int *)0x0)
     ) {
    iVar3 = (**(code **)(DAT_100394fc + 0x34c))(param_1);
    piVar2[1] = iVar3;
    if (iVar3 == 0) {
      (**(code **)(DAT_100394fc + 0x358))(piVar2);
      piVar2 = (int *)0x0;
    }
    else {
      iVar4 = 0;
      if (0 < param_1) {
        do {
          puVar1 = (undefined1 *)(param_2 + iVar4);
          iVar4 = iVar4 + 1;
          *(undefined1 *)(iVar3 + -1 + iVar4) = *puVar1;
        } while (iVar4 < param_1);
      }
      *piVar2 = param_1;
    }
  }
  DAT_10036410 = piVar2;
  return iVar6;
}


