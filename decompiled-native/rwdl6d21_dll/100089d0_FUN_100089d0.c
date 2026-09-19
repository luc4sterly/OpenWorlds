// 100089d0 FUN_100089d0 [Global]
// programa: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_100089d0(byte *param_1)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = 0x11;
  pbVar1 = param_1;
  do {
    FUN_10008aa0();
    FUN_10006d20(pbVar1,pbVar1);
    iVar2 = iVar2 + -1;
    pbVar1 = pbVar1 + 3;
  } while (iVar2 != 0);
  iVar2 = 6;
  pbVar1 = param_1 + 0x33;
  do {
    FUN_10008aa0();
    FUN_10006d20(pbVar1,pbVar1);
    iVar2 = iVar2 + -1;
    pbVar1 = pbVar1 + 3;
  } while (iVar2 != 0);
  return 0x17;
}


