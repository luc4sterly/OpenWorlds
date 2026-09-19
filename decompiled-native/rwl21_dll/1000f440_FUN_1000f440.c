// 1000f440 FUN_1000f440 [Global]
// programa: RWL21.DLL

undefined4 FUN_1000f440(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (-1 < (int)param_1[0x27]) {
    iVar2 = 0;
    do {
      if (*(undefined4 **)(param_1[0x25] + iVar2) != (undefined4 *)0x0) {
        iVar1 = RwDestroyClump(*(undefined4 **)(param_1[0x25] + iVar2));
        if (iVar1 == 0) {
          return 0;
        }
      }
      iVar2 = iVar2 + 4;
      iVar3 = iVar3 + 1;
    } while (iVar3 <= (int)param_1[0x27]);
  }
  (**(code **)(PTR_DAT_1005b69c + 0x358))(param_1[0x25]);
  if (0 < (int)param_1[0x22]) {
    while( true ) {
      iVar3 = FUN_1001d750();
      if (iVar3 <= (int)param_1[0x22]) break;
      iVar3 = FUN_1001d780();
      if (iVar3 == 0) {
        return 0;
      }
    }
  }
  if (0 < (int)param_1[0x23]) {
    while( true ) {
      iVar3 = FUN_1001d740((int)DAT_1005dfd0);
      if (iVar3 <= (int)param_1[0x23]) break;
      iVar3 = FUN_1001d720(DAT_1005dfd0);
      if (iVar3 == 0) {
        return 0;
      }
    }
  }
  if (0 < (int)param_1[0x24]) {
    while( true ) {
      iVar3 = FUN_10019b40();
      if (iVar3 <= (int)param_1[0x24]) break;
      iVar3 = RwPopCurrentMaterial();
      if (iVar3 == 0) {
        return 0;
      }
    }
  }
  FUN_10037010(DAT_1005a0d0,param_1);
  return 1;
}


