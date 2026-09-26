// 10009100 FUN_10009100 [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10009100(byte *param_1)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = 0x11;
  pbVar1 = param_1;
  do {
    FUN_100091d0();
    FUN_100074e0(pbVar1,pbVar1);
    iVar2 = iVar2 + -1;
    pbVar1 = pbVar1 + 3;
  } while (iVar2 != 0);
  iVar2 = 6;
  pbVar1 = param_1 + 0x33;
  do {
    FUN_100091d0();
    FUN_100074e0(pbVar1,pbVar1);
    iVar2 = iVar2 + -1;
    pbVar1 = pbVar1 + 3;
  } while (iVar2 != 0);
  return 0x17;
}


