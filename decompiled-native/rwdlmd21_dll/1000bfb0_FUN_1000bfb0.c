// 1000bfb0 FUN_1000bfb0 [Global]
// programa: rwdlmd21.dll

undefined4 FUN_1000bfb0(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  piVar1 = DAT_10087368;
  if (DAT_10087368 != (int *)0x0) {
    if (*DAT_10087368 == 0) {
      if (DAT_10087368 == (int *)0x0) {
        DAT_10087368 = (int *)0x0;
        return 0;
      }
      iVar4 = 8;
      piVar3 = DAT_10087368;
      do {
        piVar3 = piVar3 + 1;
        iVar2 = FUN_1000bf20((int *)*piVar3);
        iVar4 = iVar4 + -1;
        *piVar3 = iVar2;
      } while (iVar4 != 0);
    }
    else {
      if (DAT_10087368 == (int *)0x0) {
        DAT_10087368 = (int *)0x0;
        return 0;
      }
      piVar3 = DAT_10087368 + 1;
      if (DAT_10087368[1] != 0) {
        (**(code **)(DAT_10089de0 + 0x358))(DAT_10087368[1]);
      }
      *piVar3 = 0;
      *piVar1 = 0;
    }
    (**(code **)(DAT_10089de0 + 0x358))(piVar1);
  }
  DAT_10087368 = (int *)0x0;
  return 0;
}


