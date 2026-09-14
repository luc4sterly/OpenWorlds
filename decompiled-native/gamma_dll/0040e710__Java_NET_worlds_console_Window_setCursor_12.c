// 0040e710 _Java_NET_worlds_console_Window_setCursor@12 [Global]
// programa: gamma.dll

void _Java_NET_worlds_console_Window_setCursor_12
               (undefined4 param_1,undefined4 param_2,WPARAM param_3)

{
                    /* 0xe710  113  _Java_NET_worlds_console_Window_setCursor@12 */
  if (DAT_004891c0 == (HWND)0x0) {
    DAT_004891c8 = param_3;
  }
  else {
    SendMessageA(DAT_004891c0,0x8067,param_3,0);
  }
  return;
}


