// 0043f9d0 FUN_0043f9d0 [Global]
// programa: gamma.dll

void FUN_0043f9d0(void)

{
  ATOM AVar1;
  WNDCLASSEXA local_34;
  
  if (DAT_0049df40 != 0) {
    return;
  }
  local_34.cbWndExtra = 0;
  local_34.cbSize = 0x30;
  local_34.cbClsExtra = 0;
  local_34.style = 0x23;
  local_34.lpfnWndProc = FUN_0043f9b0;
  local_34.hInstance = (HINSTANCE)FUN_0040c110();
  local_34.hIcon = (HICON)0x0;
  local_34.hIconSm = (HICON)0x0;
  local_34.hCursor = (HCURSOR)0x0;
  local_34.lpszClassName = s_TextureSurface_00477ed0;
  local_34.hbrBackground = (HBRUSH)0x0;
  local_34.lpszMenuName = (LPCSTR)0x0;
  AVar1 = RegisterClassExA(&local_34);
  if (AVar1 == 0) {
    FUN_00402800(s_nTexSurface_00477ee0,0x2d);
  }
  DAT_0049df40 = 1;
  return;
}


