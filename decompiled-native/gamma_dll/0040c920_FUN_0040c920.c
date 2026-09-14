// 0040c920 FUN_0040c920 [Global]
// programa: gamma.dll

void FUN_0040c920(void)

{
  HWND hWnd;
  
  if (DAT_004892b8 == (HWND)0x0) {
    if (DAT_0049ff1c == (undefined4 *)0x0) {
      hWnd = (HWND)0x0;
    }
    else {
      hWnd = (HWND)*DAT_0049ff1c;
    }
    SetFocus(hWnd);
  }
  else {
    SetFocus(DAT_004892b8);
    DAT_004892b8 = (HWND)0x0;
  }
  return;
}


