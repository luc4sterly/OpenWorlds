// 0043ee90 FUN_0043ee90 [Global]
// program: gamma.dll

void FUN_0043ee90(void)

{
  ATOM AVar1;
  WNDCLASSEXA local_34;
  
  if (DAT_0049dee8 != 0) {
    return;
  }
  local_34.cbWndExtra = 0;
  local_34.cbSize = 0x30;
  local_34.cbClsExtra = 0;
  local_34.style = 0x23;
  local_34.lpfnWndProc = (WNDPROC)&LAB_0043edd0;
  local_34.hInstance = (HINSTANCE)FUN_0040c110();
  local_34.hIcon = (HICON)0x0;
  local_34.hIconSm = (HICON)0x0;
  local_34.hCursor = (HCURSOR)0x0;
  local_34.lpszClassName = s_RenderCanvasOverlay_00477c28;
  local_34.hbrBackground = (HBRUSH)0x1;
  local_34.lpszMenuName = (LPCSTR)0x0;
  AVar1 = RegisterClassExA(&local_34);
  if (AVar1 == 0) {
    FUN_00402800(s_nRenderCanvas_00477c58,0x4f);
  }
  DAT_0049dee8 = 1;
  return;
}


