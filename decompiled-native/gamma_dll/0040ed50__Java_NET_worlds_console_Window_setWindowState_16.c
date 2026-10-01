// 0040ed50 _Java_NET_worlds_console_Window_setWindowState@16 [Global]
// program: gamma.dll

void _Java_NET_worlds_console_Window_setWindowState_16
               (undefined4 param_1,undefined4 param_2,HWND param_3,undefined4 param_4)

{
  int nCmdShow;
  
                    /* 0xed50  117  _Java_NET_worlds_console_Window_setWindowState@16 */
  if (param_3 != (HWND)0x0) {
    nCmdShow = 9;
    switch(param_4) {
    case 1:
      nCmdShow = 6;
      break;
    case 2:
      nCmdShow = 3;
    }
    ShowWindow(param_3,nCmdShow);
  }
  return;
}


