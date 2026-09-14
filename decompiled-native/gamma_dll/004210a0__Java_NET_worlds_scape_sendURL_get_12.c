// 004210a0 _Java_NET_worlds_scape_sendURL_get@12 [Global]
// programa: gamma.dll

undefined4 _Java_NET_worlds_scape_sendURL_get_12(int *param_1,undefined4 param_2,undefined4 param_3)

{
  HCONV pHVar1;
  HSZ pHVar2;
  char *pcVar3;
  int iVar4;
  char cVar5;
  char *pcVar6;
  CHAR aCStackY_195 [53];
  CHAR local_120;
  undefined4 local_11f [2];
  undefined2 uStack_117;
  undefined1 auStack_115 [261];
  
                    /* 0x210a0  371  _Java_NET_worlds_scape_sendURL_get@12 */
  pHVar1 = DdeConnect(DAT_0049d12c,DAT_0049d128,DAT_0049d130,(PCONVCONTEXT)0x0);
  if (pHVar1 == (HCONV)0x0) {
    return 0;
  }
  pHVar2 = DdeCreateStringHandleA(DAT_0049d12c,&DAT_004712b8,0x3ec);
  DdeClientTransaction((LPBYTE)0x0,0,pHVar1,pHVar2,1,0x20b0,0xffffffff,(LPDWORD)0x0);
  DdeDisconnect(pHVar1);
  DdeFreeStringHandle(DAT_0049d12c,pHVar2);
  pHVar1 = DdeConnect(DAT_0049d12c,DAT_0049d128,DAT_0049d134,(PCONVCONTEXT)0x0);
  if (pHVar1 == (HCONV)0x0) {
    return 0;
  }
  pcVar3 = (char *)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  iVar4 = -1;
  pcVar6 = pcVar3;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    cVar5 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar5 != '\0');
  local_120 = '\"';
  cVar5 = -2 - (char)iVar4;
  FUN_0044df50(local_11f,(undefined4 *)pcVar3,(int)cVar5);
  iVar4 = (int)cVar5;
  *(undefined4 *)((int)local_11f + iVar4) = DAT_004712c0;
  *(undefined4 *)((int)local_11f + iVar4 + 4) = DAT_004712c4;
  *(undefined2 *)((int)&uStack_117 + iVar4) = DAT_004712c8;
  auStack_115[iVar4] = DAT_004712ca;
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pcVar3);
  pHVar2 = DdeCreateStringHandleA(DAT_0049d12c,&stack0xfffffee0,0x3ec);
  DdeClientTransaction((LPBYTE)0x0,0,pHVar1,pHVar2,1,0x20b0,0xffffffff,(LPDWORD)0x0);
  DdeDisconnect(pHVar1);
  DdeFreeStringHandle(DAT_0049d12c,pHVar2);
  return 1;
}


