// 0040f1e0 _Java_NET_worlds_console_Window_getWindowHeight@12 [Global]
// program: gamma.dll

int _Java_NET_worlds_console_Window_getWindowHeight_12
              (undefined4 param_1,undefined4 param_2,HWND param_3)

{
  tagRECT local_18;
  
                    /* 0xf1e0  93  _Java_NET_worlds_console_Window_getWindowHeight@12 */
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetWindowRect(param_3,&local_18);
  return local_18.bottom - local_18.top;
}


