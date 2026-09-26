// 10029ab0 FUN_10029ab0 [Global]
// programa: RWDLDD21.DLL

undefined4 FUN_10029ab0(void)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  uVar3 = 0;
  piVar2 = DAT_100390b0;
  if (DAT_100390b8 != 0) {
    do {
      iVar1 = *piVar2;
      piVar2 = piVar2 + 1;
      uVar3 = uVar3 + 1;
      (**(code **)(iVar1 + DAT_100390ac))((undefined4 *)(iVar1 + DAT_100390ac) + 1);
    } while (uVar3 < DAT_100390b8);
  }
  if (DAT_10036434 < DAT_100390a8) {
    DAT_10036434 = DAT_100390a8;
  }
  DAT_10036430 = DAT_10036430 + 1 & 0x3f;
  if (DAT_10036430 == 0) {
    if ((DAT_10036434 >> 1) + DAT_10036434 < DAT_100390b4) {
      iVar1 = (**(code **)(DAT_100394fc + 0x354))(DAT_100390ac,DAT_10036434);
      if (iVar1 != 0) {
        DAT_100390b4 = DAT_10036434;
        DAT_100390ac = iVar1;
      }
    }
    DAT_10036434 = 0;
  }
  DAT_100390a8 = 0;
  DAT_100390b8 = 0;
  return 1;
}


