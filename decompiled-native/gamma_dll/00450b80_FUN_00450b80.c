// 00450b80 FUN_00450b80 [Global]
// programa: gamma.dll

byte * __cdecl FUN_00450b80(byte *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  
  iVar2 = -1;
  pbVar5 = param_1;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar1 = *pbVar5;
    pbVar5 = pbVar5 + 1;
  } while (bVar1 != 0);
  iVar6 = -iVar2 + -2;
  iVar3 = 0;
  do {
    do {
      iVar4 = iVar3 + 1;
      pbVar5 = *(byte **)(DAT_0049fba8 + iVar3 * 4);
      if (pbVar5 == (byte *)0x0) {
        return (byte *)0x0;
      }
      iVar3 = iVar4;
    } while (pbVar5[iVar6] != 0x3d);
    iVar4 = FUN_00450930(pbVar5,param_1,iVar6);
  } while (iVar4 != 0);
  return pbVar5 + -iVar2 + -1;
}


