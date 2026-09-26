// 10027f60 FUN_10027f60 [Global]
// programa: RWDLDD21.DLL

undefined4 FUN_10027f60(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  piVar1 = DAT_10036410;
  if (DAT_10036410 != (int *)0x0) {
    if (*DAT_10036410 == 0) {
      if (DAT_10036410 == (int *)0x0) {
        DAT_10036410 = (int *)0x0;
        return 0;
      }
      iVar4 = 8;
      piVar3 = DAT_10036410;
      do {
        piVar3 = piVar3 + 1;
        iVar2 = FUN_10027ed0((int *)*piVar3);
        iVar4 = iVar4 + -1;
        *piVar3 = iVar2;
      } while (iVar4 != 0);
    }
    else {
      if (DAT_10036410 == (int *)0x0) {
        DAT_10036410 = (int *)0x0;
        return 0;
      }
      piVar3 = DAT_10036410 + 1;
      if (DAT_10036410[1] != 0) {
        (**(code **)(DAT_100394fc + 0x358))(DAT_10036410[1]);
      }
      *piVar3 = 0;
      *piVar1 = 0;
    }
    (**(code **)(DAT_100394fc + 0x358))(piVar1);
  }
  DAT_10036410 = (int *)0x0;
  return 0;
}


