// 0040bfb0 _Java_NET_worlds_console_Cursor_getSystemCursorDepth@8 [Global]
// programa: gamma.dll

int _Java_NET_worlds_console_Cursor_getSystemCursorDepth_8(void)

{
  HDC hdc;
  int iVar1;
  
                    /* 0xbfb0  22  _Java_NET_worlds_console_Cursor_getSystemCursorDepth@8 */
  hdc = GetDC((HWND)0x0);
  iVar1 = GetDeviceCaps(hdc,0xc);
  ReleaseDC((HWND)0x0,hdc);
  return iVar1;
}


