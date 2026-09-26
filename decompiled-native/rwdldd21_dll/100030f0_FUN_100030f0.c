// 100030f0 FUN_100030f0 [Global]
// programa: RWDLDD21.DLL

void FUN_100030f0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = DAT_10036180;
  iVar2 = 0;
  iVar5 = -1;
  if (0 < DAT_10036180) {
    do {
      if (DAT_1003617c[iVar2] == param_1) {
        return;
      }
      if ((iVar5 == -1) && (DAT_1003617c[iVar2] == 0)) {
        iVar5 = iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_10036180);
  }
  if (iVar5 == -1) {
    iVar5 = iVar4;
    if ((DAT_1003617c == (undefined4 *)0x0) || (DAT_10036180 == 0)) {
      puVar1 = (undefined4 *)(**(code **)(DAT_100394fc + 0x34c))(0x200);
      if (puVar1 != (undefined4 *)0x0) {
        puVar3 = puVar1;
        for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
        }
        DAT_10036180 = 0x80;
        DAT_1003617c = puVar1;
      }
    }
    else {
      puVar1 = (undefined4 *)(**(code **)(DAT_100394fc + 0x354))(DAT_1003617c,DAT_10036180 * 8);
      if (puVar1 != (undefined4 *)0x0) {
        if (DAT_10036180 != 0 && SBORROW4(DAT_10036180 * 2,DAT_10036180) == DAT_10036180 < 0) {
          puVar3 = puVar1 + DAT_10036180;
          iVar4 = DAT_10036180;
          do {
            *puVar3 = 0;
            puVar3 = puVar3 + 1;
            iVar4 = iVar4 + 1;
          } while (iVar4 < DAT_10036180 * 2);
        }
        DAT_10036180 = DAT_10036180 * 2;
        DAT_1003617c = puVar1;
      }
    }
  }
  DAT_1003617c[iVar5] = param_1;
  return;
}


