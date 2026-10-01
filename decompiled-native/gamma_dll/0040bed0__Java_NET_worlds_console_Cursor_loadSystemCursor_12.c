// 0040bed0 _Java_NET_worlds_console_Cursor_loadSystemCursor@12 [Global]
// program: gamma.dll

HCURSOR _Java_NET_worlds_console_Cursor_loadSystemCursor_12
                  (int *param_1,undefined4 param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  HCURSOR pHVar3;
  int iVar4;
  
                    /* 0xbed0  26  _Java_NET_worlds_console_Cursor_loadSystemCursor@12 */
  if (param_3 != 0) {
    pbVar1 = (byte *)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
    iVar4 = 0;
    do {
      iVar2 = FUN_0044d730((&PTR_s_IDC_APPSTARTING_0046e81c)[iVar4 * 2],pbVar1);
      if (iVar2 == 0) {
        (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pbVar1);
        pHVar3 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)(&DAT_0046e820)[iVar4 * 2]);
        return pHVar3;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0xc);
    (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pbVar1);
  }
  return (HCURSOR)0x0;
}


