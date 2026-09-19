// 1000b760 FUN_1000b760 [Global]
// programa: RWDL6D21.DLL

undefined4 FUN_1000b760(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  piVar1 = DAT_10079340;
  if (DAT_10079340 != (int *)0x0) {
    if (*DAT_10079340 == 0) {
      if (DAT_10079340 == (int *)0x0) {
        DAT_10079340 = (int *)0x0;
        return 0;
      }
      iVar4 = 8;
      piVar3 = DAT_10079340;
      do {
        piVar3 = piVar3 + 1;
        iVar2 = FUN_1000b6d0((int *)*piVar3);
        iVar4 = iVar4 + -1;
        *piVar3 = iVar2;
      } while (iVar4 != 0);
    }
    else {
      if (DAT_10079340 == (int *)0x0) {
        DAT_10079340 = (int *)0x0;
        return 0;
      }
      piVar3 = DAT_10079340 + 1;
      if (DAT_10079340[1] != 0) {
        (**(code **)(DAT_1007bda8 + 0x358))(DAT_10079340[1]);
      }
      *piVar3 = 0;
      *piVar1 = 0;
    }
    (**(code **)(DAT_1007bda8 + 0x358))(piVar1);
  }
  DAT_10079340 = (int *)0x0;
  return 0;
}


