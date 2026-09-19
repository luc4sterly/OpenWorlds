// 1000b5d0 FUN_1000b5d0 [Global]
// programa: RWDL6D21.DLL

int FUN_1000b5d0(int param_1,int param_2)

{
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  piVar2 = DAT_10079340;
  if (DAT_10079340 != (int *)0x0) {
    if (*DAT_10079340 == 0) {
      if (DAT_10079340 == (int *)0x0) goto LAB_1000b63d;
      iVar6 = 8;
      piVar5 = DAT_10079340;
      do {
        piVar5 = piVar5 + 1;
        iVar3 = FUN_1000b6d0((int *)*piVar5);
        iVar6 = iVar6 + -1;
        *piVar5 = iVar3;
      } while (iVar6 != 0);
    }
    else {
      if (DAT_10079340 == (int *)0x0) goto LAB_1000b63d;
      piVar5 = DAT_10079340 + 1;
      if (DAT_10079340[1] != 0) {
        (**(code **)(DAT_1007bda8 + 0x358))(DAT_10079340[1]);
      }
      *piVar5 = 0;
      *piVar2 = 0;
    }
    (**(code **)(DAT_1007bda8 + 0x358))(piVar2);
  }
LAB_1000b63d:
  DAT_10079340 = (int *)0x0;
  if ((param_1 < 1) || (param_2 == 0)) {
    iVar6 = 1;
  }
  else {
    iVar6 = 0;
  }
  piVar2 = DAT_10079340;
  if ((iVar6 == 0) && (piVar2 = (int *)(**(code **)(DAT_1007bda8 + 0x34c))(8), piVar2 != (int *)0x0)
     ) {
    iVar3 = (**(code **)(DAT_1007bda8 + 0x34c))(param_1);
    piVar2[1] = iVar3;
    if (iVar3 == 0) {
      (**(code **)(DAT_1007bda8 + 0x358))(piVar2);
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
  DAT_10079340 = piVar2;
  return iVar6;
}


