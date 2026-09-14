// 00404490 _Java_NET_worlds_network_DDEMLClass_Request@12 [Global]
// programa: gamma.dll

bool _Java_NET_worlds_network_DDEMLClass_Request_12
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  LPCSTR psz;
  undefined4 *puVar1;
  HSZ hszItem;
  int iVar2;
  
                    /* 0x4490  176  _Java_NET_worlds_network_DDEMLClass_Request@12 */
  psz = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 400))(param_1,param_2,DAT_0048907c);
  if (puVar1[4] == 0) {
    iVar2 = -1;
  }
  else {
    hszItem = DdeCreateStringHandleA(DAT_004a0430,psz,0x3ec);
    DdeClientTransaction((LPBYTE)0x0,0,(HCONV)*puVar1,hszItem,1,0x20b0,0xffffffff,(LPDWORD)0x0);
    DdeFreeStringHandle(DAT_004a0430,hszItem);
    iVar2 = 0;
  }
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,psz);
  return iVar2 == 0;
}


