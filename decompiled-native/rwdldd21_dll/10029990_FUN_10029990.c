// 10029990 FUN_10029990 [Global]
// programa: RWDLDD21.DLL

undefined4 * FUN_10029990(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = param_1 + 4;
  if (DAT_100390b4 < (uint)(DAT_100390a8 + iVar3)) {
    if (DAT_100390ac == 0) {
      iVar1 = (**(code **)(DAT_100394fc + 0x34c))(DAT_100390a8 + iVar3);
    }
    else {
      iVar1 = (**(code **)(DAT_100394fc + 0x354))(DAT_100390ac);
    }
    if (iVar1 == 0) {
      return (undefined4 *)0x0;
    }
    DAT_100390b4 = DAT_100390a8 + iVar3;
    DAT_100390ac = iVar1;
  }
  if (DAT_100390bc <= DAT_100390b8) {
    if (DAT_100390b0 == 0) {
      iVar1 = (**(code **)(DAT_100394fc + 0x34c))(DAT_100390bc * 4 + 4);
    }
    else {
      iVar1 = (**(code **)(DAT_100394fc + 0x354))(DAT_100390b0);
    }
    if (iVar1 == 0) {
      return (undefined4 *)0x0;
    }
    DAT_100390bc = DAT_100390bc + 1;
    DAT_100390b0 = iVar1;
  }
  *(int *)(DAT_100390b0 + DAT_100390b8 * 4) = DAT_100390a8;
  puVar2 = (undefined4 *)(DAT_100390a8 + DAT_100390ac);
  *puVar2 = param_2;
  DAT_100390b8 = DAT_100390b8 + 1;
  DAT_100390a8 = DAT_100390a8 + iVar3;
  return puVar2 + 1;
}


