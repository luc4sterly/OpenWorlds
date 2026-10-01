// 0040dfc0 FUN_0040dfc0 [Global]
// program: gamma.dll

void FUN_0040dfc0(void)

{
  ATOM AVar1;
  WNDCLASSEXA local_34;
  
  if (DAT_004892d0 != 0) {
    return;
  }
  local_34.cbSize = 0x30;
  local_34.hInstance = DAT_004891bc;
  local_34.style = 0;
  local_34.hIconSm = (HICON)0x0;
  local_34.lpfnWndProc = (WNDPROC)&LAB_0040dfb0;
  local_34.lpszClassName = s_TempClass_0046e9c8;
  local_34.cbClsExtra = 0;
  local_34.lpszMenuName = (LPCSTR)0x0;
  local_34.cbWndExtra = 0;
  local_34.hbrBackground = (HBRUSH)0x1;
  local_34.hIcon = (HICON)0x0;
  local_34.hCursor = (HCURSOR)0x0;
  AVar1 = RegisterClassExA(&local_34);
  if (AVar1 == 0) {
    FUN_00402800(s_nWindow_0046e8c4,0x667);
  }
  DAT_004892d0 = 1;
  return;
}


