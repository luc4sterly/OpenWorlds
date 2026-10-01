// 0040bd70 _Java_NET_worlds_console_Cursor_loadCursor@12 [Global]
// program: gamma.dll

void _Java_NET_worlds_console_Cursor_loadCursor_12(int *param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  char local_268 [297];
  char acStack_13f [3];
  uint local_13c [75];
  
                    /* 0xbd70  25  _Java_NET_worlds_console_Cursor_loadCursor@12 */
  if (param_3 != 0) {
    local_268[1] = '\0';
    pcVar2 = (char *)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
    FUN_0044d6b0(local_268,pcVar2);
    (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pcVar2);
    if (((local_268[0] != '\\') && (local_268[0] != '/')) && (local_268[1] != ':')) {
      local_13c[0]._0_1_ = 0;
      FUN_0044d990((uint *)(acStack_13f + 3),300);
      iVar3 = -1;
      pcVar2 = local_268;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      iVar4 = -1;
      pcVar2 = acStack_13f + 3;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      if (299 < (uint)((-2 - iVar4) - iVar3)) {
        FUN_00402800(s_nCursor_0046e778,0x25);
      }
      iVar3 = -1;
      pcVar2 = acStack_13f + 3;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      if (((-iVar3 != 2) && (acStack_13f[-iVar3] != '\\')) && (acStack_13f[-iVar3] != '/')) {
        FUN_0044d700(acStack_13f + 3,&DAT_0046e780);
      }
      FUN_0044d700(acStack_13f + 3,local_268);
      FUN_0044d6b0(local_268,acStack_13f + 3);
    }
    LoadCursorFromFileA(local_268);
  }
  return;
}


