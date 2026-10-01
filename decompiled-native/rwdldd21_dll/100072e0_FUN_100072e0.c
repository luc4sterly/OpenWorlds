// 100072e0 FUN_100072e0 [Global]
// program: RWDLDD21.DLL

undefined4 FUN_100072e0(int param_1,int param_2,undefined1 *param_3)

{
  int iVar1;
  int iVar2;
  
  if (0 < param_2) {
    if ((param_1 < 10) || (0xf6 < param_1 + param_2)) {
      return 0;
    }
    iVar2 = 0;
    if (0 < param_2) {
      do {
        iVar1 = param_1 + iVar2;
        iVar2 = iVar2 + 1;
        (&DAT_10039610)[iVar1] = *param_3;
        (&DAT_10039710)[iVar1] = param_3[1];
        (&DAT_10039500)[iVar1] = param_3[2];
        param_3 = param_3 + 4;
      } while (iVar2 < param_2);
    }
  }
  FUN_10023a40();
  return 1;
}


