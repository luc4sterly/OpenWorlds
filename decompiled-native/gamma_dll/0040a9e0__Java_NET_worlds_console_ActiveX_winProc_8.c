// 0040a9e0 _Java_NET_worlds_console_ActiveX_winProc@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_console_ActiveX_winProc_8(undefined4 param_1)

{
  BOOL BVar1;
  tagMSG local_20;
  
                    /* 0xa9e0  18  _Java_NET_worlds_console_ActiveX_winProc@8 */
  DAT_004890f8 = param_1;
  BVar1 = PeekMessageA(&local_20,(HWND)0x0,0,0,0);
  if (BVar1 != 0) {
    GetMessageA(&local_20,(HWND)0x0,0,0);
    TranslateMessage(&local_20);
    DispatchMessageA(&local_20);
  }
  return;
}


