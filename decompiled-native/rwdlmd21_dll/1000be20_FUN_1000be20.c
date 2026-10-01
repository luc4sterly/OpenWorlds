// 1000be20 FUN_1000be20 [Global]
// program: rwdlmd21.dll

int FUN_1000be20(int param_1,int param_2)

{
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  piVar2 = DAT_10087368;
  if (DAT_10087368 != (int *)0x0) {
    if (*DAT_10087368 == 0) {
      if (DAT_10087368 == (int *)0x0) goto LAB_1000be90;
      iVar5 = 8;
      piVar6 = DAT_10087368;
      do {
        piVar6 = piVar6 + 1;
        iVar3 = FUN_1000bf20((int *)*piVar6);
        iVar5 = iVar5 + -1;
        *piVar6 = iVar3;
      } while (iVar5 != 0);
    }
    else {
      if (DAT_10087368 == (int *)0x0) goto LAB_1000be90;
      piVar6 = DAT_10087368 + 1;
      if (DAT_10087368[1] != 0) {
        (**(code **)(DAT_10089de0 + 0x358))(DAT_10087368[1]);
      }
      *piVar6 = 0;
      *piVar2 = 0;
    }
    (**(code **)(DAT_10089de0 + 0x358))(piVar2);
  }
LAB_1000be90:
  DAT_10087368 = (int *)0x0;
  if ((param_1 < 1) || (param_2 == 0)) {
    iVar5 = 1;
  }
  else {
    iVar5 = 0;
  }
  piVar2 = DAT_10087368;
  if ((iVar5 == 0) && (piVar2 = (int *)(**(code **)(DAT_10089de0 + 0x34c))(8), piVar2 != (int *)0x0)
     ) {
    iVar3 = (**(code **)(DAT_10089de0 + 0x34c))(param_1);
    piVar2[1] = iVar3;
    if (iVar3 == 0) {
      (**(code **)(DAT_10089de0 + 0x358))(piVar2);
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
  DAT_10087368 = piVar2;
  return iVar5;
}


