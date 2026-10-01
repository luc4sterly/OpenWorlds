// 00421300 Java_NET_worlds_scape_sendURL_silent_get [Global]
// program: gamma.dll

/* long __stdcall Java_NET_worlds_scape_sendURL_silent_get(struct JNIEnv_ *,class _jclass *,class
   _jstring *) */

long Java_NET_worlds_scape_sendURL_silent_get(JNIEnv_ *param_1,_jclass *param_2,_jstring *param_3)

{
  HCONV hConv;
  char *pcVar1;
  HSZ hszItem;
  int iVar2;
  char cVar3;
  char *pcVar4;
  CHAR aCStackY_195 [53];
  CHAR local_120;
  undefined4 local_11f [2];
  undefined2 uStack_117;
  undefined1 auStack_115 [261];
  
                    /* 0x21300  12
                       ?Java_NET_worlds_scape_sendURL_silent_get@@YGJPAUJNIEnv_@@PAV_jclass@@PAV_jstring@@@Z
                        */
  hConv = DdeConnect(DAT_0049d12c,DAT_0049d128,DAT_0049d134,(PCONVCONTEXT)0x0);
  if (hConv == (HCONV)0x0) {
    return 0;
  }
  pcVar1 = (char *)(**(code **)(*(int *)param_1 + 0x2a4))(param_1,param_3,0);
  iVar2 = -1;
  pcVar4 = pcVar1;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar3 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar3 != '\0');
  local_120 = '\"';
  cVar3 = -2 - (char)iVar2;
  FUN_0044df50(local_11f,(undefined4 *)pcVar1,(int)cVar3);
  iVar2 = (int)cVar3;
  *(undefined4 *)((int)local_11f + iVar2) = DAT_004712c0;
  *(undefined4 *)((int)local_11f + iVar2 + 4) = DAT_004712c4;
  *(undefined2 *)((int)&uStack_117 + iVar2) = DAT_004712c8;
  auStack_115[iVar2] = DAT_004712ca;
  (**(code **)(*(int *)param_1 + 0x2a8))(param_1,param_3,pcVar1);
  hszItem = DdeCreateStringHandleA(DAT_0049d12c,&stack0xfffffee0,0x3ec);
  DdeClientTransaction((LPBYTE)0x0,0,hConv,hszItem,1,0x20b0,0xffffffff,(LPDWORD)0x0);
  DdeDisconnect(hConv);
  DdeFreeStringHandle(DAT_0049d12c,hszItem);
  return 1;
}


