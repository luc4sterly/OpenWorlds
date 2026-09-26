// 10008920 FUN_10008920 [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10008920(byte *param_1)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = 0x11;
  pbVar1 = param_1;
  do {
    FUN_100089f0();
    FUN_10006c70(pbVar1,pbVar1);
    iVar2 = iVar2 + -1;
    pbVar1 = pbVar1 + 3;
  } while (iVar2 != 0);
  iVar2 = 6;
  pbVar1 = param_1 + 0x33;
  do {
    FUN_100089f0();
    FUN_10006c70(pbVar1,pbVar1);
    iVar2 = iVar2 + -1;
    pbVar1 = pbVar1 + 3;
  } while (iVar2 != 0);
  return 0x17;
}


