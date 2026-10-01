// 00404530 _Java_NET_worlds_network_DDEMLClass_Poke@16 [Global]
// program: gamma.dll

bool _Java_NET_worlds_network_DDEMLClass_Poke_16(int *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  LPCSTR psz;
  undefined4 *puVar2;
  HSZ hszItem;
  int iVar3;
  char *pcVar4;
  
                    /* 0x4530  175  _Java_NET_worlds_network_DDEMLClass_Poke@16 */
  psz = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  puVar2 = (undefined4 *)(**(code **)(*param_1 + 400))(param_1,param_2,DAT_0048907c);
  if (puVar2[4] == 0) {
    iVar3 = -1;
  }
  else {
    hszItem = DdeCreateStringHandleA(DAT_004a0430,psz,0x3ec);
    iVar3 = -1;
    pcVar4 = (char *)0x0;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    DdeClientTransaction
              ((LPBYTE)0x0,0xffffffff - iVar3,(HCONV)*puVar2,hszItem,1,0x4090,0xffffffff,
               (LPDWORD)0x0);
    DdeFreeStringHandle(DAT_004a0430,hszItem);
    iVar3 = 0;
  }
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,psz);
  return iVar3 == 0;
}


